/**
 @file ctc_ipuc.h

 @author Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2011-11-07

 @version v2.0

   This file contains all ipuc related data structure, enum, macro and proto.
*/

#ifndef _CTC_IPUC_H
#define _CTC_IPUC_H
#ifdef __cplusplus
extern "C" {
#endif
/****************************************************************
 *
 * Header Files
 *
 ***************************************************************/
#include "sal_types.h"
#include "ctc_const.h"

/****************************************************************
*
* Defines and Macros
*
****************************************************************/
/**
 @defgroup ipuc IPUC
 @{
*/


/**
 @brief  Define ipuc route flags
*/
enum ctc_ipuc_flag_e
{
    CTC_IPUC_FLAG_RPF_CHECK          = 0x01,      /**< [HB.GB.GG]This route will do RPF check */
    CTC_IPUC_FLAG_TTL_CHECK          = 0x02,      /**< [HB.GB]This route will do ttl check */
    CTC_IPUC_FLAG_ICMP_CHECK         = 0x04,      /**< [HB.GB.GG]This route will do icmp redirect check, only set for normal ipuc nexthop, not ecmp nexthop */
    CTC_IPUC_FLAG_CPU                = 0x08,      /**< [HB.GB.GG]This route will be copied to CPU */
    CTC_IPUC_FLAG_NEIGHBOR           = 0x10,      /**< [HB.GB.GG]This is a host route, only set when mask length is 32 on IPv4 or 128 on IPv6 */
    CTC_IPUC_FLAG_CONNECT            = 0x20,      /**< [HB.GB.GG]This is a CONNECT entry */
    CTC_IPUC_FLAG_PROTOCOL_ENTRY     = 0x40,      /**< [HB.GB.GG]This route will enable l3pdu to cpu */
    CTC_IPUC_FLAG_SELF_ADDRESS       = 0x80,      /**< [GB.GG]Indicate it is a host address */
    CTC_IPUC_FLAG_ICMP_ERR_MSG_CHECK = 0x100,     /**< [GB.GG]This route will do icmp error message check */
    CTC_IPUC_FLAG_STATS_EN           = 0x200,     /**< [GB]Only host route support stats */
    CTC_IPUC_FLAG_AGING_EN           = 0x400,     /**< [GG]Only host route support aging */
    CTC_IPUC_FLAG_ASSIGN_PORT        = 0x800,     /**< [GG]Use the assign port as the output port */
    CTC_IPUC_FLAG_TTL_NO_CHECK          = 0x1000,      /**< [GG]This route will not do ttl check */

    MAX_CTC_IPUC_FLAG                = (CTC_IPUC_FLAG_TTL_NO_CHECK << 1) - 1

};
typedef enum ctc_ipuc_flag_e ctc_ipuc_flag_t;

/**
 @brief  Define ip global property flags
*/
enum ctc_ip_global_property_flag_e
{
    CTC_IP_GLB_PROP_V4_MARTIAN_CHECK_EN               = 0x01, /**< [HB.GB.GG]Enable/Disable martian packet check for IPv4. */
    CTC_IP_GLB_PROP_V6_MARTIAN_CHECK_EN               = 0x02, /**< [HB.GB.GG]Enable/Disable martian packet check for IPv6. */
    CTC_IP_GLB_PROP_MCAST_MACDA_IP_UNMATCH_CHECK      = 0x04, /**< [HB.GB.GG]Enable/Disable unmatched muticast MAC/IP address check */
    CTC_IP_GLB_PROP_TTL_THRESHOLD                     = 0x08, /**< [HB.GB.GG]Config ip ttl threshold. Packet is dropped when its TTL value less than the threshold. */
    CTC_IP_GLB_PROP_IPUC_V4_IPSA_SERACH_EN            = 0x10, /**< [HB]Enable/Disable IPSA lookup for IPv4, only need in HUMBER */
    CTC_IP_GLB_PROP_IPUC_V6_IPSA_SERACH_EN            = 0x20, /**< [HB]Enable/Disable IPSA lookup for IPv6, only need in HUMBER */

    MAX_CTC_IP_GLOBAL_PROP
};
typedef enum ctc_ip_global_property_flag_e ctc_ip_global_property_flag_t;

/**
 @brief  Define ip tunnel route flags
*/
enum ctc_ipuc_tunnel_flag_e
{
    CTC_IPUC_TUNNEL_FLAG_LKUP_WITH_IPSA          = 0x001,      /**< [HB.GB.GG]If set, route will do lookup with ipsa ,else only with ipda */
    CTC_IPUC_TUNNEL_FLAG_USE_OUTER_TTL           = 0x002,      /**< [GB.GG]If set, route will use outer header TTL ,else use inner TTL */
    CTC_IPUC_TUNNEL_FLAG_GRE_WITH_KEY            = 0x004,      /**< [HB.GB.GG]If set, route is encap by GRE with key */
    CTC_IPUC_TUNNEL_FLAG_LKUP_BY_OUTER_HEAD      = 0x008,      /**< [GB.GG]If set, route use outer header to lookup */
    CTC_IPUC_TUNNEL_FLAG_TTL_CHECK               = 0x010,      /**< [HB.GB.GG]If set, route will do TTL check for out header else no TTL check */
    CTC_IPUC_TUNNEL_FLAG_ISATAP_CHECK_EN         = 0x020,      /**< [GB.GG]If set, route will do ISATAP source address check */
    CTC_IPUC_TUNNEL_FLAG_COPY_TO_CPU             = 0x040,      /**< [HB]If set, route will be copied to CPU */
    CTC_IPUC_TUNNEL_FLAG_V4_RPF_CHECK            = 0x080,      /**< [GB.GG]If set, route will do RPF check for outer header */
    CTC_IPUC_TUNNEL_FLAG_V4_MORE_RPF             = 0x100,      /**< [GB.GG]If set, if RPF fail will send to cpu */
    CTC_IPUC_TUNNEL_FLAG_INNER_VRF_EN            = 0x200,      /**< [GB.GG]If set, inner route will lookup by user defined VRF ID */
    CTC_IPUC_TUNNEL_FLAG_ACL_LKUP_BY_OUTER_HEAD  = 0x400,      /**< [GB.GG]If set, use outer header info do acl lookup, default use the inner*/
    CTC_IPUC_TUNNEL_FLAG_SERVICE_ACL_EN          = 0x800,      /**< [GB.GG] Enable service acl */
    CTC_IPUC_TUNNEL_FLAG_SERVICE_QUEUE_EN        = 0x1000,     /**< [GB] Enable service queue */
    CTC_IPUC_TUNNEL_FLAG_SERVICE_POLICER_EN      = 0x2000,     /**< [GB.GG] Enable service policer */
    CTC_IPUC_TUNNEL_FLAG_STATS_EN                = 0x4000,     /**< [GB.GG] Enable statistic */
    CTC_IPUC_TUNNEL_FLAG_DISCARD                 = 0x8000,     /**< [GB.GG] Discard the packet */
    CTC_IPUC_TUNNEL_FLAG_USE_FLEX                = 0x10000,    /**< [GB.GG] Means use tcam. It can used for solve hash conflict */
    CTC_IPUC_TUNNEL_FLAG_QOS_USE_OUTER_INFO      = 0x20000,    /**< [GG] Use outer info(dscp/cos) do qos classification */
    CTC_IPUC_TUNNEL_FLAG_METADATA_EN             = 0x40000,     /**< [GG] overlay network tunnel enable metadata for open flow*/

    MAX_CTC_IPUC_TUNNEL_FLAG
};
typedef enum ctc_ipuc_tunnel_flag_e ctc_ipuc_tunnel_flag_t;

/**
 @brief  the packet layer4 type refer to ctc_parser_l4_type_t
*/
enum ctc_ipuc_tunnel_payload_type_e
{
    CTC_IPUC_TUNNEL_PAYLOAD_TYPE_GRE  = 0,    /**< [HB.GB.GG]payload TYPE is GRE */
    CTC_IPUC_TUNNEL_PAYLOAD_TYPE_V4   = 1,    /**< [HB.GB.GG]payload TYPE is IPv4 */
    CTC_IPUC_TUNNEL_PAYLOAD_TYPE_V6   = 2,    /**< [HB.GB.GG]payload TYPE is IPv6 */

    MAX_CTC_IPUC_TUNNEL_PAYLOAD_TYPE
};
typedef enum ctc_ipuc_tunnel_payload_type_e ctc_ipuc_tunnel_payload_type_t;

/**
 @brief  Define ipuc nat flags
*/
enum ctc_ipuc_nat_flag_e
{
    CTC_IPUC_NAT_FLAG_USE_TCP_PORT      = 0x01,      /**< [GB.GG]Indicate l4-src-port is tcp port or not. If set is TCP port else is UDP port */

    MAX_CTC_IPUC_NAT_FLAG               = 0xFF

};
typedef enum ctc_ipuc_nat_flag_e ctc_ipuc_nat_flag_t;

/**
 @brief  Define ipuc global config structure
*/
struct ctc_ipuc_global_cfg_s
{
    uint8 use_hash8;                    /**< [GB]Define IPv4 LPM lookup mode, if set 1 use hash 8 mode else use hash 16 mode */
    uint8 rpf_check_port;               /**< [GG]rpf check by port, not interface. it will concern ipuc & ipmc rpf check */
    uint8 default_route_mode;           /**< [GG]Define default route lookup mode, if set 1 use TCAM mode else use AD mode */
    uint8 rsv0;
};
typedef struct ctc_ipuc_global_cfg_s ctc_ipuc_global_cfg_t;

/**
 @brief  Define ipuc nat parameter structure
*/
struct ctc_ipuc_nat_sa_param_s
{
    uint8     flag;                     /**< [GB.GG] NAT flag, refer to ctc_ipuc_nat_flag_e */
    uint8     ip_ver;                   /**< [GB.GG] CTC_IP_VER_4 or CTC_IP_VER_6, now only support CTC_IP_VER_4 */
    uint16    vrf_id;                   /**< [GB.GG] Vrf ID of the nat */

    union
    {
        ip_addr_t ipv4;    /**< [GB.GG]IPv4 source address */
        ipv6_addr_t ipv6;  /**< [GB.GG]IPv6 source address */
    } ipsa;

    union
    {
        ip_addr_t ipv4;    /**< [GB.GG]new IPv4 source address */
        ipv6_addr_t ipv6;  /**< [GB.GG]new IPv6 source address */
    } new_ipsa;

    uint16    l4_src_port;              /**< [GB.GG] layer4 source port, if it is not zero, indicate it is NAPT */
    uint16    new_l4_src_port;          /**< [GB.GG] new layer4 source port */
};
typedef struct ctc_ipuc_nat_sa_param_s ctc_ipuc_nat_sa_param_t;

/**
 @brief  Define ipuc parameter structure
*/
struct ctc_ipuc_param_s
{
    uint32 nh_id;          /**< [HB.GB.GG]Nexthop ID */
    uint16 vrf_id;         /**< [HB.GB.GG]Vrf ID of the route */
    uint16 l3_inf;         /**< [HB.GB.GG]l3 interface, only valid when CTC_IPUC_FLAG_CONNECT is set */
    uint32 route_flag;     /**< [HB.GB.GG]Flags of the route, values is defined by ctc_ipuc_flag_e, one route can set one or more flags, or no flag */
    uint8  masklen;        /**< [HB.GB.GG]Mask length of destination */
    uint8  ip_ver;         /**< [HB.GB.GG]Destination ip address version, CTC_IP_VER_4 or CTC_IP_VER_6 */
    uint8  is_ecmp_nh;     /**< [HB]Nexthop is a ECMP group */
    uint8  rsv0[3];
    uint32 stats_id;       /**< [GB] stats id for this route.*/
    union
    {
        ip_addr_t ipv4;    /**< [HB.GB.GG]IPv4 destination address */
        ipv6_addr_t ipv6;  /**< [HB.GB.GG]IPv6 destination address */
    } ip;

    uint16 l4_dst_port;    /**< [GB.GG] layer4 destination port, if not 0, indicate it is a NAPT route. Now only support IPV4 NAPT */
    uint8  is_tcp_port;    /**< [GB.GG] If set, indicate the layer4 destination port is TCP port, else is UDP port */
    uint8  rpf_port_num;                        /**< [GG] valid gport number */
    uint32 rpf_port[CTC_IP_MAX_RPF_IF];         /**< [GG] RPF check gport for vlan interface */
    uint32 gport;          /**< [GG] Assign output gport */
};
typedef struct ctc_ipuc_param_s ctc_ipuc_param_t;

/**
 @brief Define ip tunnel parameter structure
*/
struct ctc_ipuc_tunnel_param_s
{
    uint32 nh_id;             /**< [HB.GB.GG]Nexthop ID , if CTC_IPUC_TUNNEL_FLAG_LKUP_BY_OUTER_HEAD flag is set, nexthop id must assigned */
    uint16 vrf_id;            /**< [HB.GB.GG][HB]Vrf ID of the tunnel route;[GB.GG] User defined Vrf ID mapping from GRE KEY,and will be used to inner route */
    uint16 metadata;          /**< [GG] metadata used for open flow */
    uint32 flag;              /**< [HB.GB.GG]Flags of the ip tunnel route, values is defined by ctc_ipuc_tunnel_flag_e */
    uint8  ip_ver;            /**< [HB.GB.GG]Destination ip address version, CTC_IP_VER_4 or CTC_IP_VER_6 */
    uint8  payload_type;      /**< [HB.GB.GG]set payload type must be ctc_ipuc_tunnel_payload_type_e */
    uint8  is_ecmp_nh;        /**< [HB]Nexthop is a ECMP group */
    uint8  rsv0;

    /**< [GB.GG]l3 interface, used for RPF check, 0 means invalid , only valid when
         CTC_IPUC_TUNNEL_FLAG_LKUP_BY_OUTER_HEAD is not set and
         CTC_IPUC_TUNNEL_FLAG_V4_RPF_CHECK is set */
    uint16 l3_inf[CTC_IPUC_IP_TUNNEL_MAX_IF_NUM];

    uint32 gre_key;           /**< [HB.GB.GG]GRE key */

    uint16 service_id;        /**< [GB] service id for do service queue/policer */
    uint16 policer_id;        /**< [GG] Policer id */
    uint16 logic_port;        /**< [GB.GG] Binding logic port, used for service acl/queue */
    uint16 stats_id;          /**< [GB.GG] statsid */
    uint8  scl_id;            /**< [GG] There are 2 scl lookup<0-1>, and each has its own feature, only for tcam key */
    uint8  rsv1;

    union
    {
        ip_addr_t ipv4;       /**< [HB.GB.GG]IPv4 destination address */
        ipv6_addr_t ipv6;     /**< [HB.GB.GG]IPv6 destination address */
    } ip_da;
    union
    {
        ip_addr_t   ipv4;     /**< [HB.GB.GG]IPv4 sourec address */
        ipv6_addr_t ipv6;     /**< [HB.GB.GG]IPv6 sourec address */
    } ip_sa;
};
typedef struct ctc_ipuc_tunnel_param_s ctc_ipuc_tunnel_param_t;

/**
 @brief  Define structure to config ipuc global property
*/
struct ctc_ipuc_global_property_s
{
    uint32 valid_flag;               /**< [HB.GB.GG]Flags indicate the valid members must number of
                                         ctc_ip_global_property_flag_e */

    uint8  v4_martian_check_en;      /**< [HB.GB.GG]New value of martian check enable for IPv4, valid when
                                         CTC_IP_GLB_PROP_V4_MARTIAN_CHECK_EN set */
    uint8  v6_martian_check_en;      /**< [HB.GB.GG]New value of martian check enable for IPv6, valid when
                                         CTC_IP_GLB_PROP_V6_MARTIAN_CHECK_EN set */
    uint8  mcast_match_check_en;    /**< [HB.GB.GG]New value of mcast addr match check, valid when
                                         CTC_IP_GLB_PROP_MCAST_MACDA_IP_UNMATCH_CHECK set */
    uint8  ip_ttl_threshold;        /**< [HB.GB.GG]New value of ip ttl threshold, valid when
                                         CTC_IP_GLB_PROP_TTL_THRESHOLD set */

    uint8  ipv4_sa_search_en;       /**< [HB]New value of ipv4 sa search enabel, valid when
                                         CTC_IP_GLB_PROP_IPUC_V4_IPSA_SERACH_EN set,
                                         TRUE: set IPUC search key to be Source IP + destination IP + VRFID
                                         FALSE: set IPUC search key to be destination IP + VID*/
    uint8  ipv6_sa_search_en;       /**< [HB]New value of ipv6 sa search enabel, valid when
                                         CTC_IP_GLB_PROP_IPUC_V6_IPSA_SERACH_EN set,
                                         TRUE: set IPUC search key to be Source IP + destination IP + VRFID
                                         FALSE: set IPUC search key to be destination IP + VID*/
    uint8 rsv0[2];
};
typedef struct ctc_ipuc_global_property_s ctc_ipuc_global_property_t;

typedef int32 (* ctc_ipuc_traverse_fn)(ctc_ipuc_param_t* p_ipuc_param, void* user_data);

/**@} end of @defgroup  ipuc IPUC */

#ifdef __cplusplus
}
#endif

#endif  /*_CTC_IPUC_H*/

