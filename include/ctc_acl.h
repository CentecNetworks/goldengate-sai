/**
 @file ctc_acl.h

 @date 2012-10-19

 @version v2.0

 The file define api struct used in ACL.
*/

#ifndef _CTC_ACL_H_
#define _CTC_ACL_H_

#ifdef __cplusplus
extern "C" {
#endif
/****************************************************************
 *
 * Header Files
 *
 ***************************************************************/

#include "ctc_const.h"
/****************************************************************
*
* Defines and Macros
*
****************************************************************/
#define  CTC_ACL_GROUP_ID_NORMAL         0xFFFF0000  /* Max normal group id */
/* Below groups are created already. just use it . */
#define  CTC_ACL_GROUP_ID_HASH_MAC       0xFFFF0001
#define  CTC_ACL_GROUP_ID_HASH_IPV4      0xFFFF0002
#define  CTC_ACL_GROUP_ID_HASH_MPLS      0xFFFF0003
#define  CTC_ACL_GROUP_ID_HASH_L2_L3     0xFFFF0004
#define  CTC_ACL_GROUP_ID_HASH_IPV6      0xFFFF0005
#define  CTC_ACL_GROUP_ID_HASH_RSV_0     0xFFFF0006
#define  CTC_ACL_GROUP_ID_MAX            0xFFFF0007  /* Always last group id. Invalid group id */
#define  CTC_ACL_ENTRY_PRIORITY_HIGHEST  0xFFFFFFFF
#define  CTC_ACL_ENTRY_PRIORITY_LOWEST   0
#define  CTC_ACL_ENTRY_PRIORITY_DEFAULT  1

#define        CTC_ACL_KEY_SIZE_SINGLE    0
#define        CTC_ACL_KEY_SIZE_DOUBLE    1

#define        CTC_ACL_UDF_BYTE_NUM    4
/****************************************************************
*
* Data Structures
*
****************************************************************/

enum ctc_acl_action_field_type_e
{
    CTC_ACL_ACTION_FIELD_COPY_TO_CPU,           /**< [DT2] Copy To Cpu; data0: Index; data1: Sub Index. */
    CTC_ACL_ACTION_FIELD_DENY_BRIDGE,           /**< [DT2] Deny Bridge. */
    CTC_ACL_ACTION_FIELD_DENY_LEARNING,         /**< [DT2] Deny Learning. */
    CTC_ACL_ACTION_FIELD_DENY_ROUTE,            /**< [DT2] Deny Route. */
    CTC_ACL_ACTION_FIELD_STATS,                 /**< [DT2] Packet Statistics; data0: Stats Id */
    CTC_ACL_ACTION_FIELD_RANDOM_LOG,            /**< [DT2] Random Log To Cpu; data0: Log Id; data1: Log Percent. */
    CTC_ACL_ACTION_FIELD_COLOR,                 /**< [DT2] Change Color; data0: New Color. */
    CTC_ACL_ACTION_FIELD_DSCP,                  /**< [DT2] Dscp; data0: New Dscp*/
    CTC_ACL_ACTION_FIELD_MICRO_FLOW_POLICER,    /**< [DT2] Micro Flow Policer; data0: Micro Policer Id. */
    CTC_ACL_ACTION_FIELD_MACRO_FLOW_POLICER,    /**< [DT2] Macro Flow Policer; data0: Macro Policer Id. */

    CTC_ACL_ACTION_FIELD_REDIRECT,              /**< [DT2] Redirect Packet; data0: Nexthop Id. */
    CTC_ACL_ACTION_FIELD_REDIRECT_PORT,         /**< [DT2] Redirect Packet to Single Port; data0: Nexthop Id; data1: Assign Port. */

    CTC_ACL_ACTION_FIELD_DISCARD,               /**< [DT2] Discard Packet of All Color. */
    CTC_ACL_ACTION_FIELD_DISCARD_GREEN,         /**< [DT2] Discard Green Packet. */
    CTC_ACL_ACTION_FIELD_DISCARD_YELLOW,        /**< [DT2] Discard Yellow Packet. */
    CTC_ACL_ACTION_FIELD_DISCARD_RED,           /**< [DT2] Discard Red Packet. */

    CTC_ACL_ACTION_FIELD_CANCEL_DISCARD,        /**< [DT2] Cancel Discard Packet of All Color. */
    CTC_ACL_ACTION_FIELD_CANCEL_DISCARD_GREEN,  /**< [DT2] Cancel Discard Green Packet. */
    CTC_ACL_ACTION_FIELD_CANCEL_DISCARD_YELLOW, /**< [DT2] Cancel Discard Yellow Packet. */
    CTC_ACL_ACTION_FIELD_CANCEL_DISCARD_RED,    /**< [DT2] Cancel Discard Red Packet. */

    CTC_ACL_ACTION_FIELD_PRIORITY,              /**< [DT2] Change Priority of All Color; data0: New Priority. */
    CTC_ACL_ACTION_FIELD_PRIORITY_GREEN,        /**< [DT2] Change Green Priority; data0: New Priority. */
    CTC_ACL_ACTION_FIELD_PRIORITY_YELLOW,       /**< [DT2] Change Yellow Priority; data0: New Priority. */
    CTC_ACL_ACTION_FIELD_PRIORITY_RED,          /**< [DT2] Change Red Priority; data0: New Priority. */

    CTC_ACL_ACTION_FIELD_DISABLE_ELEPHANT_LOG,  /**< [DT2] Disable Elephant Flow Log to cpu. */
    CTC_ACL_ACTION_FIELD_TERMINATE_SGT_HDR,     /**< [DT2] Do not Insert SGT Header to Packet. */
    CTC_ACL_ACTION_FIELD_CANCEL_NAT,             /**< [DT2] Do Not perform NAT on this matching packet. */

    CTC_ACL_ACTION_FIELD_IPFIX_PROFILE_ID,      /**< [DT2] Set Ipfix Cfg Profile Id; data0: Profile Id. */
    CTC_ACL_ACTION_FIELD_IPFIX_HASH_FIELD_SEL,  /**< [DT2] Set Ipfix Hash Field Select Id; data0: Field Sel Id. */
    CTC_ACL_ACTION_FIELD_IPFIX_HASH_TYPE,       /**< [DT2] Set Ipfix Hash Type; data0: Hash Type. */
    CTC_ACL_ACTION_FIELD_IPFIX_USE_MAPPED_VLAN, /**< [DT2] Set Ipfix Use Mapped Vlan. */
    CTC_ACL_ACTION_FIELD_DISABLE_IPFIX,         /**< [DT2] Disable Ipfix. */
    CTC_ACL_ACTION_FIELD_DENY_IPFIX_LEARNING,   /**< [DT2] Disable Ipfix Learning. */

    CTC_ACL_ACTION_FIELD_REPLACE_LAG_HASH,      /**< [DT2] Replace Linkagg Hash Value; data0: Linkagg Hash. */
    CTC_ACL_ACTION_FIELD_REPLACE_ECMP_HASH,     /**< [DT2] Replace ECMP Hash Value; data0: Ecmp Hash. */

    CTC_ACL_ACTION_FIELD_METADATA,              /**< [DT2] Metedata; data0: Metadata. */
    CTC_ACL_ACTION_FIELD_ECN_ACTION,            /**< [DT2] ECN Action; data0: Action Mode; data1: Action. */

    CTC_ACL_ACTION_FIELD_VLAN_EDIT,             /**< [DT2] Vlan Edit; ext_data: ctc_acl_vlan_edit_t. */
    CTC_ACL_ACTION_FIELD_STRIP_PACKET,          /**< [DT2] Strip Packet; ext_data: ctc_acl_packet_strip_t. */

    CTC_ACL_ACTION_FIELD_NUM
};
typedef enum ctc_acl_action_field_type_e ctc_acl_action_field_type_t;

struct ctc_acl_field_action_s
{
    uint16 type;                    /**< [DT2] Action Field type, CTC_ACL_ACTION_FIELD_XXX. */

    uint32 data0;                   /**< [DT2] Action Field data0 (uint32). */
    uint32 data1;                   /**< [DT2] Action Field data1 (uint32). */
    void*  ext_data;                /**< [DT2] Action Field extend data (void*). */
};
typedef struct ctc_acl_field_action_s ctc_acl_field_action_t;

/** @brief  ACl Key Type */
enum ctc_acl_key_type_e
{
    CTC_ACL_KEY_MAC = 0,            /**< [HB.GB.GG.DT2] ACL MAC key type */
    CTC_ACL_KEY_IPV4,               /**< [HB.GB.GG.DT2] ACL IPv4 key type */
    CTC_ACL_KEY_MPLS,               /**< [HB.GB] ACL MPLS key type */
    CTC_ACL_KEY_IPV6,               /**< [HB.GB.GG.DT2] Mode 0: ACL Mac+IPv6 key type;
                                                        Mode 1: ACL Ipv6 key type */
    CTC_ACL_KEY_HASH_MAC,           /**< [GB.GG.DT2] ACL MAC Hash key type */
    CTC_ACL_KEY_HASH_IPV4,          /**< [GB.GG.DT2] ACL IPv4 Hash key type */
    CTC_ACL_KEY_HASH_L2_L3,         /**< [GG.DT2] ACL L2 L3 Hash key type */
    CTC_ACL_KEY_HASH_MPLS,          /**< [GG.DT2] ACL MPLS Hash key type */
    CTC_ACL_KEY_HASH_IPV6,          /**< [GG.DT2] ACL IPv6 Hash key type */
    CTC_ACL_KEY_PBR_IPV4,           /**< [HB.GB.GG] ACL PBR IPv4 key type */
    CTC_ACL_KEY_PBR_IPV6,           /**< [HB.GB.GG] ACL PBR IPv6 key type */

    CTC_ACL_KEY_IPV4_EXT,           /**< [DT2] ACL IPv4 extend key type */
    CTC_ACL_KEY_MAC_IPV4,           /**< [DT2] ACL Mac+IPv4 key type */
    CTC_ACL_KEY_MAC_IPV4_EXT,       /**< [DT2] ACL Mac+IPv4 extend key type */
    CTC_ACL_KEY_IPV6_EXT,           /**< [DT2] ACL IPv6 extend key type */
    CTC_ACL_KEY_MAC_IPV6,           /**< [DT2] ACL Mac+IPv6 extend key type */

    CTC_ACL_KEY_SGT,                /**< [DT2] ACL SGT basic key type */
    CTC_ACL_KEY_INTERFACE,          /**< [DT2] ACL Interface key type */
    CTC_ACL_KEY_FWD,                /**< [DT2] ACL Forward key type */
    CTC_ACL_KEY_FWD_EXT,            /**< [DT2] ACL Forward key type */

    CTC_ACL_KEY_NUM
};
typedef enum ctc_acl_key_type_e ctc_acl_key_type_t;


struct ctc_acl_hash_mac_key_s
{
    uint32 field_sel_id;        /**< [GG] Field Select Id*/

    uint32 gport;               /**< [GB.GG] Global source port, share with logic port and metadata */
    uint8  gport_is_logic_port; /**< [GB] GPort is logic port */

    mac_addr_t mac_da;          /**< [GB.GG] MAC-DA */
    mac_addr_t mac_sa;          /**< [GG] MAC-DA */

    uint16 eth_type;            /**< [GB.GG] Ethernet type */

    uint8  is_ctag;             /**< [GG] tag is ctag */
    uint8  cos;                 /**< [GB.GG] tag Cos */
    uint16 vlan_id;             /**< [GB.GG] tag Vlan Id */
    uint8  tag_valid;           /**< [GG] tag exist */
    uint8  cfi;             /**< [GG] tag Cfi */

};
typedef struct ctc_acl_hash_mac_key_s  ctc_acl_hash_mac_key_t;


struct ctc_acl_hash_ipv4_key_s
{
    uint32 field_sel_id;         /**< [GG] Field Select Id*/

    uint32 gport;                /**< [GB.GG] Global source port */
    uint8  gport_is_logic_port;  /**< [GB] Gport is logic port */
    uint32 metadata;             /**< [GG] Metadata */

    uint32 ip_sa;                /**< [GB.GG] IP-SA */
    uint32 ip_da;                /**< [GB.GG] IP-DA */

    uint8  dscp;                 /**< [GB.GG] DSCP */
    uint8  ecn;                  /**< [GG] ECN */
    uint8  l4_protocol;          /**< [GB.GG] L4 Protocol */
    uint8  arp_packet;           /**< [GB] Is arp packet */

    uint8  icmp_type;            /**< [GG] ICMP type */
    uint8  icmp_code;            /**< [GG] ICMP code */

    uint16 l4_src_port;          /**< [GB.GG] Layer 4 source port.*/
    uint16 l4_dst_port;          /**< [GB.GG] Layer 4 dest port */
};
typedef struct ctc_acl_hash_ipv4_key_s  ctc_acl_hash_ipv4_key_t;


struct ctc_acl_hash_mpls_key_s
{
    uint32 field_sel_id;        /**< [GG] Field Select Id*/

    uint32 gport;               /**< [GG] Global source port */
    uint32 metadata;            /**< [GG] Metadata */

    uint8  mpls_label_num;           /**< [GG] Metadata */

    uint32 mpls_label0_label;         /**< [GG] MPLS Label 0 */
    uint8  mpls_label0_exp;           /**< [GG] MPLS Exp 0 */
    uint8  mpls_label0_s;             /**< [GG] MPLS S-bit 0 */
    uint8  mpls_label0_ttl;           /**< [GG] MPLS Ttl 0 */

    uint32 mpls_label1_label;         /**< [GG] MPLS Label 1 */
    uint8  mpls_label1_exp;           /**< [GG] MPLS Exp 1 */
    uint8  mpls_label1_s;             /**< [GG] MPLS S-bit 1 */
    uint8  mpls_label1_ttl;           /**< [GG] MPLS Ttl 1 */

    uint32 mpls_label2_label;         /**< [GG] MPLS Label 2 */
    uint8  mpls_label2_exp;           /**< [GG] MPLS Exp 2 */
    uint8  mpls_label2_s;             /**< [GG] MPLS S-bit 2 */
    uint8  mpls_label2_ttl;           /**< [GG] MPLS Ttl 2 */
};
typedef struct ctc_acl_hash_mpls_key_s  ctc_acl_hash_mpls_key_t;


struct ctc_acl_hash_ipv6_key_s
{
    uint32 field_sel_id;        /**< [GG] Field Select Id*/

    uint32 gport;               /**< [GG] Global source port, share with logic port and metadata*/
    ipv6_addr_t ip_sa;          /**< [GG] IP-SA */
    ipv6_addr_t ip_da;          /**< [GG] IP-DA */

    uint8  dscp;                /**< [GG] DSCP */
    uint8  l4_type;             /**< [GG] Layer 4 type */
    uint8  icmp_type;            /**< [GG] ICMP type */
    uint8  icmp_code;            /**< [GG] ICMP code */

    uint16 l4_src_port;         /**< [GG] Layer 4 source port.*/
    uint16 l4_dst_port;         /**< [GG] Layer 4 dest port */
};
typedef struct ctc_acl_hash_ipv6_key_s  ctc_acl_hash_ipv6_key_t;


struct ctc_acl_hash_l2_l3_key_s
{
    uint32 field_sel_id;        /**< [GG] Field Select Id*/
    uint8  l3_type;             /**< [GG] config to distinguish mpls, ipv4. refer ctc_parser_l3_type_t  */

    uint32 gport;               /**< [GG] Global source port */
    uint32 metadata;            /**< [GG] Metadata*/

    mac_addr_t mac_da;          /**< [GG] MAC-DA */
    mac_addr_t mac_sa;          /**< [GG] MAC-DA */

    uint8  stag_cos;            /**< [GG] Stag Cos */
    uint16 stag_vlan;           /**< [GG] Stag Vlan Id */
    uint8  stag_valid;          /**< [GG] Stag Exist */
    uint8  stag_cfi;            /**< [GG] Stag Cos */

    uint8  ctag_cos;            /**< [GG] Ctag Cos */
    uint16 ctag_vlan;           /**< [GG] Ctag Vlan Id */
    uint8  ctag_valid;          /**< [GG] Ctag Exist */
    uint8  ctag_cfi;            /**< [GG] Ctag Cos */

    uint32 ip_sa;               /**< [GG] IP-SA */
    uint32 ip_da;               /**< [GG] IP-DA */

    uint8  dscp;                /**< [GG] DSCP */
    uint8  ecn;                 /**< [GG] ECN*/
    uint8  ttl;                 /**< [GG] TTL */

    uint16 eth_type;            /**< [GG] Ethernet type */
    uint8  l4_type;             /**< [GG] Layer4 type */

    uint8  mpls_label_num;      /**< [GG] Label Num */

    uint32 mpls_label0_label;   /**< [GG] MPLS Label 0 */
    uint8  mpls_label0_exp;     /**< [GG] MPLS Exp 0 */
    uint8  mpls_label0_s;       /**< [GG] MPLS S-bit 0 */
    uint8  mpls_label0_ttl;     /**< [GG] MPLS Ttl 0 */

    uint32 mpls_label1_label;   /**< [GG] MPLS Label 1 */
    uint8  mpls_label1_exp;     /**< [GG] MPLS Exp 1 */
    uint8  mpls_label1_s;       /**< [GG] MPLS S-bit 1 */
    uint8  mpls_label1_ttl;     /**< [GG] MPLS Ttl 1 */

    uint32 mpls_label2_label;   /**< [GG] MPLS Label 2 */
    uint8  mpls_label2_exp;     /**< [GG] MPLS Exp 2 */
    uint8  mpls_label2_s;       /**< [GG] MPLS S-bit 2 */
    uint8  mpls_label2_ttl;     /**< [GG] MPLS Ttl 2 */

    uint16 l4_src_port;         /**< [GG] Layer 4 source port.*/
    uint16 l4_dst_port;         /**< [GG] Layer 4 dest port */

    uint8  icmp_type;           /**< [GG] ICMP type */
    uint8  icmp_code;           /**< [GG] ICMP code */
};
typedef struct ctc_acl_hash_l2_l3_key_s  ctc_acl_hash_l2_l3_key_t;



/** @brief  Mac key field flag*/
enum ctc_acl_mac_key_flag_e
{
    CTC_ACL_MAC_KEY_FLAG_MAC_DA      = 1U << 0,  /**< [HB.GB.GG] Valid MAC-DA in MAC key */
    CTC_ACL_MAC_KEY_FLAG_MAC_SA      = 1U << 1,  /**< [HB.GB.GG] Valid MAC-SA in MAC key */
    CTC_ACL_MAC_KEY_FLAG_COS         = 1U << 2,  /**< [HB] Valid CoS in MAC key */
    CTC_ACL_MAC_KEY_FLAG_CVLAN       = 1U << 3,  /**< [HB.GB.GG] Valid C-VLAN in MAC key */
    CTC_ACL_MAC_KEY_FLAG_CTAG_COS    = 1U << 4,  /**< [HB.GB.GG] Valid C-tag CoS in MAC key */
    CTC_ACL_MAC_KEY_FLAG_SVLAN       = 1U << 5,  /**< [HB.GB.GG] Valid S-VLAN in MAC key */
    CTC_ACL_MAC_KEY_FLAG_STAG_COS    = 1U << 6,  /**< [HB.GB.GG] Valid S-tag CoS in MAC key */
    CTC_ACL_MAC_KEY_FLAG_ETH_TYPE    = 1U << 7,  /**< [HB.GB.GG] Valid eth-type in MAC key */
    CTC_ACL_MAC_KEY_FLAG_L2_TYPE     = 1U << 8,  /**< [HB.GB.GG] Valid l2-type in MAC key */
    CTC_ACL_MAC_KEY_FLAG_L3_TYPE     = 1U << 9,  /**< [HB.GB.GG] Valid l3-type in MAC key */
    CTC_ACL_MAC_KEY_FLAG_CTAG_CFI    = 1U << 10, /**< [HB.GB.GG] Valid l2-type in MAC key */
    CTC_ACL_MAC_KEY_FLAG_STAG_CFI    = 1U << 11, /**< [HB.GB.GG] Valid l3-type in MAC key */
    CTC_ACL_MAC_KEY_FLAG_ARP_OP_CODE = 1U << 12, /**< [GB] Valid Arp-op-code in MAC key */
    CTC_ACL_MAC_KEY_FLAG_IP_SA       = 1U << 13, /**< [GB] Valid Ip-sa in MAC key */
    CTC_ACL_MAC_KEY_FLAG_IP_DA       = 1U << 14, /**< [GB] Valid Ip-da in MAC key */
    CTC_ACL_MAC_KEY_FLAG_STAG_VALID  = 1U << 15, /**< [GB.GG] Valid stag-valid in MAC key */
    CTC_ACL_MAC_KEY_FLAG_CTAG_VALID  = 1U << 16, /**< [GB.GG] Valid ctag-valid in MAC key */
    CTC_ACL_MAC_KEY_FLAG_VLAN_NUM    = 1U << 17, /**< [GG] Valid vlan number in MAC key */
    CTC_ACL_MAC_KEY_FLAG_METADATA    = 1U << 18  /**< [GG] Valid metadata in MAC key */
};
typedef enum ctc_acl_mac_key_flag_e ctc_acl_mac_key_flag_t;


struct ctc_acl_mac_key_s
{
    uint32 flag;                /**< [HB.GB.GG] Bitmap of CTC_ACL_MAC_KEY_FLAG_XXX */

    mac_addr_t mac_da;          /**< [HB.GB.GG] MAC-DA */
    mac_addr_t mac_da_mask;     /**< [HB.GB.GG] MAC-DA mask */
    mac_addr_t mac_sa;          /**< [HB.GB.GG] MAC-SA */
    mac_addr_t mac_sa_mask;     /**< [HB.GB.GG] MAC-SA mask */

    uint16 cvlan;               /**< [HB.GB.GG] C-VLAN */
    uint16 cvlan_mask;          /**< [HB.GB.GG] C-VLAN mask*/
    uint16 svlan;               /**< [HB.GB.GG] S-VLAN */
    uint16 svlan_mask;          /**< [HB.GB.GG] S-VLAN mask*/

    uint8  ctag_cos;            /**< [HB.GB.GG] C-tag CoS */
    uint8  ctag_cos_mask;       /**< [HB.GB.GG] C-tag CoS mask*/
    uint8  ctag_cfi;            /**< [HB.GB.GG] C-tag CFI */
    uint8  stag_cos;            /**< [HB.GB.GG] S-tag CoS */
    uint8  stag_cos_mask;       /**< [HB.GB.GG] S-tag CoS mask*/
    uint8  stag_cfi;            /**< [HB.GB.GG] S-tag CFI */

    uint8  l2_type;             /**< [HB.GB] Layer 2 type. Refer to ctc_parser_l2_type_t */
    uint8  l2_type_mask;        /**< [HB.GB] Layer 2 type mask*/
    uint8  l3_type;             /**< [HB.GB.GG] Layer 3 type. Refer to ctc_parser_l3_type_t */
    uint8  l3_type_mask;        /**< [HB.GB.GG] Layer 3 type mask*/
    uint16 eth_type;            /**< [HB.GB.GG] Ethernet type, for unknow or flexible L3 type in GG */
    uint16 eth_type_mask;       /**< [HB.GB.GG] Ethernet type mask*/

    uint8  cos;                 /**< [HB] Packet_info.src_cos in IPE, packet_info.new_cos in EPE */
    uint8  cos_mask;            /**< [HB] Cos mask */

    uint16 arp_op_code;         /**< [GB] Arp op code*/
    uint16 arp_op_code_mask;    /**< [GB] Arp op code mask*/
    uint32 ip_sa;               /**< [GB] Ip source address */
    uint32 ip_sa_mask;          /**< [GB] Ip source address mask */
    uint32 ip_da;               /**< [GB] Ip destination address */
    uint32 ip_da_mask;          /**< [GB] Ip destination address mask*/
    uint8  stag_valid;          /**< [GB.GG] Stag valid */
    uint8  ctag_valid;          /**< [GB.GG] Ctag valid */

    uint32 metadata;            /**< [GG] metadata */
    uint32 metadata_mask;       /**< [GG] metadata mask*/

    uint8 vlan_num;            /**< [GG] vlan number */
    uint8 vlan_num_mask;       /**< [GG] vlan number mask */

};
typedef struct ctc_acl_mac_key_s  ctc_acl_mac_key_t;

enum ctc_acl_ipv4_key_flag_e
{

    CTC_ACL_IPV4_KEY_FLAG_MAC_DA        = 1U << 0,  /**< [HB.GB.GG-D] Valid MAC-DA in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_MAC_SA        = 1U << 1,  /**< [HB.GB.GG-D] Valid MAC-SA in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_COS           = 1U << 2,  /**< [HB] Valid CoS in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_CVLAN         = 1U << 3,  /**< [HB.GB.GG-D] Valid C-VLAN in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_CTAG_COS      = 1U << 4,  /**< [HB.GB.GG-D] Valid C-tag CoS in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_SVLAN         = 1U << 5,  /**< [HB.GB.GG-D] Valid S-VLAN in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_STAG_COS      = 1U << 6,  /**< [HB.GB.GG-D] Valid S-tag CoS in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_L2_TYPE       = 1U << 7,  /**< [HB.GB.GG] Valid l2-type in IPv4 key. NOTE: Limited support on GB. When merge key,
                                                                    collision with FLAG_DSCP/FLAG_PRECEDENCE. And ineffective for ipv4_packet.*/
    CTC_ACL_IPV4_KEY_FLAG_L3_TYPE       = 1U << 8,  /**< [HB.GG] Valid l3-type in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_IP_SA         = 1U << 9,  /**< [HB.GB.GG] Valid IP-SA in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_IP_DA         = 1U << 10, /**< [HB.GB.GG] Valid IP-DA in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_L4_PROTOCOL   = 1U << 11, /**< [HB.GB.GG] Valid L4-Proto in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_DSCP          = 1U << 12, /**< [HB.GB.GG] Valid DSCP in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_PRECEDENCE    = 1U << 13, /**< [HB.GB.GG] Valid IP Precedence in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_IP_FRAG       = 1U << 14, /**< [HB.GB.GG] Valid fragment in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_IP_OPTION     = 1U << 15, /**< [HB.GB.GG] Valid IP option in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_ROUTED_PACKET = 1U << 16, /**< [HB.GB.GG] Valid routed packet in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_CTAG_CFI      = 1U << 17, /**< [HB.GB.GG-D] Valid C-tag CoS in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_STAG_CFI      = 1U << 18, /**< [HB.GB.GG-D] Valid S-tag CoS in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_STAG_VALID    = 1U << 19, /**< [GB.GG-D] Valid Stag-valid in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_CTAG_VALID    = 1U << 20, /**< [GB.GG-D] Valid Ctag-valid in IPv4 key */
    CTC_ACL_IPV4_KEY_FLAG_ETH_TYPE      = 1U << 22, /**< [GB.GG] Valid Ether type in IPv4 Key. NOTE:  (GB) Used when merge key, collision with L4_DST_PORT.
                                                                    Do NOT set this flag on Egress ACL. And If required matching ipv4 packet,
                                                                    Do NOT set this flag with set ether_type = 0x0800. Set CTC_ACL_IPV4_KEY_FLAG_IPV4_PACKET instead. */
    CTC_ACL_IPV4_KEY_FLAG_IPV4_PACKET   = 1U << 23, /**< [GB] Valid Ipv4 packet in IPv4 Key. NOTE: (GB) used when merge key. For non-merge, Ipv4 key only for ipv4/arp packet.*/
    CTC_ACL_IPV4_KEY_FLAG_ARP_PACKET    = 1U << 24, /**< [GB] Valid Arp packet in IPv4 Key. NOTE: (GB) used when merge key. For non-merge, Ipv4 key only for ipv4/arp packet.*/
    CTC_ACL_IPV4_KEY_FLAG_ECN           = 1U << 25, /**< [GG] */
    CTC_ACL_IPV4_KEY_FLAG_METADATA      = 1U << 26,  /**< [GG] Valid metadata in ipv4 key */
    CTC_ACL_IPV4_KEY_FLAG_UDF      = 1U << 27  /**< [GG-D] Valid udf in ipv4 key */
};
typedef enum ctc_acl_ipv4_key_flag_e ctc_acl_ipv4_key_flag_t;


enum ctc_acl_ipv4_key_sub_flag_e
{
    CTC_ACL_IPV4_KEY_SUB_FLAG_L4_SRC_PORT       = 1U << 0, /**< [HB.GB.GG] Depend on L4_PROTOCOL = TCP|UDP. Valid L4 source port in IPv4 key */
    CTC_ACL_IPV4_KEY_SUB_FLAG_L4_DST_PORT       = 1U << 1, /**< [HB.GB.GG] Depend on L4_PROTOCOL = TCP|UDP. Valid L4 destination port in IPv4 key */
    CTC_ACL_IPV4_KEY_SUB_FLAG_TCP_FLAGS         = 1U << 2, /**< [HB.GB.GG] Depend on L4_PROTOCOL = TCP. Valid TCP flag in IPv4 key */
    CTC_ACL_IPV4_KEY_SUB_FLAG_ICMP_TYPE         = 1U << 3, /**< [HB.GB.GG] Depend on L4_PROTOCOL = ICMP. Valid ICMP type in IPv4 key */
    CTC_ACL_IPV4_KEY_SUB_FLAG_ICMP_CODE         = 1U << 4, /**< [HB.GB.GG] Depend on L4_PROTOCOL = ICMP. Valid ICMP code in IPv4 key */
    CTC_ACL_IPV4_KEY_SUB_FLAG_IGMP_TYPE         = 1U << 5, /**< [HB.GB.GG] Depend on L4_PROTOCOL = IGMP. Valid IGMP type in IPv4 key */
    CTC_ACL_IPV4_KEY_SUB_FLAG_ARP_OP_CODE       = 1U << 6, /**< [GB.GG] (GB)Depend on ARP_PACKET. (GG)Depend on L3_TYPE. Valid Arp op code in Arp Key. */
    CTC_ACL_IPV4_KEY_SUB_FLAG_ARP_SENDER_IP     = 1U << 7, /**< [GB.GG] (GB)Depend on ARP_PACKET. (GG)Depend on L3_TYPE. Valid Arp sender Ip in Arp Key. */
    CTC_ACL_IPV4_KEY_SUB_FLAG_ARP_TARGET_IP     = 1U << 8, /**< [GB.GG] (GB)Depend on ARP_PACKET. (GG)Depend on L3_TYPE. Valid Arp target Ip in Arp Key. */
    CTC_ACL_IPV4_KEY_SUB_FLAG_ARP_PROTOCOL_TYPE = 1U << 9, /**< [GG] (GB)Depend on ARP_PACKET. (GG)Depend on L3_TYPE. Valid Arp target Ip in Arp Key. */
    CTC_ACL_IPV4_KEY_SUB_FLAG_GRE_KEY           = 1U << 10,/**< [GG] Depend on L4_PROTOCOL = GRE. Valid GRE key in IPv4 key */
    CTC_ACL_IPV4_KEY_SUB_FLAG_VNI               = 1U << 11,/**< [GG] Depend on L4_PROTOCOL = UDP. Valid vni in IPv4 key */
    CTC_ACL_IPV4_KEY_SUB_FLAG_NVGRE_KEY         = 1U << 12 /**< [GG] Depend on L4_PROTOCOL = NVGRE. Valid NVGRE key in IPv4 key */
};
typedef enum ctc_acl_ipv4_key_sub_flag_e ctc_acl_ipv4_key_sub_flag_t;

enum ctc_acl_ipv4_key_sub1_flag_e
{

    CTC_ACL_IPV4_KEY_SUB1_FLAG_MPLS_LABEL_NUM,         /**< [GG] MPLS label number field*/
    CTC_ACL_IPV4_KEY_SUB1_FLAG_MPLS_LABEL0,            /**< [GG] MPLS label 0 as key field*/
    CTC_ACL_IPV4_KEY_SUB1_FLAG_MPLS_LABEL1,            /**< [GG] MPLS label 1 as key field*/
    CTC_ACL_IPV4_KEY_SUB1_FLAG_MPLS_LABEL2,            /**< [GG] MPLS label 2 as key field*/
};
typedef enum ctc_acl_ipv4_key_sub1_flag_e ctc_acl_ipv4_key_sub1_flag_t;

enum ctc_acl_ipv4_key_sub3_flag_e
{
    CTC_ACL_IPV4_KEY_SUB3_FLAG_ETHOAM_LEVEL = 1U << 0,      /**< [GG] Ether oam level as key field*/
    CTC_ACL_IPV4_KEY_SUB3_FLAG_ETHOAM_OPCODE = 1U << 1     /**< [GG] Ether oam opcode as key field*/
};
typedef enum ctc_acl_ipv4_key_sub3_flag_e ctc_acl_ipv4_key_sub3_flag_t;


enum ctc_acl_tcp_flag_flag_e
{
    CTC_ACL_TCP_FIN_FLAG = 1U << 0, /**< [HB.GB.GG] TCP fin flag */
    CTC_ACL_TCP_SYN_FLAG = 1U << 1, /**< [HB.GB.GG] TCP syn flag */
    CTC_ACL_TCP_RST_FLAG = 1U << 2, /**< [HB.GB.GG] TCP rst flag */
    CTC_ACL_TCP_PSH_FLAG = 1U << 3, /**< [HB.GB.GG] TCP psh flag */
    CTC_ACL_TCP_ACK_FLAG = 1U << 4, /**< [HB.GB.GG] TCP ack flag */
    CTC_ACL_TCP_URG_FLAG = 1U << 5  /**< [HB.GB.GG] TCP urg flag */
};
typedef enum ctc_acl_tcp_flag_flag_e ctc_acl_tcp_flag_flag_t;


struct ctc_acl_ipv4_key_s
{
    uint32 flag;                        /**< [HB.GB.GG] Bitmap of CTC_ACL_IPV4_KEY_FLAG_XXX */
    uint32 sub_flag;                    /**< [HB.GB.GG] Bitmap of CTC_ACL_IPV4_KEY_SUB_FLAG_XXX */
    uint32 sub1_flag;                   /**< [GG] Bitmap of CTC_ACL_IPV4_KEY_SUB1_FLAG_XXX */
    uint32 sub2_flag;                   /**< [GG] Bitmap of CTC_ACL_IPV4_KEY_SUB2_FLAG_XXX */
    uint32 sub3_flag;                   /**< [GG] Bitmap of CTC_ACL_IPV4_KEY_SUB3_FLAG_XXX */
    uint8  key_size;                    /**< [GG] Key Size */

    uint32 ip_sa;                       /**< [HB.GB.GG] IP-SA */
    uint32 ip_sa_mask;                  /**< [HB.GB.GG] IP-SA mask */
    uint32 ip_da;                       /**< [HB.GB.GG] IP-DA */
    uint32 ip_da_mask;                  /**< [HB.GB.GG] IP-DA mask */

    uint16 l4_src_port_0;               /**< [HB.GB.GG] Layer 4 source port.Min/Data */
    uint16 l4_src_port_1;               /**< [HB.GB.GG] Layer 4 source port.Max/Mask */

    uint8  l4_src_port_use_mask;        /**< [HB.GB.GG] Use mask instead of range*/
    uint8  l4_dst_port_use_mask;        /**< [HB.GB.GG] Use mask instead of range*/
    uint8  ip_option;                   /**< [HB.GB.GG] Ip option */
    uint8  routed_packet;               /**< [HB.GB.GG] Routed packet */

    uint16 l4_dst_port_0;               /**< [HB.GB.GG] Layer 4 dest port */
    uint16 l4_dst_port_1;               /**< [HB.GB.GG] Layer 4 dest port */

    uint8  tcp_flags_match_any;         /**< [HB.GB.GG] 0:match all. 1:match any*/
    uint8  tcp_flags;                   /**< [HB.GB.GG] Tcp flag bitmap*/
    uint8  dscp;                        /**< [HB.GB.GG] DSCP */
    uint8  dscp_mask;                   /**< [HB.GB.GG] DSCP mask*/

    uint8  l4_protocol;                 /**< [HB.GB.GG] Layer 4 protocol */
    uint8  l4_protocol_mask;            /**< [HB.GB.GG] Layer 4 protocol mask, for gg if protocol is TCP/UDP/GRE, the mask must be 0xff*/
    uint8  igmp_type;                   /**< [HB.GB.GG] IGMP type */
    uint8  igmp_type_mask;              /**< [HB.GB.GG] IGMP type mask*/

    uint8  icmp_type;                   /**< [HB.GB.GG] ICMP type */
    uint8  icmp_type_mask;              /**< [HB.GB.GG] ICMP type mask*/
    uint8  icmp_code;                   /**< [HB.GB.GG] ICMP code */
    uint8  icmp_code_mask;              /**< [HB.GB.GG] ICMP code mask*/

    uint8  ip_frag;                     /**< [HB.GB.GG] Ip fragment, CTC_ACL_IP_FRAG_XXX */
    uint8  rsv0[3];

    mac_addr_t mac_sa;                  /**< [HB.GB.GG-D] MAC-SA */
    mac_addr_t mac_sa_mask;             /**< [HB.GB.GG-D] MAC-SA mask */
    mac_addr_t mac_da;                  /**< [HB.GB.GG-D] MAC-DA */
    mac_addr_t mac_da_mask;             /**< [HB.GB.GG-D] MAC-DA mask */

    uint16 cvlan;                       /**< [HB.GB.GG-D] C-VLAN */
    uint16 cvlan_mask;                  /**< [HB.GB.GG-D] C-VLAN mask*/
    uint16 svlan;                       /**< [HB.GB.GG-D] S-VLAN */
    uint16 svlan_mask;                  /**< [HB.GB.GG-D] S-VLAN mask*/

    uint8  ctag_cos;                    /**< [HB.GB.GG-D] C-tag CoS */
    uint8  ctag_cos_mask;               /**< [HB.GB.GG-D] C-tag CoS mask*/
    uint8  stag_cos;                    /**< [HB.GB.GG-D] S-tag CoS */
    uint8  stag_cos_mask;               /**< [HB.GB.GG-D] S-tag CoS mask*/

    uint8  ctag_cfi;                    /**< [HB.GB.GG-D] C-tag CFI */
    uint8  stag_cfi;                    /**< [HB.GB.GG-D] S-tag CFI */
    uint8  l2_type;                     /**< [HB.GB.GG] Layer 2 type. Refer to ctc_parser_l2_type_t */
    uint8  l2_type_mask;                /**< [HB.GB.GG] Layer 2 type */

    uint8  cos;                         /**< [HB] Packet_info.src_cos in IPE, packet_info.new_cos in EPE */
    uint8  cos_mask;                    /**< [HB] Cos mask */
    uint8  l3_type;                     /**< [HB.GG] Layer 3 type. Refer to ctc_parser_l3_type_t */
    uint8  l3_type_mask;                /**< [HB.GG] Layer 3 type mask, when care Layer 3 type should set 0xF */

    uint16 eth_type;                    /**< [GB.GG] Ethernet type */
    uint16 eth_type_mask;               /**< [GB.GG] Ethernet type mask*/

    uint16 arp_op_code;                 /**< [GB.GG] Arp op code*/
    uint16 arp_op_code_mask;            /**< [GB.GG] Arp op code mask*/

    uint32 sender_ip;                   /**< [GB.GG] Sender ip */
    uint32 sender_ip_mask;              /**< [GB.GG] Sender ip mask */
    uint32 target_ip;                   /**< [GB.GG] Target ip */
    uint32 target_ip_mask;              /**< [GB.GG] Target ip mask */

    uint8  stag_valid;                  /**< [GB.GG] Stag valid */
    uint8  ctag_valid;                  /**< [GB.GG] Ctag valid */
    uint8  ipv4_packet;                 /**< [GB] Ipv4 packet */
    uint8  arp_packet;                  /**< [GB] Arp packet */

    uint8  ecn;                         /**< [GG] ecn*/
    uint8  ecn_mask;                    /**< [GG] ecn mask*/

    uint16 arp_protocol_type;           /**< [GG] arp protocle type*/
    uint16 arp_protocol_type_mask;      /**< [GG] arp protocle type mask*/

    uint32 mpls_label0;                 /**< [GG] MPLS label 0, include: Label + Exp + S + TTL */
    uint32 mpls_label0_mask;            /**< [GG] MPLS label 0 mask*/
    uint32 mpls_label1;                 /**< [GG] MPLS label 1, include: Label + Exp + S + TTL */
    uint32 mpls_label1_mask;            /**< [GG] MPLS label 1 mask*/
    uint32 mpls_label2;                 /**< [GG] MPLS label 2, include: Label + Exp + S + TTL */
    uint32 mpls_label2_mask;            /**< [GG] MPLS label 2 mask*/

    uint8  mpls_label_num;                    /**< [GG] MPLS label number*/
    uint8  mpls_label_num_mask;               /**< [GG] MPLS label number mask*/

    uint8 ethoam_level;                 /**< [GG] Ethernet oam level*/
    uint8 ethoam_level_mask;            /**< [GG] Ethernet oam level mask*/

    uint8 ethoam_version;               /**< [GG] Ethernet oam version*/
    uint8 ethoam_version_mask;          /**< [GG] Ethernet oam version mask*/

    uint8 ethoam_op_code;               /**< [GG] Ethernet oam op code*/
    uint8 ethoam_op_code_mask;          /**< [GG] Ethernet oam op code mask*/

    uint8 ethoam_is_y1731;              /**< [GG] Ethernet oam is y1731*/
    uint8 ethoam_is_y1731_mask;         /**< [GG] Ethernet oam is y1731 mask*/

    uint8 slowproto_sub_type;       /**< [GG] Slow protocol sub type*/
    uint8 slowproto_sub_type_mask;  /**< [GG] Slow protocol sub type mask*/

    uint16 slowproto_flags;         /**< [GG] Slow protocol flags*/
    uint16 slowproto_flags_mask;    /**< [GG] Slow protocol flags mask*/

    uint8 slowproto_code;           /**< [GG] Slow protocol code*/
    uint8 slowproto_code_mask;      /**< [GG] Slow protocol code mask*/

    uint8 ptp_version;                  /**< [GG] PTP version*/
    uint8 ptp_version_mask;             /**< [GG] PTP version mask*/

    uint8 ptp_msg_type;                 /**< [GG] PTP message type*/
    uint8 ptp_msg_type_mask;            /**< [GG] PTP message type mask*/

    uint32 fcoe_did;                    /**< [GG] FCOE did*/
    uint32 fcoe_did_mask;               /**< [GG] FCOE did mask*/

    uint32 fcoe_sid;                    /**< [GG] FCOE sid*/
    uint32 fcoe_sid_mask;               /**< [GG] FCOE sid mask*/

    uint32 gre_key;                     /**< [GG] GRE key*/
    uint32 gre_key_mask;                /**< [GG] GRE key mask*/

    uint32 metadata;            /**< [GB.GG] Metadata */
    uint32 metadata_mask;       /**< [GB.GG] Metadata mask*/

    uint32 vni;                     /**< [GG] share with l4 src port and dst port*/
    uint32 vni_mask;                /**< [GG] share with l4 src port and dst port mask*/

    uint8 udf[CTC_ACL_UDF_BYTE_NUM];                  /**< [GG-D] udf, bytes in packet combined */
    uint8 udf_mask[CTC_ACL_UDF_BYTE_NUM];       /**< [GG-D] udf mask*/

    uint8 udf_type;      /**< [GG-D] udf type, refer ctc_parser_udf_type_t*/
};
typedef struct ctc_acl_ipv4_key_s  ctc_acl_ipv4_key_t;

enum ctc_acl_mpls_key_flag_e
{
    CTC_ACL_MPLS_KEY_FLAG_MAC_DA        = 1U << 0, /**< [HB.GB.GG] Valid MAC-DA in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_MAC_SA        = 1U << 1, /**< [HB.GB.GG] Valid MAC-SA in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_COS           = 1U << 2, /**< [HB] Valid CoS in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_CVLAN         = 1U << 3, /**< [HB.GB.GG] Valid C-VLAN in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_CTAG_COS      = 1U << 4, /**< [HB.GB.GG] Valid C-tag CoS in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_SVLAN         = 1U << 5, /**< [HB.GB.GG] Valid S-VLAN in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_STAG_COS      = 1U << 6, /**< [HB.GB.GG] Valid S-tag CoS in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_L2_TYPE       = 1U << 7, /**< [HB] Valid l2-type in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_MPLS_LABEL0   = 1U << 8, /**< [HB.GB.GG] Valid MPLS label 0 in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_MPLS_LABEL1   = 1U << 9, /**< [HB.GB.GG] Valid MPLS label 1 in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_MPLS_LABEL2   = 1U << 10,/**< [HB.GB.GG] Valid MPLS label 2 in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_MPLS_LABEL3   = 1U << 11,/**< [HB.GB] Valid MPLS label 3 in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_ROUTED_PACKET = 1U << 12,/**< [HB.GB.GG] Valid Routed-packet in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_CTAG_CFI      = 1U << 13,/**< [HB.GB.GG] Valid C-tag CoS in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_STAG_CFI      = 1U << 14,/**< [HB.GB.GG] Valid S-tag CoS in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_METADATA      = 1U << 15, /**< [GG] Valid metadata in MPLS key */
    CTC_ACL_MPLS_KEY_FLAG_MPLS_LABEL_NUM = 1U << 16  /**< [GG] MPLS label number field*/
};
typedef enum ctc_acl_mpls_key_flag_e ctc_acl_mpls_key_flag_t;


struct ctc_acl_mpls_key_s
{
    uint32 flag;                /**< [HB.GB.GG] Bitmap of CTC_ACL_MPLS_KEY_FLAG_XXX */

    mac_addr_t mac_da;          /**< [HB.GB.GG] MAC-DA */
    mac_addr_t mac_da_mask;     /**< [HB.GB.GG] MAC-DA mask */
    mac_addr_t mac_sa;          /**< [HB.GB.GG] MAC-SA */
    mac_addr_t mac_sa_mask;     /**< [HB.GB.GG] MAC-SA mask */

    uint16 cvlan;               /**< [HB.GB.GG] C-VLAN tag */
    uint16 cvlan_mask;          /**< [HB.GB.GG] C-VLAN mask*/
    uint16 svlan;               /**< [HB.GB.GG] S-VLAN tag */
    uint16 svlan_mask;          /**< [HB.GB.GG] S-VLAN mask*/

    uint8  ctag_cos;            /**< [HB.GB.GG] C-tag CoS */
    uint8  ctag_cos_mask;       /**< [HB.GB.GG] C-tag CoS mask */
    uint8  stag_cos;            /**< [HB.GB.GG] S-tag Cos */
    uint8  stag_cos_mask;       /**< [HB.GB.GG] S-tag Cos mask */

    uint8  ctag_cfi;            /**< [HB.GB.GG] C-tag Cfi */
    uint8  stag_cfi;            /**< [HB.GB.GG] S-tag Cfi */
    uint8  routed_packet;       /**< [HB.GB.GG] Routed packet */
    uint8  rsv0;

    uint8  cos;                 /**< [HB] Packet_info.src_cos in IPE, packet_info.new_cos in EPE */
    uint8  cos_mask;            /**< [HB] Cos mask */
    uint8  l2_type;             /**< [HB] Layer 2 type. Refer to ctc_parser_l2_type_t */
    uint8  l2_type_mask;        /**< [HB] Layer 2 type mask*/

    uint32 mpls_label0;         /**< [HB.GB.GG] MPLS label 0, include: Label + Exp + S + TTL */
    uint32 mpls_label0_mask;    /**< [HB.GB.GG] MPLS label 0 mask*/
    uint32 mpls_label1;         /**< [HB.GB.GG] MPLS label 1, include: Label + Exp + S + TTL */
    uint32 mpls_label1_mask;    /**< [HB.GB.GG] MPLS label 1 mask*/
    uint32 mpls_label2;         /**< [HB.GB.GG] MPLS label 2, include: Label + Exp + S + TTL */
    uint32 mpls_label2_mask;    /**< [HB.GB.GG] MPLS label 2 mask*/
    uint32 mpls_label3;         /**< [HB.GB] MPLS label 3, include: Label + Exp + S + TTL */
    uint32 mpls_label3_mask;    /**< [HB.GB] MPLS label 3 mask*/

    uint8  mpls_label_num;       /**< [GG] MPLS label number*/
    uint8  mpls_label_num_mask;  /**< [GG] MPLS label number mask*/

    uint32 metadata;            /**< [GG] Metadata */
    uint32 metadata_mask;       /**< [GG] Metadata mask*/

};
typedef struct ctc_acl_mpls_key_s  ctc_acl_mpls_key_t;

enum ctc_acl_ipv6_key_flag_e
{
    CTC_ACL_IPV6_KEY_FLAG_MAC_DA        = 1U << 0,  /**< [HB.GB.GG] Valid MAC-DA in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_MAC_SA        = 1U << 1,  /**< [HB.GB.GG] Valid MAC-SA in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_COS           = 1U << 2,  /**< [HB] Valid CoS in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_CVLAN         = 1U << 3,  /**< [HB.GB.GG] Valid CVLAN in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_CTAG_COS      = 1U << 4,  /**< [HB.GB.GG] Valid Ctag CoS in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_SVLAN         = 1U << 5,  /**< [HB.GB.GG] Valid SVLAN in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_STAG_COS      = 1U << 6,  /**< [HB.GB.GG] Valid Stag CoS in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_ETH_TYPE      = 1U << 7,  /**< [HB.GB.GG] Valid Ether-type in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_L2_TYPE       = 1U << 8,  /**< [HB.GB.GG] Valid L2-type CoS in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_L3_TYPE       = 1U << 9,  /**< [HB.GB.GG] Valid L3-type in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_IP_SA         = 1U << 10, /**< [HB.GB.GG] Valid IPv6-SA in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_IP_DA         = 1U << 11, /**< [HB.GB.GG] Valid IPv6-DA in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_L4_PROTOCOL   = 1U << 12, /**< [HB.GB.GG] Valid L4-Protocol in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_DSCP          = 1U << 13, /**< [HB.GB.GG] Valid DSCP in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_PRECEDENCE    = 1U << 14, /**< [HB.GB.GG] Valid IP Precedence in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_IP_FRAG       = 1U << 15, /**< [HB.GB.GG] Valid fragment in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_IP_OPTION     = 1U << 16, /**< [HB.GB.GG] Valid IP option in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_ROUTED_PACKET = 1U << 17, /**< [HB.GB.GG] Valid Routed-packet in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_EXT_HDR       = 1U << 18, /**< [HB] Valid IPv6 extension header in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_FLOW_LABEL    = 1U << 19, /**< [HB.GB.GG] Valid IPv6 flow label in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_CTAG_CFI      = 1U << 20, /**< [HB.GB.GG] Valid C-tag Cfi in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_STAG_CFI      = 1U << 21, /**< [HB.GB.GG] Valid S-tag Cfi in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_STAG_VALID    = 1U << 22, /**< [GB.GG] Valid Stag-valid in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_CTAG_VALID    = 1U << 23, /**< [GB.GG] Valid Ctag-valid in IPv6 key */
    CTC_ACL_IPV6_KEY_FLAG_ECN           = 1U << 24, /**< [GG] */
    CTC_ACL_IPV6_KEY_FLAG_METADATA      = 1U << 25,  /**< [GG] Valid metadata in ipv6 key */
    CTC_ACL_IPV6_KEY_FLAG_UDF      = 1U << 26  /**< [GG] Valid udf in ipv6 key */
};
typedef enum ctc_acl_ipv6_key_flag_e ctc_acl_ipv6_key_flag_t;


enum ctc_acl_ipv6_key_sub_flag_e
{
    CTC_ACL_IPV6_KEY_SUB_FLAG_L4_SRC_PORT  = 1U << 0, /**< [HB.GB.GG] Depend on L4_PROTOCOL = TCP|UDP Valid L4 source port in IPv6 key */
    CTC_ACL_IPV6_KEY_SUB_FLAG_L4_DST_PORT  = 1U << 1, /**< [HB.GB.GG] Depend on L4_PROTOCOL = TCP|UDP Valid L4 destination port in IPv6 key */
    CTC_ACL_IPV6_KEY_SUB_FLAG_TCP_FLAGS    = 1U << 2, /**< [HB.GB.GG] Depend on L4_PROTOCOL = TCP.    Valid TCP flags in IPv6 key */
    CTC_ACL_IPV6_KEY_SUB_FLAG_ICMP_TYPE    = 1U << 3, /**< [HB.GB.GG] Depend on L4_PROTOCOL = ICMP.   Valid ICMP type in IPv6 key */
    CTC_ACL_IPV6_KEY_SUB_FLAG_ICMP_CODE    = 1U << 4, /**< [HB.GB.GG] Depend on L4_PROTOCOL = ICMP.   Valid ICMP code in IPv6 key */
    CTC_ACL_IPV6_KEY_SUB_FLAG_GRE_KEY      = 1U << 5, /**< [GG] Depend on L4_PROTOCOL = GRE.    Valid GRE key in IPv6 key */
    CTC_ACL_IPV6_KEY_SUB_FLAG_VNI          = 1U << 6, /**< [GG] Depend on L4_PROTOCOL = UDP.    Valid vni in IPv6 key */
    CTC_ACL_IPV6_KEY_SUB_FLAG_NVGRE_KEY    = 1U << 7  /**< [GG] Depend on L4_PROTOCOL = NVGRE.    Valid NVGRE key in IPv6 key */
};
typedef enum ctc_acl_ipv6_key_sub_flag_e ctc_acl_ipv6_key_sub_flag_t;


struct ctc_acl_ipv6_key_s
{
    uint32 flag;                 /**< [HB.GB.GG] Bitmap of CTC_ACL_IPV6_KEY_FLAG_XXX */
    uint32 sub_flag;             /**< [HB.GB.GG] Bitmap of CTC_ACL_IPV6_KEY_SUB_FLAG_XXX */

    ipv6_addr_t ip_sa;           /**< [HB.GB.GG] IPv6-SA */
    ipv6_addr_t ip_sa_mask;      /**< [HB.GB.GG] IPv6-SA mask */
    ipv6_addr_t ip_da;           /**< [HB.GB.GG] IPv6-DA */
    ipv6_addr_t ip_da_mask;      /**< [HB.GB.GG] IPv6-DA mask */

    uint16 l4_src_port_0;        /**< [HB.GB.GG] Layer 4 source port.Min/Data */
    uint16 l4_src_port_1;        /**< [HB.GB.GG] Layer 4 source port.Max/Mask */

    uint8  l4_src_port_use_mask; /**< [HB.GB.GG] Use mask instead of range*/
    uint8  ip_option;            /**< [HB.GB.GG] IP option */
    uint8  routed_packet;        /**< [HB.GB.GG] Routed packet */
    uint8  l4_dst_port_use_mask; /**< [HB.GB.GG] Use mask instead of range. dest_port is collision with l2_type and eth_type on GB.*/

    uint16 l4_dst_port_0;        /**< [HB.GB.GG] Layer 4 dest port */
    uint16 l4_dst_port_1;        /**< [HB.GB.GG] Layer 4 dest port */

    uint8  ip_frag;              /**< [HB.GB.GG] Ip fragment, CTC_ACL_IP_FRAG_XXX */
    uint8  tcp_flags_match_any;  /**< [HB.GB.GG] 0:match all. 1:match any*/
    uint8  tcp_flags;            /**< [HB.GB.GG] Tcp flag bitmap*/
    uint8  rsv0;

    uint32 flow_label;           /**< [HB.GB.GG] Flow label */
    uint32 flow_label_mask;      /**< [HB.GB.GG] Flow label */

    uint8  l4_protocol;          /**< [HB.GB.GG] Layer 4 protocol */
    uint8  l4_protocol_mask;     /**< [HB.GB.GG] Layer 4 protocol mask*/
    uint8  icmp_type;            /**< [HB.GB.GG] ICMP type */
    uint8  icmp_type_mask;       /**< [HB.GB.GG] ICMP type mask*/

    uint8  icmp_code;            /**< [HB.GB.GG] ICMP code */
    uint8  icmp_code_mask;       /**< [HB.GB.GG] ICMP code mask*/
    uint8  dscp;                 /**< [HB.GB.GG] DSCP */
    uint8  dscp_mask;            /**< [HB.GB.GG] DSCP mask */

    mac_addr_t mac_sa;           /**< [HB.GB.GG] MAC-SA */
    mac_addr_t mac_sa_mask;      /**< [HB.GB.GG] MAC-SA mask */
    mac_addr_t mac_da;           /**< [HB.GB.GG] MAC-DA */
    mac_addr_t mac_da_mask;      /**< [HB.GB.GG] MAC-DA mask */

    uint16 eth_type;             /**< [HB.GB] Ethernet type */
    uint16 eth_type_mask;        /**< [HB.GB] Ethernet type mask */

    uint16 cvlan;                /**< [HB.GB.GG] C-VLAN */
    uint16 cvlan_mask;           /**< [HB.GB.GG] C-VLAN mask*/

    uint16 svlan;                /**< [HB.GB.GG] S-VLAN */
    uint16 svlan_mask;           /**< [HB.GB.GG] S-VLAN mask*/

    uint8  ctag_cos;             /**< [HB.GB.GG] C-tag CoS */
    uint8  ctag_cos_mask;        /**< [HB.GB.GG] C-tag CoS mask */
    uint8  stag_cos;             /**< [HB.GB.GG] S-tag CoS */
    uint8  stag_cos_mask;        /**< [HB.GB.GG] S-tag Cos mask */

    uint8  ctag_cfi;             /**< [HB.GB.GG] C-tag CFI */
    uint8  stag_cfi;             /**< [HB.GB.GG] S-tag CFI */
    uint8  l2_type;              /**< [HB.GB] Layer 2 type. Refer to ctc_parser_l2_type_t */
    uint8  l2_type_mask;         /**< [HB.GB] Layer 2 type mask*/

    uint8  cos;                  /**< [HB] Packet_info.src_cos in IPE, packet_info.new_cos in EPE */
    uint8  cos_mask;             /**< [HB] Cos mask */
    uint8  ext_hdr;              /**< [HB] Extension header ,Bitmap of ctc_parser_ipv6_extend_header_type_t*/
    uint8  ext_hdr_mask;         /**< [HB] Extension header mask*/

    uint8  stag_valid;           /**< [GB.GG] Stag valid*/
    uint8  ctag_valid;           /**< [GB.GG] Ctag valid*/
    uint8  l3_type;              /**< [HB.GB.GG] Layer 3 type. Refer to ctc_parser_l3_type_t */
    uint8  l3_type_mask;         /**< [HB.GB.GG] Layer 3 type mask*/

    uint8  ecn;                  /**< [GG] ecn*/
    uint8  ecn_mask;             /**< [GG] ecn mask*/

    uint32 gre_key;              /**< [GG] share with l4 src port and dst port*/
    uint32 gre_key_mask;         /**< [GG] share with l4 src port and dst port mask*/

    uint32 metadata;            /**< [GG] metadata */
    uint32 metadata_mask;       /**< [GG] metadata mask*/

    uint32 vni;                     /**< [GG] share with l4 src port and dst port*/
    uint32 vni_mask;                /**< [GG] share with l4 src port and dst port mask*/

    uint8 udf[CTC_ACL_UDF_BYTE_NUM];                  /**< [GG] udf, bytes in packet combined */
    uint8 udf_mask[CTC_ACL_UDF_BYTE_NUM];       /**< [GG] udf mask*/

    uint8 udf_type;      /**< [GG] udf type, refer ctc_parser_udf_type_t*/

};
typedef struct ctc_acl_ipv6_key_s ctc_acl_ipv6_key_t;

enum ctc_acl_pbr_ipv4_key_flag_e
{
    CTC_ACL_PBR_IPV4_KEY_FLAG_IP_SA         = 1U << 0, /**< [HB.GB.GG] Valid IP-SA in IPv4 key */
    CTC_ACL_PBR_IPV4_KEY_FLAG_IP_DA         = 1U << 1, /**< [HB.GB.GG] Valid IP-DA in IPv4 key */
    CTC_ACL_PBR_IPV4_KEY_FLAG_L4_PROTOCOL   = 1U << 2, /**< [HB.GB.GG] Valid L4-Proto in IPv4 key */
    CTC_ACL_PBR_IPV4_KEY_FLAG_DSCP          = 1U << 3, /**< [HB.GB.GG] Valid DSCP in IPv4 key */
    CTC_ACL_PBR_IPV4_KEY_FLAG_PRECEDENCE    = 1U << 4, /**< [HB.GB.GG] Valid IP Precedence in IPv4 key */
    CTC_ACL_PBR_IPV4_KEY_FLAG_IP_FRAG       = 1U << 5, /**< [HB.GB.GG] Valid fragment in IPv4 key */
    CTC_ACL_PBR_IPV4_KEY_FLAG_VRFID         = 1U << 6  /**< [HB.GB.GG] Valid vrfid in IPv4 key */
};
typedef enum ctc_acl_pbr_ipv4_key_flag_e ctc_acl_pbr_ipv4_key_flag_t;


enum ctc_acl_pbr_ipv4_key_sub_flag_e
{
    CTC_ACL_PBR_IPV4_KEY_SUB_FLAG_L4_SRC_PORT     = 1U << 0, /**< [HB.GB.GG] Depend on L4_PROTOCOL = TCP|UDP. Valid L4 source port in IPv4 key */
    CTC_ACL_PBR_IPV4_KEY_SUB_FLAG_L4_DST_PORT     = 1U << 1, /**< [HB.GB.GG] Depend on L4_PROTOCOL = TCP|UDP. Valid L4 destination port in IPv4 key */
    CTC_ACL_PBR_IPV4_KEY_SUB_FLAG_TCP_FLAGS       = 1U << 2, /**< [HB.GB.GG] Depend on L4_PROTOCOL = TCP. Valid TCP flag in IPv4 key */
    CTC_ACL_PBR_IPV4_KEY_SUB_FLAG_ICMP_TYPE       = 1U << 3, /**< [HB.GB.GG] Depend on L4_PROTOCOL = ICMP. Valid ICMP type in IPv4 key */
    CTC_ACL_PBR_IPV4_KEY_SUB_FLAG_ICMP_CODE       = 1U << 4  /**< [HB.GB.GG] Depend on L4_PROTOCOL = ICMP. Valid ICMP code in IPv4 key */
};
typedef enum ctc_acl_pbr_ipv4_key_sub_flag_e ctc_acl_pbr_ipv4_key_sub_flag_t;


struct ctc_acl_pbr_ipv4_key_s
{
    uint32 flag;                        /**< [HB.GB.GG] Bitmap of CTC_ACL_PBR_IPV4_KEY_FLAG_XXX */
    uint32 sub_flag;                    /**< [HB.GB.GG] Bitmap of CTC_ACL_PBR_IPV4_KEY_SUB_FLAG_XXX */

    uint32 ip_sa;                       /**< [HB.GB.GG] IP-SA */
    uint32 ip_sa_mask;                  /**< [HB.GB.GG] IP-SA mask */
    uint32 ip_da;                       /**< [HB.GB.GG] IP-DA */
    uint32 ip_da_mask;                  /**< [HB.GB.GG] IP-DA mask */

    uint16 l4_src_port_0;               /**< [HB.GB.GG] Layer 4 source port.Min/Data */
    uint16 l4_src_port_1;               /**< [HB.GB.GG] Layer 4 source port.Max/Mask */

    uint8  l4_src_port_use_mask;        /**< [HB.GB.GG] Use mask instead of range*/
    uint8  l4_dst_port_use_mask;        /**< [HB.GB.GG] Use mask instead of range*/
    uint8  ip_frag;                     /**< [HB.GB.GG] Ip fragment, CTC_ACL_IP_FRAG_XXX */
    uint8  rsv1;

    uint16 l4_dst_port_0;               /**< [HB.GB.GG] Layer 4 dest port */
    uint16 l4_dst_port_1;               /**< [HB.GB.GG] Layer 4 dest port */

    uint8  tcp_flags_match_any;         /**< [HB.GB.GG] 0:match all. 1:match any*/
    uint8  tcp_flags;                   /**< [HB.GB.GG] Tcp flag bitmap*/
    uint8  dscp;                        /**< [HB.GB.GG] DSCP */
    uint8  dscp_mask;                   /**< [HB.GB.GG] DSCP mask*/

    uint8  l4_protocol;                 /**< [HB.GB.GG] Layer 4 protocol */
    uint8  l4_protocol_mask;            /**< [HB.GB.GG] Layer 4 protocol mask*/
    uint8  rsv2[2];

    uint8  icmp_type;                   /**< [HB.GB.GG] ICMP type */
    uint8  icmp_type_mask;              /**< [HB.GB.GG] ICMP type mask*/
    uint8  icmp_code;                   /**< [HB.GB.GG] ICMP code */
    uint8  icmp_code_mask;              /**< [HB.GB.GG] ICMP code mask*/

    uint16 vrfid;                      /**< [HB.GB.GG] VRFID */
    uint16 vrfid_mask;                 /**< [HB.GB.GG] VRFID mask*/

};
typedef struct ctc_acl_pbr_ipv4_key_s  ctc_acl_pbr_ipv4_key_t;

enum ctc_acl_pbr_ipv6_key_flag_e
{
    CTC_ACL_PBR_IPV6_KEY_FLAG_MAC_DA        = 1U << 0,  /**< [HB.GB] Valid MAC-DA in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_MAC_SA        = 1U << 1,  /**< [HB.GB] Valid MAC-SA in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_CVLAN         = 1U << 2,  /**< [HB.GB] Valid CVLAN in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_CTAG_COS      = 1U << 3,  /**< [HB.GB] Valid Ctag CoS in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_SVLAN         = 1U << 4,  /**< [HB.GB] Valid SVLAN in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_STAG_COS      = 1U << 5,  /**< [HB.GB] Valid Stag CoS in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_ETH_TYPE      = 1U << 6,  /**< [HB.GB] Valid Ether-type in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_L2_TYPE       = 1U << 7,  /**< [HB.GB] Valid L2-type CoS in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_L3_TYPE       = 1U << 8,  /**< [HB.GB] Valid L3-type in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_IP_SA         = 1U << 9,  /**< [HB.GB.GG] Valid IPv6-SA in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_IP_DA         = 1U << 10, /**< [HB.GB.GG] Valid IPv6-DA in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_L4_PROTOCOL   = 1U << 11, /**< [HB.GB.GG] Valid L4-Protocol in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_DSCP          = 1U << 12, /**< [HB.GB.GG] Valid DSCP in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_PRECEDENCE    = 1U << 13, /**< [HB.GB.GG] Valid IP Precedence in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_IP_FRAG       = 1U << 14, /**< [HB.GB.GG] Valid fragment in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_FLOW_LABEL    = 1U << 15, /**< [HB.GB.GG] Valid IPv6 flow label in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_CTAG_CFI      = 1U << 16, /**< [HB.GB] Valid C-tag Cfi in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_STAG_CFI      = 1U << 17, /**< [HB.GB] Valid S-tag Cfi in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_VRFID         = 1U << 18, /**< [HB.GB.GG] Valid vrfid in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_EXT_HDR       = 1U << 19, /**< [HB] Valid IPv6 extension header in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_FLAG_COS           = 1U << 20  /**< [HB] Valid CoS in IPv6 key */
};
typedef enum ctc_acl_pbr_ipv6_key_flag_e ctc_acl_pbr_ipv6_key_flag_t;


enum ctc_acl_pbr_ipv6_key_sub_flag_e
{
    CTC_ACL_PBR_IPV6_KEY_SUB_FLAG_L4_SRC_PORT   = 1U << 0,  /**< [HB.GB.GG] Depend on L4_PROTOCOL = TCP|UDP Valid L4 source port in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_SUB_FLAG_L4_DST_PORT   = 1U << 1,  /**< [HB.GB.GG] Depend on L4_PROTOCOL = TCP|UDP Valid L4 destination port in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_SUB_FLAG_TCP_FLAGS     = 1U << 2,  /**< [HB.GB.GG] Depend on L4_PROTOCOL = TCP.    Valid TCP flags in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_SUB_FLAG_ICMP_TYPE     = 1U << 3,  /**< [HB.GB.GG] Depend on L4_PROTOCOL = ICMP.   Valid ICMP type in IPv6 key */
    CTC_ACL_PBR_IPV6_KEY_SUB_FLAG_ICMP_CODE     = 1U << 4   /**< [HB.GB.GG] Depend on L4_PROTOCOL = ICMP.   Valid ICMP code in IPv6 key */
};
typedef enum ctc_acl_pbr_ipv6_key_sub_flag_e ctc_acl_pbr_ipv6_key_sub_flag_t;


struct ctc_acl_pbr_ipv6_key_s
{
    uint32 flag;                        /**< [HB.GB.GG] Bitmap of CTC_ACL_IPV6_KEY_FLAG_XXX */
    uint32 sub_flag;                    /**< [HB.GB.GG] Bitmap of CTC_ACL_IPV6_KEY_SUB_FLAG_XXX */

    ipv6_addr_t ip_sa;                  /**< [HB.GB.GG] IPv6-SA */
    ipv6_addr_t ip_sa_mask;             /**< [HB.GB.GG] IPv6-SA mask */
    ipv6_addr_t ip_da;                  /**< [HB.GB.GG] IPv6-DA */
    ipv6_addr_t ip_da_mask;             /**< [HB.GB.GG] IPv6-DA mask */

    uint16 l4_src_port_0;               /**< [HB.GB.GG] Layer 4 source port.Min/Data */
    uint16 l4_src_port_1;               /**< [HB.GB.GG] Layer 4 source port.Max/Mask */

    uint8  l4_src_port_use_mask;        /**< [HB.GB.GG] Use mask instead of range*/
    uint8  l4_dst_port_use_mask;        /**< [HB.GB.GG] Use mask instead of range. dest_port is collision with l2_type and eth_type on GB.*/
    uint8  l3_type;                     /**< [HB.GB] Layer 3 type. Refer to ctc_parser_l3_type_t */
    uint8  l3_type_mask;                /**< [HB.GB] Layer 3 type mask*/

    uint16 l4_dst_port_0;               /**< [HB.GB.GG] Layer 4 dest port */
    uint16 l4_dst_port_1;               /**< [HB.GB.GG] Layer 4 dest port */

    uint8  ip_frag;                     /**< [HB.GB.GG] Ip fragment, CTC_ACL_IP_FRAG_XXX */
    uint8  tcp_flags_match_any;         /**< [HB.GB.GG] 0:match all. 1:match any*/
    uint8  tcp_flags;                   /**< [HB.GB.GG] Tcp flag bitmap*/
    uint8  rsv0;

    uint32 flow_label;                  /**< [HB.GB.GG] Flow label */
    uint32 flow_label_mask;             /**< [HB.GB.GG] Flow label */

    uint8  l4_protocol;                 /**< [HB.GB.GG] Layer 4 protocol */
    uint8  l4_protocol_mask;            /**< [HB.GB.GG] Layer 4 protocol mask*/
    uint8  icmp_type;                   /**< [HB.GB.GG] ICMP type */
    uint8  icmp_type_mask;              /**< [HB.GB.GG] ICMP type mask*/

    uint8  icmp_code;                   /**< [HB.GB.GG] ICMP code */
    uint8  icmp_code_mask;              /**< [HB.GB.GG] ICMP code mask*/
    uint8  dscp;                        /**< [HB.GB.GG] DSCP */
    uint8  dscp_mask;                   /**< [HB.GB.GG] DSCP mask */

    mac_addr_t mac_sa;                  /**< [HB.GB] MAC-SA */
    mac_addr_t mac_sa_mask;             /**< [HB.GB] MAC-SA mask */
    mac_addr_t mac_da;                  /**< [HB.GB] MAC-DA */
    mac_addr_t mac_da_mask;             /**< [HB.GB] MAC-DA mask */

    uint16 eth_type;                    /**< [HB.GB] Ethernet type */
    uint16 eth_type_mask;               /**< [HB.GB] Ethernet type mask */

    uint16 cvlan;                       /**< [HB.GB] C-VLAN */
    uint16 cvlan_mask;                  /**< [HB.GB] C-VLAN mask*/

    uint16 svlan;                       /**< [HB.GB] S-VLAN */
    uint16 svlan_mask;                  /**< [HB.GB] S-VLAN mask*/

    uint8  ctag_cos;                    /**< [HB.GB] C-tag CoS */
    uint8  ctag_cos_mask;               /**< [HB.GB] C-tag CoS mask */
    uint8  stag_cos;                    /**< [HB.GB] S-tag CoS */
    uint8  stag_cos_mask;               /**< [HB.GB] S-tag Cos mask */

    uint8  ctag_cfi;                    /**< [HB.GB] C-tag CFI */
    uint8  stag_cfi;                    /**< [HB.GB] S-tag CFI */
    uint8  l2_type;                     /**< [HB.GB] Layer 2 type. Refer to ctc_parser_l2_type_t */
    uint8  l2_type_mask;                /**< [HB.GB] Layer 2 type mask*/

    uint8  cos;                         /**< [HB] Packet_info.src_cos in IPE, packet_info.new_cos in EPE */
    uint8  cos_mask;                    /**< [HB] Cos mask */
    uint8  ext_hdr;                     /**< [HB] Extension header ,Bitmap of ctc_parser_ipv6_extend_header_type_t*/
    uint8  ext_hdr_mask;                /**< [HB] Extension header mask*/

    uint16 vrfid;                      /**< [HB.GB.GG] VRFID */
    uint16 vrfid_mask;                 /**< [HB.GB.GG] VRFID mask*/
};
typedef struct ctc_acl_pbr_ipv6_key_s ctc_acl_pbr_ipv6_key_t;

struct ctc_acl_key_s
{
    ctc_acl_key_type_t type;                 /**< [HB.GB] CTC_ACL_XXX_KEY */

    union
    {
        ctc_acl_mac_key_t  mac_key;          /**< [HB.GB.GG] ACL MAC key content */
        ctc_acl_mpls_key_t mpls_key;         /**< [HB.GB] ACL MPLS key content */
        ctc_acl_ipv4_key_t ipv4_key;         /**< [HB.GB.GG] ACL IPv4 key content */
        ctc_acl_ipv6_key_t ipv6_key;         /**< [HB.GB.GG] ACL IPv6 key content */
        ctc_acl_hash_mac_key_t  hash_mac_key;         /**< [GB.GG] ACL MAC Hash key content */
        ctc_acl_hash_ipv4_key_t hash_ipv4_key;        /**< [GB.GG] ACL IPv4 Hash key content */
        ctc_acl_hash_ipv6_key_t hash_ipv6_key;        /**< [GG] ACL IPv6 Hash key content */
        ctc_acl_hash_mpls_key_t hash_mpls_key;        /**< [GG] ACL MPLS Hash key content */
        ctc_acl_hash_l2_l3_key_t hash_l2_l3_key;      /**< [GG] ACL L2 L3 key content */
        ctc_acl_pbr_ipv4_key_t pbr_ipv4_key;          /**< [HB.GB.GG] ACL PBR IPv4 key content */
        ctc_acl_pbr_ipv6_key_t pbr_ipv6_key;          /**< [HB.GB.GG] ACL PBR IPv6 key content */
    } u;
};
typedef struct ctc_acl_key_s ctc_acl_key_t;

enum ctc_acl_action_flag_e
{
    CTC_ACL_ACTION_FLAG_DISCARD                        = 1U << 0,  /**< [HB.GB(b).GG(b)] Discard the packet i:ingress e:egress*/
    CTC_ACL_ACTION_FLAG_DENY_BRIDGE                    = 1U << 1,  /**< [HB.GB(i).GG(i)] Deny bridging process */
    CTC_ACL_ACTION_FLAG_DENY_LEARNING                  = 1U << 2,  /**< [HB.GB(i).GG(i)] Deny learning process */
    CTC_ACL_ACTION_FLAG_DENY_ROUTE                     = 1U << 3,  /**< [HB.GB(i).GG(i)] Deny routing process */
    CTC_ACL_ACTION_FLAG_STATS                          = 1U << 6,  /**< [HB.GB(b).GG(b)] Statistic */
    CTC_ACL_ACTION_FLAG_PRIORITY_AND_COLOR             = 1U << 8,  /**< [HB.GB(i).GG(i)] Priority color */
    CTC_ACL_ACTION_FLAG_TRUST                          = 1U << 9,  /**< [HB.GB(i).GG(i)] QoS trust state */
    CTC_ACL_ACTION_FLAG_MICRO_FLOW_POLICER             = 1U << 10, /**< [HB.GB(b).GG(b)] Micro Flow policer */
    CTC_ACL_ACTION_FLAG_RANDOM_LOG                     = 1U << 11, /**< [HB.GB(b).GG(b)] Log to any network port */
    CTC_ACL_ACTION_FLAG_COPY_TO_CPU                    = 1U << 12, /**< [HB.GB(i).GG(b)] Copy to cpu */
    CTC_ACL_ACTION_FLAG_REDIRECT                       = 1U << 13, /**< [HB.GB(i).GG(i)] Redirect */
    CTC_ACL_ACTION_FLAG_DSCP                           = 1U << 14, /**< [GB(i).GG(i)] Dscp */
    CTC_ACL_ACTION_FLAG_COPY_TO_CPU_WITH_TIMESTAMP     = 1U << 15, /**< [GB(i).] Copy to cpu with timestamp */
    CTC_ACL_ACTION_FLAG_QOS_DOMAIN                     = 1U << 16, /**< [GB(i).GG(i)] Qos domain */
    CTC_ACL_ACTION_FLAG_MACRO_FLOW_POLICER             = 1U << 17, /**< [GB(b).GG(b)] Macro Flow Policer */
    CTC_ACL_ACTION_FLAG_AGING                          = 1U << 18, /**< [GB(i)] Aging */
    CTC_ACL_ACTION_FLAG_VLAN_EDIT                      = 1U << 19, /**< [GB(i).GG(i)] Vlan edit */
    CTC_ACL_ACTION_FLAG_PRIORITY                       = 1U << 26, /**< [GG(i)] Priority*/
    CTC_ACL_ACTION_FLAG_COLOR                          = 1U << 27, /**< [GG(i)] Color id */
    CTC_ACL_ACTION_FLAG_DISABLE_IPFIX                  = 1U << 28, /**< [GG(b)] Disable ipfix*/
    CTC_ACL_ACTION_FLAG_DENY_IPFIX_LEARNING            = 1U << 29, /**< [GG(b)] Deny ipfix learning*/
    CTC_ACL_ACTION_FLAG_POSTCARD_EN                    = 1U << 30, /**< [GG(i)] Enable postcard*/
    CTC_ACL_ACTION_FLAG_CANCEL_DISCARD                 = 1U << 31, /**< [GG(i)] Cancel discard the packet */
    CTC_ACL_ACTION_FLAG_ASSIGN_OUTPUT_PORT             = 1LLU << 32, /**<[GG(i)] DestId assigned by user */
    CTC_ACL_ACTION_FLAG_FORCE_ROUTE                    = 1LLU << 33,  /**< [GG(i)] Force routing process,will cancel deny route,deny bridge */
    CTC_ACL_ACTION_FLAG_METADATA                       = 1LLU << 34, /**< [GG(i)] Metadata */
    CTC_ACL_ACTION_FLAG_FID                            = 1LLU << 35, /**< [GG(i)] fid */
    CTC_ACL_ACTION_FLAG_VRFID                          = 1LLU << 36,  /**< [GG(i)] Vrf ID of the route */

    /* following is pbr action flag */
    CTC_ACL_ACTION_FLAG_PBR_TTL_CHECK                  = 1U << 20, /**< [HB.GB.GG] Set PBR ttl-check flag */
    CTC_ACL_ACTION_FLAG_PBR_ICMP_CHECK           = 1U << 21, /**< [HB.GB.GG] Set PBR icmp-check flag */
    CTC_ACL_ACTION_FLAG_PBR_CPU                        = 1U << 22, /**< [HB.GB.GG] Set PBR copy-to-cpu flag */
    CTC_ACL_ACTION_FLAG_PBR_ECMP                       = 1U << 23, /**< [HB.GB] Set PBR ecmp flag which means use ecmp nexthop directly */
    CTC_ACL_ACTION_FLAG_PBR_FWD                        = 1U << 24, /**< [HB.GB.GG] Set PBR fwd flag */
    CTC_ACL_ACTION_FLAG_PBR_DENY                       = 1U << 25  /**< [HB.GB.GG] Set PBR deny flag */
};
typedef enum ctc_acl_action_flag_e ctc_acl_action_flag_t;

enum ctc_log_percent_e
{
    CTC_LOG_PERCENT_POWER_NEGATIVE_15,     /**< [HB.GB] 2 (-15) */
    CTC_LOG_PERCENT_POWER_NEGATIVE_14,     /**< [HB.GB.GG] 2 (-14) */
    CTC_LOG_PERCENT_POWER_NEGATIVE_13,     /**< [HB.GB.GG] 2 (-13) */
    CTC_LOG_PERCENT_POWER_NEGATIVE_12,     /**< [HB.GB.GG] 2 (-12) */
    CTC_LOG_PERCENT_POWER_NEGATIVE_11,     /**< [HB.GB.GG] 2 (-11) */
    CTC_LOG_PERCENT_POWER_NEGATIVE_10,     /**< [HB.GB.GG] 2 (-10) */
    CTC_LOG_PERCENT_POWER_NEGATIVE_9,      /**< [HB.GB.GG] 2 (-9)  */
    CTC_LOG_PERCENT_POWER_NEGATIVE_8,      /**< [HB.GB.GG] 2 (-8)  */
    CTC_LOG_PERCENT_POWER_NEGATIVE_7,      /**< [HB.GB.GG] 2 (-7)  */
    CTC_LOG_PERCENT_POWER_NEGATIVE_6,      /**< [HB.GB.GG] 2 (-6)  */
    CTC_LOG_PERCENT_POWER_NEGATIVE_5,      /**< [HB.GB.GG] 2 (-5) : */
    CTC_LOG_PERCENT_POWER_NEGATIVE_4,      /**< [HB.GB.GG] 2 (-4) : 1/16*/
    CTC_LOG_PERCENT_POWER_NEGATIVE_3,      /**< [HB.GB.GG] 2 (-3) : 1/8 */
    CTC_LOG_PERCENT_POWER_NEGATIVE_2,      /**< [HB.GB.GG] 2 (-2) : 1/4   */
    CTC_LOG_PERCENT_POWER_NEGATIVE_1,      /**< [HB.GB.GG] 2 (-1) : 1/2   */
    CTC_LOG_PERCENT_POWER_NEGATIVE_0,      /**< [HB.GB.GG] 2 (0)  : 1/1  */
    CTC_LOG_PERCENT_MAX                    /**< [HB.GB.GG] max number  */
} ;
typedef enum ctc_log_percent_e ctc_log_percent_t;


struct ctc_acl_query_s
{
    uint32  group_id;   /**< [HB.GB.GG] (in)     ACL group ID*/
    uint32  entry_size; /**< [HB.GB.GG] (in)     The maximum number of entry IDs to return. If 0, the number of entries is returned*/
    uint32* entry_array;/**< [HB.GB.GG] (in|out) A pointer to a memory buffer to hold the array of IDs*/
    uint32  entry_count;/**< [HB.GB.GG] (out)    Number of entries returned or. if entry_size  is 0, the number of entries available.*/
};
typedef struct ctc_acl_query_s ctc_acl_query_t;


/**
 @brief [GB] define acl vlan tag operation
*/

enum ctc_acl_vlan_tag_op_e
{
    CTC_ACL_VLAN_TAG_OP_NONE,    /**< [GB.GG] do nothing*/
    CTC_ACL_VLAN_TAG_OP_REP,     /**< [GB.GG] replace tag only for packet tagged*/
    CTC_ACL_VLAN_TAG_OP_ADD,     /**< [GB.GG] append a new tag even if packet already has tag*/
    CTC_ACL_VLAN_TAG_OP_DEL,     /**< [GB.GG] delete packet's tag only for packet tagged*/
    CTC_ACL_VLAN_TAG_OP_REP_OR_ADD, /**< [GG] replace for tagged, add for no stag */
    CTC_ACL_VLAN_TAG_OP_MAX
};
typedef enum ctc_acl_vlan_tag_op_e ctc_acl_vlan_tag_op_t;



/**
 @brief [GB] define acl vid or cos or cfi operation
*/

enum ctc_acl_vlan_tag_sl_e
{
    CTC_ACL_VLAN_TAG_SL_NONE,               /**< [GB.GG] do nothing*/
    CTC_ACL_VLAN_TAG_SL_ALTERNATIVE  = 0x1, /**< [GB.GG] select the other tag's vid/cos, if the other tag not present, use default*/
    CTC_ACL_VLAN_TAG_SL_NEW          = 0x2, /**< [GB.GG] select user assigned vid/cos */
    CTC_ACL_VLAN_TAG_SL_MAX
};
typedef enum ctc_acl_vlan_tag_sl_e ctc_acl_vlan_tag_sl_t;



/**
 @brief [GB] define acl vlan edit operation
*/
struct ctc_acl_vlan_edit_s
{
    uint8  stag_op;         /**< [GB.GG] operation type of stag, see CTC_ACL_VLAN_TAG_OP_XXX  */
    uint8  svid_sl;         /**< [GB.GG] select type of svid, see CTC_ACL_VLAN_TAG_SL_XXX  */
    uint8  scos_sl;         /**< [GB.GG] select type of scos, see CTC_ACL_VLAN_TAG_SL_XXX  */
    uint8  scfi_sl;         /**< [GB.GG] select type of scfi, see CTC_ACL_VLAN_TAG_SL_XXX  */
    uint16 svid_new;        /**< [GB.GG] new svid, valid only if svid_sl is CTC_ACL_VLAN_TAG_OP_REP/CTC_ACL_VLAN_TAG_OP_ADD*/
    uint8  scos_new;        /**< [GB.GG] new scos, valid only if scos_sl is CTC_ACL_VLAN_TAG_OP_REP/CTC_ACL_VLAN_TAG_OP_ADD*/
    uint8  scfi_new;        /**< [GB.GG] new scfi, valid only if scfi_sl is CTC_ACL_VLAN_TAG_OP_REP/CTC_ACL_VLAN_TAG_OP_ADD*/

    uint8  ctag_op;         /**< [GB.GG] operation type of ctag, see CTC_ACL_VLAN_TAG_OP_XXX */
    uint8  cvid_sl;         /**< [GB.GG] select type of cvid, see CTC_ACL_VLAN_TAG_SL_XXX */
    uint8  ccos_sl;         /**< [GB.GG] select type of ccos, see CTC_ACL_VLAN_TAG_SL_XXX */
    uint8  ccfi_sl;         /**< [GB.GG] select type of ccfi, see CTC_ACL_VLAN_TAG_SL_XXX */
    uint16 cvid_new;        /**< [GB.GG] new cvid, valid only if cvid_sl is CTC_ACL_VLAN_TAG_OP_REP/CTC_ACL_VLAN_TAG_OP_ADD*/
    uint8  ccos_new;        /**< [GB.GG] new ccos, valid only if ccos_sl is CTC_ACL_VLAN_TAG_OP_REP/CTC_ACL_VLAN_TAG_OP_ADD*/
    uint8  ccfi_new;        /**< [GB.GG] new ccfi, valid only if ccfi_sl is CTC_ACL_VLAN_TAG_OP_REP/CTC_ACL_VLAN_TAG_OP_ADD*/
};
typedef struct ctc_acl_vlan_edit_s ctc_acl_vlan_edit_t;

/**
 @brief [GG] define acl start packet strip
*/
enum ctc_acl_start_packet_strip_e
{
    CTC_ACL_STRIP_NONE,          /**< [GG] do nothing*/
    CTC_ACL_STRIP_START_TO_L2,   /**< [GG] Remove the start-of-packet up to the L2 header. */
    CTC_ACL_STRIP_START_TO_L3,   /**< [GG] Remove the start-of-packet up to the L3 header. */
    CTC_ACL_STRIP_START_TO_L4,   /**< [GG] Remove the start-of-packet up to the L4 header. */
    CTC_ACL_STRIP_MAX
};
typedef enum ctc_acl_start_packet_strip_e ctc_acl_start_packet_strip_t;

/**
 @brief [GG] define acl packet strip
*/
struct ctc_acl_packet_strip_s
{
    uint8  start_packet_strip;  /**< [GG] strip start type. CTC_ACL_STRIP_START_TO_XX */
    uint8  packet_type;         /**< [GG] payload packet type. PKT_TYPE_XXX */
    uint8  strip_extra_len;     /**< [GG] stript extra length, unit: byte*/
};
typedef struct ctc_acl_packet_strip_s ctc_acl_packet_strip_t;

struct ctc_acl_action_s
{
    uint64 flag;                /**< [HB.GB.GG] Bitmap of CTC_ACL_ACTION_FLAG_XXX */

    uint32 nh_id;               /**< [HB.GB.GG] Forward nexthop ID, shared by acl, qos and pbr*/
    uint32 stats_id;            /**< [GB.GG] Stats id*/
    uint16 micro_policer_id;    /**< [HB.GB.GG] Micro flow policer ID */
    uint16 macro_policer_id;    /**< [GB.GG] Macro flow policer ID */
    uint8  trust;               /**< [HB.GB.GG] QoS trust state, CTC_QOS_TRUST_XXX */
    uint8  color;               /**< [HB.GB.GG] Color: green, yellow, or red :CTC_QOS_COLOR_XXX*/
    uint8  priority;            /**< [HB.GB.GG] Priority: 0 - 63 */
    uint8  log_percent;         /**< [HB.GB.GG] Logging percent, CTC_LOG_PERCENT_POWER_NEGATIVE_XX */
    uint8  log_session_id;      /**< [HB.GB.GG] Logging session ID */
    uint8  qos_domain;          /**< [GB.GG] qos domain*/
    uint8  dscp;                /**< [GB.GG] dscp*/

    uint32  assign_port;        /**< [GG] using for CTC_ACL_ACTION_FLAG_ASSIGN_OUTPUT_PORT, means destination Port*/
    uint16  fid;                /**< [GG] fid */
    uint16  vrf_id;             /**< [GG] Vrf ID of the route */
    uint32  metadata;           /**< [GG] Metadata*/

    ctc_acl_packet_strip_t packet_strip; /**< [GG] strip packet for ingress acl*/

    ctc_acl_vlan_edit_t vlan_edit;     /**< [GB.GG] vlan edit only supported for ingress acl*/
};
typedef struct ctc_acl_action_s ctc_acl_action_t;



/** @brief  acl entry struct */
struct ctc_acl_entry_s
{
    ctc_acl_key_t key;              /**< [HB.GB.GG.DT2] acl key struct*/
    ctc_acl_action_t action;        /**< [HB.GB.GG.DT2] acl action struct*/
    uint32 entry_id;                /**< [HB.GB.GG.DT2] acl action id*/
    uint8  priority_valid;          /**< [HB.GB.GG.DT2] acl entry priority valid. if not valid, use default priority*/
    uint32 priority;                /**< [HB.GB.GG.DT2] acl entry priority.*/
    uint8  pkt_type;                /**< [DT2] Packet Type.*/
    uint8  mode;                    /**< [DT2] Mode. */
};
typedef struct ctc_acl_entry_s ctc_acl_entry_t;

/** @brief  acl copy entry struct */
struct ctc_acl_copy_entry_s
{
    uint32 src_entry_id;  /**< [HB.GB.GG] ACL entry ID to copy from */
    uint32 dst_entry_id;  /**< [HB.GB.GG] New entry copied from src_entry_id */
    uint32 dst_group_id;  /**< [HB.GB.GG] Group ID new entry belongs */
};
typedef struct ctc_acl_copy_entry_s ctc_acl_copy_entry_t;


enum ctc_acl_hash_mac_key_flag_e
{
    CTC_ACL_HASH_MAC_KEY_FLAG_MAC_DA           = 1U << 0, /**< [GB] MAC DA as ACL HASH MAC KEY member*/
    CTC_ACL_HASH_MAC_KEY_FLAG_ETH_TYPE         = 1U << 1, /**< [GB] ETHER TYPE as ACL HASH MAC KEY member*/
    CTC_ACL_HASH_MAC_KEY_FLAG_PHY_PORT         = 1U << 2, /**< [GB] PHY PORT as ACL HASH MAC KEY member*/
    CTC_ACL_HASH_MAC_KEY_FLAG_LOGIC_PORT       = 1U << 3, /**< [GB] LOGIC PORT as ACL HASH MAC KEY member*/
    CTC_ACL_HASH_MAC_KEY_FLAG_COS              = 1U << 4, /**< [GB] COS as ACL HASH MAC KEY member*/
    CTC_ACL_HASH_MAC_KEY_FLAG_VLAN_ID          = 1U << 5, /**< [GB] VLAN ID as ACL HASH MAC KEY member*/
    CTC_ACL_HASH_MAC_KEY_FLAG_MAX              = 1U << 6
};
typedef enum ctc_acl_hash_mac_key_flag_e ctc_acl_hash_mac_key_flag_t;


enum ctc_acl_hash_ipv4_key_flag_e
{
    CTC_ACL_HASH_IPV4_KEY_FLAG_IP_DA            = 1U << 0, /**< [GB] IP DA as ACL IPV4 KEY member*/
    CTC_ACL_HASH_IPV4_KEY_FLAG_IP_SA            = 1U << 1, /**< [GB] IP SA as ACL IPV4 KEY member*/
    CTC_ACL_HASH_IPV4_KEY_FLAG_L4_SRC_PORT      = 1U << 2, /**< [GB] L4 source port as ACL IPV4 KEY member*/
    CTC_ACL_HASH_IPV4_KEY_FLAG_L4_DST_PORT      = 1U << 3, /**< [GB] L4 dest port as ACL IPV4 KEY member*/
    CTC_ACL_HASH_IPV4_KEY_FLAG_PHY_PORT         = 1U << 4, /**< [GB] Phy port as ACL IPV4 KEY member*/
    CTC_ACL_HASH_IPV4_KEY_FLAG_LOGIC_PORT       = 1U << 5, /**< [GB] Logic port as ACL IPV4 KEY member*/
    CTC_ACL_HASH_IPV4_KEY_FLAG_DSCP             = 1U << 6, /**< [GB] Dscp as ACL IPV4 KEY member*/
    CTC_ACL_HASH_IPV4_KEY_FLAG_L4_PROTOCOL      = 1U << 7, /**< [GB] L4 protocol as ACL IPV4 KEY member*/
    CTC_ACL_HASH_IPV4_KEY_FLAG_ARP_PACKET       = 1U << 8, /**< [GB] Arp packet as ACL IPV4 KEY member*/
    CTC_ACL_HASH_IPV4_KEY_FLAG_MAX              = 1U << 9
};
typedef enum ctc_acl_hash_ipv4_key_flag_e ctc_acl_hash_ipv4_key_flag_t;

struct ctc_acl_hash_mac_field_sel_s
{
    uint8 mac_da     ;  /**< [GG] Select mac da as hash mac key field*/
    uint8 mac_sa     ;  /**< [GG] Select mac sa as hash mac key field*/
    uint8 eth_type   ;  /**< [GG] Select ether type as hash mac key field*/
    uint8 phy_port   ;  /**< [GG] Select phy port as hash mac key field*/
    uint8 logic_port ;  /**< [GG] Select logic port as hash mac key field*/
    uint8 metadata   ;  /**< [GG] Select metadata as hash mac key field*/
    uint8 cos        ;  /**< [GG] Select cos as hash mac key field*/
    uint8 cfi        ;  /**< [GG] Select cfi as hash mac key field*/
    uint8 vlan_id    ;  /**< [GG] Select vlan_id as hash mac key field*/
    uint8 tag_valid  ;  /**< [GG] Select tag valid as hash mac key field*/
};
typedef struct ctc_acl_hash_mac_field_sel_s ctc_acl_hash_mac_field_sel_t;


struct ctc_acl_hash_ipv4_field_sel_s
{
    uint8  ip_da      ;  /**< [GG] Select ip da as hash ipv4 key field*/
    uint8  ip_sa      ;  /**< [GG] Select ip sa as hash ipv4 key field*/
    uint8  l4_src_port ;  /**< [GG] Select l4 source port as hash ipv4 key field*/
    uint8  l4_dst_port ;  /**< [GG] Select l4 dest port as hash ipv4 key field*/
    uint8  phy_port    ;  /**< [GG] Select phy port as hash ipv4 key field*/
    uint8  logic_port  ;  /**< [GG] Select logic port as hash ipv4 key field*/
    uint8  metadata    ;  /**< [GG] Select metadata as hash ipv4 key field*/
    uint8  dscp        ;  /**< [GG] Select dscp as hash ipv4 key field*/
    uint8  ecn         ;  /**< [GG] Select ecn da as hash ipv4 key field*/
    uint8  l4_protocol ;  /**< [GG] Select l4 protocol as hash ipv4 key field*/
    uint8  icmp_type   ;  /**< [GG] Select icmp type as hash ipv4 key field*/
    uint8  icmp_code   ;  /**< [GG] Select icmp code as hash ipv4 key field*/
};
typedef struct ctc_acl_hash_ipv4_field_sel_s ctc_acl_hash_ipv4_field_sel_t;

struct ctc_acl_hash_mpls_field_sel_s
{
    uint8 phy_port          ;  /**< [GG] Select phy port as hash mpls key field*/
    uint8 logic_port        ;  /**< [GG] Select logic port as hash mpls key field*/
    uint8 metadata          ;  /**< [GG] Select metadata as hash mpls key field*/
    uint8 mpls_label_num    ;  /**< [GG] Select mpls label number as hash mpls key field*/
    uint8 mpls_label0_label ;  /**< [GG] Select mpls label0's label as hash mpls key field*/
    uint8 mpls_label0_exp   ;  /**< [GG] Select mpls label0's exp as hash mpls key field*/
    uint8 mpls_label0_s     ;  /**< [GG] Select mpls label0's sbit as hash mpls key field*/
    uint8 mpls_label0_ttl   ;  /**< [GG] Select mpls label0's ttl as hash mpls key field*/
    uint8 mpls_label1_label ;  /**< [GG] Select mpls label1's label as hash mpls key field*/
    uint8 mpls_label1_exp   ;  /**< [GG] Select mpls label1's exp as hash mpls key field*/
    uint8 mpls_label1_s     ;  /**< [GG] Select mpls label1's sbit as hash mpls key field*/
    uint8 mpls_label1_ttl   ;  /**< [GG] Select mpls label1's ttl as hash mpls key field*/
    uint8 mpls_label2_label ;  /**< [GG] Select mpls label2's label as hash mpls key field*/
    uint8 mpls_label2_exp   ;  /**< [GG] Select mpls label2's exp as hash mpls key field*/
    uint8 mpls_label2_s     ;  /**< [GG] Select mpls label2's sbit as hash mpls key field*/
    uint8 mpls_label2_ttl   ;  /**< [GG] Select mpls label2's ttl as hash mpls key field*/
};
typedef struct ctc_acl_hash_mpls_field_sel_s ctc_acl_hash_mpls_field_sel_t;

struct ctc_acl_hash_ipv6_field_sel_s
{
    uint8 ip_da      ;  /**< [GG] Select ip da as hash ipv6 key field*/
    uint8 ip_sa      ;  /**< [GG] Select ip sa as hash ipv6 key field*/
    uint8 l4_src_port ;  /**< [GG] Select l4 source port as hash ipv6 key field*/
    uint8 l4_dst_port ;  /**< [GG] Select l4 dest port as hash ipv6 key field*/
    uint8 phy_port    ;  /**< [GG] Select phy port as hash ipv6 key field*/
    uint8 logic_port  ;  /**< [GG] Select logic port as hash ipv6 key field*/
    uint8 metadata    ;  /**< [GG] Select metadata as hash ipv6 key field*/
    uint8 dscp        ;  /**< [GG] Select dscp as hash ipv6 key field*/
    uint8 l4_type     ;  /**< [GG] Select l4 type as hash ipv6 key field*/
    uint8 icmp_type   ;  /**< [GG] Select icmp type as hash ipv6 key field*/
    uint8 icmp_code   ;  /**< [GG] Select icmp code as hash ipv6 key field*/
};
typedef struct ctc_acl_hash_ipv6_field_sel_s ctc_acl_hash_ipv6_field_sel_t;


struct ctc_acl_hash_l2_l3_field_sel_s
{
    uint8 phy_port            ;  /**< [GG] Select phy port as hash l2 l3 key field*/
    uint8 logic_port          ;  /**< [GG] Select logic port as hash l2 l3 key field*/
    uint8 metadata            ;  /**< [GG] Select metadata as hash l2 l3 key field*/
    uint8 mac_da              ;  /**< [GG] Select mac da as hash l2 l3 key field*/
    uint8 mac_sa              ;  /**< [GG] Select mac sa as hash l2 l3 key field*/
    uint8 stag_cos            ;  /**< [GG] Select stag cos as hash l2 l3 key field*/
    uint8 stag_cfi            ;  /**< [GG] Select stag cfi as hash l2 l3 key field*/
    uint8 stag_vlan           ;  /**< [GG] Select stag vlan as hash l2 l3 key field*/
    uint8 stag_valid          ;  /**< [GG] Select stag valid as hash l2 l3 key field*/
    uint8 ctag_cos            ;  /**< [GG] Select ctag cos as hash l2 l3 key field*/
    uint8 ctag_cfi            ;  /**< [GG] Select ctag cfi as hash l2 l3 key field*/
    uint8 ctag_vlan           ;  /**< [GG] Select ctag vlan as hash l2 l3 key field*/
    uint8 ctag_valid          ;  /**< [GG] Select ctag valid as hash l2 l3 key field*/
    uint8 ip_da              ;   /**< [GG] Select ip da as hash l2 l3 key field*/
    uint8 ip_sa              ;   /**< [GG] Select ip sa as hash l2 l3 key field*/
    uint8 dscp                ;  /**< [GG] Select dscp as hash l2 l3 key field*/
    uint8 ecn                 ;  /**< [GG] Select ecn as hash l2 l3 key field*/
    uint8 ttl                 ;  /**< [GG] Select ttl as hash l2 l3 key field*/
    uint8 eth_type            ;  /**< [GG] Select ether type as hash l2 l3 key field*/
    uint8 l3_type             ;  /**< [GG] Select l3 type as hash l2 l3 key field*/
    uint8 l4_type             ;  /**< [GG] Select l4 type as hash l2 l3 key field*/
    uint8 mpls_label_num      ;  /**< [GG] Select mpls label num as hash l2 l3 key field*/
    uint8 mpls_label0_label   ;  /**< [GG] Select mpls label0's label as hash l2 l3 key field*/
    uint8 mpls_label0_exp     ;  /**< [GG] Select mpls label0's exp as hash l2 l3 key field*/
    uint8 mpls_label0_s       ;  /**< [GG] Select mpls label0's sbit as hash l2 l3 key field*/
    uint8 mpls_label0_ttl     ;  /**< [GG] Select mpls label0's ttl as hash l2 l3 key field*/
    uint8 mpls_label1_label   ;  /**< [GG] Select mpls label1's label as hash l2 l3 key field*/
    uint8 mpls_label1_exp     ;  /**< [GG] Select mpls label1's exp as hash l2 l3 key field*/
    uint8 mpls_label1_s       ;  /**< [GG] Select mpls label1's sbit as hash l2 l3 key field*/
    uint8 mpls_label1_ttl     ;  /**< [GG] Select mpls label1's ttl as hash l2 l3 key field*/
    uint8 mpls_label2_label   ;  /**< [GG] Select mpls label2's label as hash l2 l3 key field*/
    uint8 mpls_label2_exp     ;  /**< [GG] Select mpls label2's exp as hash l2 l3 key field*/
    uint8 mpls_label2_s       ;  /**< [GG] Select mpls label2's sbit as hash l2 l3 key field*/
    uint8 mpls_label2_ttl     ;  /**< [GG] Select mpls label2's ttl as hash l2 l3 key field*/

    uint8 l4_src_port;  /**< [GG] Select l4 source port as hash l2 l3 key field*/
    uint8 l4_dst_port;  /**< [GG] Select l4 dest port as hash l2 l3 key field*/

    uint8  icmp_type;  /**< [GG] Select icmp type as hash l2 l3 key field*/
    uint8  icmp_code;  /**< [GG] Select icmp code as hash l2 l3 key field*/

};
typedef struct ctc_acl_hash_l2_l3_field_sel_s ctc_acl_hash_l2_l3_field_sel_t;


struct ctc_acl_hash_field_sel_s
{
    uint8  hash_key_type;            /**< [GG]refer ctc_acl_key_type_t */
    uint32 field_sel_id;             /**< [GG] field select id*/

    union
    {
        ctc_acl_hash_mac_field_sel_t   mac;  /**< [GG] hash mac field select */
        ctc_acl_hash_mpls_field_sel_t  mpls;  /**< [GG] hash mpls field select*/
        ctc_acl_hash_ipv4_field_sel_t  ipv4;  /**< [GG] hash ipv4 field select*/
        ctc_acl_hash_ipv6_field_sel_t  ipv6;  /**< [GG] hash ipv6 field select*/
        ctc_acl_hash_l2_l3_field_sel_t l2_l3;  /**< [GG] hash l2 l3 field select*/
    }u;

};
typedef struct ctc_acl_hash_field_sel_s ctc_acl_hash_field_sel_t;


/** @brief  acl global config */
struct ctc_acl_global_cfg_s
{
    uint16 acl_redirect_num;        /**< [HB] The number of ds_fwd_ptr reserved for acl redirect function */
    uint8  merge_mac_ip;            /**< [GB] If merged, l2 packets and ipv4 packets will all go ipv4-entry. In this case, mac-entry will never hit. */
    uint8  ingress_use_mapped_vlan; /**< [HB.GB] Ingress acl use mapped vlan instead of packet vlan  */

    uint8  trill_use_ipv6;            /**< [GB] trill packet use ipv6 key*/
    uint8  arp_use_ipv6;              /**< [GB] arp packet use ipv6 key*/
    uint8  non_ipv4_mpls_use_ipv6;    /**< [GB] non ipv4 or mpls packet use ipv6 key*/
    uint8  hash_acl_en;               /**< [GB] enable hash acl */
    uint32  priority_bitmap_of_stats;  /**< [GB] bitmap of priority to support stats. Only support 2 stats of 4 priority. Bigger than 2, the high priority will take effect. */

    uint8  ingress_port_service_acl_en; /**< [GB.GG] ingress service acl enable on port*/
    uint8  ingress_vlan_service_acl_en; /**< [GB.GG] ingress service acl enable on vlan*/
    uint8  egress_port_service_acl_en; /**< [GB.GG] egress service acl enable on port*/
    uint8  egress_vlan_service_acl_en; /**< [GB.GG] egress service acl enable on vlan*/

    uint32 hash_ipv4_key_flag;  /**< [GB] hash ipv4 key flag*/
    uint32 hash_mac_key_flag;   /**< [GB] hash mac key flag*/

    uint8  white_list_en;       /**< [GB] acl white list enable*/

};
typedef struct ctc_acl_global_cfg_s ctc_acl_global_cfg_t;

/** @brief  acl group type */
enum ctc_acl_group_type_e
{
    CTC_ACL_GROUP_TYPE_HASH,         /**< [GB.GG] Hash group. */
    CTC_ACL_GROUP_TYPE_PORT_BITMAP,  /**< [GB.GG] Port bitmap. */
    CTC_ACL_GROUP_TYPE_GLOBAL,       /**< [HB.GB.GG] Global acl, mask ports and vlans. */
    CTC_ACL_GROUP_TYPE_VLAN_CLASS,   /**< [HB.GB.GG] A vlan class acl is against a class(group) of vlan*/
    CTC_ACL_GROUP_TYPE_PORT_CLASS,   /**< [HB.GB.GG] A port class acl is against a class(group) of port*/
    CTC_ACL_GROUP_TYPE_SERVICE_ACL,  /**< [HB.GB.GG] A service acl is against a service*/
    CTC_ACL_GROUP_TYPE_L3IF_CLASS,   /**< [DT2] A l3if class acl is against a class(group) of l3if*/
    CTC_ACL_GROUP_TYPE_PBR_CLASS,    /**< [HB.GB.GG] A pbr class is against a class(group) of l3 source interface*/
    CTC_ACL_GROUP_TYPE_PORT,         /**< [GG] Port acl, care gport. */
    CTC_ACL_GROUP_TYPE_MAX
};
typedef enum ctc_acl_group_type_e ctc_acl_group_type_t;

struct ctc_acl_port_bitmap_s
{
    uint8 port_bitmap[CTC_ACL_PORT_BITMAP_IN_BYTE];       /**< [HB] port bitmap*/
};
typedef struct ctc_acl_port_bitmap_s ctc_acl_port_bitmap_t;

/** @brief  acl group info.  NOT For hash group. */
struct ctc_acl_group_info_s
{
    uint8 type;                      /**< [HB.GB.GG.DT2] install_group ignore this. CTC_ACL_GROUP_TYPE_XXX. */
    uint8 lchip;                     /**< [HB.GB.GG.DT2] install_group ignore this. Local chip id. only for type= PORT_BITMAP | PORT_CLASS. Other type ignore it.*/
    uint8 priority;                  /**< [HB.GB.GG.DT2] install_group ignore this. Group priority. Pbr ignore it.*/

    ctc_direction_t dir;             /**< [HB.GB.GG.DT2] diretion. Pbr ignore it.*/
    union
    {
        ctc_port_bitmap_t port_bitmap;/**< [GB.GG.DT2] only support 52 port. even though, the struct is 56-bit*/
        uint16 port_class_id;         /**< [HB.GB.GG.DT2] port class id. multiple ports can share same port_class_id. */
        uint16 vlan_class_id;         /**< [HB.GB.GG.DT2] vlan class id. multiple vlans can share same vlan_class_id. */
        uint16 l3if_class_id;         /**< [DT2] l3if class id. multiple l3 interface can share same l3if_class_id. */
        uint16 service_id;            /**< [HB.GB.GG.DT2] service id.  */
        uint8  pbr_class_id;          /**< [HB.GB.GG] pbr class id. */
        uint32 gport;                 /**< [GG.DT2] gport. */
    } un;
};
typedef struct ctc_acl_group_info_s ctc_acl_group_info_t;


#ifdef __cplusplus
}
#endif

#endif

