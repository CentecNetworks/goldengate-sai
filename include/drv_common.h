/**
 @file

 @date 2010/02/22

 @version v5.1

 This file contains those macro & enum definitions and global var
*/

#ifndef _DRV_COMMON_H_
#define _DRV_COMMON_H_

#include "sal.h"
#include "drv_error.h"
//#include "drv_tbl_reg.h"

#define ZHOUW_NOTE 0
#define XUZX_NOTE 0
#define CMODEL_CAN_NOT_REALIZE 0
#define V5_8_NOTE 0
#define IS_RTL_REGISTER 0
#define COSIM_DBG_FLAG 1
#define V5_15_NOTE 0
/*SDK Modify {*/
#define SDK_COSIM 0
#define SDK_DEBUG 1
/*SDK Modify }*/
/**********************************************************************************
              Define Typedef, define and Data Structure
***********************************************************************************/
#define MAX_LOCAL_CHIP_NUM 8
#define MAX_LOCAL_PORT_NUM 256

#define MAX_ENTRY_WORD 128    /**< define table/reg entry's max words */
#define MAX_ENTRY_BYTE 128   /**< define table/reg entry's max bytes */

#define CONDITIONAL_BREAK(exp)      if((exp)) break
#define CONDITIONAL_CONTINUE(exp)   if((exp)) continue

#define DRV_HASH_INVALID_INDEX 0xFFFFFFFF  /* HASH invalid index */
#define DRV_TCAM_INVALID_INDEX 0xFFFFFFFF  /* TCAM invalid index */

/* directions */
#define DRV_IOC_READ          1U
#define DRV_IOC_WRITE         2U

#define DRV_IOC_DIR_BITS      2
#define DRV_IOC_MEMID_BITS    13
#define DRV_IOC_FIELDID_BITS  16
#define DRV_ENTRY_FLAG        0x1FFF   /* when fieldid equals this value, it represent
                                          the operation is applied to the whole entry */

#define DRV_IOC_DIR_MASK     ((1 << DRV_IOC_DIR_BITS)-1)
#define DRV_IOC_MEMID_MASK   ((1 << DRV_IOC_MEMID_BITS)-1)
#define DRV_IOC_FIELDID_MASK ((1 << DRV_IOC_FIELDID_BITS)-1)

#define DRV_IOC_FIELDID_SHIFT 0
#define DRV_IOC_MEMID_SHIFT  (DRV_IOC_FIELDID_SHIFT + DRV_IOC_FIELDID_BITS)
#define DRV_IOC_DIR_SHIFT    (DRV_IOC_MEMID_SHIFT + DRV_IOC_MEMID_BITS)

#define DRV_IOC_OP(cmd)      (((cmd) >> DRV_IOC_DIR_SHIFT)&DRV_IOC_DIR_MASK)
#define DRV_IOC_MEMID(cmd)   (((cmd) >> DRV_IOC_MEMID_SHIFT)&DRV_IOC_MEMID_MASK)
#define DRV_IOC_FIELDID(cmd) (((cmd) >> DRV_IOC_FIELDID_SHIFT)&DRV_IOC_FIELDID_MASK)

#define DRV_IOC(dir, memid, fieldid) \
    (((dir) << DRV_IOC_DIR_SHIFT) | \
    ((memid) << DRV_IOC_MEMID_SHIFT) | \
    ((fieldid) << DRV_IOC_FIELDID_SHIFT))

#define DRV_IOR(memid, fieldid) DRV_IOC(DRV_IOC_READ, (memid), (fieldid))
#define DRV_IOW(memid, fieldid) DRV_IOC(DRV_IOC_WRITE, (memid), (fieldid))

#define DRV_IOCREAT(memid, ptr) \
    do\
    {\
        int size;\
        size = TABLE_ENTRY_SIZE(memid);\
        ptr = sal_malloc(size);\
        if (ptr == NULL)\
        {\
            return DRV_E_INVALID_PTR;\
        }\
        sal_memset(ptr, 0, size);\
    }\
    while(0)

#define DRV_IOW_FIELD(memid, fieldid, value, ptr) \
    do\
    {\
        int retv = 0;\
        retv = drv_set_field(memid, fieldid, ptr, value);\
        if (retv < 0)\
        {\
            return(retv); \
        }\
    }\
    while(0)

#define DRV_IOR_FIELD(memid, fieldid, value, ptr) \
    do\
    {\
        int retv = 0;\
        retv = drv_get_field(memid, fieldid, ptr, value);\
        if (retv < 0)\
        {\
            return(retv); \
        }\
    }\
    while(0)

#define DRV_IODESTORY(ptr) \
    do\
    {\
        sal_free(ptr);\
        ptr = NULL;\
    }\
    while(0)


/* Tcam data mask storage structure */
struct tbl_entry_s
{
    uint32* data_entry;
    uint32* mask_entry;
};
typedef struct tbl_entry_s tbl_entry_t;

/* driver initialize chip info.
   (include initialized chip number and chipID base value) */
struct drv_init_chip_info_s
{
    uint8 drv_init_chip_num;
    uint8 drv_init_chipid_base;
    uint16 reserved;
};
typedef struct drv_init_chip_info_s drv_init_chip_info_t;


/**
 @brief check whether the operation's return value is error or not
*/
#define DRV_IF_ERROR_RETURN(op) \
do\
{ \
    int32 rv; \
    if ((rv = (op)) < 0) \
    { \
        return(rv); \
    }\
}\
while(0)

/**
 @brief check whether the operation's return value is error or not. If error, then unlock
*/
#define DRV_IF_ERROR_RETURN_WITH_UNLOCK(op, lock) \
    { \
        int32 rv; \
        if ((rv = (op)) < 0)  \
        {  \
            sal_mutex_unlock(lock); \
            return rv; \
        } \
    }

/**
 @brief check whether the operation's return value is error or not. If error, then free memory
*/
#define DRV_IF_ERROR_RETURN_AND_FREE(op, mem) \
    do \
    { \
        int32 rv; \
        if ((rv = (op)) < 0) \
        { \
            sal_free(mem); \
            return (rv); \
        } \
    } \
    while (0)
/**
 @brief define the pointer valid check
*/
#define DRV_PTR_VALID_CHECK(ptr)\
if (NULL == (ptr))\
{\
    return DRV_E_INVALID_PTR;\
}

#define DRV_DBG_INFO(FMT, ...)                          \
                    do                                                     \
                    { \
                      sal_printf(FMT, ##__VA_ARGS__); \
                    } while (0)

#define DRV_DBG_FUNC()                          \
                    do \
                    {\
                         sal_printf("\n%s()\n", __FUNCTION__); \
                    } while (0)


#endif /*end of _DRV_COMMON_H*/

