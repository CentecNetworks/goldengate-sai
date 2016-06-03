/**
 @file ctc_vlan.h

 @date 2009-12-11

 @version v2.0

 The file define api struct used in VLAN.
*/
#ifndef _CTC_VLAN_H
#define _CTC_VLAN_H
#ifdef __cplusplus
extern "C" {
#endif

#include "ctc_const.h"
#include "ctc_parser.h"

/*****
 *@defgroup vlan VLAN
 *@{
 *****/

/**
 @brief define Arp & Dhcp packet action
*/
enum ctc_exception_type_e
{
    CTC_EXCP_FWD_AND_TO_CPU,                                 /**< [HB.GB.GG] forwarding and send to cpu */
    CTC_EXCP_NORMAL_FWD,                                     /**< [HB.GB.GG] normal forwarding */
    CTC_EXCP_DISCARD_AND_TO_CPU,                             /**< [HB.GB.GG] discard and send to cpu */
    CTC_EXCP_DISCARD                                         /**< [HB.GB.GG] discard */
};
typedef enum ctc_exception_type_e ctc_exception_type_t;

/**
 @defgroup VlanMapping VlanMapping
 @{
*/

/**
 @brief define vlan mapping vlan tag operation
*/

enum ctc_vlan_tag_op_e
{
    CTC_VLAN_TAG_OP_NONE,                                    /**< [GB.GG] operation invalid*/
    CTC_VLAN_TAG_OP_REP_OR_ADD,                       /**< [GB.GG] replace for tagged, add for no tag*/
    CTC_VLAN_TAG_OP_ADD,                                     /**< [GB.GG] append a new tag even if packet already has tag*/
    CTC_VLAN_TAG_OP_DEL,                                     /**< [GB.GG] delete packet's tag*/
    CTC_VLAN_TAG_OP_REP,                                     /**< [GB.GG] replace for tagged. do nothing for no tag*/
    CTC_VLAN_TAG_OP_VALID,                                   /**< [GB.GG] Operation valid, but do nothing. */
    CTC_VLAN_TAG_OP_MAX
};
typedef enum ctc_vlan_tag_op_e ctc_vlan_tag_op_t;

/**
 @brief define vlan mapping vid or cos operation
*/

enum ctc_vlan_tag_sl_e
{
    CTC_VLAN_TAG_SL_AS_PARSE,                               /**< [GB.GG] select parser result vid/cos/cfi*/
    CTC_VLAN_TAG_SL_ALTERNATIVE,                           /**< [GB.GG] select the other tag's vid/cos/cfi, if the other tag not present, use default*/
    CTC_VLAN_TAG_SL_NEW,                                    /**< [GB.GG] select user assigned vid/cos/cfi */
    CTC_VLAN_TAG_SL_DEFAULT,                                /**< [GB.GG] select default vid/cos/cfi in ingress, select mapped cos/cfi in egress, but not support for vid in egress*/
    CTC_VLAN_TAG_SL_MAX
};
typedef enum ctc_vlan_tag_sl_e ctc_vlan_tag_sl_t;

/**
 @brief define key type for egress vlan mapping
*/
enum ctc_egress_vlan_mapping_key_e
{
    CTC_EGRESS_VLAN_MAPPING_KEY_NONE       = 0x00000000,     /**< [GB.GG] egress vlan mapping only use port as key*/
    CTC_EGRESS_VLAN_MAPPING_KEY_CVID       = 0x00000001,     /**< [GB.GG] egress vlan mapping use cvid as key*/
    CTC_EGRESS_VLAN_MAPPING_KEY_SVID       = 0x00000002,     /**< [GB.GG] egress vlan mapping use svid as key*/
    CTC_EGRESS_VLAN_MAPPING_KEY_CTAG_COS   = 0x00000004,     /**< [GB.GG] egress vlan mapping use ctag cos as key*/
    CTC_EGRESS_VLAN_MAPPING_KEY_STAG_COS    = 0x00000008    /**< [GB.GG] egress vlan mapping use stag cos as key*/
};
typedef enum ctc_egress_vlan_mapping_key_e ctc_egress_vlan_mapping_key_t;

/**
 @brief define egress vlan mapping output used on epe vlan mapping
*/
enum ctc_egress_vlan_mapping_action_e
{
    CTC_EGRESS_VLAN_MAPPING_OUTPUT_SVID     = 0x00000001,       /**< [GB.GG] output svid in mapping result*/
    CTC_EGRESS_VLAN_MAPPING_OUTPUT_CVID     = 0x00000002,       /**< [GB.GG] output cvid in mapping result*/
    CTC_EGRESS_VLAN_MAPPING_OUTPUT_SCOS     = 0x00000004,       /**< [GB.GG] output stag cos in mapping result*/
    CTC_EGRESS_VLAN_MAPPING_OUTPUT_CCOS     = 0x00000008,       /**< [GB.GG] output ctag cos in mapping result*/
    CTC_EGRESS_VLAN_MAPPING_OUTPUT_SCFI     = 0x00000010,       /**< [GG] output stag cfi in mapping result*/
    CTC_EGRESS_VLAN_MAPPING_FLAG_AGING      = 0x00001000,       /**< [GB] flag to indicate enable aging*/

};
typedef enum ctc_egress_vlan_mapping_action_e ctc_egress_vlan_mapping_action_t;

/**
 @brief define data structure for egress vlan mapping used in APIs
*/
struct ctc_egress_vlan_mapping_s
{
    uint32    key;                              /**< [GB.GG] egress vlan mapping key type,GB support 6 kinds of key or key combination type:
                                                             CTC_EGRESS_VLAN_MAPPING_KEY_NONE /
                                                             CTC_EGRESS_VLAN_MAPPING_KEY_CVID /
                                                             CTC_EGRESS_VLAN_MAPPING_KEY_SVID /
                                                             CTC_EGRESS_VLAN_MAPPING_KEY_CVID + CTC_EGRESS_VLAN_MAPPING_KEY_CTAG_COS /
                                                             CTC_EGRESS_VLAN_MAPPING_KEY_SVID + CTC_EGRESS_VLAN_MAPPING_KEY_STAG_COS /
                                                             CTC_EGRESS_VLAN_MAPPING_KEY_SVID + CTC_EGRESS_VLAN_MAPPING_KEY_CVID
                                                             you can see num ctc_egress_vlan_mapping_key_t remark*/
    uint32   action;                           /**< [GB.GG] action of egress vlan mapping, ctc_egress_vlan_mapping_action_t*/

    ctc_vlan_tag_op_t         stag_op;         /**< [GB.GG] operation type of stag, see ctc_vlan_tag_op_t struct*/
    ctc_vlan_tag_sl_t          svid_sl;        /**< [GB.GG] operation type of svlan id, see ctc_vlan_tag_sl_t struct*/
    ctc_vlan_tag_sl_t          scos_sl;        /**< [GB.GG] operation type of scos, see ctc_vlan_tag_sl_t struct*/
    ctc_vlan_tag_sl_t          scfi_sl;        /**< [GG] operation type of scfi, see ctc_vlan_tag_sl_t struct*/

    ctc_vlan_tag_op_t        ctag_op;          /**< [GB.GG] operation type of ctag, see ctc_vlan_tag_op_t struct*/
    ctc_vlan_tag_sl_t          cvid_sl;        /**< [GB.GG] operation type of cvlan id, see ctc_vlan_tag_sl_t struct*/
    ctc_vlan_tag_sl_t          ccos_sl;        /**< [GB.GG] operation type of ccos, see ctc_vlan_tag_sl_t struct*/

    uint16   old_cvid;                         /**< [GB.GG] orignal cvlan id in packet*/
    uint16   old_svid;                         /**< [GB.GG] orignal svlan id in packet*/

    uint16   cvlan_end;                        /**< [GB.GG] if vlan range check want to be used, cvlan_end must be configured
                                                        as the max cvlan id need to do range check*/
    uint16   svlan_end;                        /**< [GB.GG] if vlan range check want to be used, svlan_end must be configured
                                                        as the max svlan id need to do range check*/

    uint8  vrange_grpid;                       /**< [GB.GG] if vlan range check want to be used, vlan range group id: 0~63
                                                        the vlan range group property should be as same as the property vlan range
                                                        check on port*/

    uint8  new_scfi;                            /**< [GG] new scfi in packet through egress vlan mapping*/
    uint8  rsv0[2];

    uint16 new_svid;                            /**< [GB.GG] new svlan id in packet through egress vlan mapping*/
    uint16 new_cvid;                            /**< [GB.GG] new cvlan id in packet through egress vlan mapping*/

    uint8  old_ccos;                            /**< [GB.GG] orignal ccos id in packet*/
    uint8  old_scos;                            /**< [GB.GG] orignal scos id in packet*/

    uint8  new_scos;                            /**< [GB.GG] new scos in packet through egress vlan mapping*/
    uint8  new_ccos;                            /**< [GB.GG] new ccos in packet through egress vlan mapping*/

};
typedef struct ctc_egress_vlan_mapping_s ctc_egress_vlan_mapping_t;

/**
 @brief define key type for ingress vlan mapping
*/

enum ctc_vlan_mapping_key_e
{
    CTC_VLAN_MAPPING_KEY_NONE               = 0x00000000,           /**< [HB.GB.GG] vlan mapping use port as key*/
    CTC_VLAN_MAPPING_KEY_CVID               = 0x00000001,           /**< [HB.GB.GG] use cvid as key*/
    CTC_VLAN_MAPPING_KEY_SVID               = 0x00000002,           /**< [HB.GB.GG] use svid as key*/
    CTC_VLAN_MAPPING_KEY_CTAG_COS           = 0x00000004,           /**< [HB.GB.GG] use ctag cos as key*/
    CTC_VLAN_MAPPING_KEY_STAG_COS           = 0x00000008,           /**< [HB.GB.GG] use stag cos as key*/
    CTC_VLAN_MAPPING_KEY_MAC_SA             = 0x00000010,           /**< [HB.GG] use mac sa as key*/
    CTC_VLAN_MAPPING_KEY_IPV4_SA            = 0x00000020,           /**< [HB.GG] use ipv4 sa as key*/
    CTC_VLAN_MAPPING_KEY_IPV6_SA            = 0x00000040,           /**< [GG] use ipv6 sa as key*/


    /*below are used for flexible key*/
    CTC_VLAN_MAPPING_KEY_MAC_DA             = 0x00000100,           /**< [HB] use mac da as key*/
    CTC_VLAN_MAPPING_KEY_IPV4_DA            = 0x00000200,           /**< [HB] use ipv4 da as key*/
    CTC_VLAN_MAPPING_KEY_L2_TYPE            = 0x00000400,           /**< [HB] use l2 type as key*/
    CTC_VLAN_MAPPING_KEY_L3_TYPE            = 0x00000800,           /**< [HB] use l3 type as key*/
    CTC_VLAN_MAPPING_KEY_L4_SRCPORT         = 0x00001000,           /**< [HB] use l2 type as key*/
    CTC_VLAN_MAPPING_KEY_L4_DSTPORT         = 0x00002000            /**< [HB] use l3 type as key*/

};
typedef enum ctc_vlan_mapping_key_e ctc_vlan_mapping_key_t;

/**
 @brief vlan mapping output used on ipe_usrid
*/
enum ctc_vlan_mapping_action_e
{
    CTC_VLAN_MAPPING_OUTPUT_SVID                = 0x00000001,    /**< [HB.GB.GG] output svid in mapping result*/
    CTC_VLAN_MAPPING_OUTPUT_LOGIC_SRC_PORT      = 0x00000002,    /**< [HB.GB.GG] output logic source port in mapping result*/
    CTC_VLAN_MAPPING_OUTPUT_APS_SELECT          = 0x00000004,    /**< [HB.GB.GG] output aps select information in mapping result*/

    CTC_VLAN_MAPPING_OUTPUT_FID                 = 0x00000008,    /**< [HB.GB.GG] output fid in mapping result*/
    CTC_VLAN_MAPPING_OUTPUT_NHID                = 0x00000010,    /**< [HB.GB.GG] output nexthop in mapping result*/

    CTC_VLAN_MAPPING_OUTPUT_SERVICE_ID          = 0x00000020,    /**< [HB.GB] output service ID of HQoS in mapping result*/
    CTC_VLAN_MAPPING_OUTPUT_CVID                = 0x00000040,    /**< [HB.GB.GG] output cvid in mapping result*/

    CTC_VLAN_MAPPING_OUTPUT_VLANPTR             = 0x00000080,    /**< [HB.GB.GG] output VlanPtr in mapping result*/
    CTC_VLAN_MAPPING_OUTPUT_SCOS                = 0x00000100,    /**< [GB.GG] output stag cos in mapping result*/
    CTC_VLAN_MAPPING_OUTPUT_CCOS                = 0x00000200,    /**< [GB.GG] output ctag cos in mapping result*/
    CTC_VLAN_MAPPING_OUTPUT_VN_ID               = 0x00000400,    /**< [GG] output virtual subnet id used only for overlay network tunnel initiator*/

    CTC_VLAN_MAPPING_FLAG_VLAN_SWITCHING        = 0x00000800,    /**< [HB] flag to indicate vlan switching. valid if OUTPUT_NHID*/
    CTC_VLAN_MAPPING_FLAG_VPWS                  = 0x00001000,    /**< [HB.GB.GG] flag to indicate vpws application*/
    CTC_VLAN_MAPPING_FLAG_VPLS                  = 0x00002000,    /**< [HB.GB.GG] flag to indicate vpls application*/
    CTC_VLAN_MAPPING_FLAG_VPLS_LRN_DIS          = 0x00004000,    /**< [HB.GB] flag to indicate vpls learning will be disable*/
    CTC_VLAN_MAPPING_FLAG_MACLIMIT_EN           = 0x00008000,    /**< [HB.GB] flag to indicate vpls learning will be disable*/

    CTC_VLAN_MAPPING_FLAG_ETREE_LEAF            = 0x00010000,    /**< [GB.GG] flag to indicate it is leaf node in E-Tree networks */

    CTC_VLAN_MAPPING_FLAG_AGING                 = 0x00040000,    /**< [GB] flag to indicate enable aging*/

    CTC_VLAN_MAPPING_FLAG_SERVICE_ACL_EN        = 0x00100000,    /**< [HB.GB.GG] enable service acl of HQoS in mapping result*/
    CTC_VLAN_MAPPING_FLAG_SERVICE_POLICER_EN    = 0x00200000,    /**< [HB.GB.GG] enable service policer of HQoS in mapping result*/
    CTC_VLAN_MAPPING_FLAG_STATS_EN              = 0x00400000,    /**< [GB.GG] enable stats in mapping result*/
    CTC_VLAN_MAPPING_FLAG_SERVICE_QUEUE_EN      = 0x00800000,    /**< [GB] enable service queue */
    CTC_VLAN_MAPPING_OUTPUT_STP_ID              = 0x01000000,    /**< [GG] output stp id in mapping result */

    CTC_VLAN_MAPPING_FLAG_L2VPN_OAM             = 0x02000000,    /**< [GG] indecate L2VPN OAM, need config l2vpn_oam_id*/
    CTC_VLAN_MAPPING_OUTPUT_VLAN_DOMAIN         = 0x04000000,    /**< [GG] output vlan domain in mapping result */

    CTC_VLAN_MAPPING_OUTPUT_VRFID               = 0x08000000,    /**< [GB.GG] output vrfid in mapping result */
    CTC_VLAN_MAPPING_FLAG_IGMP_SNOOPING_EN      = 0x10000000,    /**< [GB] enable IGMP snooping in mapping result */
};
typedef enum ctc_vlan_mapping_action_e ctc_vlan_mapping_action_t;

/**
 @brief enum value used in vlan mapping flag APIs
*/
enum ctc_vlan_mapping_flag_e
{
    CTC_VLAN_MAPPING_FLAG_USE_FLEX = 0x01,   /**< [GB.GG] if set, vlan mapping key use tcam*/
    CTC_VLAN_MAPPING_FLAG_USE_LOGIC_PORT    = 0x02,   /**< [GB] if set, vlan mapping key use logic port as port*/
    CTC_VLAN_MAPPING_FLAG_MAX
};
typedef enum ctc_vlan_mapping_flag_e ctc_vlan_mapping_flag_t;

/**
 @brief define data structure used in APIs
*/
struct ctc_vlan_mapping_s
{

    /*key*/
    uint32 key;                             /**< [HB.GB.GG] vlan mapping key type,GB support any kinds of key or key combination type,
                                                           see enum ctc_vlan_mapping_key_t remark*/
    uint16 old_cvid;                        /**< [HB.GB.GG] orignal start cvlan id in packet*/
    uint16 old_svid;                        /**< [HB.GB.GG] orignal start svlan id in packet*/
    uint16 cvlan_end;                       /**< [HB.GB.GG] orignal max cvlan id need to do vlan mapping*/
    uint16 svlan_end;                       /**< [HB.GB.GG] orignal max svlan id need to do vlan mapping*/
    uint8  old_ccos;                        /**< [HB.GB.GG] orignal ccos id in packet*/
    uint8  old_scos;                        /**< [HB.GB.GG] orignal scos id in packet*/
    uint8  vrange_grpid;                    /**< [GB.GG] vlan range group id: 0~63 used in vlan range check*/
    uint8 flag;                                 /**< [GB.GG] Supported vlan mapping bitmap, see ctc_vlan_mapping_flag_t */

    mac_addr_t macsa;                       /**< [HB.GG] macsa as key*/
    mac_addr_t macda;                       /**< [HB] macda as key   for flexiable vlan mapping*/
    ip_addr_t ipv4_sa;                      /**< [HB.GG] ipv4 sa as key*/
    ip_addr_t ipv4_smask;                   /**< [HB] ipv4 sa mask as key   for flexiable vlan mapping*/
    ip_addr_t ipv4_da;                      /**< [HB] ipv4 da as key        for flexiable vlan mapping*/
    ip_addr_t ipv4_dmask;                   /**< [HB] ipv4 da mask as key   for flexiable vlan mapping*/
    ipv6_addr_t ipv6_sa;                    /**< [GG] ipv6 sa as key*/
    uint16 l4src_port;                      /**< [HB] l4src_port as key for flexiable vlan mapping*/
    uint16 l4dest_port;                     /**< [HB] l4dest_port as key for flexiable vlan mapping*/
    uint8 l2_type;                          /**< [HB] l2 type as key for flexiable vlan mapping*/
    uint8 l3_type;                          /**< [HB] l3 type as key for flexiable vlan mapping*/


    /*action*/
    uint16 user_vlanptr;                    /**< [HB.GB.GG] to use this feature. set ctc_vlan_global_cfg_s.vlanptr_mode = CTC_VLANPTR_MODE_USER_DEFINE1 / USER_DEFINE2*/
    uint32 action;                          /**< [HB.GB.GG] action type of vlan mapping, see ctc_vlan_mapping_action_t remark*/

    /*vlan edit*/
    ctc_vlan_tag_op_t      stag_op;         /**< [GB.GG] operation type of stag, see ctc_vlan_tag_op_t struct*/
    ctc_vlan_tag_sl_t      svid_sl;         /**< [GB.GG] operation type of svlan id, see ctc_vlan_tag_sl_t struct*/
    ctc_vlan_tag_sl_t      scos_sl;         /**< [GB.GG] operation type of scos, see ctc_vlan_tag_sl_t struct*/

    ctc_vlan_tag_op_t      ctag_op;         /**< [GB.GG] operation type of ctag, see ctc_vlan_tag_op_t struct*/
    ctc_vlan_tag_sl_t      cvid_sl;         /**< [GB.GG] operation type of cvlan id, see ctc_vlan_tag_sl_t struct*/
    ctc_vlan_tag_sl_t      ccos_sl;         /**< [GB.GG] operation type of ccos, see ctc_vlan_tag_sl_t struct*/

    uint16 new_svid;                        /**< [HB.GB.GG] new svid append on packet, HB only can select one parameter of this
                                                 and logic_src_port and aps_select_group_id*/
    uint16 new_cvid;                        /**< [HB.GB.GG] new cvid append on packet*/
    uint8 new_scos;                         /**< [GB.GG] new stag cos*/
    uint8 new_ccos;                         /**< [GB.GG] new ctag cos*/

    uint16 logic_src_port;                  /**< [HB.GB.GG] logic source port*/
    uint16 aps_select_group_id;             /**< [HB.GB.GG] aps selector group id*/
    uint16 service_id;                      /**< [HB.GB] service id for do service acl/queueu/policer */
    uint32 stats_id;                        /**< [GB.GG] stats id*/

    union
    {
        uint16 fid;                         /**< [HB.GB.GG] forwarding instance, maybe EVC concept on MEF10*/
        uint32 nh_id;                       /**< [HB.GB.GG] nexthop id, need create nexthop first*/
        uint32 vn_id;                       /**< [GG] virtual subnet id , used only for overlay network tunnel initiator*/
        uint16 vrf_id;                      /**< [GB.GG] Vrf ID of the route*/
    } u3;

    uint16 l2vpn_oam_id;      /**< [GG] vpws oam id or vpls fid, used in Port + Oam ID mode, refer to CTC_OAM_Y1731_CFG_TYPE_L2VPN_OAM_MODE*/

    uint8 is_igs_srvq;                   /**< [HB] service queue direction*/
    uint8 is_working_path;               /**< [HB.GB.GG] indicate the flow is working path or protecting path, used in APS*/
    uint16 protected_vlan;               /**< [HB.GB.GG] protected vlan, used in APS, general equal to vlan of working path*/
    uint8 logic_port_type;               /**< [GB.GG] logic-port-type, used for VPLS horizon split discard */
    uint8 stp_id;                           /**< [GG] stp id: 1 - 127*/
    uint8 scl_id;                           /**< [GG] TCAM  SCL lookup ID.There are 2 scl lookup<0-1>, and each has its own feature */
    uint8 vlan_domain;                      /**< [GG] new vlan domain, <0-2>, see ctc_scl_vlan_domain_t */
    uint16 policer_id;                      /**< [GG] policer id for do service/flow policer */

    uint8  color;                           /**< [GB.GG] Color: green, yellow, or red :CTC_QOS_COLOR_XXX*/
    uint8  priority;                        /**< [GB.GG] Priority*/

};
typedef struct ctc_vlan_mapping_s ctc_vlan_mapping_t;

/**
 @brief define action of default entry of vlan mapping and vlan class
*/
enum ctc_vlan_miss_flag_e
{
    CTC_VLAN_MISS_ACTION_DO_NOTHING,        /**< [HB.GB.GG] default action do nothing, will be forwarding normal*/
    CTC_VLAN_MISS_ACTION_DISCARD,           /**< [HB.GB.GG] default action discard, will be discard*/
    CTC_VLAN_MISS_ACTION_OUTPUT_VLANPTR,    /**< [HB.GB.GG] default action output vlanptr*/

    /*below are for ingress only*/
    CTC_VLAN_MISS_ACTION_TO_CPU,            /**< [HB.GB.GG] default action to cpu, will be redirect to cpu only support by ingress vlan mapping*/
    CTC_VLAN_MISS_ACTION_SERVICE_QUEUE,     /**< [HB] default action output service queue information only support by ingress vlan mapping*/
    CTC_VLAN_MISS_ACTION_APPEND_STAG        /**< [GB.GG] default action add a stag with new_svid even if packet tagged*/
};
typedef enum ctc_vlan_miss_flag_e ctc_vlan_miss_flag_t;

/**
 @brief define action of default entry of vlan mapping and vlan class
*/
struct ctc_vlan_miss_s
{
    uint16 service_id;              /**< [HB] service id binding to the packet[ingress only]*/
    uint8  flag;                     /**< [HB.GB.GG] if vlan mapping mismatch any entry, do action as this, see enum ctc_vlan_miss_flag_t*/
    uint8  is_igs_srvq;             /**< [HB] service queue direction*/
    uint16 user_vlanptr;            /**< [HB.GG] to use this feature. set ctc_vlan_global_cfg_s.vlanptr_mode = CTC_VLANPTR_MODE_USER_DEFINE1 / USER_DEFINE2*/
    uint16 new_svid;                /**< [GB.GG] default action add a stag with this new_svid even if packet tagged only for ingress vlan mapping*/
    uint8 new_scos;                         /**< [GB.GG] new stag cos*/
    uint8  rsv0[3];
    ctc_vlan_tag_sl_t      scos_sl;         /**< [GB.GG] operation type of scos, see ctc_vlan_tag_sl_t struct*/
};
typedef struct ctc_vlan_miss_s ctc_vlan_miss_t;

/**@} end of @defgroup vlanmapping */

/**
 @defgroup vlanclassification vlanclassification
 @{
*/

/**
 @brief enum value used in vlan classification APIs
*/
enum ctc_vlan_class_type_e
{
    CTC_VLAN_CLASS_MAC,                 /**< [HB.GB.GG] mac based vlan*/
    CTC_VLAN_CLASS_IPV4,                /**< [HB.GB.GG] ipv4/flow based vlan*/
    CTC_VLAN_CLASS_IPV6,                /**< [HB.GB.GG] ipv6/flow based vlan*/
    CTC_VLAN_CLASS_PROTOCOL,            /**< [HB.GB.GG] protocol based vlan*/
    CTC_VLAN_CLASS_MAX
};
typedef enum ctc_vlan_class_type_e ctc_vlan_class_type_t;

/**
 @brief enum value used in vlan classification flag APIs
*/
enum ctc_vlan_class_flag_e
{
    CTC_VLAN_CLASS_FLAG_USE_MACDA = 0x01,   /**< [HB.GB.GG] if set, macda will be valid to use while mac based vlan class*/
    CTC_VLAN_CLASS_FLAG_OUTPUT_COS = 0x02,  /**< [GB.GG] if set, cos will be valid to output while vlan class*/
    CTC_VLAN_CLASS_FLAG_USE_FLEX = 0x04,    /**< [HB.GB.GG] if set, flex mac ipv4 or ipv6 tcam key will be used*/
    CTC_VLAN_CLASS_FLAG_MAX
};
typedef enum ctc_vlan_class_flag_e ctc_vlan_class_flag_t;

/**
 @brief the structure of vlan classification
*/
struct ctc_vlan_class_s
{
    ctc_vlan_class_type_t type;                 /**< [HB.GB.GG] vlan classification type, based mac/ip/protocol/flow*/
    uint8 flag;                                 /**< [HB.GB.GG] Supported vlan class bitmap, see ctc_vlan_class_flag_t */
    uint8  cos;                                 /**< [GB.GG] new cos*/
    uint16 rsv0;

    uint8  scl_id;                             /**< [GG] TCAM  SCL lookup ID.There are 2 scl lookup<0-1>, and each has its own feature */
    uint8  rsv1;
    uint16 vlan_id;                         /**< [HB.GB.GG] new vlan id*/
    union
    {
        mac_addr_t mac;                         /**< [HB.GB.GG] only mac address based vlan class*/
        ip_addr_t ipv4_sa;                      /**< [HB.GB.GG] only IPv4 source address based vlan class*/
        ipv6_addr_t ipv6_sa;                    /**< [HB.GB.GG] only IPv6 source address based vlan class*/
        ctc_parser_l3_type_t l3_type;           /**< [HB] layer3 parser type*/
        uint16 ether_type;                      /**< [GB.GG] ether type,0x0001~0xFFFF other chip*/

        struct
        {
            ip_addr_t ipv4_sa;                  /**< [HB.GB.GG] IPv4 source address*/
            ip_addr_t ipv4_sa_mask;             /**< [HB.GB.GG] IPv4 source mask*/
            ip_addr_t ipv4_da;                  /**< [HB.GB.GG] IPv4 destination address*/
            ip_addr_t ipv4_da_mask;             /**< [HB.GB.GG] IPv4 destination mask*/
            mac_addr_t macsa;                   /**< [HB.GB] mac source address*/
            mac_addr_t macda;                   /**< [HB.GB] mac destination address*/
            uint16 l4src_port;                  /**< [HB.GB.GG] layer4 source port*/
            uint16 l4dest_port;                 /**< [HB.GB.GG] layer4 destination port*/
            ctc_parser_l3_type_t l3_type;       /**< [HB.GB.GG] layer3 parser type*/
            ctc_parser_l4_type_t l4_type;       /**< [HB.GB.GG] layer4 parser type*/
        } flex_ipv4;

        struct
        {
            ipv6_addr_t ipv6_sa;                /**< [HB.GB.GG] IPv6 source address*/
            ipv6_addr_t ipv6_sa_mask;           /**< [HB.GB.GG] IPv6 source mask*/
            ipv6_addr_t ipv6_da;                /**< [HB.GB.GG] IPv6 destination address*/
            ipv6_addr_t ipv6_da_mask;           /**< [HB.GB.GG] IPv6 destination mask*/
            mac_addr_t macsa;                   /**< [HB.GB] mac source address*/
            mac_addr_t macda;                   /**< [HB.GB] mac destination address*/
            uint16 l4src_port;                  /**< [HB.GB.GG] layer4 source port*/
            uint16 l4dest_port;                 /**< [HB.GB.GG] layer4 destination type*/
            ctc_parser_l4_type_t l4_type;       /**< [HB.GB.GG] layer4 parser type*/
        } flex_ipv6;

    } vlan_class;                /**<vlan classification key information*/

};
typedef struct ctc_vlan_class_s ctc_vlan_class_t;
/**@} end of @defgroup VlanClassification*/

/**
  @brief Define vlan acl property
*/
struct ctc_vlan_acl_property_s
{
    uint8 acl_priority;            /**< [DT2] <0--7> for ingress ,<0-2> for egress*/
    uint8 acl_en;                  /**< [DT2] set acl en */
    uint8 direction;               /**< [DT2] direction, CTC_INGRESS or CTC_EGRESS*/
    uint8 tcam_lkup_type;          /**< [DT2] tcam lookup type,refer to CTC_ACL_TCAM_LKUP_TYPE_XXX */

    uint8 class_id;                /**< [DT2] class id */
    uint8 use_metadata;            /**< [DT2] if set, acl use metadata to lookup*/
    uint8 use_mapped_vlan;         /**< [DT2] if set, acl use mapped vlan to lookup*/
    uint8 rsv;
};
typedef struct ctc_vlan_acl_property_s ctc_vlan_acl_property_t;

/**
  @brief Define vlan property flags
*/
enum ctc_vlan_property_e
{
    CTC_VLAN_PROP_RECEIVE_EN,                /**< [GB.GG] vlan receive enable*/
    CTC_VLAN_PROP_BRIDGE_EN,                 /**< [GB.GG] vlan bridge enable*/
    CTC_VLAN_PROP_TRANSMIT_EN,               /**< [GB.GG] vlan transmit enable*/
    CTC_VLAN_PROP_LEARNING_EN,               /**< [GB.GG] vlan learning enable*/
    CTC_VLAN_PROP_DHCP_EXCP_TYPE,            /**< [GB.GG] dhcp packet processing type, value see enum ctc_exception_type_t */
    CTC_VLAN_PROP_ARP_EXCP_TYPE,             /**< [GB.GG] arp packet processing type, value see enum ctc_exception_type_t */
    CTC_VLAN_PROP_IGMP_SNOOP_EN,             /**< [GB.GG] igmp snooping enable     */
    CTC_VLAN_PROP_FID,                       /**< [GB.GG] fid for general l2 bridge, VSIID for L2VPN*/
    CTC_VLAN_PROP_IPV4_BASED_L2MC,           /**< [GB.GG] Ipv4 based l2mc*/
    CTC_VLAN_PROP_IPV6_BASED_L2MC,           /**< [GB.GG] Ipv6 based l2mc*/
    CTC_VLAN_PROP_PTP_EN,                    /**< [GB] ptp enable*/
    CTC_VLAN_PROP_DROP_UNKNOWN_UCAST_EN,     /**< [GB.GG] vlan drop unknown ucast packet enable*/
    CTC_VLAN_PROP_DROP_UNKNOWN_MCAST_EN,     /**< [GB.GG] vlan drop unknown mcast packet enable*/
    CTC_VLAN_PROP_DROP_UNKNOWN_BCAST_EN,     /**< [GG] vlan drop unknown bcast packet enable*/
    CTC_VLAN_PROP_FIP_EXCP_TYPE,             /**< [GG] fip packet processing type, value see enum ctc_exception_type_t */
};
typedef enum ctc_vlan_property_e  ctc_vlan_property_t;


/**
  @brief Define vlan property flags with direction
*/
enum ctc_vlan_direction_property_e
{
    CTC_VLAN_DIR_PROP_ACL_EN,                /**< [GB.GG] vlan acl enable. bitmap refer CTC_ACL_EN_XXX*/
    CTC_VLAN_DIR_PROP_ACL_CLASSID,           /**< [GB.GG] vlan acl classid 0*/
    CTC_VLAN_DIR_PROP_ACL_CLASSID_1,         /**< [GG] vlan acl classid 1, only for ingress*/
    CTC_VLAN_DIR_PROP_ACL_CLASSID_2,         /**< [GG] vlan acl classid 2, only for ingress*/
    CTC_VLAN_DIR_PROP_ACL_CLASSID_3,         /**< [GG] vlan acl classid 3, only for ingress*/
    CTC_VLAN_DIR_PROP_ACL_ROUTED_PKT_ONLY,   /**< [GB.GG] vlan routed packet only for acl 0*/
    CTC_VLAN_DIR_PROP_ACL_TCAM_LKUP_TYPE_0,  /**< [GG] acl tcam type. refer CTC_ACL_TCAM_LKUP_TYPE_XXX */
    CTC_VLAN_DIR_PROP_ACL_TCAM_LKUP_TYPE_1,  /**< [GG] acl tcam type. refer CTC_ACL_TCAM_LKUP_TYPE_XXX */
    CTC_VLAN_DIR_PROP_ACL_TCAM_LKUP_TYPE_2,  /**< [GG] acl tcam type. refer CTC_ACL_TCAM_LKUP_TYPE_XXX */
    CTC_VLAN_DIR_PROP_ACL_TCAM_LKUP_TYPE_3,  /**< [GG] acl tcam type. refer CTC_ACL_TCAM_LKUP_TYPE_XXX */

    CTC_VLAN_DIR_PROP_NUM
};
typedef enum ctc_vlan_direction_property_e  ctc_vlan_direction_property_t;

/**
 @brief Define vlan range group property
*/
struct ctc_vlan_range_info_s
{
    uint8 vrange_grpid;              /**< [GB.GG] vlan range check group id*/
    ctc_direction_t direction;       /**< [GB.GG] vlan range check group direction*/
};
typedef struct ctc_vlan_range_info_s  ctc_vlan_range_info_t;

/**
 @brief Define vlan range items, including start and end vlan id
*/
struct ctc_vlan_range_s
{
    uint16 vlan_start;              /**< [GB.GG] vlan range item start vlan id*/
    uint16 vlan_end;                /**< [GB.GG] vlan range item end vlan id*/
};
typedef struct ctc_vlan_range_s  ctc_vlan_range_t;

/**
 @brief Define get vlan range group info
*/
struct ctc_vlan_range_group_s
{
    ctc_vlan_range_t vlan_range[8]; /**< [GB.GG] 8 items info in one group*/
};
typedef struct ctc_vlan_range_group_s  ctc_vlan_range_group_t;


/**
 @brief define the mode of vlanPtr
*/
enum ctc_vlanptr_mode_e
{
    CTC_VLANPTR_MODE_VLANID,            /**< [HB.GG] set or get vlan property by vlan id (create vlan with ctc_vlan_create_vlan [Goldengate])*/
    CTC_VLANPTR_MODE_USER_DEFINE1,      /**< [HB.GG] set or get vlan property by user defined vlanPtr.(1~7K-1,vlan filter won't featured [Humber], 1~4094)
                                             (vlanptr 0~4K-1, set or get vlan property by uservlanptr, create vlan with ctc_vlan_create_uservlan [Goldengate])*/
    CTC_VLANPTR_MODE_USER_DEFINE2       /**< [HB] set or get vlan property by user defined vlanPtr.(1-4094 vlanid + 4096-4607 user_vlanptr. with vlan_filter)[humber only]*/
};
typedef enum ctc_vlanptr_mode_e  ctc_vlanptr_mode_t;


/**
 @brief Create user vlan param
*/
struct ctc_vlan_uservlan_s
{
    uint16 vlan_id;                       /**<[GG] Vlan id */
    uint16 user_vlanptr;                      /**<[GG] User vlan ptr */
    uint16 fid;                           /**<[GG] Fid , l2 flooding group id*/
    uint32 flag;                          /**<[GG] Flag, use CTC_MAC_LEARN_USE_XXX / */
};
typedef struct ctc_vlan_uservlan_s ctc_vlan_uservlan_t;

/**
 @brief vlan global config information
*/
struct ctc_vlan_global_cfg_s
{
    uint8    vlanptr_mode;                /**< [HB.GG] refer to enum ctc_vlanptr_mode_t.*/
    uint8    rsv0[3];
};
typedef struct ctc_vlan_global_cfg_s ctc_vlan_global_cfg_t;

/**@} end of @defgroup vlan*/
#ifdef __cplusplus
}
#endif

#endif

