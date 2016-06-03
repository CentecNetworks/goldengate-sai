/**
 @file ctc_mpls.h

 @author Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2010-03-11

 @version v2.0

   This file contains all mpls related data structure, enum, macro and proto.
*/

#ifndef _CTC_MPLS_H
#define _CTC_MPLS_H
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
 @defgroup mpls MPLS
 @{
*/

/**
 @brief  Define mpls label type
*/
enum ctc_mpls_label_type_e
{
    CTC_MPLS_LABEL_TYPE_NORMAL,      /**< [HB.GB.GG] This label is a normal label */
    CTC_MPLS_LABEL_TYPE_L3VPN,       /**< [HB.GB.GG] This label is a l3vpn VC label */
    CTC_MPLS_LABEL_TYPE_VPWS,        /**< [HB.GB.GG] This label is a vpws VC label */
    CTC_MPLS_LABEL_TYPE_VPLS,        /**< [HB.GB.GG] This label is a vpls VC label */
    CTC_MPLS_LABEL_TYPE_GATEWAY,     /**< [GG] This label is a VC label attach to fid and vrf */
    CTC_MPLS_MAX_LABEL_TYPE
};

/**
 @brief  Define mpls tunnel mode
*/
enum ctc_mpls_id_type_e
{
    CTC_MPLS_ID_NULL       = 0x0,       /**< [HB.GB.GG] NULL */
    CTC_MPLS_ID_FLOW       = 0x1,       /**< [HB.GB] The ILM use flow policer */
    CTC_MPLS_ID_VRF        = 0x2,       /**< [HB.GB.GG] The ILM use vrfid, only for l3vpn vc label */
    CTC_MPLS_ID_SERVICE    = 0x4,       /**< [HB.GB.GG] The ILM use qos, only for l2vpn vc label */
    CTC_MPLS_ID_APS_SELECT = 0x8,       /**< [HB.GB.GG] The aps select group id, only for l2vpn vc label */
    CTC_MPLS_ID_STATS      = 0x10,      /**< [HB.GB.GG] The ILM use stats */
    CTC_MPLS_MAX_ID        = 0xff
};

/**
 @brief  Define mpls pw mode
*/
enum ctc_mpls_l2vpn_pw_mode_e
{
    CTC_MPLS_L2VPN_TAGGED,      /**< [GB.GG] The PW mode is TAGGED */
    CTC_MPLS_L2VPN_RAW,         /**< [GB.GG] The PW mode is RAW */
    CTC_MPLS_MAX_L2VPN_MODE
};

/**
 @brief  Define mpls ac bind type
*/
enum ctc_mpls_ac_bind_type_e
{
    CTC_MPLS_BIND_ETHERNET,      /**< [HB] The AC bind type is port */
    CTC_MPLS_BIND_SVLAN,         /**< [HB] The customer vlan is svlan */
    CTC_MPLS_BIND_CVLAN,         /**< [HB] The customer vlan is cvlan */
    CTC_MPLS_MAX_BIND_TYPE
};

/**
 @brief  Define l2vpn type
*/
enum ctc_mpls_l2vpn_type_e
{
    CTC_MPLS_L2VPN_VPWS,      /**< [HB.GB.GG] The L2VPN is VPWS */
    CTC_MPLS_L2VPN_VPLS,      /**< [HB.GB.GG] The L2VPN is VPLS */
    CTC_MPLS_MAX_L2VPN_TYPE
};

enum ctc_mpls_label_size_type_e
{
    CTC_MPLS_LABEL_NUM_64_TYPE      = 0,  /**< [GB] */
    CTC_MPLS_LABEL_NUM_128_TYPE     = 1,  /**< [GB] */
    CTC_MPLS_LABEL_NUM_256_TYPE     = 2,  /**< [GB] */
    CTC_MPLS_LABEL_NUM_512_TYPE     = 3,  /**< [GB] */
    CTC_MPLS_LABEL_NUM_1K_TYPE      = 4,  /**< [GB] */
    CTC_MPLS_LABEL_NUM_2K_TYPE      = 5,  /**< [GB] */
    CTC_MPLS_LABEL_NUM_4K_TYPE      = 6,  /**< [GB] */
    CTC_MPLS_LABEL_NUM_8K_TYPE      = 7,  /**< [GB] */
    CTC_MPLS_LABEL_NUM_16K_TYPE     = 8,  /**< [GB] */
    CTC_MPLS_LABEL_NUM_32K_TYPE     = 9,  /**< [GB] */
    CTC_MPLS_LABEL_NUM_64K_TYPE     = 10, /**< [GB] */
    CTC_MPLS_LABEL_NUM_128K_TYPE    = 11, /**< [GB] */
    CTC_MPLS_LABEL_NUM_256K_TYPE    = 12, /**< [GB] */
    CTC_MPLS_LABEL_NUM_512K_TYPE    = 13, /**< [GB] */
    CTC_MPLS_LABEL_NUM_1024K_TYPE   = 14, /**< [GB] */
    CTC_MPLS_LABEL_NUM_2048K_TYPE   = 15, /**< [GB] */
    CTC_MPLS_LABEL_NUM_MAX_TYPE
};

/**
 @brief define ip version
*/
enum ctc_mpls_inner_pkt_type_e
{
    CTC_MPLS_INNER_IP,     /**< [GB.GG] IP version 4 or IP version 6 */
    CTC_MPLS_INNER_IPV4,   /**< [GB.GG] IP version 4 */
    CTC_MPLS_INNER_IPV6,   /**< [GB.GG] IP version 6 */
    CTC_MPLS_INNER_RAW,    /**< [GB.GG] Don't check inner packet by parser */
    MAX_MPLS_CTC_VER
};
typedef enum ctc_mpls_inner_pkt_type_e ctc_mpls_inner_pkt_type_t;

enum ctc_mpls_ilm_flag_e
{
   CTC_MPLS_ILM_FLAG_ASSIGN_OUTPUT_PORT = 1U << 0,      /**<[GG] if set ,indicate the output port will get by MPLS module,not by nhid */

   CTC_MPLS_ILM_FLAG_L2VPN_OAM          = 1U << 1,      /**< [GG] indecate L2VPN OAM, need config l2vpn_oam_id*/
   CTC_MPLS_ILM_FLAG_SERVICE_ACL_EN     = 1U << 2,      /**< [GG] enable OAM feature*/
   CTC_MPLS_ILM_FLAG_SERVICE_POLICER_EN = 1U << 3,      /**< [GG] if the bit not set and policer-id isn't 0,it's flow policer*/
   CTC_MPLS_ILM_FLAG_ACL_USE_OUTER_INFO = 1U << 4,      /**< [GG] if set, acl match rule will use mpls packet outer information */
   CTC_MPLS_ILM_FLAG_BOS_LABLE  = 1U << 5,              /**< [GG] if set, the normal label is VC label */

   CTC_MPLS_ILM_FLAG_MAX
};
typedef enum ctc_mpls_ilm_flag_e ctc_mpls_ilm_flag_t;

/**
 @brief define mpls ilm update type
*/
enum ctc_mpls_ilm_property_type_e
{
    CTC_MPLS_ILM_DATA_DISCARD,      /**< [GB.GG] Update to discard data, not OAM , for lock use. value 1, discard; 0, not discard */
    CTC_MPLS_ILM_QOS_DOMAIN,        /**< [GB.GG] Update Qos domain, value is qos domain, 1~7 is valid value, 0 means disable */
    CTC_MPLS_ILM_APS_SELECT,        /**< [GB.GG] Update Aps select info, value is ctc_mpls_ilm_t  */
    CTC_MPLS_ILM_OAM_TOCPU,         /**< [GG] Set Oam packet direct to CPU  */
    CTC_MPLS_ILM_ROUTE_MAC,         /**< [GG] Bind the L3 payload router mac with ilm, and void *value is mac_addr_t*  */
    CTC_MPLS_ILM_LLSP,              /**< [GB.GG] L-LSP enable, use lable to mapping PHB  */
    CTC_MPLS_ILM_MAX
};
typedef enum ctc_mpls_ilm_property_type_e ctc_mpls_ilm_property_type_t;


/**
 @brief  Define mpls stats index
*/
struct ctc_mpls_stats_index_s
{
    uint32 stats_id;/**< [GB] Stats id */
    uint32 label;   /**< [HB.GB] MPLS label */
    uint8 spaceid;  /**< [HB.GB] Label space id */
};
typedef struct ctc_mpls_stats_index_s ctc_mpls_stats_index_t;

/**
 @brief  Define mpls parameter structure
*/
struct ctc_mpls_ilm_s
{
    uint32 label;                   /**< [HB.GB.GG] In label */
    uint32 flag;                    /**< [GG] CTC_MPLS_ILM_FLAG_XXX */
    uint32 nh_id;                   /**< [HB.GB.GG] Nexthop ID, pop mode don't need to config nexthop,in pop mode use drop nh */
    uint32 gport;                   /**< [GG] valid when CTC_MPLS_ILM_FLAG_ASSIGN_OUTPUT_PORT is set */
    uint32 stats_id;                /**< [GB.GG] Stats id */
    uint16 pwid;                    /**< [HB.GB.GG] PW ID, VPLS use PW ID to bridge packets in instance, 0xffff means not used */
    union
    {
        uint16 flow_id;             /**< [HB.GB] The ILM use flow policer */
        uint16 vrf_id;              /**< [HB.GB] The ILM use vrfid, only for l3vpn vc label */
        uint16 service_id;          /**< [HB.GB] The ILM use qos, only for l2vpn vc label */
        uint16 aps_select_grp_id;   /**< [HB.GB] The aps select group id, only only for l2vpn vc label */
    } flw_vrf_srv_aps;

    uint8 id_type;                  /**< [HB.GB] flw_vrf_srv_aps value with which type */
    uint8 spaceid;                  /**< [HB.GB.GG] Label space ID */
    uint8 type;                     /**< [HB.GB.GG] Label type, should be one of the ctc_mpls_label_type_e value */
    uint8 model;                    /**< [HB.GB.GG] Tunnel mode, should be one of the ctc_mpls_tunnel_mode_e value */
    uint8 cwen;                     /**< [HB.GB.GG] Control word enable, if label is a l2vpn vc label, the PW control word function maybe enable */
    uint8 pop;                      /**< [HB.GB.GG] Whether the label is POP label or not, only used when label type is normal */
    uint8 decap;                    /**< [GB.GG] Whether the inner packet will decap in pop mode*/
    uint8 aps_select_protect_path;  /**< [HB.GB.GG] If id_type is CTC_MPLS_ID_APS_SELECT and it is set, indicate the path is aps protect path,else the path is working path */
    uint8 logic_port_type;          /**< [HB.GB.GG] The VPLS PW is a H-VPLS tunnel */
    uint8 oam_en;                   /**< [HB.GB.GG] Enable OAM */
    uint8 trust_outer_exp;          /**< [HB.GB.GG] Trust outer label exp */
    uint8 inner_pkt_type;           /**< [GB.GG] Inner packet type used for ipv6 */
    uint8 qos_use_outer_info;       /**< [GB.GG] If set, use outer parse info for qos */
    uint8 out_intf_spaceid;         /**< [GB.GG] Interafce label space ID, pop label can generate an interface label space. */
    uint16 aps_select_grp_id;       /**< [GG] The aps select group id, only only for l2vpn vc label */
    uint8  svlan_tpid_index;        /**< [GB.GG] svlan tpid index*/
    uint8 pw_mode;                  /**< [GB.GG] pw mode only used for goldengate, when PW is raw mode, dsmpls.OuterVlanIsCvlan must set to 1 for eth AC won't strip the tag */
    uint16 fid;                     /**< [HB.GB.GG] VPLS ID */
    uint16 vrf_id;                  /**< [HB.GB.GG] The ILM use vrfid, only for l3vpn vc label */
    uint16 l2vpn_oam_id;            /**< [GG] vpws oam id or vpls fid, used in Port + Oam ID mode, refer to CTC_OAM_Y1731_CFG_TYPE_L2VPN_OAM_MODE*/
    uint16 policer_id;              /**< [GG] policer id*/
};
typedef struct ctc_mpls_ilm_s ctc_mpls_ilm_t;

/**
 @brief  Define l2vpn pw parameter structure
*/
struct ctc_mpls_l2vpn_pw_s
{
    uint32 label;                   /**< [HB.GB.GG] In label */
    uint32 flag;                    /**< [GG] CTC_MPLS_ILM_FLAG_XXX */
    uint8 l2vpntype;                /**< [HB.GB.GG] ctc_mpls_l2vpn_type_e,L2VPN type, VPWS or VPLS */
    uint8 learn_disable;            /**< [HB.GB] VPLS learning disable, 0:learning enable, 1:learning disable */
    uint8 maclimit_enable;          /**< [HB.GB] VPLS mac limit enable*/
    uint8 space_id;                 /**< [GB.GG] Label space ID*/

    uint8 pw_mode;                  /**< [GB.GG] pw mode only used for goldengate, when PW is raw mode, dsmpls.OuterVlanIsCvlan must set to 1 for eth AC won't strip the tag */
    uint8 igmp_snooping_enable;     /**< [GB] igmpSnoopingEn */
    uint8 cwen;                     /**< [GB.GG] Control word enable, if label is a l2vpn vc label, the PW control word function maybe enable */
    uint8 rsv0;

    uint8 qos_use_outer_info;       /**< [GB.GG] If set, use outer parse info for qos */
    uint8 id_type;                  /**< [GB] flw_vrf_srv_aps value with which type */
    uint8 oam_en;                   /**< [GB.GG] Enable OAM */
    uint8 aps_select_protect_path;  /**< [GB.GG] If id_type is CTC_MPLS_ID_APS_SELECT and it is set, indicate the path is aps protect path,else the path is working path */

    uint16 service_id;              /**< [GB.GG] service id for do service acl/queueu/policer */
    uint8  service_policer_en;      /**< [GB] If set, service policer enable */
    uint8  service_queue_en;        /**< [GB] If set, service queue enable */
    uint8  service_aclqos_enable;   /**< [GB] If set, service acl enable */

    uint8  svlan_tpid_index;        /**< [GB.GG] svlan tpid index*/
    uint8  trust_outer_exp;         /**< [GB] Trust outer label exp */
    uint8  inner_pkt_type;          /**< [GB.GG] Inner packet type, refer to ctc_mpls_inner_pkt_type_t */

    uint32 stats_id;                /**< [GB.GG] Stats id */
    uint16 aps_select_grp_id;       /**< [HB.GB.GG] The aps select group id, only only for l2vpn vc label */
    uint16 logic_port;              /**< [HB.GB.GG] PW logic source port, 0xffff means no used */

    uint16 l2vpn_oam_id;            /**< [GG.GG] vpws oam id or vpls fid, used in Port + Oam ID mode, refer to CTC_OAM_Y1731_CFG_TYPE_L2VPN_OAM_MODE*/

    union
    {
        uint32 pw_nh_id;            /**< [HB.GB] Nexthop ID of PW, should be a vpws nexthop */
        struct
        {
            uint16 fid;             /**< [HB.GB] VPLS ID */
            uint8  logic_port_type; /**< [HB.GB] VPLS PW is a VPLS tunnel or H-VPLS tunnel */
        } vpls_info;
    } u;


    uint32 gport;                   /**< [GG] valid when CTC_MPLS_ILM_FLAG_ASSIGN_OUTPUT_PORT is set */
};
typedef struct ctc_mpls_l2vpn_pw_s ctc_mpls_l2vpn_pw_t;

/**
 @brief  Define vpls pw parameter structure
*/
struct ctc_mpls_pw_s
{
    uint32 vc_label;    /**< [GB] VC label of vpls PW */
    uint32 fid;         /**< [GB] VPLS ID */
};
typedef struct ctc_mpls_pw_s ctc_mpls_pw_t;

/**
 @brief  Define mpls label space information structure
*/
struct ctc_mpls_space_info_s
{
    uint8 enable;       /**< [HB.GB] Whether the label space is valid */
    uint8 sizetype;     /**< [HB.GB] The label space for HB:size =  256 * (2 ^ sizetype)    for GB:size =  64 * (2 ^ sizetype)*/
};
typedef struct ctc_mpls_space_info_s ctc_mpls_space_info_t;

/**
 @brief  Define mpls init information structure
*/
struct ctc_mpls_init_s
{
    ctc_mpls_space_info_t space_info[CTC_MPLS_SPACE_NUMBER];    /**< [HB.GB] Label space information array */
};
typedef struct ctc_mpls_init_s ctc_mpls_init_t;


/**
 @brief  Define mpls property update structure
*/
struct ctc_mpls_property_s
{
    uint8 space_id;             /**< [GB.GG] Label space ID */
    uint32 label;               /**< [GB.GG] In label */
    uint32 property_type;       /**< [GB.GG] property type, refer to ctc_mpls_ilm_property_type_t */
    void *value;                /**< [GB.GG] property value, according to property type */
};
typedef struct ctc_mpls_property_s ctc_mpls_property_t;

/**@} end of @defgroup mpls MPLS */

#ifdef __cplusplus
}
#endif

#endif  /*_CTC_MPLS_H*/

