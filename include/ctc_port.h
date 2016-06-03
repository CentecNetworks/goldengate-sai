/**
 @file ctc_port.h

 @author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2011-11-9

 @version v2.0

 This file contains all port related data structure, enum, macro and proto.

*/

#ifndef _CTC_PORT_H
#define _CTC_PORT_H
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
 @defgroup port PORT
 @{
*/

#define CTC_PORT_PREFIX_PORT_MAC_NUM    2

/**
 @brief Port vlan tag ctl
*/
enum ctc_vlantag_ctl_e
{
    CTC_VLANCTL_ALLOW_ALL_PACKETS,                  /**< [HB.GB.GG] Allow all packet regardless of vlan tag*/
    CTC_VLANCTL_DROP_ALL_UNTAGGED,                  /**< [HB.GB.GG] Drop all untagged packet*/
    CTC_VLANCTL_DROP_ALL_TAGGED,                    /**< [HB.GB.GG] Drop all tagged packet*/
    CTC_VLANCTL_DROP_ALL,                           /**< [HB.GB.GG] Drop all packet*/
    CTC_VLANCTL_DROP_PACKET_WITHOUT_TWO_TAG,        /**< [HB.GB.GG] Drop packet without double tagged*/
    CTC_VLANCTL_DROP_ALL_PACKET_WITH_TWO_TAG,       /**< [HB.GB.GG] Drop packet with double tagged*/
    CTC_VLANCTL_DROP_ALL_SVLAN_TAG,                 /**< [HB.GB.GG] Drop packet with stag*/
    CTC_VLANCTL_DROP_ALL_NON_SVLAN_TAG,             /**< [HB.GB.GG] Drop packet without stag*/
    CTC_VLANCTL_DROP_ONLY_SVLAN_TAG,                /**< [HB.GB.GG] Drop packet with only stag*/
    CTC_VLANCTL_PERMIT_ONLY_SVLAN_TAG,              /**< [HB.GB.GG] Permit packet with only stag*/
    CTC_VLANCTL_DROP_ALL_CVLAN_TAG,                 /**< [HB.GB.GG] Drop packet with ctag*/
    CTC_VLANCTL_DROP_ALL_NON_CVLAN_TAG,             /**< [HB.GB.GG] Drop packet without ctag*/
    CTC_VLANCTL_DROP_ONLY_CVLAN_TAG,                /**< [HB.GB.GG] Drop packet with only ctag*/
    CTC_VLANCTL_PERMIT_ONLY_CVLAN_TAG,              /**< [HB.GB.GG] Permit packet with only ctag*/

    MAX_CTC_VLANTAG_CTL
};
typedef enum ctc_vlantag_ctl_e ctc_vlantag_ctl_t;

/**
 @brief Port dot1q type
*/
enum ctc_dot1q_type_e
{
    CTC_DOT1Q_TYPE_NONE,        /**< [HB.GB.GG] Packet transmit out with untag*/
    CTC_DOT1Q_TYPE_CVLAN,       /**< [HB.GB.GG] Packet transmit out with ctag*/
    CTC_DOT1Q_TYPE_SVLAN,       /**< [HB.GB.GG] Packet transmit out with stag*/
    CTC_DOT1Q_TYPE_BOTH         /**< [HB.GB.GG] Packet transmit out with double tag*/
};
typedef enum ctc_dot1q_type_e ctc_dot1q_type_t;

/**
 @brief Port speed type
*/
enum ctc_port_speed_e
{
    CTC_PORT_SPEED_1G,          /**< [HB.GB.GG] Port speed 1G mode*/
    CTC_PORT_SPEED_100M,        /**< [HB.GB.GG] Port speed 100M mode*/
    CTC_PORT_SPEED_10M,         /**< [HB.GB.GG] Port speed 10M mode*/
    CTC_PORT_SPEED_2G5,         /**< [HB.GB.GG] Port speed 2.5G mode*/
    CTC_PORT_SPEED_10G,         /**< [GB.GG] Port speed 10G mode*/
    CTC_PORT_SPEED_20G,         /**< [GG] Port speed 20G mode*/
    CTC_PORT_SPEED_40G,         /**< [GG] Port speed 40G mode*/
    CTC_PORT_SPEED_100G,        /**< [GG] Port speed 100G mode*/

    CTC_PORT_SPEED_MAX
};
typedef enum ctc_port_speed_e ctc_port_speed_t;
/**
 @brief define mac type of port
*/
enum ctc_port_mac_type_e
{
    CTC_PORT_MAC_GMAC,      /**< [HB.GB] mac type gmac, speed can be 1G 100M and 10M*/
    CTC_PORT_MAC_XGMAC,     /**< [HB.GB] mac type Xgmac, speed at 10G*/
    CTC_PORT_MAC_SGMAC,     /**< [HB.GB] mac type Sgmac, speed can be 13G*/
    CTC_PORT_MAC_CPUMAC,    /**< [HB.GB] mac type Cpumac, uplink to cpu*/
    CTC_PORT_MAC_MAX
};
typedef enum ctc_port_mac_type_e ctc_port_mac_type_t;

/**
 @brief Port max frame size type
*/
enum ctc_frame_size_e
{
    CTC_FRAME_SIZE_0,       /**< [HB.GG] Max/min frame size0*/
    CTC_FRAME_SIZE_1,       /**< [HB.GG] Max/min frame size1*/
    CTC_FRAME_SIZE_2,       /**< [GG] Max/min frame size2*/
    CTC_FRAME_SIZE_3,       /**< [GG] Max/min frame size3*/
    CTC_FRAME_SIZE_4,       /**< [GG] Max/min frame size4*/
    CTC_FRAME_SIZE_5,       /**< [GG] Max/min frame size5*/
    CTC_FRAME_SIZE_6,       /**< [GG] Max/min frame size6*/
    CTC_FRAME_SIZE_7,       /**< [GG] Max/min frame size7*/
    CTC_FRAME_SIZE_MAX
};
typedef enum ctc_frame_size_e ctc_frame_size_t;

/**
 @brief Port inter-packet gap size
*/
enum ctc_ipg_size_e
{
    CTC_IPG_SIZE_0,       /**< [HB.GB.GG] Ipg size0*/
    CTC_IPG_SIZE_1,       /**< [HB.GB.GG] Ipg size1*/
    CTC_IPG_SIZE_2,       /**< [HB.GB.GG] Ipg size2*/
    CTC_IPG_SIZE_3,       /**< [HB.GB.GG] Ipg size3*/
    CTC_IPG_SIZE_MAX
};
typedef enum ctc_ipg_size_e ctc_ipg_size_t;

/**
 @brief Port loopback action type
*/
enum ctc_port_lbk_type_e
{
    CTC_PORT_LBK_TYPE_SWAP_MAC,  /**< [HB.GB.GG] After port loopback, pakcet mac is swap*/
    CTC_PORT_LBK_TYPE_BYPASS,    /**< [HB.GB.GG] After port loopback, pakcet is no change*/
    CTC_PORT_LBK_TYPE_MAX
};
typedef enum ctc_port_lbk_type_e ctc_port_lbk_type_t;

/**
 @brief Port mux-demux type
*/
enum ctc_port_mux_demux_type_e
{
    CTC_PORT_TYPE_MUX,      /**< [HB.GB] Only internal port support mux,
                                         range <64-255>, 64 and 65 is reserved by sdk*/
    CTC_PORT_TYPE_DEMUX     /**< [HB.GB] Only network port support demux, range <0-51>*/
};
typedef enum ctc_port_mux_demux_type_e ctc_port_mux_demux_type_t;

/**
 @brief Port arp packet processing type
*/
enum ctc_port_arp_action_type_e
{
    CTC_PORT_ARP_ACTION_TYPE_FW_EX       = 0,    /**< [GB.GG] Normal forwarding and exception to CPU*/
    CTC_PORT_ARP_ACTION_TYPE_FW          = 1,    /**< [GB.GG] Normal forwarding, no exception*/
    CTC_PORT_ARP_ACTION_TYPE_EX          = 2,    /**< [GB.GG] Always exception to CPU, and discard*/
    CTC_PORT_ARP_ACTION_TYPE_DISCARD     = 3,    /**< [GB.GG] Discard*/
    CTC_PORT_ARP_ACTION_TYPE_MAX
};
typedef enum ctc_port_arp_action_type_e ctc_port_arp_action_type_t;

/**
 @brief Port dhcp packet processing type
*/
enum ctc_port_dhcp_action_type_e
{
    CTC_PORT_DHCP_ACTION_TYPE_FW_EX = 0,     /**< [GB.GG] Normal forwarding and exception to CPU*/
    CTC_PORT_DHCP_ACTION_TYPE_FW = 1,        /**< [GB.GG] Normal forwarding, no exception*/
    CTC_PORT_DHCP_ACTION_TYPE_EX = 2,        /**< [GB.GG] Always exception to CPU and discard*/
    CTC_PORT_DHCP_ACTION_TYPE_DISCARD = 3,   /**< [GB.GG] No exception and discard*/
    CTC_PORT_DHCP_ACTION_TYPE_MAX
};
typedef enum ctc_port_dhcp_action_type_e ctc_port_dhcp_action_type_t;

/**
 @brief Port rpf type
*/
enum ctc_port_rpf_type_e
{
    CTC_PORT_RPF_TYPE_STRICT = 0,   /**< [GB.GG] Strict*/
    CTC_PORT_RPF_TYPE_LOOSE = 1,    /**< [GB.GG] Loose*/
    CTC_PORT_RPF_TYPE_MAX
};
typedef enum ctc_port_rpf_type_e ctc_port_rpf_type_t;

/**
 @brief Port lbk mode
*/
enum ctc_port_lbk_mode_e
{
    CTC_PORT_LBK_MODE_CC,           /**< [GB.GG] crossconnect loopback*/
    CTC_PORT_LBK_MODE_EFM,          /**< [GB.GG] efm loopback*/
    CTC_PORT_LBK_MODE_TAP           /**< [GG] TAP*/
};
typedef enum ctc_port_lbk_mode_e ctc_port_lbk_mode_t;

/**
 @brief Port loopback parameter
*/
struct ctc_port_lbk_param_s
{
    ctc_port_lbk_type_t lbk_type;     /**< [HB.GB.GG] Port loopback type,
                                                      refer to ctc_port_lbk_type_t*/
    uint32 src_gport;                 /**< [HB.GB.GG] Souce port for loopback*/
    uint32 dst_gport;                 /**< [HB.GB.GG] Destination port for loopback. NOTE: when efm and crossconnect loopback,
                                           if dst_gport equal src_gport, indicat loopback to self, other port to this port is discard.
                                           when TAP, mac has been divided into groups. if use one mac as TAP dest,
                                           all mac included in the group which has the TAP dest mac won't do normal forwarding. */
    uint8   lbk_enable;               /**< [HB.GB.GG] If set, enable/disable loopback*/
    uint8   efm_to_cpu_en;            /**< [HB] If set, efm pdu will redirect to cpu*/
    uint8   efm_to_cpu_index;         /**< [HB] If set, efm pdu will redirect to cpu*/
    uint8   lbk_mode;                 /**< [GB.GG] refer to ctc_port_lbk_mode_t*/
    uint32  lbk_gport;                /**< [HB.GB.GG] [out] lbk_gport is internal port.
                                                         using for EFM OAM loopback,
                                                         when EFM OAM loopback enable,
                                                         packet from cpu to loopback port
                                                         should use the internal port*/

    uint8    rsv1[2];                 /**< rsv*/
};
typedef struct ctc_port_lbk_param_s ctc_port_lbk_param_t;

/**
 @brief Port scl key type
*/
enum ctc_port_scl_key_type_e
{
    CTC_SCL_KEY_TYPE_DISABLE,                /**< [GB] Disable scl key*/
    CTC_SCL_KEY_TYPE_VLAN_MAPPING_PORT,      /**< [GB] Scl vlan mapping using port*/
    CTC_SCL_KEY_TYPE_VLAN_MAPPING_CVID,      /**< [GB] Scl vlan mapping using cvlan id*/
    CTC_SCL_KEY_TYPE_VLAN_MAPPING_SVID,      /**< [GB] Scl vlan mapping using svlan id*/
    CTC_SCL_KEY_TYPE_VLAN_MAPPING_CVID_CCOS, /**< [GB] Scl vlan mapping using cvlan id and cos*/
    CTC_SCL_KEY_TYPE_VLAN_MAPPING_SVID_SCOS, /**< [GB] Scl vlan mapping using svlan id and cos*/
    CTC_SCL_KEY_TYPE_VLAN_MAPPING_DVID,      /**< [GB] Scl vlan mapping using both svlan and cvlan id*/

    CTC_SCL_KEY_TYPE_VLAN_CLASS_MAC_SA,      /**< [GB] Scl vlan class using macsa*/
    CTC_SCL_KEY_TYPE_VLAN_CLASS_MAC_DA,      /**< [GB] Scl vlan class using macda*/
    CTC_SCL_KEY_TYPE_VLAN_CLASS_IPV4,        /**< [GB] Scl vlan class using ipv4 addr*/
    CTC_SCL_KEY_TYPE_VLAN_CLASS_IPV6,        /**< [GB] Scl vlan class using ipv6 addr*/

    CTC_SCL_KEY_TYPE_IPSG_PORT_MAC,          /**< [GB] Scl ip source guard check mode:
                                                          CTC_SECURITY_BINDING_TYPE_IP_MAC_VLAN/
                                                          CTC_SECURITY_BINDING_TYPE_MAC/
                                                          CTC_SECURITY_BINDING_TYPE_MAC_VLAN*/
    CTC_SCL_KEY_TYPE_IPSG_PORT_IP,           /**< [GB] Scl ip source guard check mode:
                                                          CTC_SECURITY_BINDING_TYPE_IP/
                                                          CTC_SECURITY_BINDING_TYPE_IP_VLAN/
                                                          CTC_SECURITY_BINDING_TYPE_IP_MAC*/
    CTC_SCL_KEY_TYPE_IPSG_IPV6,              /**< [GB] Scl ip source guard check mode:
                                                          CTC_SECURITY_BINDING_TYPE_IPV6_MAC*/

    CTC_SCL_KEY_TYPE_IPV4_TUNNEL,            /**< [GB] Scl tunnel identify for IPv4/IPv6 in IPv4
                                                          and GRE with/without GRE key*/
    CTC_SCL_KEY_TYPE_IPV4_TUNNEL_AUTO,       /**< [GG] Scl tunnel identify for IPv4/IPv6 in IPv4,
                                                          6to4 and ISATAP*/
    CTC_SCL_KEY_TYPE_IPV6_TUNNEL,            /**< [GB] Scl tunnel identify for any in IPv6*/
    CTC_SCL_KEY_TYPE_IPV4_TUNNEL_WITH_RPF,   /**< [GB] Scl tunnel identiry for IPv4/IPv6 in IPv4,
                                                          GRE with/without GRE key tunnel, with outer head RPF check*/
    CTC_SCL_KEY_TYPE_IPV6_TUNNEL_WITH_RPF,   /**< [GB] Scl tunnel idenitfy for any in IPv6 tunnel,
                                                          with outer head RPF check*/
    CTC_SCL_KET_TYPE_NVGRE,                  /**< [GG] Scl tunnel identify for NvGre*/
    CTC_SCL_KET_TYPE_VXLAN,                  /**< [GG] Scl tunnel identify for Vxlan*/

    CTC_SCL_KEY_TYPE_MAX
};
typedef enum ctc_port_scl_key_type_e ctc_port_scl_key_type_t;

/**
 @brief Port vlan domain type
*/
enum ctc_port_vlan_domain_type_e
{
    CTC_PORT_VLAN_DOMAIN_SVLAN                = 0,    /**< [GB.GG] Svlan domain*/
    CTC_PORT_VLAN_DOMAIN_CVLAN                = 1,    /**< [GB.GG] Cvlan domain*/
    CTC_PORT_VLAN_DOMAIN_MAX
};
typedef enum ctc_port_vlan_domain_type_e ctc_port_vlan_domain_type_t;

/*
 @brief Port raw packet type
*/
enum ctc_port_raw_packet_e
{
    CTC_PORT_RAW_PKT_NONE,          /**< [GB.GG] Raw packet parser disable*/
    CTC_PORT_RAW_PKT_ETHERNET,      /**< [GB.GG] Port parser ethernet raw packet*/
    CTC_PORT_RAW_PKT_IPV4,          /**< [GB.GG] Port only parser ipv4 raw packet*/
    CTC_PORT_RAW_PKT_IPV6,          /**< [GB.GG] Port only parser ipv6 raw packet*/
    CTC_PORT_RAW_PKT_MAX
};
typedef enum ctc_port_raw_packet_e ctc_port_raw_packet_t;

/*
 @brief Port restriction type: private vlan, blocking based on port and port isolation
*/
enum ctc_port_restriction_mode_e
{
    CTC_PORT_RESTRICTION_DISABLE = 0,               /**< [GB.GG] Private vlan, blocking and port isolation is disable on port*/
    CTC_PORT_RESTRICTION_PVLAN,                     /**< [GB.GG] Private vlan is enabled on port*/
    CTC_PORT_RESTRICTION_PORT_BLOCKING,             /**< [HB.GB.GG] Blocking based on port is enabled on port*/
    CTC_PORT_RESTRICTION_PORT_ISOLATION             /**< [HB.GB.GG] Port isolation is enabled on port*/
};
typedef enum ctc_port_restriction_mode_e ctc_port_restriction_mode_t;

/*
 @brief Port private vlan type
*/
enum ctc_port_pvlan_type_e
{
    CTC_PORT_PVLAN_NONE  = 0,     /**< [GB.GG] Port is none port*/
    CTC_PORT_PVLAN_PROMISCUOUS,   /**< [GB.GG] Port is promiscuous port,isolated id must not be configured*/
    CTC_PORT_PVLAN_ISOLATED,      /**< [GB.GG] Port is isolated port,isolated id must not be configured*/
    CTC_PORT_PVLAN_COMMUNITY      /**< [GB.GG] Port is community port,isolated id must be configured*/
};
typedef enum ctc_port_pvlan_type_e ctc_port_pvlan_type_t;

/*
 @brief Port isolation packet isolated type
*/
enum ctc_port_isolation_pkt_type_e
{
    CTC_PORT_ISOLATION_ALL                 = 0x0000,        /**< [GB.GG] All packet will be isolated*/
    CTC_PORT_ISOLATION_UNKNOW_UCAST        = 0x0001,        /**< [GB.GG] Unknown ucast type packet will be isolated*/
    CTC_PORT_ISOLATION_UNKNOW_MCAST        = 0x0002,        /**< [GB.GG] Unknown mcast type packet will be isolated*/
    CTC_PORT_ISOLATION_KNOW_UCAST          = 0x0004,        /**< [GG] Known ucast type packet will be isolated*/
    CTC_PORT_ISOLATION_KNOW_MCAST          = 0x0008,        /**< [GB.GG] Known mcast type packet will be isolated*/
    CTC_PORT_ISOLATION_BCAST               = 0x0010         /**< [GB.GG] Bcast type packet will be isolated*/
};
typedef enum ctc_port_isolation_pkt_type_e ctc_port_isolation_pkt_type_t;

/*
 @brief Port blocking packet blocked type
*/
enum ctc_port_blocking_pkt_type_e
{
    CTC_PORT_BLOCKING_UNKNOW_UCAST        = 0x0001,        /**< [HB.GB.GG] Unknown ucast type packet will be blocked*/
    CTC_PORT_BLOCKING_UNKNOW_MCAST        = 0x0002,        /**< [HB.GB.GG] Unknown mcast type packet will be blocked*/
    CTC_PORT_BLOCKING_KNOW_UCAST          = 0x0004,        /**< [GG] Known ucast type packet will be blocked*/
    CTC_PORT_BLOCKING_KNOW_MCAST          = 0x0008,        /**< [GB.GG] Known mcast type packet will be blocked*/
    CTC_PORT_BLOCKING_BCAST               = 0x0010         /**< [GB.GG] Bcast type packet will be blocked*/
};
typedef enum ctc_port_blocking_pkt_type_e ctc_port_blocking_pkt_type_t;

/**
  @brief Port restriction parameter: private vlan, port isolation, blocking based on port
*/
struct ctc_port_restriction_s
{
    ctc_port_restriction_mode_t mode;                     /**< [GB.GG] Restriction mode enable on port, see ctc_port_restriction_type_t*/
    ctc_direction_t dir;                                  /**< [GB.GG] Direction*/
    uint16 isolate_group;                                 /**< [GG]    Isolation group id*/
    uint16 isolated_id;                                   /**< [GB.GG] If port is community port in private vlan, isolated id <0-15>
                                                                       If port isolation is enabled on port, isolated id <0-31>*/
    uint16 type;                                          /**< [GB.GG] If private vlan is enabled on port,
                                                                       set pvlan type on port(see ctc_port_pvlan_type_e);
                                                                       if port isolation is enabled on port, set isolated id,
                                                                       and if the dir is egress,
                                                                       set isolation packet type on port(see ctc_port_isolation_pkt_type_e)
                                                                       if blocking based on port is enabled on port,
                                                                       set blocking packet type on port(see ctc_port_blocking_pkt_type_e)*/
};
typedef struct ctc_port_restriction_s ctc_port_restriction_t;

/**
  @brief Port untag port default vlan type
*/
enum ctc_port_untag_pvid_type_e
{
    CTC_PORT_UNTAG_PVID_TYPE_NONE,                       /**< [HB.GB.GG] Do nothing for port default svlan or cvlan id*/
    CTC_PORT_UNTAG_PVID_TYPE_SVLAN,                      /**< [HB.GB.GG] Untag port default svlan id*/
    CTC_PORT_UNTAG_PVID_TYPE_CVLAN,                      /**< [HB.GB.GG] Untag port default cvlan id*/
    CTC_PORT_UNTAG_PVID_TYPE_MAX
};
typedef enum ctc_port_untag_pvid_type_e ctc_port_untag_pvid_type_t;

/**
  @brief Port 802.3ap port ability flags
*/
enum ctc_port_cl73_ability_e
{
    CTC_PORT_CL73_1000BASE_KX     = (1 << 0 ),  /**< [GG] 1000Base-KX ability */
    CTC_PORT_CL73_10GBASE_KX4     = (1 << 1 ),  /**< [GG] 10GBase-KX4 ability */
    CTC_PORT_CL73_10GBASE_KR      = (1 << 2 ),  /**< [GG] 10GBase-KR ability */
    CTC_PORT_CL73_40GBASE_KR4     = (1 << 3 ),  /**< [GG] 40GBase-KR4 ability */
    CTC_PORT_CL73_40GBASE_CR4     = (1 << 4 ),  /**< [GG] 40GBase-CR4 ability */
    CTC_PORT_CL73_100GBASE_CR10   = (1 << 5 ),  /**< [GG] 100GBase-CR10 ability */
    CTC_PORT_CL73_100GBASE_KP4    = (1 << 6 ),  /**< [GG] 100GBase-KP4 ability */
    CTC_PORT_CL73_100GBASE_KR4    = (1 << 7 ),  /**< [GG] 100GBase-KR4 ability */
    CTC_PORT_CL73_100GBASE_CR4    = (1 << 8 ),  /**< [GG] 100GBase-CR4 ability */
    CTC_PORT_CL73_FEC_ABILITY     = (1 << 9 ),  /**< [GG] local device support FEC */
    CTC_PORT_CL73_FEC_REQUESTED   = (1 << 10),  /**< [GG] request remote device enable FEC */
    CTC_PORT_CL73_MAX
};
typedef enum ctc_port_cl73_ability_e ctc_port_cl73_ability_t;

enum ctc_port_auto_neg_mode_e
{
    CTC_PORT_AUTO_NEG_MODE_1000BASE_X,            /**< [GB.GG] 1000BASE-X Auto-neg mode */
    CTC_PORT_AUTO_NEG_MODE_SGMII_SLAVER,          /**< [GB.GG] SGMII slaver Auto-neg mode */
    CTC_PORT_AUTO_NEG_MODE_MAX_MODE
};
typedef enum ctc_port_auto_neg_mode_e ctc_port_auto_neg_mode_t;

/**
  @brief Port property flags
*/
enum ctc_port_property_e
{
    /**< genernal property */
    CTC_PORT_PROP_MAC_EN,                         /**< [GB.GG] Port mac enable*/
    CTC_PORT_PROP_PORT_EN,                        /**< [GB.GG] Port whether the port is enable,
                                                               the following properties will be set:
                                                               CTC_PORT_PROP_TRANSMIT_EN,
                                                               CTC_PORT_PROP_RECEIVE_EN and CTC_PORT_PROP_BRIDGE_EN*/

    CTC_PORT_PROP_VLAN_CTL,                       /**< [GB.GG] Port's vlan tag control mode*/
    CTC_PORT_PROP_DEFAULT_VLAN,                   /**< [GB.GG] Default vlan id, the following properties will be set:
                                                               untag_default_svlan = 1,untag_default_vlanId = 1,
                                                               DsPhyPortExt_DefaultVlanId_f and DsDestPort_DefaultVlanId_f*/
    CTC_PORT_PROP_UNTAG_PVID_TYPE,                /**< [GB.GG] Untag default vlan type. refer CTC_PORT_UNTAG_PVID_TYPE_XXX */
    CTC_PORT_PROP_VLAN_DOMAIN,                    /**< [GB.GG] vlan domain of the port */

    CTC_PORT_PROP_PROTOCOL_VLAN_EN,               /**< [GB.GG] protocol vlan enable*/
    CTC_PORT_PROP_QOS_POLICY,                     /**< [HB.GB.GG] QOS policy*/
    CTC_PORT_PROP_DEFAULT_PCP,                    /**< [HB.GB.GG] default PCP*/
    CTC_PORT_PROP_DEFAULT_DEI,                    /**< [HB.GB.GG] default DEI*/
    CTC_PORT_PROP_SCL_USE_DEFAULT_LOOKUP,         /**< [GB.GG] SCL default vlan lookup*/
    CTC_PORT_PROP_SCL_IPV4_LOOKUP_EN,             /**< [GB] SCL ipv4 lookup enable*/
    CTC_PORT_PROP_SCL_IPV6_LOOKUP_EN,             /**< [GB] SCL ipv6 lookup enable*/
    CTC_PORT_PROP_SCL_FORCE_IPV4_TO_MAC,          /**< [GB] force Ipv4 packet go against MAC SCL entry*/
    CTC_PORT_PROP_SCL_FORCE_IPV6_TO_MAC,          /**< [GB] force Ipv6 packet go against MAC SCL entry*/
    CTC_PORT_PROP_NVGRE_MCAST_NO_DECAP,           /**< [GG] NvGRE mcast packet do not decapsulation*/
    CTC_PORT_PROP_VXLAN_MCAST_NO_DECAP,           /**< [GG] VxLAN mcast packet do not decapsulation*/
    CTC_PORT_PROP_PTP_EN,                         /**< [GB.GG] PTP enable*/

    CTC_PORT_PROP_SPEED,                          /**< [GB.GG] port speed*/
    CTC_PORT_PROP_MAX_FRAME_SIZE,                 /**< [GB.GG] max frame size*/
    CTC_PORT_PROP_MIN_FRAME_SIZE,                 /**< [GB.GG] min frame size*/
    CTC_PORT_PROP_PREAMBLE,                       /**< [GB.GG] preamble value*/
    CTC_PORT_PROP_PADING_EN,                      /**< [GB.GG] pading enable*/
    CTC_PORT_PROP_STRETCH_MODE_EN,                /**< [GB] port stretch mode enable*/
    CTC_PORT_PROP_IPG,                            /**< [GB.GG] ipg index per port*/
    CTC_PORT_PROP_RX_PAUSE_TYPE,                  /**< [GB.GG] set port rx pause type, normal or pfc*/
    CTC_PORT_PROP_MAC_TS_EN,                      /**< [GB] Enbale Mac for append time-stamp */
    CTC_PORT_PROP_ERROR_CHECK,                    /**< [GG] Mac CRC check, 1:enable, 0:disable */

    CTC_PORT_PROP_TRANSMIT_EN,                    /**< [GB.GG] Tx enbale*/
    CTC_PORT_PROP_RECEIVE_EN,                     /**< [GB.GG] Rx enbale*/
    CTC_PORT_PROP_BRIDGE_EN,                      /**< [GB.GG] bridge enbale in both direction*/
    CTC_PORT_PROP_LEARNING_EN,                    /**< [GB.GG] learning enable*/
    CTC_PORT_PROP_PRIORITY_TAG_EN,                /**< [GB.GG] priority tag enable*/

    CTC_PORT_PROP_CROSS_CONNECT_EN,               /**< [GB.GG] port cross connect*/
    CTC_PORT_PROP_DOT1Q_TYPE,                     /**< [GB.GG] dot1q type*/
    CTC_PORT_PROP_USE_OUTER_TTL,                  /**< [GB.GG] use outer ttl in case of tunnel*/
    CTC_PORT_PROP_DISCARD_NON_TRIL_PKT,           /**< [GB.GG] discard non-trill pkg enbale*/
    CTC_PORT_PROP_DISCARD_TRIL_PKT,               /**< [GB.GG] discard trill pkg enbale*/
    CTC_PORT_PROP_SRC_DISCARD_EN,                 /**< [GB.GG] port whether the srcdiscard is enable*/
    CTC_PORT_PROP_PORT_CHECK_EN,                  /**< [GB.GG] port port check enable*/
    CTC_PORT_PROP_RAW_PKT_TYPE,                   /**< [GB.GG] raw packet type*/

    CTC_PORT_PROP_REFLECTIVE_BRIDGE_EN,           /**< [GB.GG] bridge to the same port enable*/
    CTC_PORT_PROP_HW_LEARN_EN,                    /**< [GB.GG] hw learning enable*/
    CTC_PORT_PROP_TRILL_EN,                       /**< [GB.GG] trill enable*/
    CTC_PORT_PROP_TRILL_MCAST_DECAP_EN,           /**< [GG] trill mcast decap when enable*/
    CTC_PORT_PROP_FCOE_EN,                        /**< [GB.GG] FCOE enable*/
    CTC_PORT_PROP_FCOE_RPF_EN,                    /**< [GB.GG] FCOE RPF enable*/
    CTC_PORT_PROP_FCMAP,                          /**< [GG] fcoe FCMAP(0x0EFC00-0x0EFCFF), default is 0x0EFC00 */
    CTC_PORT_PROP_REPLACE_STAG_COS,               /**< [HB.GB.GG] the STAG COS field is replaced by the classified COS result*/
    CTC_PORT_PROP_REPLACE_STAG_TPID,              /**< [GG] the STAG TPID is replaced by the vlanXlate TPID result*/
    CTC_PORT_PROP_REPLACE_CTAG_COS,               /**< [GB.GG] the STAG COS field is replaced by the classified COS result*/
    CTC_PORT_PROP_REPLACE_DSCP_EN,                /**< [HB.GB.GG] the dscp field is replaced by the classified qos result*/

    CTC_PORT_PROP_L3PDU_ARP_ACTION,               /**< [GB.GG] l3PDU arp action*/
    CTC_PORT_PROP_L3PDU_DHCP_ACTION,              /**< [GB.GG] l3PDU dhcp action*/
    CTC_PORT_PROP_TUNNEL_RPF_CHECK,               /**< [GB.GG] tunnel RPF check enable*/
    CTC_PORT_PROP_RPF_TYPE,                       /**< [GB.GG] RPF type, refer to ctc_port_rpf_type_t */
    CTC_PORT_PROP_IS_LEAF,                        /**< [GB.GG] the port connect with a leaf node*/
    CTC_PORT_PROP_PKT_TAG_HIGH_PRIORITY,          /**< [GB.GG] Packet tag take precedence over all*/
    CTC_PORT_PROP_ROUTE_EN,                       /**< [GB.GG] Enbale route on port */

    CTC_PORT_PROP_AUTO_NEG_EN,                    /**< [GB.GG] Enbale Auto-neg on port */
    CTC_PORT_PROP_AUTO_NEG_MODE,                  /**< [GB.GG] Config Auto-neg mode on port */
    CTC_PORT_PROP_CL73_ABILITY,                   /**< [GG] cfg cl73 ability */
    CTC_PORT_PROP_FEC_EN,                         /**< [GG] Enable FEC */
    CTC_PORT_PROP_LINK_INTRRUPT_EN,               /**< [GB.GG] Enbale Mac PCS link interrupt */

    CTC_PORT_PROP_LINKSCAN_EN,                    /**< [GB.GG] Enable linkscan funciton on port*/
    CTC_PORT_PROP_APS_FAILOVER_EN,                /**< [GB.GG] Enable Aps-failover on port*/
    CTC_PORT_PROP_LINKAGG_FAILOVER_EN,            /**< [GB.GG] Enable Linkagg-failover on port*/
    CTC_PORT_PROP_SCL_HASH_FIELD_SEL_ID,          /**< [GG] SCL flow hash field sel id */
    CTC_PORT_PROP_APS_SELECT_GRP_ID,              /**< [GG] The aps select group id, 0xFFFFFFFF means disable aps select*/
    CTC_PORT_PROP_APS_SELECT_WORKING,             /**< [GG] Indicate the flow is working path or protecting path*/

    CTC_PORT_PROP_SNOOPING_PARSER,                /**< [GG] Enable parser tunnel payload even no tunnel decap */
    CTC_PORT_PROP_FLOW_LKUP_BY_OUTER_HEAD,         /**< [GG] If set,indicate tunnel packet will use outer header to do ACL/IPFIX flow lookup */
    CTC_PORT_PROP_EXTERN_ENABLE,                  /**< [GG] When want to use pkt inner infor(nvgre/vxlan), can use outer l4 info as key */
    CTC_PORT_PROP_NVGRE_ENABLE,                   /**< [GG] Enable nvgre */

    CTC_PORT_PROP_METADATA_OVERWRITE_PORT,        /**< [GG] Enable metadata overwrite port */
    CTC_PORT_PROP_METADATA_OVERWRITE_UDF,         /**< [GG] Enable metadata overwrite udf */

    CTC_PORT_PROP_SIGNAL_DETECT,                  /**< [GG] Signal detect on port */

    CTC_PORT_PROP_SRC_MISMATCH_EXCEPTION_EN,      /**< [GG] Enable src mismatch exception */
    CTC_PORT_PROP_EFD_EN,                         /**< [GG] Enable EFD */
    CTC_PORT_PROP_EEE_EN,                         /**< [GB] Enable eee on port*/

    CTC_PORT_PROP_LOGIC_PORT,                     /**< [GB.GG] Port logic port value. if set 0xFFFF, mean logic port disable */
    CTC_PORT_PROP_ADD_DEFAULT_VLAN_DIS,           /**< [GB.GG] Will not add default vlan for untagged packet */
    MAX_CTC_PORT_PROP_NUM
};
typedef enum ctc_port_property_e  ctc_port_property_t;

/**
  @brief Port property flags with direction
*/
enum ctc_port_direction_property_e
{
    CTC_PORT_DIR_PROP_VLAN_FILTER_EN,                 /**< [GB.GG] vlan filter enable*/
    CTC_PORT_DIR_PROP_RANDOM_LOG_EN,                  /**< [GB.GG] random log enable*/
    CTC_PORT_DIR_PROP_RANDOM_LOG_PERCENT,             /**< [GB.GG] percetn of random threshold*/
    CTC_PORT_DIR_PROP_RANDOM_LOG_RATE,                /**< [GB.GG] rate of random threshold*/

    CTC_PORT_DIR_PROP_QOS_DOMAIN,                     /**< [HB.GB] QOS domain*/
    CTC_PORT_DIR_PROP_QOS_COS_DOMAIN,                 /**< [DT2] QOS COS domain*/
    CTC_PORT_DIR_PROP_QOS_DSCP_DOMAIN,                /**< [DT2] QOS DSCP domain*/

    CTC_PORT_DIR_PROP_PORT_POLICER_VALID,             /**< [GB.GG] policer valid*/
    CTC_PORT_DIR_PROP_STAG_TPID_INDEX,                /**< [GB.GG] stag TPID index*/

    CTC_PORT_DIR_PROP_ACL_EN,                         /**< [HB.GB.GG] port acl enable, refer CTC_ACL_EN_XXX */
    CTC_PORT_DIR_PROP_ACL_CLASSID,                    /**< [GB.GG] port acl classid */
    CTC_PORT_DIR_PROP_ACL_CLASSID_0,                  /**< [HB.GG] port acl0 classid */
    CTC_PORT_DIR_PROP_ACL_CLASSID_1,                  /**< [HB.GG] port acl1 classid */
    CTC_PORT_DIR_PROP_ACL_CLASSID_2,                  /**< [GG] port acl2 classid */
    CTC_PORT_DIR_PROP_ACL_CLASSID_3,                  /**< [GG] port acl3 classid */
    CTC_PORT_DIR_PROP_ACL_IPV4_FORCE_MAC,             /**< [HB.GB] ipv4-packet force use mac-key */
    CTC_PORT_DIR_PROP_ACL_IPV6_FORCE_MAC,             /**< [HB.GB] ipv6-packet force use mac-key */
    CTC_PORT_DIR_PROP_ACL_FORCE_USE_IPV6,             /**< [GB] force use ipv6 key */
    CTC_PORT_DIR_PROP_ACL_USE_CLASSID,                /**< [GB.GG] use acl classid not bitmap*/
    CTC_PORT_DIR_PROP_ACL_HASH_FIELD_SEL_ID,          /**< [GG] hash field sel id */
    CTC_PORT_DIR_PROP_SERVICE_ACL_EN,                 /**< [GB.GG] service acl enable */
    CTC_PORT_DIR_PROP_ACL_HASH_LKUP_TYPE,             /**< [GG] acl hash type. refer CTC_ACL_HASH_LKUP_TYPE_XXX */
    CTC_PORT_DIR_PROP_ACL_TCAM_LKUP_TYPE_0,           /**< [GG] acl tcam type. refer CTC_ACL_TCAM_LKUP_TYPE_XXX */
    CTC_PORT_DIR_PROP_ACL_TCAM_LKUP_TYPE_1,           /**< [GG] acl tcam type. refer CTC_ACL_TCAM_LKUP_TYPE_XXX */
    CTC_PORT_DIR_PROP_ACL_TCAM_LKUP_TYPE_2,           /**< [GG] acl tcam type. refer CTC_ACL_TCAM_LKUP_TYPE_XXX */
    CTC_PORT_DIR_PROP_ACL_TCAM_LKUP_TYPE_3,           /**< [GG] acl tcam type. refer CTC_ACL_TCAM_LKUP_TYPE_XXX */
    CTC_PORT_DIR_PROP_ACL_USE_MAPPED_VLAN,            /**< [GG] acl use mapped vlan*/

    MAX_CTC_PORT_DIR_PROP_NUM
};
typedef enum ctc_port_direction_property_e ctc_port_direction_property_t;

/**
  @brief Port mac prefix type
*/
enum ctc_port_mac_prefix_type_e
{
    CTC_PORT_MAC_PREFIX_MAC_NONE    = 0x00,         /**< [HB.GB] none */
    CTC_PORT_MAC_PREFIX_MAC_0       = 0x01,         /**< [HB.GB] port mac prefix 0 */
    CTC_PORT_MAC_PREFIX_MAC_1       = 0x02,         /**< [GB] port mac prefix 1 */
    CTC_PORT_MAC_PREFIX_MAC_ALL     = 0x03,         /**< [GB] port mac prefix 0 and prefix 1 */
    CTC_PORT_MAC_PREFIX_48BIT       = 0x04          /**< [GG] port mac 48bit */
};
typedef enum ctc_port_mac_prefix_type_e  ctc_port_mac_prefix_type_t;

/**
  @brief Port mac prefix parameter
*/
struct ctc_port_mac_prefix_s
{
    uint8       prefix_type;                              /**< [GB] MAC Prefix bitmap, ctc_port_mac_prefix_type_t*/
    mac_addr_t  port_mac[CTC_PORT_PREFIX_PORT_MAC_NUM];   /**< [HB.GB] Port MAC, high 40 bit. for GB, high 32bit must same, for GG only port_mac array0 is valid */
};
typedef struct ctc_port_mac_prefix_s ctc_port_mac_prefix_t;

/**
  @brief Port mac postfix parameter
*/
struct ctc_port_mac_postfix_s
{
    uint8       prefix_type;                /**< [GB] MAC Prefix type, CTC_PORT_MAC_PREFIX_MAC_0: prefix mac0, CTC_PORT_MAC_PREFIX_MAC_1: prefix mac1*/
    uint8       low_8bits_mac;              /**< [HB.GB] Port MAC low 8bit*/
    mac_addr_t  port_mac;                   /**< [GG] Port MAC 48bit */
};
typedef struct ctc_port_mac_postfix_s ctc_port_mac_postfix_t;

#define CTC_PORT_LINK_STATUS_1G     0x00000001
#define CTC_PORT_LINK_STATUS_XG     0x00000002

/**
  @brief Port link status
*/
struct ctc_port_link_status_s
{
    uint32  status_1g[2];       /*[GB] link status of 1G port */
    uint32  status_xg[1];       /*[GB] link status of XG port */
    uint32  gport;              /*[GB][GG] link change Gport Id */
    uint16  rsv;
};
typedef struct ctc_port_link_status_s ctc_port_link_status_t;

/**
  @brief Port fc property parameter
*/
struct ctc_port_fc_prop_s
{
    uint32 gport;    /**< [HB.GB.GG] Global port of flow control */
    uint8  priority_class; /**< [GG] Pfc priority class <0-7>, value should be priority/8, priority refer to qos priority */
    uint8  is_pfc;   /**< [GB.GG] If set, Priority based flow contol else port base flow control */

    uint8  pfc_class;  /**< [GG] PFC frame class value <0-7> */
    uint8  dir;        /**< [HB.GB.GG] Rx or Tx pause frame */
    uint8  enable;     /**< [HB.GB.GG] enable/disable flow control */
    uint8  rsv;
};
typedef struct ctc_port_fc_prop_s ctc_port_fc_prop_t;

/**
  @brief Port igs scl hash type
*/
enum ctc_port_igs_scl_hash_type_e
{
    CTC_PORT_IGS_SCL_HASH_TYPE_DISABLE,            /**< [GB.GG] disable igs scl hash*/
    CTC_PORT_IGS_SCL_HASH_TYPE_PORT_2VLAN,         /**< [GB.GG] igs scl port and double vlan id hash type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_PORT_SVLAN,         /**< [GB.GG] igs scl port and svlan id hash type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_PORT_CVLAN,         /**< [GB.GG] igs scl port and cvlan id hash type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_PORT_SVLAN_COS,     /**< [GB.GG] igs scl port, svlan id and cos hash type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_PORT_CVLAN_COS,     /**< [GB.GG] igs scl port, cvlan id and cos hash type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_MAC_SA,             /**< [GB.GG] igs scl macsa hash type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_PORT_MAC_SA,        /**< [GB.GG] igs scl port and macsa hash type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_MAC_DA,             /**< [GB.GG] igs scl macda hash type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_PORT_MAC_DA,        /**< [GB.GG] igs scl port and macda hash type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_IP_SA,              /**< [GB.GG] igs scl ipsa hash type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_PORT_IP_SA,         /**< [GB.GG] igs scl port and ipsa hash type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_PORT,               /**< [GB.GG] igs scl port hash type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_L2,                 /**< [GB.GG] igs scl l2 hash key, include macda, macsa, svlan id/cos/cfi and ether type*/
    CTC_PORT_IGS_SCL_HASH_TYPE_TUNNEL,             /**< [GB.GG] igs scl for all IPv4 manual tunnel which both IPDA IPSA is lookuped, such as IPv4/IPv6 in IPv4, GRE with/without GRE type in IPv4 tunnel*/
    CTC_PORT_IGS_SCL_HASH_TYPE_TUNNEL_RPF,         /**< [GB.GG] igs scl for all IPv4 manual tunnel do outer head RPF check, must used in scl id 1*/
    CTC_PORT_IGS_SCL_HASH_TYPE_IPV4_TUNNEL_AUTO,   /**< [GG] igs scl for IPv4/IPv6 in IPv4, 6to4, ISATAP tunnel*/
    CTC_PORT_IGS_SCL_HASH_TYPE_NVGRE,              /**< [GG] igs scl for NvGre tunnel*/
    CTC_PORT_IGS_SCL_HASH_TYPE_VXLAN,              /**< [GG] igs scl for VxLan tunnel*/
    CTC_PORT_IGS_SCL_HASH_TYPE_TRILL,              /**< [GG] igs scl for TRILL tunnel or check*/
    CTC_PORT_IGS_SCL_HASH_TYPE_CAPWAP,             /**< [DT2] igs scl for capwap tunnel*/
    CTC_PORT_IGS_SCL_HASH_TYPE_MAX
};
typedef enum ctc_port_igs_scl_hash_type_e ctc_port_igs_scl_hash_type_t;

/**
  @brief Port egs scl hash type
*/
enum ctc_port_egs_scl_hash_type_e
{
    CTC_PORT_EGS_SCL_HASH_TYPE_DISABLE,            /**< [GB.GG] disable egs scl hash*/
    CTC_PORT_EGS_SCL_HASH_TYPE_PORT_2VLAN,         /**< [GB.GG] egs scl port and double vlan id hash type*/
    CTC_PORT_EGS_SCL_HASH_TYPE_PORT_SVLAN,         /**< [GB.GG] egs scl port and svlan id hash type*/
    CTC_PORT_EGS_SCL_HASH_TYPE_PORT_CVLAN,         /**< [GB.GG] egs scl port and cvlan id hash type*/
    CTC_PORT_EGS_SCL_HASH_TYPE_PORT_SVLAN_COS,     /**< [GB.GG] egs scl port, svlan id and cos hash type*/
    CTC_PORT_EGS_SCL_HASH_TYPE_PORT_CVLAN_COS,     /**< [GB.GG] egs scl port, cvlan id and cos hash type*/
    CTC_PORT_EGS_SCL_HASH_TYPE_PORT,               /**< [GB.GG] egs scl port hash type*/
    CTC_PORT_EGS_SCL_HASH_TYPE_MAX
};
typedef enum ctc_port_egs_scl_hash_type_e ctc_port_egs_scl_hash_type_t;

/**
  @brief Port igs scl tcam type
*/
enum ctc_port_igs_scl_tcam_type_e
{
    CTC_PORT_IGS_SCL_TCAM_TYPE_DISABLE,            /**< [GB.GG.DT2] disable igs scl tcam*/
    CTC_PORT_IGS_SCL_TCAM_TYPE_MAC,                /**< [GB.GG.DT2] igs scl mac tcam type*/
    CTC_PORT_IGS_SCL_TCAM_TYPE_IP,                 /**< [GB.GG.DT2] (GG)auto adujst for ipv6. for other l3-type packet, including l3,mac info*/
    CTC_PORT_IGS_SCL_TCAM_TYPE_IP_SINGLE,          /**< [GG.DT2] (GG)auto adujst for ipv6. for other l3-type packet, only including l3 info*/
    CTC_PORT_IGS_SCL_TCAM_TYPE_VLAN,               /**< [GB.GG] igs scl tcam type*/
    CTC_PORT_IGS_SCL_TCAM_TYPE_TUNNEL,             /**< [GB] for all IPv4 auto tunnel which IPSA do not care, such as ISATAP/6TO4 and anyInIPv6 tunnel*/
    CTC_PORT_IGS_SCL_TCAM_TYPE_TUNNEL_RPF,         /**< [GB] for all IPv4 auto tunnel and anyInIPv6 tunnel do outer head RPF check, must used in scl id 1*/
    CTC_PORT_IGS_SCL_TCAM_TYPE_RESOLVE_CONFLICT,  /**< [DT2] resolve scl hash confilct*/
    CTC_PORT_IGS_SCL_TCAM_TYPE_MAX
};
typedef enum ctc_port_igs_scl_tcam_type_e ctc_port_igs_scl_tcam_type_t;

/**
  @brief Port igs scl action type
*/
enum ctc_port_scl_action_type_e
{
    CTC_PORT_SCL_ACTION_TYPE_SCL,                  /**< [GG] scl action type scl*/
    CTC_PORT_SCL_ACTION_TYPE_FLOW,                 /**< [GG] scl action type flow*/
    CTC_PORT_SCL_ACTION_TYPE_TUNNEL,               /**< [GG] scl action type tunnel*/
    CTC_PORT_SCL_ACTION_TYPE_MAX
};
typedef enum ctc_port_scl_action_type_e ctc_port_scl_action_type_t;

/**
  @brief Port scl property parameter
*/
struct ctc_port_scl_property_s
{
    uint8 scl_id;             /**< [GB.GG] There are 2 scl lookup<0-1>, and each has its own feature*/
    uint8 direction;          /**< [GB.GG] direction, CTC_INGRESS or CTC_EGRESS*/

/* property */
    uint8 hash_type;          /**< [GB.GG] hash type. refer ctc_port_igs_scl_hash_type_t or ctc_port_egs_scl_hash_type_t*/
    uint8 action_type;        /**< [GG] action type. apply on both scl0 and scl1. refer ctc_port_scl_action_type_t*/
    uint8 tcam_type;          /**< [GB.GG] ingress only. refer ctc_port_igs_scl_tcam_type_t*/
    uint8 class_id_en;        /**< [GB.GG] use class id to lookup scl*/
    uint16 class_id;          /**< [GB.GG] class id. when class_id_en set*/
    uint8 use_logic_port_en;   /**< [GB.GG] SCL lookup port use logic port*/
    uint8 rsv0[3];
};
typedef struct ctc_port_scl_property_s ctc_port_scl_property_t;

/**
  @brief Port acl property parameter
*/
struct ctc_port_acl_property_s
{
    uint8 acl_priority;            /**< [DT2] <0--7> for ingress ,<0-2> for egress*/
    uint8 acl_en;                  /**< [DT2] set acl en */
    uint8 direction;               /**< [DT2] direction, CTC_INGRESS or CTC_EGRESS*/
    uint8 tcam_lkup_type;          /**< [DT2] tcam lookup type,refer to CTC_ACL_TCAM_LKUP_TYPE_XXX */

    uint8 class_id;                /**< [DT2] class id */
    uint8 use_port_bitmap;         /**< [DT2] if set, acl use port_bitmap to lookup */
    uint8 use_mapped_vlan;         /**< [DT2] if set, acl use mapped vlan to lookup*/
    uint8 use_metadata;            /**< [DT2] if set, acl use metadata to lookup*/

};
typedef struct ctc_port_acl_property_s ctc_port_acl_property_t;

/**
 @brief Port global config parameter
*/
struct ctc_port_global_cfg_s
{
    uint8 default_logic_port_en;    /**< [GB.GG] If set, port will enable default logic port for all local phy port and linkagg group*/
    uint8 rsv0[3];
};
typedef struct ctc_port_global_cfg_s ctc_port_global_cfg_t;


/**@} end of @defgroup port  */

#ifdef __cplusplus
}
#endif

#endif

