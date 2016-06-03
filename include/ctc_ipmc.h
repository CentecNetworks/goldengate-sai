/**
 @file ctc_ipmc.h

 @author Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2010-01-25

 @version v2.0

   This file contains all IP Multicast related data structure, enum, macro and proto.
*/

#ifndef _CTC_IPMC_H_
#define _CTC_IPMC_H_
#ifdef __cplusplus
extern "C" {
#endif
/**
 @defgroup ipmc IPMC
 @{
*/
#include "ctc_l3if.h"

#define CTC_IPMC_FLAG_DROP                      0x00000001  /**< [HB.GB.GG] Packets will be dropped */
#define CTC_IPMC_FLAG_COPY_TOCPU                0x00000002  /**< [HB.GB.GG] Packets will be copied to CPU */
#define CTC_IPMC_FLAG_RPF_CHECK                 0x00000004  /**< [HB.GB.GG] Packets will do RPF check */
#define CTC_IPMC_FLAG_MORE_RPFIF                0x00000008  /**< [HB] Packets will be sent to CPU */
#define CTC_IPMC_FLAG_RPF_FAIL_BRIDGE_AND_TOCPU 0x00000010  /**< [HB.GB.GG] Packets will be sent to CPU and fallback bridged */
#define CTC_IPMC_FLAG_BIDPIM_CHECK              0x00000020  /**< [HB.GB.GG] Packets will do bidirection PIM check */
#define CTC_IPMC_FLAG_TTL_CHECK                 0x00000040  /**< [HB.GB.GG] Packets will do TTL check */
#define CTC_IPMC_FLAG_KEEP_EMPTY_ENTRY          0x00000100  /**< [HB.GB.GG] When removing group,  only delete all member */
#define CTC_IPMC_FLAG_STATS                     0x00000200  /**< [HB.GB.GG] Statistic will be supported*/
#define CTC_IPMC_FLAG_REDIRECT_TOCPU            0x00000400  /**< [HB.GB.GG] Packets will be redirected to CPU*/
#define CTC_IPMC_FLAG_TUNNEL                    0x00000800  /**< [HB.GB] Packets will be encap */
#define CTC_IPMC_FLAG_L2MC                      0x00001000  /**< [GB.GG] Packets will do l2 mcast by ip */
#define CTC_IPMC_FLAG_PTP_ENTRY                 0x00002000  /**< [GB.GG] Mcast PTP IP address, using for IP DA */
#define CTC_IPMC_FLAG_BIDIPIM_FAIL_BRIDGE_AND_TOCPU 0x00004000  /**< [GG] Packets will be sent to CPU and fallback bridged */
#define CTC_IPMC_MAX_MEMBER_PER_GROUP           64          /**< [HB.GB] Define max member that an ipmc group can contain*/

/**
 @brief Ipv4/6 multicast default actions
*/
enum ctc_ipmc_default_action_e
{
    CTC_IPMC_DEFAULT_ACTION_DROP = 0,           /**< [HB.GB.GG] IPMC packet will be discarded by default action*/
    CTC_IPMC_DEFAULT_ACTION_TO_CPU = 1,         /**< [HB.GB.GG] IPMC packet will be sent to cpu by default action*/
    CTC_IPMC_DEFAULT_ACTION_FALLBACK_BRIDGE = 2, /**< [HB.GB.GG] IPMC packet will fall back bridge*/
    CTC_IPMC_DEFAULT_ACTION_MAX
};
typedef enum ctc_ipmc_default_action_e ctc_ipmc_default_action_t;

/**
 @brief Ipmc force route
*/
struct ctc_ipmc_force_route_s
{
    uint8 ip_version;       /**< [HB.GB.GG] ctc_ip_ver_t, v4 or v6*/
    uint8 force_bridge_en;  /**< [HB.GB.GG] force special mcast address to bridge*/
    uint8 force_ucast_en;   /**< [HB.GB.GG] force special mcast address to do ucast, lower priority than force bridge*/
    uint8 rsv;              /**< reserved*/

    uint8 ipaddr0_valid;    /**< [HB.GB.GG] first ip address is enable*/
    uint8 ipaddr1_valid;    /**< [HB.GB.GG] second ip address is enable*/
    uint8 addr0_mask;       /**< [HB.GB.GG] first ip address mask length*/
    uint8 addr1_mask;       /**< [HB.GB.GG] second ip address mask length*/

    union
    {
        ip_addr_t ipv4;     /**< [HB.GB.GG] Ipv4 address*/
        ipv6_addr_t ipv6;   /**< [HB.GB.GG] Ipv6 address*/
    } ip_addr0;             /**< [HB.GB.GG] first ip address*/

    union
    {
        ip_addr_t ipv4;     /**< [HB.GB.GG] Ipv4 address*/
        ipv6_addr_t ipv6;   /**< [HB.GB.GG] Ipv6 address*/
    } ip_addr1;             /**< [HB.GB.GG] second ip address*/

};
typedef struct ctc_ipmc_force_route_s ctc_ipmc_force_route_t;

/**
 @brief Ipv4 multicast address.
*/
struct ctc_ipmc_ipv4_addr_s
{
    uint32 src_addr;           /**< [HB.GB.GG] IPv4 Source address */
    uint32 group_addr;         /**< [HB.GB.GG] IPv4 Group address */
    uint32 vrfid;              /**< [HB.GB.GG] VRF Id ,if IP-L2MC,used as FID.
                                    [GG] if vrf_mode is CTC_IPMC_MODE_SVLAN, vrfid is svlan id */

};
typedef struct ctc_ipmc_ipv4_addr_s ctc_ipmc_ipv4_addr_t;

/**
 @brief Ipv6 multicast address.
*/
struct ctc_ipmc_ipv6_addr_s
{
    ipv6_addr_t src_addr;          /**< [HB.GB.GG] IPv6 Source address */
    ipv6_addr_t group_addr;        /**< [HB.GB.GG] IPv6 Group address */
    uint32 vrfid;                  /**< [HB.GB.GG] VRF Id ,if IP-L2MC,used as FID.
                                        [GG] if vrf_mode is CTC_IPMC_MODE_SVLAN, vrfid is svlan id */
};
typedef struct ctc_ipmc_ipv6_addr_s ctc_ipmc_ipv6_addr_t;

/**
 @brief Union structure that stores ipv4 or ipv6 address.
*/
union ctc_ipmc_addr_info_u
{
    ctc_ipmc_ipv4_addr_t ipv4;      /**< [HB.GB.GG] IPV4 address structure */
    ctc_ipmc_ipv6_addr_t ipv6;      /**< [HB.GB.GG] IPV6 address structure */
};
typedef union ctc_ipmc_addr_info_u ctc_ipmc_addr_info_t;

/**
 @brief Data structure that stores member information.
*/
struct ctc_ipmc_member_info_s
{
    uint32 global_port;         /**< [HB.GB.GG] Member port if member is local member, gport: gchip(8bit) + local phy port(8bit);
                                     else if member is remote chip entry, gport: gchip(local) + remote gchip id(8bit) */
    uint16 vlan_id;             /**< [HB.GB.GG] Vlan id */
    ctc_l3if_type_t l3_if_type; /**< [HB.GB.GG] Layer3 interface type */
    bool remote_chip;           /**< [HB.GB.GG] If set, member is remote chip entry */
    bool vlan_port;             /**< [HB.GB.GG] If set and  l3if is vlan interface , output packet only do L2 bridging . */
    bool is_nh;                 /**< [HB.GB.GG] If set add member by nexthop. */
    bool re_route;              /**< [GG] If set add loop back member. */

    uint32 nh_id;               /**< [HB.GB.GG] Nexthop Id */
};
typedef struct ctc_ipmc_member_info_s ctc_ipmc_member_info_t;

/**
 @brief Data structure that stores group information.
*/
struct ctc_ipmc_group_info_s
{
    uint32 g_key_index;                            /**< [GG] G group index for (*,G) and (S,G) */
    uint32 sg_key_index;                           /**< [GG] S group index for (S,G) */
    uint8  ip_version;                             /**< [HB.GB.GG] 0 IPV4, 1 IPV6 */
    uint8  member_number;                          /**< [HB.GB.GG] The numbers of member added to this group, not support this info for reply */
    uint8  src_ip_mask_len;                        /**< [HB.GB.GG] IP Source address mask length, V4: 0, 32; V6: 0, 128 */
    uint8  group_ip_mask_len;                      /**< [HB.GB.GG] IP Group address mask length, V4: 0, 32; V6: 0, 128 */
    uint8  rpf_intf_valid[CTC_IP_MAX_RPF_IF];      /**< [HB.GB.GG] RPF check valid flag */
    uint16 rpf_intf[CTC_IP_MAX_RPF_IF];            /**< [HB.GB.GG] RPF check interface id or port */
    uint32 flag;                                   /**< [HB.GB.GG] Rules that define actions for packets of this group,CTC_IPMC_FLAG_XXX,
                                      CTC_IPMC_FLAG_TTL_CHECK flag to enable TTL check;CTC_IPMC_FLAG_RPF_CHECK flag to enable RPF check;
                                      CTC_IPMC_FLAG_L2MC flag to enable L2MC based on IP;CTC_IPMC_FLAG_STATS flag to enable  ipmc statistic.
                                      CTC_IPMC_FLAG_COPY_TOCPU, CTC_IPMC_FLAG_REDIRECT_TOCPU flag to enable ipda exception. CTC_IPMC_FLAG_BIDPIM_CHECK and
                                      CTC_IPMC_FLAG_RPF_CHECK can not enable together */
    uint32 stats_id;                               /**< [GB.GG] Stats id */
    uint16 group_id;                               /**< [HB.GB.GG] Identify a group */
    uint8   rp_id;                                 /**< [GG] rp id */
    uint8   statsFail;                             /**< [HB.GB] Return value,if ipmc stats don't get stats resource, not support this info for reply */
    ctc_ipmc_member_info_t ipmc_member[CTC_IPMC_MAX_MEMBER_PER_GROUP];  /**< [HB.GB.GG] record member information, not support this info for reply */
    ctc_ipmc_addr_info_t address;                  /**< [HB.GB.GG] Union structure stores ipv4 or ipv6 address */
};
typedef struct ctc_ipmc_group_info_s  ctc_ipmc_group_info_t;

/**
 @brief Rp information.
*/
struct ctc_ipmc_rp_s
{
    uint8   rp_id;                                 /**< [GG] rp id */
    uint8   rp_intf_count;                         /**< [GG] rp interface count valid */
    uint16  rp_intf[CTC_IPMC_RP_INTF];             /**< [GG] rp interface configured */
};
typedef struct ctc_ipmc_rp_s  ctc_ipmc_rp_t;

typedef int32 (* ctc_ipmc_traverse_fn)(ctc_ipmc_group_info_t* p_ipmc_param, void* user_data);

/**@} end of @defgroup  ipmc IPMC */
#ifdef __cplusplus
}
#endif

#endif

