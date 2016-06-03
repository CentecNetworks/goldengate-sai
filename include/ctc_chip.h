/**
 @file ctc_chip.h

 @author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2009-11-30

 @version v2.0

   This file contains all chip related data structure, enum, macro and proto.
*/

#ifndef _CTC_CHIP_H
#define _CTC_CHIP_H
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************
 *
 * Header Files
 *
 ***************************************************************/

#include "sal_types.h"
#include "ctc_mix.h"

/****************************************************************
*
* Defines and Macros
*
****************************************************************/

/****************************************************************
*
* Data Structures
*
****************************************************************/

/**
 @defgroup chip CHIP
 @{
*/

/**
 @brief define chip type
*/
enum ctc_chip_type_e
{
    CTC_CHIP_HUMBER,    /**< [HB]indicate this is a humber chip */
    CTC_CHIP_GREATBELT, /**< [GB]indicate this is a greatbelt chip */
    MAX_CTC_CHIP_TYPE
};
typedef enum ctc_chip_type_e ctc_chip_type_t;

/**
 @brief define chip IO type
*/
enum ctc_chip_datapath_type_e
{
    CTC_CHIP_DATAPATH_48G_4SG,  /**<[HB] indicate this chip use 48 GMAC + 4 SGMAC */
    CTC_CHIP_DATAPATH_4XG_4SG,  /**<[HB] indicate this chip use 4 XMAC + 4 SGMAC */
    CTC_CHIP_DATAPATH_100G,     /**<[HB] indicate this chip use  ???*/
    MAX_CTC_CHIP_DATAPATH
};
typedef enum ctc_chip_datapath_type_e ctc_chip_datapath_type_t;

/**
 @brief define chip reset type
*/
enum ctc_chip_reset_type_e
{
    CTC_CHIP_RESET_TCAM_CORE,   /**< [HB]reset tcam core */
    CTC_CHIP_RESET_TCAM_POWER,  /**< [HB]reset tcam power */
    CTC_CHIP_RESET_GLB,         /**< [HB]reset glb */
    CTC_CHIP_RESET_DLLOCK,      /**< [HB]reset dllock */
    CTC_CHIP_RESET_PCI,         /**< [HB]reset pci */
    CTC_CHIP_RESET_SUP,         /**< [HB]reset sup */
    MAX_CTC_CHIP_RESET_RESET_TYPE
};
typedef enum ctc_chip_reset_type_e ctc_chip_reset_type_t;

/**
 @brief define cpumac speed
*/
enum ctc_cpumac_speed_e
{
    CTC_CPUMAC_SPEED_MODE_100M, /**<[HB.GB] indicate cpumac's speed is 100M  */
    CTC_CPUMAC_SPEED_MODE_1G,   /**<[HB.GB] indicate cpumac's speed is 1G  */
    CTC_CPUMAC_SPEED_MODE_MAX
};
typedef enum ctc_cpumac_speed_e ctc_cpumac_speed_t;

/**
 @brief define serdes mode of port
*/
enum ctc_serdes_mode_e
{
    CTC_SERDES_MODE_1G25,          /**<[HB]serdes 1.25Gbps mode */
    CTC_SERDES_MODE_3G125,         /**<[HB]serdes 3.125Gbps mode */
    CTC_SERDES_MODE_MAX
};
typedef enum ctc_serdes_mode_e ctc_serdes_mode_t;

/**
 @brief define chip datapath
*/
struct ctc_chip_datapath_s
{
    uint32  chip_id;                    /**< [HB]chip id */
    ctc_chip_type_t chip_type;          /**< [HB]chip type */
    ctc_cpumac_speed_t cpumac_speed;    /**< [HB]cpumac speed */
    ctc_chip_datapath_type_t  datapath; /**< [HB]datapath type */
    uint8 ptp_quanta;                   /**< [HB]ptp quanta */
};
typedef struct ctc_chip_datapath_s ctc_chip_datapath_t;

/**
 @brief define chip global configure
*/
struct ctc_chip_global_cfg_s
{
    uint8  lchip;                                   /**< [HB.GB] local chip id */
    uint8  cpu_port_en;                             /**< [GG] Network port as cpu port*/
    uint8  rsv[2];
    uint16 tpid;                                    /**< [GB.GG] TpId field in cpu port Tx packet */
    uint16 vlanid;                                  /**< [GB.GG] vlanId filed in cpu port Tx packet */
    mac_addr_t cpu_mac_sa;                          /**< [HB.GB.GG] cpu mac source address */
    mac_addr_t cpu_mac_da[MAX_CTC_CPU_MACDA_NUM];   /**< [HB.GB.GG] cpu mac destination address */
    uint32 cpu_port;                                /**< [GG] Network global port which is used for cpu port */

    uint8  cut_through_en;                          /**< [GB.GG] Enable cut through. 0: disable; 1: Enable */
    uint8  cut_through_speed;                       /**< [GB.GG] Cut through port speed.
                                                           [GB] 0:none; 1:1G; 2:10G; 3: mix supoort 1G and 10G
                                                           [GG] 1:10/40/100G mixed;2:1/10/100G mixed 3:1/10/40G mixed, else none */
    uint8  ecc_recover_en;                          /**< [GG] Enable ecc error recover */
    uint8  tcam_scan_en;                            /**< [GG] Enable tcam key scan and recover error */
};
typedef struct ctc_chip_global_cfg_s ctc_chip_global_cfg_t;

/**
 @brief define user mode for dynamic switch
*/
enum ctc_chip_datapath_mode_e
{
    CTC_CHIP_48G_PLUS_4TG,          /**<[HB] 48G+4XG mode */
    CTC_CHIP_36G_PLUS_6TG,          /**<[HB] 36G+6XG mode */
    CTC_CHIP_GLOBAL_MODE_MAX
};
typedef enum ctc_chip_datapath_mode_e ctc_chip_datapath_mode_t;

/**
 @brief define memory scan para
*/
struct ctc_chip_mem_scan_cfg_t
{
    uint8  tcam_scan_interval; /**<[GG] Time interval between every entire tcam scan, unit is minute, 0 means disable*/
    uint8  tcam_scan_mode;     /**<[GG] 0:Stop scanning after a scan, 1:Continuously scan, 0xFF means not set this function*/
    uint8  sbe_scan_interval;  /**<[GG] Time interval between every entire single bit error scan, unit is minute, 0 means disable*/
    uint8  sbe_scan_mode;      /**<[GG] 0:Stop scanning after a scan, 1:Continuously scan, 0xFF means not set this function*/
};
typedef struct ctc_chip_mem_scan_cfg_t ctc_chip_mem_scan_cfg_t;

/**
 @brief define ge phy para
*/
struct ctc_chip_gephy_para_s
{
    uint8 reg;           /**< [HB.GB.GG]the offset of the phy internal address */
    uint8 rsv;
    uint16 val;          /**< [HB.GB.GG]the value of the register */
};
typedef struct ctc_chip_gephy_para_s ctc_chip_gephy_para_t;

/**
 @brief define xg phy para
*/
struct ctc_chip_xgphy_para_s
{
    uint8   devno;       /**< [HB.GB]the device NO. of the xg phy*/
    uint16  reg;         /**< [HB.GB]the offset of the phy internal address */
    uint16  val;         /**< [HB.GB]the value of the register */
    uint8   rsv[2];
};
typedef struct ctc_chip_xgphy_para_s ctc_chip_xgphy_para_t;

/**
 @brief define mapping para
*/
struct ctc_chip_phy_mapping_para_s
{
    uint8   port_mdio_mapping_tbl[MAX_PORT_NUM_PER_CHIP];      /**< [HB.GB.GG]port and mdio mapping, index is local phy port */
    uint8   port_phy_mapping_tbl[MAX_PORT_NUM_PER_CHIP];       /**< [HB.GB.GG]port and mdio mapping, index is local phy port*/
};
typedef struct ctc_chip_phy_mapping_para_s ctc_chip_phy_mapping_para_t;

struct ctc_chip_gpio_params_s
{
    uint8   gpio_id;                        /**< [GG] gpio id */
    uint8   value   ;                       /**< [GG] input or output value */
    uint8   rsv[2];
};
typedef struct ctc_chip_gpio_params_s ctc_chip_gpio_params_t;

/**
 @brief define chip access type
*/
enum ctc_chip_access_type_e
{
    CTC_CHIP_PCI_ACCESS,    /**<[GB.GG] Pcie access type */
    CTC_CHIP_I2C_ACCESS,    /**<[GB.GG] I2C access type */

    CTC_CHIP_MAX_ACCESS_TYPE
};
typedef enum ctc_chip_access_type_e ctc_chip_access_type_t;

/**
 @brief define ge auto scan optinal register
*/
struct ctc_chip_ge_opt_reg_s
{
    uint8 intr_enable;                         /**<[GB.GG] whether to enable interrupt */
    uint8 reg;                                 /**<[GB.GG] special ge phy register for auto scan */
    uint8 bit_ctl;                             /**<[GB.GG] special ge phy register bit for auto scan */
    uint8 lchip;
};
typedef struct ctc_chip_ge_opt_reg_s  ctc_chip_ge_opt_reg_t;

/**
 @brief define xg auto scan optinal register
*/
struct ctc_chip_xg_opt_reg_s
{
    uint8 intr_enable;                     /**<[GB.GG] whether to enable interrupt */
    uint8 dev;                             /**<[GB.GG] special xg phy device type for auto scan */
    uint16 reg;                            /**<[GB.GG] special ge phy register for auto scan */
    uint8 bit_ctl;                         /**<[GB.GG] special ge phy register bit for auto scan */
    uint8 lchip;
    uint8 rsv[2];
};
typedef struct ctc_chip_xg_opt_reg_s ctc_chip_xg_opt_reg_t;

/**
 @brief define phy auto scan control parameter
*/
struct ctc_chip_phy_scan_ctrl_s
{
    uint32 op_flag;                     /**<[GB.GG] Flags indicate parameter type, zero means set all parameter */
    uint32 scan_interval;               /**<[GB.GG] interval for next phy scan, the unit is core frequency */
    uint32 mdio_use_phy0;               /**<[GB.GG] mac0~31 use phy or not, 1:use phy, link status come from externel phy; 0: not use phy, link status come from mac pcs layer */
    uint32 mdio_use_phy1;               /**<[GB.GG] mac 32~59, use phy or not */
    uint32 scan_gephy_bitmap0;          /**<[GB.GG] control which ge phy in mdio bus 0 will be scaned */
    uint32 scan_gephy_bitmap1;          /**<[GB.GG] control which ge phy in mdio bus 1 will be scaned */
    uint8  scan_xgphy_bitmap0;          /**<[GB.GG] control which xg phy in mdio bus 3 will be scaned */
    uint8  scan_xgphy_bitmap1;          /**<[GB.GG] control which xg phy in mdio bus 4 will be scaned */
    uint8  xgphy_link_bitmask;          /**<[GB.GG] control whether PMA,PCS or XS link status should mask */
    uint8  xgphy_scan_twice;            /**<[GB.GG] control whether xgphy should scan twice */
    uint8  lchip;
    uint8  ctl_id;                      /**<[GG] choose which slice, 0-slice0; 1-slice1 */
    uint8  rsv[2];
};
typedef struct ctc_chip_phy_scan_ctrl_s ctc_chip_phy_scan_ctrl_t;

/**
 @brief define phy auto scan control parameter type
*/
enum ctc_chip_phy_scan_type_e
{
    CTC_CHIP_INTERVAL_OP = 0x01,        /**<[GB.GG] to set phy scan interval parameter */
    CTC_CHIP_USE_PHY_OP = 0x02,         /**<[GB.GG] to set mdio use phy parameter */
    CTC_CHIP_GE_BITMAP_OP = 0x04,       /**<[GB.GG] to set ge phy bitmap parameter */
    CTC_CHIP_XG_BITMAP_OP = 0x08,       /**<[GB.GG] to set xg phy bitmap parameter */
    CTC_CHIP_XG_LINK_MASK_OP = 0x10,    /**<[GB.GG] to set xgphy device link mask parameter */
    CTC_CHIP_XG_TWICE_OP = 0x20         /**<[GB.GG] to set xgphy scan twice parameter */
};
typedef enum ctc_chip_phy_scan_type_e ctc_chip_phy_scan_type_t;

/**
 @brief define sfp auto scan control parameter type
*/
enum ctc_chip_sfp_scan_op_e
{
    CTC_CHIP_SFP_INTERVAL_OP = 0x01,        /**<[GB] to set i2c scan interval parameter */
    CTC_CHIP_SFP_BITMAP_OP = 0x02,          /**<[GB] to set i2c device biitmap parameter */
    CTC_CHIP_SFP_SCAN_REG_OP = 0x04         /**<[GB] to set which space to scan for i2c device */
};
typedef enum ctc_chip_sfp_scan_op_e ctc_chip_sfp_scan_op_t;

#define CTC_CHIP_MAC_BITMAP     2
/**
 @brief define sfp auto scan control parameter
*/
struct ctc_chip_i2c_scan_s
{
    uint8   ctl_id;                     /**<[GG] i2c master control id <0-1>  */
    uint32  op_flag;                    /**<[GB] Flags indicate parameter type, zero means set all parameter */
    uint32  slave_bitmap[CTC_CHIP_MAC_BITMAP];               /**<[GB.GG] bit map for slave device to scan */
    uint16  dev_addr;                   /**<[GB] slave device address */
    uint8   offset;                     /**<[GB] offset in slave devie for scan */
    uint8   length;                     /**<[GB] scan length */
    uint32  interval;                   /**<[GB] interval for next round scan, the unit is sup clock cycle */
    uint8   lchip;
    uint8   i2c_switch_id;               /**<[GG] interval for next round scan, the unit is sup clock cycle */
    uint8   rsv[2];
};
typedef struct ctc_chip_i2c_scan_s ctc_chip_i2c_scan_t;

/**
 @brief define sfp read para
*/
struct ctc_chip_i2c_read_s
{
    uint8 ctl_id;                       /**<[GG] i2c master control id <0-1>  */
    uint8 slave_dev_id;                 /**<[GG] slave device id */
    uint16 dev_addr;                    /**<[GB.GG] slave device address */
    uint32 slave_bitmap;                /**<[GB] bit map for slave device to scan */
    uint8  offset;                      /**<[GB.GG] offset in slave devie for scan */
    uint8  length;                      /**<[GB.GG] scan length */
    uint8 lchip;                        /**<[GB.GG] local chip id */
    uint8 i2c_switch_id;                /**<[GG] for dev like pca9548a, set 0 mean disable */
    uint8* p_buf;                       /**<[GB.GG] buffer for store read data result */
    uint32 buf_length;                  /**<[GG] buffer length */
};
typedef struct ctc_chip_i2c_read_s ctc_chip_i2c_read_t;

/**
 @brief define polling read
*/
struct ctc_chip_i2c_scan_read_s
{
    uint8 ctl_id;                       /**<[GG] i2c master control id <0-1> */
    uint8 gchip;                        /**<[GG] global chip id */
    uint8 rsv[2];
    uint32 len;                         /**<[GG] buffer length */
    uint8* p_buf;                       /**<[GG] buffer pointer */
};
typedef struct ctc_chip_i2c_scan_read_s ctc_chip_i2c_scan_read_t;

/**
 @brief define sfp write para
*/
struct ctc_chip_i2c_write_s
{
    uint8 ctl_id;                       /**<[GG] i2c master control id <0-1> */
    uint8 rsv;
    uint16 dev_addr;                    /**<[GB.GG] slave device address */
    uint8  offset;                      /**<[GB.GG] offset in slave devie for scan */
    uint8  slave_id;                    /**<[GB.GG] slave device id */
    uint8  data;                        /**<[GB.GG] data to write */
    uint8  lchip;                       /**<[GB.GG] local chip id */
    uint8  i2c_switch_id;               /**<[GG] for dev like pca9548a, set 0 mean disable */
};
typedef struct ctc_chip_i2c_write_s ctc_chip_i2c_write_t;

/**
 @brief define mac led type
*/
enum ctc_chip_mac_led_type_e
{
    CTC_CHIP_USING_ONE_LED,       /**<[GB.GG] using one led for mac status */
    CTC_CHIP_USING_TWO_LED,       /**<[GB.GG] using two led for mac status */

    CTC_CHIP_MAX_LED_TYPE
};
typedef enum ctc_chip_mac_led_type_e ctc_chip_mac_led_type_t;

/**
 @brief define mac led mode
*/
enum ctc_chip_led_mode_e
{
    CTC_CHIP_RXLINK_MODE,                   /**<[GB.GG]  led on when rx link up, led off when rx link down, not blind */
    CTC_CHIP_TXLINK_MODE,                   /**<[GB.GG]  led on when tx link up, led off when tx link down, not blind, only for 10g mac */
    CTC_CHIP_RXLINK_RXACTIVITY_MODE,        /**<[GB.GG]  led on when rx link up, led off when rx link down, led blind when rx activity */
    CTC_CHIP_TXLINK_TXACTIVITY_MODE,        /**<[GB.GG]  led on when tx link up, led off when tx link down, led blind when tx activity, only for 10g */
    CTC_CHIP_RXLINK_BIACTIVITY_MODE,        /**<[GB.GG]  led on when rx link up, off when rx link down, led blind when rx or tx activity */
    CTC_CHIP_TXACTIVITY_MODE,               /**<[GB.GG]  led always off, led blind when tx activity */
    CTC_CHIP_RXACTIVITY_MODE,               /**<[GB.GG]  led always off, led blind when rx activity */
    CTC_CHIP_BIACTIVITY_MODE,               /**<[GB.GG]  led always off, led blind when rx or tx activity */
    CTC_CHIP_FORCE_ON_MODE,                 /**<[GB.GG]  led always on, not blind  */
    CTC_CHIP_FORCE_OFF_MODE,                /**<[GB.GG]  led always off, not blind  */

    CTC_CHIP_MAC_LED_MODE
};
typedef enum ctc_chip_led_mode_e ctc_chip_led_mode_t;

/**
 @brief define mac led para
*/
struct ctc_chip_led_para_s
{
    uint32 op_flag;                             /**<[GB.GG] Flags indicate parameter type, zero means set all parameter */
    uint16 port_id;                             /**<[GB.GG]  mac id */
    uint8  lchip;
    uint8  ctl_id;                              /**<[GG] mac led control id <0-1> */
    uint32 polarity;                            /**<[GB.GG] config led driver polarity */
    ctc_chip_led_mode_t  first_mode;            /**<[GB.GG] first mac led mode */
    ctc_chip_led_mode_t  sec_mode;              /**<[GB.GG] second mac led mode, only use when using two leds */
};
typedef struct ctc_chip_led_para_s ctc_chip_led_para_t;

/**
 @brief define mac led para set type
*/
enum ctc_chip_mac_led_op_e
{
    CTC_CHIP_LED_MODE_SET_OP = 0x01,           /**<[GB]  to set mac led mode parameter */
    CTC_CHIP_LED_POLARITY_SET_OP = 0x02        /**<[GB]  to set mac led polarity parameter, must acording hardware design */
};
typedef enum ctc_chip_mac_led_op_e ctc_chip_mac_led_op_t;

/**
 @brief define mac led mapping
*/
struct ctc_chip_mac_led_mapping_s
{
    uint8* p_mac_id;                            /**<[GB.GG] mac id for mac led sequence, the size must be adjusted to mac_led_num parameter */
    uint8 mac_led_num;                          /**<[GB.GG] how many mac led should be used */
    uint8 lchip;
    uint8 ctl_id;                               /**<[GG] mac led control id <0-1> */
    uint8 rsv[1];
};
typedef struct ctc_chip_mac_led_mapping_s ctc_chip_mac_led_mapping_t;

/**
 @brief define gpio mode
*/
enum ctc_chip_gpio_mode_e
{
    CTC_CHIP_INPUT_MODE,            /**<[GB.GG] gpio used as input */
    CTC_CHIP_OUTPUT_MODE,           /**<[GB.GG] gpio used as output */
    CTC_CHIP_SPECIAL_MODE,          /**<[GB] gpio used as specail function */

    CTC_CHIP_MAX_GPIO_MODE
};
typedef enum ctc_chip_gpio_mode_e ctc_chip_gpio_mode_t;

enum ctc_chip_serdes_mode_e
{
    CTC_CHIP_SERDES_NONE_MODE,               /**<[GG] serdes is useless */
    CTC_CHIP_SERDES_XFI_MODE,                /**<[GB.GG] config serdes to XFI mode */
    CTC_CHIP_SERDES_SGMII_MODE,              /**<[GB.GG] config serdes to SGMII mode */
    CTC_CHIP_SERDES_XSGMII_MODE,             /**<[GB] config serdes to XSGMII mode */
    CTC_CHIP_SERDES_QSGMII_MODE,             /**<[GB] config serdes to QSGMII mode */
    CTC_CHIP_SERDES_XAUI_MODE,               /**<[GB.GG] config serdes to XAUI mode */
    CTC_CHIP_SERDES_DXAUI_MODE,              /**<[GG] config serdes to D-XAUI mode */
    CTC_CHIP_SERDES_XLG_MODE,                /**<[GG] config serdes to xlg mode */
    CTC_CHIP_SERDES_CG_MODE,                 /**<[GG] config serdes to cg mode */
    CTC_CHIP_SERDES_2DOT5G_MODE,             /**<[GG] config serdes to 2.5g mode */

    CTC_CHIP_MAX_SERDES_MODE
};
typedef enum ctc_chip_serdes_mode_e ctc_chip_serdes_mode_t;

struct ctc_chip_serdes_info_s
{
    uint8 serdes_id;                              /**<[GB.GG] serdes id */
    uint8 rsv[3];
    ctc_chip_serdes_mode_t serdes_mode;           /**<[GB.GG] serdes mode */
};
typedef struct ctc_chip_serdes_info_s ctc_chip_serdes_info_t;

enum ctc_chip_mdio_type_e
{
    CTC_CHIP_MDIO_GE,               /**<[GB.GG] 1G phy */
    CTC_CHIP_MDIO_XG,               /**<[GB.GG] 10G phy */
    CTC_CHIP_MDIO_XGREG_BY_GE       /**<[GB.GG] accecc 10 phy by 1G bus */
};
typedef enum ctc_chip_mdio_type_e ctc_chip_mdio_type_t;

struct ctc_chip_mdio_para_s
{
    uint8 ctl_id;               /**<[GG] mdio control id <0-1> */
    uint8 bus;                  /**<[GB.GG] bus id */
    uint8 phy_addr;             /**<[GB.GG] phy address */
    uint8 rsv;
    uint16 reg;                 /**<[GB.GG] register address */
    uint16 value;               /**<[GB.GG] config vlaue */
    uint16 dev_no;              /**<[GB.GG] only usefull for xgphy */
    uint8 rsv1[2];
};
typedef struct ctc_chip_mdio_para_s ctc_chip_mdio_para_t;

enum ctc_chip_sensor_type_e
{
    CTC_CHIP_SENSOR_TEMP,           /**<[GB.GG] sensor chip temperature */
    CTC_CHIP_SENSOR_VOLTAGE         /**<[GB.GG] sensor chip voltage */
};
typedef enum ctc_chip_sensor_type_e ctc_chip_sensor_type_t;

enum ctc_chip_serdes_prbs_polynome_e
{
    CTC_CHIP_SERDES_PRBS7_PLUS,     /**<[GB.GG] prbs mode PRBS7+ */
    CTC_CHIP_SERDES_PRBS7_SUB,      /**<[GB.GG] prbs mode PRBS7- */
    CTC_CHIP_SERDES_PRBS15_PLUS,    /**<[GB.GG] prbs mode PRBS15+ */
    CTC_CHIP_SERDES_PRBS15_SUB,     /**<[GB.GG] prbs mode PRBS15- */
    CTC_CHIP_SERDES_PRBS23_PLUS,    /**<[GB.GG] prbs mode PRBS23+ */
    CTC_CHIP_SERDES_PRBS23_SUB,     /**<[GB.GG] prbs mode PRBS23- */
    CTC_CHIP_SERDES_PRBS31_PLUS,    /**<[GB.GG] prbs mode PRBS31+ */
    CTC_CHIP_SERDES_PRBS31_SUB      /**<[GB.GG] prbs mode PRBS31- */
};
typedef enum ctc_chip_serdes_prbs_polynome_e ctc_chip_serdes_polynome_type_t;

struct ctc_chip_serdes_prbs_s
{
    uint8 serdes_id;                    /**<[GB.GG] serdes ID */
    uint8 polynome_type;                /**<[GB.GG] relate to ctc_chip_serdes_polynome_type_t */
    uint8 mode;                         /**<[GB.GG] 0--Rx, 1--Tx */
    uint8 value;                        /**<[GB.GG] used for tx, 0--tx disable, 1--tx enable; used for rx, is check result, 1 is "ok", other value is "fail" */
};
typedef struct ctc_chip_serdes_prbs_s ctc_chip_serdes_prbs_t;

struct ctc_chip_serdes_loopback_s
{
   uint8 serdes_id;                     /**<[GB.GG] serdes ID */
   uint8 enable;                        /**<[GB.GG] 1--enable, 0--disable */
   uint8 mode;                          /**<[GB.GG] loopback mode, 0--interal, 1--external */
};
typedef struct ctc_chip_serdes_loopback_s ctc_chip_serdes_loopback_t;

enum ctc_chip_property_e
{
    CTC_CHIP_PROP_SERDES_FFE,           /**<[GB.GG] config serdes ffe parameter */
    CTC_CHIP_PEOP_SERDES_POLARITY,      /**<[GG] config serdes polarity */
    CTC_CHIP_PROP_SERDES_PRBS,          /**<[GB.GG] config serdes prbs */
    CTC_CHIP_PROP_SERDES_LOOPBACK,      /**<[GB.GG] config serdes loopback */
    CTC_CHIP_PROP_SERDES_RX_PEAKING,    /**<[GG] when optical using Pre-emphasis mode, for trace length
                                                      too short serdes, need config this mode to reduce rx peaking */
    CTC_CHIP_PROP_EEE_EN,               /**<[GB] enable eee globally */
    CTC_CHIP_PHY_SCAN_EN,               /**<[GB] enable phy scan */
    CTC_CHIP_I2C_SCAN_EN,               /**<[GB] enable I2C Master scan */
    CTC_CHIP_MAC_LED_EN,                /**<[GB.GG] enable Mac Led */
    CTC_CHIP_PROP_MEM_SCAN,             /**<[GB.GG] enable tcam key and single bit error scan */
    CTC_CHIP_PROP_GPIO_MODE,            /**<[GG] set GPIO working mode ctc_chip_gpio_mode_t */
    CTC_CHIP_PROP_GPIO_OUT,             /**<[GG] write Value onto the GPIO with ctc_chip_gpio_params_t */
    CTC_CHIP_PROP_GPIO_IN,              /**<[GG] read Value from the GPIO with ctc_chip_gpio_params_t */
    CTC_CHIP_PROP_PHY_MAPPING,          /**<[GG] set mdio and phy mapping relation, Value is a pointer to ctc_chip_phy_mapping_para_t */

    CTC_CHIP_PROP_DEVICE_INFO,          /**<[GB.GG] chip device information */

    CTC_CHIP_PROP_MAX_TYPE
};
typedef enum ctc_chip_property_e ctc_chip_property_t;

enum ctc_chip_serdes_ffe_mode_e
{
    CTC_CHIP_SERDES_FFE_MODE_TYPICAL,  /**<[GB.GG] config ffe by motherboard material and trace length */
    CTC_CHIP_SERDES_FFE_MODE_DEFINE,   /**<[GB.GG] config ffe by user define value, this mode is traditional mode, support copper and fiber */
    CTC_CHIP_SERDES_FFE_MODE_3AP       /**<[GG] config ffe by user define value, this mode is 802.3ap mode, only support copper */
};
typedef enum ctc_chip_serdes_ffe_mode_e ctc_chip_serdes_ffe_mode_t;

struct ctc_chip_serdes_ffe_s
{
    uint8  rsv[2];
    uint8  serdes_id;                                       /**<[GB.GG] serdes id */
    uint8  mode;                                            /**<[GB.GG] relate to ctc_chip_serdes_mode_t */
    uint16 board_material;                                  /**<[GB.GG] motherboard material: 0--FR4, 1--M4, 2--M6 */
    uint16 trace_len;                                       /**<[GB.GG] trace length: 0-- (0~4)inch, 1--(4~7)inch, 2--(7~10)inch */
    uint16 coefficient[CTC_CHIP_FFE_PARAM_NUM];             /**<[GB.GG] coefficient value */
};
typedef struct ctc_chip_serdes_ffe_s ctc_chip_serdes_ffe_t;

struct ctc_chip_serdes_polarity_s
{
    uint8 dir;                          /**<[GG] 0:rx, 1:tx */
    uint8 serdes_id;                    /**<[GG] serdes id */
    uint16 polarity_mode;               /**<[GG] 0:normal, 1:Reverse*/
};
typedef struct ctc_chip_serdes_polarity_s ctc_chip_serdes_polarity_t;

struct ctc_chip_serdes_peaking_s
{
    uint8 serdes_id;            /**<[GG] serdes id */
    uint8 rsv;
    uint16 enable;              /**<[GG] 0:disable, 1:enable*/
};
typedef struct ctc_chip_serdes_peaking_s ctc_chip_serdes_peaking_t;

typedef int32 (* ctc_chip_reset_cb)(uint8 type, uint32 flag);
/**@} end of @defgroup chip  */

/**
 @defgroup datapath
 @{
*/

struct ctc_datapath_serdes_prop_s
{
    uint8 mode;                 /**<[GG]refer to ctc_chip_serdes_mode_t */
    uint8 is_dynamic;           /**<[GG]serdes support dynamic switch */
    uint8 rx_polarity;          /**<[GG]serdes rx polarity is reversed or not,  0:normal, 1:Reverse */
    uint8 tx_polarity;          /**<[GG]serdes tx polarity is reversed or not,  0:normal, 1:Reverse */
};
typedef struct ctc_datapath_serdes_prop_s ctc_datapath_serdes_prop_t;

struct ctc_datapath_global_cfg_s
{
    uint16 core_frequency_a;            /**<[GG]for core plla */
    uint16 core_frequency_b;            /**<[GG]for core pllb */
    ctc_datapath_serdes_prop_t serdes[CTC_DATAPATH_SERDES_NUM];
};
typedef struct ctc_datapath_global_cfg_s ctc_datapath_global_cfg_t;

struct ctc_chip_device_info_s
{
    uint16 device_id;                           /**<[GB.GG]chip device ID */
    uint16 version_id;                          /**<[GB.GG]chip version ID */

    char chip_name[CTC_MAX_CHIP_NAME_LEN];      /**<[GB.GG]chip name */
};
typedef struct ctc_chip_device_info_s ctc_chip_device_info_t;

/**@} end of @defgroup datapath  */

#ifdef __cplusplus
}
#endif

#endif

