/****************************************************************************
 * memmgr.h      memory manager defines and macros.
 *
 * Copyright (C) 2011 Centec Networks Inc.  All rights reserved.
 *
 * Modify History:
 * Revision:     R0.01.
 * Author:       Zhu Zhengdong.
 * Date:         2007-3-22.
 * Reason:       First Create.
 ****************************************************************************/
#ifndef _SAL_MEMMGR_H_
#define _SAL_MEMMGR_H_
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
 *
* Header Files
*
****************************************************************************/
#include "sal_mutex.h"
#include "sal_slab.h"

/* block sizes */

#define    MEM_BLK_4_SIZE      4
#define    MEM_BLK_8_SIZE      8
#define    MEM_BLK_16_SIZE     16
#define    MEM_BLK_32_SIZE     32
#define    MEM_BLK_64_SIZE     64
#define    MEM_BLK_96_SIZE     96
#define    MEM_BLK_128_SIZE    128
#define    MEM_BLK_192_SIZE    192
#define    MEM_BLK_256_SIZE    256
#define    MEM_BLK_384_SIZE    384
#define    MEM_BLK_512_SIZE    512
#define    MEM_BLK_768_SIZE    768
#define    MEM_BLK_1K_SIZE     1024
#define    MEM_BLK_1536_SIZE   1536
#define    MEM_BLK_2K_SIZE     2048
#define    MEM_BLK_4K_SIZE     4096
#define    MEM_BLK_8K_SIZE     8192
#define    MEM_BLK_16K_SIZE    16384
#define    MEM_BLK_32K_SIZE    32768
#define    MEM_BLK_64K_SIZE    65536
#define    MEM_BLK_124K_SIZE   126976
#define    MEM_BLK_INVALID_SIZE 0xFFFFFFFF
/* block count */
#define    MEM_BLK_4_COUNT      1024
#define    MEM_BLK_8_COUNT      1024
#define    MEM_BLK_16_COUNT     8092
#define    MEM_BLK_32_COUNT     16384
#define    MEM_BLK_64_COUNT     16384
#define    MEM_BLK_96_COUNT     16384
#define    MEM_BLK_128_COUNT    8192
#define    MEM_BLK_192_COUNT    8192
#define    MEM_BLK_256_COUNT    1024
#define    MEM_BLK_384_COUNT    1024
#define    MEM_BLK_512_COUNT    1024
#define    MEM_BLK_768_COUNT    256
#define    MEM_BLK_1K_COUNT     256
#define    MEM_BLK_1536_COUNT   128
#define    MEM_BLK_2K_COUNT     128
#define    MEM_BLK_4K_COUNT     64
#define    MEM_BLK_8K_COUNT     0
#define    MEM_BLK_16K_COUNT    0
#define    MEM_BLK_32K_COUNT    0
#define    MEM_BLK_64K_COUNT    0
#define    MEM_BLK_124K_COUNT   0

#define    MEM_PRE_GUARD_AREA   8
#define    MEM_POST_GUARD_AREA  8

#define    MEM_MAX_NAME_SIZE    20

#define MEM_RUNTIME_CHECK 0

#define MAX_MEM_FILE_SZ 20

#define MAX_MEM_SIZE 0

#define MEM_CHECK_MEM_SIZE

#define BUCKET_NAME "bucket"

#define MEM_HEADER_MAGIC_NUMBER 0xA1D538FA
#define MEM_TAIL_MAGIC_NUMBER   0xA1D538FB

#define MEMMGR_LOCK(ptr) \
    if (ptr != NULL) sal_mutex_lock(ptr)

#define MEMMGR_UNLOCK(ptr) \
    if (ptr != NULL) sal_mutex_unlock(ptr)

/****************************************************************
*
* Defines and Macros
*
****************************************************************/
#ifdef _SAL_LINUX_UM
#ifndef MEMMGR
#define MEMMGR
#endif
#else
#undef MEMMGR
#endif

#ifdef MEMMGR
#define mem_malloc(type, size) mem_mgr_malloc(size, type, __FILE__, __LINE__)
#define mem_free(ptr)   \
    { \
        mem_mgr_free(ptr, __FILE__,  __LINE__); \
        ptr = NULL; \
    }
#define mem_realloc(type, ptr, size) mem_mgr_realloc(type, ptr, size, __FILE__,  __LINE__)
#else
#define mem_malloc(type, size)  sal_malloc(size)
#define mem_free(ptr)   \
    { \
        sal_free(ptr); \
        ptr = NULL; \
    }
#define mem_realloc(type, ptr, size) sal_realloc(ptr, size)
#endif

#define CTC_MEMMNGR_DBG_INFO(FMT, ...)                          \
    { \
        CTC_DEBUG_OUT_INFO(memmngr, memmngr, MEMMNGR_CTC, FMT, ##__VA_ARGS__); \
    }

/* bucket array indices */

#if MEM_RUNTIME_CHECK

/*
 *  Mtype memory debug information for tracing back each memory allocation
 *  or freeing to a filename and line number at which it is initiated. This
 *  information is appended at the end of each memblock. This feature is
 *  used only for internal builds.
 */
struct mem_block_trailer
{
    uint32  guard;
    uint16 line_number;
    uint8 rsv[2];
    char filename[MAX_MEM_FILE_SZ];
};
#endif

/*
 *  Memory manager table for holding stats for each mtype.
 *   - allocated table is based on mtype
 *   - free tbale is based on buckets having fixed size blocks.
 */
struct mem_table
{
    void* list;           /* points to mtype memory list */
    uint32    size;       /* total size of memory allocated or free */
    uint32    req_size;   /* total user requested size */
    uint32    count;      /* number of blocks allocated or free */
    sal_mutex_t* p_mem_mutex;
};
typedef struct mem_table mem_table_t;

/*
 *  This header precedes each user buffer.  This header size must be multiple of
 *  16 bytes to avoid alignment exceptions.
 */
struct mem_block_header
{
    uint8    bukt;             /* bucket index */
    uint8    mid;              /* mtype id */
    uint16   rsv;
#if MEM_RUNTIME_CHECK
    struct mem_block_header* next;   /* linked list pointer */
    struct mem_block_header* prev;
    uint32    req_size;         /* user requested size */
    uint32    guard;
#endif
};

enum mem_mgr_type
{
    MEM_SYSTEM_MODULE,
    MEM_FDB_MODULE,
    MEM_MPLS_MODULE,
    MEM_QUEUE_MODULE,
    MEM_IPUC_MODULE,
    MEM_IPMC_MODULE,
    MEM_RPF_MODULE,
    MEM_NEXTHOP_MODULE,
    MEM_AVL_MODULE,
    MEM_STATS_MODULE,
    MEM_L3IF_MODULE,
    MEM_PORT_MODULE,
    MEM_VLAN_MODULE,
    MEM_APS_MODULE,
    MEM_VPN_MODULE,
    MEM_SORT_KEY_MODULE,
    MEM_LINKAGG_MODULE,
    MEM_USRID_MODULE,
    MEM_SCL_MODULE,
    MEM_ACL_MODULE,
    MEM_LINKLIST_MODULE,
    MEM_CLI_MODULE,
    MEM_VECTOR_MODULE,
    MEM_HASH_MODULE,
    MEM_SPOOL_MODULE,
    MEM_OPF_MODULE,
    MEM_SAL_MODULE,
    MEM_OAM_MODULE,
    MEM_PTP_MODULE,
    MEM_FTM_MODULE,
    MEM_STK_MODULE,
    MEM_LIBCTCCLI_MODULE,
    MEM_DMA_MODULE,
    MEM_STMCTL_MODULE,
    MEM_L3_HASH_MODULE,
    MEM_FPA_MODULE,
    MEM_MIRROR_MODULE,
    MEM_SYNC_ETHER_MODULE,
    MEM_APP_MODULE,
    MEM_MONITOR_MODULE,
    MEM_OVERLAY_TUNNEL_MODULE,
    MEM_EFD_MODULE,
    MEM_IPFIX_MODULE,
    MEM_TRILL_MODULE,
    MEM_FCOE_MODULE,
    MEM_TYPE_MAX

};

struct bucket_info_s
{
    uint32 block_size;
    uint32 block_count;
    uint32 used_count;
    int8 name[MEM_MAX_NAME_SIZE];
#ifndef _SAL_VXWORKS
#ifdef SDK_IN_KERNEL
    sal_mem_pool_t* mem_pool;
#else
    mem_cache_t* cache;
    sal_mutex_t* cache_mutex;
#endif
#endif
};
typedef struct bucket_info_s bucket_info_t;

struct mem_type_name_s
{
    enum mem_mgr_type mtype;
    int8 name[40];
};
typedef struct mem_type_name_s mem_type_name_t;
/*Add by guoyh for memory check, 2009-11-23*/
void* pal_mem_malloc(uint32 size, enum mem_mgr_type mtype);
int32 mem_mgr_init(void);
int32 mem_mgr_deinit(void);
void mem_mgr_free(void* ptr, char* file, int line);
void* mem_mgr_malloc(uint32 size, enum mem_mgr_type mtype, char* filename, uint16 line);
void* mem_mgr_realloc(uint32 mtype, void* ptr, uint32 size, char* filename, uint16 line);
void mem_mgr_check_mtype(enum mem_mgr_type mtype, bool is_show_detail);
void mem_show_bucket_used_count();
int32 mem_get_bucket_used_info(bucket_info_t* bucket_used_info, uint8 index);
int32 mem_mgr_get_mtype_info(enum mem_mgr_type mtype, mem_table_t* p_mtype_table_info, int8** m_name);

#ifdef __cplusplus
}
#endif

#endif

