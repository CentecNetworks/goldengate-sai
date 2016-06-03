/**
 @file sys_goldengate_chip.h

 @date 2009-10-19

 @version v2.0

 The file contains all chip related APIs of sys layer
*/

#ifndef _SYS_GOLDENGATE_CHIP_H
#define _SYS_GOLDENGATE_CHIP_H
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************
 *
 * Header Files
 *
 ***************************************************************/
#include "sal.h"
#include "ctc_const.h"
#include "ctc_chip.h"
#include "ctc_debug.h"
#include "sys_goldengate_common.h"

/****************************************************************
*
* Defines and Macros
*
****************************************************************/
#define SYS_CHIP_HSS12G_MACRO_NUM        4
#define STS_CHIP_HSS12G_LINK_NUM         8
#define SYS_HSS12G_PORT_EN_REG1          6
#define SYS_HSS12G_PORT_EN_REG2          7
#define SYS_HSS12G_PORT_RESET_REG1       8
#define SYS_HSS12G_PORT_RESET_REG2       9
#define SYS_HSS12G_PLL_COMMON_HIGH_ADDR  16
#define SYS_CHIP_CPU_MAC_ETHER_TYPE      0x5a5a
#define SYS_CHIP_SWITH_THREADHOLD        20
#define SYS_CHIP_PER_SLICE_PORT_NUM      256


#define SYS_DRV_GCHIP_LENGTH                5           /**< Gchip id length(unit: bit) */
#define SYS_DRV_GCHIP_MASK                  0x1F        /**< Gchip id mask(unit: bit) */
#define SYS_DRV_LOCAL_PORT_LENGTH           9           /**< Local port id length(unit: bit) */
#define SYS_DRV_LOCAL_PORT_MASK             0x1FF        /**< Local port mask */

#define SYS_DRV_GPORT_TO_GCHIP(gport)        (((gport) >> SYS_DRV_LOCAL_PORT_LENGTH) & CTC_GCHIP_MASK)
#define SYS_DRV_GPORT_TO_LPORT(gport)        ((gport)& SYS_DRV_LOCAL_PORT_MASK)
#define SYS_DRV_IS_LINKAGG_PORT(gport)       ((SYS_DRV_GPORT_TO_GCHIP(gport)&SYS_DRV_GCHIP_MASK) == CTC_LINKAGG_CHIPID)

#define SYS_MAP_DRV_LPORT_TO_SYS_LPORT(lport) (lport)

#define SYS_MAP_SYS_LPORT_TO_DRV_LPORT(lport)  (lport)

#define SYS_MAP_CTC_GPORT_TO_DRV_LPORT(gport) SYS_MAP_SYS_LPORT_TO_DRV_LPORT(CTC_MAP_GPORT_TO_LPORT((gport)))

#define SYS_MAP_DRV_LPORT_TO_CTC_GPORT(gchip, lport) CTC_MAP_LPORT_TO_GPORT(gchip, SYS_MAP_DRV_LPORT_TO_SYS_LPORT(lport))

#define SYS_MAP_DRV_LPORT_TO_SLICE(lport) (((lport) < SYS_CHIP_PER_SLICE_PORT_NUM) ? 0 : 1)

#define SYS_MAP_CHANID_TO_SLICE(chan) ((chan >= 64) ? 1 : 0)

#define SYS_MAP_CTC_GPORT_TO_DRV_LPORT_WITH_CHECK(gport, lchip, lport) \
{\
    uint8 gchip = SYS_MAP_CTC_GPORT_TO_GCHIP(gport);\
    if (gchip > 0x1e) return CTC_E_INVALID_GLOBAL_CHIPID;\
    if (FALSE == sys_goldengate_chip_is_local(lchip, gchip)) \
        return CTC_E_CHIP_IS_REMOTE;\
    lport = CTC_MAP_GPORT_TO_LPORT(gport);\
    if (lport >= MAX_PORT_NUM_PER_CHIP)\
        return CTC_E_INVALID_LOCAL_PORT;\
     lport = SYS_MAP_SYS_LPORT_TO_DRV_LPORT(lport);\
}

#define SYS_MAP_CTC_GPORT_TO_DRV_GPORT(gport) ((CTC_MAP_GPORT_TO_GCHIP(gport) << SYS_DRV_LOCAL_PORT_LENGTH)\
                                              | (CTC_IS_LINKAGG_PORT(gport) ? CTC_MAP_GPORT_TO_LPORT(gport) : SYS_MAP_CTC_GPORT_TO_DRV_LPORT(gport)))

#define SYS_MAP_CTC_GPORT_TO_GCHIP(gport)     (((gport) >> CTC_LOCAL_PORT_LENGTH) & CTC_GCHIP_MASK)

#define SYS_MAP_DRV_GPORT_TO_CTC_GPORT(gport)   (CTC_MAP_LPORT_TO_GPORT(SYS_DRV_GPORT_TO_GCHIP(gport)\
        , SYS_DRV_IS_LINKAGG_PORT(gport)? (SYS_DRV_GPORT_TO_LPORT(gport)):(SYS_MAP_DRV_LPORT_TO_SYS_LPORT(SYS_DRV_GPORT_TO_LPORT(gport)))))

#define SYS_MAX_PHY_PORT_CHECK(lport) \
{ \
    if (((lport) & 0xff) >= 64) \
    {  \
        return CTC_E_INVALID_LOCAL_PORT;  \
    } \
}

/*Below Define is for CTC APIs dispatch*/
/*---------------------------------------------------------------*/
extern uint8 g_ctcs_api_en;

#define SYS_MAP_GCHIP_TO_LCHIP(gchip, lchip) \
    do{\
        if (gchip >= 0x1e)\
        {\
            return CTC_E_INVALID_GLOBAL_CHIPID;\
        }\
        if(!g_ctcs_api_en)\
        {\
            if(CTC_E_NONE != sys_goldengate_get_local_chip_id(gchip, &lchip))\
            {\
                return CTC_E_CHIP_IS_REMOTE;\
            }\
        }\
    }while(0);

#define SYS_MAP_GPORT_TO_LCHIP(gport, lchip) \
    do{\
        if(!g_ctcs_api_en)\
        {\
            SYS_MAP_GCHIP_TO_LCHIP(SYS_MAP_CTC_GPORT_TO_GCHIP(gport), lchip);\
        }\
    }while(0);

#define CTC_SET_API_LCHIP(lchip, api_lchip) \
    do{\
        if(!g_ctcs_api_en) lchip = api_lchip;\
    }while(0);


#define CTC_FOREACH_LCHIP(lchip_start,lchip_end,all_lchip) \
      if(g_ctcs_api_en)              \
      {                              \
          lchip_start = lchip;       \
          lchip_end = lchip + 1;     \
      }                              \
      else                           \
      {                              \
          lchip_start = all_lchip ? 0:lchip_start;\
          lchip_end = all_lchip ?sys_goldengate_get_local_chip_num():lchip_end;\
      }\
      for(lchip = lchip_start ; lchip < lchip_end; lchip++)


#define CTC_FOREACH_ROLLBACK(lchip_start,lchip_end) \
      if(g_ctcs_api_en)              \
      {                              \
          lchip_start = 0;           \
          lchip_end = 0;             \
      }                              \
      else                           \
      {                              \
         lchip_start = (lchip != lchip_end) ? 0: lchip;\
         lchip_end   = lchip;\
      }\
      for(lchip = lchip_start ; lchip < lchip_end; lchip++)


#define CTC_FOREACH_ERROR_RETURN(exist_ret,ret,op)    \
        ret = (op);                                    \
        if(exist_ret == ret)                         \
        {                                              \
            ret = CTC_E_NONE;                          \
            continue;                                  \
        }                                              \
        else if(CTC_E_NONE == ret)                     \
        {                                              \
            continue;                                  \
        }                                              \
        else                                           \
        {                                              \
            break;                                     \
        }

#define CTC_FOREACH_ERROR_RETURN2(exist_ret1,exist_ret2,ret,op)     \
        ret = (op);                                                 \
        if((exist_ret1 == ret) || (exist_ret2 == ret))          \
        {                                                           \
            ret = CTC_E_NONE;                                       \
            continue;                                               \
        }                                                           \
        else if(CTC_E_NONE == ret)                                  \
        {                                                           \
            continue;                                               \
        }                                                           \
        else                                                        \
        {                                                           \
            break;                                                  \
        }


/*---------------------------------------------------------------*/


#define SYS_LOCAL_CHIPID_CHECK(lchip)                                      \
    do {                                                                   \
        uint8 local_chip_num = sys_goldengate_get_local_chip_num(lchip);        \
        if (lchip >= local_chip_num){ return CTC_E_INVALID_LOCAL_CHIPID; } \
    } while (0);


#define FEATURE_SUPPORT_CHECK(feature) \
{\
    if (CTC_FEATURE_MAX <= feature) \
        return CTC_E_INTR_INVALID_PARAM; \
    if (FALSE == sys_goldengate_chip_check_feature_support(feature)) \
        return CTC_E_NOT_SUPPORT;\
}


#define SYS_CHIP_DBG_OUT(level, FMT, ...) \
    do { \
        CTC_DEBUG_OUT(chip, chip, CHIP_SYS, level, FMT, ##__VA_ARGS__); \
    } while (0)

/*#define SYS_HUMBER_CHIP_CLOCK 625*/
#define CHIP_LOCK(lchip) \
    if (p_chip_master[lchip]->p_chip_mutex) sal_mutex_lock(p_chip_master[lchip]->p_chip_mutex)

#define CHIP_UNLOCK(lchip) \
    if (p_chip_master[lchip]->p_chip_mutex) sal_mutex_unlock(p_chip_master[lchip]->p_chip_mutex)

#define SWITCH_LOCK(lchip) \
    if (p_chip_master[lchip]->p_switch_mutex) sal_mutex_lock(p_chip_master[lchip]->p_switch_mutex)

#define SWITCH_UNLOCK(lchip) \
    if (p_chip_master[lchip]->p_switch_mutex) sal_mutex_unlock(p_chip_master[lchip]->p_switch_mutex)

#define LCHIP_CHECK(lchip)                              \
    do {                                                     \
        if ((lchip) >= sys_goldengate_get_local_chip_num(lchip)){  \
            return CTC_E_INVALID_LOCAL_CHIPID; }              \
    } while (0)

#define SYS_LPORT_IS_CPU_ETH(lchip, lport) sys_goldengate_chip_is_eth_cpu_port(lchip, lport)


#define SYS_HSS12G_ADDRESS_CONVERT(addr_h, addr_l)   (((addr_h) << 6) | (addr_l))

#define SYS_XQMAC_PER_SLICE_NUM      12
#define SYS_SUBMAC_PER_XQMAC_NUM      4
#define SYS_SGMAC_PER_SLICE_NUM       (SYS_XQMAC_PER_SLICE_NUM * SYS_SUBMAC_PER_XQMAC_NUM)
#define SYS_CGMAC_PER_SLICE_NUM       2

#define SYS_CHIP_MAC_LED_CLK    25

struct sys_chip_master_s
{
    sal_mutex_t* p_chip_mutex;
    sal_mutex_t* p_switch_mutex;
    uint8   resv[2];
    uint8   g_chip_id;
    char    datapath_mode[20];
    uint8   first_ge_opt_reg_used;
    uint8   first_ge_opt_reg;
    uint8   second_ge_opt_reg_used;
    uint8   second_ge_opt_reg;
    mac_addr_t cpu_mac_sa;
    mac_addr_t cpu_mac_da[MAX_CTC_CPU_MACDA_NUM];
    uint8   port_mdio_mapping_tbl[CTC_MAX_PHY_PORT];
    uint8   port_phy_mapping_tbl[CTC_MAX_PHY_PORT];

    uint8   cut_through_en;
    uint8   cut_through_speed;

    uint8   tpid;
    uint8   cpu_eth_en;
    uint16  cpu_channel;
    uint16  vlan_id;

    sal_mutex_t* p_i2c_mutex;
    sal_mutex_t* p_smi_mutex;
};
typedef struct sys_chip_master_s sys_chip_master_t;

enum sys_chip_mdio_bus_e
{
    SYS_CHIP_MDIO_BUS0,
    SYS_CHIP_MDIO_BUS1,
    SYS_CHIP_MDIO_BUS2,
    SYS_CHIP_MDIO_BUS3,

    SYS_CHIP_MAX_MDIO_BUS
};
typedef enum sys_chip_mdio_bus_e sys_chip_mdio_bus_t;

enum sys_chip_device_id_type_e
{
    SYS_CHIP_DEVICE_ID_GG_CTC8096,
    SYS_CHIP_DEVICE_ID_INVALID,
};
typedef enum sys_chip_device_id_type_e sys_chip_device_id_type_t;

/****************************************************************************
 *
* Function
*
*****************************************************************************/
extern int32
sys_goldengate_chip_init(uint8 lchip, uint8 lchip_num);

extern uint8
sys_goldengate_get_local_chip_num();

extern int32
sys_goldengate_set_gchip_id(uint8 lchip, uint8 gchip_id);

extern bool
sys_goldengate_chip_is_local(uint8 lchip, uint8 gchip_id);

extern int32
sys_goldengate_get_gchip_id(uint8 lchip, uint8* gchip_id);

extern int32
sys_goldengate_set_chip_global_cfg(uint8 lchip, ctc_chip_global_cfg_t* chip_cfg);

extern int32
sys_goldengate_get_chip_clock(uint8 lchip, uint16* freq);

extern int32
sys_goldengate_get_chip_cpumac(uint8 lchip, uint8* mac_sa, uint8* mac_da);

extern int32
sys_goldengate_get_chip_cpu_eth_en(uint8 lchip, uint8 *enable, uint8* cpu_eth_chan);

extern int32
sys_goldengate_chip_set_eth_cpu_cfg(uint8 lchip);

extern bool
sys_goldengate_chip_is_eth_cpu_port(uint8 lchip, uint16 lport);

extern int32
sys_goldengate_chip_set_phy_mapping(uint8 lchip, ctc_chip_phy_mapping_para_t* phy_mapping_para);

extern int32
sys_goldengate_chip_get_phy_mapping(uint8 lchip, ctc_chip_phy_mapping_para_t* phy_mapping_para);

extern int32
sys_goldengate_chip_get_phy_mdio(uint8 lchip, uint16 gport, uint8* mdio_bus, uint8* phy_addr);

extern int32
sys_goldengate_chip_write_gephy_reg(uint8 lchip, uint16 gport, ctc_chip_gephy_para_t* gephy_para);

extern int32
sys_goldengate_chip_read_gephy_reg(uint8 lchip, uint16 gport, ctc_chip_gephy_para_t* gephy_para);

extern int32
sys_goldengate_chip_write_xgphy_reg(uint8 lchip, uint16 gport, ctc_chip_xgphy_para_t* xgphy_para);

extern int32
sys_goldengate_chip_read_xgphy_reg(uint8 lchip, uint16 gport, ctc_chip_xgphy_para_t* xgphy_para);

extern int32
sys_goldengate_chip_set_gephy_scan_special_reg(uint8 lchip, ctc_chip_ge_opt_reg_t* p_gephy_opt, bool enable);

extern int32
sys_goldengate_chip_set_xgphy_scan_special_reg(uint8 lchip, ctc_chip_xg_opt_reg_t* p_xgphy_opt, uint8 enable);

extern int32
sys_goldengate_chip_set_phy_scan_para(uint8 lchip, ctc_chip_phy_scan_ctrl_t* p_scan_para);

extern int32
sys_goldengate_chip_set_phy_scan_en(uint8 lchip, bool enable);

extern int32
sys_goldengate_chip_set_i2c_scan_para(uint8 lchip, ctc_chip_i2c_scan_t* p_i2c_para);

extern int32
sys_goldengate_chip_set_i2c_scan_en(uint8 lchip, bool enable);

extern int32
sys_goldengate_chip_read_i2c_buf(uint8 lchip, ctc_chip_i2c_scan_read_t *p_i2c_scan_read);

extern int32
sys_goldengate_chip_i2c_read(uint8 lchip, ctc_chip_i2c_read_t* p_i2c_para);

extern int32
sys_goldengate_chip_i2c_write(uint8 lchip, ctc_chip_i2c_write_t* p_i2c_para);

extern int32
sys_goldengate_chip_set_mac_led_mode(uint8 lchip, ctc_chip_led_para_t* p_led_para, ctc_chip_mac_led_type_t led_type);

extern int32
sys_goldengate_chip_set_mac_led_mapping(uint8 lchip, ctc_chip_mac_led_mapping_t* p_led_map);

extern int32
sys_goldengate_chip_set_mac_led_en(uint8 lchip, bool enable);

extern int32
sys_goldengate_chip_set_gpio_mode(uint8 lchip, uint8 gpio_id, ctc_chip_gpio_mode_t mode);

extern int32
sys_goldengate_chip_set_gpio_output(uint8 lchip, uint8 gpio_id, uint8 out_para);

extern int32
sys_goldengate_chip_get_gpio_input(uint8 lchip, uint8 gpio_id, uint8* in_value);

extern int32
sys_goldengate_chip_set_access_type(uint8 lchip, ctc_chip_access_type_t access_type);

extern int32
sys_goldengate_chip_get_access_type(uint8 lchip, ctc_chip_access_type_t* p_access_type);

extern int32
sys_goldengate_chip_hss12g_link_power_up(uint8 lchip, uint8 hssid, uint8 link_idx);

extern int32
sys_goldengate_chip_hss12g_link_power_down(uint8 lchip, uint8 hssid, uint8 link_idx);

extern int32
sys_goldengate_chip_get_serdes_info(uint8 lchip, uint8 lport, uint8* macro_idx, uint8* link_idx);

/* return value units: MHz*/
extern uint16
sys_goldengate_get_core_freq(uint8 lchip, uint8 type);

extern int32
sys_goldengate_chip_set_serdes_mode(uint8 lchip, ctc_chip_serdes_info_t* p_serdes_info);

extern int32
sys_goldengate_chip_mdio_read(uint8 lchip, ctc_chip_mdio_type_t type, ctc_chip_mdio_para_t* p_para);

extern int32
sys_goldengate_chip_mdio_write(uint8 lchip, ctc_chip_mdio_type_t type, ctc_chip_mdio_para_t* p_para);

extern int32
sys_goldengate_chip_set_mdio_clock(uint8 lchip, ctc_chip_mdio_type_t type, uint16 freq);

extern int32
sys_goldengate_chip_set_hss12g_enable(uint8 lchip, uint8 hssid, ctc_chip_serdes_mode_t mode, uint8 enable);

extern int32
sys_goldengate_get_cut_through_en(uint8 lchip);

extern int32
sys_goldengate_get_cut_through_speed(uint8 lchip, uint16 gport);

extern int32
sys_goldengate_chip_set_property(uint8 lchip, ctc_chip_property_t chip_prop, void* p_value);

extern int32
sys_goldengate_get_chip_sensor(uint8 lchip, ctc_chip_sensor_type_t type, uint32* p_value);

extern int32
sys_goldengate_chip_ecc_recover_init(uint8 lchip);

extern int32
sys_goldengate_chip_show_ecc_recover_status(uint8 lchip, uint8 is_all);

extern int32
sys_goldengate_chip_get_device_info(uint8 lchip, ctc_chip_device_info_t* p_device_info);

extern int32
sys_goldengate_mdio_init(uint8 lchip);

extern int32
sys_goldengate_chip_get_property(uint8 lchip, ctc_chip_property_t chip_prop, void* p_value);

extern int32
sys_goldengate_chip_set_dlb_chan_type(uint8 lchip, uint8 chan_id);

/**
 Configure the tcam scan burst interval time and burst entry num.
 When burst_interval = 0, means scan all tcam without interval, otherwise burst_entry_num must > 0.
 */
extern int32
sys_goldengate_chip_set_tcam_scan_cfg(uint8 lchip, uint32 burst_entry_num, uint32 burst_interval);

extern int32
sys_goldengate_get_local_chip_id(uint8 gchip_id, uint8* lchip_id);

extern bool
sys_goldengate_chip_check_feature_support(uint8 feature);

#ifdef __cplusplus
}
#endif

#endif

