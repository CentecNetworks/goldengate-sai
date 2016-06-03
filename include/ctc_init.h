/**********************************************************
 * ctc_init.h
 * Date:
 **********************************************************/
#ifndef _CTC_INIT_H
#define _CTC_INIT_H
#ifdef __cplusplus
extern "C" {
#endif
/**********************************************************
 *
 * Header file
 *
 **********************************************************/
#include "dal.h"
#include "ctc_acl.h"
#include "ctc_bpe.h"
#include "ctc_chip.h"
#include "ctc_dma.h"
#include "ctc_interrupt.h"
#include "ctc_ipuc.h"
#include "ctc_l2.h"
#include "ctc_l3if.h"
#include "ctc_learning_aging.h"
#include "ctc_linkagg.h"
#include "ctc_mpls.h"
#include "ctc_nexthop.h"
#include "ctc_oam.h"
#include "ctc_packet.h"
#include "ctc_parser.h"
#include "ctc_port.h"
#include "ctc_qos.h"
#include "ctc_scl.h"
#include "ctc_stacking.h"
#include "ctc_stats.h"
#include "ctc_vlan.h"
#include "ctc_ptp.h"
#include "ctc_ftm.h"
#include "ctc_debug.h"
#include "ctc_overlay_tunnel.h"
#include "ctc_ipfix.h"

/**********************************************************
 *
 * Defines and macros
 *
 **********************************************************/
#define CTC_INIT_DBG_OUT(level, FMT, ...) \
    do { \
        CTC_DEBUG_OUT(init, init, INIT_CODE, level, FMT, ##__VA_ARGS__); \
    } while (0)

#define CTC_INIT_ERR_RET(ret) \
    ((ret != 0) && (ret != CTC_E_NOT_SUPPORT))

#define CTC_INIT_DO_INIT(__FEATURE__,__DO_INIT__,__FLAG__)                  \
{                                                                           \
    __DO_INIT__ = 0;                                                    \
    if (CTC_FLAG_ISSET(__FLAG__, __FEATURE__))  \
    {                                                                       \
        __DO_INIT__ = 1;                                                 \
    }                                                                       \
}

/**
 @brief Define SDK init module type, default init_flag value is CTC_INIT_MODULE_FCOE-1
*/
enum ctc_init_module_type_e
{
    CTC_INIT_MODULE_MPLS        = 1U << 0,
    CTC_INIT_MODULE_APS         = 1U << 1,
    CTC_INIT_MODULE_OAM         = 1U << 2,
    CTC_INIT_MODULE_PTP         = 1U << 3,
    CTC_INIT_MODULE_SYNCE       = 1U << 4,
    CTC_INIT_MODULE_STACKING    = 1U << 5,
    CTC_INIT_MODULE_BPE         = 1U << 6,
    CTC_INIT_MODULE_IPFIX       = 1U << 7,
    CTC_INIT_MODULE_MONITOR     = 1U << 8,
    CTC_INIT_MODULE_OVERLAY     = 1U << 9,
    CTC_INIT_MODULE_EFD         = 1U << 10,
    CTC_INIT_MODULE_FCOE        = 1U << 11,
    CTC_INIT_MODULE_TRILL       = 1U << 12,
    CTC_INIT_MODULE_MAX
};
typedef enum ctc_init_module_type_e ctc_init_module_type_t;


/**
 @brief Define SDK init data-structure
*/
struct ctc_init_cfg_s
{
    uint32 init_flag;

    ctc_chip_global_cfg_t        * p_chip_cfg;
    ctc_datapath_global_cfg_t    * p_datapath_cfg;
    ctc_nh_global_cfg_t          * p_nh_cfg;
    ctc_qos_global_cfg_t         * p_qos_cfg;
    ctc_vlan_global_cfg_t        * p_vlan_cfg;
    ctc_l3if_global_cfg_t        * p_l3if_cfg;
    ctc_parser_global_cfg_t      * p_parser_cfg;
    ctc_port_global_cfg_t        * p_port_cfg;
    ctc_linkagg_global_cfg_t     * p_linkagg_cfg;
    ctc_pkt_global_cfg_t         * p_pkt_cfg;
    ctc_l2_fdb_global_cfg_t      * p_l2_fdb_cfg;
    ctc_stats_global_cfg_t       * p_stats_cfg;
    ctc_acl_global_cfg_t         * p_acl_cfg;
    ctc_ipuc_global_cfg_t        * p_ipuc_cfg;
    ctc_mpls_init_t              * p_mpls_cfg;
    ctc_learn_aging_global_cfg_t * p_learning_aging_cfg;
    ctc_oam_global_t             * p_oam_cfg;
    ctc_ptp_global_config_t      * p_ptp_cfg;
    ctc_intr_global_cfg_t        * p_intr_cfg;
    ctc_stacking_glb_cfg_t       * p_stacking_cfg;
    ctc_dma_global_cfg_t         * p_dma_cfg;
    ctc_bpe_global_cfg_t         * p_bpe_cfg;
    ctc_overlay_tunnel_global_cfg_t   * p_overlay_cfg;
    ctc_ipfix_global_cfg_t         * p_ipifx_cfg;
    dal_op_t                     * dal_cfg;
    ctc_chip_phy_mapping_para_t*  phy_mapping_para[CTC_MAX_LOCAL_CHIP_NUM];

    ctc_ftm_profile_info_t       ftm_info;
    uint8 gchip[CTC_MAX_LOCAL_CHIP_NUM];
    uint8 local_chip_num;
    uint8 rsv;
};
typedef struct ctc_init_cfg_s ctc_init_cfg_t;

extern int32
ctc_sdk_init(void * p_global_cfg);

extern int32
ctc_sdk_deinit(void);


extern int32
ctcs_sdk_init(uint8 lchip, void * p_global_cfg);

extern int32
ctcs_sdk_deinit(uint8 lchip);


#ifdef __cplusplus
}
#endif
#endif
