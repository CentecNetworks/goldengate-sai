/**
 @file ctc_oam.h

 @date 2010-1-19

 @version v2.0

 This file contains Ethernet OAM(80.21.ag/y1731) ,MPLS TP OAM(Y.1731), BFD (IP/MPLS/MPLS-TP) OAM related data structure, enum, macro.

*/

#ifndef _CTC_OAM_H
#define _CTC_OAM_H
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
#include "ctc_linklist.h"
#include "ctc_oam_y1731.h"
#include "ctc_oam_bfd.h"

/****************************************************************
*
* Defines and Macros
*
****************************************************************/

/**
 @defgroup oam OAM
 @{
*/
#define CTC_OAM_MAX_ERROR_CACHE_NUM             16      /**< The max num of error cache */
#define CTC_OAM_EVENT_MAX_ENTRY_NUM             32      /**< The max num of oam event for isr call back */
#define CTC_OAM_MAX_MAID_LEN                    48      /**< The max length of MAID or MEGID */
#define CTC_OAM_STATS_COS_NUM                   8        /**< The max num of COS based stats */
#define CTC_OAM_TRPT_SESSION_NUM                4       /**< The max num of Throughput session */

/**
 @brief  Define oam exceptions
*/
enum ctc_oam_exceptions_e
{
    CTC_OAM_EXCP_INVALID_OAM_PDU                = 0,  /**< [HB.GB.GG] Exception[0]: Individual OAM PDU */
    CTC_OAM_EXCP_SOME_RDI_DEFECT                = 1,  /**< [HB.GB] Exception[1]: Some RDI defect */
    CTC_OAM_EXCP_SOME_MAC_STATUS_DEFECT         = 2,  /**< [HB.GB] Exception[2]: Some MAC status defect */
    CTC_OAM_EXCP_HIGH_VER_OAM_TO_CPU            = 3,  /**< [HB.GB.GG] Exception[3]: Higher version OAM to CPU */
    CTC_OAM_EXCP_RMEP_NOT_FOUND                 = 4,  /**< [HB.GB] Exception[4]: RMEP not found */
    CTC_OAM_EXCP_XCON_CCM_DEFECT                = 5,  /**< [HB.GB] Exception[5]: cross-connect CCM defect */
    CTC_OAM_EXCP_CCM_SEQ_NUM_ERROR              = 6,  /**< [HB.GB] Exception[6]: CCM sequence number error */
    CTC_OAM_EXCP_CTRL_REG_CFG_ERROR             = 7,  /**< [HB.GB] Exception[7]: Ds or Control Register configure error */
    CTC_OAM_EXCP_OPTION_CCM_TLV                 = 8,  /**< [HB.GB.GG] Exception[8]: CCM has optional TLV */
    CTC_OAM_EXCP_SLOW_OAM_TO_CPU                = 9,  /**< [HB.GB] Exception[9]: Slow OAM to CPU */
    CTC_OAM_EXCP_SMAC_MISMATCH                  = 13, /**< [HB.GB] Exception[13]: Source MAC mismatch */
    CTC_OAM_EXCP_APS_PDU_TO_CPU                 = 16, /**< [HB.GB.GG] Exception[16]: APS PDU to CPU */
    CTC_OAM_EXCP_CCM_INTERVAL_MISMATCH          = 17, /**< [HB.GB] Exception[17]: CCM interval mismatch */
    CTC_OAM_EXCP_DM_TO_CPU                      = 18, /**< [HB.GB.GG] Exception[18]: DM to CPU */
    CTC_OAM_EXCP_PBT_MM_DEFECT_OAM_PDU          = 23, /**< [HB.GB.GG] Exception[23]: PBT mmDefect OAM PDU to CPU */
    CTC_OAM_EXCP_EQUAL_LBR                      = 25, /**< [HB.GB] Exception[25]: LBR to CPU */
    CTC_OAM_EXCP_LM_TO_CPU                      = 27, /**< [HB.GB.GG] Exception[27]: LM to CPU */

    CTC_OAM_EXCP_HIGHER_CCM_ON_CBP              = 11, /**< [HB] Exception[11]: Higher CCM on CBP/PIP */
    CTC_OAM_EXCP_OAM_LOOKUP_NOT_ENABLE          = 12, /**< [HB] Exception[12]: OAM not enabled */
    CTC_OAM_EXCP_FDI_TO_CPU                     = 14, /**< [HB] Exception[14]: FDI to CPU */
    CTC_OAM_EXCP_BDI_TO_CPU                     = 15, /**< [HB] Exception[15]: BDI to CPU */
    CTC_OAM_EXCP_PASSIVE_LOW_TO_CPU             = 19, /**< [HB] Exception[19]: MD level lower than passive's MD level to CPU */
    CTC_OAM_EXCP_MPLS_MEP_CFG_ERROR             = 20, /**< [HB] Exception[20]: MPLS or PBT MEP configure error to CPU */
    CTC_OAM_EXCP_MPLS_CHECK_ERROR               = 21, /**< [HB] Exception[21]: MPLS or PBT check error */
    CTC_OAM_EXCP_PBB_BSI_PDU_TO_CPU             = 22, /**< [HB] Exception[22]: All PBB-BSI OAM PDU to CPU */
    CTC_OAM_EXCP_MPLS_CV0                       = 24, /**< [HB] Exception[24]: Send MPLS Cv0 to CPU */
    CTC_OAM_EXCP_LBM_DMAC_CHECK_FAIL            = 26, /**< [HB] Exception[26]: MAC DA check fail to CPU */

    CTC_OAM_EXCP_ETH_TST_TO_CPU                 = 10, /**< [GB.GG] Exception[10]: Test PDU to CPU */
    CTC_OAM_EXCP_INVALID_BFD_MPLS_DM_DLM_PDU    = 11, /**< [GB] Exception[11]: Invalid BFD/MPLS-TP DM DLM PDU */
    CTC_OAM_EXCP_BIG_INTERVAL_OR_SW_MEP_TO_CPU  = 12, /**< [GB.GG] Exception[12]: Big CCM/BFD interval to CPU or MEP configured in software */
    CTC_OAM_EXCP_MPLS_TP_DLM_TO_CPU             = 14, /**< [GB.GG] Exception[14]: MPLS-TP DLM to CPU */
    CTC_OAM_EXCP_MPLS_TP_DM_DLMDM_TO_CPU        = 15, /**< [GB.GG] Exception[15]: MPLS-TP DM/DLMDM to CPU */
    CTC_OAM_EXCP_CSF_TO_CPU                     = 20, /**< [GB.GG] Exception[20]: Y1731 CSF PDU to CPU */
    CTC_OAM_EXCP_MIP_RECEIVE_NON_PROCESS_PDU    = 21, /**< [GB] Exception[21]: MIP receive non process PDU */
    CTC_OAM_EXCP_MCC_PDU_TO_CPU                 = 22, /**< [GB.GG] Exception[22]: Y1731 MCC PDU to CPU */
    CTC_OAM_EXCP_EQUAL_LTM_LTR_TO_CPU           = 24, /**< [GB.GG] Exception[24]: Equal LTM/LTR to CPU */
    CTC_OAM_EXCP_LBM_MAC_DA_MEP_ID_CHECK_FAIL   = 26, /**< [GB] Exception[26]: LBM MAC DA for Ethernet or MEP ID for MPLS-TP check fail */
    CTC_OAM_EXCP_LEARNING_BFD_TO_CPU            = 28, /**< [GB.GG] Exception[28]: Learning BFD to CPU */
    CTC_OAM_EXCP_ERROR_BFD                      = 29, /**< [GB] Exception[29]: Error BFD */
    CTC_OAM_EXCP_BFD_TIMER_NEGOTIATION          = 30, /**< [GB.GG] Exception[30]: BFD timer negotiation */
    CTC_OAM_EXCP_SCC_PDU_TO_CPU                 = 31, /**< [GB.GG] Exception[31]: Y1731 SCC PDU to CPU */

    CTC_OAM_EXCP_ALL_DEFECT                     = 1,  /**< [GG] Exception[1]: All defect to CPU */
    CTC_OAM_EXCP_LBM                            = 2,  /**< [GG] Exception[2]: Ether LBM/LBR and MPLS-TP LBR to CPU */
    CTC_OAM_EXCP_TP_LBM                         = 4,  /**< [GG] Exception[4]: MPLS-TP LBM to CPU */
    CTC_OAM_EXCP_TP_CSF                         = 5,  /**< [GG] Exception[5]: MPLS-TP CSF to CPU */
    CTC_OAM_EXCP_TP_MCC                         = 6,  /**< [GG] Exception[6]: MPLS-TP MCC to CPU */
    CTC_OAM_EXCP_TP_SCC                         = 7,  /**< [GG] Exception[7]: MPLS-TP SCC to CPU */
    CTC_OAM_EXCP_TP_FM                          = 9,  /**< [GG] Exception[9]: MPLS-TP FM to CPU */
    CTC_OAM_EXCP_SM                             = 11, /**< [GG] Exception[11]: Ether SLM/SLR to CPU */
    CTC_OAM_EXCP_TP_BFD_CV                      = 13, /**< [GG] Exception[13]: TP BFD CV PDU to CPU */
    CTC_OAM_EXCP_UNKNOWN_PDU                    = 17, /**< [GG] Exception[17]: Unknown PDU to CPU */
    CTC_OAM_EXCP_LEARNING_CCM_TO_CPU            = 19, /**< [GG] Exception[19]: Learning CCM to CPU */
    CTC_OAM_EXCP_BFD_DISC_MISMATCH              = 21  /**< [GG] Exception[21]: BFD discreaminator mismatch to CPU */
};
typedef enum ctc_oam_exceptions_e ctc_oam_exceptions_t;

/**
 @brief  Define defects causing aps signal fail message
*/

enum ctc_oam_trig_aps_msg_flag_e
{
    CTC_OAM_TRIG_APS_MSG_FLAG_NONE                = 0x00000000, /**< [HB.GB] None */
    CTC_OAM_TRIG_APS_MSG_FLAG_INTF_STATE          = 0x00000001, /**< [HB.GB] Interface status */
    CTC_OAM_TRIG_APS_MSG_FLAG_PORT_STATE          = 0x00000002, /**< [HB.GB] Port status */
    CTC_OAM_TRIG_APS_MSG_FLAG_RDI                 = 0x00000004, /**< [HB.GB] Defect RDI */
    CTC_OAM_TRIG_APS_MSG_FLAG_D_LOC               = 0x00000008, /**< [HB.GB] Defect loss of connectivity */
    CTC_OAM_TRIG_APS_MSG_FLAG_D_UNEXP_PERIOD      = 0x00000010, /**< [HB.GB] Defect unexpected period */
    CTC_OAM_TRIG_APS_MSG_FLAG_D_MEG_LVL           = 0x00000020, /**< [HB.GB] Defect unexpected MEG level */
    CTC_OAM_TRIG_APS_MSG_FLAG_D_MISMERGE          = 0x00000040, /**< [HB.GB] Defect mismerge */
    CTC_OAM_TRIG_APS_MSG_FLAG_D_UNEXP_MEP         = 0x00000080, /**< [HB.GB] Defect unexpected MEP */

    CTC_OAM_TRIG_APS_MSG_FLAG_BFD_UP_TO_DOWN      = 0x00000100, /**< [GB] BFD state up to down */
    CTC_OAM_TRIG_APS_MSG_FLAG_ALL                 = 0x000001FF  /**< [HB.GB] All */

};
typedef enum ctc_oam_trig_aps_msg_flag_e ctc_oam_trig_aps_msg_flag_t;

/**
 @brief   Define Mep Type
*/
enum ctc_oam_mep_type_e
{
    /*Y.1731*/
    CTC_OAM_MEP_TYPE_ETH_1AG,           /**< [HB.GB.GG] Ethernet 802.1ag  mep */
    CTC_OAM_MEP_TYPE_ETH_Y1731,         /**< [HB.GB.GG] Ethernet Y1731    mep */
    CTC_OAM_MEP_TYPE_MPLS_TP_Y1731,     /**< [GB.GG] MPLS-TP Y.1731    mep */
    /*BFD*/
    CTC_OAM_MEP_TYPE_IP_BFD,            /**< [GB.GG] Ipv4/ipv6    bfd mep */
    CTC_OAM_MEP_TYPE_MPLS_BFD,          /**< [GB.GG] MPLS BFD mep */
    CTC_OAM_MEP_TYPE_MPLS_TP_BFD,       /**< [GB.GG] MPLS-TP BFD mep */

    CTC_OAM_MEP_TYPE_MAX
};
typedef enum ctc_oam_mep_type_e ctc_oam_mep_type_t;

/**
 @brief   Define oam property Type
*/
enum ctc_oam_property_type_e
{
    CTC_OAM_PROPERTY_TYPE_COMMON,       /**< [HB.GB.GG] Common OAM property */
    CTC_OAM_PROPERTY_TYPE_Y1731,        /**< [HB.GB.GG] Y.1731 OAM property */
    CTC_OAM_PROPERTY_TYPE_BFD,          /**< [GB.GG] BFD OAM property */
    CTC_OAM_PROPERTY_TYPE_MAX
};
typedef enum ctc_oam_property_type_e ctc_oam_property_type_t;

/**
 @brief   Define LM Type
*/
enum ctc_oam_lm_type_e
{
    CTC_OAM_LM_TYPE_NONE,           /**< [GB.GG] No Lm enable */
    CTC_OAM_LM_TYPE_DUAL,           /**< [GB.GG] Dual-ended Lm */
    CTC_OAM_LM_TYPE_SINGLE,         /**< [GB.GG] Single-ended Lm */
    CTC_OAM_LM_TYPE_MAX
};
typedef enum ctc_oam_lm_type_e ctc_oam_lm_type_t;

/**
 @brief   Define LM cos Type
*/
enum ctc_oam_lm_cos_type_e
{
    CTC_OAM_LM_COS_TYPE_ALL_COS,            /**< [GB.GG] All cos data counter together */
    CTC_OAM_LM_COS_TYPE_SPECIFIED_COS,      /**< [GB.GG] Only count specified cos data */
    CTC_OAM_LM_COS_TYPE_PER_COS,            /**< [GB.GG] Per cos date to count */
    CTC_OAM_LM_COS_TYPE_MAX
};
typedef enum ctc_oam_lm_cos_type_e ctc_oam_lm_cos_type_t;

/**
 @brief  Define CSF Type
*/
enum ctc_oam_csf_type_e
{
    CTC_OAM_CSF_TYPE_LOS,        /**< [GB.GG] Client loss of signal */
    CTC_OAM_CSF_TYPE_FDI,        /**< [GB.GG] Client forward defect indication */
    CTC_OAM_CSF_TYPE_RDI,        /**< [GB.GG] Client remote defect indication */
    CTC_OAM_CSF_TYPE_DCI,        /**< [GB.GG] Client defect clear indication */
    CTC_OAM_CSF_TYPE_MAX
};
typedef enum ctc_oam_csf_type_e ctc_oam_csf_type_t;

/**
 @brief   Define the error cache structure
 */
struct ctc_oam_error_cache_s
{
    uint8  is_mpls_err_cache;       /**< [HB] If this erorr is for mpls oam */
    uint8  defect_type;             /**< [HB] Defect type */
    uint8  defect_sub_type;         /**< [HB] Defect sub type */
    uint8  port_status_valid;       /**< [HB] If port status is valid */
    uint8  port_status_value;       /**< [HB] Port status value */
    uint8  intf_status_valid;       /**< [HB] If interface status is valid */
    uint8  intf_status_value;       /**< [HB] Interface status value */
    uint8  defect_priority;         /**< [HB] Defect priority */
    uint16 rmep_index;              /**< [HB] Rmep index */
    uint16 mep_index;               /**< [HB] Mep index */
    uint8  is_error_cache_valid;    /**< [HB] If this entry is valid */
    uint8  resv0;
    uint16 resv1;
};
typedef struct ctc_oam_error_cache_s ctc_oam_error_cache_t;

/**
 @brief   Define the error cache array
 */
struct ctc_oam_error_cache_list_s
{
    ctc_oam_error_cache_t oam_error_cache[CTC_OAM_MAX_ERROR_CACHE_NUM]; /**< [HB] All error cache items */
};
typedef struct ctc_oam_error_cache_list_s ctc_oam_error_cache_list_t;

/**
 @brief   Define the defect cache info
 */
struct ctc_oam_defect_info_s
{
    uint8  valid_cache_num;                                 /**< [GB.GG] Indicated valid cache number */
    uint8  rsv0[3];
    uint16 mep_index_base[CTC_OAM_MAX_ERROR_CACHE_NUM];     /**< [GB.GG] MEP index base in error cache */
    uint32 mep_index_bitmap[CTC_OAM_MAX_ERROR_CACHE_NUM];   /**< [GB.GG] MEP bitmap from start MEP index base */
};
typedef struct ctc_oam_defect_info_s ctc_oam_defect_info_t;

/**
* [HB] define defect priority, defect clear priority must use even number
*/
#define CTC_ETH_OAM_DEFECT_PRIORITY_PASSIVE_LOW_CCM          1
#define CTC_ETH_OAM_DEFECT_PRIORITY_SRC_MAC_MISMATCH         2
#define CTC_ETH_OAM_DEFECT_PRIORITY_RDI                      11
#define CTC_ETH_OAM_DEFECT_PRIORITY_RDI_CLEAR                12
#define CTC_ETH_OAM_DEFECT_PRIORITY_MAC_STATUS               13
#define CTC_ETH_OAM_DEFECT_PRIORITY_INTERVEAL_MISMATCH       17
#define CTC_ETH_OAM_DEFECT_PRIORITY_INTERVEAL_MISMATCH_CLEAR 18
#define CTC_ETH_OAM_DEFECT_PRIORITY_RMEP_NOT_FOUND           19
#define CTC_ETH_OAM_DEFECT_PRIORITY_RMEP_NOT_FOUND_CLEAR     20
#define CTC_ETH_OAM_DEFECT_PRIORITY_LOW_CCM                  21
#define CTC_ETH_OAM_DEFECT_PRIORITY_LOW_CCM_CLEAR            22
#define CTC_ETH_OAM_DEFECT_PRIORITY_MAID_MISMATCH            23
#define CTC_ETH_OAM_DEFECT_PRIORITY_MAID_MISMATCH_CLEAR      24
#define CTC_ETH_OAM_DEFECT_PRIORITY_D_LOC                    61
#define CTC_ETH_OAM_DEFECT_PRIORITY_D_LOC_CLEAR              62
#define CTC_OAM_DEFECT_PRIORITY_SYS_RSV                      63

/**
 @brief Define OAM defect type for RDI & CPU
*/
enum ctc_oam_defect_s
{
    CTC_ETH_OAM_RDI_DEFECT_USER                 = 0x01,  /**< [HB] User defined defects */
    CTC_ETH_OAM_RDI_DEFECT_SOME_RDI             = 0x02,  /**< [HB] Some RDI defects */
    CTC_ETH_OAM_RDI_DEFECT_SOME_MAC_STATUS      = 0x04,  /**< [HB] Some mac status defect */
    CTC_ETH_OAM_RDI_DEFECT_SOME_RMEP_CCM        = 0x08,  /**< [HB] Some Rmep ccm defect */
    CTC_ETH_OAM_RDI_DEFECT_ERROR_CCM            = 0x10,  /**< [HB] Error ccm defect */
    CTC_ETH_OAM_RDI_DEFECT_XCON_CCM             = 0x20,  /**< [HB] Cross connect ccm defect */

    /*Y.1731*/
    CTC_OAM_DEFECT_NONE                         = 0x00000, /**< [GB.GG] None */
    CTC_OAM_DEFECT_MAC_STATUS_CHANGE            = 0x00001, /**< [GB.GG] Some mac status defect */
    CTC_OAM_DEFECT_SRC_MAC_MISMATCH             = 0x00002, /**< [GB.GG] Remote mep mac not match defect */
    CTC_OAM_DEFECT_MISMERGE                     = 0x00004, /**< [GB.GG] Mismerge ccm defect */
    CTC_OAM_DEFECT_UNEXPECTED_LEVEL             = 0x00008, /**< [GB.GG] Level cross connect ccm defect */
    CTC_OAM_DEFECT_UNEXPECTED_MEP               = 0x00010, /**< [GB.GG] Unexpected MEP defect */
    CTC_OAM_DEFECT_UNEXPECTED_PERIOD            = 0x00020, /**< [GB.GG] Unexpected period defect */
    CTC_OAM_DEFECT_DLOC                         = 0x00040, /**< [GB.GG] LOC defect */
    CTC_OAM_DEFECT_CSF                          = 0x00080, /**< [GB.GG] CSF defect */

    CTC_OAM_DEFECT_EVENT_RX_FIRST_PKT           = 0x00100, /**< [GB.GG] Rx first CCM Packet defect, no trigger rdi */
    CTC_OAM_DEFECT_EVENT_RDI_RX                 = 0x00200, /**< [GB.GG] CSF defect, no trigger rdi */
    CTC_OAM_DEFECT_EVENT_RDI_TX                 = 0x00400, /**< [GB.GG] CSF defect, no trigger rdi */
    /*BFD*/
    CTC_OAM_DEFECT_EVENT_BFD_DOWN               = 0x00800, /**< [GB.GG] BFD down defect, no trigger rdi */
    CTC_OAM_DEFECT_EVENT_BFD_INIT               = 0x01000, /**< [GB.GG] BFD init defect, no trigger rdi */
    CTC_OAM_DEFECT_EVENT_BFD_UP                 = 0x02000, /**< [GB.GG] BFD up defect, no trigger rdi */
    CTC_OAM_DEFECT_EVENT_BFD_MIS_CONNECT        = 0x04000, /**< [GB.GG] BFD up defect, no trigger rdi */
    CTC_OAM_DEFECT_ALL                          = 0x07FFF  /**< [GB.GG] All */
};
typedef enum ctc_oam_defect_s ctc_oam_defect_t;

/**
 @brief  Define OAM maid length mode
*/
enum ctc_oam_maid_len_format_s
{
    CTC_OAM_MAID_LEN_16BYTES = 1,   /**< [HB.GB.GG] Length of MAID is 16 Bytes */
    CTC_OAM_MAID_LEN_32BYTES,       /**< [HB.GB.GG] Length of MAID is 32 Bytes */
    CTC_OAM_MAID_LEN_48BYTES        /**< [HB.GB.GG] Length of MAID is 48 Bytes */
};
typedef enum ctc_oam_maid_len_format_s ctc_oam_maid_len_format_t;

/**********************************************************************************************
------------------------- Ether OAM (support IEEE 802.1ag & Y.1731 OAM)-----------------------
**********************************************************************************************/
/**
 @defgroup eth_oam ETH_OAM
 @{
*/

/**
 @brief  Define Ethernet OAM key
*/
struct ctc_oam_eth_key_s
{
    uint16    vlan_id;          /**< [HB.GB.GG] Ethernet OAM channel associated Vlan ID, the vlan_id may be greater than 4095, please refer ctc_vlanptr_mode_t */
    uint16    ccm_vlan_id;      /**< [HB] Ethernet OAM channel associated ccm Vlan ID, this is packet vlan, so the vlan_id must below 4096*/
    uint8     ccm_vlan_id_valid; /**< [HB] Indecate ccm vlan id is valid, or will use vlan_id for ccm_vlan_id */
    uint8     md_level;         /**< [HB.GB.GG] Ethernet OAM MD level */
    uint32 gport;            /**< [HB.GB.GG] Ethernet OAM channel associated global port id,if MEP configured on linkagg,the gport should global linkagg ID */

    uint16 l2vpn_oam_id;    /**< [GG] VPWS OAM id or VPLS fid, used in Port + Oam ID mode, refer to CTC_OAM_Y1731_CFG_TYPE_L2VPN_OAM_MODE */
    uint8  rsv0[2];
};
typedef struct ctc_oam_eth_key_s ctc_oam_eth_key_t;

/**
 @brief  Define  Ethernet OAM channel
*/
struct ctc_oam_eth_chan_s
{
    uint8  master_gchip;                /**< [HB] Configured linkagg MEP's master gchip ID,the detail refers to userguide */
    uint8  rsv0[3];
};
typedef struct ctc_oam_eth_chan_s ctc_oam_eth_chan_t;

/**@}end of @defgroup  eth_oam ETH_OAM */

/**********************************************************************************************
----------------------------- MPLS-TP Y.1731 OAM ---------------------------
**********************************************************************************************/
/**
 @defgroup mpls_tp_Y.1731_oam MPLS_TP_Y.1731_OAM
 @{
*/
/**
 @brief  Define MPLS-TP Y.1731 & BFD OAM key
*/
struct ctc_oam_tp_key_s
{
    uint32  label;              /**< [GB.GG] MPLS-TP OAM associated in Label */
    uint32 gport_or_l3if_id;    /**< [GB.GG] MPLS-TP Section lookup key, port based should be gport, interface based should be interfce id */
    uint8  resv1[3];
    uint8  mpls_spaceid;        /**< [GB.GG] MPLS Label space ID */
};
typedef struct ctc_oam_tp_key_s ctc_oam_tp_key_t;

/**@}end of @defgroup  mpls_tp_Y.1731_oam MPLS_TP_Y.1731_OAM */

/**
 @brief  Define IP/MPLS BFD OAM key
*/
struct ctc_oam_bfd_key_s
{
    uint32  discr;              /**< [GB.GG] IP/MPLS BFD OAM lookup key, discriminator */
};
typedef struct ctc_oam_bfd_key_s ctc_oam_bfd_key_t;

/*
 @brief   Define oam global data structure
*/
struct ctc_oam_global_s
{
    uint8      is_p2p_mode;                     /**< [HB] Global flag, assign to ctc_oam_eth_global_flag_t */
    uint8      maid_len_format;                 /**< [HB.GB.GG] MAID length format, assign to ctc_oam_maid_len_format_t */
    uint16     tp_y1731_ach_chan_type;          /**< [GB.GG] TP Y.1731 ACH channel type, default to 0x8902*/

    uint16     tp_csf_ach_chan_type;      /**< [GB.GG] Config ACH channel type for CSF */
    uint8      tp_csf_fdi;                              /**< [GB.GG] Config FDI field of CSF */
    uint8      tp_csf_rdi;                              /**< [GB.GG] Config RDI field of CSF */

    uint8      tp_csf_los;                              /**< [GB.GG] Config LOS field of CSF */
    uint8      tp_csf_clear;                          /**< [GB.GG] Config CLEAR field of CSF */
    uint8      mep_index_alloc_by_sdk;          /**< [GB.GG] Indicate OAM module MEP resource allocate by SDK or system.*/
    uint8      tp_section_oam_based_l3if;       /**< [GB.GG] TP section OAM based l3 interface ID, default to 0 means use port */

    uint8      tp_bfd_333ms;                    /**< [GB.GG] TP BFD OAM use use Y.1731 interval mode, default to 0 means 1ms interval mode */
    uint16     mep_1ms_num;                     /**< [GB] OAM session range for 1ms interval OAM, such as IP BFD, MPLS BFD, mep means session */
    uint8      mpls_pw_vccv_with_ip_en;         /**< [GB] If set, will support MPLS PW VCCV with IP BFD */
};
typedef struct ctc_oam_global_s ctc_oam_global_t;

enum ctc_oam_com_property_cfg_type_e
{
    CTC_OAM_COM_PRO_TYPE_DEFECT_TO_CPU,         /**< [GB.GG] Indicated to set defect to error cache condition, use ctc_oam_defect_t */
    CTC_OAM_COM_PRO_TYPE_DEFECT_TO_RDI,         /**< [HB.GB.GG] Indicated to set defect to RDI condition, use ctc_oam_defect_t */
    CTC_OAM_COM_PRO_TYPE_EXCEPTION_TO_CPU,      /**< [HB.GB.GG] Indicated to set OAM exception to CPU condition, ctc_oam_exceptions_t */
    CTC_OAM_COM_PRO_TYPE_TRIG_APS_MSG,          /**< [HB.GB] Indicated to set APS message trigg condition, ctc_oam_trig_aps_msg_flag_t */
    CTC_OAM_COM_PRO_TYPE_REDIRECT_OAM,          /**< [GB.GG] Indicated to set OAM not process by OAM Engine, ctc_oam_rederect_oam_type_flag_t */
};
typedef enum ctc_oam_com_property_cfg_type_e ctc_oam_com_property_cfg_type_t;

/*
 @brief   Define oam com property data structure
*/
struct ctc_oam_com_property_s
{
    uint32           cfg_type;          /**< [HB.GB.GG] Global com property ,ctc_oam_com_property_cfg_type_t */
    uint32           value;             /**< [HB.GB.GG] According cfg type to use */
};
typedef struct ctc_oam_com_property_s ctc_oam_com_property_t;

/*
 @brief   Define oam property data structure
*/
struct ctc_oam_property_s
{
    uint8 oam_pro_type;                         /**< [HB.GB.GG] OAM property type, ctc_oam_property_type_t */
    union
    {
        ctc_oam_com_property_t  common;         /**< [HB.GB.GG] Common oam property */
        ctc_oam_y1731_prop_t    y1731;          /**< [HB.GB.GG] Ether oam & MPLS-TP Y.1731 property */
        ctc_oam_bfd_prop_t      bfd;            /**< [GB.GG] IP/MPLS/MPLS-TP BFD property */
    } u;
};
typedef struct ctc_oam_property_s ctc_oam_property_t;

/*
 @brief   Define oam key flags
*/
enum ctc_oam_key_flag_e
{
    CTC_OAM_KEY_FLAG_LINK_SECTION_OAM   = 1U << 0,   /**< [HB.GB.GG] Indicate key for eth link or MPLS-TP Section OAM */
    CTC_OAM_KEY_FLAG_VPLS               = 1U << 1,   /**< [HB.GB.GG] When CTC_OAM_KEY_FLAG_L2VPN is set, this flag indicates
                                               VPLS or VPWS up MEP. VPLS if set, otherwise VPWS */
    CTC_OAM_KEY_FLAG_UP_MEP             = 1U << 2,   /**< [HB.GB.GG] Indicate key for up MEP */
    CTC_OAM_KEY_FLAG_L2VPN              = 1U << 3,   /**< [GG] Indicate key for L2VPN up MEP */

    CTC_OAM_KEY_FLAG_MAX
};
typedef enum ctc_oam_key_flag_e ctc_oam_key_flag_t;

/*
 @brief   Define oam key data structure
*/
struct ctc_oam_key_s
{
    ctc_oam_mep_type_t mep_type;  /**< [HB.GB.GG] Mep type, assign to ctc_oam_mep_type_t */
    uint32             flag;      /**< [HB.GB.GG] OAM key flag, assign to ctc_oam_key_flag_t */
    union
    {
        ctc_oam_eth_key_t eth;    /**< [HB.GB.GG] Ether OAM key */
        ctc_oam_tp_key_t  tp;     /**< [GB.GG] MPLS-TP Y.1731 & BFD OAM key */
        ctc_oam_bfd_key_t bfd;    /**< [GB.GG] MPLS/IP BFD OAM key */
    } u;
};
typedef struct ctc_oam_key_s ctc_oam_key_t;

/*
 @brief   Define oam maid data structure
*/
struct ctc_oam_maid_s
{
    ctc_oam_mep_type_t  mep_type;                       /**< [HB.GB.GG] Mep type, ctc_oam_mep_type_t */

    uint8               maid[CTC_OAM_MAX_MAID_LEN];     /**< [HB.GB.GG] MAID or MEGID  vlaue */
    uint8               maid_len;                       /**< [HB.GB.GG] MAID or MEGID  length */
    uint8               rsv0[3];
};
typedef struct ctc_oam_maid_s ctc_oam_maid_t;

/*
 @brief   Define oam chan data structure
*/
struct ctc_oam_chan_s
{
    ctc_oam_key_t      key;          /**< [HB] OAM lookup key */
    union
    {
        ctc_oam_eth_chan_t eth_chan; /**< [HB] Ether OAM chan */
    } u;
};
typedef struct ctc_oam_chan_s ctc_oam_chan_t;

/*
 @brief   Define oam local mep data structure
*/
struct ctc_oam_lmep_s
{
    ctc_oam_key_t  key;                         /**< [HB.GB.GG] OAM lookup key */
    ctc_oam_maid_t maid;                        /**< [HB.GB.GG] OAM maid */
    uint32  endpoint_id;                        /**< [GB.GG] OAM endpoint identifier */
    union
    {
        ctc_oam_y1731_lmep_t     y1731_lmep;    /**< [HB.GB.GG] Ether OAM & TP Y.1731 local mep */
        ctc_oam_bfd_lmep_t       bfd_lmep;      /**< [GB.GG] BFD OAM local mep */
    } u;
    uint32 lmep_index;                          /**< [GB.GG] Local mep index alocation by system */
};
typedef struct ctc_oam_lmep_s ctc_oam_lmep_t;

/*
 @brief   Define oam remote mep data structure
*/
struct ctc_oam_rmep_s
{
    ctc_oam_key_t key;                              /**< [HB.GB.GG] OAM lookup key */
    uint32  endpoint_id;                            /**< [GB.GG] OAM endpoint identifier */
    union
    {
        ctc_oam_y1731_rmep_t      y1731_rmep;       /**< [HB.GB.GG] Ether OAM & MPLS-TP Y.1731 remote mep */
        ctc_oam_bfd_rmep_t        bfd_rmep;         /**< [GB.GG] BFD OAM remote mep */
    } u;
    uint32 rmep_index;                              /**< [GB.GG] Remote mep index alocation by system */
};
typedef struct ctc_oam_rmep_s ctc_oam_rmep_t;

/*
 @brief   Define oam mip data structure
*/
struct ctc_oam_mip_s
{
    ctc_oam_key_t key;                  /**< [GB.GG] OAM lookup key */
    uint8  master_gchip;                /**< [GB.GG] Configured linkagg MEP's master gchip ID,the detail refers to userguide */
};
typedef struct ctc_oam_mip_s ctc_oam_mip_t;

struct ctc_oam_update_s
{
    ctc_oam_key_t key;                  /**< [HB.GB.GG] OAM lookup key */
    uint32  update_type;                /**< [HB.GB.GG] According mep type to update ctc_oam_y1731_lmep_update_type_t,
                                                                            ctc_oam_y1731_rmep_update_type_t,
                                                                            ctc_oam_bfd_lmep_update_type_t,
                                                                            ctc_oam_bfd_rmep_update_type_t */
    uint32  update_value;               /**< [HB.GB.GG] Update value */
    uint8   is_local;                   /**< [HB.GB.GG] Indicate update local or remote mep */
    uint8   resv0;
    uint16  rmep_id;                    /**< [HB.GB.GG] Remote mep mep id, for update remote  mep only */
    void*   p_update_value;             /**< [GB.GG] Update values */
};
typedef struct ctc_oam_update_s ctc_oam_update_t;

/*
 @brief   Define Local MEP data structure get from both SDK database and ASIC dataset
*/
union ctc_oam_lmep_info_u
{
    ctc_oam_y1731_lmep_info_t       y1731_lmep;     /**< [HB.GB.GG] Local Eth MEP & MPLS-TP Y.1731 MEP from database */
    ctc_oam_bfd_lmep_info_t         bfd_lmep;       /**< [GB.GG] Local BFD MEP from database */
};
typedef union ctc_oam_lmep_info_u ctc_oam_lmep_info_t;

/*
 @brief   Define Remote MEP data structure get from both SDK database and ASIC dataset
*/
union ctc_oam_rmep_info_u
{
    ctc_oam_y1731_rmep_info_t       y1731_rmep;     /**< [HB.GB.GG] Remote ether MEP & MPLS-TP Y.1731 MEP from database */
    ctc_oam_bfd_rmep_info_t         bfd_rmep;       /**< [GB.GG] Remote BFD MEP from database */
};
typedef union ctc_oam_rmep_info_u ctc_oam_rmep_info_t;

/*
 @brief   Define MEP data structure get from both SDK database and ASIC dataset
*/
struct ctc_oam_mep_info_s
{
    uint16    mep_index;                /**< [HB.GB.GG] The index of MEP,      input parameter */
    uint8     is_rmep;                  /**< [HB.GB.GG] Indicate index of MEP is Remote MEP */
    uint8     resv[1];
    ctc_oam_mep_type_t   mep_type;      /**< [HB.GB.GG] Mep type, ctc_oam_mep_type_t */
    ctc_oam_lmep_info_t  lmep;          /**< [HB.GB.GG] Local MEP from database, valid if is_rmep is FALSE */
    ctc_oam_rmep_info_t  rmep;          /**< [HB.GB.GG] Remote MEP from database, valid if is_rmep is TRUE */
};
typedef struct ctc_oam_mep_info_s ctc_oam_mep_info_t;


/*
 @brief   Define MEP data structure get from both SDK database and ASIC dataset
*/
struct ctc_oam_mep_info_with_key_s
{
    ctc_oam_key_t  key;             /**< [GB.GG] OAM lookup key information */
    uint16 rmep_id;                     /**< [GB.GG] OAM remote mep id */
    ctc_oam_lmep_info_t  lmep;          /**< [HB.GB.GG] Local MEP from database, valid if is_rmep is FALSE */
    ctc_oam_rmep_info_t  rmep;          /**< [HB.GB.GG] Remote MEP from database, valid if is_rmep is TRUE */
};
typedef struct ctc_oam_mep_info_with_key_s ctc_oam_mep_info_with_key_t;

/*
 @brief   Define ccm lm counter structure
*/
struct ctc_oam_lm_info_s
{
    uint32 tx_fcf;          /**< [GB.GG] Value of the local counter TxFCl at the time of transmission of the CCM frame */
    uint32 rx_fcb;          /**< [GB.GG] Value of the local counter RxFCl at the time of reception of the last CCM
                                  frame from the peer MEP */
    uint32 tx_fcb;          /**< [GB.GG] Value of TxFCf in the last received CCM frame from the peer MEP */
    uint32 rx_fcl;          /**< [GB.GG] Value of local counter RxFCl at time this CCM frame was received */
};
typedef struct ctc_oam_lm_info_s ctc_oam_lm_info_t;

/*
 @brief   Define Autogen stats structure
*/
struct ctc_oam_trpt_stats_s
{
    uint64 tx_pkt;         /**< [GB.GG] Throughput packet cnt stats in Tx Dir */
    uint64 tx_oct;         /**< [GB.GG] Throughput packet octets stats in Tx Dir */
    uint64 rx_pkt;         /**< [GB.GG] Throughput packet cnt stats in Rx Dir */
    uint64 rx_oct;         /**< [GB.GG] Throughput packet octets stats in Rx Dir */
    uint64 tx_fcf;         /**< [GG] Tx fcf in SLM */
    uint64 tx_fcb;         /**< [GG] Tx fcb in SLM */
    uint64 rx_fcl;         /**< [GG] Rx fcl in SLM */
};
typedef struct ctc_oam_trpt_stats_s ctc_oam_trpt_stats_t;

/*
 @brief   Define MEP stats structure get from ASIC dataset
*/
struct ctc_oam_stats_info_s
{
    ctc_oam_key_t  key;                                     /**< [GB.GG] OAM lookup key */
    ctc_oam_lm_info_t lm_info[CTC_OAM_STATS_COS_NUM];       /**< [GB.GG] LM counter in ccm */
    uint8 lm_type;                                          /**< [GB.GG] MEP LM type, refer to ctc_oam_lm_type_t */
    uint8 lm_cos_type;                                      /**< [GB.GG] MEP LM cos type, refer to ctc_oam_lm_cos_type_t */
    uint8 resv[2];
};
typedef struct ctc_oam_stats_info_s ctc_oam_stats_info_t;

/*
 @brief   Define OAM defect information entry
*/
struct ctc_oam_event_entry_s
{
    ctc_oam_mep_type_t mep_type;            /**< [GB.GG] Mep type , refer to ctc_oam_mep_type_t */
    uint32  local_endpoint_id;              /**< [GB.GG] OAM local endpoint identifier */
    uint32  remote_endpoint_id;             /**< [GB.GG] OAM remote endpoint identifier */
    uint8   maid[CTC_OAM_MAX_MAID_LEN];     /**< [GB.GG] MAID or MEGID  vlaue */
    uint16  lmep_id;                        /**< [GB.GG] Local MEP ID */
    uint16  rmep_id;                        /**< [GB.GG] Remote MEP ID, valid only is_remote set */
    ctc_oam_key_t  oam_key;                 /**< [GB.GG] OAM lookup key information */

    uint16  lmep_index;                     /**< [GB.GG] Local MEP Index */
    uint16  rmep_index;                     /**< [GB.GG] Remote MEP Index, valid only is_remote set */
    uint8   is_remote;                      /**< [GB.GG] Indicated event is triggered by local or remote MEP */
    uint8   resv[3];
    uint32  event_bmp;                      /**< [GB.GG] Event bitmap ,refer to ctc_oam_defect_t */
};
typedef struct ctc_oam_event_entry_s ctc_oam_event_entry_t;

/*
 @brief   Define OAM defect event information for interrput call back function
*/
struct ctc_oam_event_s
{
    uint8  valid_entry_num;                                             /**< [GB.GG] Indicated valid event entry num */
    uint8  resv0[3];
    ctc_oam_event_entry_t oam_event_entry[CTC_OAM_EVENT_MAX_ENTRY_NUM]; /**< [GB.GG] Event entry ,refer to ctc_oam_event_entry_t */
};
typedef struct ctc_oam_event_s ctc_oam_event_t;

/*
 @brief   Define OAM throughput pattern type
*/
enum ctc_oam_trpt_pattern_type_e
{
    CTC_OAM_PATTERN_REPEAT_TYPE,       /**< [GB.GG] Repeat mode */
    CTC_OAM_PATTERN_RANDOM_TYPE,       /**< [GB.GG] Random mode */
    CTC_OAM_PATTERN_INC_BYTE_TYPE,     /**< [GB.GG] Increase by byte mode */
    CTC_OAM_PATTERN_DEC_BYTE_TYPE,     /**< [GB.GG] Decrease by byte mode */
    CTC_OAM_PATTERN_INC_WORD_TYPE,     /**< [GB.GG] Increase by word mode */
    CTC_OAM_PATTERN_DEC_WORD_TYPE,     /**< [GB.GG] Decrease by word mode */

    CTC_OAM_PATTERN_MAX_TYPE
};
typedef enum ctc_oam_trpt_pattern_type_e ctc_oam_trpt_pattern_type_t;

/*
 @brief   Define OAM throughput tx mode type
*/
enum ctc_oam_trpt_tx_type_e
{
    CTC_OAM_TX_TYPE_PACKET = 0,      /**< [GB.GG] Stop packets transmission after the number of packet transmission */
    CTC_OAM_TX_TYPE_CONTINUOUS,          /**< [GB.GG] Transmit continuously */
    CTC_OAM_TX_TYPE_PERIOD,     /**< [GG] Stop packets transmission after a period of packet transmission */

    CTC_OAM_TX_TYPE_MAX
};
typedef enum ctc_oam_trpt_tx_type_e ctc_oam_trpt_tx_type_t;

/*
 @brief   Define OAM throughput config structure
*/
struct ctc_oam_trpt_s
{
    uint8 session_id;             /**< [GB.GG] Throughput session id 0~3 */
    uint8  tx_mode;               /**< [GB.GG] Tx mode, refer to ctc_oam_trpt_tx_type_t */
    uint8 resv[2];

    uint16 vlan_id;            /**< [GB.GG] Vlan id */
    uint32 gport;                 /**< [GB.GG] Throughput test port */

    ctc_oam_trpt_pattern_type_t pattern_type;    /**< [GB.GG] Pattern type */
    uint32 repeat_pattern;         /**< [GB.GG] Repeat pattern used for CTC_PATTERN_REPEAT_TYPE */
    uint32 rate;                   /**< [GB.GG] Line speed(Kbps) */

    void*   pkt_header;            /**< [GB.GG] User-defined data */

    uint16  size;                  /**< [GB.GG] Total packet size, include header_len and crc, must >= 64 && >= header_len + 4 bytes */
    uint16  header_len;            /**< [GB.GG] User-defined data length, not include crc */

    uint32  tx_period;                /**< [GG] Used for send pkts when in tx CTC_OAM_TX_TYPE_PERIOD mode, unit: 1s */

    uint8 tx_seq_en;               /**< [GB.GG] Enable insert sequen number */
    uint8 seq_num_offset;          /**< [GB.GG] Insert sequen number offset in user-defined packet
                             when send SLM packet, the offset is the TxFcf offset in SLM packet, and tx_seq_en must be set to 1*/
    uint32  packet_num;             /**< [GB.GG] Used for send pkts when in tx CTC_OAM_TX_TYPE_PACKET mode */
    ctc_direction_t direction;      /**< [GB.GG] direction of trpt, ingress or egress */
    /*SLM/SLR*/
    uint8 is_slm;                             /**< [GG] 1: send SLM packet */
    uint8 first_pkt_clear_en;  /**< [GG] SLM stats value will be cleared when tx/rx the first packet */
};
typedef struct ctc_oam_trpt_s ctc_oam_trpt_t;


/**@} end of @defgroup  oam OAM */

#ifdef __cplusplus
}
#endif

#endif

