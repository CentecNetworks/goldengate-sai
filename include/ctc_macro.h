/****************************************************************************
 *file ctc_macro.h

 *author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 *date 2009-11-26

 *version v2.0

The file define  all CTC SDK module's  common Macros
 ****************************************************************************/

#ifndef _CTC_MACRO_H
#define _CTC_MACRO_H
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************
 *
 * Header Files
 *
 ***************************************************************/
#include "sal_types.h"

/****************************************************************
*
* Defines and Macros
*
****************************************************************/
#define CTC_ETH_ADDR_LEN                 6
#define CTC_MAX_CHIP_NAME_LEN           32

/* define bit operations  */
#define CTC_IS_BIT_SET(flag, bit)   (((flag) & (1 << (bit))) ? 1 : 0)
#define CTC_BIT_SET(flag, bit)      ((flag) = (flag) | (1 << (bit)))
#define CTC_BIT_UNSET(flag, bit)    ((flag) = (flag) & (~(1 << (bit))))

#define CTC_SET_FLAG(VAL, FLAG)          (VAL) = (VAL) | (FLAG)
#define CTC_UNSET_FLAG(VAL, FLAG)        (VAL) = (VAL)&~(FLAG)
#define CTC_FLAG_ISSET(VAL, FLAG)        (((VAL)&(FLAG)) == (FLAG))


/*define make uint32, uint16 operation*/
#define CTC_MAKE_UINT16(hb, lb) (((hb) << 8) | (lb))
#define CTC_MAKE_UINT32(b3, b2, b1, b0) (((b3) << 24) | ((b2) << 16)\
                                       | ((b1) << 8) | (b0))


/* define bitmap array operation */
/* internal used */
#define _CTC_BMP_OP(_bmp, _offset, _op)     \
    (_bmp[(_offset) / CTC_UINT32_BITS] _op(1U << ((_offset) % CTC_UINT32_BITS)))

/* bmp should be a array of uint32, e.g. uint32 bmp[2] */

/* init bitmap */
#define CTC_BMP_INIT(bmp)                   \
    sal_memset((bmp), 0, sizeof((bmp)));

/* check bitmap */
#define CTC_BMP_OFFSET_CHECK(bmp, offset)   \
    ((0 <= offset) && ((offset) < CTC_BMP_BITS(bmp)))

/* set bit */
#define CTC_BMP_SET(bmp, offset)            \
    _CTC_BMP_OP((bmp), (offset), |= )

/* unset bit */
#define CTC_BMP_UNSET(bmp, offset)          \
    _CTC_BMP_OP((bmp), (offset), &= ~)

/* get bit set */
#define CTC_BMP_ISSET(bmp, offset)          \
    _CTC_BMP_OP((bmp), (offset), &)

/* get bit count */
#define CTC_BMP_BITS(bmp)                   \
    ((CTC_UINT32_BITS * sizeof((bmp)) / sizeof(uint32)))

/* bit iterate begin */
#define CTC_BMP_ITER_BEGIN(bmp, offset)                             \
    do {                                                                \
        for ((offset) = 0; (offset) < CTC_BMP_BITS((bmp)); (offset)++)  \
            if (CTC_BMP_ISSET((bmp), (offset)))

/* bit iterate end */
#define CTC_BMP_ITER_END(bmp, offset)       \
    } while (0)

/* define port and linkagg operations  */
#define CTC_IS_LINKAGG_PORT(gport)   ((((gport) >> CTC_LOCAL_PORT_LENGTH) & CTC_LINKAGGID_MASK) == CTC_LINKAGG_CHIPID)
#define CTC_IS_CPU_PORT(gport)   ((((gport) >> (CTC_LOCAL_PORT_LENGTH + CTC_GCHIP_LENGTH + CTC_EXT_PORT_LENGTH + CTC_RSV_PORT_LENGTH)) & CTC_TYPE_PORT_MASK) == 0x1)
#define CTC_MAP_TID_TO_GPORT(tid)    ((tid) | (CTC_LINKAGG_CHIPID << CTC_LOCAL_PORT_LENGTH))

#define CTC_MAP_LPORT_TO_GPORT(gchip, lport)  (((((lport) >> CTC_LOCAL_PORT_LENGTH) & CTC_EXT_PORT_MASK) \
                                              << (CTC_LOCAL_PORT_LENGTH + CTC_GCHIP_LENGTH))           \
                                              | (((gchip) & CTC_GCHIP_MASK) << CTC_LOCAL_PORT_LENGTH)    \
                                              | ((lport) & CTC_LOCAL_PORT_MASK))

#define CTC_MAP_GPORT_TO_LPORT(gport)         ((((gport) >> (CTC_LOCAL_PORT_LENGTH + CTC_GCHIP_LENGTH)   \
                                               & CTC_EXT_PORT_MASK) << CTC_LOCAL_PORT_LENGTH)          \
                                               | ((gport) & CTC_LOCAL_PORT_MASK))

#define CTC_MAP_GPORT_TO_GCHIP(gport)         (((gport) >> CTC_LOCAL_PORT_LENGTH) & CTC_GCHIP_MASK)

#define CTC_GPORT_LINKAGG_ID(gport)           ((gport) & CTC_LINKAGGID_MASK)

#define CTC_GLOBAL_CHIPID_CHECK(gchip)      \
    if ((gchip == 0x1F) || (gchip > CTC_MAX_GCHIP_CHIP_ID))          \
    {                                       \
        return CTC_E_INVALID_GLOBAL_CHIPID; \
    }

#define CTC_GLOBAL_PORT_CHECK(gport)                                                          \
    if ((CTC_IS_LINKAGG_PORT(gport) && ((gport & CTC_LOCAL_PORT_MASK) > CTC_MAX_LINKAGG_ID))  \
       || (!CTC_IS_LINKAGG_PORT(gport) && (!CTC_IS_CPU_PORT(gport))&& ((CTC_MAP_GPORT_TO_GCHIP(gport) > CTC_MAX_GCHIP_CHIP_ID)   \
       || (CTC_MAP_GPORT_TO_LPORT(gport) >= MAX_PORT_NUM_PER_CHIP))))                        \
    {                                                                                         \
        return CTC_E_INVALID_GLOBAL_PORT;                                                     \
    }                                                                                         \

#define CTC_GPORT_CHECK_WITH_UNLOCK(gport, lock) \
    if ((CTC_IS_LINKAGG_PORT(gport) && ((gport & CTC_LOCAL_PORT_MASK) > CTC_MAX_LINKAGG_ID))  \
       || (!CTC_IS_LINKAGG_PORT(gport) && (!CTC_IS_CPU_PORT(gport)) && ((CTC_MAP_GPORT_TO_GCHIP(gport) > CTC_MAX_GCHIP_CHIP_ID)  \
       || (CTC_MAP_GPORT_TO_LPORT(gport) >= MAX_PORT_NUM_PER_CHIP))))                        \
    {                                                                                          \
        sal_mutex_unlock(lock);                                                                \
        return CTC_E_INVALID_GLOBAL_PORT;                                                      \
    }

/*   define mcast addr check  */
#define IS_MCAST_MAC_ADDR(mac0) (((mac0) & 0x1) == 1)

#define CTC_INTEGER_CMP(data1, data2) \
    { \
        if ((data1) > (data2)) \
        { \
            return 1; \
        } \
        else if ((data1) < (data2)) \
        { \
            return -1; \
        } \
        else \
        { \
        } \
    }

#define CTC_EQUAL_CHECK(item_1, item_2)               \
    {                                                \
        if ((item_1) != (item_2)){                          \
            return CTC_E_INVALID_PARAM;                \
        };                                            \
    }

#define CTC_NOT_EQUAL_CHECK(item_1, item_2)     \
    {                                           \
        if ((item_1) == (item_2)){                     \
            return CTC_E_INVALID_PARAM;            \
        };                                        \
    }

#define CTC_NOT_ZERO_CHECK(item) \
    { \
        if (0 == (item)){ \
            return CTC_E_INVALID_PARAM; \
        } \
    }

#define IPV4_MASK_TO_LEN(mask, len) \
    { \
        int32 i; \
        len = 0; \
        for (i = 31; i >= 0; i--) \
        { \
            if (CTC_IS_BIT_SET((mask), (uint32)i)) \
            {(len)++; } \
            else \
            {break; } \
        } \
    }

#define IPV6_MASK_TO_LEN(mask, len) \
    { \
        int32 i; \
        len = 0; \
        for (i = 127; i >= 0; i--) \
        { \
            if (CTC_IS_BIT_SET(mask[(3 - ((uint32)i) / 32)], ((uint32)i) % 32)) \
            {(len)++; } \
            else \
            {break; } \
        } \
    }

#define IPV4_LEN_TO_MASK(mask, len)  \
    {                           \
        (mask) = (len) ? ~((1 << (CTC_IPV4_ADDR_LEN_IN_BIT - (len))) - 1) : 0; \
    }

#define IPV6_LEN_TO_MASK(mask, len)  \
    {                           \
        uint8 feedlen = CTC_IPV6_ADDR_LEN_IN_BIT - (len); \
        uint8 sublen = feedlen % 32; \
        int16 index = feedlen / 32; \
        int16 i;                 \
        if (index < CTC_IPV6_ADDR_LEN) \
        { \
            (mask)[(uint16)index] = ~((1 << sublen) - 1); \
        } \
        for (i = 0; i < index; i++) \
        {                       \
            (mask)[(uint16)i] = 0;    \
        }                       \
        for (i = index + 1; i < CTC_IPV6_ADDR_LEN; i++) \
        {                       \
            (mask)[(uint16)i] = 0xffffffff; \
        }                       \
    }

/*alloc 1D pointer's memory */
#define MALLOC_POINTER(T, p) \
    { \
        p = (T*)mem_malloc(MEM_SYSTEM_MODULE, sizeof(T)); \
    }

/* free 1D pointer's memory*/
#define FREE_POINTER(p) \
    { \
        mem_free(p); \
    }

/* alloc 2D pointer's memory*/
#define MALLOC_2D_POINTER(T, pp, M, N) \
    { \
        int  i = 0; \
        int  j = 0; \
        pp = (T**)mem_malloc(MEM_SYSTEM_MODULE, M * sizeof(void*)); \
        if (pp != NULL) \
        { \
            for (i = 0; i < M; ++i) \
            { \
                pp[i] = (T*)mem_malloc(MEM_SYSTEM_MODULE, N * sizeof(T)); \
                if (pp[i] == NULL) \
                { \
                    for (j = 0; j < i; ++j) \
                    { \
                        mem_free(pp[j]); \
                        pp[j] = NULL; \
                    } \
                    mem_free(pp); \
                    pp = NULL; \
                    break; \
                } \
                else \
                { \
                    sal_memset(pp[i], 0, N * sizeof(T)); \
                } \
            } \
        } \
    }

/* free 2D pointer's memory*/
#define FREE_2D_POINTER(pp, M) \
    { \
        int  i = 0; \
        for (i = 0; i < (M); ++i) \
        { \
            mem_free(pp[i]); \
        } \
        mem_free(pp); \
    }


#define MALLOC_ZERO(_type_, _ptr_, _size_)           \
    {                                                \
        if (_size_)                                  \
        {                                            \
            (_ptr_) = mem_malloc((_type_), (_size_));\
            if ((_ptr_)){                                \
                sal_memset((_ptr_), 0, (_size_));        \
            }  else {                                    \
                sal_printf("Error: No memory! Fun:%s() Line:%d \n",__FUNCTION__, __LINE__);\
            }                                            \
        }                                                \
    }


#define CTC_BOTH_DIRECTION_CHECK(dir) \
    if ((dir) >= CTC_BOTH_DIRECTION) \
    { \
        return CTC_E_INVALID_PARAM; \
    }

#define CTC_PTR_VALID_CHECK(ptr) \
    if ((ptr) == NULL) \
    { \
        return CTC_E_INVALID_PTR; \
    }

#define CTC_ACL_VLAN_CLASS_ID_CHECK(id) \
    if (((id) < CTC_ACL_VLAN_CLASSID_MIN) || ((id) > CTC_ACL_VLAN_CLASSID_MAX)) \
    { \
        return CTC_E_INVALID_PARAM; \
    }

#define CTC_ACL_PORT_CLASS_ID_CHECK(id) \
    if (((id) < CTC_ACL_PORT_CLASSID_MIN) || ((id) > CTC_ACL_PORT_CLASSID_MAX)) \
    { \
        return CTC_E_INVALID_PARAM; \
    }

#define CTC_SCL_PORT_CLASS_ID_CHECK(id) \
    if (((id) < CTC_SCL_PORT_CLASSID_MIN) || ((id) > CTC_SCL_PORT_CLASSID_MAX)) \
    { \
        return CTC_E_INVALID_PARAM; \
    }

#define CTC_ACL_PBR_CLASS_ID_CHECK(id) \
    if ((id) > CTC_ACL_PBR_CLASSID_MAX) \
    { \
        return CTC_E_INVALID_PARAM; \
    }

/* max value is max valid value */
#define    CTC_MAX_VALUE_CHECK(var, max_value) \
    { \
        if ((var) > (max_value)){return CTC_E_INVALID_PARAM; } \
    }

#define    CTC_MIN_VALUE_CHECK(var, min_value)   \
    { \
        if ((var) < (min_value)){return CTC_E_INVALID_PARAM; } \
    }

#define    CTC_VALUE_RANGE_CHECK(var, min_value, max_value)   \
    { \
        if ((var) < (min_value) || (var) > (max_value)){return CTC_E_INVALID_PARAM; } \
    }

#define CTC_REV_CHECK(val)    \
    { \
        switch (val) \
        { \
        case 0xff: \
        case 0xffff: \
        case 0xffffffff: \
            return CTC_E_LESS_ZERO; \
        } \
    }

#define CTC_VLAN_RANGE_CHECK(val) \
    { \
        if ((val) < CTC_MIN_VLAN_ID || (val) > CTC_MAX_VLAN_ID){ \
            return CTC_E_VLAN_INVALID_VLAN_ID; } \
    }

#define CTC_COS_RANGE_CHECK(val) \
    { \
        if ((val) >= CTC_MAX_COS){ \
            return CTC_E_INVALID_COS; } \
    }

#define CTC_FID_RANGE_CHECK(val) \
    { \
        if ((val) > CTC_MAX_FID_ID){ \
            return CTC_E_FDB_INVALID_FID; } \
    }

#define CTC_VSI_RANGE_CHECK(val) \
    { \
        if ((val) == 0){ \
            return CTC_E_INVALID_PARAM; } \
    }

#define CTC_VRFID_RANGE_CHECK(val) \
    { \
        if ((val) > CTC_MAX_VRFID_ID){ \
            return CTC_E_VLAN_INVALID_VRFID; } \
    }

#define CTC_LOGIC_PORT_RANGE_CHECK(val) \
    { \
        if ((val) > CTC_MAX_LOGIC_PORT_ID){ \
            return CTC_E_VPLS_INVALID_VPLSPORT_ID; } \
    }

#define CTC_MTU_SIZE_RANGE_CHECK(val) \
    { \
        if ((val) > CTC_MAX_MTU_SIZE){ \
            return CTC_E_INVALID_MTU_SIZE; } \
    }

#define CTC_APS_GROUP_ID_CHECK(aps_group_id)  \
    { \
        if (aps_group_id >= CTC_MAX_APS_GROUP_NUM){ \
            return CTC_E_APS_INVALID_GROUP_ID; } \
    }

#define CTC_IP_VER_CHECK(ver)                     \
    {                                                 \
        if ((ver) >= MAX_CTC_IP_VER)                  \
        {                                             \
            return CTC_E_INVALID_PARAM;               \
        }                                             \
    }

#ifdef SDK_IN_KERNEL
#define CTC_EXPORT_SYMBOL(p_fun) EXPORT_SYMBOL(p_fun)
#else
#define CTC_EXPORT_SYMBOL(p_fun)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _CTC_MACRO_H*/

