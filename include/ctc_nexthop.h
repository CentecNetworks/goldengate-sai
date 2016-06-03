/**
 @file ctc_nexthop.h

 @author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2009-12-11

 @version v2.0

 This file contains all Nexthop related data structure, enum, macro and proto.
*/

#ifndef _CTC_NEXTHOP_H
#define _CTC_NEXTHOP_H
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************
 *
 * Header Files
 *
 ***************************************************************/
#include "ctc_port.h"
#include "ctc_vlan.h"
#include "ctc_stats.h"

/****************************************************************
*
* Defines and Macros
*
****************************************************************/
#define CTC_MPLS_NH_MAX_PUSH_LABEL_NUM     4 /**< [HB.GB.GG] The maximum of MPLS lable can be pushed */
#define CTC_MPLS_NH_MAX_TUNNEL_LABEL_NUM   2 /**< [HB.GB.GG] The maximum of MPLS lable can be pushed */
#define CTC_NH_DEFAULT_MAX_EXTERNAL_NEXTHOP_NUM  16384
#define CTC_NH_DEFAULT_MAX_MPLS_TUNNEL_NUM  1024

/****************************************************************
*
* Data Structures
*
****************************************************************/

/**
 @defgroup nexthop NEXTHOP
 @{
*/

/**
 @brief  Define Global reserved nexthop ID
*/
enum ctc_nh_reserved_nhid_e
{
    CTC_NH_RESERVED_NHID_FOR_NONE   = 0,    /**< [HB.GB.GG] Global reserved nexthop Id for none */
    CTC_NH_RESERVED_NHID_FOR_DROP   = 1,    /**< [HB.GB.GG] Global reserved nexthop Id for drop */
    CTC_NH_RESERVED_NHID_FOR_TOCPU  = 2,    /**< [HB.GB.GG] Global reserved nexthop Id for cpu */
    CTC_NH_RESERVED_NHID_MAX        = 3
};
typedef enum ctc_nh_reserved_nhid_e ctc_nh_reserved_nhid_t;

enum ctc_nh_reserved_dsnh_offset_type_e
{
    CTC_NH_RES_DSNH_OFFSET_TYPE_BRIDGE_NH = 0,   /**< [HB.GB.GG] Reserved L2Uc Nexthop */
    CTC_NH_RES_DSNH_OFFSET_TYPE_BYPASS_NH,       /**< [HB.GB.GG] Reserved bypass Nexthop */
    CTC_NH_RES_DSNH_OFFSET_TYPE_MIRROR_NH,       /**< [HB.GB.GG] Reserved mirror Nexthop*/
    CTC_NH_RES_DSNH_OFFSET_TYPE_MAX
};
typedef enum ctc_nh_reserved_dsnh_offset_type_e ctc_nh_reserved_dsnh_offset_type_t;

/**
 @brief  Define Nexthop outgoing interface type ,pls refer to ctc_l3if_type_t
*/
enum ctc_nh_oif_type_e
{

    CTC_NH_OIF_TYPE_ROUTED_PORT,    /**< [HB.GB] Outgoing interface is routed port*/
    CTC_NH_OIF_TYPE_SUB_IF,         /**< [HB.GB] Outgoing interface is sub-interface*/
    CTC_NH_OIF_TYPE_VLAN_PORT,      /**< [HB.GB] Outgoing interface is vlan port */
    CTC_NH_OIF_TYPE_MAX
};
typedef enum ctc_nh_oif_type_e ctc_nh_oif_type_t;
/**
 @brief  Define Nexthop outgoing interface information structure
*/
struct ctc_nh_oif_info_s
{
    uint32 gport;           /**< [HB.GB.GG] Outgoing global port */
    uint16   vid;             /**< [HB.GB.GG] Outgoing vlan id*/
    uint8    oif_type;        /**< [HB] outgoing interface type, CTC_NH_OIF_TYPE_XXX,refer to ctc_nh_oif_type_t   */
    uint8    is_l2_port;      /**< [HB.GB.GG] if set,indicate oif is L2 port,and only do bridging*/
    uint16   ecmp_if_id;      /**< [GG] if not equal 0, means outgoing interface is ecmp interface */
};
typedef struct ctc_nh_oif_info_s ctc_nh_oif_info_t;

/**
 @brief  Define ECMP update type
*/
enum ctc_nh_ecmp_update_type_e
{
    CTC_NH_ECMP_ADD_MEMBER,        /**< [HB.GB.GG] Add a member into ECMP group */
    CTC_NH_ECMP_REMOVE_MEMBER,     /**< [HB.GB.GG] Remove a member from ECMP group */

    CTC_NH_ECMP_UPDATE_OP_MAX
};
typedef enum ctc_nh_ecmp_update_type_e ctc_nh_ecmp_update_type_t;

/**
 @brief  Define nexthop edit mode
*/
enum ctc_nh_edit_mode_e
{
    CTC_NH_IGS_CHIP_EDIT_MODE= 0,  /**< [HB.GB.GG] do packet edit on ingress chip  */
    CTC_NH_EGS_CHIP_EDIT_MODE = 1, /**< [HB.GB.GG] do packet edit on egress chip */
    CTC_NH_CHIP_EDIT_MODEMAX
};
typedef enum ctc_nh_edit_mode_e ctc_nh_edit_mode_t;

/**
 @brief  Define ECMP dynamic type
*/
enum ctc_nh_ecmp_dlb_mode_s
{
    CTC_NH_ECMP_DYNAMIC_MODE_NORMAL   = 0x1,  /**< [GG] ECMP dynamic load balancing normal mode:if inactivity duration
                                                        lapsed, use optimal member, else use assigned member.  This is default mode*/
    CTC_NH_ECMP_DYNAMIC_MODE_FIRST    = 0x2,  /**< [GG] ECMP dynamic load balancing first mode: only new flow
                                                        use optimal member for the first time, than use assigned member */
    CTC_NH_ECMP_DYNAMIC_MODE_PACKET   = 0x4,  /**< [GG] ECMP dynamic load balancing packet mode: use optimal member
                                                        every 1024 packets */
    CTC_NH_ECMP_DYNAMIC_MODE_ELEPHANT = 0x8,  /**< [GG] Only elephant(big) flow do ECMP dynamic load blance */
    CTC_NH_ECMP_DYNAMIC_MODE_TCP      = 0x10, /**< [GG] Only TCP flow do ECMP dynamic load blance */

    MAX_CTC_NH_ECMP_DYNAMIC_MODE
};
typedef enum ctc_nh_ecmp_dlb_mode_s ctc_nh_ecmp_dlb_mode_t;

/**
 @brief  Define Nexthop outgoing interface type flag
*/
struct ctc_nh_global_cfg_s
{
    uint32 max_external_nhid;               /**< [HB.GB.GG] max nhid used for external nexthop  */

    uint32 acl_redirect_fwd_ptr_num;        /**< [HB] The number of ds_fwd_ptr reserved for acl redirect function£¬only humber have the limition */
    uint32 local_met_num;                   /**< [HB]value 0: indicate local met share sram with dsFwd */
    uint32 local_nh_4w_num;                 /**< [HB]value 0: indicate local nexthop 4w share sram with local nexthop 8w */
    uint32 l2_edit_4w_num;                  /**< [HB]value 0: indicate l2edit 4w share sram with l2edit 8w */
    uint32 l3_edit_4w_num;                  /**< [HB]value 0: indicate l3edit 4w share sram with l3edit 8w */
    uint32 nh_edit_mode;                    /**< [HB] if it is CTC_NH_IGS_CHIP_EDIT_MODE, ,indicate dsnh_offset will be allocated in SDK.
                                                                      Humber :   it can be configured to 1 in Pizzbox mode;else it must be 0 ,default value 0*/
    uint16 max_ecmp;                        /**< [GB.GG] the maximum ECMP paths allowed for a route */
    uint16 max_tunnel_id;                   /**< [GB.GG] max tunnel id used for mpls tunnel label  */
    uint16 ecmp_dynamic_mode;               /**< [GG] ecmp dynamic load balancing mode, refer to ctc_nh_ecmp_dlb_mode_t */

};
typedef struct ctc_nh_global_cfg_s ctc_nh_global_cfg_t;

/**
 @brief  Define Nexthop update type
*/
enum ctc_nh_upd_type_s
{
    CTC_NH_UPD_UNRSV_TO_FWD,    /**< [HB.GB.GG] update to forwarding nexthop  */
    CTC_NH_UPD_FWD_TO_UNRSV,    /**< [HB.GB.GG] update to unresoved nexthop */
    CTC_NH_UPD_FWD_ATTR,        /**< [HB.GB.GG] updated forwarding nexthop attribute */
    MAX_CTC_NH_UPDTYPE
};
typedef enum ctc_nh_upd_type_s ctc_nh_upd_type_t;

/**
 @brief  Define ECMP Nexthop type
*/
enum ctc_nh_ecmp_type_s
{
    CTC_NH_ECMP_TYPE_STATIC,        /**< [GG] static ECMP */
    CTC_NH_ECMP_TYPE_DLB,           /**< [GG] ECMP dynamic load balancing modes, refer ctc_nh_ecmp_dlb_mode_t */
    CTC_NH_ECMP_TYPE_RR,            /**< [GG] ECMP round robin load balancing mode */
    CTC_NH_ECMP_TYPE_RANDOM_RR,     /**< [GG] ECMP random round robin load balancing mode */
    CTC_NH_ECMP_TYPE_XERSPAN,       /**< [GG] ECMP erspan used for symmetric hash */

    MAX_CTC_NH_ECMP_TYPE
};
typedef enum ctc_nh_ecmp_type_s ctc_nh_ecmp_type_t;

/**
@brief  Define ECMP create data structure
*/
struct ctc_nh_ecmp_nh_param_s
{
    uint32 nhid[CTC_MAX_ECPN]; /**< [HB.GB.GG] ECMP member nh ID */
    uint8  nh_num;        /**< [HB.GB.GG] Number of members  */
    uint8  type;          /**< [GG] ECMP type, refer to ctc_nh_ecmp_type_t */
    uint8  upd_type;      /**< [HB.GB.GG] CTC_NH_ECMP_ADD_MEMBER or CTC_NH_ECMP_REMOVE_MEMBER */
    uint8  failover_en;   /**< [GG] Indicate linkdown use hw based linkup member select, only used for static or rr ecmp */
    uint32 stats_id;      /**< [GG] Stats id*/
};
typedef struct ctc_nh_ecmp_nh_param_s ctc_nh_ecmp_nh_param_t;

/**
 @brief  Define brg unicast nexthop sub type enum
*/
enum ctc_nh_param_brguc_sub_type_e
{
    CTC_NH_PARAM_BRGUC_SUB_TYPE_BASIC               = (1 << 0), /**< [HB.GB.GG] basic type nexthop*/
    CTC_NH_PARAM_BRGUC_SUB_TYPE_UNTAGGED            = (1 << 1), /**< [HB] apply for port untagged mode */
    CTC_NH_PARAM_BRGUC_SUB_TYPE_BYPASS              = (1 << 2), /**< [HB.GB.GG] bypass type nexthop */
    CTC_NH_PARAM_BRGUC_SUB_TYPE_RAW_PACKET_ELOG_CPU = (1 << 3), /**< [HB] raw pacekt type nexthop */
    CTC_NH_PARAM_BRGUC_SUB_TYPE_SERVICE_QUEUE       = (1 << 4), /**< [HB] service queue type nexthop*/
    CTC_NH_PARAM_BRGUC_SUB_TYPE_ALL                 =  0        /**< [HB.GB.GG] all subtype  */

};
typedef enum ctc_nh_param_brguc_sub_type_e ctc_nh_param_brguc_sub_type_t;

/**
 @brief  Define nexthop arp mac sub type enum
*/
enum ctc_nh_nexthop_mac_flag_e
{
    CTC_NH_NEXTHOP_MAC_VLAN_VALID               = (1 << 0),  /**< [GB.GG] if set,indicate outgoing port is Phy_if,and packet need to do vlan edit.(To achieve sub interface) */
    CTC_NH_NEXTHOP_MAC_ECMP_IF_ARP              = (1 << 1),  /**< [GG] if set ,config ecmp if arp mac*/
    CTC_NH_NEXTHOP_MAC_DISCARD                  = (1 << 2),  /**< [GB.GG] if set, config arp miss action discard */
    CTC_NH_NEXTHOP_MAC_REDIRECT_TO_CPU          = (1 << 3)   /**< [GB.GG] if set, config arp miss action to CPU */
};
typedef enum ctc_nh_nexthop_mac_flag_e ctc_nh_nexthop_mac_flag_t;

/**
 @brief  Define Next hop router Mac parametes structure
*/
struct ctc_nh_nexthop_mac_param_s
{
    uint16      flag;           /**< [GB.GG] refer to ctc_nh_nexthop_mac_flag_t */
    mac_addr_t  mac;            /**< [GB.GG] Outgoing mac */
    uint16      vlan_id;        /**< [GB.GG] Vlan Id*/
    uint32      gport;          /**< [GG] used to config ecmp if arp mac */
};
typedef struct ctc_nh_nexthop_mac_param_s ctc_nh_nexthop_mac_param_t;

/**
 @brief  Define ip nexthop flag enum
*/
enum ctc_ip_nh_flag_e
{
    CTC_IP_NH_FLAG_UNROV          = 0x00000001,        /**< [HB.GB.GG] unresolved IP next hop */
    CTC_IP_NH_FLAG_TTL_NO_DEC     = 0x00000002,        /**< [GB.GG] ttl not decrease */
    CTC_IP_NH_FLAG_STRIP_MAC      = 0x00000004,        /**< [GB] strip mac and vlan */
    CTC_IP_NH_FLAG_FPMA           = 0x00000008,        /**< [GG] FPMA mode for FCoE MACDA */
    CTC_IP_NH_FLAG_MAX
};
typedef enum ctc_ip_nh_flag_e ctc_ip_nh_flag_t;


/**
 @brief  Define ip nexthop parametes structure
*/
struct ctc_ip_nh_param_s
{
    uint32                  flag;         /**< [HB.GB.GG] IP nexthop flag --> ctc_ip_nh_flag_t,CTC_IP_NH_FLAG_xxx flags*/
    ctc_nh_upd_type_t       upd_type;     /**< [HB.GB.GG] nexthop update type ,used for update Operation*/

    ctc_nh_oif_info_t       oif;         /**< [HB.GB.GG] Outgoing interface*/
    mac_addr_t              mac;         /**< [HB.GB.GG] Outgoing mac */

    ctc_nh_oif_info_t    p_oif;         /**< [HB.GB.GG] if aps_en set,protection outgoing interface*/
    mac_addr_t           p_mac;         /**< [HB.GB.GG] if aps_en set,protection outgoing mac */
    uint32               dsnh_offset;   /**< [HB] if Chipset use Egress chip Edit mode ,the
                                              dsnh_offset is allocated in platform adaption Layer;
                                              else the dsnh_offset is internally allocated in SDK */

    uint8   aps_en;                   /**< [GB.GG] if set, APS enable*/
    uint8   rsv0;
    uint16  aps_bridge_group_id;      /**< [GB.GG] the APS group ID of the nexthop. */

    uint32 loop_nhid;                 /**< [GB] loopback to destination nexthop id, 0 means invalid */
    uint16 arp_id;                    /**< [GB.GG] working path arp id, 0 means invalid */
    uint16 p_arp_id;                  /**< [GB.GG] protection path arp id, 0 means invalid */
};
typedef struct ctc_ip_nh_param_s ctc_ip_nh_param_t;

/**
 @brief  Define ip nexthop tunnel flag
*/
enum ctc_ip_nh_tunnel_flag_e
{
    CTC_IP_NH_TUNNEL_FLAG_MAP_TTL        =    (1 << 0),  /**< [HB.GB.GG] If set , means new TTL mapped from (pkt_ttl - ttl)*/
    CTC_IP_NH_TUNNEL_FLAG_COPY_DONT_FRAG =    (1 << 1),  /**< [HB.GB.GG] [Only for In4] If set , means new dont frag will copy payload ip dont frag);else will use user defined dont frag*/
    CTC_IP_NH_TUNNEL_FLAG_DONT_FRAG      =    (1 << 2),  /**< [HB.GB.GG] [Only for In4] User defined dont frag,if set ,dont frag will set to 1;else to 0 */
    CTC_IP_NH_TUNNEL_FLAG_MTU_CHECK      =    (1 << 3),  /**< [HB.GB.GG] If set , means mtu check enable(only 6to4 auto )*/
    CTC_IP_NH_TUNNEL_FLAG_GRE_WITH_KEY   =    (1 << 4),   /**<[HB.GB.GG] If set ,means GRE header with KEY*/
    CTC_IP_NH_TUNNEL_FLAG_REROUTE_WITH_TUNNEL_HDR =  (1 << 5), /**< [HB.GB.GG] If set ,means encap packet will re-route with new tunnel header; for ivi, will re-route with new ip header */
    CTC_IP_NH_TUNNEL_FLAG_6TO4_USE_MANUAL_IPSA    = (1 << 6),  /**< [HB.GB.GG] If set ,means encap packet's IPSA is manual */
    CTC_IP_NH_TUNNEL_FLAG_MIRROR         = (1 << 7),      /**< [HB.GB.GG] If set ,means encap packet will be applied to mirror session */
    CTC_IP_NH_TUNNEL_FLAG_IP_BFD               = (1 << 8),      /**< [HB.GB.GG] If set , packet will be applied to IP BFD.
                                                           only for CTC_TUNNEL_TYPE_IPV4_IN4 & CTC_TUNNEL_TYPE_IPV4_IN6 */
    CTC_IP_NH_TUNNEL_FLAG_NAT_REPLACE_IP       = (1 << 9),      /**< [GB] [Only for Nat] If set , only ip will be repalce */
    CTC_IP_NH_TUNNEL_FLAG_OVERLAY_HOVERLAY      = (1 << 10),    /**< [GG] If set, means the tunnel is a hierarchy overlay tunnel, it will disable split horizon and set logic port*/
    CTC_IP_NH_TUNNEL_FLAG_OVERLAY_CROSS_VNI    = (1 << 11),   /**< [GG] If set, means overlay tunnel is encap new VN ID */
    CTC_IP_NH_TUNNEL_FLAG_STRIP_VLAN    = (1 << 12),   /**< [GG] If set, means pakcet will strip original vlan  */
    CTC_IP_NH_TUNNEL_FLAG_OVERLAY_VXLAN_GPE    = (1 << 13),   /**< [GG] If set, means overlay tunnel is VxLAN-GPE */
    CTC_IP_NH_TUNNEL_FLAG_OVERLAY_UPDATE_MACSA = (1 << 14),   /**< [GG] If set, means update inner MACSA for overlay tunnel*/
    CTC_IP_NH_TUNNEL_FLAG_XERSPN_WITH_EXT_HDR  = (1 << 15),   /**< [GG] If set ,means erspan will encapsulate extend header */
    CTC_IP_NH_TUNNEL_FLAG_XERSPN_WITH_EXT_HDR_HASH = (1 << 16),/**< [GG] If set ,means erspan extend header will  include symmtric hash vlaue*/
    CTC_IP_NH_TUNNEL_FLAG_XERSPN_KEEP_IGS_TS   = (1 << 17)     /**< [GG] If set ,means erspan extend header timestamp is from ingress, else from egress*/
};
typedef enum ctc_ip_nh_tunnel_flag_e ctc_ip_nh_tunnel_flag_t;


/**
 @brief  Define ip nexthop Tunnel types
*/
enum ctc_nh_ip_tunnel_type_e
{
    CTC_TUNNEL_TYPE_NONE,               /**< [HB.GB.GG] NO IP tunneling. */
    CTC_TUNNEL_TYPE_IPV4_IN4,           /**< [HB.GB.GG] RFC 2003/2893: IPv4-in-IPv4 tunnel. */
    CTC_TUNNEL_TYPE_IPV6_IN4,           /**< [HB.GB.GG] RFC 2003/2893: IPv6-in-IPv4 tunnel. */
    CTC_TUNNEL_TYPE_IPV4_IN6,           /**< [HB.GB.GG] RFC 2003/2893: IPv4-in-IPv6 tunnel. */
    CTC_TUNNEL_TYPE_IPV6_IN6,           /**< [HB.GB.GG] RFC 2003/2893: IPv6-in-IPv6 tunnel. */
    CTC_TUNNEL_TYPE_GRE_IN4,            /**< [HB.GB.GG] RFC 1701/2784/2890: GRE IPv4-in-IPv4  tunnel. */
    CTC_TUNNEL_TYPE_GRE_IN6,            /**< [HB.GB.GG] RFC 1701/2784/2890: GRE IPv4-in-IPv6  tunnel. */
    CTC_TUNNEL_TYPE_ISATAP,             /**< [HB.GB.GG] RFC 5214/5579 ,IPv6-in-IPv4 tunnel,ipv4 da copy ipv6 da(last 32bit) */
    CTC_TUNNEL_TYPE_6TO4,               /**< [HB.GB.GG] RFC 3056,IPv6-in-IPv4 tunnel,ipv4 da and sa copy ipv6 da and (middle 32bit) */
    CTC_TUNNEL_TYPE_6RD,                /**< [HB.GB.GG] RFC 3056,IPv6-in-IPv4 tunnel,ipv4 da and sa copy ipv6 da and (middle 32bit) */
    CTC_TUNNEL_TYPE_IPV4_NAT,           /**< [HB.GB.GG] NAT nexthop. for NAT:replace ipda; for NAPT: replace ipda and l4dstport */
    CTC_TUNNEL_TYPE_IVI_6TO4,           /**< [HB.GB.GG] IVI nexthop. do ipv6 address translate to ipv4 adress */
    CTC_TUNNEL_TYPE_IVI_4TO6,           /**< [HB.GB.GG] IVI nexthop. do ipv4 address translate to ipv6 adress */
    CTC_TUNNEL_TYPE_NVGRE_IN4,          /**< [GG] NVGRE nexthop. do l2 overlay network encapsuation by NvGRE in ipv4*/
    CTC_TUNNEL_TYPE_VXLAN_IN4,          /**< [GG] VXLAN nexthop. do l2 overlay network encapsuation by Vxlan/eVxLAN in ipv4*/
    CTC_TUNNEL_TYPE_GENEVE_IN4,          /**< [GG] GENEVE nexthop. do l2 overlay network encapsuation by GENEVE in ipv4*/
    CTC_TUNNEL_TYPE_NVGRE_IN6,          /**< [GG] NVGRE nexthop. do l2 overlay network encapsuation by NvGRE in ipv6*/
    CTC_TUNNEL_TYPE_VXLAN_IN6,          /**< [GG] VXLAN nexthop. do l2 overlay network encapsuation by Vxlan/eVxLAN in ipv6*/
    CTC_TUNNEL_TYPE_GENEVE_IN6,          /**< [GG] GENEVE nexthop. do l2 overlay network encapsuation by GENEVE in ipv6*/
    MAX_CTC_TUNNEL_TYPE                 /* Must be last */
};
typedef enum ctc_nh_ip_tunnel_type_e ctc_nh_ip_tunnel_type_t;

/**
 @brief  Define IPv6 flow label mode
*/
enum ctc_nh_dscp_select_mode_e
{
    CTC_NH_DSCP_SELECT_ASSIGN,          /**< [HB.GB.GG] Use user-define DSCP to outer header.*/
    CTC_NH_DSCP_SELECT_MAP,             /**< [HB.GB.GG] Use DSCP value from DSCP map */
    CTC_NH_DSCP_SELECT_PACKET,          /**< [HB.GB.GG] Copy packet DSCP to outer header */
    MAX_CTC_NH_DSCP_SELECT_MODE        /* Must be last */
};
typedef enum ctc_nh_dscp_select_mode_e ctc_nh_dscp_select_mode_t;

/**
 @brief  Define flow label mode
*/
enum ctc_nh_flow_label_mode_e
{
    CTC_NH_FLOW_LABEL_NONE,            /**< [HB.GB.GG] Do not set flow label value */
    CTC_NH_FLOW_LABEL_WITH_HASH,        /**< [GB.GG] Use (user-define flow label + header hash) to outer header.*/
    CTC_NH_FLOW_LABEL_ASSIGN,          /**< [HB.GB.GG] Use user-define flow label to outer header.*/
    MAX_CTC_NH_FLOW_LABEL              /* Must be last */
};
typedef enum ctc_nh_flow_label_mode_e ctc_nh_flow_label_mode_t;

/**
 @brief  Define flow label mode
*/
enum ctc_nh_sp_prefix_length_e
{
    CTC_NH_SP_PREFIX_LENGTH_16  = 0,  /**< [GB.GG] 6rd type tunnel SP prefix length is 16. */
    CTC_NH_SP_PREFIX_LENGTH_24  = 1,  /**< [GB.GG] 6rd type tunnel SP prefix length is 24. */
    CTC_NH_SP_PREFIX_LENGTH_32  = 2,  /**< [GB.GG] 6rd type tunnel SP prefix length is 32. */
    CTC_NH_SP_PREFIX_LENGTH_40  = 3,  /**< [GB.GG] 6rd type tunnel SP prefix length is 40. */
    CTC_NH_SP_PREFIX_LENGTH_48  = 4,  /**< [GB.GG] 6rd type tunnel SP prefix length is 48. */
    CTC_NH_SP_PREFIX_LENGTH_56  = 5,  /**< [GB.GG] 6rd type tunnel SP prefix length is 56. */
    MAX_CTC_NH_SP_PREFIX_LENGTH       /* Must be last */
};
typedef enum ctc_nh_sp_prefix_length_e ctc_nh_sp_prefix_length_t;

/**
 @brief  Define ivi prefix length
*/
enum ctc_nh_ivi_prefix_len_e
{
    CTC_NH_IVI_PREFIX_LEN_32         = 0, /**< [GB.GG] ivi prefix length is 32 */
    CTC_NH_IVI_PREFIX_LEN_40         = 1, /**< [GB.GG] ivi prefix length is 40 */
    CTC_NH_IVI_PREFIX_LEN_48         = 2, /**< [GB.GG] ivi prefix length is 48 */
    CTC_NH_IVI_PREFIX_LEN_56         = 3, /**< [GB.GG] ivi prefix length is 56 */
    CTC_NH_IVI_PREFIX_LEN_64         = 4, /**< [GB.GG] ivi prefix length is 64 */
    CTC_NH_IVI_PREFIX_LEN_72         = 5, /**< [GB.GG] ivi prefix length is 72 */
    CTC_NH_IVI_PREFIX_LEN_80         = 6, /**< [GB.GG] ivi prefix length is 80 */
    CTC_NH_IVI_PREFIX_LEN_96         = 7, /**< [GB.GG] ivi prefix length is 96 */

    MAX_CTC_NH_IVI_PREFIX_LEN
};
typedef enum ctc_nh_ivi_prefix_len_e ctc_nh_ivi_prefix_len_t;

/**
 @brief  Define ip nexthop tunnel info structure
*/
struct ctc_ip_nh_tunne_info_s
{
    uint8  tunnel_type;    /**< [HB.GB.GG] Ip tunnel type, CTC_TUNNEL_TYPE_XXX,refer to ctc_nh_ip_tunnel_type_t*/
    uint8  ttl;            /**< [HB.GB.GG] TTL value*/
    uint8  rsv[0];

    uint32 flag;           /**< [HB.GB.GG] CTC_IP_NH_TUNNEL_FLAG_XXX,ctc_ip_nh_tunnel_flag_t*/

    uint8  dscp_select;    /**< [HB.GB.GG] Dscp select mode,refer to ctc_nh_dscp_select_mode_t*/
    uint8  dscp_or_tos;    /**< [HB.GB.GG] Dscp value for Ip version 4 , tos for Ip version 6(Dscp value for Ip version 6 for GG) */
    uint16 mtu_size;       /**< [HB.GB.GG] MTU size*/

    uint32 flow_label;     /**< [HB.GB.GG] Ip version 6 flow label */

    uint8  flow_label_mode; /**< [GB.GG] Ip version 6 flow label mode,refer to ctc_nh_flow_label_mode_t */
    uint8  inner_packet_type;    /**< [GG] indicate payload packet type when encap overlay tunnel, refer to packet_type_t*/
    uint16 l4_dst_port;     /**< [GB.GG] layer4 destination port used by NAPT */

    uint32 vn_id;          /**< [GG] vn_id value used for overlay(NvGRE/VxLAN/eVxLAN/GENEVE) encap , if 0 means use the vn_id from IPE */
    mac_addr_t inner_macda;/**< [GG] inner_macda value only valid when CTC_IP_NH_TUNNEL_FLAG_OVERLAY_CROSS_VNI is set */
    mac_addr_t inner_macsa;/**< [GG] inner_macsa value only valid when CTC_IP_NH_TUNNEL_FLAG_OVERLAY_ROUTE_MACSA is set, it will
                                    use route MAC when inner_macsa = 0*/

    uint16 logic_port;     /**< [GG] Assign a logic port to the tunnel */
    uint16 span_id;        /**< [GG] Assign span_id for erspan session, <0-1023> */

    uint32 stats_id;       /**< [GG] Stats id, 0 is disable */

    union
    {
        ip_addr_t   ipv4; /**< [HB.GB.GG] Ip version 4 address */
        ipv6_addr_t ipv6; /**< [HB.GB.GG] Ip version 6 address */
    } ip_sa;               /**< [HB.GB.GG] New ip sa address in ip header*/

    union
    {
        ip_addr_t   ipv4; /**< [HB.GB.GG] Ip version 4 address */
        ipv6_addr_t ipv6; /**< [HB.GB.GG] Ip version 6 address */
    } ip_da;               /**< [HB.GB.GG] New ip da address in ip header*/

    struct
    {
        uint8  gre_ver;         /**< [HB.GB.GG] GRE verion,delete */
        uint8  rsv;             /**< [HB.GB.GG] reserved */
        uint16 protocol_type;   /**< [HB.GB.GG] GRE header's Protocol Type field  */
        uint32 gre_key;         /**< [HB.GB.GG] GRE Key. When enable mtu check, GRE key only have 16 bit */
    } gre_info;

    struct
    {
        uint8 sp_prefix_len;    /**< [GB.GG] SP prefix length for 6rd type tunnel, refer to ctc_nh_sp_prefix_length_t */
        uint8 v4_sa_masklen;    /**< [GB.GG] The number of high-order bits for ipv4 sa that can be config by user. */
        uint8 v4_da_masklen;    /**< [GB.GG] The number of high-order bits for ipv4 da that can be config by user. */
        uint8 rsv0;
    } sixrd_info;

    struct
    {
        ctc_nh_ivi_prefix_len_t  prefix_len;    /**< [GB.GG] ivi prefix length */
        uint8 is_rfc6052;                       /**< [GB.GG] the IPv4-embedded IPv6 address's 64 to 71 bits are set to zero*/
        ipv6_addr_t ipv6;                       /**< [GB.GG] ipv6 prefix address used for IVI4TO6 */
    } ivi_info;


};
typedef struct ctc_ip_nh_tunne_info_s ctc_ip_nh_tunne_info_t;

/**
 @brief  Define ip tunnel nexthop parameter structure
*/
struct ctc_ip_tunnel_nh_param_s
{
    uint32                  flag;       /**< [HB.GB.GG] IP nexthop flag --> ctc_ip_nh_flag_t,CTC_IP_NH_FLAG_xxx flags*/
    ctc_nh_upd_type_t       upd_type;   /**< [HB.GB.GG] nexthop update type ,used for update Operation*/
    ctc_nh_oif_info_t       oif;        /**< [HB.GB.GG] if encap packet directly send out,it is outgoing interface information,else it is invalid*/
    mac_addr_t              mac;        /**< [HB.GB.GG] if encap packet directly send out,it is nexthop router mac,else it is invalid */
    mac_addr_t              mac_sa;     /**< [GG] if encap packet directly send out by vlan port,it is nexthop mac sa,else it is invalid */
    ctc_ip_nh_tunne_info_t  tunnel_info; /**< [HB.GB.GG]  tunneling information */
    uint32                  dsnh_offset; /**< [HB] if Chipset use Egress chip Edit mode ,
                                                  the dsnh_offset is allocated in platform adaption Layer;
                                                  else the dsnh_offset is internally allocated in SDK */
    uint16 arp_id;                       /**< [GB.GG] arp id */
};
typedef struct ctc_ip_tunnel_nh_param_s ctc_ip_tunnel_nh_param_t;

/**
 @brief Define the type of vlan edit type in EPE of Humber
*/
enum ctc_vlan_egress_edit_type_e
{
    /*output vlan is same as ingress mapped vlan(eg. vlan translation vid,epe do not edit the vlan*/
    CTC_VLAN_EGRESS_EDIT_NONE,                  /**< [HB.GB.GG] Will keep ingress mapped vlan*/
    /*Keep output vlan same as input vlan(raw vlan) in the packet*/
    CTC_VLAN_EGRESS_EDIT_KEEP_VLAN_UNCHANGE,    /**< [HB.GG] Will keep original packet's vlan*/
    CTC_VLAN_EGRESS_EDIT_INSERT_VLAN,           /**< [HB.GB.GG] Will insert a new vlan, according to ingress mapped vlan or egress specified vlan, egress vlan have high priority*/
    CTC_VLAN_EGRESS_EDIT_REPLACE_VLAN,          /**< [HB.GB.GG] Will replace original vlan, according to ingress mapped vlan or egress specified vlan, egress vlan have high priority; if original packet is untagged, will append a new tag*/
    CTC_VLAN_EGRESS_EDIT_STRIP_VLAN,            /**< [HB.GB.GG] Will strip original vlan*/
    CTC_VLAN_EGRESS_EDIT_MAX
};
typedef enum ctc_vlan_egress_edit_type_e ctc_vlan_egress_edit_type_t;

/**
 @brief  Define Egress Vlan Editing nexthop flag
*/
enum ctc_vlan_egress_edit_nh_flag_e
{
    CTC_VLAN_NH_SERVICE_QUEUE_FLAG = (1 << 0),     /**< [HB.GB] create a egress valn nexthop with service queue select type*/
    CTC_VLAN_NH_LENGTH_ADJUST_EN   = (1 << 1),     /**< [HB.GB] This flag indicate need adjust packet length when do shaping*/
    CTC_VLAN_NH_ETREE_LEAF         = (1 << 2),     /**< [GB.GG] This flag indicate the nexthop is leaf node in E-Tree networks */
    CTC_VLAN_NH_HORIZON_SPLIT_EN   = (1 << 3),     /**< [GB.GG] This flag indicate the nexthop enable horizon split in VPLS networks */
    CTC_VLAN_NH_STATS_EN           = (1 << 4),     /**< [GB.GG] This flag indicate the nexthop enable stats */
    CTC_VLAN_NH_MTU_CHECK_EN       = (1 << 5)      /**< [GB] Enable MTU check, will use nexthop8w */
};
typedef enum ctc_vlan_egress_edit_nh_flag_e ctc_vlan_egress_edit_nh_flag_t;

/**
 @brief  Define egress vlan edit information structure
*/
struct ctc_vlan_egress_edit_info_s
{
    uint32 flag;                                    /**< [HB.GB.GG] nexthop flag, CTC_VLAN_NH_XXX_FLAG,pls refer to ctc_vlan_egress_edit_nh_flag_t*/
    /*If cvlan edit type is insert cvlan, then svlan edit should not be replace;
    And if svlan edit type is insert svlan, cvlan edit should not be replace*/
    uint32 stats_id;                                /**< [GB.GG] Stats id*/
    ctc_vlan_egress_edit_type_t cvlan_edit_type;    /**< [HB.GB.GG] Edit type on cvlan*/
    ctc_vlan_egress_edit_type_t svlan_edit_type;    /**< [HB.GB.GG] Edit type on svlan*/
    uint16 output_cvid;                             /**< [HB.GB.GG] Specified output cvlan id*/
    uint16 output_svid;                             /**< [HB.GB.GG] Specified output svlan id*/
    uint8 edit_flag;                                /**< [HB.GB.GG] Edit flag*/
    uint8 svlan_tpid_index;                         /**< [GB.GG] svlan tpid index*/
#define CTC_VLAN_EGRESS_EDIT_VLAN_SWAP_EN           (1 << 0)    /**< [HB.GB.GG] Edit flag indicate vlan swap*/
#define CTC_VLAN_EGRESS_EDIT_TPID_SWAP_EN           (1 << 1)    /**< [HB.GB.GG] Edit flag indicate tpid swap*/
#define CTC_VLAN_EGRESS_EDIT_COS_SWAP_EN            (1 << 2)    /**< [HB.GB.GG] Edit flag indicate cos swap*/
#define CTC_VLAN_EGRESS_EDIT_OUPUT_CVID_VALID       (1 << 3)    /**< [HB.GB.GG] Edit flag indicate output cvlan id*/
#define CTC_VLAN_EGRESS_EDIT_OUPUT_SVID_VALID       (1 << 4)    /**< [HB.GB.GG] Edit flag indicate output svlan id*/
#define CTC_VLAN_EGRESS_EDIT_OUTPUT_SVLAN_TPID_VALID   (1 << 5)    /**< [GB.GG] This flag indicate the nexthop can change svlan tpid */
#define CTC_VLAN_EGRESS_EDIT_REPLACE_SVLAN_COS   (1 << 6)    /**< [GB] This flag indicate the nexthop can change svlan cos */
#define CTC_VLAN_EGRESS_EDIT_MAP_SVLAN_COS       (1 << 7)    /**< [GB.GG] This flag indicate the new stag cos is mapped from priority */

    uint8 stag_cos;                                /**< [GB] Specified output stag cos*/

    uint8 resv;

    uint16 user_vlanptr;                            /**< [HB] Set the dest_vlanptr of the nexthop, 0 means use src_vlan_ptr or from output_svid */
    uint16 mtu_size;                                /**< [GB] MTU size */
    uint32 loop_nhid;                               /**< [GB] loopback to destination nexthop id, 0 means invalid */
};
typedef struct ctc_vlan_egress_edit_info_s ctc_vlan_egress_edit_info_t;

/**
 @brief Define the data structure about vlan nexthop parameter structure
*/
struct ctc_vlan_edit_nh_param_s
{
    uint32 dsnh_offset;                           /**< [HB] if Chipset use Egress chip Edit , the dsnh_offset is allocated in platform adaption Layer; else the dsnh_offset is internally allocated in SDK */

    uint32 gport_or_aps_bridge_id;                /**< [HB.GB.GG]  Destination global port  or APS bridge group id */
    uint8  aps_en;                                 /**< [HB.GB.GG] if set,indicate aps enable */
    uint8  logic_port_valid;                      /**< [GB.GG] if set, indicated logic_port is valid.In VPLS networks,it should be set to 1. */

    uint16 logic_port;                            /**< [GB.GG] destination logic port in VPLS networks */
    uint16 rsv0;                                  /**< Reserved0 */

    ctc_vlan_egress_edit_info_t vlan_edit_info;   /**< [HB.GB.GG] Working path's Vlan Edit */
    ctc_vlan_egress_edit_info_t vlan_edit_info_p; /**< [HB.GB.GG] Protection path's Vlan Edit */
};
typedef struct ctc_vlan_edit_nh_param_s ctc_vlan_edit_nh_param_t;

/**
 @brief  Define MPLS nexthop operation type
*/
enum ctc_mpls_nh_op_e
{
    /*Push operation*/
    CTC_MPLS_NH_PUSH_OP_NONE,             /**< [HB.GB.GG] Will append new layer2 header, mpls payload is Ethernet, and will keep mpls payload unchanged.   */
    /*Swap  label on LSR /Pop label and do   label  Swap on LER */
    CTC_MPLS_NH_PUSH_OP_ROUTE,            /**< [HB.GB.GG] Will append new layer2 header, mpls payload is IP, and ip TTL will be updated. (L3VPN/FTN)*/
    CTC_MPLS_NH_PUSH_OP_L2VPN,            /**< [HB.GB.GG] Will append new layer2 header, mpls payload is Ethernet, ethernet packet's tag could be edited (L2VPN)*/

    /* pop operation*/
    CTC_MPLS_NH_PHP,                     /**< [HB.GB.GG] Will append new layer2 header, TTL processing according to ctc_mpls_nexthop_pop_param_t.ttl_mode*/

    CTC_MPLS_NH_OP_MAX
};
typedef enum ctc_mpls_nh_op_e ctc_mpls_nh_op_t;

/**
 @brief  Define mpls nexthop label type
*/
enum ctc_mpls_nh_label_type_flag_e
{
    CTC_MPLS_NH_LABEL_IS_VALID  = (1 << 0),   /**< [HB.GB.GG] If set , means this MPLS label is valid*/
    CTC_MPLS_NH_LABEL_IS_MCAST  = (1 << 1),   /**< [HB.GB.GG] If set , means this MPLS label is mcast label*/
    CTC_MPLS_NH_LABEL_MAP_TTL   = (1 << 2)    /**< [HB.GB.GG] If set , means new TTL mapped from (pkt_ttl - ttl)*/
};
typedef enum ctc_mpls_nh_label_type_flag_e ctc_mpls_nh_label_type_flag_t;

/**
 @brief  Define mpls exp select mode
*/
enum ctc_nh_exp_select_mode_e
{
    CTC_NH_EXP_SELECT_ASSIGN,          /**< [HB.GB.GG] Use user-define EXP to outer header.*/
    CTC_NH_EXP_SELECT_MAP,             /**< [HB.GB.GG] Use EXP value from EXP map */
    CTC_NH_EXP_SELECT_PACKET,          /**< [HB.GB.GG] Copy packet EXP to outer header */
    MAX_CTC_NH_EXP_SELECT_MODE        /* Must be last */
};
typedef enum ctc_nh_exp_select_mode_e ctc_nh_exp_select_mode_t;

/**
 @brief  Define MPLS label parameter structure
*/
struct ctc_mpls_nh_label_param_s
{
    uint8  lable_flag; /**< [HB.GB.GG] MPLS label flag,ctc_mpls_nh_label_type_flag_t */
    uint8  ttl;        /**< [HB.GB.GG] TTL value.
                                      if CTC_MPLS_NH_LABEL_MAP_TTL set to 1:
                                        FTN Pipe mode ttl set to 0,else 1.
                                      else ttl will fare up to (0£¬1£¬2£¬8£¬15£¬16£¬31£¬32£¬60£¬63£¬64£¬65£¬127£¬128£¬254£¬255)
                                      according to user defined value*/
    uint8  exp_type;   /**< [HB.GB.GG] New MPLS exp type in this label,pls refer to ctc_nh_exp_select_mode_t*/
    uint8  exp;        /**< [HB.GB.GG] EXP value*/
    uint32 label;      /**< [HB.GB.GG] MPLS label value*/
};
typedef struct ctc_mpls_nh_label_param_s ctc_mpls_nh_label_param_t;

/**
 @brief  Define MPLS martini label sequence type
*/
enum ctc_mpls_nh_martini_seq_type_e
{
    CTC_MPLS_NH_MARTINI_SEQ_NONE = 0,   /**< [HB.GB.GG] Martini label sequence number type none, means doesn't support martini label sequence*/
    CTC_MPLS_NH_MARTINI_SEQ_PER_PW,     /**< [HB] Martini label sequence number type is per-PW*/
    CTC_MPLS_NH_MARTINI_SEQ_GLB_TYPE0,  /**< [HB] Martini label sequence number type is global type 0*/
    CTC_MPLS_NH_MARTINI_SEQ_GLB_TYPE1,  /**< [HB] Martini label sequence number type is global type 1*/

    CTC_MPLS_NH_MARTINI_SEQ_MAX
};
typedef enum ctc_mpls_nh_martini_seq_type_e ctc_mpls_nh_martini_seq_type_t;

/**
 @brief  Define MPLS nexthop flag type
*/
enum ctc_mpls_nh_flag_type_e
{
    CTC_MPLS_NH_FLAG_SERVICE_QUEUE_EN  =  (1 << 0),     /**< [HB.GB] Enable service queue, ,only need set the bit in humber */
    CTC_MPLS_NH_FLAG_SQN_EN            =  (1 << 1)       /**<[HB.GB] Enable SQN */
};
typedef enum ctc_mpls_nh_flag_type_e ctc_mpls_nh_flag_type_t;

/**
 @brief  Define MPLS nexthop aps flag type
*/
enum ctc_mpls_nh_tunnel_aps_flag_type_e
{
    CTC_NH_MPLS_APS_EN          = (1 << 0),               /**< [HB.GB.GG] if set,indicate tunnel enable aps  */
    CTC_NH_MPLS_APS_2_LAYER_EN                =(1 << 1),  /**< [HB.GB.GG] if set, if label_num is equal to 2 ,aps_en is 1 and it
                                                              is set,indicate two layer tunnel protection are enable  */
    CTC_NH_MPLS_APS_2_LAYER_EN_PROTECTION   = (1 << 2), /**< [HB.GB.GG] if set ,indicate tunnel parameter is protection  path parameter
                                                              ;else indicate tunnel parameter is working path parameter */
};
typedef enum ctc_mpls_nh_tunnel_aps_flag_type_e ctc_mpls_nh_tunnel_aps_flag_type_t;

/**
 @brief  Define MPLS nexthop common parameter structure
*/
struct ctc_mpls_nexthop_com_param_s
{
    uint32  mpls_nh_flag;                  /**< [HB.GB.GG] MPLS nexthop flag, CTC_MPLS_NH_FLAG_XXXX*/

    ctc_mpls_nh_op_t   opcode;             /**< [HB.GB.GG] MPLS nexthop operation code*/
    ctc_nh_oif_info_t  oif;                /**< [HB.GB.GG] Outgoing interface for mpls POP nexthop.*/
    mac_addr_t mac;                        /**< [GG] MPLS nexthop outgoing MAC address*/
    mac_addr_t mac_sa;                     /**< [GG] MPLS nexthop outgoing MAC address for L3VPN to L2VPN*/
    ctc_vlan_egress_edit_info_t vlan_info; /**< [HB.GB.GG] VLAN edit information, used for layer2 VPN*/
};
typedef struct ctc_mpls_nexthop_com_param_s ctc_mpls_nexthop_com_param_t;

/**
 @brief  Define MPLS tunnel label nexthop parameter structure
*/
struct ctc_mpls_nexthop_tunnel_info_s
{
    ctc_mpls_nh_label_param_t  tunnel_label[CTC_MPLS_NH_MAX_TUNNEL_LABEL_NUM]; /**< [GB.GG] MPLS lable  information.Order:VC label-->Tunnel labell*/
    mac_addr_t mac;        /**< [GB.GG] MPLS nexthop outgoing MAC address*/
    ctc_nh_oif_info_t  oif;/**< [GB.GG] Outgoing interface.*/
    uint32 stats_id;       /**< [GB.GG] stats id*/
    uint8  stats_valid;    /**< [GB.GG] stats valid*/
    uint8  label_num;      /**< [GB.GG] the number of tunnel label,it may be 1,2 */
    uint8  is_spme;        /**< [GG] If label number is 1, use spme edit to add label*/
    uint16 arp_id;         /**< [GG] arp id */
};
typedef struct ctc_mpls_nexthop_tunnel_info_s ctc_mpls_nexthop_tunnel_info_t;

/**
 @brief  Define MPLS tunnel label  parameter structure
 */

/*

 if tunnel label have two layer label,taking LSP label & SPME label as a case;
         and if tunnel label have only one layer label,taking LSP label as a case
    if CTC_NH_MPLS_APS_EN & CTC_NH_MPLS_APS_2_LAYER_EN are set, aps_bridge_group_id is 2-level(Lsp) protection group id
                                    SPME label(w)  (nh_param)
              LSP label(w)------>                                (CTC_NH_MPLS_APS_2_LAYER_EN_PROTECTION isn't set)
                                    SPME label(p)   (nh_p_param)


                                    SPME label(w)   (nh_param)
              LSP label(P)------>                                (CTC_NH_MPLS_APS_2_LAYER_EN_PROTECTION is set)
                                    SPME label(p)   (nh_p_param)

    if CTC_NH_MPLS_APS_EN only is set, there are two case,aps_bridge_group_id is 2-level(Lsp) protection group id.

             (1) LSP label(w)------> SPME label  (-->nh_param)
                 LSP label(P)------> SPME label  (-->nh_p_param)
             (2)
                LSP label(w)  (-->nh_param)
                LSP label(P)  (-->nh_p_param)
*/
struct ctc_mpls_nexthop_tunnel_param_s
{
    ctc_mpls_nexthop_tunnel_info_t    nh_param; /**< [GB.GG] MPLS lable  information,Order :LSP label (w)-->SPME label (w)*/
    ctc_mpls_nexthop_tunnel_info_t    nh_p_param; /**< [GB.GG] MPLS lable  information,Order :LSP label(P)-->SPME label (w)*/
    uint32 aps_flag;                              /**< [GB.GG]ctc_mpls_nh_tunnel_aps_flag_type_t */
    uint16 aps_bridge_group_id;                   /**< [GB.GG] aps group id*/
};
typedef struct ctc_mpls_nexthop_tunnel_param_s ctc_mpls_nexthop_tunnel_param_t;
/**
 @brief  Define MPLS push nexthop parameter structure*/
struct ctc_mpls_nexthop_push_param_s
{
    ctc_mpls_nexthop_com_param_t nh_com;    /**< [HB.GB.GG] MPLS nexthop common information*/
    ctc_mpls_nh_label_param_t    push_label[CTC_MPLS_NH_MAX_PUSH_LABEL_NUM]; /**< [HB.GB.GG] MPLS lable  information,Order :PW label(inner label)->LSP Label ->SPME Label (outer label)*/
    uint8  martini_encap_valid;               /**< [HB.GB.GG] Martini label is valid*/
    uint8  martini_encap_type;                /**< [HB.GB.GG] Martini label encap type, 0: Fix mode; 1:specify Control Word*/
    uint32 stats_id;                          /**< [GB.GG] stats id*/
    uint8  stats_valid;                       /**< [GB.GG]pw stats is valid */
    uint8  mtu_check_en;                      /**< [HB.GB.GG] MTU check is enabled*/

    ctc_mpls_nh_martini_seq_type_t seq_num_type;  /**< [HB] Martini label sequence number type*/
    uint32 seq_num_index;                   /**< [GB.GG] if martini_encap_type set,indicate it is 32-bit CW;
	                                             or [HB] indicate it is sequence number index*/
    uint8 label_num;                        /**< [HB]the label_num include tunnel label & vc label,it may be 1,2,3;
                                                 [GB.GG]the label_num only include vc label,it may be 0,1;if nexthop is tunnel nexthop,it should be set to 0*/
    uint8  rsv0[1];                         /**< [HB.GB.GG] researve for future */

    uint16 tunnel_id;                       /**< [GB.GG]the tunnel id, will use it to find the tunnel info.*/

    uint16 mtu_size;                        /**< [HB.GB] MTU size for this nexthop */
};
typedef struct ctc_mpls_nexthop_push_param_s ctc_mpls_nexthop_push_param_t;

/**
 @brief  Define MPLS pop nexthop parameter structure
*/
struct ctc_mpls_nexthop_pop_param_s
{
    ctc_mpls_nexthop_com_param_t nh_com; /**< [HB.GB.GG] MPLS nexthop common information*/
    uint32   seq_num_index;              /**< [HB] Martini label sequence number index*/
    uint8    ttl_mode;                   /**< [HB.GB.GG] uniform/pipe/short pipe,refer cto ctc_mpls_tunnel_mode_e*/
    uint16   arp_id;                     /**< [GB.GG] arp id */
};
typedef struct ctc_mpls_nexthop_pop_param_s ctc_mpls_nexthop_pop_param_t;

/**
 @brief  Define MPLS switch nexthop parameter structure
*/
struct ctc_mpls_nexthop_switch_param_s
{
    uint32 gport;                         /**< [HB] outgoing interface */
    uint8           egs_vlan_valid;                /**< [HB] Optional, used for l2vpn*/
    ctc_vlan_egress_edit_info_t vlan_info;         /**< [HB] VLAN edit information, used for layer2 VPN*/
};
typedef struct ctc_mpls_nexthop_switch_param_s ctc_mpls_nexthop_switch_param_s;

/**
 @brief  Define MPLS nexthop property associated type emun
*/
enum ctc_mpls_nh_prop_e
{
    CTC_MPLS_NH_NONE,                /**< [HB.GB.GG]  any mpls nexthop */
    CTC_MPLS_NH_PUSH_TYPE,           /**< [HB.GB.GG]  mpls push nexthop */
    CTC_MPLS_NH_POP_TYPE,            /**< [HB.GB.GG]  mpls POP(Only apply to PHP) nexthop */
    CTC_MPLS_NH_SWITCH_TYPE,         /**< [HB]        mpls switch nexthop */
    CTC_MPLS_NH_PROP_TYPE_MAX
};
typedef enum ctc_mpls_nh_prop_e ctc_mpls_nh_prop_t;

/**
 @brief  Define MPLS nexthop operation type emun
*/
enum ctc_mpls_nh_operation_type_flag_e
{
    CTC_MPLS_NH_IS_UNRSV             = 0x00000001,  /**< [HB.GB.GG] if set, nexthop is unresolved nexthop  */
	CTC_MPLS_NH_IS_HVPLS             = 0x00000002,  /**< [HB.GB.GG] if set,Enable hvpls and disable split horizon in VPLS network*/

};
typedef enum ctc_mpls_nh_operation_type_flag_e ctc_mpls_nh_operation_type_flag_t;

/**
 @brief  Define MPLS nexthop parameter structure
*/
struct ctc_mpls_nexthop_param_s
{
    ctc_mpls_nh_prop_t nh_prop;               /**< [HB.GB.GG] MPLS nexthop property associated type --> ctc_mpls_nh_prop_t */
    ctc_nh_upd_type_t upd_type;               /**< [HB.GB.GG] nexthop update type ,used for update Operation*/
    uint32  dsnh_offset;                      /**< [HB] dsNexthop offset,if is_p_para_valid is enable ,when protected object is user service
                                                    (working and protection path's use different VC label ),it will occupy 2 entries dsNexthop
                                                     and the offset are dsnh_offset and dsnh_offset+1*/
    uint32   flag;                           /**<[HB.GB.GG] CTC_MPLS_NH_XX_XX,pls refer to ctc_mpls_nh_operation_type_flag_t */
    uint8    aps_en;                         /**<[HB.GB.GG] if set,[HB] indicate LSP layer APS enable;[GB.GG] indicate PW layer APS enable*/
    uint8    logic_port_valid;               /**<[HB.GB.GG] if set, indicated logic_port is valid.In VPLS networks,it should be set to 1. */
    uint8    adjust_length;                  /**<[GB.GG] The value of adjust length form 0 to 18. */

	uint16   aps_bridge_group_id;            /**<[HB.GB.GG]  the APS group ID of the nexthop,*/
    uint16   logic_port;                     /**<[HB.GB.GG] destination logic port in VPLS networks */

    union
    {
        ctc_mpls_nexthop_pop_param_t   nh_param_pop;      /**< [HB.GB.GG] mpls (asp) pop nexthop */
        ctc_mpls_nexthop_push_param_t  nh_param_push;     /**< [HB.GB.GG] mpls push (asp) nexthop */
        ctc_mpls_nexthop_switch_param_s nh_param_switch;  /**< [HB]mpls switch nexthop */
    }  nh_para;     /**< [HB.GB.GG] nexthop parameter used to create this nexthop */

    union
    {
        ctc_mpls_nexthop_pop_param_t   nh_p_param_pop;      /**< [HB.GB.GG] mpls asp pop nexthop */
        ctc_mpls_nexthop_push_param_t  nh_p_param_push;     /**< [HB.GB.GG] mpls push asp nexthop */
    }  nh_p_para;       /**< [HB.GB.GG] protection path's Nexthop parameter used to create this nexthop ,only used in create a mpls aps nexthop */
};
typedef struct ctc_mpls_nexthop_param_s ctc_mpls_nexthop_param_t;

/**
 @brief  Define loopback nexthop parameter structure
*/
struct ctc_loopback_nexthop_param_s
{
    uint8 customerid_valid;                  /**< [HB.GB.GG] If set, indicates the inner payload has an MPLS encapsulation or GRE key, which contains the customer ID as the label */
    uint8 map_vclabel_exp;                   /**< [HB] If set, indicates that the priority and color are mapped from the EXP field in VC label. this flag is only effective in MPLS VPN loopback */
    uint8 inner_packet_type_valid;           /**< [HB] This field indicates if the inner_packet_type is valid*/
    uint8 logic_port;                     /**< [HB.GB.GG] If set, indicates that the packet is from a VPLS tunnel port*/
    uint8 service_queue_en;                  /**< [HB] If set, indicates that the packets will do service queue processing*/
    uint8 sequence_en;                       /**< [HB] If set, indicates that the packets will do sequence order */
    ctc_parser_pkt_type_t inner_packet_type; /**< [HB] This field indicates the encapsulated packet type */
    uint16 lpbk_lport;                       /**< [HB.GB.GG] Loopback source local physical port, should not be linkagg port*/
    uint8 words_removed_from_hdr;           /**< [HB.GB.GG] 1 word stands for 4 bytes, not include customerId 4 bytes;*/
    uint8 sequence_counter_index;           /**< [HB] Sequence number counter index */
};
typedef struct ctc_loopback_nexthop_param_s ctc_loopback_nexthop_param_t;

/**
 @brief  Define remote mirror nexthop parameter structure
*/
struct ctc_rspan_nexthop_param_s
{
    uint16 rspan_vid;   /**<  [HB.GB.GG] RSPAN VLAN ID  */
    uint8  remote_chip;   /**<[GB.GG] if set,indicate it is crosschip RSPAN nexthop*/
    uint8  rsv;

    uint32 dsnh_offset; /**< [HB] DsNextHop offset */
};
typedef struct ctc_rspan_nexthop_param_s ctc_rspan_nexthop_param_t;

/**
 @brief  Define Misc Nexthop l2/L3 edit flags
*/
enum ctc_misc_nh_edit_flag_e
{
    CTC_MISC_NH_L2_EDIT_REPLACE_MAC_DA      = 0x00000001,   /**< [HB.GB] Will replace layer2 header mac da */
    CTC_MISC_NH_L2_EDIT_REPLACE_MAC_SA      = 0x00000002,   /**< [HB.GB] Will replace layer2 header mac sa */
    CTC_MISC_NH_L2_EDIT_SWAP_MAC            = 0x00000004,   /**< [HB.GB] Will swap layer2 header mac da & sa, cannot mix with other types */
    CTC_MISC_NH_L2_EDIT_VLAN_EDIT           = 0x00000008,   /**< [GB] Will do vlan edit */
    CTC_MISC_NH_L3_EDIT_REPLACE_IPDA        = 0x00000010,   /**< [GB] Will replace ipda */
    CTC_MISC_NH_L3_EDIT_REPLACE_DST_PORT    = 0x00000020,   /**< [GB] Will replace dst port */
    CTC_MISC_NH_L2_EDIT_REPLACE_SVLAN_TAG   = 0x00000040   /**< [HB] Replace svlan only used in humber */
};

/**
 @brief  Define Misc nexthop L2 Edit parameter structure
*/
struct ctc_misc_nh_l2edit_param_s
{

    uint32       flag;                          /**< [HB.GB.GG] CTC_MISC_NH_L2_EDIT_XXX */

    mac_addr_t   mac_da;                        /**< [HB.GB.GG] Mac destination address */
    mac_addr_t   mac_sa;                        /**< [HB.GB.GG] Mac source address */
    uint16       vlan_id;                       /**< [HB.GB.GG] Vlan id */
    uint8        is_reflective;                /**< [GB.GG] if set,packet will be reflectived to ingress port */
    uint8        rsv[1];                           /**< [HB.GB.GG] reserved */

};
typedef struct ctc_misc_nh_l2edit_param_s ctc_misc_nh_l2edit_param_t;

/**
 @brief  Define Misc nexthop L2/L3 Edit parameter structure
*/
struct ctc_misc_nh_l2_l3edit_param_s
{
    uint32       flag;                          /**< [GB] CTC_MISC_NH_L2_EDIT_XXX */
    mac_addr_t   mac_da;                        /**< [GB] Mac destination address */
    mac_addr_t   mac_sa;                        /**< [GB] Mac source address */

    uint32       dst_port;                      /**< [GB] dst-port */
    uint8        is_reflective;                 /**< [GB] if set,packet will be reflectived to ingress port */
    uint8        rsv;                        /**< [GB] reserved */
    uint32       ipda;                          /**< [GB] ipda */
    ctc_vlan_egress_edit_info_t vlan_edit_info;   /**< [GB] while egress valn nexthop : Egress vlan edit information ; while ASP Egress Vlan Editing nexthop : Egress vlan edit information of working path*/
};
typedef struct ctc_misc_nh_l2_l3edit_param_s ctc_misc_nh_l2_l3edit_param_t;
/**
 @brief  Define cpu reason nexthop parameter structure
*/
struct ctc_misc_nh_cpu_reason_param_s
{
    uint16  cpu_reason_id;      /**< [GB.GG] ctc_pkt_cpu_reason_t */
};
typedef struct ctc_misc_nh_cpu_reason_param_s ctc_misc_nh_cpu_reason_param_t;
/**
 @brief  Define Misc nexthop Flex Edit flags
*/
enum ctc_misc_nh_flex_edit_flag_e
{
   /*L2*/
    CTC_MISC_NH_FLEX_EDIT_REPLACE_L2_HDR    = 0x00000001,         /**< [GG] replace l2 header  */
    CTC_MISC_NH_FLEX_EDIT_SWAP_MACDA        = 0x00000002,         /**< [GG] swap macda/macsa  */
    CTC_MISC_NH_FLEX_EDIT_REPLACE_MACDA     = 0x00000004,      /**< [GG] mac destination address */
    CTC_MISC_NH_FLEX_EDIT_REPLACE_MACSA     = 0x00000008,      /**< [GG] mac source address*/
    CTC_MISC_NH_FLEX_EDIT_REPLACE_ETHERTYPE = 0x00000010,      /**< [GG] etherType*/
    CTC_MISC_NH_FLEX_EDIT_REPLACE_VLAN_TAG  = 0x00000020,      /**< [GG] Vlan tag*/

   /*IP*/
   CTC_MISC_NH_FLEX_EDIT_REPLACE_IP_HDR     = 0x00000100,         /**< [GG] replace ip header */
   CTC_MISC_NH_FLEX_EDIT_REPLACE_IPDA       = 0x00000200,           /**< [GG] ipda*/
   CTC_MISC_NH_FLEX_EDIT_REPLACE_IPSA       = 0x00000400,           /**< [GG] ipsa*/
   CTC_MISC_NH_FLEX_EDIT_SWAP_IP            = 0x00000800,           /**< [GG] swap packet ipsa and ipda*/

   CTC_MISC_NH_FLEX_EDIT_REPLACE_ECN        = 0x00002000,           /**< [GG] replace ecn*/
   CTC_MISC_NH_FLEX_EDIT_REPLACE_TTL        = 0x00004000,           /**< [GG] replace ttl is high priority*/
   CTC_MISC_NH_FLEX_EDIT_DECREASE_TTL       = 0x00008000,          /**< [GG] decrease ttl */
   CTC_MISC_NH_FLEX_EDIT_REPLACE_PROTOCOL   = 0x00010000,       /**< [GG] replace protocol */
   CTC_MISC_NH_FLEX_EDIT_REPLACE_FLOW_LABEL = 0x00020000,      /**< [GG] replace flow label*/
   CTC_MISC_NH_FLEX_EDIT_IPV4               = 0x00040000,      /**< [GG] ipv4/ipv6*/

   CTC_MISC_NH_FLEX_EDIT_REPLACE_L4_HDR     = 0x10000000,         /**< [GG] replace L4 header (include udp/tcp/gre/icmp)  */
  /*tcp/udp*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_L4_SRC_PORT  = 0x00100000,     /**< [GG] replace udp/tcp src port */
  CTC_MISC_NH_FLEX_EDIT_REPLACE_L4_DST_PORT  = 0x00200000,     /**< [GG] replace udp/tcp dst port*/
  CTC_MISC_NH_FLEX_EDIT_SWAP_L4_PORT         = 0x00400000,     /**< [GG] swap packet src and dst port */
  CTC_MISC_NH_FLEX_EDIT_REPLACE_UDP_PORT     = 0x00800000,     /**< [GG] replace udp/tcp src port */
  CTC_MISC_NH_FLEX_EDIT_REPLACE_TCP_PORT     = 0x01000000,     /**< [GG] replace udp/tcp src port */

  /*GRE*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_GRE_KEY  = 0x00100000,         /**< [GG] replace GRE Key  */

  /*ICMP*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_ICMP_TYPE  = 0x00100000,       /**< [GG] replace ICMP Type*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_ICMP_CODE  = 0x00200000,       /**< [GG] replace ICMP Code */

 /*ARP*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_ARP_HDR  = 0x00000100,         /**< [GG] replace arp header */
  CTC_MISC_NH_FLEX_EDIT_REPLACE_ARP_HT   = 0x00000200,         /**< [GG] format of hardware type*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_ARP_PT   = 0x00000400,         /**< [GG] format of protocol type*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_ARP_HLEN = 0x00001000,         /**< [GG] length of hardware address*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_ARP_PLEN = 0x00002000,         /**< [GG] length of protocol address*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_ARP_OP   = 0x00004000,         /**< [GG] ARP Opcode*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_ARP_SHA  = 0x00008000,         /**< [GG] sender hardware address*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_ARP_SPA  = 0x00010000,         /**< [GG] sender protocol address*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_ARP_THA  = 0x00020000,         /**< [GG] target hardware address*/
  CTC_MISC_NH_FLEX_EDIT_REPLACE_ARP_TPA  = 0x00040000          /**< [GG] target protocol address */


 };
typedef enum ctc_misc_nh_flex_edit_flag_e ctc_misc_nh_flex_edit_flag_t;


/**
 @brief  Define flex nexthop use packet type
*/
enum ctc_misc_nh_packet_type_e
{
    CTC_MISC_NH_PACKET_TYPE_NONE,      /**< [GG] other packet */
    CTC_MISC_NH_PACKET_TYPE_ARP,       /**< [GG] arp packet*/
    CTC_MISC_NH_PACKET_TYPE_ICMP,      /**< [GG] icmp packet */
    CTC_MISC_NH_PACKET_TYPE_GRE,       /**< [GG] gre packet*/
    CTC_MISC_NH_PACKET_TYPE_UDPORTCP,  /**< [GG] tcp or udp packet */
    CTC_MISC_NH_PACKET_TYPE_MAX
};
typedef enum ctc_misc_nh_packet_type_e ctc_misc_nh_packet_type_t;

/**
 @brief  Define flex nexthop parameter structure
*/
struct ctc_misc_nh_flex_edit_param_s
{

    uint32       flag;                          /**< [GG] CTC_MISC_NH_FLEX_EDIT__XXX */
	uint8        is_reflective;                 /**< [GG] if set,packet will be reflectived to ingress port */

    uint8        packet_type;                   /**< [GG] CTC_MISC_NH_PACKET_TYPE__XXX */

   /*L2 Header*/
    mac_addr_t   mac_da;                        /**< [GG] Mac destination address */
    mac_addr_t   mac_sa;                        /**< [GG] Mac source address */
    uint16       ether_type;                    /**< [GG] Ether TYPE*/

   /*vlan edit*/
    ctc_vlan_tag_op_t      stag_op;         /**< [GG] operation type of stag, see ctc_vlan_tag_op_t struct*/
    ctc_vlan_tag_sl_t      svid_sl;         /**< [GG] operation type of svlan id, see ctc_vlan_tag_sl_t struct*/
    ctc_vlan_tag_sl_t      scos_sl;         /**< [GG] operation type of scos, see ctc_vlan_tag_sl_t struct*/

    ctc_vlan_tag_op_t      ctag_op;         /**< [GG] operation type of ctag, see ctc_vlan_tag_op_t struct*/
    ctc_vlan_tag_sl_t      cvid_sl;         /**< [GG] operation type of cvlan id, see ctc_vlan_tag_sl_t struct*/
    ctc_vlan_tag_sl_t      ccos_sl;         /**< [GG] operation type of ccos, see ctc_vlan_tag_sl_t struct*/

	uint8  new_stpid_en;                    /**< [GG] new svid tpid enable */
    uint8 new_stpid_idx;                   /**< [GG] new svid tpid index */
    uint16 new_svid;                        /**< [GG] new svid */
    uint16 new_cvid;                        /**< [GG] new cvid*/
    uint8  new_scos;                        /**< [GG] new stag cos*/
    uint8  new_ccos;                        /**< [GG] new ctag cos*/

   /*IP Header*/
    union
    {
        ip_addr_t   ipv4; /**< [GG] Ip version 4 address */
        ipv6_addr_t ipv6; /**< [GG] Ip version 6 address */
    } ip_sa;              /**< [GG] New ip sa address in ip header*/

    union
    {
        ip_addr_t   ipv4; /**< [GG] Ip version 4 address */
        ipv6_addr_t ipv6; /**< [GG] Ip version 6 address */
    } ip_da;
	uint8  protocol;       /**< [GG] protocol type */
	uint8  ttl;            /**< [GG] ttl */
	uint8  ecn;            /**< [GG] ecn */
	uint8  dscp_select;    /**< [GG] Dscp select mode,refer to ctc_nh_dscp_select_mode_t*/
    uint8  dscp_or_tos;    /**< [GG] Dscp value for Ip version 4 , tos for Ip version 6 */

	uint32 flow_label;     /**< [GG] flow label */

   /*UDP/TCP Port*/
    uint16 l4_src_port;  /**< [GG] L4 source Port */
    uint16 l4_dst_port;  /**< [GG] L4 dest Port */

	/*GRE KEY*/
    uint32 gre_key;/**< [GG] GRE Key */

	/*ICMP*/
	uint8  icmp_type;   /**< [GG] ICMP type */
	uint8  icmp_code;    /**< [GG] ICMP Code */

	/*ARP*/
    uint16  arp_ht;    /**< [GG] hardware type */
    uint16  arp_pt;    /**< [GG] protocol type */
    uint8   arp_halen; /**<[GG] length of hardware address */
    uint8   arp_palen; /**< [GG]length of protocol address */
    uint16  arp_op;    /**< [GG]ARP/RARP operation */
    mac_addr_t   arp_sha; /**<[GG] sender hardware address */
    mac_addr_t   arp_tha; /**<[GG] target hardware address */
	uint32  arp_spa;      /**< [GG]sender protocol address */
    uint32  arp_tpa;      /**< [GG]target protocol address */

};
typedef struct ctc_misc_nh_flex_edit_param_s ctc_misc_nh_flex_edit_param_t;


/**
 @brief  Define over l2 nexthop parameter structure
*/
struct ctc_misc_nh_over_l2_edit_param_s
{
    mac_addr_t   mac_da;                        /**< [GG] Mac destination address */
    mac_addr_t   mac_sa;                        /**< [GG] Mac source address */
    uint16       ether_type;                    /**< [GG] Ether TYPE*/

    uint16       vlan_id;                       /**< [GG] vlan id */
    uint16       flow_id;                       /**< [GG] flow id*/
};
typedef struct ctc_misc_nh_over_l2_edit_param_s ctc_misc_nh_over_l2_edit_param_t;

/**
 @brief  Define flex nexthop flag
*/
enum ctc_misc_nh_type_e
{
    CTC_MISC_NH_TYPE_REPLACE_L2HDR,     /**< [HB.GB] Replace layer2 header */
    CTC_MISC_NH_TYPE_REPLACE_L2_L3HDR,  /**< [HB.GB] Replace layer2 header and ipda & destport*/
    CTC_MISC_NH_TYPE_TO_CPU,            /**< [GB.GG] Send to CPU with specified reason */
    CTC_MISC_NH_TYPE_FLEX_EDIT_HDR,     /**< [GG] Flex edit layer2/Layer3/layer4 header*/
    CTC_MISC_NH_TYPE_OVER_L2_WITH_TS    /**< [GG] Add layer2 header with time stamp
                                                macda+macsa+vlan+ether_type+flowid+source port+ time stamp
                                            */
};
typedef enum ctc_misc_nh_type_e ctc_misc_nh_type_t;

/**
@brief  Define flex nexthop parameter structure
*/
struct ctc_misc_nh_param_s
{

    uint8    type;             /**< [GB.GG] CTC_MISC_NH_TYPE_XXX */
    uint8    rsv;
    uint32 gport;            /**< [GB.GG] Dest global port id ,if is_reflective is set, the gport is invalid*/
    uint32   dsnh_offset;      /**<  DsNextHop offset */

    union
    {
        ctc_misc_nh_l2edit_param_t     l2edit;   /**<  [GB] L2Edit parameter */
        ctc_misc_nh_l2_l3edit_param_t  l2_l3edit;/**<  [GB] L2Edit/L3Edit parameter */
        ctc_misc_nh_cpu_reason_param_t cpu_reason;/**< [GB.GG] To Cpu parameter */
        ctc_misc_nh_flex_edit_param_t  flex_edit;/**<  [GG] Flex packet edit parameter */
        ctc_misc_nh_over_l2_edit_param_t over_l2edit;/**< [GG] Over l2 eidt parameter */
    }
    misc_param;
}
;
typedef struct ctc_misc_nh_param_s ctc_misc_nh_param_t;

/**
 @brief  Define mcast nexthop operation code
*/
enum ctc_mcast_nh_param_opcode_e
{
    CTC_NH_PARAM_MCAST_NONE                  = 0, /**< [HB.GB.GG] None */
    CTC_NH_PARAM_MCAST_ADD_MEMBER            = 1, /**< [HB.GB.GG] Add mcast member */
    CTC_NH_PARAM_MCAST_DEL_MEMBER            = 2  /**< [HB.GB.GG] Del mcast member */
};
typedef enum ctc_mcast_nh_param_opcode_e ctc_mcast_nh_param_opcode_t;

/**
 @brief  Define mcast nexthop member type
*/
enum ctc_mcast_nh_param_member_type_s
{
    CTC_NH_PARAM_MEM_BRGMC_LOCAL = 0,       /**< [HB.GB.GG] Bridge mcast member  */
    CTC_NH_PARAM_MEM_IPMC_LOCAL,            /**< [HB.GB.GG] IP mcast member  */
    CTC_NH_PARAM_MEM_LOCAL_WITH_NH,         /**< [HB.GB.GG] Mcast member with nexthop */
    CTC_NH_PARAM_MEM_REMOTE,                /**< [HB.GB.GG] Remote member  */
    CTC_NH_PARAM_MEM_INVALID                /**< [HB.GB.GG] Invalid mcast member  */
};
typedef enum ctc_mcast_nh_param_member_type_s ctc_mcast_nh_param_member_type_t;

/**
 @brief  Define mcast nexthop member parameter structure
*/
struct ctc_mcast_nh_param_member_s
{
    ctc_mcast_nh_param_member_type_t member_type;   /**< [HB.GB.GG] Mcast member type */
    uint32  ref_nhid;               /**< [HB.GB.GG] Reference other nhid, eg egress vlan translation nhid */
    uint32  destid;                 /**< [HB.GB.GG] Local member:local portid(gchip(8bit) +local phy port(8bit)), LAGID(eg.0x1F01)/remote chip member: gchip(local) + remote gchip id(8bit) */
    uint16  vid;                    /**< [HB.GB.GG] For IPMC */
    uint8   lchip;                  /**< [HB.GB.GG] Local chip this member will be added to */
    uint8   l3if_type;              /**< [HB.GB.GG] ctc_l3if_type_t */
    uint8   is_vlan_port;           /**< [HB.GB.GG] If set and  l3if is vlan interface , output packet only do L2 bridging . */
    uint8   is_reflective;          /**< [GG] If set ,Mcast reflective  valid except member_type is CTC_NH_PARAM_MEM_IPMC_LOCAL */
    uint8   is_source_check_dis;    /**< [GB.GG] If set ,Mcast packet will not check source and dest port, else check*/
    uint8   rsv0[1];
};
typedef struct ctc_mcast_nh_param_member_s ctc_mcast_nh_param_member_t;

/**
 @brief  Define mcast nexthop parametes structure
*/
struct ctc_mcast_nh_param_group_s
{
    uint16                        mc_grp_id;    /**< [HB.GB.GG] Identify a group */
    uint8                         opcode;       /**< [HB.GB.GG] ctc_mcast_nh_param_opcode_t */
    uint8                         is_mirror;    /**< [HB.GB.GG] if set,indicate the a mcast  group is applied to mirror */
    uint8                         stats_en;     /**< [GB.GG] if set,indicate stats is enable */
    ctc_mcast_nh_param_member_t   mem_info;     /**< [HB.GB.GG] Mcast member info */
    uint32                        stats_id;     /**< [GB.GG] Stats id */
};
typedef struct ctc_mcast_nh_param_group_s ctc_mcast_nh_param_group_t;

/**
 @brief  Define nexthop information flag
*/
enum ctc_nh_info_flag_e
{
    CTC_NH_INFO_FLAG_IS_UNROV   = 0x0001, /**< [GB.GG] Indicate unrovle nexthop,packet will be discarded */
    CTC_NH_INFO_FLAG_IS_DSNH8W = 0x0002,  /**< [GB.GG] Indicate DsNexthop is double wide table */
    CTC_NH_INFO_FLAG_IS_APS_EN  = 0x0004, /**< [GB.GG] Indicate Aps enable */
    CTC_NH_INFO_FLAG_IS_DISCARD = 0x0008,
    CTC_NH_INFO_FLAG_IS_MCAST   = 0x0010, /**< [GB.GG] Indicate Mcast Nexthop */
    CTC_NH_INFO_FLAG_IS_ECMP    = 0x0020  /**< [GB.GG] Indicate ECMP Nexthop */
};
typedef enum ctc_nh_info_flag_e ctc_nh_info_flag_t;

/**
 @brief  Define nexthop information structure
*/
struct ctc_nh_info_s
{
   uint32   flag;              /**< [GB.GG] CTC_NH_INFO_FLAG_XX, pls refer to ctc_nh_info_flag_t*/
   uint32   dsnh_offset[CTC_MAX_LOCAL_CHIP_NUM];  /**< DsNextHop offset */
   uint32 gport;             /**< [GB.GG]if CTC_NH_INFO_FLAG_IS_APS_EN set,it is aps group id;
                                        else if CTC_NH_INFO_FLAG_IS_MCAST set,mcast group id;
                                        else gport   */

   uint8    ecmp_cnt;          /*[GB.GG] include resoved & unresoved nexthop member*/
   uint8    valid_ecmp_cnt;    /*[GB.GG] valid(resoved) member*/
   uint32   ecmp_mem_nh[CTC_MAX_ECPN]; /*[GB.GG] valid nh array[valid_cnt] -->unresoved nh*/

    /*mcast  information*/
    ctc_mcast_nh_param_member_t* buffer;      /**<[GB] [in/out] A buffer store query results */
    uint32  start_index;        /**<[GB] [in] If it is the first query, it is equal to 0, else it is equal to the last next_query_index */
    uint32  next_query_index;   /**<[GB] [out] return index of the next query */
    uint8   is_end;             /**<[GB] [out] if is_end == 1, indicate the end of query */
    uint8   rsv;                /**< reserved*/
    uint16  buffer_len;         /**<[GB] [in]multiple of sizeof(ctc_mcast_nh_param_member_t) */
    uint32  valid_number;       /**<[GB] [out] The valid numbers */

};
typedef struct ctc_nh_info_s ctc_nh_info_t;

/**
 @brief  Define nexthop stats type
*/
enum ctc_nh_stats_type_e
{
    CTC_NH_STATS_TYPE_NHID         = 0x0001,    /**< [HB.GB.GG] indicate nhid */
    CTC_NH_STATS_TYPE_TUNNELID     = 0x0002     /**< [GB.GG] indicate mpls tunnel id */
};
typedef enum ctc_nh_stats_type_e ctc_nh_stats_type_t;

/**
 @brief  Define nexthop stats structure
*/
struct ctc_nh_stats_info_s
{
    uint8 stats_type;           /**< [HB.GB.GG] stats type, refer to ctc_nh_stats_type_t */
    uint8 is_protection_path;   /**< [GB.GG] protection path */
    union
    {
        uint16 nhid;            /**< [HB.GB.GG] nexthop id */
        uint16 tunnel_id;       /**< [GB.GG] mpls tunnel id */
    }id;

    ctc_stats_basic_t stats;    /**< [HB.GB.GG] output stats data */
};
typedef struct ctc_nh_stats_info_s ctc_nh_stats_info_t;


/**
 @brief  Define set nexthop drop data structure
*/
struct ctc_nh_drop_info_s
{
    uint8 drop_en;               /**< [GB] drop en, If set data  drop, else not */
    uint8 is_protection_path;    /**< [GB] protection path */
};
typedef struct ctc_nh_drop_info_s  ctc_nh_drop_info_t;


/**
 @brief  Define trill nexthop operation type emun
*/
enum ctc_nh_trill_flag_e
{
    CTC_NH_TRILL_IS_UNRSV             = 0x00000001,  /**< [GG] If set, nexthop is unresolved nexthop  */
    CTC_NH_TRILL_MTU_CHECK            = 0x00000002,  /**< [GG] If set , means mtu check enable*/
};
typedef enum ctc_nh_trill_flag_e ctc_nh_trill_flag_t;

/**
 @brief  Define trill tunnel nexthop structure
*/
struct ctc_nh_trill_param_s
{
    uint32 flag;                 /**< [GG] TRILL nexthop flag, refer to ctc_nh_trill_flag_t*/
    ctc_nh_upd_type_t upd_type;  /**< [GG] nexthop update type ,used for update Operation*/
    ctc_nh_oif_info_t oif;       /**< [GG] Outgoing port or interface, and outer Vlan*/
    mac_addr_t mac;              /**< [GG] If encap packet directly send out,it is nexthop router mac,else it is invalid */
    uint32 dsnh_offset;          /**< [GG] If Chipset use Egress chip Edit mode ,
                                               the dsnh_offset is allocated in platform adaption Layer;
                                               else the dsnh_offset is internally allocated in SDK */
    uint16 ingress_nickname;     /**< [GG] Ingress nickname of TRILL header*/
    uint16 egress_nickname;      /**< [GG] Egress nickname of TRILL header*/

    uint8 ttl;                   /**< [GG] Hop count of TRILL header*/
    uint8 rsv;
    uint16 mtu_size;             /**< [GG] MTU size for this nexthop */

    uint32 stats_id;             /**< [GG] Stats id, 0 is disable */
};
typedef struct ctc_nh_trill_param_s ctc_nh_trill_param_t;



/**@} end of @defgroup  nexthop */

#ifdef __cplusplus
}
#endif

#endif /*!_CTC_NEXTHOP_H*/

