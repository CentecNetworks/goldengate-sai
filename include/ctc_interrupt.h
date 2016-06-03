/**
 @file ctc_interrupt.h

 @author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2010-1-20

 @version v2.0

   This file contains all isr related data structure, enum, macro and proto.
*/

#ifndef _CTC_INTERRUPT_H
#define _CTC_INTERRUPT_H
#ifdef __cplusplus
extern "C" {
#endif
/****************************************************************
 *
 * Header Files
 *
 ***************************************************************/
#include "ctc_mix.h"

/****************************************************************
*
* Defines and Macros
*
****************************************************************/

/**
 @defgroup isr ISR
 @{
*/

#define CTC_INTERRUPT_PARITY_ERROR_MAX_ENTRY_WORD     8

/**
 @brief [HB] Define interrupt type
*/
enum ctc_interrupt_intr_type_e
{
    CTC_INTERRUPT_NORMAL_INTR = 0,   /**< [HB]normal interrupt */
    CTC_INTERRUPT_FATAL_INTR            /**< [HB]fatal interrupt */
};
typedef enum ctc_interrupt_intr_type_e ctc_interrupt_intr_type_t;

/**
 @brief [HB] Define normal interrupt type
*/
enum ctc_interrupt_normal_intr_type_e
{
    CTC_INTERRUPT_NORMAL_OAM_INTR = 12,               /**< [HB]normal OAM interrupt */
    CTC_INTERRUPT_NORMAL_STATISTICS_INTR = 14,        /**<[HB] normal statistics interrupt */
    CTC_INTERRUPT_NORMAL_LEARNING_INTR = 15,          /**<[HB] normal learning interrupt */
    CTC_INTERRUPT_NORMAL_AGING_INTR = 16,             /**<[HB] normal aging interrupt */
    CTC_INTERRUPT_NORMAL_PTP_INTR = 17,               /**<[HB] normal PTP interrupt */

    CTC_INTERRUPT_NORMAL_INTR_TYPE_MAX
};
typedef enum ctc_interrupt_normal_intr_type_e ctc_interrupt_normal_intr_type_t;

/**
 @brief [HB] Define fatal interrupt type
*/
enum ctc_interrupt_fatal_intr_type_e
{
    CTC_INTERRUPT_FATAL0_INTR = 0,

    CTC_INTERRUPT_FATAL0_MAC_MUX_INTR = 0,
    CTC_INTERRUPT_FATAL0_CPU_MAC_INTR,
    CTC_INTERRUPT_FATAL0_NET_TX_INTR,
    CTC_INTERRUPT_FATAL0_NET_RX_INTR,
    CTC_INTERRUPT_FATAL0_QUAD_MAC_APP0_INTR,
    CTC_INTERRUPT_FATAL0_QUAD_MAC_APP1_INTR,
    CTC_INTERRUPT_FATAL0_QUAD_MAC_APP2_INTR,
    CTC_INTERRUPT_FATAL0_QUAD_MAC_APP3_INTR,
    CTC_INTERRUPT_FATAL0_QUAD_MAC_APP4_INTR,
    CTC_INTERRUPT_FATAL0_QUAD_MAC_APP5_INTR,
    CTC_INTERRUPT_FATAL0_QUAD_MAC_APP6_INTR,
    CTC_INTERRUPT_FATAL0_QUAD_MAC_APP7_INTR,
    CTC_INTERRUPT_FATAL0_QUAD_MAC_APP8_INTR,
    CTC_INTERRUPT_FATAL0_QUAD_MAC_APP9_INTR,
    CTC_INTERRUPT_FATAL0_QUAD_MAC_APP10_INTR,
    CTC_INTERRUPT_FATAL0_QUAD_MAC_APP11_INTR,
    CTC_INTERRUPT_FATAL0_GMAC0_INTR,
    CTC_INTERRUPT_FATAL0_GMAC1_INTR,
    CTC_INTERRUPT_FATAL0_GMAC2_INTR,
    CTC_INTERRUPT_FATAL0_GMAC3_INTR,
    CTC_INTERRUPT_FATAL0_GMAC4_INTR,
    CTC_INTERRUPT_FATAL0_GMAC5_INTR,
    CTC_INTERRUPT_FATAL0_GMAC6_INTR,
    CTC_INTERRUPT_FATAL0_GMAC7_INTR,
    CTC_INTERRUPT_FATAL0_GMAC8_INTR,
    CTC_INTERRUPT_FATAL0_GMAC9_INTR,
    CTC_INTERRUPT_FATAL0_GMAC10_INTR,
    CTC_INTERRUPT_FATAL0_GMAC11_INTR,
    CTC_INTERRUPT_FATAL0_GMAC12_INTR,
    CTC_INTERRUPT_FATAL0_GMAC13_INTR,
    CTC_INTERRUPT_FATAL0_GMAC14_INTR,
    CTC_INTERRUPT_FATAL0_GMAC15_INTR,

    CTC_INTERRUPT_FATAL1_INTR = 32,

    CTC_INTERRUPT_FATAL1_GMAC16_INTR = 32,
    CTC_INTERRUPT_FATAL1_GMAC17_INTR,
    CTC_INTERRUPT_FATAL1_GMAC18_INTR,
    CTC_INTERRUPT_FATAL1_GMAC19_INTR,
    CTC_INTERRUPT_FATAL1_GMAC20_INTR,
    CTC_INTERRUPT_FATAL1_GMAC21_INTR,
    CTC_INTERRUPT_FATAL1_GMAC22_INTR,
    CTC_INTERRUPT_FATAL1_GMAC23_INTR,
    CTC_INTERRUPT_FATAL1_GMAC24_INTR,
    CTC_INTERRUPT_FATAL1_GMAC25_INTR,
    CTC_INTERRUPT_FATAL1_GMAC26_INTR,
    CTC_INTERRUPT_FATAL1_GMAC27_INTR,
    CTC_INTERRUPT_FATAL1_GMAC28_INTR,
    CTC_INTERRUPT_FATAL1_GMAC29_INTR,
    CTC_INTERRUPT_FATAL1_GMAC30_INTR,
    CTC_INTERRUPT_FATAL1_GMAC31_INTR,
    CTC_INTERRUPT_FATAL1_GMAC32_INTR,
    CTC_INTERRUPT_FATAL1_GMAC33_INTR,
    CTC_INTERRUPT_FATAL1_GMAC34_INTR,
    CTC_INTERRUPT_FATAL1_GMAC35_INTR,
    CTC_INTERRUPT_FATAL1_GMAC36_INTR,
    CTC_INTERRUPT_FATAL1_GMAC37_INTR,
    CTC_INTERRUPT_FATAL1_GMAC38_INTR,
    CTC_INTERRUPT_FATAL1_GMAC39_INTR,
    CTC_INTERRUPT_FATAL1_GMAC40_INTR,
    CTC_INTERRUPT_FATAL1_GMAC41_INTR,
    CTC_INTERRUPT_FATAL1_GMAC42_INTR,
    CTC_INTERRUPT_FATAL1_GMAC43_INTR,
    CTC_INTERRUPT_FATAL1_GMAC44_INTR,
    CTC_INTERRUPT_FATAL1_GMAC45_INTR,
    CTC_INTERRUPT_FATAL1_GMAC46_INTR,
    CTC_INTERRUPT_FATAL1_GMAC47_INTR,

    CTC_INTERRUPT_FATAL2_INTR = 64,

    CTC_INTERRUPT_FATAL2_EPE_STATS_INTR = 64,
    CTC_INTERRUPT_FATAL2_EPE_HDR_EDIT_INTR,
    CTC_INTERRUPT_FATAL2_EPE_CLASSIFICATION_INTR,
    CTC_INTERRUPT_FATAL2_EPE_ACLQOS_INTR,
    CTC_INTERRUPT_FATAL2_EPE_HDR_PROC_INTR,
    CTC_INTERRUPT_FATAL2_EPE_NEXTHOP_INTR,
    CTC_INTERRUPT_FATAL2_EPE_HDR_ADJ_INTR,
    CTC_INTERRUPT_FATAL2_EPE_PARSER_INTR,
    CTC_INTERRUPT_FATAL2_IPE_AGING_INTR,
    CTC_INTERRUPT_FATAL2_IPE_STATS_INTR,
    CTC_INTERRUPT_FATAL2_IPE_FWD_INTR,
    CTC_INTERRUPT_FATAL2_IPE_PKT_PROC_INTR,
    CTC_INTERRUPT_FATAL2_IPE_LKP_MGR_INTR,
    CTC_INTERRUPT_FATAL2_IPE_INTF_MAPPER_INTR,
    CTC_INTERRUPT_FATAL2_IPE_HDR_ADJ_INTR,
    CTC_INTERRUPT_FATAL2_IPE_PARSER_INTR,
    CTC_INTERRUPT_FATAL2_FABRIC_VOQ_INTR,
    CTC_INTERRUPT_FATAL2_FABRIC_SER_INTR,
    CTC_INTERRUPT_FATAL2_FABRIC_RXQ_INTR,
    CTC_INTERRUPT_FATAL2_FABRIC_RTS_INTR,
    CTC_INTERRUPT_FATAL2_FABRIC_GTS_INTR,
    CTC_INTERRUPT_FATAL2_FABRIC_DSF_INTR,
    CTC_INTERRUPT_FATAL2_FABRIC_CRB_INTR,
    CTC_INTERRUPT_FATAL2_FABRIC_CAS_INTR,
    CTC_INTERRUPT_FATAL2_SGMAC0_INTR,
    CTC_INTERRUPT_FATAL2_SGMAC1_INTR,
    CTC_INTERRUPT_FATAL2_SGMAC2_INTR,
    CTC_INTERRUPT_FATAL2_SGMAC3_INTR,
    CTC_INTERRUPT_FATAL2_XGMAC0_INTR,
    CTC_INTERRUPT_FATAL2_XGMAC1_INTR,
    CTC_INTERRUPT_FATAL2_XGMAC2_INTR,
    CTC_INTERRUPT_FATAL2_XGMAC3_INTR,

    CTC_INTERRUPT_FATAL3_INTR = 96,

    CTC_INTERRUPT_FATAL3_DS_HASH_KEY_TBL_INTR = 96,
    CTC_INTERRUPT_FATAL3_HASH_CTL_INTR,
    CTC_INTERRUPT_FATAL3_TCAM_CTL_EXT_INTR,
    CTC_INTERRUPT_FATAL3_TCAM_CTL_INT_INTR,
    CTC_INTERRUPT_FATAL3_PB_CTL_INTR,
    CTC_INTERRUPT_FATAL3_QDR_ARB_INTR,
    CTC_INTERRUPT_FATAL3_TB_INFO_ARB_INTR,
    CTC_INTERRUPT_FATAL3_TCAM_ARB_INTR,
    CTC_INTERRUPT_FATAL3_SHARED_DS_INTR,
    CTC_INTERRUPT_FATAL3_STP_STATE_INTR,
    CTC_INTERRUPT_FATAL3_STATISTICS_INTR,
    CTC_INTERRUPT_FATAL3_POLICING_INTR,
    CTC_INTERRUPT_FATAL3_MET_FIFO_INTR,
    CTC_INTERRUPT_FATAL3_ELOOP_INTR,
    CTC_INTERRUPT_FATAL3_BUF_RETRV_INTR,
    CTC_INTERRUPT_FATAL3_BUF_STORE_INTR,
    CTC_INTERRUPT_FATAL3_QMGR_QUE_ENTRY_INTR,
    CTC_INTERRUPT_FATAL3_QMGR_SUB_CH_INTR,
    CTC_INTERRUPT_FATAL3_QMGR_SCH_INTR,
    CTC_INTERRUPT_FATAL3_QMGR_LINKLIST_INTR,
    CTC_INTERRUPT_FATAL3_QMGR_ENQ_INTR,
    CTC_INTERRUPT_FATAL3_OAM_PROC_INTR,
    CTC_INTERRUPT_FATAL3_OAM_LKP_INTR,
    CTC_INTERRUPT_FATAL3_OAM_FWD_INTR,
    CTC_INTERRUPT_FATAL3_OAM_PARSER_INTR,
    CTC_INTERRUPT_FATAL3_QDR_CTL_INTR,
    CTC_INTERRUPT_FATAL3_DDR_CTL_INTR,

    CTC_INTERRUPT_FATAL_INTR_TYPE_MAX
};
typedef enum ctc_interrupt_fatal_intr_type_e ctc_interrupt_fatal_intr_type_t;

/**
 @brief [HB.GB] Define fatal interrupt action
*/
enum ctc_interrupt_fatal_intr_action_e
{
    CTC_INTERRUPT_FATAL_INTR_NULL = 0,    /**< [HB.GB.GG] no any operation */
    CTC_INTERRUPT_FATAL_INTR_LOG,         /**< [HB.GB.GG] only for log */
    CTC_INTERRUPT_FATAL_INTR_RESET,       /**< [HB.GB.GG] need to reset chip */
    CTC_INTERRUPT_FATAL_INTR_RESET_MODULE /**< [HB] need to reset one module of chip */
};
typedef enum ctc_interrupt_fatal_intr_action_e ctc_interrupt_fatal_intr_action_t;

/**
 @brief [HB] Define fatal interrupt status
*/
struct ctc_interrupt_fatal_intr_status_s
{
    uint32  sub_fatal_intr0;
    uint32  sub_fatal_intr1;
    uint32  sub_fatal_intr2;
    uint32  sub_fatal_intr3;
    ctc_interrupt_fatal_intr_action_t   action;  /**<[HB] fatal interrupt action */
    uint8   is_parity_error_occur;                /**<[HB] parity error status flag */
    uint8   parity_error_sram_type;         /**<[HB] 1: 16K sram; 2: 48K sram; 3: 96K sram; 4: 256K ext sram */
    uint8   rsv[2];
    uint32  parity_error_static_tbl_id;   /**<[HB] table id for parity error static */
    uint32  parity_error_index;             /**<[HB] The index of the table or the sram */
    uint32  parity_error_asic_addr;
    uint32  parity_error_asic_data[CTC_INTERRUPT_PARITY_ERROR_MAX_ENTRY_WORD];
    uint32  parity_error_mapping_addr;
    uint32  parity_error_mapping_data[CTC_INTERRUPT_PARITY_ERROR_MAX_ENTRY_WORD];
};
typedef struct ctc_interrupt_fatal_intr_status_s ctc_interrupt_fatal_intr_status_t;

enum ctc_interrupt_ecc_type_e
{
   CTC_INTERRUPT_ECC_TYPE_SBE,           /**< [GB.GG] single bit error */
   CTC_INTERRUPT_ECC_TYPE_MBE,           /**< [GB.GG] muliple bit error*/
   CTC_INTERRUPT_ECC_TYPE_PARITY_ERROR,  /**< [GB.GG] parity error*/
   CTC_INTERRUPT_ECC_TYPE_TCAM_ERROR,    /**< [GB.GG] tcam error */
   CTC_INTERRUPT_ECC_TYPE_NUM
};
typedef enum ctc_interrupt_ecc_type_e ctc_interrupt_ecc_type_t;

/**
 @brief  Define ecc event info
*/
struct ctc_interrupt_ecc_s
{
   uint8  type;                 /**< [GB.GG] refer to ctc_interrupt_ecc_type_t */
   uint32 tbl_id;               /**< [GB.GG] table id */
   uint32 tbl_index;            /**< [GB.GG] table index */
   uint8  action;               /**< [GB.GG] refer to ctc_interrupt_fatal_intr_action_t */
   uint8  recover;              /**< [GB.GG] error recovered by ecc recover module */
};
typedef struct ctc_interrupt_ecc_s ctc_interrupt_ecc_t;

/**
 @brief Define interrupt related MACROs
*/
#define CTC_INTR_DESC_LEN       32              /**<[GB.GG] length of interrupt description string */
#define CTC_INTR_MAX_INTR       32              /**<[GB.GG] max number of sup-level interrupts */
#define CTC_INTR_STAT_SIZE      3               /**<[GB.GG] max number of DWORD/uint32 of interrupt status */
#define INVG                    ((uint32) - 1)    /**<[GB.GG] invalid group ID */
#define CTC_INTR_ALL            ((uint32) - 1)    /**<[GB.GG] all interrupt bits of sup-level/sub-level */
#define CTC_INTR_T2B(_type_)    (1 << (_type_))   /**<[GB.GG] convert interrupt type to bit */

/**
 @brief [GB] interrupt related MACRO
*/
#define CTC_INTR_GB_MAX_GROUP       6       /**< [GB.GG] max interrupt group(PIN) number */
#define CTC_INTR_GB_MAX_INTR        29      /**< [GB.GG] max sup-level interrupt number */

/**
 @brief sup-level interrupt type
*/
enum ctc_interrupt_type_e
{
    /* ASIC Internal Interrupt */
    CTC_INTR_CHIP_FATAL = 0,             /**< [GB.GG] sup fatal exception appear, sub-intr [0,47] */
    CTC_INTR_CHIP_NORMAL,                /**< [GB.GG] sup normal exception appear, sub-intr [0,85] */

    /* Functional Interrupts */
    CTC_INTR_FUNC_PTP_TS_CAPTURE,        /**< [GB.GG] PTP RX timestamp capture, when 1PPS or SyncPulse received */
    CTC_INTR_FUNC_PTP_MAC_TX_TS_CAPTURE, /**< [GB.GG] PTP TX timestamp capture, for 2-step */
    CTC_INTR_FUNC_PTP_TOD_PULSE_IN,      /**< [GB.GG] PTP 1PPS received */
    CTC_INTR_FUNC_PTP_TOD_CODE_IN_RDY,   /**< [GB.GG] PTP TOD input code is ready */
    CTC_INTR_FUNC_PTP_SYNC_PULSE_IN,     /**< [GB.GG] PTP SyncPulse received */
    CTC_INTR_FUNC_PTP_SYNC_CODE_IN_RDY,  /**< [GB.GG] PTP Sync Interface input code is ready */
    CTC_INTR_FUNC_OAM_TRPT_STATS,        /**< [GB]OAM throughput stats */
    CTC_INTR_FUNC_OAM_DEFECT_CACHE,      /**< [GB.GG] OAM defect cache to notify OAM status change */
    CTC_INTR_FUNC_MDIO_CHANGE,           /**< [GB.GG] MDIO detects any status changes including 1G and XG,
                                                                       [GB] Only for XG Phy*/
    CTC_INTR_FUNC_MDIO_1G_CHANGE,        /**< [GB]MDIO detects any status changes of 1G PHYs, only used for GB */
    CTC_INTR_FUNC_LINKAGG_FAILOVER,      /**< [GB.GG] Linkagg protect switch done */
    CTC_INTR_FUNC_IPE_LEARN_CACHE,       /**< [GB.GG] Learning cache to notify SW learning */
    CTC_INTR_FUNC_IPE_AGING_FIFO,        /**< [GB.GG] Aging FIFO to notify SW aging */
    CTC_INTR_FUNC_STATS_FIFO,            /**< [GB.GG] Statistics exceed the threshold */
    CTC_INTR_FUNC_APS_FAILOVER,          /**< [GB.GG] APS protect switch done */
    CTC_INTR_FUNC_LINK_CHAGNE,          /**< [GG] Pcs link status change */

    /* DMA Interrupt */
    CTC_INTR_DMA_FUNC,                   /**< [GB.GG] DMA channel need to handle, sub-intr [0,16] */
    CTC_INTR_DMA_NORMAL,                 /**< [GB]DMA channel exception appear, sub-intr [0,47] */
    CTC_INTR_MAX
};
typedef enum ctc_interrupt_type_e ctc_interrupt_type_t;


/**
 @brief [GB] the follwing macros are to compatible with GB
*/
#define   CTC_INTR_GB_CHIP_FATAL                 CTC_INTR_CHIP_FATAL
#define   CTC_INTR_GB_CHIP_NORMAL                CTC_INTR_CHIP_NORMAL
#define   CTC_INTR_GB_FUNC_PTP_TS_CAPTURE        CTC_INTR_FUNC_PTP_TS_CAPTURE
#define   CTC_INTR_GB_FUNC_PTP_MAC_TX_TS_CAPTURE CTC_INTR_FUNC_PTP_MAC_TX_TS_CAPTURE
#define   CTC_INTR_GB_FUNC_PTP_TOD_PULSE_IN      CTC_INTR_FUNC_PTP_TOD_PULSE_IN
#define   CTC_INTR_GB_FUNC_PTP_TOD_CODE_IN_RDY   CTC_INTR_FUNC_PTP_TOD_CODE_IN_RDY
#define   CTC_INTR_GB_FUNC_PTP_SYNC_PULSE_IN     CTC_INTR_FUNC_PTP_SYNC_PULSE_IN
#define   CTC_INTR_GB_FUNC_PTP_SYNC_CODE_IN_RDY  CTC_INTR_FUNC_PTP_SYNC_CODE_IN_RDY
#define   CTC_INTR_GB_FUNC_OAM_DEFECT_CACHE      CTC_INTR_FUNC_OAM_DEFECT_CACHE
#define   CTC_INTR_GB_FUNC_MDIO_CHANGE           CTC_INTR_FUNC_MDIO_CHANGE
#define   CTC_INTR_GB_FUNC_MDIO_1G_CHANGE        CTC_INTR_FUNC_MDIO_1G_CHANGE
#define   CTC_INTR_GB_FUNC_LINKAGG_FAILOVER      CTC_INTR_FUNC_LINKAGG_FAILOVER
#define   CTC_INTR_GB_FUNC_IPE_LEARN_CACHE       CTC_INTR_FUNC_IPE_LEARN_CACHE
#define   CTC_INTR_GB_FUNC_IPE_AGING_FIFO        CTC_INTR_FUNC_IPE_AGING_FIFO
#define   CTC_INTR_GB_FUNC_STATS_FIFO            CTC_INTR_FUNC_STATS_FIFO
#define   CTC_INTR_GB_FUNC_APS_FAILOVER          CTC_INTR_FUNC_APS_FAILOVER

#define   CTC_INTR_GB_DMA_FUNC                   CTC_INTR_DMA_FUNC
#define   CTC_INTR_GB_DMA_NORMAL                 CTC_INTR_DMA_NORMAL
#define   CTC_INTR_GB_MAX                        CTC_INTR_MAX

/**
 @brief [GB] Define a prototype for interrupt callback function
*/
typedef int32 (* CTC_INTERRUPT_FUNC)(uint8 lchip, uint32 intr, void* p_data);

/**
 @brief [GB] Define a prototype for event callback function
*/
typedef int32 (* CTC_INTERRUPT_EVENT_FUNC)(uint8 gchip, void* p_data);

/**
 @brief [GB] Define event type SDK notify application
*/
enum ctc_interrupt_event_e
{
    CTC_EVENT_L2_SW_LEARNING = 0,   /**<[GB.GG] (MUST) Notify application newest entries needed to learn, refer to ctc_learning_cache_t */
    CTC_EVENT_L2_SW_AGING,          /**<[GB.GG] (MUST) Notify application newest entries needed to aging, refer to ctc_aging_fifo_info_t */
    CTC_EVENT_OAM_STATUS_UPDATE,    /**<[GB.GG] (MUST) Notify application newest status changes of OAM session, refer to TBD */
    CTC_EVENT_PTP_TX_TS_CAPUTRE,    /**<[GB.GG] (MUST) Notify application captured TX TS entries, refer to ctc_ptp_ts_cache_t */
    CTC_EVENT_PTP_INPUT_CODE_READY, /**<[GB.GG] (OPTIONAL) Notify application Sync or ToD Interface input code ready, refer to ctc_ptp_rx_ts_message_t*/
    CTC_EVENT_PORT_LINK_CHANGE,     /**<[GB.GG] (OPTIONAL) Notify application 1G or XG PHY's link status changs, refer to ctc_port_link_status_t */
    CTC_EVENT_ABNORMAL_INTR,        /**<[GB.GG] (OPTIONAL) Notify application chip's abnormal status, refer to ctc_interrupt_abnormal_status_t */
    CTC_EVENT_ECC_ERROR             /**<[GB.GG] (OPTIONAL) Notify application chip's memory ecc error, refer to ctc_interrupt_ecc_t */
};
typedef enum ctc_interrupt_event_e ctc_interrupt_event_t;

/**
 @brief [GB] Define cascading interrupt type, CHIP replaced by gb
*/
struct ctc_intr_type_s
{
    uint32  intr;                /**<[GB.GG] sup-level interrupt type defined in ctc_interrupt_type_CHIP_t */
    uint32  sub_intr;            /**<[GB.GG] sub-level interrupt type defined in ctc_interrupt_type_CHIP_sub_SUP_t */
    uint32  low_intr;            /**<[GG] low-level interrupt type, used only for fatal and normal interrupt  */
};
typedef struct ctc_intr_type_s ctc_intr_type_t;

/**
 @brief [GB] Define interrupt status in bitmap
*/
struct ctc_intr_status_s
{
    uint32  bmp[CTC_INTR_STAT_SIZE];    /**< [GB.GG]bitmap of interrupt status */
    uint32  bit_count;                  /**< [GB.GG]valid bit count */
    uint32  low_intr;            /**<[GG] low-level interrupt type, used only for fatal and normal interrupt  */
};
typedef struct ctc_intr_status_s ctc_intr_status_t;

/**
 @brief [GB] Define chip abnormal status
*/
struct ctc_interrupt_abnormal_status_s
{
    ctc_intr_type_t     type;                   /**< [GB.GG]interrupt type */
    ctc_intr_status_t   status;                 /**<[GB.GG] low-level interrupt status */
    ctc_interrupt_fatal_intr_action_t action;   /**< [GB.GG]advised action of this status */
};
typedef struct ctc_interrupt_abnormal_status_s ctc_interrupt_abnormal_status_t;

/**
 @brief [GB] Define parameters of a sup-level interrupt
*/
struct ctc_intr_mapping_s
{
    int32               group;                      /**< [GB.GG]group ID of this interrupt */
    uint32              intr;                       /**< [GB.GG]type/ID of this interrupt, refer to ctc_interrupt_type_CHIP_t */
};
typedef struct ctc_intr_mapping_s ctc_intr_mapping_t;

/**
 @brief [GB] Define parameters of a group
*/
struct ctc_intr_group_s
{
    int32               group;                      /**< [GB.GG]group ID */
    uint32              irq;                        /**< [GB.GG]IRQ for this group, for msi this means msi irq index */
    int32               prio;                       /**< [GB.GG]priority of thread/task for handle this group */
    char                desc[CTC_INTR_DESC_LEN];    /**< [GB.GG]description of this group */
};
typedef struct ctc_intr_group_s ctc_intr_group_t;

/**
 @brief [GB] Define global configure parameters to initialize interrupt module
*/
struct ctc_intr_global_cfg_s
{
    uint32              group_count;                /**<[GB.GG] count of groups */
    uint32              intr_count;                 /**<[GB.GG] count of interrupts */
    ctc_intr_group_t*    p_group;  /**<[GB.GG] array of groups */
    ctc_intr_mapping_t*  p_intr;    /**<[GB.GG] array of interrupts */
    uint8                intr_mode;                  /**<[GB.GG] interrupt mode, 0: interrupt pin, 1: msi*/
    uint8                rsv[3];
};
typedef struct ctc_intr_global_cfg_s ctc_intr_global_cfg_t;

/**@} end of @defgroup isr ISR  */

#ifdef __cplusplus
}
#endif

#endif

