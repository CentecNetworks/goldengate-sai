/**
 @file ctc_fcoe.h

 @author Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2015-09-29

 @version v2.0

   This file contains all fcoe related data structure, enum, macro and proto.
*/

#ifndef _CTC_FCOE_H
#define _CTC_FCOE_H
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
/**
 @defgroup fcoe fcoe
 @{
*/


/**
 @brief  Define fcoe route flags
*/
enum ctc_fcoe_flag_e
{
    CTC_FCOE_FLAG_DST_DISCARD        = 0x01,      /**< [GG][da] Destination FC-ID match discard */
    CTC_FCOE_FLAG_RPF_CHECK          = 0x02,      /**< [GG][sa] Do RPF source port check */
    CTC_FCOE_FLAG_MACSA_CHECK        = 0x04,      /**< [GG][sa] Do MAC-SA check */
    CTC_FCOE_FLAG_SRC_DISCARD        = 0x08       /**< [GG][sa] Source FC-ID match discard */
};
typedef enum ctc_fcoe_flag_e ctc_fcoe_flag_t;


/**
 @brief  Define fcoe parameter structure
*/
struct ctc_fcoe_route_s
{
    uint32 flag;                    /**< [GG] Flags of the route, values is defined by ctc_fcoe_flag_t */
    uint32 fcid;                    /**< [GG] Dest/Source FC-ID, 0 is default route */
    uint16 fid;                      /**< [GG] Vid or fid */
    uint8 rsv0[2];
    uint32 nh_id;                 /**< [GG] Nexthop ID */
    uint32 src_gport;          /**< [GG] RPF check source gport */
    mac_addr_t mac_sa;          /**< [GG] Check MAC-SA */
};
typedef struct ctc_fcoe_route_s ctc_fcoe_route_t;


/**@} end of @defgroup  fcoe fcoe */

#ifdef __cplusplus
}
#endif

#endif  /*_CTC_FCOE_H*/

