/**
 @file ctc_oam_y1731.h

 @date 2010-1-19

 @version v2.0

 This file contains Ethernet OAM(80.21.ag/y1731) ,MPLS TP OAM(Y.1731) OAM related data structure, enum, macro.

*/

#ifndef _CTC_OAM_Y1731_H
#define _CTC_OAM_Y1731_H
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
 @defgroup y1731_oam Y.1731_OAM
 @{
*/
#define CTC_OAM_ETH_MAX_SENDER_ID_LEN        15     /**< The max length of SENDER ID */

/**
 @brief  Define CFM OAM port status
*/
enum ctc_oam_eth_port_status_s
{
    CTC_OAM_ETH_PS_BLOCKED=1,         /**< [HB.GB.GG] Ordinary data can't pass the port mep resides*/
    CTC_OAM_ETH_PS_UP                 /**< [HB.GB.GG] Ordinary data can pass the port mep resides*/
};
typedef enum ctc_oam_eth_port_status_s ctc_oam_eth_port_status_t;

/**
 @brief  Define CFM OAM interface status
*/
enum ctc_oam_eth_interface_status_s
{
    CTC_OAM_ETH_INTF_IS_UP = 1,                  /**< [HB.GB.GG] Interface is ready to pass pkt*/
    CTC_OAM_ETH_INTF_IS_DOWN,                    /**< [HB.GB.GG] Interface can't pass pkt*/
    CTC_OAM_ETH_INTF_IS_TESTING,                 /**< [HB.GB.GG] Interface in some test mode*/
    CTC_OAM_ETH_INTF_IS_UNKNOWN,                 /**< [HB.GB.GG] Interface status can't be determined*/
    CTC_OAM_ETH_INTF_IS_DORMANT,                 /**< [HB.GB.GG] Interface in a pending state*/
    CTC_OAM_ETH_INTF_IS_NOT_PRESENT,             /**< [HB.GB.GG] Some componet is missing*/
    CTC_OAM_ETH_INTF_IS_LOWER_LAYER_DOWN         /**< [HB.GB.GG] Interface is down due to lower layer stauts*/
};
typedef enum ctc_oam_eth_interface_status_s ctc_oam_eth_interface_status_t;

/**
 @brief   Define the senderid of CCM in 802.1ag mode
 */
struct ctc_oam_eth_senderid_s
{
    uint8 sender_id[CTC_OAM_ETH_MAX_SENDER_ID_LEN]; /**< [HB.GB.GG] Sender id  */
    uint8 sender_id_len;                            /**< [HB.GB.GG] The length of sender id */
};
typedef struct ctc_oam_eth_senderid_s ctc_oam_eth_senderid_t;

/**
 @brief   Define Ethernet OAM local mep flag
*/
enum ctc_oam_y1731_lmep_flag_e
{
    CTC_OAM_Y1731_LMEP_FLAG_NONE            = 0x00000000,  /**< [HB.GB.GG] None*/
    CTC_OAM_Y1731_LMEP_FLAG_MEP_EN          = 0x00000001,  /**< [HB.GB.GG] If set, notify local mep is active */
    CTC_OAM_Y1731_LMEP_FLAG_DM_EN           = 0x00000002,  /**< [HB.GB.GG] If set, notify local mep dm is enbale */
    CTC_OAM_Y1731_LMEP_FLAG_LM_EN           = 0x00000004,  /**< [GB.GG] If set, indicate local mep enable LM*/
    CTC_OAM_Y1731_LMEP_FLAG_TX_CSF_EN       = 0x00000008,  /**< [GB.GG] If set, indicate local mep enable TX CSF*/
    CTC_OAM_Y1731_LMEP_FLAG_MEP_ON_CPU      = 0x00000010,  /**< [HB.GB.GG] If set, notify local mep is proc by software not by asic */
    CTC_OAM_Y1731_LMEP_FLAG_APS_EN          = 0x00000020,  /**< [HB.GB.GG] If set, notify local mep aps message is enable */
    CTC_OAM_Y1731_LMEP_FLAG_CCM_SEQ_NUM_EN  = 0x00000040,  /**< [HB.GB.GG] [1ag] If set, notify local mep ccm sequence num is enbale */
    CTC_OAM_Y1731_LMEP_FLAG_TX_IF_STATUS    = 0x00000080,  /**< [HB.GB.GG] [1ag] If set, notify local mep ccm tx with interface status */
    CTC_OAM_Y1731_LMEP_FLAG_TX_PORT_STATUS  = 0x00000100,  /**< [HB.GB.GG] [1ag] If set, notify local mep ccm tx with port status */
    CTC_OAM_Y1731_LMEP_FLAG_TX_SEND_ID      = 0x00000200,  /**< [HB.GB.GG] [1ag] If set, notify local mep ccm tx with sender id */
    CTC_OAM_Y1731_LMEP_FLAG_VPLSOAM         = 0x00000400,  /**< [HB] [1ag/Y1731] If set, indicate local mep  is vpls/vpws mep */
    CTC_OAM_Y1731_LMEP_FLAG_P2P_MODE        = 0x00000800,  /**< [GB.GG] [1ag/Y1731] If set, indicate local mep  is p2p mep */
    CTC_OAM_Y1731_LMEP_FLAG_SHARE_MAC       = 0x00001000,  /**< [HB.GB.GG] [1ag/Y1731] If set, indicate local mep share mac mode*/
    CTC_OAM_Y1731_LMEP_FLAG_WITHOUT_GAL     = 0x00002000,  /**< [GB.GG] [TP Y1731] If set, notify local mep pw without gal */
    CTC_OAM_Y1731_LMEP_FLAG_PROTECTION_PATH = 0x00004000,  /**< [GB.GG] [TP Y1731] If set, notify local mep config on protection path, else working path*/
    CTC_OAM_Y1731_LMEP_FLAG_ALL             = 0x00007FFF   /**< [HB.GB.GG] All*/
};
typedef enum ctc_oam_y1731_lmep_flag_e ctc_oam_y1731_lmep_flag_t;

/**
 @brief   Define Ethernet OAM  local mep  update type
*/
enum ctc_oam_y1731_lmep_update_type_e
{
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_NONE,              /**< [HB.GB.GG] Update local mep none */
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_MEP_EN,            /**< [HB.GB.GG]Update local mep enable,  update_value:1 (enable), update_value:0 (disabel)*/
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_CCM_EN,            /**< [HB.GB.GG] Update local ccm enable,  update_value:1 (enable), update_value:0 (disabel)*/
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_DM_EN,             /**< [HB.GB.GG] Update local dm enable,   update_value:1 (enable), update_value:0 (disabel)*/
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_TX_COS_EXP,        /**< [HB.GB.GG] Update local transmit cos value,                update_value: cos value*/
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_RDI,               /**< [HB.GB.GG] Update local rdi value,   update_value:1 (set rdi), update_value:0 (clear rdi)*/
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_LMEP_SF_STATE,     /**< [HB.GB.GG] Update local signal fail state value,   update_value: signal fail state*/
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_CCM_SEQ_NUM_EN,    /**< [HB.GB.GG] [1ag] Update local mep ccm sequence number,  update_value:1 (enable), update_value:0 (disabel)*/
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_TX_CSF_EN,         /**< [GB.GG] Update local mep CSF tx enable */
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_TX_CSF_TYPE,       /**< [GB.GG] Update local mep CSF tx type*/
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_LM_EN,             /**< [GB.GG] Update local mep LM enable */
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_LM_TYPE,           /**< [GB.GG] Update local mep LM type,  */
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_LM_COS_TYPE,       /**< [GB.GG] Update local mep LM cos type, */
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_LM_COS,            /**< [GB.GG] Update local mep LM cos */
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_PORT_STATUS,       /**< [HB.GB.GG] [1ag] Update local transmit port status value,        update_value: port status value*/
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_IF_STATUS,         /**< [HB.GB.GG] [1ag] Update local transmit interface status value,   update_value: interface status value*/
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_TX_CSF_USE_UC_DA,  /**< [GB.GG] [1ag/Y1731] Update local mep p2p mep CSF tx use unicast da */
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_P2P_TX_USE_UC_DA,  /**< [GB.GG] [1ag/Y1731] Update local mep p2p mep tx use unicast da */
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_NHOP,              /**< [GB.GG] [TP Y1731] Update local mep nextHop id                 */
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_MEL,               /**< [GB.GG] [TP Y1731] Update local mep md level*/
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_TRPT,              /**<[GB.GG] Update local mep throughput state, 0xff means disable, 0~3 is valid */
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_LOCK,           /**< [GG] [TP Y1731] Update local mep lock*/
    CTC_OAM_Y1731_LMEP_UPDATE_TYPE_MAX
};
typedef enum ctc_oam_y1731_lmep_update_type_e ctc_oam_y1731_lmep_update_type_t;

/**
 @brief   Define Ethernet OAM  local mep
*/
struct ctc_oam_y1731_lmep_s
{
    uint32 flag;                 /**< [HB.GB.GG] Local mep flag,   assign to ctc_oam_y1731_lmep_flag_t,       set for add api*/

    uint8  master_gchip;         /**< [HB.GB.GG] Configured linkagg MEP's master gchip ID,the detail refers to userguide*/
    uint8  ccm_interval;         /**< [HB.GB.GG] Local mep ccm interval,                                          set for add api*/
    uint16 mep_id;               /**< [HB.GB.GG] Local mep mep id,                                                set for add api*/

    uint8  lm_type;              /**< [GB.GG] Local mep loss measurement type, ctc_oam_lm_type_t   */
    uint8  lm_cos_type;          /**< [GB.GG] Local mep loss measurement cos type,   ctc_oam_lm_cos_type_t*/
    uint8  lm_cos;               /**< [GB.GG] Local mep loss measurement cos for lm cos type CTC_OAM_LM_COS_TYPE_SPECIFIED_COS */
    uint8  tx_csf_type;          /**< [GB.GG] Local mep tx csf type,  ctc_oam_csf_type_t           */

    uint8  tx_cos_exp;           /**< [HB.GB.GG] Local mep tx cos,                                 */
    uint8  tpid_index;           /**< [HB.GB.GG] [1ag/Y1731] Local mep ether type index for vlan tpid,                        set for add api*/
    uint16 ccm_gport_id;         /**< [HB] [1ag/Y1731] Local mep tx port id,                                */

    uint32 up_mep_tx_mc_grp_id;  /**< [HB] [1ag/Y1731] Local mep up mep tx group id,                        */

    uint8  mpls_ttl;             /**< [GB.GG] [TP Y1731] Local mep tx mpls ttl*/
    uint8  resv0[3];

    uint32 nhid;                 /**< [GB.GG] [TP Y1731] NextHop id,                 */
};
typedef struct ctc_oam_y1731_lmep_s ctc_oam_y1731_lmep_t;

/**
 @brief   Define Ethernet OAM remote mep flag
*/
enum ctc_oam_y1731_rmep_flag_e
{
    CTC_OAM_Y1731_RMEP_FLAG_NONE              = 0x00000000, /**< [HB.GB.GG] None*/
    CTC_OAM_Y1731_RMEP_FLAG_MEP_EN            = 0x00000001, /**< [HB.GB.GG] If set, notify Remote mep is active */
    CTC_OAM_Y1731_RMEP_FLAG_CSF_EN            = 0x00000002, /**< [GB.GG] If set, notify Remote mep source mac learn enable */
    CTC_OAM_Y1731_RMEP_FLAG_CCM_SEQ_NUM_EN    = 0x00000004, /**< [HB.GB.GG] [1ag] If set, notify Remote mep sequence num enable */
    CTC_OAM_Y1731_RMEP_FLAG_MAC_UPDATE_EN     = 0x00000008, /**< [HB.GB.GG] [1ag] If set, notify Remote mep source mac learn enable */
    CTC_OAM_Y1731_RMEP_FLAG_ALL               = 0x0000000F  /**< [HB.GB.GG] All*/
};
typedef enum ctc_oam_y1731_rmep_flag_e ctc_oam_y1731_rmep_flag_t;

/**
 @brief   Define Ethernet OAM remote mep update type
*/
enum ctc_oam_y1731_rmep_update_type_e
{
    CTC_OAM_Y1731_RMEP_UPDATE_TYPE_NONE,              /**< [HB.GB.GG] Update Remote mep none */
    CTC_OAM_Y1731_RMEP_UPDATE_TYPE_MEP_EN,            /**< [HB.GB.GG] Update Remote mep enable,  update_value:1 (enable), update_value:0 (disabel)*/
    CTC_OAM_Y1731_RMEP_UPDATE_TYPE_CSF_EN,            /**< [GB.GG] Update Remote mep process csf, update_value:1 (enable), update_value:0 (disabel)*/
    CTC_OAM_Y1731_RMEP_UPDATE_TYPE_DCSF,              /**< [GB.GG] Update Remote mep csf defect, update_value:1 (set), update_value:0 (clear)*/
    CTC_OAM_Y1731_RMEP_UPDATE_TYPE_RMEP_SF_STATE,     /**< [HB.GB.GG] Update remote signal fail state value,  update_value: signal fail state*/
    CTC_OAM_Y1731_RMEP_UPDATE_TYPE_SEQ_FAIL_CLEAR,    /**< [HB.GB.GG] [1ag] Update Remote mep sequence num,  counter is reset*/
    CTC_OAM_Y1731_RMEP_UPDATE_TYPE_CCM_SEQ_NUM_EN,    /**< [GB.GG] [1ag] Update Remote mep ccm sequence number,  update_value:1 (enable), update_value:0 (disabel)*/
    CTC_OAM_Y1731_RMEP_UPDATE_TYPE_RMAC_MIS,          /**< [GB.GG] [1ag] Update Remote mep mac mismatch, update_value:1 (set), update_value:0 (clear)*/
    CTC_OAM_Y1731_RMEP_UPDATE_TYPE_PORT_INTF_MIS,     /**< [GB.GG] [1ag] Update Remote mep mac status mismatch, update_value:1 (set), update_value:0 (clear)*/
    CTC_OAM_Y1731_RMEP_UPDATE_TYPE_MAX
};
typedef enum ctc_oam_y1731_rmep_update_type_e ctc_oam_y1731_rmep_update_type_t;

/**
 @brief   Define Ethernet OAM remote mep data structure
*/
struct ctc_oam_y1731_rmep_s
{
    uint32 flag;           /**< [HB.GB.GG] Remote mep flag,         assign to ctc_oam_y1731_rmep_flag_t,       set for add api*/

    uint16     rmep_id;    /**< [HB.GB.GG] Remote mep mep id,                                                set for add api*/
    mac_addr_t rmep_mac;   /**< [HB.GB.GG] [1ag/Y1731] Remote mep mac address,                                           set for add api*/
};
typedef struct ctc_oam_y1731_rmep_s ctc_oam_y1731_rmep_t;

/**
 @brief   Define Ethernet OAM property configure type
*/
enum ctc_oam_y1731_cfg_type_e
{
    CTC_OAM_Y1731_CFG_TYPE_BIG_CCM_INTERVAL_TO_CPU, /**< [HB.GB.GG] Config larger ccm to cpu,      need set value[Larger_ccm_interval]*/
    CTC_OAM_Y1731_CFG_TYPE_LBM_PROC_IN_ASIC,       /**< [HB.GB.GG] Config LBM process by ASIC, need set value[1:asic,0:cpu]*/
    CTC_OAM_Y1731_CFG_TYPE_LMM_PROC_IN_ASIC,       /**< [GB.GG] Config LMM process by ASIC, need set value[1:asic,0:cpu]*/
    CTC_OAM_Y1731_CFG_TYPE_DM_PROC_IN_ASIC,        /**< [GB.GG] Config DM process by ASIC, need set value[1:asic,0:cpu]*/
    CTC_OAM_Y1731_CFG_TYPE_SLM_PROC_IN_ASIC,       /**< [GG] Config SLM process by ASIC, need set value[1:asic,0:cpu]*/

    CTC_OAM_Y1731_CFG_TYPE_PORT_OAM_EN,            /**< [HB.GB.GG] [1ag/Y1731] Config port oam en,            need set gport, dir , value[1:enable,0:disable] */
    CTC_OAM_Y1731_CFG_TYPE_PORT_TUNNEL_EN,         /**< [HB.GB.GG] [1ag/Y1731] Config port tunnel en,         need set gport, value[1:enable,0:disable] */
    CTC_OAM_Y1731_CFG_TYPE_ALL_TO_CPU,             /**< [HB.GB.GG] [1ag/Y1731] Config all packet proc by cpu, need set vlaue[1:enable,0:disable] */
    CTC_OAM_Y1731_CFG_TYPE_TX_VLAN_TPID,           /**< [HB.GB.GG] [1ag/Y1731] Config TX vlan tpid,           need set value[31:16] tpid_index, value[15:0] vlan_tpid */
    CTC_OAM_Y1731_CFG_TYPE_RX_VLAN_TPID,           /**< [HB.GB.GG] [1ag/Y1731] Config RX vlan tpid,           need set value[31:16] tpid_index, value[15:0] vlan_tpid */
    CTC_OAM_Y1731_CFG_TYPE_ADD_EDGE_PORT,          /**< [HB.GB.GG] [1ag/Y1731] Config add edge to mep,        need set gport, humber need value[md_level]*/
    CTC_OAM_Y1731_CFG_TYPE_REMOVE_EDGE_PORT,       /**< [HB.GB.GG] [1ag/Y1731] Config remove edge from mep,   need set gport*/
    CTC_OAM_Y1731_CFG_TYPE_SENDER_ID,              /**< [HB.GB.GG] [1ag/Y1731] Config senderid,       need set p_value[ctc_oam_eth_senderid_t]*/
    CTC_OAM_Y1731_CFG_TYPE_BRIDGE_MAC,             /**< [HB.GB.GG] [1ag/Y1731] Config bridge mac for share mac mode, need set p_value[mac_addr_t]*/
    CTC_OAM_Y1731_CFG_TYPE_LBR_SA_USE_LBM_DA,      /**< [HB.GB.GG] [1ag/Y1731] Config reply LBR sa use LBM mac da when unicast LBM, need set value[1:enable,0:disable]*/
    CTC_OAM_Y1731_CFG_TYPE_LBR_SA_SHARE_MAC,       /**< [HB.GB.GG] [1ag/Y1731] Global config reply LBR use share mac mode, need set value*/

    CTC_OAM_Y1731_CFG_TYPE_VLAN_OAM_EN,            /**< [HB] [1ag/Y1731] Config vlan oam enable,        need set vlan_id, value[1:enable,0:disable] */
    CTC_OAM_Y1731_CFG_TYPE_PORT_MAX_LEVEL,         /**< [HB] [1ag/Y1731] Config port max level,         need set gport, dir ,value[max level]*/
    CTC_OAM_Y1731_CFG_TYPE_VLAN_MAX_LEVEL,         /**< [HB] [1ag/Y1731] Config vlan max level,         need set vlan_id, dir ,value[max level]*/
    CTC_OAM_Y1731_CFG_TYPE_PORT_LM_EN,             /**< [GB.GG] [1ag/Y1731] Config port lm en,    value[1:enable,0:disable] */

    CTC_OAM_Y1731_CFG_TYPE_L2VPN_OAM_MODE, /**< [GG] [1ag/Y1731] Config L2VPN oam mode, need set
                                                        value[0: Port + Oam ID; 1: Port + Vlan] */


    CTC_OAM_Y1731_CFG_TYPE_MAX
};
typedef enum ctc_oam_y1731_cfg_type_e ctc_oam_y1731_cfg_type_t;

/**
 @brief   Define Ethernet OAM property data structure
*/
struct ctc_oam_y1731_prop_s
{
    uint8    cfg_type;  /**< [HB.GB.GG] Config type, assign to ctc_oam_y1731_cfg_type_t*/
    uint8    dir;       /**< [HB.GB.GG] [1ag/Y1731] Direction,   assign to ctc_direction_t,   set depend on cfg_type*/
    uint16   rsv0;

    uint32 gport;     /**< [HB.GB.GG] [1ag/Y1731] Global port value,    set depend on cfg_type*/
    uint16   vlan_id;   /**< [HB.GB.GG] [1ag/Y1731] Vlan id value, set depend on cfg_type, the vlan_id may be greater than 4095, please refer ctc_vlanptr_mode_t*/

    uint32   value;     /**< [HB.GB.GG] Configure value,      set depend on cfg_type*/
    void*    p_value;   /**< [HB.GB.GG] Configure value,      set depend on cfg_type*/
};
typedef struct ctc_oam_y1731_prop_s ctc_oam_y1731_prop_t;

/*
 @brief   Define Ether & MPLS-TP Y.1731 Local MEP data structure get from both SDK database and ASIC dataset
*/
struct ctc_oam_y1731_lmep_info_s
{
    uint16  mep_id;        /**< [HB.GB.GG] Local mep id*/
    uint8   ccm_interval;  /**< [HB.GB.GG] CCM interval*/
    uint8   ccm_enable;    /**< [HB.GB.GG] CCM enable*/

    uint8   dm_enable;     /**< [HB.GB.GG] DM enable*/
    uint8   aps_enable;    /**< [HB.GB.GG] APS enable*/
    uint8   active;        /**< [HB.GB.GG] Active flag in local mep*/
    uint8   rsv0;

    uint8   present_rdi;   /**< [HB.GB.GG] Present rdi value*/
    uint8   d_unexp_mep;   /**< [HB.GB.GG] Unexp mep defect*/
    uint8   d_mismerge;    /**< [HB.GB.GG] Mismerge defect*/
    uint8   d_meg_lvl;     /**< [HB.GB.GG] Xcon defect*/

    uint32 gport;         /**< [HB.GB.GG] [1ag/Y1731] Global port for chan*/
    uint16  vlan_id;       /**< [HB.GB.GG] [1ag/Y1731] Vlan id for chan, the vlan_id may be greater than 4095, please refer ctc_vlanptr_mode_t*/

    uint8   level;         /**< [HB.GB.GG] [1ag/Y1731] MD level*/
    uint8   is_up_mep;     /**< [HB.GB.GG] [1ag/Y1731]Is upmep or down mep*/
    uint8   seq_num_en;    /**< [HB.GB.GG] [1ag/Y1731] Sequnce number enable*/
    uint8   rsv1;
};
typedef struct ctc_oam_y1731_lmep_info_s ctc_oam_y1731_lmep_info_t;

/*
 @brief   Define Ether & MPLS-TP Y.1731 Remote MEP data structure get from both SDK database and ASIC dataset
*/
struct ctc_oam_y1731_rmep_info_s
{
    uint16  rmep_id;                    /**< [HB.GB.GG] Remote mep id*/
    uint16  lmep_index;                 /**< [HB.GB.GG] Local mep table index*/

    uint8   first_pkt_rx;               /**< [HB.GB.GG] First packet receive flag*/
    uint8   active;                     /**< [HB.GB.GG] Active falg in Remote mep*/
    uint8   last_rdi;                   /**< [HB.GB.GG] Last rdi value*/
    uint8   d_loc;                      /**< [HB.GB.GG] Dloc defect*/

    uint8   d_unexp_period;             /**< [HB.GB.GG] Unexpect ccm period defect*/
    uint8   csf_en;                     /**< [GB.GG] CSF enable*/
    uint8   d_csf;                      /**< [GB.GG] CSF defect*/
    uint8   rx_csf_type;                /**< [GB.GG] Rx CSF type from remote*/

    uint8   is_p2p_mode;                /**< [HB.GB.GG] [1ag/Y1731] P2P mode falg in Remote mep*/
    uint8   last_port_status;           /**< [HB.GB.GG] [1ag] Last port status*/
    uint8   last_intf_status;           /**< [HB.GB.GG] [1ag] Last interface status*/
    uint8   seq_fail_count;             /**< [HB.GB.GG] [1ag] Sequence number check fail counters*/

    uint8   ma_sa_mismatch;             /**< [GB.GG] [1ag] Mac sa mismatch defect*/
    uint8   mac_status_change;          /**< [GB.GG] [1ag] Mac sa change flag*/
    uint8   mac_sa[CTC_ETH_ADDR_LEN];   /**< [HB.GB.GG] [1ag/Y1731] Mac sa value of remote mep*/
};
typedef struct ctc_oam_y1731_rmep_info_s ctc_oam_y1731_rmep_info_t;

/**@} end of @defgroup  y1731_oam Y.1731_OAM */

#ifdef __cplusplus
}
#endif

#endif

