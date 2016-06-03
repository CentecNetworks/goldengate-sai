/**
 @file sys_goldengate_datapath.h

 @date 2013-05-28

 @version v2.0

 The file define APIs and types use in sys layer
*/
#ifndef _SYS_GOLDENGATE_DATAPATH_H
#define _SYS_GOLDENGATE_DATAPATH_H
#ifdef __cplusplus
extern "C" {
#endif
/***************************************************************
 *
 * Header Files
 *
 ***************************************************************/
#include "sal.h"
#include "ctc_const.h"
#include "ctc_vector.h"

#define HSS15G_LANE_NUM 8
#define HSS28G_LANE_NUM 4
#define SERDES_NUM_PER_SLICE 48
#define HSS28G_NUM_PER_SLICE 2
#define HSS15G_NUM_PER_SLICE 5

#define SYS_DATAPATH_REFCLOCK 156
#define SYS_DATAPATH_HSS_NUM 14

#define SYS_DATAPATH_CORE_NUM 2

#define SYS_DATAPATH_DEBUG_SHOW_ALL   0x01

#define SYS_DATAPATH_USELESS_MAC 0xffff

#define SYS_DATAPATH_DBG_OUT(level, FMT, ...) \
    do { \
        CTC_DEBUG_OUT(datapath, datapath, DATAPATH_SYS, level, FMT, ##__VA_ARGS__); \
    } while (0)

struct sys_datapath_serdes_info_s
{
    uint8 mode;        /*pcs mode, refer to ctc_chip_serdes_mode_t*/
    uint8 pll_sel;       /* 0: disable,1:plla. 2:pllb */
    uint8 rate_div;     /*0: full, 1:1/2, 2:1/4, 3:1/8*/
    uint8 bit_width;   /* bit width*/
    uint16 lport;        /*chip local phy port*/
    uint8 rx_polarity;  /*0:normal, 1:reverse*/
    uint8 tx_polarity;  /*0:normal, 1:reverse*/
    uint8 lane_id;  /*serdes internal lane id */
    uint8 is_dyn;
    uint8 rsv[3];
};
typedef struct sys_datapath_serdes_info_s   sys_datapath_serdes_info_t;


struct sys_datapath_hss_attribute_s
{
    uint8 hss_type;   /*0:Hss15G, 1:Hss28G, refer sys_datapath_hss_type_t*/
    uint8 hss_id;        /*for hss15g is 0~9, for hss28g is 0~3*/
    uint8 plla_mode;  /*refer to sys_datapath_hssclk_t */
    uint8 pllb_mode;  /*refer to sys_datapath_hssclk_t */
    uint8 core_div_a[SYS_DATAPATH_CORE_NUM];  /*refer to sys_datapath_clktree_div_t, usefull plla is used*/
    uint8 core_div_b[SYS_DATAPATH_CORE_NUM];  /*refer to sys_datapath_clktree_div_t, usefull plla is used*/
    uint8 intf_div_a;   /*refer to sys_datapath_clktree_div_t, usefull pllb is used*/
    uint8 intf_div_b;   /*refer to sys_datapath_clktree_div_t, usefull pllb is used*/
    sys_datapath_serdes_info_t  serdes_info[HSS15G_LANE_NUM];   /*hss28G only 4 serdes info is valid, refer to sys_datapath_serdes_info_t  */
    uint8 plla_ref_cnt;      /*indicate used lane number for the plla, if the num decrease to 0, set plla to disable*/
    uint8 pllb_ref_cnt;      /*indicate used lane number for the pllb, if the num decrease to 0, set pllb to disable*/
    uint16 clktree_bitmap; /*indicate clktree need cfg, refer to  sys_datapath_clktree_op_t */
};
typedef struct sys_datapath_hss_attribute_s  sys_datapath_hss_attribute_t;


enum sys_datapath_hssclk_e
{
    SYS_DATAPATH_HSSCLK_DISABLE,          /* no use*/
    SYS_DATAPATH_HSSCLK_515DOT625,      /* 515.625M: for xfi,xlg */
    SYS_DATAPATH_HSSCLK_500,                  /* 500M: for sgmii */
    SYS_DATAPATH_HSSCLK_644DOT53125,   /* 644.53125M: for cg */
    SYS_DATAPATH_HSSCLK_625,                  /* 625M: for xaui,d-xaui,2.5G */
    SYS_DATAPATH_HSSCLK_MAX
};
typedef enum sys_datapath_hssclk_e sys_datapath_hssclk_t;

enum sys_datapath_pll_sel_e
{
    SYS_DATAPATH_PLL_SEL_NONE,
    SYS_DATAPATH_PLL_SEL_PLLA,
    SYS_DATAPATH_PLL_SEL_PLLB,
    SYS_DATAPATH_PLL_SEL_BOTH
};
typedef enum sys_datapath_pll_sel_e sys_datapath_pll_sel_t;

enum sys_datapath_serdes_dir_e
{
    SYS_DATAPATH_SERDES_DIR_RX,
    SYS_DATAPATH_SERDES_DIR_TX,
    SYS_DATAPATH_SERDES_DIR_BOTH
};
typedef enum sys_datapath_serdes_dir_e sys_datapath_serdes_dir_t;

enum sys_datapath_hss_type_e
{
    SYS_DATAPATH_HSS_TYPE_15G,
    SYS_DATAPATH_HSS_TYPE_28G
};
typedef enum sys_datapath_hss_type_e sys_datapath_hss_type_t;

enum sys_datapath_debug_type_e
{
    SYS_DATAPATH_DEBUG_HSS,
    SYS_DATAPATH_DEBUG_SERDES,
    SYS_DATAPATH_DEBUG_CLKTREE,
    SYS_DATAPATH_DEBUG_CALENDAR
};
typedef enum sys_datapath_debug_type_e sys_datapath_debug_type_t;

enum sys_datapath_lport_type_e
{
    SYS_DATAPATH_NETWORK_PORT,
    SYS_DATAPATH_OAM_PORT,
    SYS_DATAPATH_DMA_PORT,
    SYS_DATAPATH_ILOOP_PORT,
    SYS_DATAPATH_ELOOP_PORT,
    SYS_DATAPATH_RSV_PORT
};
typedef enum sys_datapath_lport_type_e sys_datapath_lport_type_t;

enum sys_datapath_clktree_op_e
{
    SYS_DATAPATH_CLKTREE_INTF_A,
    SYS_DATAPATH_CLKTREE_CORE_A0,
    SYS_DATAPATH_CLKTREE_CORE_A1,
    SYS_DATAPATH_CLKTREE_INTF_B,
    SYS_DATAPATH_CLKTREE_CORE_B0,
    SYS_DATAPATH_CLKTREE_CORE_B1
};
typedef enum sys_datapath_clktree_op_e sys_datapath_clktree_op_t;

struct sys_datapath_lport_attr_s
{
    uint8 port_type;  /*refer to sys_datapath_lport_type_t */
    uint8 mac_id;
    uint8 chan_id;
    uint8 speed_mode;  /*refer to ctc_port_speed_t, only usefull for network port*/
    uint8 slice_id;
    uint8 cal_index;  /*Only usefull for network port, means calendar entry index*/
    uint8 need_ext;
    uint8 pcs_mode; /*refer to ctc_chip_serdes_mode_t*/

    uint8 serdes_id;
    uint8 rsv[3];
};
typedef struct sys_datapath_lport_attr_s sys_datapath_lport_attr_t;

typedef int32 (* SYS_CALLBACK_DATAPATH_FUN_P)  (uint8 lchip, uint16 lport, sys_datapath_lport_attr_t* port_attr);

extern int32 sys_goldengate_datapath_show_status(uint8 lchip);
extern int32 sys_goldengate_datapath_show_info(uint8 lchip, uint8 type, uint32 start, uint32 end, uint8 is_all);
extern void* sys_goldengate_datapath_get_port_capability(uint8 lchip, uint16 lport, uint8 slice_id);
extern uint16 sys_goldengate_datapath_get_lport_with_mac(uint8 lchip, uint8 slice_id, uint8 mac_id);
extern int32 sys_goldengate_datapath_init(uint8 lchip, void* p_global_cfg);
extern int32 sys_goldengate_datapath_set_serdes_polarity(uint8 lchip, void* p_data);
extern int32 sys_goldengate_datapath_set_serdes_mode(uint8 lchip, uint8 serdes_id, uint8 mode);
extern int32 sys_goldengate_datapath_set_serdes_loopback(uint8 lchip, void* p_data);
extern int32 sys_goldengate_datapath_set_serdes_prbs(uint8 lchip, void* p_data);
extern int32 sys_goldengate_datapath_set_serdes_prbs_tx(uint8 lchip, void* p_data);
extern int32 sys_goldengate_datapath_set_serdes_ffe(uint8 lchip, void* p_data);
extern int32 sys_goldengate_datapath_get_serdes_with_lport(uint8 lchip, uint16 chip_port, uint8 slice, uint16* p_serdes_id, uint8* num);
extern int32 sys_goldengate_datapath_set_link_enable(uint8 lchip, uint8 serdes_id, uint8 enable, uint8 dir);
extern int32 sys_goldengate_datapath_set_link_reset(uint8 lchip, uint8 serdes_id, uint8 enable, uint8 dir);
extern int32 sys_goldengate_datapath_set_dfe_reset(uint8 lchip, uint8 serdes_id, uint8 enable);
extern uint16 sys_goldengate_datapath_get_serdes_sigdet(uint8 lchip, uint16 serdes_id);
extern int16 sys_goldengate_datapath_set_serdes_aec_aet_en(uint8 lchip, uint16 serdes_id, uint16 cfg_flag, bool enable);
extern int16 sys_goldengate_datapath_set_serdes_aec_aet_done(uint8 lchip, uint16 serdes_id);
extern int32 sys_goldengate_datapath_get_serdes_ffe(uint8 lchip, uint8 serdes_id, uint16* coefficient, uint8 ffe_mode);
extern int32 sys_goldengate_datapath_get_serdes_polarity(uint8 lchip, void* p_data);
extern int32 sys_goldengate_datapath_get_serdes_loopback(uint8 lchip, void* p_data);
extern int32 sys_goldengate_datapath_get_serdes_rx_peaking(uint8 lchip, void* p_data);
extern int32 sys_goldengate_datapath_set_serdes_rx_peaking(uint8 lchip, void* p_data);
extern uint16 sys_goldengate_datapath_get_core_clock(uint8 lchip, uint8 core_type);
extern int32 sys_goldengate_datapath_get_serdes_info(uint8 lchip, uint8 serdes_id, sys_datapath_serdes_info_t** p_serdes);
extern int32 sys_goldengate_datapath_cb_register(uint8 lchip, SYS_CALLBACK_DATAPATH_FUN_P bpe_cb);
extern int16 sys_goldengate_datapath_set_serdes_auto_neg_ability(uint8 lchip, uint16 serdes_id, uint32 ability);
extern int16 sys_goldengate_datapath_get_serdes_auto_neg_ability(uint8 lchip, uint16 serdes_id, uint32* p_ability);
extern int32 sys_goldengate_datapath_get_gport_with_serdes(uint8 lchip, uint16 serdes_id, uint16* p_gport);
extern int16 sys_goldengate_datapath_set_serdes_auto_neg_en(uint8 lchip, uint16 serdes_id, uint32 enable);
#ifdef __cplusplus
}
#endif

#endif

