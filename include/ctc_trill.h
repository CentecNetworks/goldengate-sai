/**
 @file ctc_trill.h

 @author  Copyright(C) 2005-2013 Centec Networks Inc.  All rights reserved.

 @date 2013-10-25

 @version v3.0

   This file contains trill related data structure, enum, macro and proto.
*/

/****************************************************************
*
* Defines and Macros
*
****************************************************************/
/**
 @defgroup trill TRILL
 @{
*/

#ifndef _CTC_TRILL_H
#define _CTC_TRILL_H
#ifdef __cplusplus
extern "C" {
#endif

#include "sal_types.h"
#include "ctc_const.h"

/**
 @brief define flags for trill route
*/
enum ctc_trill_route_flag_e
{
    CTC_TRILL_ROUTE_FLAG_DISCARD                 = 0x00000001, /**< [GG] Indicates discard the packet*/
    CTC_TRILL_ROUTE_FLAG_MCAST                   = 0x00000002, /**< [GG] Indicates mcast*/
    CTC_TRILL_ROUTE_FLAG_SRC_PORT_CHECK          = 0x00000004, /**< [GG] Source gport check*/
    CTC_TRILL_ROUTE_FLAG_MACSA_CHECK             = 0x00000008, /**< [GG] Outer MACSA check*/
    CTC_TRILL_ROUTE_FLAG_MAX
};
typedef enum ctc_trill_route_flag_e ctc_trill_route_flag_t;


/**
 @brief  Define trill route structure
*/
struct ctc_trill_route_s
{
    uint32 flag;                 /**< [GG] Refer to ctc_trill_route_flag_t*/

    uint16 egress_nickname;      /**< [GG] Egress nickname*/
    uint16 ingress_nickname;     /**< [GG] Ingress nickname*/

    uint16  vlan_id;             /**< [GG] Inner vlan ID*/
    uint8 rsv[2];

    uint32 nh_id;                /**< [GG] Nexthop ID*/
    uint32 src_gport;            /**< [GG] Source gport*/

    mac_addr_t  mac_sa;          /**< [GG] Outer MACSA*/
};
typedef struct ctc_trill_route_s ctc_trill_route_t;


/**
 @brief define flags for trill tunnel
*/
enum ctc_trill_tunnel_flag_e
{
    CTC_TRILL_TUNNEL_FLAG_MCAST                  = 0x00000001, /**< [GG] Indicates mcast tunnel*/
    CTC_TRILL_TUNNEL_FLAG_MAX
};
typedef enum ctc_trill_tunnel_flag_e ctc_trill_tunnel_flag_t;

/**
 @brief  Define trill tunnel structure
*/
struct ctc_trill_tunnel_s
{
    uint32 flag;                 /**< [GG] Refer to ctc_trill_tunnel_flag_t*/

    uint16 egress_nickname;      /**< [GG] Egress nickname*/
    uint16 ingress_nickname;     /**< [GG] Ingress nickname*/

    uint32 nh_id;                /**< [GG] Nexthop for decap, packet will go out directly by this nexthop */

    uint16  fid;                 /**< [GG] Forwarding instance after decap*/
    uint16 logic_src_port;       /**< [GG] Logic source port for the TRILL tunnel */

    uint16 stats_id;             /**< [GG] Stats id for the tunnel */
    uint8 rsv[2];

};
typedef struct ctc_trill_tunnel_s ctc_trill_tunnel_t;

/**@} end of @defgroup  trill TRILL */
#ifdef __cplusplus
}
#endif

#endif

