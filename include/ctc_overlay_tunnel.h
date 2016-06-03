/**
 @file ctc_overlay_tunnel.h

 @author  Copyright(C) 2005-2013 Centec Networks Inc.  All rights reserved.

 @date 2013-10-25

 @version v2.0

   This file contains all overlay network tunnel such as nvgre, vxlan related data structure, enum, macro and proto.
*/

/****************************************************************
*
* Defines and Macros
*
****************************************************************/
/**
 @defgroup overlay_tunnel OVERLAY_TUNNEL
 @{
*/

#ifndef _CTC_OVERLAY_TUNNEL_H
#define _CTC_OVERLAY_TUNNEL_H
#ifdef __cplusplus
extern "C" {
#endif

#include "sal_types.h"
#include "ctc_const.h"

/**
 @brief define the protocol type of overlay network tunnel
*/
enum ctc_overlay_tunnel_type_e
{
    CTC_OVERLAY_TUNNEL_TYPE_NVGRE,   /**< [GG] Use to set an NvGRE overlay network tunnel */
    CTC_OVERLAY_TUNNEL_TYPE_VXLAN,   /**< [GG] Use to set a VxLAN/VxLAN-GPE overlay network tunnel */
    CTC_OVERLAY_TUNNEL_TYPE_GENEVE, /**< [GG] Use to set a GENEVE overlay network tunnel */
    CTC_OVERLAY_TUNNEL_TYPE_MAX
};
typedef enum ctc_overlay_tunnel_type_e  ctc_overlay_tunnel_type_t;

/**
 @brief define flags for overlay tunnel encapsulate
*/
enum ctc_overlay_tunnel_flag_e
{
    CTC_OVERLAY_TUNNEL_FLAG_IP_VER_6                      = 0x0001,   /**< [GG] Overlay network tunnel is deal with ipv6 packet */
    CTC_OVERLAY_TUNNEL_FLAG_OUTPUT_NHID                   = 0x0002,   /**< [GG] Overlay network tunnel decap and lookup by out header */
    CTC_OVERLAY_TUNNEL_FLAG_TTL_CHECK                     = 0x0004,   /**< [GG] Overlay network tunnel do TTL check for out header */
    CTC_OVERLAY_TUNNEL_FLAG_USE_OUTER_TTL                 = 0x0008,   /**< [GG] Overlay network tunnel will use outer header TTL */
    CTC_OVERLAY_TUNNEL_FLAG_USE_IPSA                      = 0x0010,   /**< [GG] Overlay network tunnel decap with ipsa */
    CTC_OVERLAY_TUNNEL_FLAG_ACL_LKUP_BY_OUTER_HEAD        = 0x0020,   /**< [GG] Overlay network tunnel use outer header info do acl lookup */
    CTC_OVERLAY_TUNNEL_FLAG_OVERWRITE_PORT_HASH_LKUP_PROP = 0x0040,   /**< [GG] Overlay network tunnel overwrite acl port hash property */
    CTC_OVERLAY_TUNNEL_FLAG_OVERWRITE_PORT_TCAM_LKUP_PROP = 0x0080,   /**< [GG] Overlay network tunnel overwrite acl port TCAM property */
    CTC_OVERLAY_TUNNEL_FLAG_STATS_EN                      = 0x0100,   /**< [GG] Overlay network tunnel enable stats */
    CTC_OVERLAY_TUNNEL_FLAG_SERVICE_POLICER_EN            = 0x0200,   /**< [GG] Overlay network tunnel enable service policer */
    CTC_OVERLAY_TUNNEL_FLAG_SERVICE_ACL_EN                = 0x0400,   /**< [GG] Overlay network tunnel enable service acl */
    CTC_OVERLAY_TUNNEL_FLAG_METADATA_EN                   = 0x0800,   /**< [GG] Overlay network tunnel enable metadata for open flow */
    CTC_OVERLAY_TUNNEL_FLAG_VRF                           = 0x1000,   /**< [GG] Means config VRFID */
    CTC_OVERLAY_TUNNEL_FLAG_USE_FLEX                      = 0x2000,   /**< [GG] Means use tcam. It can used for solve hash conflict */
    CTC_OVERLAY_TUNNEL_FLAG_ACL_FLOW_TCAM_EN              = 0x4000,   /**< [GG] Enable acl flow tcam lookup */
    CTC_OVERLAY_TUNNEL_FLAG_ACL_FLOW_HASH_EN              = 0x8000,   /**< [GG] Enable acl flow hash lookup */
    CTC_OVERLAY_TUNNEL_FLAG_QOS_USE_OUTER_INFO            = 0x10000   /**< [GG] Use outer info(dscp/cos) do qos classification */
};
typedef enum ctc_overlay_tunnel_flag_e ctc_overlay_tunnel_flag_t;

/**
 @brief define lookup key type for tunnel decapsulate
*/
enum ctc_overlay_tunnel_decap_mode_flag_e
{
    CTC_OVERLAY_TUNNEL_DECAP_BY_IPDA_VNI              = 0x01, /**< [GG] Decap pacekt use ipda and vni as key if set; otherwise use ipda, ipsa and vni */
    CTC_OVERLAY_TUNNEL_DECAP_IPV4_UC_USE_INDIVIDUL_IPDA                = 0x02  /**< [GG] Decap IPv4 uc pacekt use individual ipda if set; otherwise use share ipda */
};
typedef enum ctc_overlay_tunnel_decap_mode_flag_e ctc_overlay_tunnel_decap_mode_flag_t;

/**
 @brief define overlay tunnel decap structure used in APIs
*/
struct ctc_overlay_tunnel_global_cfg_s
{
    uint8  nvgre_mode;          /**< [GG] Global config for NvGRE tunnel decapsulate mode bitmap of ctc_overlay_tunnel_decap_mode_t */
    uint8  vxlan_mode;          /**< [GG] Global config for VxLAN/VxLAN-GPE/GENEVE tunnel decapsulate mode bitmap of ctc_overlay_tunnel_decap_mode_t */
    uint8  rsv0[2];
};
typedef struct ctc_overlay_tunnel_global_cfg_s ctc_overlay_tunnel_global_cfg_t;

/**
 @brief define overlay tunnel decap structure used in APIs
*/
struct ctc_overlay_tunnel_param_s
{
    /* key */
    uint8 type;           /**< [GG] The protocol to set must ctc_overlay_tunnel_type_t */
    uint8 scl_id;         /**< [GG] There are 2 scl lookup<0-1>, and each has its own feature, only for tcam key */
    uint8 logic_port_type; /**< [GG] If set, means do horizon split*/
    uint8 rsv0;

    uint32 flag;          /**< [GG] The flags of tunnel decap must ctc_overlay_tunnel_flag_t */
    uint32 src_vn_id;     /**< [GG] vn_id of this key, source vn_id */
    union
    {
        ip_addr_t ipv4;   /**< [GG] IPv4 source address */
        ipv6_addr_t ipv6; /**< [GG] IPv6 source address */
    } ipsa;

    union
    {
        ip_addr_t ipv4;   /**< [GG] IPv4 dest address */
        ipv6_addr_t ipv6; /**< [GG] IPv6 dest address */
    } ipda;

    /* action */
    union
    {
        uint32 dst_vn_id; /**< [GG] vn_id of destination, later fib lookup will based on this vn_id */
        uint32 nh_id;     /**< [GG] Nexthop for decap, packet will go out directly by this nexthop */
    }action;

    uint16 logic_src_port;/**< [GG] Logic source port for the tunnel */
    uint16 stats_id;      /**< [GG] Stats id for the tunnel */

    uint16 policer_id;    /**< [GG] Service id for service queue/policer */
    uint16 vrf_id;            /**< [GG] Vrf ID of the tunnel route when set CTC_OVERLAY_TUNNEL_FLAG_VRF */

    uint8  inner_taged_chk_mode;   /**< [GG] Check mode for inner packet with vlan tag,
                                           0:No check; 1:discard; 2:forward to CPU; 3:copy to CPU */
    uint8  rsv1;
    uint16 metadata;      /**< [GG] Metadata used for open flow */

    uint8 acl_tcam_label;            /**< [GG] Acl label */
    uint8 acl_tcam_lookup_type;      /**< [GG] Acl tcam lookup type must be CTC_ACL_TCAM_LKUP_TYPE_XXX */
    uint8 acl_hash_lookup_type;      /**< [GG] Acl hash lookup type must be CTC_ACL_HASH_LKUP_TYPE_XXX */
    uint8 field_sel_id;              /**< [GG] Acl hash field sel id */

    mac_addr_t route_mac;    /* [GG] Route mac for inner packet, 0.0.0 means disable*/
};
typedef struct ctc_overlay_tunnel_param_s ctc_overlay_tunnel_param_t;


/**@} end of @defgroup  overlay_tunnel OVERLAY_TUNNEL */
#ifdef __cplusplus
}
#endif

#endif

