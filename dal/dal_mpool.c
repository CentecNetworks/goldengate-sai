
#include "dal_mpool.h"

#ifdef __KERNEL__
#include <linux/spinlock.h>
#include <linux/slab.h>

#define MALLOC(x) kmalloc(x, GFP_ATOMIC)
#define FREE(x) kfree(x)

static spinlock_t dal_mpool_lock;
#define MPOOL_LOCK_INIT() spin_lock_init(&dal_mpool_lock)
#define MPOOL_LOCK() unsigned long flags; spin_lock_irqsave(&dal_mpool_lock, flags)
#define MPOOL_UNLOCK() spin_unlock_irqrestore(&dal_mpool_lock, flags)
#define DAL_PRINT(fmt,arg...) printk(fmt,##arg)
#else /* !__KERNEL__*/

#include <stdlib.h>
#include "sal.h"
#define MALLOC(x) malloc(x)
#define FREE(x) free(x)
static sal_mutex_t* dal_mpool_lock;
#define MPOOL_LOCK_INIT() sal_mutex_create(&dal_mpool_lock)
#define MPOOL_LOCK() sal_mutex_lock(dal_mpool_lock)
#define MPOOL_UNLOCK() sal_mutex_unlock(dal_mpool_lock)
#define DAL_PRINT(fmt,arg...) sal_printf(fmt,##arg)

#endif /* __KERNEL__ */

dal_mpool_mem_t* g_free_block_ptr = NULL;

/* System cache line size */
#ifndef DAL_CACHE_LINE_BYTES
#define DAL_CACHE_LINE_BYTES 256
#endif

static dal_mpool_mem_t* p_desc_pool = NULL;
static dal_mpool_mem_t* p_data_pool = NULL;

int
dal_mpool_init(void)
{
    MPOOL_LOCK_INIT();
    return 0;
}

dal_mpool_mem_t*
_dal_mpool_create(void* base, int size, int type)
{
    dal_mpool_mem_t* head = NULL;
    dal_mpool_mem_t* tail = NULL;

    head = (dal_mpool_mem_t*)MALLOC(sizeof(dal_mpool_mem_t));
    if (head == NULL)
    {
        return NULL;
    }

    tail = (dal_mpool_mem_t*)MALLOC(sizeof(dal_mpool_mem_t));
    if (tail == NULL)
    {
        FREE(head);
        return NULL;
    }

    head->size = tail->size = 0;
    head->type = type;
    head->address = base;
    tail->address = head->address + size;
    head->next = tail;
    tail->next = NULL;

    return head;
}

dal_mpool_mem_t*
dal_mpool_create(void* base, int size)
{
    dal_mpool_mem_t* head = NULL;
    int mod = (int)(((unsigned long)base) & (DAL_CACHE_LINE_BYTES - 1));

    MPOOL_LOCK();

    if (mod)
    {
        base = (char*)base + (DAL_CACHE_LINE_BYTES - mod);
        size -= (DAL_CACHE_LINE_BYTES - mod);
    }

    size &= ~(DAL_CACHE_LINE_BYTES - 1);

    /* init for common linkptr, only used for GB */
    head = _dal_mpool_create(base, size, DAL_MPOOL_TYPE_USELESS);
    if (NULL == head)
    {
        MPOOL_UNLOCK();
        return NULL;
    }

    /* init for desc linkptr */
    p_desc_pool = _dal_mpool_create(base, DAL_MPOOL_MAX_DESX_SIZE, DAL_MPOOL_TYPE_DESC);
    if (NULL == p_desc_pool)
    {
        MPOOL_UNLOCK();
        return NULL;
    }

    /* init for data linkptr */
    p_data_pool = _dal_mpool_create(((char*)base+DAL_MPOOL_MAX_DESX_SIZE), (size - DAL_MPOOL_MAX_DESX_SIZE), DAL_MPOOL_TYPE_DATA);
    if (NULL == p_data_pool)
    {
        MPOOL_UNLOCK();
        return NULL;
    }

    MPOOL_UNLOCK();

    return head;
}

dal_mpool_mem_t*
_dal_mpool_alloc_comon(dal_mpool_mem_t* ptr,  int size, int type)
{
    dal_mpool_mem_t* new_ptr = NULL;

    while (ptr && ptr->next)
    {
        if (ptr->next->address - (ptr->address + ptr->size) >= size)
        {
            break;
        }

        ptr = ptr->next;
    }

    if (!(ptr && ptr->next))
    {
        return NULL;
    }

    new_ptr = MALLOC(sizeof(dal_mpool_mem_t));
    if (!new_ptr)
    {
        return NULL;
    }

    new_ptr->type = type;
    new_ptr->address = ptr->address + ptr->size;
    new_ptr->size = size;
    new_ptr->next = ptr->next;
    ptr->next = new_ptr;

    return new_ptr;
}

void*
dal_mpool_alloc(dal_mpool_mem_t* pool, int size, int type)
{
    dal_mpool_mem_t* ptr = NULL;
    dal_mpool_mem_t* new_ptr = NULL;
    int mod;

    MPOOL_LOCK();

    mod = size & (DAL_CACHE_LINE_BYTES - 1);
    if (mod != 0)
    {
        size += (DAL_CACHE_LINE_BYTES - mod);
    }

    switch(type)
    {
        case DAL_MPOOL_TYPE_USELESS:
            ptr = pool;
            new_ptr = _dal_mpool_alloc_comon(ptr, size, type);
            if (NULL == new_ptr)
            {
                MPOOL_UNLOCK();
                return NULL;
            }
            break;
        case DAL_MPOOL_TYPE_DESC:
            ptr = p_desc_pool;
            new_ptr = _dal_mpool_alloc_comon(ptr, size, type);
            if (NULL == new_ptr)
            {
                MPOOL_UNLOCK();
                return NULL;
            }
            break;
        case DAL_MPOOL_TYPE_DATA:
            ptr = p_data_pool;
            new_ptr = _dal_mpool_alloc_comon(ptr, size, type);
            if (NULL == new_ptr)
            {
                MPOOL_UNLOCK();
                return NULL;
            }
            break;
        default:
            break;
    }

    MPOOL_UNLOCK();

    return new_ptr->address;
}

void
_dal_mpool_free(dal_mpool_mem_t* ptr, void* addr, int type)
{
    unsigned char* address = (unsigned char*)addr;
    dal_mpool_mem_t* prev = NULL;

    while (ptr && ptr->next)
    {
        if (ptr->next->address == address)
        {
            break;
        }

        ptr = ptr->next;
    }

    if (ptr && ptr->next)
    {
        prev = ptr;
        ptr = ptr->next;
        prev->next = ptr->next;
        FREE(ptr);
    }

    return;
}

void
dal_mpool_free(dal_mpool_mem_t* pool, void* addr)
{
    dal_mpool_mem_t* ptr = pool;

    MPOOL_LOCK();

    switch(pool->type)
    {
        case DAL_MPOOL_TYPE_USELESS:
            ptr = pool;
            _dal_mpool_free(ptr, addr, DAL_MPOOL_TYPE_USELESS);
            break;
        case DAL_MPOOL_TYPE_DESC:
            ptr = p_desc_pool;
            _dal_mpool_free(ptr, addr, DAL_MPOOL_TYPE_DESC);
            break;
        case DAL_MPOOL_TYPE_DATA:
            ptr = p_data_pool;
            _dal_mpool_free(ptr, addr, DAL_MPOOL_TYPE_DATA);
            break;
        default:
            break;
    }

    MPOOL_UNLOCK();
    return;
}

int
dal_mpool_destroy(dal_mpool_mem_t* pool)
{
    dal_mpool_mem_t* ptr, * next;

    MPOOL_LOCK();

    for (ptr = pool; ptr; ptr = next)
    {
        next = ptr->next;
        FREE(ptr);
    }

    for (ptr = p_desc_pool; ptr; ptr = next)
    {
        next = ptr->next;
        FREE(ptr);
    }

    for (ptr = p_data_pool; ptr; ptr = next)
    {
        next = ptr->next;
        FREE(ptr);
    }

    MPOOL_UNLOCK();

    return 0;
}

int
dal_mpool_usage(dal_mpool_mem_t* pool, int type)
{
    int usage = 0;
    dal_mpool_mem_t* ptr;

    MPOOL_LOCK();

    for (ptr = pool; ptr; ptr = ptr->next)
    {
        if (ptr->type == type || ptr->type == -1)
        {
            usage += ptr->size;
        }
    }

    MPOOL_UNLOCK();

    return usage;
}

int
dal_mpool_debug(dal_mpool_mem_t* pool)
{
    dal_mpool_mem_t* ptr;
    int index = 0;

    MPOOL_LOCK();

    for (ptr = pool; ptr; ptr = ptr->next)
    {
//        DAL_PRINT("%2dst mpool block: address=0x%8x, size=0x%x \n", index, (unsigned int)ptr->address, ptr->size);
	 DAL_PRINT("%2dst mpool block: address=0x%p, size=0x%x \n", index, ptr->address, ptr->size); // note
        index++;
    }

    MPOOL_UNLOCK();

    return 0;
}

