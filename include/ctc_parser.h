/**
 @file ctc_parser.h

 @author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2009-12-15

 @version v2.0

This file contains all parser related data structure, enum, macro and proto.
*/

#ifndef CTC_PARSER_H_
#define CTC_PARSER_H_
#ifdef __cplusplus
extern "C" {
#endif

/**
 @defgroup parser PARSER
 @{
*/

/**
 @defgroup parser_l2 PARSER_L2
 @{
*/

/**
 @brief  the packet layer2 type
*/
enum ctc_parser_pkt_type_e
{
    CTC_PARSER_PKT_TYPE_ETHERNET,    /**<[HB.GB.GG] 0: parser packet type,it's config in system intialization*/
    CTC_PARSER_PKT_TYPE_IP_OR_IPV6,  /**<[HB.GB.GG] 1: ipv4 in gb,parser packet type,it's config in system intialization*/
    CTC_PARSER_PKT_TYPE_MPLS,        /**<[HB.GB.GG] 2: parser packet type,it's config in system intialization*/
    CTC_PARSER_PKT_TYPE_IPV6,        /**<[HB.GB.GG] 3: parser packet type,it's config in system intialization*/
    CTC_PARSER_PKT_TYPE_MCAST_MPLS,  /**<[HB.GB.GG] 4: parser packet type,it's config in system intialization*/
    CTC_PARSER_PKT_TYPE_CESOETH,     /**<[HB.GB.GG] 5: trill in gb,parser packet type,it's config in system intialization*/
    CTC_PARSER_PKT_TYPE_FLEXIBLE,    /**<[HB.GB.GG] 6: parser packet type,it's config in system intialization*/
    CTC_PARSER_PKT_TYPE_RESERVED,    /**<[HB.GB.GG] 7: parser packet type,it's config in system intialization*/

    MAX_CTC_PARSER_PKT_TYPE
};
typedef enum ctc_parser_pkt_type_e ctc_parser_pkt_type_t;

/**
 @brief  the packet layer2 type
*/
enum ctc_parser_l2_type_e
{
    CTC_PARSER_L2_TYPE_NONE,                    /**<[HB.GB.GG] 0: parser layer2 type,it's config in system intialization*/
    CTC_PARSER_L2_TYPE_ETH_V2,                  /**<[HB.GB.GG] 1: parser layer2 type,it's config in system initialization*/
    CTC_PARSER_L2_TYPE_ETH_SAP,                 /**<[HB.GB.GG] 2: parser layer2 type,it's config in system initialization*/
    CTC_PARSER_L2_TYPE_ETH_SNAP,                /**<[HB.GB.GG] 3: parser layer2 type,it's config in system initialization*/
    CTC_PARSER_L2_TYPE_PPP_2B,                  /**<[HB.GB]    4: parser layer2 type,it's config in system initialization*/
    CTC_PARSER_L2_TYPE_PPP_1B,                  /**<[HB.GB]    5: parser layer2 type,it's config in system initialization*/
    CTC_PARSER_L2_TYPE_RAW_SNAP,                /**<[HB.GB.GG] 6: parser layer2 type,it's config in system initialization*/
    CTC_PARSER_L2_TYPE_RSV_USER_DEFINE0,        /**<[HB.GB.GG] 7: parser layer2 type, it can be configed by user*/
    CTC_PARSER_L2_TYPE_RSV_USER_DEFINE1,        /**<[HB.GB.GG] 8: parser layer2 type, it can be configed by user*/
    CTC_PARSER_L2_TYPE_RSV_USER_DEFINE2,        /**<[HB.GB.GG] 9: parser layer2 type, it can be configed by user*/
    CTC_PARSER_L2_TYPE_RSV_USER_DEFINE3,        /**<[HB.GB.GG] 10: parser layer2 type, it can be configed by user*/
    CTC_PARSER_L2_TYPE_RSV_USER_DEFINE4,        /**<[HB.GB.GG] 11: parser layer2 type, it can be configed by user*/
    CTC_PARSER_L2_TYPE_RSV_USER_DEFINE5,        /**<[HB.GB.GG] 12: parser layer2 type, it can be configed by user*/
    CTC_PARSER_L2_TYPE_RSV_USER_DEFINE6,        /**<[HB.GB.GG] 13: parser layer2 type, it can be configed by user*/
    CTC_PARSER_L2_TYPE_RSV_USER_DEFINE7,        /**<[HB.GB.GG] 14: parser layer2 type, it can be configed by user*/
    CTC_PARSER_L2_TYPE_RSV_USER_DEFINE_FLEXL2,  /**<[HB.GB.GG] 15: parser layer2 type,it's config in system initialization*/
    MAX_CTC_PARSER_L2_TYPE
};
typedef enum ctc_parser_l2_type_e ctc_parser_l2_type_t;

/**
 @brief  the packet layer3 type
*/
enum ctc_parser_l3_type_e
{
    CTC_PARSER_L3_TYPE_NONE,             /**<[HB.GB.GG] 0: parser layer3 type,it's config in system intialization*/
    CTC_PARSER_L3_TYPE_IP,               /**<[HB.GB.GG] 1: parser layer3 type,it's config in system intialization*/
    CTC_PARSER_L3_TYPE_IPV4,             /**<[HB.GB.GG] 2: parser layer3 type,it's config in system intialization*/
    CTC_PARSER_L3_TYPE_IPV6,             /**<[HB.GB.GG] 3: parser layer3 type,it's config in system intialization*/
    CTC_PARSER_L3_TYPE_MPLS,             /**<[HB.GB.GG] 4: parser layer3 type,it's config in system intialization*/
    CTC_PARSER_L3_TYPE_MPLS_MCAST,       /**<[HB.GB.GG] 5: parser layer3 type,it's config in system intialization*/
    CTC_PARSER_L3_TYPE_ARP,              /**<[HB.GB.GG] 6: parser layer3 type,it's config in system intialization*/

    CTC_PARSER_L3_TYPE_FCOE = 7,         /**< [GB.GG] 7: parser layer3 type */
    CTC_PARSER_L3_TYPE_RARP = 7,         /**< [HB] 7: parser layer3 type,it's config in system intialization*/
    CTC_PARSER_L3_TYPE_TRILL = 8,        /**< [GB.GG] 8: parser layer3 type */
    CTC_PARSER_L3_TYPE_EAPOL =8,         /**< [HB] 8: parser layer3 type,it's config in system intialization*/
    CTC_PARSER_L3_TYPE_ETHER_OAM,        /**< [HB.GB.GG] 9: parser layer3 type,it's config in system intialization*/
    CTC_PARSER_L3_TYPE_SLOW_PROTO,       /**< [HB.GB.GG] 10: parser layer3 type,it's config in system intialization*/
    CTC_PARSER_L3_TYPE_CMAC,             /**< [HB.GB.GG] 11: parser layer3 type,it's config in system intialization*/
    CTC_PARSER_L3_TYPE_PTP,              /**< [HB.GB.GG] 12: parser layer3 type,it's config in system intialization*/
    CTC_PARSER_L3_TYPE_RSV_USER_DEFINE0, /**< [HB.GB.GG] 13: parser layer3 type, it can be configed by user*/
    CTC_PARSER_L3_TYPE_RSV_USER_DEFINE1, /**< [HB.GB.GG] 14: parser layer3 type, it can be configed by user*/
    CTC_PARSER_L3_TYPE_RSV_USER_FLEXL3,  /**< [HB.GB.GG] 15: parser layer3 type,it's config in system intialization*/
    MAX_CTC_PARSER_L3_TYPE
};
typedef enum ctc_parser_l3_type_e ctc_parser_l3_type_t;

/**
 @brief  the packet layer4 type
*/
enum ctc_parser_l4_type_e
{
    CTC_PARSER_L4_TYPE_NONE,             /**< [HB.GB.GG] 0: parser layer4 type,it's config in system intialization*/
    CTC_PARSER_L4_TYPE_TCP,              /**< [HB.GB.GG] 1: parser layer4 type,it's config in system intialization*/
    CTC_PARSER_L4_TYPE_UDP,              /**< [HB.GB.GG] 2: parser layer4 type,it's config in system intialization*/
    CTC_PARSER_L4_TYPE_GRE,              /**< [HB.GB.GG] 3: parser layer4 type,it's config in system intialization*/
    CTC_PARSER_L4_TYPE_IPINIP,           /**< [HB.GB.GG] 4: parser layer4 type,it's config in system intialization*/
    CTC_PARSER_L4_TYPE_V6INIP,           /**< [HB.GB.GG] 5: parser layer4 type,it's config in system intialization*/
    CTC_PARSER_L4_TYPE_ICMP,             /**< [HB.GB.GG] 6: parser layer4 type,it's config in system intialization*/
    CTC_PARSER_L4_TYPE_IGMP,             /**< [HB.GB.GG] 7: parser layer4 type,it's config in system intialization*/
    CTC_PARSER_L4_TYPE_RSV_USER_DEFINE0, /**< [HB] 8: parser layer4 type, it can be configed by user*/
    CTC_PARSER_L4_TYPE_IPINV6 = 8,       /**< [GB.GG] 8: parser layer4 type*/
    CTC_PARSER_L4_TYPE_RSV_USER_DEFINE1, /**< [HB] 9: parser layer4 type, it can be configed by user*/
    CTC_PARSER_L4_TYPE_PBB_ITAG_OAM = 9, /**< [GB.GG] 9: parser layer4 type*/
    CTC_PARSER_L4_TYPE_RSV_USER_DEFINE2, /**< [HB] 10: parser layer4 type, it can be configed by user*/
    CTC_PARSER_L4_TYPE_ACH_OAM = 10,     /**< [GB.GG] 10: parser layer4 type*/
    CTC_PARSER_L4_TYPE_RSV_USER_DEFINE3, /**< [HB] 11: parser layer4 type, it can be configed by user*/
    CTC_PARSER_L4_TYPE_V6INV6 = 11,      /**< [GB.GG] 11: parser layer4 type*/
    CTC_PARSER_L4_TYPE_RSV_USER_DEFINE4, /**< [HB] 12: parser layer4 type, it can be configed by user*/
    CTC_PARSER_L4_TYPE_RDP = 12,         /**< [GB.GG] 12: parser layer4 type*/
    CTC_PARSER_L4_TYPE_RSV_USER_DEFINE5, /**< [HB] 13: parser layer4 type, it can be configed by user*/
    CTC_PARSER_L4_TYPE_SCTP = 13,        /**< [GB.GG] 13: parser layer4 type*/
    CTC_PARSER_L4_TYPE_RSV_USER_DEFINE6, /**< [HB] 14: parser layer4 type,it's config in system intialization*/
    CTC_PARSER_L4_TYPE_DCCP = 14,        /**< [GB.GG] 14: parser layer4 type*/
    CTC_PARSER_L4_TYPE_ANY_PROTO,        /**< [HB.GB] 15: parser layer4 type,it's config in system intialization*/
    MAX_CTC_PARSER_L4_TYPE
};
typedef enum ctc_parser_l4_type_e  ctc_parser_l4_type_t;

/**
 @brief  packet type
*/
enum packet_type_e
{
    PKT_TYPE_ETH = 0,       /**<[HB.GB.GG] pkt type map type0*/
    PKT_TYPE_IPV4,          /**<[HB.GB.GG] pkt type map type1*/
    PKT_TYPE_MPLS,          /**<[HB.GB.GG] pkt type map type2*/
    PKT_TYPE_IPV6,          /**<[HB.GB.GG] pkt type map type3*/
    PKT_TYPE_IP = 5,        /**<[HB.GB.GG] pkt type map type6*/
    PKT_TYPE_FLEXIBLE = 6,  /**<[GB]    pkt type map type6*/

    PKT_TYPE_RESERVED = 7   /**<[HB.GB.GG] pkt type maptype7*/
};
typedef enum packet_type_e packet_type_t;

/**
 @brief  tpid enum
*/
enum ctc_parser_l2_tpid_e
{
    CTC_PARSER_L2_TPID_CVLAN_TPID,      /**< [HB.GB.GG] cvlan tpid*/
    CTC_PARSER_L2_TPID_ITAG_TPID,       /**< [HB.GB.GG] itag tpid in pbb packet*/
    CTC_PARSER_L2_TPID_BLVAN_TPID,      /**< [HB.GB.GG] bvlan tpid in pbb packet*/
    CTC_PARSER_L2_TPID_SVLAN_TPID_0,    /**< [HB.GB.GG] svlan tpid0*/
    CTC_PARSER_L2_TPID_SVLAN_TPID_1,    /**< [HB.GB.GG] svlan tpid1*/
    CTC_PARSER_L2_TPID_SVLAN_TPID_2,    /**< [HB.GB.GG] svlan tpid2*/
    CTC_PARSER_L2_TPID_SVLAN_TPID_3,    /**< [HB.GB.GG] svlan tpid3*/
    CTC_PARSER_L2_TPID_CNTAG_TPID,      /**< [GB.GG] cntag tpid in Congestion Notification (CN) message, defined in the 802.1Qau*/
    CTC_PARSER_L2_TPID_EVB_TPID         /**< [GG] evb tpid */
};
typedef enum ctc_parser_l2_tpid_e ctc_parser_l2_tpid_t;

/**
 @brief  pbb header field
*/
struct ctc_parser_pbb_header_s
{
    uint8 nca_value_en;              /**< [HB.GB.GG] nca value enable set*/
    uint8 outer_vlan_is_cvlan;       /**< [HB.GB.GG] outer vlan is cvlan */
    uint8 vlan_parsing_num;          /**< [HB.GB.GG] vlan parsing num */
    uint8 pbb_oam_ether_type_offset; /**< [HB] pbb oam ethernet type offset  */
    uint16 pbb_oam_ether_type;       /**< [HB] pbb oam ethertype */
    uint16 resv;
};
typedef struct ctc_parser_pbb_header_s ctc_parser_pbb_header_t;

/**
 @brief  layer2 flex header field
*/
struct ctc_parser_l2flex_header_s
{
    uint8 mac_da_basic_offset;          /**<[HB.GB.GG] macda  basic offset, 0-26*/
    uint8 header_protocol_basic_offset; /**<[HB.GB.GG] protocol type (Ethernet Type) basic offset, 0-30*/
    uint8 min_length;                   /**<[HB.GB.GG] min length for parser check*/
    uint8 l2_basic_offset;              /**<[HB.GB.GG] layer2 basic offset, 0-63*/
};
typedef struct ctc_parser_l2flex_header_s ctc_parser_l2flex_header_t;

/**
 @brief  layer2 protocol entry fields
*/
struct ctc_parser_l2_protocol_entry_s
{
    uint32 mask;                        /**<[HB.GB.GG] mask for layer2 header protocol,layer2 type,isEth,isPPP,isSAP,0-0x7FFFFF*/

    uint16 l2_header_protocol;          /**<[HB.GB.GG] layer2 header protocol(ethertype)*/
    uint8 l3_type;                      /**<[HB.GB.GG] layer3 type, 13-15,CTC_PARSER_L3_TYPE_RSV_XXX*/
    uint8 addition_offset;              /**<[HB.GB.GG] addition offset for layer3 info parser, 0-15*/

    ctc_parser_l2_type_t l2_type;       /**<[HB.GB.GG] layer2 type, 0-15, CTC_PARSER_L2_TYPE_XXX*/
};
typedef struct ctc_parser_l2_protocol_entry_s ctc_parser_l2_protocol_entry_t;

/**@} end of @defgroup  parser_l2 PARSER_L2 */

/**
 @defgroup parser_l3 PARSER_L3
 @{
*/

/**
 @brief  ipv6 ctl flags
*/
enum ctc_parser_ipv6_ctl_flags_e
{
    CTC_PARSER_IPV6_CTL_FLAGS_EXT_HDR_LEVEL0 = 0x00000001,        /**< [HB] ipv6 extend header level0 flags*/
    CTC_PARSER_IPV6_CTL_FLAGS_EXT_HDR_LEVEL1 = 0x00000002,        /**< [HB] ipv6 extend header level1 flags*/
    CTC_PARSER_IPV6_CTL_FLAGS_EXT_HDR_LEVEL2 = 0x00000004,        /**< [HB] ipv6 extend header level2 flags*/
    CTC_PARSER_IPV6_CTL_FLAGS_EXT_HDR_LEVEL3 = 0x00000008,        /**< [HB] ipv6 extend header level3 flags*/
    CTC_PARSER_IPV6_CTL_FLAGS_EXT_HDR_LEVEL4 = 0x00000010,        /**< [HB] ipv6 extend header level4 flags*/
    CTC_PARSER_IPV6_CTL_FLAGS_EXT_HDR_LEVEL5 = 0x00000020,        /**< [HB] ipv6 extend header level5 flags*/
    CTC_PARSER_IPV6_CTL_FLAGS_EXT_HDR_LEVEL6 = 0x00000040,        /**< [HB] ipv6 extend header level6 flags*/
    CTC_PARSER_IPV6_CTL_FLAGS_EXT_HDR_LEVEL7 = 0x00000080,        /**< [HB] ipv6 extend header level7 flags*/
    CTC_PARSER_IPV6_CTL_FLAGS_EXT_DIS        = 0x00000100,        /**< [HB] ipv6 extend header disable flags*/
    CTC_PARSER_IPV6_CTL_FLAGS_ERR_OP_EN      = 0x00000200,        /**< [HB] error operation enable*/
    CTC_PARSER_IPV6_CTL_FLAGS_RSV_L3_HDR_PTL = 0x00000400,        /**< [HB] reserved layer3 header protocol*/
    CTC_PARSER_IPV6_CTL_FLAGS_FLEX_EXT_HDR0  = 0x00000800,        /**< [HB] flexiable extend header0 flags*/
    CTC_PARSER_IPV6_CTL_FLAGS_FLEX_EXT_HDR1  = 0x00001000         /**< [HB] flexiable extend header1 flags*/
};
typedef enum ctc_parser_ipv6_ctl_flags_e ctc_parser_ipv6_ctl_flags_t;

/**
 @brief  ipv6 ctl fields
*/
struct ctc_parser_ipv6_ctl_s
{
    struct
    {
        uint8 ext_level_chk_en; /**< [HB] extend header level check enable*/
        uint8 set_ip_options;   /**< [HB] set ip option*/
        uint8 ext_shift;        /**< [HB] extend header shift*/
        uint8 ext_level;        /**< [HB] extend level*/
    } ext_hdr_level;

    uint32 flags;               /**< [HB] CTC_PARSER_IPV6_CTL_FLAGS_XXX*/

    uint8 ipv6_ext_dis;         /**< [HB] ipv6 extend header disable*/
    uint8 ipv6_err_option_en;   /**< [HB] ipv6 error option enable*/
    uint8 rsv_l3_hdr_ptl;       /**< [HB] reserved layer3 header protocol*/
    uint8 flex_ext_hdr1;        /**< [HB] flex extend header1*/

    uint8 flex_ext_hdr0;        /**< [HB] flex extend header0*/
    uint8 resv[3];
};
typedef struct ctc_parser_ipv6_ctl_s ctc_parser_ipv6_ctl_t;

/**
 @brief  ipv6 extend header type
*/
enum ctc_parser_ipv6_extend_header_type_e
{
    CTC_PARSER_IPV6_EHT_ROUTING     = 1,   /**< [HB] routing  header*/
    CTC_PARSER_IPV6_EHT_FRAGMENT    = 2,   /**< [HB] flagment  header*/
    CTC_PARSER_IPV6_EHT_DEST_OPT    = 3,   /**< [HB] destination option header */
    CTC_PARSER_IPV6_EHT_AUTHEN      = 4,   /**< [HB] authentiation  header */
    CTC_PARSER_IPV6_EHT_SCTY_ENCAP  = 5    /**< [HB] Encapsulating  security payload header */
};
typedef enum ctc_parser_ipv6_extend_header_type_e  ctc_parser_ipv6_extend_header_type_t;

/**
 @brief  layer3 flex header fields
*/
struct ctc_parser_l3flex_header_s
{
    uint8 ipda_basic_offset;              /**<[HB.GB.GG] the basic offset of ipda, 0-24*/
    uint8 l3min_length;                   /**<[HB.GB.GG] layer3 min length, 0-255*/
    uint8 protocol_byte_sel;              /**<[HB.GB.GG] protocol byte selection, 0-31*/
    uint8 l3_basic_offset;                /**<[HB.GB.GG] layer3 basic offset, 0-255*/
};
typedef struct ctc_parser_l3flex_header_s ctc_parser_l3flex_header_t;

/**
 @brief  layer3 protocol entry fields
*/
struct ctc_parser_l3_protocol_entry_s
{
    uint8 l4_type;                        /**<[HB.GB.GG] layer4 type,CTC_PARSER_L4_TYPE_XXX*/
    uint8 addition_offset;                /**<[HB.GB.GG] additional offset for layer4 basic offset*/
    uint8 l3_type_mask;                   /**<[HB.GB.GG] layer3 type mask*/
    uint8 l3_type;                        /**<[HB.GB.GG] layer3 type, CTC_PARSER_L3_TYPE_XXX*/

    uint8 l3_header_protocol;             /**<[HB.GB.GG] layer3 header protocol*/
    uint8 l3_header_protocol_mask;        /**<[HB.GB.GG] layer3 header protocol mask*/
    uint16 resv;
};
typedef struct ctc_parser_l3_protocol_entry_s ctc_parser_l3_protocol_entry_t;

/**
 @brief  trill header field
*/
struct ctc_parser_trill_header_s
{
    uint16 inner_tpid;                    /**< [GB.GG] inner vlan tag tpid*/
    uint16 rbridge_channel_ether_type;    /**< [GB.GG] rbridge channel ether type*/
};
typedef struct ctc_parser_trill_header_s ctc_parser_trill_header_t;

/**@} end of @defgroup  parser_l3 PARSER_L3*/

/**
 @defgroup parser_l4 PARSER_L4
 @{
*/

/**
 @brief  layer4 flex header fields
*/
struct ctc_parser_l4flex_header_s
{
    uint8 dest_port_basic_offset;        /**< [HB.GB.GG] byte selection to put as layer4 dest port, 0-30*/
    uint8 l4_min_len;                    /**< [HB.GB.GG] layer4 min length, 0-31*/
    uint8 l4_app_min_len;                /**< [HB] layer4 application min length, 0-31*/
    uint8 resv;
};
typedef struct ctc_parser_l4flex_header_s ctc_parser_l4flex_header_t;

/**
@brief  layer4 app ctl fields
*/
struct ctc_parser_l4app_ctl_s
{
    uint8 ptp_en;                        /**< [GB.GG] ptp enable*/
    uint8 ntp_en;                        /**< [GB.GG] ntp enable*/
    uint8 bfd_en;                        /**< [GB.GG] bfd enable*/
    uint8 vxlan_en;                      /**< [GG] vxlan enable */
};
typedef struct ctc_parser_l4app_ctl_s ctc_parser_l4app_ctl_t;

/**
 @brief  layer4 protocol entry fields
*/
struct ctc_parser_l4_protocol_entry_s
{

    uint16 src_port_value;  /**< [HB] source port value*/
    uint16 dst_port_value;  /**< [HB] dest port value*/

    uint8 application_type; /**< [HB] application type*/
    uint8 byte0_select;     /**< [HB] byte0 select to dest port or src port*/
    uint8 byte_select_dest; /**< [HB] if set,Byte sel is l4 dest port ,or is l4 src port*/
    uint8 entry_vld;        /**< [HB] entry valid*/

    uint8 byte1_select;     /**< [HB] byte1 selection to dest port or src port*/
    uint8 source_port_mask; /**< [HB] source port mask*/
    uint8 dest_port_mask;   /**< [HB] dest port mask*/
    uint8 tcp_flag_mask;    /**< [HB] tcp flag mask*/

    uint8 is_tcp_mask;      /**< [HB] is tcp mask*/
    uint8 is_tcp_value;     /**< [HB] is tcp value*/
    uint8 tcp_flag_value;   /**< [HB] tcp flag value*/
    uint8 resv;
};
typedef struct ctc_parser_l4_protocol_entry_s ctc_parser_l4_protocol_entry_t;

/**
 @brief  layer4 app data entry fields
*/
struct ctc_parser_l4_app_data_entry_s
{
    uint16 l4_dst_port_mask;      /**< [GB] dest port mask*/
    uint16 l4_dst_port_value;     /**< [GB] dest port value*/
    uint8 is_udp_mask;            /**< [GB] is udp mask*/
    uint8 is_udp_value;           /**< [GB] is udp value*/
    uint8 is_tcp_mask;            /**< [GB] is tcp mask*/
    uint8 is_tcp_value;           /**< [GB] is tcp value*/
};
typedef struct ctc_parser_l4_app_data_entry_s ctc_parser_l4_app_data_entry_t;

/**
 @brief  calculate and generate hash key method type
*/
enum ctc_parser_gen_hash_type_e
{
    CTC_PARSER_GEN_HASH_TYPE_XOR, /**< [GB.GG] xor hash type */
    CTC_PARSER_GEN_HASH_TYPE_CRC, /**< [GB.GG] crc hash type */
    CTC_PARSER_GEN_HASH_TYPE_NUM
};
typedef enum ctc_parser_gen_hash_type_e ctc_parser_gen_hash_type_t;

/**
 @brief  layer2 hash flags
*/
enum ctc_parser_l2_hash_flags_e
{
    CTC_PARSER_L2_HASH_FLAGS_COS           = 0x00000001,      /**< [GB.GG] hash key includes cos, support inner packet */
    CTC_PARSER_L2_HASH_FLAGS_MACSA         = 0x00000002,      /**< [GB.GG] hash key includes macsa, support inner packet */
    CTC_PARSER_L2_HASH_FLAGS_MACDA         = 0x00000004,      /**< [GB.GG] hash key includes macda, support inner packet */
    CTC_PARSER_L2_HASH_FLAGS_CTAG_VID      = 0x00000008,      /**< [GG] hash key includes cvlan vlan id, support inner packet */
    CTC_PARSER_L2_HASH_FLAGS_CTAG_CFI      = 0x00000010,      /**< [GG] hash key includes cvlan vlan cfi, support inner packet */
    CTC_PARSER_L2_HASH_FLAGS_CTAG_COS      = 0x00000020,      /**< [GG] hash key includes cvlan vlan cos, support inner packet */
    CTC_PARSER_L2_HASH_FLAGS_STAG_VID      = 0x00000040,      /**< [GG] hash key includes stag vlan id, support inner packet */
    CTC_PARSER_L2_HASH_FLAGS_STAG_CFI      = 0x00000080,      /**< [GG] hash key includes stag vlan cfi, support inner packet */
    CTC_PARSER_L2_HASH_FLAGS_STAG_COS      = 0x00000100,      /**< [GG] hash key includes stag vlan cos, support inner packet */
    CTC_PARSER_L2_HASH_FLAGS_ETHERTYPE     = 0x00000200,      /**< [GG] hash key includes ethertype, support inner packet */
};
typedef enum  ctc_parser_l2_hash_flags_e  ctc_parser_l2_hash_flags_t;

/**
 @brief  ip hash flags
*/
enum ctc_parser_ip_ecmp_hash_flags_e
{
    CTC_PARSER_IP_ECMP_HASH_FLAGS_PROTOCOL        = 0x00000001,    /**< [HB.GB.GG] use protocol num to compute hash flags, support inner packet*/
    CTC_PARSER_IP_ECMP_HASH_FLAGS_DSCP            = 0x00000002,    /**< [HB.GB.GG] use dscp to compute hash flags, support inner packet*/
    CTC_PARSER_IP_ECMP_HASH_FLAGS_IPV6_FLOW_LABEL = 0x00000004,    /**< [HB.GB.GG] use ipv6 flow label to compute hash flags, support inner packet*/
    CTC_PARSER_IP_ECMP_HASH_FLAGS_IPSA            = 0x00000008,    /**< [HB.GB.GG] use ipsa to compute hash flags, support inner packet*/
    CTC_PARSER_IP_ECMP_HASH_FLAGS_IPDA            = 0x00000010     /**< [HB.GB.GG] use ipda to compute hash flags, support inner packet*/
};
typedef enum ctc_parser_ip_ecmp_hash_flags_e ctc_parser_ip_ecmp_hash_flags_t;

/**
 @brief  ip hash flags
*/
enum ctc_parser_ip_hash_flags_e
{
    CTC_PARSER_IP_HASH_FLAGS_PROTOCOL        = 0x00000001,    /**< [GG] use protocol num to compute hash flags, support inner packet*/
    CTC_PARSER_IP_HASH_FLAGS_DSCP            = 0x00000002,    /**< [GG] use dscp to compute hash flags, support inner packet*/
    CTC_PARSER_IP_HASH_FLAGS_IPV6_FLOW_LABEL = 0x00000004,    /**< [GG] use ipv6 flow label to compute hash flags, support inner packet*/
    CTC_PARSER_IP_HASH_FLAGS_IPSA            = 0x00000008,    /**< [GG] use ipsa to compute hash flags, support inner packet*/
    CTC_PARSER_IP_HASH_FLAGS_IPDA            = 0x00000010     /**< [GG] use ipda to compute hash flags, support inner packet*/
};
typedef enum ctc_parser_ip_hash_flags_e ctc_parser_ip_hash_flags_t;

/**
 @brief  layer4 hash flags
*/
enum ctc_parser_l4_ecmp_hash_flags_e
{
    CTC_PARSER_L4_ECMP_HASH_FLAGS_SRC_PORT            = 0x00000001,     /**< [HB.GB.GG] use source port to compute hash flags, support inner packet*/
    CTC_PARSER_L4_ECMP_HASH_FLAGS_DST_PORT            = 0x00000002,     /**< [HB.GB.GG] use dest port to compute hash flags, support inner packet*/
    CTC_PARSER_L4_ECMP_HASH_FLAGS_GRE_KEY             = 0x00000004,     /**< [GB.GG] use dest port to compute hash flags*/
    CTC_PARSER_L4_ECMP_HASH_FLAGS_L4_TYPE             = 0x00000008,     /**< [GG] use layer4 type to compute hash flags*/
    CTC_PARSER_L4_ECMP_HASH_FLAGS_L4_USER_TYPE        = 0x00000010,     /**< [GG] use layer4 user type to compute hash flags*/
    CTC_PARSER_L4_ECMP_HASH_FLAGS_VXLAN_L4_SRC_PORT   = 0x00000020,     /**< [GG] use vxlan layer4 source port to compute hash flags*/
    CTC_PARSER_L4_ECMP_HASH_FLAGS_L4_TCP_FLAG         = 0x00000040,     /**< [GG] use layer4 tcp flag to compute hash flags*/
    CTC_PARSER_L4_ECMP_HASH_FLAGS_L4_TCP_ECN          = 0x00000080,     /**< [GG] use layer4 ecn flag to compute hash flags*/
    CTC_PARSER_L4_ECMP_HASH_FLAGS_L4_NVGRE_VSID       = 0x00000100,     /**< [GG] use layer4 nvgre vsid to compute hash flags*/
    CTC_PARSER_L4_ECMP_HASH_FLAGS_L4_NVGRE_FLOW_ID    = 0x00000200,     /**< [GG] use layer4 nvgre flow id to compute hash flags*/
    CTC_PARSER_L4_ECMP_HASH_FLAGS_L4_VXLAN_VNI        = 0x00000400      /**< [GG] use layer4 vxlan vni to compute hash flags*/
};
typedef enum ctc_parser_l4_ecmp_hash_flags_e ctc_parser_l4_ecmp_hash_flags_t;

/**
 @brief  layer4 hash flags
*/
enum ctc_parser_l4_hash_flags_e
{
    CTC_PARSER_L4_HASH_FLAGS_SRC_PORT            = 0x00000001,     /**< [GG] use source port to compute hash flags, support inner packet */
    CTC_PARSER_L4_HASH_FLAGS_DST_PORT            = 0x00000002,     /**< [GG] use dest port to compute hash flags, support inner packet */
    CTC_PARSER_L4_HASH_FLAGS_GRE_KEY             = 0x00000004,     /**< [GG] use dest port to compute hash flags*/
    CTC_PARSER_L4_HASH_FLAGS_L4_TYPE             = 0x00000008,     /**< [GG] use layer4 type to compute hash flags*/
    CTC_PARSER_L4_HASH_FLAGS_L4_USER_TYPE        = 0x00000010,     /**< [GG] use layer4 user type to compute hash flags*/
    CTC_PARSER_L4_HASH_FLAGS_VXLAN_L4_SRC_PORT   = 0x00000020,     /**< [GG] use vxlan layer4 source port to compute hash flags*/
    CTC_PARSER_L4_HASH_FLAGS_L4_TCP_FLAG         = 0x00000040,     /**< [GG] use layer4 tcp flag to compute hash flags*/
    CTC_PARSER_L4_HASH_FLAGS_L4_TCP_ECN          = 0x00000080,     /**< [GG] use layer4 ecn flag to compute hash flags*/
    CTC_PARSER_L4_HASH_FLAGS_L4_NVGRE_VSID       = 0x00000100,     /**< [GG] use layer4 nvgre vsid to compute hash flags*/
    CTC_PARSER_L4_HASH_FLAGS_L4_NVGRE_FLOW_ID    = 0x00000200,     /**< [GG] use layer4 nvgre flow id to compute hash flags*/
    CTC_PARSER_L4_HASH_FLAGS_L4_VXLAN_VNI        = 0x00000400      /**< [GG] use layer4 vxlan vni to compute hash flags*/
};
typedef enum ctc_parser_l4_hash_flags_e ctc_parser_l4_hash_flags_t;

/**
 @brief  pbb hash flags
*/
enum ctc_parser_pbb_hash_flags_e
{
    CTC_PARSER_PBB_HASH_FLAGS_CMAC_DA            = 0x00000001,     /**< [GG] ecmp/linkagg/flow hash include CMAC DA */
    CTC_PARSER_PBB_HASH_FLAGS_CMAC_SA            = 0x00000002,     /**< [GG] ecmp/linkagg/flow hash include CMAC SA */
    CTC_PARSER_PBB_HASH_FLAGS_ISID               = 0x00000004,     /**< [GG] ecmp/linkagg/flow hash include ISID */
    CTC_PARSER_PBB_HASH_FLAGS_STAG_VID           = 0x00000008,     /**< [GG] ecmp/linkagg/flow hash includestag vlan id */
    CTC_PARSER_PBB_HASH_FLAGS_STAG_COS           = 0x00000010,     /**< [GG] ecmp/linkagg/flow hash includestag vlan cos */
    CTC_PARSER_PBB_HASH_FLAGS_STAG_CFI           = 0x00000020,     /**< [GG] ecmp/linkagg/flow hash includestag vlan cfi */
    CTC_PARSER_PBB_HASH_FLAGS_CTAG_VID           = 0x00000040,     /**< [GG] ecmp/linkagg/flow hash includectag vlan id */
    CTC_PARSER_PBB_HASH_FLAGS_CTAG_COS           = 0x00000080,     /**< [GG] ecmp/linkagg/flow hash includectag vlan cos */
    CTC_PARSER_PBB_HASH_FLAGS_CTAG_CFI           = 0x00000100      /**< [GG] ecmp/linkagg/flow hash includectag vlan cfi */
};
typedef enum ctc_parser_pbb_hash_flags_e ctc_parser_pbb_hash_flags_t;

/**
 @brief  fcoe hash flags
*/
enum ctc_parser_fcoe_ecmp_hash_flags_e
{
    CTC_PARSER_FCOE_ECMP_HASH_FLAGS_SID    = 0x00000001,     /**< [GB.GG] use sid to compute ecmp hash flags*/
    CTC_PARSER_FCOE_ECMP_HASH_FLAGS_DID    = 0x00000002      /**< [GB.GG] use did to compute ecmp hash flags*/
};
typedef enum ctc_parser_fcoe_ecmp_hash_flags_e  ctc_parser_fcoe_ecmp_hash_flags_t;

/**
 @brief  fcoe hash flags
*/
enum ctc_parser_fcoe_hash_flags_e
{
    CTC_PARSER_FCOE_HASH_FLAGS_SID    = 0x00000001,     /**< [GG] use sid to compute hash flags*/
    CTC_PARSER_FCOE_HASH_FLAGS_DID    = 0x00000002      /**< [GG] use did to compute hash flags*/
};
typedef enum ctc_parser_fcoe_hash_flags_e  ctc_parser_fcoe_hash_flags_t;

/**
 @brief  trill hash flags
*/
enum ctc_parser_trill_ecmp_hash_flags_e
{
    CTC_PARSER_TRILL_ECMP_HASH_FLAGS_INNER_VLAN_ID       = 0x00000001,     /**< [GB.GG] use inner vlan id to compute hash flags*/
    CTC_PARSER_TRILL_ECMP_HASH_FLAGS_INGRESS_NICKNAME    = 0x00000002,     /**< [GB.GG] use ingress nickname to compute hash flags*/
    CTC_PARSER_TRILL_ECMP_HASH_FLAGS_EGRESS_NICKNAME     = 0x00000004      /**< [GB.GG] use egress nickname to compute hash flags*/
};
typedef enum ctc_parser_trill_ecmp_hash_flags_e  ctc_parser_trill_ecmp_hash_flags_t;

/**
 @brief  trill hash flags
*/
enum ctc_parser_trill_hash_flags_e
{
    CTC_PARSER_TRILL_HASH_FLAGS_INNER_VLAN_ID       = 0x00000001,     /**< [GG] use inner vlan id to compute hash flags*/
    CTC_PARSER_TRILL_HASH_FLAGS_INGRESS_NICKNAME    = 0x00000002,     /**< [GG] use ingress nickname to compute hash flags*/
    CTC_PARSER_TRILL_HASH_FLAGS_EGRESS_NICKNAME     = 0x00000004      /**< [GG] use egress nickname to compute hash flags*/
};
typedef enum ctc_parser_trill_hash_flags_e  ctc_parser_trill_hash_flags_t;

/**
 @brief  mpls hash flags
*/
enum ctc_parser_mpls_ecmp_hash_flag_e
{
    CTC_PARSER_MPLS_ECMP_HASH_FLAGS_PROTOCOL        = 0x00000001,     /**<[HB.GB.GG] use protocol to compute hash flags*/
    CTC_PARSER_MPLS_ECMP_HASH_FLAGS_DSCP            = 0x00000002,     /**<[HB.GB.GG] use dscp to compute hash flags*/
    CTC_PARSER_MPLS_ECMP_HASH_FLAGS_IPV6_FLOW_LABEL = 0x00000004,     /**<[HB.GB.GG] use ipv6 flow label to compute hash flags*/
    CTC_PARSER_MPLS_ECMP_HASH_FLAGS_IPSA            = 0x00000008,     /**<[HB.GB.GG] use ipsa to compute hash flags*/
    CTC_PARSER_MPLS_ECMP_HASH_FLAGS_IPDA            = 0x00000010      /**<[HB.GB.GG] use ipda to compute ecmp hash flags*/
};
typedef enum ctc_parser_mpls_ecmp_hash_flag_e  ctc_parser_mpls_ecmp_hash_flag_t;

/**
 @brief  mpls hash flags
*/
enum ctc_parser_mpls_hash_flag_e
{
    CTC_PARSER_MPLS_HASH_FLAGS_PROTOCOL        = 0x00000001,         /**<[GG] use protocol to compute hash flags*/
    CTC_PARSER_MPLS_HASH_FLAGS_DSCP            = 0x00000002,         /**<[GG] use dscp to compute hash flags*/
    CTC_PARSER_MPLS_HASH_FLAGS_IPV6_FLOW_LABEL = 0x00000004,         /**<[GG] use ipv6 flow label to compute hash flags*/
    CTC_PARSER_MPLS_HASH_FLAGS_IPSA            = 0x00000008,         /**<[GG] use ipsa to compute hash flags*/
    CTC_PARSER_MPLS_HASH_FLAGS_IPDA            = 0x00000010          /**<[GG] use ipda to compute hash flags*/
};
typedef enum ctc_parser_mpls_hash_flag_e  ctc_parser_mpls_hash_flag_t;

/**
 @brief  l2 hash flags
*/
enum ctc_parser_l2_ecmp_hash_flag_e
{
    CTC_PARSER_L2_ECMP_HASH_FLAGS_COS   = 0x00000001,     /**<[GB] use cos   to compute ecmp hash */
    CTC_PARSER_L2_ECMP_HASH_FLAGS_MACSA = 0x00000002,     /**<[GB] use macsa to compute ecmp hash */
    CTC_PARSER_L2_ECMP_HASH_FLAGS_MACDA = 0x00000004      /**<[GB] use macda to compute ecmp hash */
};
typedef enum ctc_parser_l2_ecmp_hash_flag_e  ctc_parser_l2_ecmp_hash_flag_t;

/**
 @brief  select to config hash type flags
*/
enum ctc_parser_ecmp_hash_type_e
{
    CTC_PARSER_ECMP_HASH_TYPE_FLAGS_IP     = 0x00000001,     /**< [HB.GB.GG] layer3 ip hash ctl flags*/
    CTC_PARSER_ECMP_HASH_TYPE_FLAGS_L4     = 0x00000002,     /**< [HB.GB.GG] layer4 hash ctl flags*/
    CTC_PARSER_ECMP_HASH_TYPE_FLAGS_MPLS   = 0x00000004,     /**< [HB.GB.GG] layer3 mpls hash ctl flags*/
    CTC_PARSER_ECMP_HASH_TYPE_FLAGS_FCOE   = 0x00000008,     /**< [GB.GG] layer3 fcoe hash ctl flags*/
    CTC_PARSER_ECMP_HASH_TYPE_FLAGS_TRILL  = 0x00000010,     /**< [GB.GG] layer3 trill hash ctl flags*/
    CTC_PARSER_ECMP_HASH_TYPE_FLAGS_L2     = 0x00000020,     /**< [GB.GG] layer2 hash ctl flags*/

    /* following is hash type control */
    CTC_PARSER_ECMP_HASH_TYPE_FLAGS_INNER  = 0x01000000,     /**< [GG] if set, config inner hash key */
    CTC_PARSER_ECMP_HASH_TYPE_FLAGS_DLB_EFD= 0x02000000      /**< [GG] if set, config dlb&efd hash key */
};
typedef enum ctc_parser_ecmp_hash_type_e ctc_parser_ecmp_hash_type_t;

enum ctc_parser_hash_type_e
{
    CTC_PARSER_HASH_TYPE_FLAGS_IP    = 0x00000001,           /**< [HB.GB.GG] layer3 ip hash ctl flags*/
    CTC_PARSER_HASH_TYPE_FLAGS_L4    = 0x00000002,           /**< [HB.GB.GG] layer4 hash ctl flags*/
    CTC_PARSER_HASH_TYPE_FLAGS_MPLS  = 0x00000004,           /**< [HB.GB.GG] layer3 mpls hash ctl flags*/
    CTC_PARSER_HASH_TYPE_FLAGS_FCOE  = 0x00000008,           /**< [HB.GB.GG] layer3 fcoe hash ctl flags*/
    CTC_PARSER_HASH_TYPE_FLAGS_TRILL = 0x00000010,           /**< [HB.GB.GG] layer3 trill hash ctl flags*/
    CTC_PARSER_HASH_TYPE_FLAGS_L2    = 0x00000020,           /**< [GG] layer2 hash ctl flags*/
    CTC_PARSER_HASH_TYPE_FLAGS_PBB   = 0x00000040,           /**< [GG] pbb hash ctl flags*/

    /* following is hash type control */
    CTC_PARSER_HASH_TYPE_FLAGS_INNER        = 0x01000000,    /**< [GG] if set, config inner hash key */
    CTC_PARSER_HASH_TYPE_FLAGS_DLB_EFD      = 0x02000000     /**< [GG] if set, config dlb&efd hash key */
};
typedef enum ctc_parser_hash_type_e ctc_parser_hash_type_t;

enum ctc_parser_tunnel_type_e
{
    CTC_PARSER_TUNNEL_TYPE_UDP,             /**< [GG] udp tunnel */
    CTC_PARSER_TUNNEL_TYPE_MPLS_VPN,        /**< [GG] mpls vpn tunnel*/
    CTC_PARSER_TUNNEL_TYPE_MPLS,            /**< [GG] mpls tunnel*/
    CTC_PARSER_TUNNEL_TYPE_IP,              /**< [GG] ipv4 or ipv6 tunnel*/
    CTC_PARSER_TUNNEL_TYPE_TRILL,           /**< [GG] trill tunnel*/
    CTC_PARSER_TUNNEL_TYPE_PBB,             /**< [GG] pbb tunnel*/
    CTC_PARSER_TUNNEL_TYPE_GRE,             /**< [GG] gre tunnel*/
    CTC_PARSER_TUNNEL_TYPE_NVGRE,           /**< [GG] nvgre tunnels*/
    CTC_PARSER_TUNNEL_TYPE_VXLAN,           /**< [GG] vxlan tunnel*/

    CTC_PARSER_TUNNEL_TYPE_MAX
};
typedef enum ctc_parser_tunnel_type_e ctc_parser_tunnel_type_t;

enum ctc_parser_tunnel_hash_mode_e
{
    CTC_PARSER_TUNNEL_HASH_MODE_OUTER,      /**< [GG] use outer hash key */
    CTC_PARSER_TUNNEL_HASH_MODE_MERGE,      /**< [GG] merge inner and outer hash key */
    CTC_PARSER_TUNNEL_HASH_MODE_INNER,      /**< [GG] use inner hash key */
};
typedef enum ctc_parser_tunnel_hash_mode_e ctc_parser_tunnel_hash_mode_t;

/**
 @brief  ecmp hash ctl fields
*/
struct ctc_parser_hash_ctl_s
{
    uint32  hash_type_bitmap;             /**< [HB.GB.GG] hash type flag in ctc_parser_xxx_hash_type_t */

    uint32  ip_flag;                      /**< [HB.GB.GG] layer3 ip hash ctl flag*/
    uint32  l4_flag;                      /**< [HB.GB.GG] layer4 hash ctl flag*/
    uint32  mpls_flag;                    /**< [HB.GB.GG] layer3 mpls hash ctl flag*/
    uint32  fcoe_flag;                    /**< [GB.GG] layer3 fcoe hash ctl flag*/
    uint32  trill_flag;                   /**< [GB.GG] trill hash ctl flag*/
    uint32  l2_flag;                      /**< [GB.GG] layer2 hash ctl flag in CTC_PARSER_ECMP_HASH_TYPE_FLAGS_L2 */
    uint32  pbb_flag;                     /**< [GG] pbb hash flag*/
};
typedef struct ctc_parser_hash_ctl_s ctc_parser_hash_ctl_t;

typedef ctc_parser_hash_ctl_t ctc_parser_ecmp_hash_ctl_t;
typedef ctc_parser_hash_ctl_t ctc_parser_linkagg_hash_ctl_t;
typedef ctc_parser_hash_ctl_t ctc_parser_flow_hash_ctl_t;

/**
 @brief  parser global config fields
*/
struct ctc_parser_global_cfg_s
{
    uint8   ecmp_hash_type;          /**< [GB.GG] ecmp hash algorithm use xor or crc, if set use crc ,else use xor*/
    uint8   linkagg_hash_type;       /**< [GB.GG] linkagg hash algorithm use xor or crc, if set use crc ,else use xor*/
    uint8   small_frag_offset;       /**< [HB.GB.GG] ipv4 small fragment offset, 0~3, means 0,8,16,24 bytes of small fragment length*/
    uint8   resv;
    uint8   ecmp_tunnel_hash_mode[CTC_PARSER_TUNNEL_TYPE_MAX];      /**< [GG] refer to ctc_parser_tunnel_hash_mode_t */
    uint8   linkagg_tunnel_hash_mode[CTC_PARSER_TUNNEL_TYPE_MAX];   /**< [GG] refer to ctc_parser_tunnel_hash_mode_t */
    uint8   dlb_efd_tunnel_hash_mode[CTC_PARSER_TUNNEL_TYPE_MAX];   /**< [GG] refer to ctc_parser_tunnel_hash_mode_t */
};
typedef struct ctc_parser_global_cfg_s ctc_parser_global_cfg_t;

/**
 @brief  parser udp app op ctl fields
*/
struct ctc_parser_udp_app_op_ctl_s
{
    uint16 udp_app_value;       /**< [HB] udp application value*/
    uint16 udp_app_mask;        /**< [HB] udp application mask*/
};
typedef struct ctc_parser_udp_app_op_ctl_s ctc_parser_udp_app_op_ctl_t;

/**
 @brief  parser layer4 ptp ctl fields
*/
struct ctc_parser_ptp_ctl_s
{
    uint16 ptp_port0;           /**< [HB] ptp port0*/
    uint16 ptp_port1;           /**< [HB] ptp port1*/
    uint8 ptp_en;               /**< [HB] ptp enable*/
    uint8 resv[3];
};
typedef struct ctc_parser_ptp_ctl_s ctc_parser_ptp_ctl_t;

/**@} end of @defgroup  parser_l4 PARSER_L4*/

/**
 @defgroup parser_udf
 @{
*/
#define CTC_PARSER_UDF_FIELD_NUM 4

enum ctc_parser_udf_type_e
{
    CTC_PARSER_UDF_TYPE_L3_UDF, /**< [GG] UDF based L3 filed  */
    CTC_PARSER_UDF_TYPE_L4_UDF, /**< [GG] UDF based L4 filed  */
    CTC_PARSER_UDF_TYPE_NUM
};
typedef enum ctc_parser_udf_type_e ctc_parser_udf_type_t;

/**
@brief layer2/layer3/layer4 based DATA packet qualifier fields
*/
struct ctc_parser_udf_s
{
    uint8  type;                                        /**< [GG] UDF based L3 or L4 filed, CTC_PARSER_UDF_TYPE_XX */

    /*L3 UDF key*/
    uint16 ether_type;                                  /**< [GG] Ether type */

    /*L4 UDF key*/
    uint8  ip_version;                                  /**< [GG] IP version, CTC_IP_VER_X, must set for L4 UDF */
    uint16 l3_header_protocol;                          /**< [GG] L3 header protocol, must set for L4 UDF */

    uint8  is_l4_src_port;                              /**< [GG] Select L4 source port as L4 UDF Key */
    uint8  is_l4_dst_port;                              /**< [GG] Select L4 dest port as L4 UDF Key */
    uint16 l4_src_port;                                 /**< [GG] Optinal field, L4 source port */
    uint16 l4_dst_port;                                 /**< [GG] Optinal field, L4 dest port */

    /*
     * L3/L4 UDF offset:
     * +-------+-------+------+-----------+-----------+--------+---------------------+
     * | MacDa | MacSa | Vlan | EtherType |   Layer3  | Layer4 |      Payload        |
     * +-------+-------+------+-----------+-----------+--------+---------------------+
     *                                    ^                                          |
     *                                    |              L3 UDF Offset               |
     *                                    |<---------------------------------------->|
     *
     * +-------+-------+------+-----------+-----------+--------------------+---------+
     * | MacDa | MacSa | Vlan | EtherType | IP Header | Layer4(TCP or UDP) | Payload |
     * +-------+-------+------+-----------+-----------+--------------------+---------+
     *                                                ^                              |
     *                                                |        L4 UDF Offset         |
     *                                                |<---------------------------->|
     */
    uint8  udf_offset[CTC_PARSER_UDF_FIELD_NUM];        /**< [GG] The offset of each UDF field */
    uint8  udf_num;                                     /**< [GG] The number of UDF field */
};
typedef struct ctc_parser_udf_s ctc_parser_udf_t;


/**@} end of @defgroup  parser_udf*/
/**@} end of @defgroup  parser PARSER */

#ifdef __cplusplus
}
#endif

#endif

