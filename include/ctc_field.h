/**
 @file ctc_field.h

 @date 2015-12-19

 @version v1.1

 The file define api struct used in ACL/SCL/Ipfix.
*/

#ifndef _CTC_FIELD_H_
#define _CTC_FIELD_H_

#ifdef __cplusplus
extern "C" {
#endif
/****************************************************************
 *
 * Header Files
 *
 ***************************************************************/


/****************************************************************
*
* Defines and Macros
*
****************************************************************/

/** @brief  key field */
enum ctc_field_key_type_e
{
    /*Packet type field*/
    CTC_FIELD_KEY_L2_TYPE,                  /**< [DT2] Layer 2 type (ctc_parser_l2_type_t). */
    CTC_FIELD_KEY_L3_TYPE,                  /**< [DT2] Layer 3 type (ctc_parser_l3_type_t). */
    CTC_FIELD_KEY_L4_TYPE,                  /**< [DT2] Layer 4 type (ctc_parser_l4_type_t). */

    /*Ether  field*/
    CTC_FIELD_KEY_MAC_SA,                   /**< [DT2] Source MAC Address. */
    CTC_FIELD_KEY_MAC_DA,                   /**< [DT2] Destination MAC Address. */
    CTC_FIELD_KEY_STAG_VALID,               /**< [DT2] S-Vlan Exist. */
    CTC_FIELD_KEY_SVLAN_ID,                 /**< [DT2] S-Vlan ID. */
    CTC_FIELD_KEY_STAG_COS,                 /**< [DT2] Stag Cos. */
    CTC_FIELD_KEY_STAG_CFI,                 /**< [DT2] Stag Cfi. */
    CTC_FIELD_KEY_CTAG_VALID,               /**< [DT2] C-Vlan Exist. */
    CTC_FIELD_KEY_CVLAN_ID,                 /**< [DT2] C-Vlan ID. */
    CTC_FIELD_KEY_CTAG_COS,                 /**< [DT2] Ctag Cos. */
    CTC_FIELD_KEY_CTAG_CFI,                 /**< [DT2] Ctag Cfi. */
    CTC_FIELD_KEY_ETHER_TYPE,               /**< [DT2] Ether type. */
    CTC_FIELD_KEY_VLAN_NUM,                 /**< [DT2] Vlan Tag Number, Share with L2 Type. */

    /*IP packet field*/
    CTC_FIELD_KEY_IP_SA,                    /**< [DT2] Source IPv4 Address. */
    CTC_FIELD_KEY_IP_DA,                    /**< [DT2] Destination IPv4 Address. */
    CTC_FIELD_KEY_IPV6_SA,                  /**< [DT2] Source IPv6 Address. */
    CTC_FIELD_KEY_IPV6_DA,                  /**< [DT2] Destination IPv6 Address. */
    CTC_FIELD_KEY_IPV6_SA_HIGH,             /**< [DT2] Source IPv6 Address (High 64 bits). */
    CTC_FIELD_KEY_IPV6_DA_HIGH,             /**< [DT2] Destination IPv6 Address (High 64 bits). */
    CTC_FIELD_KEY_IPV6_FLOW_LABEL,          /**< [DT2] Ipv6 Flow label*/
    CTC_FIELD_KEY_IP_PROTOCOL,              /**< [DT2] Ip Protocol. */
    CTC_FIELD_KEY_IP_DSCP,                  /**< [DT2] DSCP. */
    CTC_FIELD_KEY_IP_PRECEDENCE,            /**< [DT2] Precedence. */
    CTC_FIELD_KEY_IP_ECN,                   /**< [DT2] Ecn. */
    CTC_FIELD_KEY_IP_FRAG,                  /**< [DT2] IP Fragment Information. */
    CTC_FIELD_KEY_IP_HDR_ERROR,             /**< [DT2] Ip Header Error. */
    CTC_FIELD_KEY_IP_OPTIONS,               /**< [DT2] Ip Options. */
    CTC_FIELD_KEY_IP_PKT_LEN_RANGE,         /**< [DT2] Ip Packet Length Range. */
    CTC_FIELD_KEY_IP_TTL,                   /**< [DT2] Ttl. */

    /*ARP packet field*/
    CTC_FIELD_KEY_ARP_OP_CODE,              /**< [DT2] Opcode Field of ARP Header. */
    CTC_FIELD_KEY_ARP_PROTOCOL_TYPE,            /**< [DT2] Protocol Type of ARP Header. */
    CTC_FIELD_KEY_ARP_SENDER_IP,                /**< [DT2] Sender IPv4 Field of ARP Header. */
    CTC_FIELD_KEY_ARP_TARGET_IP,                /**< [DT2] Target IPv4 Field of ARP Header */

    /*TCP/UDP packet field*/
    CTC_FIELD_KEY_L4_DST_PORT,              /**< [DT2] Layer 4 Dest Port. */
    CTC_FIELD_KEY_L4_SRC_PORT,              /**< [DT2] Layer 4 Src Port. */
    CTC_FIELD_KEY_L4_SRC_PORT_RANGE,        /**< [DT2] Layer 4 Src Port Range. */
    CTC_FIELD_KEY_L4_DST_PORT_RANGE,        /**< [DT2] Layer 4 Dest Port Range. */
    CTC_FIELD_KEY_TCP_ECN,                  /**< [DT2] TCP Ecn. */
    CTC_FIELD_KEY_TCP_FLAGS,                /**< [DT2] TCP Flags. */

    /*GRE packet field*/
    CTC_FIELD_KEY_GRE_KEY,                  /**< [DT2] Gre Key. */

    /*VXLAN packet field*/
    CTC_FIELD_KEY_VN_ID,                    /**< [DT2] Vxlan Network Id. */

    /*ICMP packet field*/
    CTC_FIELD_KEY_ICMP_CODE,                /**< [DT2] ICMP Code.*/
    CTC_FIELD_KEY_ICMP_TYPE,                /**< [DT2] ICMP Type.*/

    /*IGMP packet field*/
    CTC_FIELD_KEY_IGMP_TYPE,                /**< [DT2] IGMP Type.*/

    /*MPLS packet field*/
    CTC_FIELD_KEY_LABEL_NUM,                /**< [DT2] MPLS Label Number. */
    CTC_FIELD_KEY_MPLS_LABEL0,              /**< [DT2] Label Field of the MPLS Label 0. */
    CTC_FIELD_KEY_MPLS_EXP0,                /**< [DT2] Exp Field of the MPLS Label 0.*/
    CTC_FIELD_KEY_MPLS_SBIT0,               /**< [DT2] S-bit Field of the MPLS Label 0.*/
    CTC_FIELD_KEY_MPLS_TTL0,                /**< [DT2] Ttl Field of the MPLS Label 0.*/
    CTC_FIELD_KEY_MPLS_LABEL1,              /**< [DT2] Label Field of the MPLS Label 1. */
    CTC_FIELD_KEY_MPLS_EXP1,                /**< [DT2] Exp Field of the MPLS Label 1.*/
    CTC_FIELD_KEY_MPLS_SBIT1,               /**< [DT2] S-bit Field of the MPLS Label 1.*/
    CTC_FIELD_KEY_MPLS_TTL1,                /**< [DT2] Ttl Field of the MPLS Label 1.*/
    CTC_FIELD_KEY_MPLS_LABEL2,              /**< [DT2] Label Field of the MPLS Label 2. */
    CTC_FIELD_KEY_MPLS_EXP2,                /**< [DT2] Exp Field of the MPLS Label 2.*/
    CTC_FIELD_KEY_MPLS_SBIT2,               /**< [DT2] S-bit Field of the MPLS Label 2.*/
    CTC_FIELD_KEY_MPLS_TTL2,                /**< [DT2] Ttl Field of the MPLS Label 2.*/

    /*NSH packet field*/
    CTC_FIELD_KEY_NSH_CBIT,                 /**< [DT2] Nsh Cbit. */
    CTC_FIELD_KEY_NSH_NEXT_PROTOCOL,        /**< [DT2] Nsh Next Protocol. */
    CTC_FIELD_KEY_NSH_OBIT,                 /**< [DT2] Nsh Obit. */
    CTC_FIELD_KEY_NSH_SI,                   /**< [DT2] Nsh Si. */
    CTC_FIELD_KEY_NSH_SPI,                  /**< [DT2] Nsh Spi. */

    /*Ether OAM packet field*/
    CTC_FIELD_KEY_IS_Y1731_OAM,             /**< [DT2] Is Y1731 Oam. */
    CTC_FIELD_KEY_ETHER_OAM_LEVEL,          /**< [DT2] Oam Level. */
    CTC_FIELD_KEY_ETHER_OAM_OP_CODE,        /**< [DT2] Oam Opcode. */
    CTC_FIELD_KEY_ETHER_OAM_VERSION,        /**< [DT2] Oam Version. */

    /*Slow Protocol packet field*/
    CTC_FIELD_KEY_SLOW_PROTOCOL_CODE,       /**< [DT2] Slow Protocol Code. */
    CTC_FIELD_KEY_SLOW_PROTOCOL_FLAGS,      /**< [DT2] Slow Protocol Flags. */
    CTC_FIELD_KEY_SLOW_PROTOCOL_SUB_TYPE,   /**< [DT2] Slow Protocol Sub Type. */

    /*PTP packet field*/
    CTC_FIELD_KEY_PTP_MESSAGE_TYPE,         /**< [DT2] PTP Message Type. */
    CTC_FIELD_KEY_PTP_VERSION,              /**< [DT2] PTP Message Version. */

    /*FCOE packet field*/
    CTC_FIELD_KEY_FCOE_DST_FCID,            /**< [DT2] Fcoe Did.*/
    CTC_FIELD_KEY_FCOE_SRC_FCID,            /**< [DT2] Fcoe Sid.*/

    /*Capwap packet field*/
    CTC_FIELD_KEY_CAPWAP_RADIO_MAC,         /**< [DT2] Capwap Radio Mac.*/
    CTC_FIELD_KEY_CAPWAP_RADIO_ID,          /**< [DT2] Capwap Radio Id.*/
    CTC_FIELD_KEY_CAPWAP_CTL_PKT,           /**< [DT2] Capwap Control Packet.*/

    /*SATPDU packet field*/
    CTC_FIELD_KEY_SATPDU_MEF_OUI,           /**< [DT2] Satpdu Metro Ethernet Forum Oui.*/
    CTC_FIELD_KEY_SATPDU_OUI_SUB_TYPE,      /**< [DT2] Satpdu Oui Sub type.*/

    /*TRILL packet field*/
    CTC_FIELD_KEY_INGRESS_NICKNAME,         /**< [DT2] Ingress Nick Name. */
    CTC_FIELD_KEY_EGRESS_NICKNAME,          /**< [DT2] Egress Nick Name. */
    CTC_FIELD_KEY_IS_ESADI,                 /**< [DT2] Is Esadi. */
    CTC_FIELD_KEY_IS_TRILL_CHANNEL,         /**< [DT2] Is Trill Channel. */
    CTC_FIELD_KEY_TRILL_INNER_VLANID,       /**< [DT2] Trill Inner Vlan Id. */
    CTC_FIELD_KEY_TRILL_INNER_VLANID_VALID, /**< [DT2] Trill Inner Vlan Id Valid. */
    CTC_FIELD_KEY_TRILL_KEY_TYPE,           /**< [DT2] Trill Key Type. */
    CTC_FIELD_KEY_TRILL_LENGTH,             /**< [DT2] Trill Length. */
    CTC_FIELD_KEY_TRILL_MULTIHOP,           /**< [DT2] Trill Multi-Hop. */
    CTC_FIELD_KEY_TRILL_MULTICAST,          /**< [DT2] Trill MultiCast. */
    CTC_FIELD_KEY_TRILL_VERSION,            /**< [DT2] Trill Version. */
    CTC_FIELD_KEY_TRILL_TTL,                /**< [DT2] Trill Ttl. */

    /*SGT packet field*/
    CTC_FIELD_KEY_DST_SGT_ID,               /**< [DT2] Destination Security Group ID. */
    CTC_FIELD_KEY_SRC_SGT_ID,               /**< [DT2] Source Security Group ID. */

    /*UDF, user define field*/
    CTC_FIELD_KEY_UDF,                      /**< [DT2] UDF. */

    /*Match port type*/
    CTC_FIELD_KEY_GLOBAL_PORT,              /**< [DT2] Global Port. */
    CTC_FIELD_KEY_LOGIC_PORT,               /**< [DT2] Logic Port. */
    CTC_FIELD_KEY_PORT_CLASS,               /**< [DT2] Port Class. */

    /*Forwarding information*/
    CTC_FIELD_KEY_DECAP,                    /**< [DT2] Decapsulation occurred. */
    CTC_FIELD_KEY_ELEPHANT_PKT,             /**< [DT2] Is Elephant. */
    CTC_FIELD_KEY_VXLAN_PKT,                /**< [DT2] Is Vxlan Packet. */
    CTC_FIELD_KEY_ROUTED_PKT,               /**< [DT2] Is Routed packet. */
    CTC_FIELD_KEY_PKT_FWD_TYPE,             /**< [DT2] Packet Forwarding Type. */
    CTC_FIELD_KEY_MACSA_LKUP,               /**< [DT2] Mac-Sa Lookup Enable. */
    CTC_FIELD_KEY_MACSA_HIT,                /**< [DT2] Mac-Sa Lookup Hit. */
    CTC_FIELD_KEY_MACDA_LKUP,               /**< [DT2] Mac-Da Lookup Enable. */
    CTC_FIELD_KEY_MACDA_HIT,                /**< [DT2] Mac-Da Lookup Hit. */
    CTC_FIELD_KEY_IPSA_LKUP,                /**< [DT2] L3-Sa Lookup Enable. */
    CTC_FIELD_KEY_IPSA_HIT,                 /**< [DT2] L3-Sa Lookup Hit. */
    CTC_FIELD_KEY_IPDA_LKUP,                /**< [DT2] L3-Da Lookup Enable. */
    CTC_FIELD_KEY_IPDA_HIT,                 /**< [DT2] L3-Da Lookup Hit. */

    CTC_FIELD_KEY_DISCARD,                  /**< [DT2] Packet Is Flagged to be Discarded. */
    CTC_FIELD_KEY_CPU_REASON_ID,            /**< [DT2] CPU Reason Id. */
    CTC_FIELD_KEY_DST_GPORT,                /**< [DT2] Fwd Destination Port. */
    CTC_FIELD_KEY_DST_NHID,                 /**< [DT2] Nexthop Id. */

    CTC_FIELD_KEY_INTERFACE_ID,             /**< [DT2] L3 Interface Id. */
    CTC_FIELD_KEY_VRFID,                    /**< [DT2] Vrfid. */
    CTC_FIELD_KEY_METADATA,                 /**< [DT2] Metadata. */
    CTC_FIELD_KEY_CUSTOMER_ID,              /**< [DT2] Customer Id*/

    /*HASH key field*/
    CTC_FIELD_KEY_HASH_SEL_ID,              /**< [DT2] Hash Key Field Select ID. */
    CTC_FIELD_KEY_HASH_VALID,               /**< [DT2] Hash Valid Key. */

    CTC_FIELD_KEY_NUM
};
typedef enum ctc_field_key_type_e ctc_field_key_type_t;

struct ctc_field_range_s
{
    uint32 min;
    uint32 max;
};
typedef struct ctc_field_range_s ctc_field_range_t;

struct ctc_field_key_s
{
    uint16 type;                    /**< [DT2] Key Field type, CTC_FIELD_KEY_XXX. */

    uint32 data;                    /**< [DT2] Key Field data (uint32). */
    uint32 mask;                    /**< [DT2] Key Field mask (uint32). */
    void*  ext_data;                /**< [DT2] Key Field extend data (void*). */
    void*  ext_mask;                /**< [DT2] Key Field extend mask (void*). */
};
typedef struct ctc_field_key_s ctc_field_key_t;


#ifdef __cplusplus
}
#endif

#endif


