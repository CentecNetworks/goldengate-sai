/**
 @file ctc_oam_bfd.h

 @date 2012-01-07

 @version v2.0

 This file contains BFD OAM(MPLS TP/MPLS/IP)related data structure, enum, macro.

*/

#ifndef _CTC_OAM_BFD_H
#define _CTC_OAM_BFD_H
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

#define CTC_OAM_BFD_CV_MEP_ID_MAX_LEN  36   /**< The max length of source MEP ID TLV */

/**
 @defgroup bfd_oam BFD_OAM
 @{
*/

/**
 @brief  Define BFD OAM state
*/
enum ctc_oam_bfd_state_e
{
    CTC_OAM_BFD_STATE_ADMIN_DOWN    = 0,    /**< [GB.GG] BFD session state admin down */
    CTC_OAM_BFD_STATE_DOWN          = 1,    /**< [GB.GG] BFD session state down */
    CTC_OAM_BFD_STATE_INIT          = 2,    /**< [GB.GG] BFD session state init */
    CTC_OAM_BFD_STATE_UP            = 3     /**< [GB.GG] BFD session state up */
};
typedef enum ctc_oam_bfd_state_e ctc_oam_bfd_state_t;

/**
 @brief  Define BFD OAM diag
*/
enum ctc_oam_bfd_diag_e
{
    CTC_OAM_BFD_DIAG_NONE                           = 0,    /**< [GB.GG] BFD No Diagnostic */
    CTC_OAM_BFD_DIAG_TIME_EXPIRED                   = 1,    /**< [GB.GG] BFD Control Detection Time Expired */
    CTC_OAM_BFD_DIAG_ECHO_FAIL                      = 2,    /**< [GB.GG] BFD Echo Function Failed */
    CTC_OAM_BFD_DIAG_NEIGHBOR_DOWN                  = 3,    /**< [GB.GG] BFD Neighbor Signaled Session Down */
    CTC_OAM_BFD_DIAG_FORWARDING_RESET               = 4,    /**< [GB.GG] BFD Forwarding Plane Reset */
    CTC_OAM_BFD_DIAG_PATH_DOWN                      = 5,    /**< [GB.GG] BFD Path Down */
    CTC_OAM_BFD_DIAG_CONCATENTED_PATH_DOWN          = 6,    /**< [GB.GG] BFD Concatenated Path Down */
    CTC_OAM_BFD_DIAG_ADMINISTRATIVELY_DOWN          = 7,    /**< [GB.GG] BFD Administratively Down */
    CTC_OAM_BFD_DIAG_REVERSE_CONCATENTED_PATH_DOWN  = 8,    /**< [GB.GG] BFD Reverse Concatenated Path Down */
    CTC_OAM_BFD_DIAG_MIS_CONNECT                    = 9,    /**< [GB.GG] BFD mis-connectivity defect */
    CTC_OAM_BFD_DIAG_MAX                            = 31
};
typedef enum ctc_oam_bfd_diag_e ctc_oam_bfd_diag_t;

/**
 @brief  Define BFD OAM timer negotiation param
*/
struct ctc_oam_bfd_timer_s
{
    uint16 min_interval; /**< [GB.GG] BFD min tx/rx interval */
    uint8  detect_mult;  /**< [GB.GG] BFD detection time multiplier */
    uint8  resv[1];
};
typedef struct ctc_oam_bfd_timer_s ctc_oam_bfd_timer_t;

/**
 @brief   Define BFD OAM local mep flag
*/
enum ctc_oam_bfd_lmep_flag_e
{
    CTC_OAM_BFD_LMEP_FLAG_NONE            = 0x00000000,  /**< [GB.GG] None */
    CTC_OAM_BFD_LMEP_FLAG_MEP_EN          = 0x00000001,  /**< [GB.GG] If set, notify local mep is active */
    CTC_OAM_BFD_LMEP_FLAG_LM_EN           = 0x00000002,  /**< [GB.GG] [TP BFD] If set, indicate local mep enable LM */
    CTC_OAM_BFD_LMEP_FLAG_CSF_EN          = 0x00000004,  /**< [GB.GG] [TP BFD] If set, notify CSF is enable */
    CTC_OAM_BFD_LMEP_FLAG_TX_CSF_EN       = 0x00000008,  /**< [GB.GG] [TP BFD] If set, indicate local mep enable TX CSF */
    CTC_OAM_BFD_LMEP_FLAG_MEP_ON_CPU      = 0x00000010,  /**< [GB.GG] If set, notify local mep is proc by software not by asic */
    CTC_OAM_BFD_LMEP_FLAG_APS_EN          = 0x00000020,  /**< [GB.GG] If set, notify local mep aps message is enable */
    CTC_OAM_BFD_LMEP_FLAG_IP_SINGLE_HOP   = 0x00000040,  /**< [GB.GG] [IP BFD] If set, notify local mep is single hop */
    CTC_OAM_BFD_LMEP_FLAG_WITHOUT_GAL     = 0x00000080,  /**< [GB.GG] [TP BFD] If set, notify local mep is without GAL */
    CTC_OAM_BFD_LMEP_FLAG_TP_WITH_MEP_ID  = 0x00000100,  /**< [GB.GG] [TP BFD] If set, notify local mep with source MEP ID tlv */
    CTC_OAM_BFD_LMEP_FLAG_MPLS_PW_VCCV    = 0x00000200,  /**< [GB.GG] [TP BFD] If set, notify local mep mpls PW MEP with no IP */
    CTC_OAM_BFD_LMEP_FLAG_IPV4_ENCAP      = 0x00000400,  /**< [GG] [IP BFD] If set, notify local mep with ipv4 address */
    CTC_OAM_BFD_LMEP_FLAG_IPV6_ENCAP            = 0x00000800,  /**< [GG] [TP BFD] If set, notify local mep with ipv6 address */
    CTC_OAM_BFD_LMEP_FLAG_MPLS_PW_VCCV_IPV4    = 0x00001000,  /**< [GB.GG] [TP BFD] If set, notify local mep mpls PW MEP */
    CTC_OAM_BFD_LMEP_FLAG_MPLS_PW_VCCV_IPV6    = 0x00002000,  /**< [GG] [TP BFD] If set, notify local mep mpls PW MEP */
    CTC_OAM_BFD_LMEP_FLAG_PROTECTION_PATH = 0x00004000,  /**< [GB.GG] [TP BFD] If set, notify local mep config in aps protection path, else working path */
    CTC_OAM_BFD_LMEP_FLAG_ALL             = 0x00007FFF   /**< [GB.GG] All */
};
typedef enum ctc_oam_bfd_lmep_flag_e ctc_oam_bfd_lmep_flag_t;

/**
 @brief   Define BFD OAM  local mep  update type
*/
enum ctc_oam_bfd_lmep_update_type_e
{
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_NONE,                      /**< Update local mep none */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_MEP_EN,                    /**< [GB.GG] Update local mep enable,  update_value:1 (enable), update_value:0 (disable)*/
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_CC_EN,                     /**< [GB.GG] Update local BFD tx enable,  update_value:1 (enable), update_value:0 (disable)*/
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_CV_EN,                     /**< [GB.GG] Update local BFD cv enable,  update_value:1 (enable), update_value:0 (disable);*/
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_TX_COS_EXP,                /**< [GB.GG] Update local transmit cos value,                update_value: cos value */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_LMEP_SF_STATE,             /**< [GB] Update local signal fail state value,   update_value: signal fail state */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_CSF_EN,                    /**< [GB.GG] Update local mep process csf, update_value:1 (enable), update_value:0 (disable)*/
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_TX_CSF_EN,                 /**< [GB.GG] Update local mep CSF tx enable */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_TX_CSF_TYPE,               /**< [GB.GG] Update local mep CSF tx type */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_DCSF,                      /**< [GB.GG] Update local mep csf defect, update_value:1 (set), update_value:0 (clear)*/
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_LM_EN,                     /**< [GB.GG] Update local mep LM enable */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_LM_COS_TYPE,               /**< [GB.GG] Update local mep LM cos type, */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_LM_COS,                    /**< [GB.GG] Update local mep LM cos */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_TX_TIMER,                  /**< [GB.GG] Update desired min tx interval
                                                                 & detection interval multiplier, p_update_value refer to ctc_oam_bfd_timer_t */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_ACTUAL_TX_TIMER,           /**< [GB.GG] Update acutal tx interval*/
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_DIAG,                      /**< [GB.GG] Update local mep diagnostic code */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_STATE,                     /**< [GB.GG] Update local mep session state */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_DISCR,                     /**< [GB.GG] Update local mep My discriminator */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_NHOP,                      /**< [GB.GG] Update local mep nextHop id */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_LOCK,                      /**< [GG] [TP BFD] Update local mep lock */
    CTC_OAM_BFD_LMEP_UPDATE_TYPE_MAX
};
typedef enum ctc_oam_bfd_lmep_update_type_e ctc_oam_bfd_lmep_update_type_t;

/**
 @brief   Define BFD OAM local mep
*/
struct ctc_oam_bfd_lmep_s
{
    uint32 flag;                    /**< [GB.GG] Local mep flag,   refer to ctc_oam_bfd_lmep_flag_t */

    uint8  master_gchip;            /**< [GB.GG] Configured linkagg MEP's master gchip ID,the detail refers to userguide */
    uint8  local_diag;              /**< [GB.GG] Local diagnostic code, refer to ctc_oam_bfd_diag_t */
    uint8  local_state;             /**< [GB.GG] Local session state, refer to ctc_oam_bfd_state_t */
    uint8  local_detect_mult;       /**< [GB.GG] Local detection interval multiplier */

    uint32 local_discr;             /**< [GB.GG] My discriminator */

    uint16 desired_min_tx_interval; /**< [GB.GG] Desired local min tx interval */
    uint8  resv;
    uint8  mpls_spaceid;            /**< [GB.GG] MPLS Label space ID */

    uint8  mep_id[CTC_OAM_BFD_CV_MEP_ID_MAX_LEN];   /**< [GB.GG] Local mep MPLS-TP CC/CV TLV and source MEP ID */
    uint8  mep_id_len;                              /**< [GB.GG] Length of MPLS-TP CC/CV TLV and source MEP ID */
    uint8  lm_cos_type;             /**< [GB.GG] Local mep loss measurement cos type, refer to  ctc_oam_lm_cos_type_t */
    uint8  lm_cos;                  /**< [GB.GG] Local mep loss measurement cos for lm cos type CTC_OAM_LM_COS_TYPE_SPECIFIED_COS */
    uint8  tx_csf_type;             /**< [GB.GG] Local mep tx csf type, refer to ctc_oam_csf_type_t */

    uint8  tx_cos_exp;              /**< [GB.GG] Local mep tx cos */
    uint8  ttl;                     /**< [GB.GG] Local mep tx mpls ttl for MPLS-TP BFD or ip ttl for IP BFD */
    uint16 bfd_src_port;            /**< [GB.GG] Source UDP port for MPLS and IP BFD */

    uint32 nhid;                    /**< [GB.GG] NextHop id */
    uint32 mpls_in_label;           /**< [GB.GG] [MPLS BFD] MPLS in label */

    ip_addr_t   ip4_sa;             /**< [GB.GG] IPv4 IPSa for MPLS BFD */
    ip_addr_t   ip4_da;             /**< [GG] IPv4 IPDa for MPLS BFD */
    ipv6_addr_t ipv6_sa;            /**< [GG] IPv6 source address */
    ipv6_addr_t ipv6_da;            /**< [GG] IPv6 destination address */

};
typedef struct ctc_oam_bfd_lmep_s ctc_oam_bfd_lmep_t;

/**
 @brief   Define BFD OAM remote mep flag
*/
enum ctc_oam_bfd_rmep_flag_e
{
    CTC_OAM_BFD_RMEP_FLAG_NONE              = 0x00000000, /**< [GB.GG] None */
    CTC_OAM_BFD_RMEP_FLAG_MEP_EN            = 0x00000001, /**< [GB.GG] If set, notify Remote mep is active */
    CTC_OAM_BFD_RMEP_FLAG_TP_WITH_MEP_ID    = 0x00000002, /**< [GG] If set, represent Remote mep id */
    CTC_OAM_BFD_RMEP_FLAG_ALL               = 0x00000003  /**< [GB.GG] All */
};
typedef enum ctc_oam_bfd_rmep_flag_e ctc_oam_bfd_rmep_flag_t;

/**
 @brief   Define BFD OAM remote mep update type
*/
enum ctc_oam_bfd_rmep_update_type_e
{
    CTC_OAM_BFD_RMEP_UPDATE_TYPE_NONE,              /**< [GB.GG] Update Remote mep none */
    CTC_OAM_BFD_RMEP_UPDATE_TYPE_MEP_EN,            /**< [GB.GG] Update Remote mep enable,  update_value:1 (enable), update_value:0 (disable)*/
    CTC_OAM_BFD_RMEP_UPDATE_TYPE_RMEP_SF_STATE,     /**< [GB] Update remote mep signal fail state value,  update_value: signal fail state */
    CTC_OAM_BFD_RMEP_UPDATE_TYPE_RX_TIMER,          /**< [GB.GG] Update required min rx interval
                                                                 &can not update remote detection interval multiplier, p_update_value refer to ctc_oam_bfd_timer_t */
    CTC_OAM_BFD_RMEP_UPDATE_TYPE_ACTUAL_RX_TIMER,   /**< [GB.GG] Update acutal rx interval*/
    CTC_OAM_BFD_RMEP_UPDATE_TYPE_DIAG,              /**< [GB.GG] Update remote diagnostic code, refer to ctc_oam_bfd_diag_t */
    CTC_OAM_BFD_RMEP_UPDATE_TYPE_STATE,             /**< [GB.GG] Update remote session state, refer to ctc_oam_bfd_state_t */
    CTC_OAM_BFD_RMEP_UPDATE_TYPE_DISCR,             /**< [GB.GG] Update remote mep discriminator */
    CTC_OAM_BFD_RMEP_UPDATE_TYPE_MAX
};
typedef enum ctc_oam_bfd_rmep_update_type_e ctc_oam_bfd_rmep_update_type_t;

/**
 @brief   Define BFD OAM remote mep
*/
struct ctc_oam_bfd_rmep_s
{
    uint32 flag;                        /**< [GB.GG] Remote mep flag,   refer to ctc_oam_bfd_rmep_flag_t */
    uint32 remote_discr;                /**< [GB.GG] Your discriminator */

    uint16 required_min_rx_interval;    /**< [GB.GG] Required remote min rx interval */
    uint8  remote_diag;                 /**< [GB.GG] Remote diagnostic code, refer to ctc_oam_bfd_diag_t */
    uint8  remote_state;                /**< [GB.GG] Remote session state, refer to ctc_oam_bfd_state_t */

    uint8  remote_detect_mult;          /**< [GB.GG] Remote detection interval multiplier */
    uint8  resv[3];

    uint8  mep_id[CTC_OAM_BFD_CV_MEP_ID_MAX_LEN];   /**< [GG] Remote mep MPLS-TP CC/CV TLV and source MEP ID */
    uint8  mep_id_len;                              /**< [GG] Length of MPLS-TP CC/CV TLV and source MEP ID */
};
typedef struct ctc_oam_bfd_rmep_s ctc_oam_bfd_rmep_t;

/**
 @brief   Define BFD property configure type
*/
enum ctc_oam_bfd_cfg_type_e
{
    CTC_OAM_BFD_CFG_TYPE_SLOW_INTERVAL, /**< [GG] Config BFD actual tx/rx interval when establish session, need set value, unit: msec */

    CTC_OAM_BFD_CFG_TYPE_MAX
};
typedef enum ctc_oam_bfd_cfg_type_e ctc_oam_bfd_cfg_type_t;


/**
 @brief   Define BFD OAM property data structure
*/
struct ctc_oam_bfd_prop_s
{
    uint8    cfg_type;  /**< [GG] Config type, assign to ctc_oam_bfd_cfg_type_t */
    uint8    rsv[3];

    uint32 value;         /**< [GG] Configure value,      set depend on cfg_type */
};
typedef struct ctc_oam_bfd_prop_s  ctc_oam_bfd_prop_t;

/*
 @brief   Define BFD Local MEP data structure get from both SDK database and ASIC dataset
*/
struct ctc_oam_bfd_lmep_info_s
{
    uint8   mep_en;                 /**< [GB.GG] Active flag in local mep */
    uint8   cc_enable;                  /**< [GB.GG] BFD enable */
    uint8   cv_enable;                  /**< [GB.GG] BFD CV enable */
    uint8   resv;

    uint8   aps_enable;                 /**< [GB.GG] APS Message enable */
    uint8   loacl_state;                /**< [GB.GG] BFD session local mep state */
    uint8   local_diag;                 /**< [GB.GG] BFD session local mep diagnostic code */
    uint8   local_detect_mult;          /**< [GB.GG] BFD session local mep detection interval multiplier */

    uint32  local_discr;                /**< [GB.GG] BFD session local mep discriminator */

    uint16  actual_tx_interval;         /**< [GB.GG] BFD session actual local tx interval */
    uint16  desired_min_tx_interval;    /**< [GB.GG] BFD session desired local min tx interval */

    uint8   mep_id[CTC_OAM_BFD_CV_MEP_ID_MAX_LEN];  /**< [GB.GG] Source mep id */

    uint8   single_hop;                 /**< [GB.GG] BFD session is single hop */
    uint8   csf_en;                     /**< [GB.GG] CSF enable */
    uint8   d_csf;                      /**< [GB.GG] CSF defect */
    uint8   rx_csf_type;                /**< [GB.GG] Rx CSF type from remote */
};
typedef struct ctc_oam_bfd_lmep_info_s ctc_oam_bfd_lmep_info_t;

/*
 @brief   Define BFD Remote MEP data structure get from both SDK database and ASIC dataset
*/
struct ctc_oam_bfd_rmep_info_s
{
    uint16  lmep_index;                 /**< [GB.GG] Local mep table index */
    uint8   first_pkt_rx;               /**< [GB.GG] First packet receive flag */
    uint8   mep_en;                     /**< [GB.GG] Active falg in Remote mep */

    uint8   mis_connect;                /**< [GB.GG] Mis-connect defect */
    uint8   remote_state;               /**< [GB.GG] BFD session remote mep state */
    uint8   remote_diag;                /**< [GB.GG] BFD session remote mep diagnostic code */
    uint8   remote_detect_mult;         /**< [GB.GG] BFD session remote mep detection interval multiplier */

    uint32  remote_discr;               /**< [GB.GG] BFD session remote mep discriminator */

    uint16  actual_rx_interval;         /**< [GB.GG] BFD session actual local rx interval */
    uint16  required_min_rx_interval;   /**< [GB.GG] BFD session required remote min rx interval */
};
typedef struct ctc_oam_bfd_rmep_info_s ctc_oam_bfd_rmep_info_t;

/**@} end of @defgroup bfd_oam BFD_OAM */

#ifdef __cplusplus
}
#endif

#endif

