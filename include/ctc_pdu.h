/**
 @file ctc_pdu.h

 @author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2009-12-30

 @version v2.0

 This file contains all pdu related data structure, enum, macro and proto.
*/

#ifndef _CTC_PDU_H_
#define _CTC_PDU_H_
#ifdef __cplusplus
extern "C" {
#endif

/**
 @defgroup pdu PDU
 @{
*/

/**
 @defgroup l2pdu L2PDU
 @{
*/

/**
 @brief pdu l2 pdu action based flags
*/
enum ctc_pdu_l2pdu_type_e
{
    CTC_PDU_L2PDU_TYPE_BPDU,                /**< [HB.GB.GG] Macda = 01:80:c2:00:00:00, static classify by mac.*/
    CTC_PDU_L2PDU_TYPE_SLOW_PROTO,          /**< [GB.GG] Ether type = 0x8809, static classify by ether type.*/
    CTC_PDU_L2PDU_TYPE_EAPOL,               /**< [GB.GG] Ether type = 0x888E, static classify by ether type.*/
    CTC_PDU_L2PDU_TYPE_LLDP,                /**< [GB.GG] Ether type = 0x88CC, static classify by ether type.*/
    CTC_PDU_L2PDU_TYPE_ISIS,                /**< [GB.GG] Ether type = 0x22F4, static classify by ether type.*/
    CTC_PDU_L2PDU_TYPE_EFM_OAM,             /**< [GG] Ether type = 0x8809, Macda = 0180.C200.0002, static classify by ether type and mac .*/

    CTC_PDU_L2PDU_TYPE_L3TYPE,              /**< [HB] Layer2 pdu action based on layer3 type.*/
    CTC_PDU_L2PDU_TYPE_L2HDR_PROTO,         /**< [HB.GB.GG] Layer2 pdu action based on ether type.*/
    CTC_PDU_L2PDU_TYPE_MACDA,               /**< [HB.GB.GG] Layer2 pdu action based on macda.*/
    CTC_PDU_L2PDU_TYPE_MACDA_LOW24,         /**< [HB.GB.GG] Layer2 pdu action based on macda low24 bit, the most 24bit is 01:80:C2.*/
    CTC_PDU_L2PDU_TYPE_FIP,                 /**< [GG] FIP(FCoE Initialization Protocol),Ether type = 0x8914 */
    MAX_CTC_PDU_L2PDU_TYPE
};
typedef enum ctc_pdu_l2pdu_type_e ctc_pdu_l2pdu_type_t;

/**
 @brief pdu layer2 pdu entry fileds
*/
union ctc_pdu_l2pdu_key_u
{
    /*CTC_PDU_L2PDU_TYPE_MACDA and CTC_PDU_L2PDU_TYPE_MACDA_LOW24*/
    struct
    {
        mac_addr_t mac;                   /**< [HB.GB.GG] Macda*/
        mac_addr_t mac_mask;              /**< [HB] Macda mask*/
    } l2pdu_by_mac;
    uint16 l2hdr_proto;                   /**< [HB.GB.GG] Layer2 header protocol: CTC_PDU_L2PDU_TYPE_L2HDR_PROTO.*/
};
typedef union ctc_pdu_l2pdu_key_u ctc_pdu_l2pdu_key_t;

/**
 @brief pdu layer2 pdu global action types
*/
struct ctc_pdu_global_l2pdu_action_s
{
    uint8 bypass_all;           /**< [HB] When set the bit, not do lkp operation and so on.
                                          If the pdu's port action is redirect to cpu & discard,
                                          bypass_all should be set to 1 ,else 0.*/
    uint8 entry_valid;          /**< [HB.GB.GG] Control the added protocol entry is valid or not.*/
    uint8 action_index;         /**< [HB.GB.GG] Entry for per-port action index,
                                                the index range is 0-14 in humber, 0-31 in gb.*/
    uint8 copy_to_cpu;          /**< [HB] Bpdu exception operation.*/
};
typedef struct ctc_pdu_global_l2pdu_action_s ctc_pdu_global_l2pdu_action_t;

/**
 @brief  layer2 pdu action types
*/
enum ctc_pdu_port_l2pdu_action_e
{
    CTC_PDU_L2PDU_ACTION_TYPE_REDIRECT_TO_CPU,         /**< [HB.GB.GG] Layer2 pdu action type: redirect to cpu.*/
    CTC_PDU_L2PDU_ACTION_TYPE_COPY_TO_CPU,             /**< [HB.GB.GG] Layer2 pdu action type: copy to cpu.*/
    CTC_PDU_L2PDU_ACTION_TYPE_FWD,                     /**< [HB.GB.GG] Layer2 pdu action type: normal forwarding.*/
    CTC_PDU_L2PDU_ACTION_TYPE_DISCARD,                 /**< [HB.GB.GG] Layer2 pdu action type: discard the pdu.*/
    MAX_CTC_PDU_L2PDU_ACTION_TYPE
};
typedef enum ctc_pdu_port_l2pdu_action_e ctc_pdu_port_l2pdu_action_t;

/**@} end of @defgroup  l2pdu L2PDU */

/**
 @defgroup l3pdu L3PDU
 @{
*/

/**
 @brief  layer3 pdu action based flags
*/
enum ctc_pdu_l3pdu_type_e
{
    CTC_PDU_L3PDU_TYPE_OSPF,              /**< [GB.GG] Regardless ipv4 or ipv6, layer3 protocol = 89, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_PIM,               /**< [GB.GG] Regardless ipv4 or ipv6, layer3 protocol = 103, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_VRRP,              /**< [GB.GG] Regardless ipv4 or ipv6, layer3 protocol = 112, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_RSVP,              /**< [GB.GG] Layer3 protocol = 46, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_RIP,               /**< [GB.GG] UDP, for GB DestPort = 520 or DestPort = 521, for GG DestPort = 520, static classify by upd port.*/
    CTC_PDU_L3PDU_TYPE_BGP,               /**< [GB.GG] Regardless of ipv4 or ipv6, TCP, DestPort = 179, other bgp destport pdu classify
                                                       by CTC_PDU_L3PDU_TYPE_LAYER4_PORT or forwarding to cpu.*/
    CTC_PDU_L3PDU_TYPE_MSDP,              /**< [GB.GG] TCP, DestPort = 639, static classify by upd port.*/
    CTC_PDU_L3PDU_TYPE_LDP,               /**< [GB.GG] TCP or UDP, DestPort = 646, other ldp destport pdu classify
                                                       by CTC_PDU_L3PDU_TYPE_LAYER4_PORT or forwarding to cpu.*/
    CTC_PDU_L3PDU_TYPE_IPV4OSPF,          /**< [GG] IPv4, layer3 protocol = 89, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_IPV6OSPF,          /**< [GG] IPv6, layer3 protocol = 89, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_IPV4PIM,           /**< [GG] IPv4, layer3 protocol = 103, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_IPV6PIM,           /**< [GG] IPv6, layer3 protocol = 103, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_IPV4VRRP,          /**< [GG] IPv4, layer3 protocol = 112, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_IPV6VRRP,          /**< [GG] IPv6, layer3 protocol = 112, static classify by protocol.*/

    CTC_PDU_L3PDU_TYPE_ICMPIPV6_RS,       /**< [GG] IPv6, layer3 protocol = 58, layer4 source port = 133, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_ICMPIPV6_RA,       /**< [GG] IPv6, layer3 protocol = 58, layer4 source port = 134, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_ICMPIPV6_NS,       /**< [GG] IPv6, layer3 protocol = 58, layer4 source port = 135, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_ICMPIPV6_NA,       /**< [GG] IPv6, layer3 protocol = 58, layer4 source port = 136, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_ICMPIPV6_REDIRECT, /**< [GG] IPv6, layer3 protocol = 58, layer4 source port = 137, static classify by protocol.*/
    CTC_PDU_L3PDU_TYPE_RIPNG,             /**< [GG] UDP, DestPort = 521, static classify by upd port.*/

    CTC_PDU_L3PDU_TYPE_L3HDR_PROTO,       /**< [HB.GB.GG] Layer3 pdu action based on layer3 header protocol.*/
    CTC_PDU_L3PDU_TYPE_LAYER3_IPDA,       /**< [GG] Layer3 pdu action based on layer3 ip address.*/
    CTC_PDU_L3PDU_TYPE_LAYER4_PORT,       /**< [HB.GB.GG] Layer3 pdu action based on layer4 destport.*/
    CTC_PDU_L3PDU_TYPE_LAYER4_TYPE,       /**< [HB] Layer3 pdu action based on layer4 type.*/

    CTC_PDU_L3PDU_TYPE_ARP,               /**< [GG] Ether type = 0x0806*/
    CTC_PDU_L3PDU_TYPE_DHCP,              /**< [GG] IPv4 UDP l4DestPort = 67 or 68, IPv6 UDP l4DestPort = 546 or 547.*/

    MAX_CTC_PDU_L3PDU_TYPE
};
typedef enum ctc_pdu_l3pdu_type_e ctc_pdu_l3pdu_type_t;

/**
 @brief  layer3 pdu entry fields
*/
union ctc_pdu_l3pdu_key_u
{
    uint8 l3hdr_proto;       /**< [HB.GB.GG] Layer3 header protocol*/

    struct
    {
        uint16 dest_port;    /**< [HB.GB.GG] Layer4 dest port*/
        uint8 is_tcp;        /**< [HB.GB.GG] Field dest_port is tcp value.*/
        uint8 is_udp;        /**< [HB.GB.GG] Field dest_port is udp vlaue.*/
    }l3pdu_by_port;

    struct
    {
        uint16 ipda;         /**< [GG] for ipv4 ipda value apply to IPv4DaAddr(20,31),
                                                IPv4DaAddr(0,19) value is fixed to 0xE0000.
                                       for ipv6 ipda(4,7)  value apply to IPv6DaAddr(12,15),
                                                ipda(8,15) value apply to IPv6DaAddr(120,127),
                                                IPv6DaAddr(0,7) value is fixed to 0xFF, other bits are 0.*/
        uint8  is_ipv4;      /**< [GG] Field ipda is ipv4 value.*/
        uint8  is_ipv6;      /**< [GG] Field ipda is ipv6 value.*/
    }l3pdu_by_ipda;
};
typedef union ctc_pdu_l3pdu_key_u ctc_pdu_l3pdu_key_t;

/**
 @brief  layer3 pdu entry fields
*/
struct ctc_pdu_global_l3pdu_action_s
{
    uint8 action_index;      /**< [HB.GB.GG] Entry for per-l3if action index, the index range is 0-12 in hb, 0-63 in gb.*/
    uint8 entry_valid;       /**< [HB.GB.GG] Layer3 protocol action entry is valid or not.*/
};
typedef struct ctc_pdu_global_l3pdu_action_s ctc_pdu_global_l3pdu_action_t;

/**
 @brief  layer2 pdu action types
*/
enum ctc_pdu_l3if_l3pdu_action_e
{
    CTC_PDU_L3PDU_ACTION_TYPE_FWD,           /**< [HB.GG] Layer3 pdu action type: normal forwarding.*/
    CTC_PDU_L3PDU_ACTION_TYPE_COPY_TO_CPU,   /**< [HB.GG] Layer3 pdu action type: copy to cpu.*/
    MAX_CTC_PDU_L3PDU_ACTION_TYPE
};
typedef enum ctc_pdu_l3if_l3pdu_action_e ctc_pdu_l3if_l3pdu_action_t;

/**
 @brief  default l2-pdu action index
*/
enum ctc_l2pdu_action_index_e
{
    /**< default assigned,user can changed action index except EFM OAM PDU */
    CTC_L2PDU_ACTION_INDEX_BPDU       = 0,   /**< [HB.GB.GG]  BPDU action index, For GB, 0 is reserve for EFM.*/
    CTC_L2PDU_ACTION_INDEX_SLOW_PROTO = 1,   /**< [HB.GB.GG]  Slow protocol action index.*/
    CTC_L2PDU_ACTION_INDEX_EAPOL      = 2,   /**< [HB.GB.GG]  EAPOL action index*/
    CTC_L2PDU_ACTION_INDEX_LLDP       = 3,   /**< [HB.GB.GG]  LLDP action index*/
    CTC_L2PDU_ACTION_INDEX_ISIS       = 4,   /**< [HB.GB.GG]  ISIS action index*/
    CTC_L2PDU_ACTION_INDEX_EFM_OAM    = 5,   /**< [GG]  Efm oam action index*/
    CTC_L2PDU_ACTION_INDEX_FIP        = 6,   /**< [GG]  FIP(FCoE Initialization Protocol) action index*/

/*Modified by System to suport erps*/
    CTC_L2PDU_ACTION_INDEX_ERPS       = 7,   /**< [GG]  ERPS */
    CTC_L2PDU_ACTION_INDEX_RSV_BEGIN = 8,    /**< [HB] The begin of reserve action index*/
    CTC_L2PDU_ACTION_INDEX_RSV_END   = 14,   /**< [HB] The end of reserve action index*/
    CTC_L2PDU_ACTION_INDEX_MACDA     = 63    /**< [HB.GB.GG] MACDA exception to cpu action index*/
};
typedef enum ctc_l2pdu_action_index_e ctc_l2pdu_action_index_t;

/**
 @brief  default l3-pdu action index
*/
enum ctc_l3pdu_action_index_e
{
    CTC_L3PDU_ACTION_INDEX_RIP       = 0,    /**< [HB.GB.GG] RIP action index*/
    CTC_L3PDU_ACTION_INDEX_RIPNG     = 0,    /**< [GB.GG] RIPng action index*/
    CTC_L3PDU_ACTION_INDEX_LDP       = 1,    /**< [HB.GB.GG] LDP action index*/
    CTC_L3PDU_ACTION_INDEX_OSPF      = 2,    /**< [HB.GB.GG] Regardless of IPv4 or IPv6, OSPF action index, default cfg.*/
    CTC_L3PDU_ACTION_INDEX_PIM       = 3,    /**< [HB.GB.GG] Regardless of IPv4 or IPv6, PIM action index, default cfg.*/
    CTC_L3PDU_ACTION_INDEX_BGP       = 4,    /**< [HB.GB.GG] Regardless of IPv4 or IPv6, BGP action index, default cfg.*/
    CTC_L3PDU_ACTION_INDEX_RSVP      = 5,    /**< [HB.GB.GG] RSVP action index*/
    CTC_L3PDU_ACTION_INDEX_ICMPV6    = 6,    /**< [HB.GG] ICMPV6 action index*/
    CTC_L3PDU_ACTION_INDEX_MSDP      = 6,    /**< [GB.GG] MSDP action index*/
    CTC_L3PDU_ACTION_INDEX_IGMP      = 7,    /**< [HB] IGMP action index*/
    CTC_L3PDU_ACTION_INDEX_VRRP      = 8,    /**< [HB.GB.GG] VRRP action index*/
    CTC_L3PDU_ACTION_INDEX_BFD       = 9,    /**< [HB] BFD action index*/

    CTC_L3PDU_ACTION_INDEX_RSV_BEGIN = 10,   /**< [HB] The begin of reserve action index*/
    CTC_L3PDU_ACTION_INDEX_RSV_END   = 12,   /**< [HB] The end of reserve action index*/
    CTC_L3PDU_ACTION_INDEX_ARP_V2    = 13,   /**< [GB] ARP action index*/
    CTC_L3PDU_ACTION_INDEX_DHCP_V2   = 14,   /**< [GB] DHCP action index*/
    CTC_L3PDU_ACTION_INDEX_IPDA_V2   = 15,    /**< [GB] IPDA exception to cpu action index*/

    CTC_L3PDU_ACTION_INDEX_ARP       = 16,   /**< [GG] ARP action index*/
    CTC_L3PDU_ACTION_INDEX_DHCP      = 17,   /**< [GG] DHCP action index*/
    CTC_L3PDU_ACTION_INDEX_IPDA      = 63    /**< [GG] IPDA exception to cpu action index*/
};
typedef enum ctc_l3pdu_action_index_e ctc_l3pdu_action_index_t;

/**@} end of @defgroup  l3pdu L3PDU*/

/**@} end of @defgroup  pdu PDU */

#ifdef __cplusplus
}
#endif

#endif

