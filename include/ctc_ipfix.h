/**
 @file ctc_ipfix.h

 @author  Copyright (C) 2013 Centec Networks Inc.  All rights reserved.

 @date 2013-10-13

 @version v3.0

 This file contains all port related data structure, enum, macro and proto.

*/

#ifndef _CTC_IPFIX_H
#define _CTC_IPFIX_H
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************
 *
 * Header Files
 *
 ***************************************************************/

#include "sal.h"
#include "ctc_const.h"
/****************************************************************
*
* Defines and Macros
*
****************************************************************/

/**
 @defgroup ipfix IPFIX
 @{
*/

#define CTC_IPFIX_LABEL_NUM          3

/**
 @brief  IPFIX flag define
*/
enum ctc_ipfix_data_flags_e
{
    CTC_IPFIX_DATA_L2_MCAST_DETECTED      = (1 << 0),    /**< [GG] Session destid is L2Mcast*/
    CTC_IPFIX_DATA_L3_MCAST_DETECTED      = (1 << 1),    /**< [GG] Session destid is L3Mcast*/
    CTC_IPFIX_DATA_BCAST_DETECTED         = (1 << 2),    /**< [GG] Session destid is BMcast*/
    CTC_IPFIX_DATA_APS_DETECTED           = (1 << 3),    /**< [GG] Session destid is APS Group*/
    CTC_IPFIX_DATA_ECMP_DETECTED          = (1 << 4),    /**< [GG] Session destid is ECMP Group*/
    CTC_IPFIX_DATA_LINKAGG_DETECTED       = (1 << 5),    /**< [GG] Session destid is Linkagg Group*/
    CTC_IPFIX_DATA_UNKNOW_PKT_DETECTED    = (1 << 6),    /**< [GG] Unkown Packet detect*/
    CTC_IPFIX_DATA_FRAGMENT_PKT_DETECTED  = (1 << 7),    /**< [GG] Fragment Packet detect*/
    CTC_IPFIX_DATA_DROP_DETECTED          = (1 << 8),    /**< [GG] Drop Packrt detect*/
    CTC_IPFIX_DATA_TTL_CHANGE             = (1 << 9),    /**< [GG] TTL change in this session*/
    CTC_IPFIX_DATA_CVLAN_TAGGED           = (1 << 10),   /**< [GG] Ipfix key cvlan valid*/
    CTC_IPFIX_DATA_SVLAN_TAGGED           = (1 << 11)    /**< [GG] Ipfix key svlan valid*/
};
typedef enum ctc_ipfix_data_flags_e ctc_ipfix_data_flags_t;

/**
 @brief  IPFIX Export Reason define
*/
enum ctc_ipfix_export_reason_e
{
    CTC_IPFIX_NO_EXPORT,
    CTC_IPFIX_REASON_EXPIRED,                 /**< [GG] Export reason is time expired */
    CTC_IPFIX_REASON_TCP_CLOSE,               /**< [GG] Export reason is Tcp session close */
    CTC_IPFIX_REASON_PACKET_CNT_OVERFLOW,     /**< [GG] Export reason is packet count overflow */
    CTC_IPFIX_REASON_BYTE_CNT_OVERFLOW,       /**< [GG] Export reason is packet byte overflow */
    CTC_IPFIX_REASON_LAST_TS_OVERFLOW,        /**< [GG] Export reason is ts overflow */
    CTC_IPFIX_REASON_HASH_CONFLICT,           /**< [GG] Export reason is hash conflict */
    CTC_IPFIX_REASON_NEW_FLOW_INSERT,         /**< [GG] Export reason is new flow insert */
    CTC_IPFIX_REASON_DEST_CHANGE              /**< [GG] Export reason is dest info change */
};
typedef enum ctc_ipfix_export_reason_e ctc_ipfix_export_reason_t;

/**
 @brief  IPFIX aim to packet type
*/
enum ctc_ipfix_flow_type_e
{
    CTC_IPFIX_FLOW_TYPE_ALL_PACKET,          /**< [GG] Do ipfix for all packets including Discard and Non-discard */
    CTC_IPFIX_FLOW_TYPE_NON_DISCARD_PACKET,  /**< [GG] Only do ipfix for Non-discard packets */
    CTC_IPFIX_FLOW_TYPE_DISCARD_PACKET       /**< [GG] Only do ipfix for Discard packets */
};
typedef enum ctc_ipfix_flow_type_e ctc_ipfix_flow_type_t;

/**
 @brief  IPFIX mpls label info
*/
struct ctc_ipfix_label_info_s
{
    uint8  ttl;        /**< [GG] TTL value*/
    uint8  exp;        /**< [GG] EXP value*/
    uint8  sbit;       /**< [GG] Sbit value*/
    uint32 label;      /**< [GG] MPLS label value*/
}
;
typedef struct ctc_ipfix_label_info_s ctc_ipfix_label_info_t;

/**
 @brief  IPFIX l3 info struct
*/
struct ctc_ipfix_l3_info_s
{
    struct
    {
        uint8 ttl;             /**< [GG] TTL value*/
        uint8 dscp;            /**< [GG] DSCP value*/
        uint8 ecn;             /**< [GG] ECN value*/
        uint8 ipda_masklen;    /**< [GG] Only used for Cpu construct key, length should be 1~32*/
        uint8 ipsa_masklen;    /**< [GG] Only used for Cpu construct key, length should be 1~32*/
        ip_addr_t ipda;        /**< [GG] IPV4 ip da*/
        ip_addr_t ipsa;        /**< [GG] IPV4 ip sa*/
    }ipv4;
    struct
    {
        uint32 flow_label;     /**< [GG] Flow Label*/
        uint8 dscp;            /**< [GG] DSCP value*/
        uint8 ipda_masklen;    /**< [GG] Only used for Cpu construct key, length should be 4*n*/
        uint8 ipsa_masklen;    /**< [GG] Only used for Cpu construct key, length should be 4*n*/
        ipv6_addr_t ipda;      /**< [GG] IPV6 ip da*/
        ipv6_addr_t ipsa;      /**< [GG] IPV6 ip sa*/
    }ipv6;

    struct
    {
        uint8 label_num;                                    /**< [GG] MPLS lable number*/
        ctc_ipfix_label_info_t label[CTC_IPFIX_LABEL_NUM];  /**< [GG] MPLS lable*/
    }mpls;

    uint32 vrfid;              /**< [GG] Vrfid value*/
};
typedef struct ctc_ipfix_l3_info_s ctc_ipfix_l3_info_t;

/**
 @brief  IPFIX l4 info struct
*/
struct ctc_ipfix_l4_info_s
{
    union
    {
        uint16 l4_type;                  /**< [GG] refer to ctc_ipfix_l4_type_t, used for l2l3 and ipv6 key*/
        uint16 ip_protocol;              /**< [GG] used for ipv4 key */
    }type;

    struct
    {
        uint16 source_port;              /**< [GG] Source port value*/
        uint16 dest_port;                /**< [GG] Destination port value*/
    }l4_port;

    struct
    {
        uint8 icmpcode;                  /**< [GG] Icmpcode value*/
        uint8 icmp_type;                 /**< [GG] Icmp type*/
    }icmp;

    uint32 l4_sub_type;                  /**< [GG] refer to ctc_ipfix_l4_sub_type_t, used for l2l3 ipv4 ipv6 key. When used for ipv6, only support vxlan_vin*/
    uint32 gre_key;                      /**< [GG] GRE key*/
    uint32 vni;                          /**< [GG] Vni key*/
    uint8  is_extern;                    /**< [GG] When Nvgre/Vxlan flow using inner packet information do ipfix, can using outer l4 info as key. Used for ipv4 ipv6 l2l3 key*/
};
typedef struct ctc_ipfix_l4_info_s ctc_ipfix_l4_info_t;

/**
 @brief  IPFIX Port Type
*/
enum ctc_ipfix_port_type_s
{
    CTC_IPFIX_PORT_TYPE_NONE,       /**< [GG] Donot using Gport/LogicPort/metedara as key */
    CTC_IPFIX_PORT_TYPE_GPORT,      /**< [GG] Using GlobalPort as key */
    CTC_IPFIX_PORT_TYPE_LOGIC_PORT, /**< [GG] Using LogicPort as key */
    CTC_IPFIX_PORT_TYPE_METADATA    /**< [GG] Using Metadata as key */
};
typedef enum ctc_ipfix_port_type_s ctc_ipfix_port_type_t;

/** @brief  IPFIX Key Type */
enum ctc_ipfix_key_type_e
{
    CTC_IPFIX_KEY_HASH_MAC,           /**< [GG] MAC Hash key type */
    CTC_IPFIX_KEY_HASH_L2_L3,         /**< [GG] L2 L3 Hash key type */
    CTC_IPFIX_KEY_HASH_IPV4,          /**< [GG] IPv4 Hash key type */
    CTC_IPFIX_KEY_HASH_IPV6,          /**< [GG] IPv6 Hash key type */
    CTC_IPFIX_KEY_HASH_MPLS,          /**< [GG] MPLS Hash key type */
    CTC_IPFIX_KEY_NUM
};
typedef enum ctc_ipfix_key_type_e ctc_ipfix_key_type_t;

/**
 @brief  Define flex nexthop use packet type
*/
enum ctc_ipfix_l4_type_e
{
    CTC_IPFIX_L4_TYPE_NONE,             /**< [GG] no l4 type*/
    CTC_IPFIX_L4_TYPE_TCP,              /**< [GG] 1: l4 type is TCP*/
    CTC_IPFIX_L4_TYPE_UDP,              /**< [GG] 2: l4 type is UDP*/
    CTC_IPFIX_L4_TYPE_GRE,              /**< [GG] 3: l4 type is GRE*/
    CTC_IPFIX_L4_TYPE_IPINIP,           /**< [GG] 4: l4 type is IPINIP*/
    CTC_IPFIX_L4_TYPE_V6INIP,           /**< [GG] 5: l4 type is V6INIP*/
    CTC_IPFIX_L4_TYPE_ICMP,             /**< [GG] 6: l4 type is ICMP*/
    CTC_IPFIX_L4_TYPE_IGMP,             /**< [GG] 7: l4 type is IGMP*/
    CTC_IPFIX_L4_TYPE_SCTP,             /**< [GG] 8: l4 type is SCTP*/
    CTC_IPFIX_L4_TYPE_MAX
};
typedef enum ctc_ipfix_l4_type_e ctc_ipfix_l4_type_t;

/**
 @brief  Define flex nexthop use packet type
*/
enum ctc_ipfix_l4_sub_type_e
{
    CTC_IPFIX_L4_SUB_TYPE_NONE,          /**< [GG] no l4 sub type, for l4 type is UDP*/
    CTC_IPFIX_L4_SUB_TYPE_BFD,           /**< [GG] 1: l4 sub type is BFD, for l4 type is UDP*/
    CTC_IPFIX_L4_SUB_TYPE_UDPPTP,        /**< [GG] 2: l4 sub type is UDPPTP,for l4 type is UDP*/
    CTC_IPFIX_L4_SUB_TYPE_CAPWAP,        /**< [GG] 3: l4 sub type is CAPWAP, for l4 type is UDP*/
    CTC_IPFIX_L4_SUB_TYPE_NTP,           /**< [GG] 4: l4 sub type is NTP, for l4 type is UDP*/
    CTC_IPFIX_L4_SUB_TYPE_VXLAN,         /**< [GG] 5: l4 sub type is VXLAN, for l4 type is UDP*/
    CTC_IPFIX_L4_SUB_TYPE_MAX
};
typedef enum ctc_ipfix_l4_sub_type_e ctc_ipfix_l4_sub_type_t;

/**
 @brief  IPFIX Data struct, including key and ad infor
 for Export all infor is usefull; for lookup and cpu add/del key only key info is usefull
*/
struct ctc_ipfix_data_s
{
    uint32 flags;                 /**< [GG] reger to ctc_ipfix_data_flags_t */
    uint32 port_type;             /**< [GG] refer to ctc_ipfix_port_type_t*/
    uint32 key_type;              /**< [GG] refer to ctc_ipfix_key_type_t*/

    uint32 gport;                 /**< [GG] Used to identify local phy port, also identify GlobalPort if port_type is CTC_IPFIX_PORT_TYPE_GPORT */
    uint16 logic_port;            /**< [GG] Used to identify logic port or meter data, depends on port_type. */
    uint16 svlan;                 /**< [GG] VLAN identifier. */
    uint16 svlan_prio;            /**< [GG] VLAN priority. */
    uint16 svlan_cfi;             /**< [GG] VLAN CFI*/
    uint16 cvlan;                 /**< [GG] VLAN identifier. */
    uint16 cvlan_prio;            /**< [GG] VLAN priority. */
    uint16 cvlan_cfi;             /**< [GG] VLAN CFI*/
    uint16 ether_type;            /**< [GG] Type in ethernet II frame or 802.1Q tag. */

    uint16 rsv0;
    mac_addr_t src_mac;           /**< [GG] Source MAC address. */
    mac_addr_t dst_mac;           /**< [GG] Destination MAC address. */

    ctc_ipfix_l3_info_t l3_info;  /**< [GG] Layer3 data. */
    ctc_ipfix_l4_info_t l4_info;  /**< [GG] Layer4 data. */

     ctc_direction_t dir;         /**< [GG] Ingress or egress. >*/
     uint32 export_reason;        /**< [GG] Export reason used to construct ad information */
     uint32 start_timestamp;      /**< [GG] Start timestamp in this session. */
     uint32 last_timestamp;       /**< [GG] Last timestamp in this session. */
     uint64 byte_count;           /**< [GG] Total byts count in this session. */
     uint32 pkt_count;            /**< [GG] Total packets count in this session. */
     uint8  ttl;                  /**< [GG] TTL value of the first packet. */
     uint8  min_ttl;              /**< [GG] Min ttl value in  all packets. */
     uint8  max_ttl;              /**< [GG] Max ttl value in all packets. */
    uint8  rsv;
    uint16  dest_gport;           /**< [GG] Destination global port ID for unicast, include LinkAgg, valid if CTC_PKT_FLAG_MCAST is not set */
    uint16  dest_group_id;        /**< [GG] Destination group ID for multicast, valid if CTC_PKT_FLAG_MCAST is set */
} ;
typedef struct ctc_ipfix_data_s ctc_ipfix_data_t;

/** @brief IPFIX LOOKUP type */
enum ctc_ipfix_lkup_type_e
{
    CTC_IPFIX_HASH_LKUP_TYPE_DISABLE,     /**< [GG] Disable */
    CTC_IPFIX_HASH_LKUP_TYPE_L2,          /**< [GG] only use l2 field*/
    CTC_IPFIX_HASH_LKUP_TYPE_L3,          /**< [GG] only use l3 field*/
    CTC_IPFIX_HASH_LKUP_TYPE_L2L3,        /**< [GG] L2+ L3, Notice if using l2l3 type, must using etherType as one of hashsel elements*/
    CTC_IPFIX_HASH_LKUP_TYPE_MAX
};
typedef enum ctc_ipfix_lkup_type_e ctc_ipfix_lkup_type_t;

struct ctc_ipfix_hash_mac_field_sel_s
{
    uint8 mac_da;                /**< [GG] MAC DA select enable*/
    uint8 mac_sa;                /**< [GG] MAC SA select enable*/
    uint8 eth_type;              /**< [GG] Eth-Type select enable*/
    uint8 gport;                 /**< [GG] Using gport hash, not gport value*/
    uint8 logic_port;            /**< [GG] Logic port select enable*/
    uint8 metadata;              /**< [GG] Metadata select enable*/
    uint8 cos;                   /**< [GG] COS select enable*/
    uint8 cfi;                   /**< [GG] CFI SA select enable*/
    uint8 vlan_id;               /**< [GG] VLAN select enable*/
};
typedef struct ctc_ipfix_hash_mac_field_sel_s ctc_ipfix_hash_mac_field_sel_t;


struct ctc_ipfix_hash_ipv4_field_sel_s
{
    uint8  ip_da;           /**< [GG] IP DA select enable*/
    uint8  ip_da_mask;      /**< [GG] IP DA mask*/
    uint8  ip_sa;           /**< [GG] IP SA select enable*/
    uint8  ip_sa_mask;      /**< [GG] IP SA mask*/
    uint8  l4_src_port;     /**< [GG] l4 source port select enable*/
    uint8  l4_dst_port;     /**< [GG] l4 destination port select enable*/
    uint8  gport;           /**< [GG] Gport select enable*/
    uint8  logic_port;      /**< [GG] Logic port select enable*/
    uint8  metadata;        /**< [GG] Metadata select enable*/
    uint8  dscp;            /**< [GG] DSCP select enable*/
    uint8  ip_protocol;     /**< [GG] IP protocol select enable*/
    uint8  l4_sub_type;     /**< [GG] Before cfg l4_sub_type, first enable ip_protocol*/

    uint8  icmp_type;       /**< [GG] ICMP type select enable*/
    uint8  icmp_code;       /**< [GG] ICMP code select enable*/
    uint8  vxlan_vni;       /**< [GG] VXLAN select enable*/
    uint8  gre_key;         /**< [GG] GRE select enable*/
};
typedef struct ctc_ipfix_hash_ipv4_field_sel_s ctc_ipfix_hash_ipv4_field_sel_t;

struct ctc_ipfix_hash_mpls_field_sel_s
{
    uint8 logic_port;           /**< [GG] Logic port select enable*/
    uint8 gport;                /**< [GG] Gport select enable*/
    uint8 metadata;             /**< [GG] Metadata select enable*/
    uint8 label_num;            /**< [GG] MPLS lable number select enable*/
    uint8 mpls_label0_label;    /**< [GG] MPLS lable0 select enable*/
    uint8 mpls_label0_exp;      /**< [GG] MPLS lable0_exp select enable*/
    uint8 mpls_label0_s;        /**< [GG] MPLS lable0_s select enable*/
    uint8 mpls_label0_ttl;      /**< [GG] MPLS lable0_ttl select enable*/
    uint8 mpls_label1_label;    /**< [GG] MPLS lable1 select enable*/
    uint8 mpls_label1_exp;      /**< [GG] MPLS lable1_exp select enable*/
    uint8 mpls_label1_s;        /**< [GG] MPLS lable1_s select enable*/
    uint8 mpls_label1_ttl;      /**< [GG] MPLS lable1_ttl select enable*/
    uint8 mpls_label2_label;    /**< [GG] MPLS lable2 select enable*/
    uint8 mpls_label2_exp;      /**< [GG] MPLS lable2_exp select enable*/
    uint8 mpls_label2_s;        /**< [GG] MPLS lable2_s select enable*/
    uint8 mpls_label2_ttl;      /**< [GG] MPLS lable2_ttl select enable*/
};
typedef struct ctc_ipfix_hash_mpls_field_sel_s ctc_ipfix_hash_mpls_field_sel_t;

struct ctc_ipfix_hash_ipv6_field_sel_s
{
    uint8 ip_da;                /**< [GG] IP DA select enable*/
    uint8 ip_da_mask;           /**< [GG] Mask len value4,8,12,...,128 */
    uint8 ip_sa;                /**< [GG] IP SA select enable*/
    uint8 ip_sa_mask;           /**< [GG] Mask len value4,8,12,...,128 */
    uint8 l4_src_port;          /**< [GG] l4 source port select enable*/
    uint8 l4_dst_port;          /**< [GG] l4 destination port select enable*/
    uint8 gport;                /**< [GG] Gport select enable*/
    uint8 logic_port;           /**< [GG] Logic port select enable*/
    uint8 metadata;             /**< [GG] Metadata select enable*/
    uint8 dscp;                 /**< [GG] DSCP select enable*/
    uint8 flow_label;           /**< [GG] flow_label select enable*/
    uint8 l4_type;              /**< [GG] l4_type select enable*/
    uint8 l4_sub_type;          /**< [GG] Before cfg l4_sub_type, first enable l4_type. Only support VXLAN*/

    uint8 icmp_type;            /**< [GG] ICMP type select enable*/
    uint8 icmp_code;            /**< [GG] ICMP code select enable*/
    uint8 vxlan_vni;            /**< [GG] VXLAN select enable*/
    uint8 gre_key;              /**< [GG] GRE select enable*/
};
typedef struct ctc_ipfix_hash_ipv6_field_sel_s ctc_ipfix_hash_ipv6_field_sel_t;


struct ctc_ipfix_hash_l2_l3_field_sel_s
{
    uint8 gport;                /**< [GG] Gport select enable*/
    uint8 logic_port;           /**< [GG] Logic port select enable*/
    uint8 metadata;             /**< [GG] Metadata select enable*/
    uint8 mac_da;               /**< [GG] MAC DA select enable*/
    uint8 mac_sa;               /**< [GG] MAC SA select enable*/
    uint8 stag_cos;             /**< [GG] SVLAN COS select enable*/
    uint8 stag_cfi;             /**< [GG] SVLAN CFI select enable*/
    uint8 stag_vlan;            /**< [GG] SVLAN select enable*/
    uint8 ctag_cos;             /**< [GG] CVLAN COS select enable*/
    uint8 ctag_cfi;             /**< [GG] CVLAN COS select enable*/
    uint8 ctag_vlan;            /**< [GG] CVLAN select enable*/

    uint8 ip_da;                /**< [GG] IP DA select enable*/
    uint8 ip_da_mask;           /**< [GG] IP DA mask*/
    uint8 ip_sa;                /**< [GG] IP SA select enable*/
    uint8 ip_sa_mask;           /**< [GG] IP SA mask*/
    uint8 dscp;                 /**< [GG] DSCP select enable*/
    uint8 ecn;                  /**< [GG] ECN select enable*/
    uint8 ttl;                  /**< [GG] TTL select enable*/
    uint8 eth_type;             /**< [GG] Eth_type select enable*/
    uint8 vrfid;                /**< [GG] vrfid select enable*/
    uint8 l4_type;              /**< [GG] L4 type select enable*/
    uint8 l4_sub_type;          /**< [GG] Before cfg l4_sub_type, first enable l4_type*/

    uint8 gre_key;              /**< [GG] GRE select enable*/
    uint8 vxlan_vni;            /**< [GG] Vxlan select enable*/
    uint8 l4_src_port;          /**< [GG] l4 source port select enable*/
    uint8 l4_dst_port;          /**< [GG] l4 destination port select enable*/
    uint8 icmp_type;            /**< [GG] ICMP type select enable*/
    uint8 icmp_code;            /**< [GG] ICMP code select enable*/

    uint8 label_num;            /**< [GG] MPLS lable number select enable*/
    uint8 mpls_label0_label;    /**< [GG] MPLS lable0 select enable*/
    uint8 mpls_label0_exp;      /**< [GG] MPLS lable0_exp select enable*/
    uint8 mpls_label0_s;        /**< [GG] MPLS lable0_s select enable*/
    uint8 mpls_label0_ttl;      /**< [GG] MPLS lable0_ttl select enable*/
    uint8 mpls_label1_label;    /**< [GG] MPLS lable1 select enable*/
    uint8 mpls_label1_exp;      /**< [GG] MPLS lable1_exp select enable*/
    uint8 mpls_label1_s;        /**< [GG] MPLS lable1_s select enable*/
    uint8 mpls_label1_ttl;      /**< [GG] MPLS lable1_ttl select enable*/
    uint8 mpls_label2_label;    /**< [GG] MPLS lable2 select enable*/
    uint8 mpls_label2_exp;      /**< [GG] MPLS lable2_exp select enable*/
    uint8 mpls_label2_s;        /**< [GG] MPLS lable2_s select enable*/
    uint8 mpls_label2_ttl;      /**< [GG] MPLS lable2_ttl select enable*/

};
typedef struct ctc_ipfix_hash_l2_l3_field_sel_s ctc_ipfix_hash_l2_l3_field_sel_t;


struct ctc_ipfix_hash_field_sel_s
{
    uint8  key_type;                            /**< [GG] Refer ctc_ipfix_key_type_t */
    uint32 field_sel_id;                        /**< [GG] Hash select ID */

    union
    {
        ctc_ipfix_hash_mac_field_sel_t   mac;   /**< [GG] Hash key type is mac key*/
        ctc_ipfix_hash_mpls_field_sel_t  mpls;  /**< [GG] Hash key type is mpls key*/
        ctc_ipfix_hash_ipv4_field_sel_t  ipv4;  /**< [GG] Hash key type is ipv4 key*/
        ctc_ipfix_hash_ipv6_field_sel_t  ipv6;  /**< [GG] Hash key type is ipv6 key*/
        ctc_ipfix_hash_l2_l3_field_sel_t l2_l3; /**< [GG] Hash key type is l2l3 key*/
    }u;
};
typedef struct ctc_ipfix_hash_field_sel_s ctc_ipfix_hash_field_sel_t;

/* IPFIX port configuration structure */
struct ctc_ipfix_port_cfg_s
{
    uint8   dir;                    /**< [GG] Direction*/
    uint8   lkup_type;              /**< [GG] Refer to ctc_ipfix_lkup_type_t */
    uint8   field_sel_id;           /**< [GG] Field select id , used associate with ctc_ipfix_key_type_t */
    uint8   tcp_end_detect_disable; /**< [GG] Tcp end detect disable*/
    uint8   flow_type;              /**< [GG] IPFIX aim to packet type, refer to ctc_ipfix_flow_type_t*/
    uint8   learn_disable;          /**< [GG] Disable learn new flow based port*/
    uint16  sample_interval;        /**< [GG] Global support for packet interval*/
};
typedef struct ctc_ipfix_port_cfg_s ctc_ipfix_port_cfg_t;


/**
 @brief define learn & Aging  global config information
*/
struct ctc_ipfix_global_cfg_s
{
    uint32  aging_interval;        /**< [GG] Aging interval (s) */
    uint32  pkt_cnt;               /**< [GG] Number of packets to be export.*/
    uint64  bytes_cnt;             /**< [GG] Number of bytes threshold to be export.*/
    uint32  times_interval;        /**< [GG] Number of times interval to be export. */
    uint8   sample_mode;           /**< [GG] Sample mode, 0: based on all packet, 1: based on unknown packet*/
    uint8   conflict_export;       /**< [GG] Conflict entry export to cpu */
    uint8   vxlan_extern_en;       /**< [GG] When Vxlan flow using inner packet information do ipfix, can using outer l4 info as key  */
    uint8   nvgre_extern_en;       /**< [GG] When Nvgre flow using inner packet information do ipfix, can using outer l4 info as key  */
    uint8   tcp_end_detect_en;     /**< [GG] Global enable tcp end detect */
    uint8   rpf_check_en;          /**< [GG] Olny do ipfix for ingress RPF check fail packet */
    uint8   new_flow_export_en;    /**< [GG] New flow export control */
    uint8   sw_learning_en;        /**< [GG] Cpu add key and delete key, asic only do update, not insert */
    uint8   unkown_pkt_dest_type;  /**< [GG] 0:using group id, 1:using vlan id */
    uint8   rsv;
};
typedef struct ctc_ipfix_global_cfg_s ctc_ipfix_global_cfg_t;

enum ctc_ipfix_traverse_type_e
{
    CTC_IPFIX_TRAVERSE_BY_ALL,     /**< [GG] Traverse by all */
    CTC_IPFIX_TRAVERSE_BY_PORT,    /**< [GG] Traverse by port */
    CTC_IPFIX_TRAVERSE_BY_DIR,     /**< [GG] Traverse by direction */
    CTC_IPFIX_TRAVERSE_BY_PORT_DIR /**< [GG] Traverse by port and direction */
};
typedef enum ctc_ipfix_traverse_type_e ctc_ipfix_traverse_type_t;

struct ctc_ipfix_traverse_s
{
    void*   user_data;
    uint32  start_index;         /**< [GG] If it is the first traverse, it is equal to 0, else it is equal to the last next_traverse_index */
    uint32  next_traverse_index; /**< [GG] [out] return index of the next traverse */
    uint8   is_end;              /**< [GG] [out] if is_end == 1, indicate the end of traverse */
    uint16  entry_num;           /**< [GG] indicate entry number for one traverse function, total entry num is 8k */

    uint32 gport;               /**< [GG] Traverse by port, it is Gport */
    uint8   dir;                 /**< [GG] Traverse by direction, 0 is ingress,1 is egress*/
    uint8   type;                /**< [GG] Traverse type, refer ctc_ipfix_traverse_type_t */
    uint8   rsv;
};
typedef struct ctc_ipfix_traverse_s ctc_ipfix_traverse_t;

/* ctc_ipfix_fn_t */
typedef void (*ctc_ipfix_fn_t)( ctc_ipfix_data_t* info, void* userdata);
typedef int32 (* ctc_ipfix_traverse_fn)(ctc_ipfix_data_t* p_data, void* user_data);

/**@} end of @defgroup ipfix  */

#ifdef __cplusplus
}
#endif

#endif
