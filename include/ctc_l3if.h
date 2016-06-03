/**
 @file ctc_l3if.h

 @author Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2010-1-7

 @version v2.0

This file contains all L3 interface related data structure, enum, macro and proto.

*/
#ifndef _CTC_L3_IF
#define _CTC_L3_IF
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
#include "ctc_stats.h"

/****************************************************************
*
* Defines and Macros
*
****************************************************************/

/**
 @defgroup l3if L3if
 @{
*/

/*-----------------------L3if id allocation ---------------------
Humber :
 Vlan L3if,Phy L3if and sub L3if share 1023 L3 interface.
 |0...............................................................................................1022|
 |Phy and sub l3if ID(0~511)  ->                      <-(0~1022) vlan l3if ID   |

 vlan l3if             range:  0~1022
 Phy and sub l3if range:   0~511
 Greatbelt:
 Vlan L3if, Phy L3if, sub L3if share 1022 interface ID, the range is 1~1023.
 Goldengate:
 Vlan L3if, Phy L3if share 1023 interface ID(0~1022), Sub interface not support now.
-----------------------------------------------------------*/
#define MAX_CTC_L3IF_VMAC_MAC_INDEX         3       /**< [HB.GB] Max index of layer 3 interface virtual router-mac */
#define MAX_CTC_L3IF_MCAST_TTL_THRESHOLD    256     /**< [HB.GB] Max TTL threshold of layer 3 interface multicast */
#define MAX_CTC_L3IF_MTU_SIZE               16 * 1024 /**< [HB.GB] Max MTU size of layer 3 interface */
#define MAX_CTC_L3IF_PBR_LABEL              0x3F    /**< [HB.GB] Max PBR label value of layer 3 interface */

/**
 @brief l3if global config information
*/
struct ctc_l3if_global_cfg_s
{
    uint16 max_vrfid_num;           /**< [GB.GG]Max vrf id supported in l3 module, MUST be times of 64, default is 256 */
    uint8 ipv4_vrf_en;              /**< [GB.GG]If set, IPv4 enable vrf lookup */
    uint8 ipv6_vrf_en;              /**< [GB.GG]If set, IPv6 enable vrf lookup */
};
typedef struct ctc_l3if_global_cfg_s ctc_l3if_global_cfg_t;

/**
 @brief  Define the prefix type of  l3 interface 40bits Router MAC
*/
enum ctc_l3if_route_mac_type_e
{
    CTC_L3IF_ROUTE_MAC_PFEFIX_TYPE0,                /**< [HB.GB] Type 0*/
    CTC_L3IF_ROUTE_MAC_PFEFIX_TYPE1,                /**< [HB.GB] Type 1*/
    CTC_L3IF_ROUTE_MAC_PFEFIX_TYPE_RSV_ROUTER_MAC,  /**< [HB.GB] Type 2,will be reserved for per-system router mac*/
    CTC_L3IF_ROUTE_MAC_PFEFIX_TYPE_INVALID,         /**< [HB.GB] Non-support type*/
    MAX_CTC_L3IF_ROUTE_MAC_PFEFIX_TYPE
};
typedef enum ctc_l3if_route_mac_type_e  ctc_l3if_route_mac_type_t;

/**
 @brief  Define the type of l3if
*/
enum ctc_l3if_type_e
{
    CTC_L3IF_TYPE_PHY_IF,    /**< [HB.GB.GG] Physical IP interfaces*/
    CTC_L3IF_TYPE_SUB_IF,    /**< [HB.GB.GG] Sub-interface*/
    CTC_L3IF_TYPE_VLAN_IF,   /**< [HB.GB.GG] Logical IP Vlan interfaces*/
    MAX_L3IF_TYPE_NUM
};
typedef enum ctc_l3if_type_e  ctc_l3if_type_t;

/**
 @brief  Define the lookup operation for of IPSA lookup
*/
enum ctc_l3if_ipsa_lkup_type_e
{
    CTC_L3IF_IPSA_LKUP_TYPE_NONE, /**< [HB.GB.GG] Don't do IPSA lookup*/
    CTC_L3IF_IPSA_LKUP_TYPE_RPF,  /**< [HB.GB.GG] IPSA lookup operation used as RPF check */
    CTC_L3IF_IPSA_LKUP_TYPE_NAT,  /**< [HB.GB.GG] IPSA lookup operation used as NAT */
    CTC_L3IF_IPSA_LKUP_TYPE_PBR,  /**< [HB.GB.GG] IPSA lookup operation used as PBR*/
    MAX_CTC_L3IF_IPSA_LKUP_TYPE
};
typedef enum ctc_l3if_ipsa_lkup_type_e ctc_l3if_ipsa_lkup_type_t;

/**
  @brief   Define l3if property flags
*/
enum ctc_l3if_property_e
{
    CTC_L3IF_PROP_ROUTE_EN,               /**< [HB.GB.GG] Enable IP Routing */
    CTC_L3IF_PROP_PBR_LABEL,              /**< [HB.GB.GG] Set Policy-based routing label*/
    CTC_L3IF_PROP_NAT_IFTYPE,             /**< [HB.GB.GG] The type of NAT,0- external,1- internal*/
    CTC_L3IF_PROP_ROUTE_ALL_PKT,          /**< [HB.GB.GG] If set,all packets are routed*/
    CTC_L3IF_PROP_IPV4_UCAST,             /**< [HB.GB.GG] If set,IpV4 Ucast Routing will be enabled*/
    CTC_L3IF_PROP_IPV4_MCAST,             /**< [HB.GB.GG] If set,IpV4 Mcast Routing will be enabled*/
    CTC_L3IF_PROP_IPV4_MCAST_RPF,         /**< [HB] If set,IpV4 Mcast RPF will be enabled */
    CTC_L3IF_PROP_IPV4_SA_TYPE,           /**< [HB.GB.GG] SA lkup operation for IPV4 Lookup, refer to ctc_l3if_ipsa_lkup_type_t */
    CTC_L3IF_PROP_IPV6_UCAST,             /**< [HB.GB.GG] If set,IpV6 Ucast Routing will be enabled*/
    CTC_L3IF_PROP_IPV6_MCAST,             /**< [HB.GB.GG] If set,IpV6 Mcast Routing will be enabled*/
    CTC_L3IF_PROP_IPV6_MCAST_RPF,         /**< [HB] If set,IpV6 Mcast RPF will be enabled */
    CTC_L3IF_PROP_IPV6_SA_TYPE,           /**< [HB.GB.GG] SA lkup operation for IPV6 Lookup, refer to ctc_l3if_ipsa_lkup_type_t  */
    CTC_L3IF_PROP_VRF_ID,                 /**< [HB.GB.GG] The ID for virtual route forward table */
    CTC_L3IF_PROP_MTU_EN,                 /**< [HB.GB.GG] MTU check is enabled on the egress interface*/
    CTC_L3IF_PROP_MTU_SIZE,               /**< [HB.GB.GG] MTU size of the egress interface*/
    CTC_L3IF_PROP_MTU_EXCEPTION_EN,       /**< [HB.GB.GG] MTU Exception enable for packet to cpu to do fragment */
    CTC_L3IF_PROP_TANSMIT_EN,             /**< [HB] Transmit is enabled for EPE */
    CTC_L3IF_PROP_RECEIVE_EN,             /**< [HB] Receive is enabled for IPE */
    CTC_L3IF_PROP_ROUTE_MAC_PREFIX_TYPE,  /**< [GB] The prefix type of router MAC, value should be ctc_l3if_route_mac_type_e */
    CTC_L3IF_PROP_ROUTE_MAC_LOW_8BITS,    /**< [GB] Low 8 bits of router MAC  */
    CTC_L3IF_PROP_EGS_MAC_SA_PREFIX_TYPE, /**< [HB.GB] The prefix type of router MAC,to be used in the MAC SA for routed packets EPE edit*/
    CTC_L3IF_PROP_EGS_MAC_SA_LOW_8BITS,   /**< [HB.GB] Low 8 bits for the MAC SA for routed packets EPE edit*/
    CTC_L3IF_PROP_EGS_MCAST_TTL_THRESHOLD,/**< [HB.GB.GG] Multicast TTL threshold */
    CTC_L3IF_PROP_MPLS_EN,                /**< [HB.GB.GG] Enable MPLS */
    CTC_L3IF_PROP_MPLS_LABEL_SPACE,       /**< [HB.GB.GG] Set MPLS label space */
    CTC_L3IF_PROP_ARP_EXCEPTION_TYPE,     /**< [HB] Set arp exception type*/
    CTC_L3IF_PROP_DHCP_EXCEPTION_TYPE,    /**< [HB] DHCP exception type  */
    CTC_L3IF_PROP_VRF_EN,                 /**< [HB.GB.GG] Enable VRF lookup */
    CTC_L3IF_PROP_IGMP_SNOOPING_EN,       /**< [HB.GG] Enable IGMP snooping */
    CTC_L3IF_PROP_RPF_CHECK_TYPE,         /**< [GB.GG] RPF check type */
    CTC_L3IF_PROP_IGS_ACL_EN,             /**< [HB] Ingress vlan acl enable, refer CTC_ACL_EN_XXX */
    CTC_L3IF_PROP_IGS_ACL_CLASSID_0,      /**< [HB] Ingress vlan acl0 classid */
    CTC_L3IF_PROP_IGS_ACL_CLASSID_1,      /**< [HB] Ingress vlan acl1 classid */
    CTC_L3IF_PROP_EGS_ACL_EN,             /**< [HB] Egress vlan acl enable, refer CTC_ACL_EN_XXX */
    CTC_L3IF_PROP_EGS_ACL_CLASSID_0,      /**< [HB] Egress vlan acl0 classid */
    CTC_L3IF_PROP_EGS_ACL_CLASSID_1,      /**< [HB] Egress vlan acl1 classid */
    CTC_L3IF_PROP_CONTEXT_LABEL_EXIST,    /**< [GG] If set, identify mpls packets on this interface have context label*/
    CTC_L3IF_PROP_RPF_PERMIT_DEFAULT,     /**< [GB.GG] Permit default ipsa pass RPF Check */
    CTC_L3IF_PROP_STATS,                  /**< [GB.GG] Stats en for interface(GB only support sub-if). if value is 0,disable stats, or value is statsid*/
    CTC_L3IF_PROP_EGS_STATS,              /**< [GG] Stats en for interface. if value is 0,disable stats, or value is statsid*/

    MAX_CTC_L3IF_PROP_NUM
};
typedef enum ctc_l3if_property_e  ctc_l3if_property_t;

/**
 @brief  Define vrf stats type
*/
enum ctc_l3if_vrf_stats_type_e
{
    CTC_L3IF_VRF_STATS_UCAST,    /**< [GB.GG] Only stats ucast route packet */
    CTC_L3IF_VRF_STATS_MCAST,    /**< Only stats mcast route packet */
    CTC_L3IF_VRF_STATS_ALL,      /**< [GG] Stats all route packet */
    MAX_L3IF_VRF_STATS_TYPE
};
typedef enum ctc_l3if_vrf_stats_type_e  ctc_l3if_vrf_stats_type_t;

/**
 @brief  Define vrf stats
*/
struct ctc_l3if_vrf_stats_s
{
    ctc_l3if_vrf_stats_type_t type;     /**< [GB.GG] VRF stats type */
    uint16 vrf_id;                      /**< [GB.GG] The ID for virtual route forward table */
    uint8 enable;                       /**< [GB.GG] Enable stats */
    uint32 stats_id;                    /**< [GB.GG] Stats id*/

    ctc_stats_basic_t stats;            /**< [GB] Output stats info */
};
typedef struct ctc_l3if_vrf_stats_s  ctc_l3if_vrf_stats_t;

/**
  @brief  Define L3if structure
 */
struct ctc_l3if_s
{
    uint8   l3if_type; /**< [HB.GB.GG] The type of l3interface , CTC_L3IF_TYPE_XXX */
    uint32 gport;     /**< [HB.GB.GG] Global logic port ID */
    uint16  vlan_id;   /**< [HB.GB.GG] Vlan Id */
};
typedef struct ctc_l3if_s  ctc_l3if_t;

/**
  @brief   Define L3if  VMAC structure
 */
struct ctc_l3if_vmac_s
{
    uint8   low_8bits_mac_index; /**< [HB.GB] The index of VMAC entry,0~3*/
    uint8   prefix_type;         /**< [HB.GB] ctc_l3if_route_mac_type_t */
    uint8   low_8bits_mac;       /**< [HB.GB] The id of L3 ingress interface */
};
typedef struct ctc_l3if_vmac_s  ctc_l3if_vmac_t;

/**
  @brief   Define L3if router mac
 */
struct ctc_l3if_router_mac_s
{
    mac_addr_t  mac[4];     /**< [GG] Router mac*/
    uint32      num;        /**< [GG] Valid router mac number in mac*/
};
typedef struct ctc_l3if_router_mac_s  ctc_l3if_router_mac_t;

/**
  @brief   Define L3if ECMP interface
 */
struct ctc_l3if_ecmp_if_s
{
    uint16 ecmp_if_id;          /**< [GG] ecmp interface id <1-1024> */
    uint16 ecmp_type;           /**< [GG] ecmp type, refer to ctc_nh_ecmp_type_t, only support static and DLB */
    uint8  failover_en;         /**< [GG] Indicate linkdown use hw based linkup member select, only used for static ecmp */
    uint32 stats_id;            /**< [GG] Stats id*/
};
typedef struct ctc_l3if_ecmp_if_s  ctc_l3if_ecmp_if_t;

#ifdef __cplusplus
}
#endif

#endif
/**@} end of @defgroup  l3if L3if */

