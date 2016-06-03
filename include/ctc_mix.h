/**
 @file ctc_mix.h

 @date 2009-10-27

 @version v2.0

The file define  chipset  independent common Macros and constant.
*/

#ifndef _CTC_MIX_H
#define _CTC_MIX_H
#ifdef __cplusplus
extern "C" {
#endif


#if defined (GREATBELT)
#define CTC_CURRENT_CHIP                "GreatBelt"

#define CTC_MAX_LOCAL_CHIP_NUM          2
#define CTC_MAX_PHY_PORT                60
#define CTC_MAX_VRFID_ID                255           /**< Max vrfid id */
#define CTC_MAX_LINKAGG_GROUP_NUM       64            /**< Max Linkagg group num */
#define MAX_PORT_NUM_PER_CHIP           128           /**< Max port num per chip */
#define CTC_MAX_ECPN                    16            /**< Maximum equal cost path number */
#define CTC_IP_MAX_RPF_IF               16            /**< Define max RPF interfaces that ipuc and ipmc supports*/
#define CTC_MAX_GPORT_ID                0x1F3F        /**< Max global port Id */
#define MIN_CTC_L3IF_ID                 1             /**< Min value of layer 3 interface ID */
#define MAX_CTC_L3IF_ID                 1022          /**< Max value of layer 3 interface ID */
#define CTC_MAX_APS_GROUP_NUM           1024          /**< Max aps group num */
#define CTC_DEFAULT_MAX_ECMP_NUM        8             /**< By default,Maximum equal cost path number */
#define CTC_ACL_PORT_BITMAP_MAX_NUM     52

#define CTC_ACL_PORT_CLASSID_MAX        1023          /**< Max port classid*/
#define CTC_ACL_PORT_CLASSID_MIN        1             /**< Min port classid*/

#define CTC_SCL_PORT_CLASSID_MAX        61            /**< Max port classid*/
#define CTC_SCL_PORT_CLASSID_MIN        1             /**< Min port classid*/

#define CTC_ACL_VLAN_CLASSID_MAX        1023          /**< Max vlan classid*/
#define CTC_ACL_VLAN_CLASSID_MIN        1             /**< Min vlan classid*/

#define CTC_PKT_CPUMAC_LEN              20            /**< [GB] CPUMAC Header Length: MACDA(6) + MACSA(6) + VLAN(4) + Type(2) + Reserved(2) */
#define CTC_PKT_HEADER_LEN              32            /**< [GB] Packet Header Length */
#define CTC_LPORT_CPU                   0x10000000    /**< [GB] cpu local phy port, refer to DRV_DATA_PATH_CPU_LPORT */
#define CTC_LPORT_OAM                   64            /**< [GB] oam local phy port, refer to DRV_DATA_PATH_OAM_LPORT */
#define CTC_GPORT_RCPU(gchip)           (0x10000000 | (((gchip) & CTC_GCHIP_MASK) << CTC_LOCAL_PORT_LENGTH))
#define MAX_CTC_CPU_MACDA_NUM           4             /**< [GB]define cpu macda number */
#define CTC_MAX_LINKAGG_ID              0x3F          /**< [GB]define max linkagg id identified by GPORT low 8bit.*/
#define CTC_MAX_CPU_REASON_GROUP_NUM    16            /**< MAX CPU Reason number.*/
#define CTC_MAX_QNUM_PER_GROUP          8             /**< MAX Queue number in one Queue Group.*/
#define CTC_INTR_MAX_GROUP              6             /**< max number of interrupt groups/PINs/IRQs */
#define CTC_LINKAGGID_MASK              0x1F          /**< Linkagg ID mask */
#define CTC_IPUC_IP_TUNNEL_MAX_IF_NUM   4             /**< Max rpf check interface id number */
#define CTC_DATAPATH_SERDES_NUM         48
#define CTC_IPMC_RP_INTF                16             /**< Define rp interface that an ipmc group add one time*/
#define CTC_IPMC_MAX_RPF_IF             16           /**< Define max RPF interface that an ipmc group supports*/
#define CTC_CHIP_FFE_PARAM_NUM          4              /** serses ffe coefficient reg num */
#endif /*!GREATBELT*/

#if defined (GOLDENGATE) || defined (DUET2)
#ifdef GOLDENGATE
#define CTC_CURRENT_CHIP                "GoldenGate"
#define MAX_PORT_NUM_PER_CHIP           512           /**< Max port num per chip */
#else
#define CTC_CURRENT_CHIP                "Duet2"
#define MAX_PORT_NUM_PER_CHIP           256           /**< Max port num per chip */
#endif
#define CTC_MAX_LOCAL_CHIP_NUM          30
#define CTC_MAX_PHY_PORT                128
#define CTC_MAX_VRFID_ID                255           /**< Max vrfid id */
#define CTC_MAX_LINKAGG_GROUP_NUM       64            /**< Max Linkagg group num */
#define CTC_MAX_ECPN                    64            /**< Maximum equal cost path number */
#define CTC_IPMC_RP_INTF                16             /**< Define rp interface that an ipmc group add one time*/
#define CTC_IP_MAX_RPF_IF               16            /**< Define max RPF interfaces that ipuc and ipmc supports*/
#define MIN_CTC_L3IF_ID                 1             /**<  Min value of layer 3 interface ID */
#define MAX_CTC_L3IF_ID                 1022          /**<  Max value of layer 3 interface ID */
#define CTC_MAX_APS_GROUP_NUM           2048          /**< Max aps group num */
#define CTC_DEFAULT_MAX_ECMP_NUM        16            /**< By default,Maximum equal cost path number */
#define CTC_ACL_PORT_BITMAP_MAX_NUM     128

#define CTC_ACL_PORT_CLASSID_MAX        255           /**< Max port classid*/
#define CTC_ACL_PORT_CLASSID_MIN        1             /**< Min port classid*/

#define CTC_SCL_PORT_CLASSID_MAX        255           /**< Max port classid*/
#define CTC_SCL_PORT_CLASSID_MIN        1             /**< Min port classid*/

#define CTC_ACL_VLAN_CLASSID_MAX        255           /**< Max vlan classid*/
#define CTC_ACL_VLAN_CLASSID_MIN        1             /**< Min vlan classid*/

#define CTC_PKT_CPUMAC_LEN              18            /**< CPUMAC Header Length: MACDA(6) + MACSA(6) + VLAN(4) + Type(2) */
#define CTC_PKT_HEADER_LEN              40            /**< Packet Header Length */
#define CTC_LPORT_CPU                   0x10000000
#define CTC_GPORT_RCPU(gchip)           (0x10000000 | (((gchip) & CTC_GCHIP_MASK) << CTC_LOCAL_PORT_LENGTH))
#define MAX_CTC_CPU_MACDA_NUM           4             /**< Define cpu macda number */
#define CTC_MAX_LINKAGG_ID              0x3F          /**< Define max linkagg id identified by GPORT low 8bit. */

#define CTC_MLAG_ISOLATION_GROUP        31            /**< [GG] MLAG isolation group id */

#define MAX_RESERVED_PORT               32            /**< [GG] reserved for internal port use */
#define MAX_NORMAL_PANNEL_PORT          96            /**< [GG] when disable extent port, support 96 normal pannel port */
#define MAX_EXTEND_PANNEL_PORT          384           /**< [GG] when enable extent port, support 384 extend pannel port */

#define CTC_NORMAL_PANNEL_PORT_BASE0    0             /**< [GG] Normal pannel port base*/
#define CTC_NORMAL_PANNEL_PORT_BASE1    64            /**< [GG] Normal pannel port base*/

#define CTC_EXTEND_PANNEL_PORT_BASE0    128           /**< [GG] Extend pannel port base*/
#define CTC_EXTEND_PANNEL_PORT_BASE1    320           /**< [GG] Extend pannel port base*/
#define CTC_MAX_CPU_REASON_GROUP_NUM    16             /**< MAX CPU Reason number.*/
#define CTC_MAX_QNUM_PER_GROUP          8             /**< MAX Queue number in one Queue Group.*/
#define CTC_INTR_MAX_GROUP              8             /**< max number of interrupt groups/PINs/IRQs */
#define CTC_LINKAGGID_MASK              0x3F          /**< Linkagg ID mask */
#define CTC_DATAPATH_SERDES_NUM         96
#define CTC_IPUC_IP_TUNNEL_MAX_IF_NUM   8             /**< Max rpf check interface id number */
#define CTC_CHIP_FFE_PARAM_NUM          4              /** serses ffe coefficient reg num */
#endif /*!GOLDENGATE*/

#ifdef HUMBER

#define CTC_CURRENT_CHIP                "Humber"
#define CTC_MAX_CHIP_NUM_PER_LC         2
#define CTC_MAX_LOCAL_CHIP_NUM          2
#define CTC_MAX_PHY_PORT                52
#define CTC_MAX_HUMBER_CHIP_NUM         32
#define CTC_MAX_HUMBER_PHY_PORT         52
#define CTC_MAX_VRFID_ID                65535       /**< Max vrfid id */
#define CTC_MAX_LINKAGG_GROUP_NUM       128         /**< Max Linkagg group num */
#define MAX_PORT_NUM_PER_CHIP           256         /**< Max port num per chip */
#define CTC_IPMC_MAX_RPF_IF             4           /**< Define max RPF interface that an ipmc group supports*/
#define CTC_MAX_GPORT_ID                0x1F7F      /**< Max global port Id */
#define MIN_CTC_L3IF_ID                 0           /**< Min value of layer 3 interface ID */
#define MAX_CTC_L3IF_ID                 1022        /**< Max value of layer 3 interface ID */
#define MAX_CTC_L3IF_ID_FOR_PHY_SUB_IF  511         /**< Max value of Phy-if and sub-if  ID*/
#define CTC_L3IF_INVALID_L3IF_ID        0x3FF       /**< Invalid value of layer 3 interface ID */
#define CTC_MAX_APS_GROUP_NUM           2048        /**< Max aps group num */

#define CTC_MAX_ECPN                    8           /**< Maximum equal cost path number */
#define CTC_DEFAULT_MAX_ECMP_NUM        8           /**< By default,Maximum equal cost path number */

#define CTC_ACL_PORT_CLASSID_MAX        127         /**< Max port classid*/
#define CTC_ACL_PORT_CLASSID_MIN        0           /**< Min port classid*/

#define CTC_ACL_VLAN_CLASSID_MAX        127         /**< Max vlan classid*/
#define CTC_ACL_VLAN_CLASSID_MIN        0           /**< Min vlan classid*/

#define CTC_PKT_CPUMAC_LEN              16          /**< [HB] CPUMAC Header Length: MACDA(6) + MACSA(6) + Type(2) + Reserved(2) */
#define CTC_PKT_HEADER_LEN              32          /**< [HB] Packet Header Length */
#define CTC_LPORT_CPU                   53
#define CTC_LPORT_OAM                   54
#define MAX_CTC_CPU_MACDA_NUM           8           /**< [HB]define cpu macda number */
#define CTC_MAX_LINKAGG_ID              0x7F        /**< [HB]define max linkagg id identified by GPORT low 8bit.*/

#endif /*!HUMBER*/

#ifdef __cplusplus
}
#endif

#endif /* _CTC_MIX_H*/

