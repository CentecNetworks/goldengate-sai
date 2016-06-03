/**
 @file drv_lib.h

 @date 2010-02-25

 @version v5.1

 The file implement include all driver .h files
*/

#ifndef _DRV_LIB_H_
#define _DRV_LIB_H_

/* humber driver's include file */
#include "drv_cfg.h"
#include "drv_enum.h"
#include "drv_common.h"
#include "drv_tbl_reg.h"
#include "drv_tbl_macro.h"
#include "drv_chip_info.h"
#include "drv_acc.h"
#include "drv_io.h"
#include "drv_error.h"
#include "drv_model_io.h"
#include "drv_chip_io.h"
#include "drv_model_hash.h"
#include "drv_hash_calculate.h"
#include "drv_hash_db.h"
#include "drv_model_dma.h"
#include "drv_ecc_recover.h"


#define DS_FIB_HOST0_MAC_HASH_KEY_BYTES sizeof(DsFibHost0MacHashKey_m)
#define DS_FIB_HOST0_IPV6_UCAST_HASH_KEY_BYTES sizeof(DsFibHost0Ipv6UcastHashKey_m)
#define DS_FIB_HOST0_HASH_CAM_BYTES sizeof(DsFibHost0HashCam_m)
#define DS_FIB_HOST1_HASH_CAM_BYTES sizeof(DsFibHost1HashCam_m)
#define DS_USER_ID_HASH_CAM_BYTES sizeof(DsUserIdHashCam_m)
#define DS_EGRESS_XC_OAM_HASH_CAM_BYTES sizeof(DsEgressXcOamHashCam_m)
#define DS_FLOW_HASH_CAM_BYTES sizeof(DsFlowHashCam_m)

#define DS_MET_ENTRY3_W_BYTES sizeof(DsMetEntry3W_m)
#define DS_MET_ENTRY6_W_BYTES sizeof(DsMetEntry6W_m)
#define DS_NEXT_HOP4_W_BYTES sizeof(DsNextHop4W_m)
#define DS_NEXT_HOP8_W_BYTES sizeof(DsNextHop8W_m)
#define FLOW_TCAM_CPU_REQ_CTL_BYTES sizeof(FlowTcamCpuReqCtl_m)
#define FLOW_TCAM_CPU_WR_DATA_BYTES sizeof(FlowTcamCpuWrData_m)
#define LPM_TCAM_IP_CPU_REQ_CTL_BYTES sizeof(LpmTcamIpCpuReqCtl_m)
#define LPM_TCAM_IP_CPU_WR_DATA_BYTES sizeof(LpmTcamIpCpuWrData_m)
#define LPM_TCAM_NAT_CPU_REQ_CTL_BYTES sizeof(LpmTcamNatCpuReqCtl2_m)
#define LPM_TCAM_NAT_CPU_WR_DATA_BYTES sizeof(LpmTcamNatCpuWrData2_m)
#define FLOW_TCAM_AD_MEM_BYTES sizeof(FlowTcamAdMem_m)
#define IPE_FWD_DISCARD_TYPE_STATS_BYTES sizeof(IpeFwdDiscardTypeStats0_m)
#define EPE_HDR_EDIT_DISCARD_TYPE_STATS_BYTES sizeof(EpeHdrEditDiscardTypeStats0_m)
#define FLOW_TCAM_LOOKUP_CTL_BYTES sizeof(FlowTcamLookupCtl_m)
#define LPM_TCAM_IP_CTL_BYTES sizeof(LpmTcamIpCtl_m)
#define OAM_UPDATE_APS_CTL_BYTES sizeof(OamUpdateCtl_m)
#define OAM_ETHER_CCI_CTL_BYTES sizeof(OamEtherCciCtl_m)
#define OAM_UPDATE_APS_CTL_BYTES sizeof(OamUpdateCtl_m)
#define OAM_ETHER_CCI_CTL_BYTES sizeof(OamEtherCciCtl_m)
#define DS_EGRESS_XC_OAM_RMEP_HASH_KEY_BYTES sizeof(DsEgressXcOamRmepHashKey_m)

#define DS_LPM_LOOKUP_KEY_BYTES sizeof(DsLpmLookupKey_m)
#define DS_LPM_TCAM_AD0_BYTES sizeof(DsLpmTcamAd0_m)
#define DS_LPM_TCAM_IPV6160_KEY0_BYTES sizeof(DsLpmTcamIpv6160Key0_m)
#define DS_LPM_TCAM_IPV440_KEY_BYTES sizeof(DsLpmTcamIpv440Key_m)
#define DS_IPFIX_L3_IPV6_HASH_KEY_BYTES sizeof(DsIpfixL3Ipv6HashKey_m)
#define DS_IPFIX_SESSION_RECORD_BYTES sizeof(DsIpfixSessionRecord_m)
#define DS_FIB_HOST0_FCOE_HASH_KEY_BYTES sizeof(DsFibHost0FcoeHashKey_m)

#define RLM_AD_CTL_RESET0_ADDR                                       0x30000020
#define RLM_AD_CTL_RESET1_ADDR                                       0x50000020
#define RLM_BR_PB_CTL_RESET_ADDR                                     0x04000020
#define RLM_BS_CTL_RESET_ADDR                                        0x00600050
#define RLM_CS_CTL_EN_CLK0_ADDR                                      0x20200050
#define RLM_CS_CTL_EN_CLK1_ADDR                                      0x40200050
#define RLM_CS_CTL_RESET0_ADDR                                       0x20200020
#define RLM_CS_CTL_RESET1_ADDR                                       0x40200020
#define RLM_DEQ_CTL_RESET_ADDR                                       0x00200020
#define RLM_ENQ_CTL_RESET_ADDR                                       0x00040030
#define RLM_EPE_CTL_RESET0_ADDR                                      0x20400020
#define RLM_EPE_CTL_RESET1_ADDR                                      0x40400020
#define RLM_HASH_CTL_RESET0_ADDR                                     0x28000020
#define RLM_HASH_CTL_RESET1_ADDR                                     0x48000020
#define RLM_HS_CTL_EN_CLK0_ADDR                                      0x20100050
#define RLM_HS_CTL_EN_CLK1_ADDR                                      0x40100050
#define RLM_HS_CTL_RESET0_ADDR                                       0x20100020
#define RLM_HS_CTL_RESET1_ADDR                                       0x40100020
#define RLM_IPE_CTL_RESET0_ADDR                                      0x20300030
#define RLM_IPE_CTL_RESET1_ADDR                                      0x40300030
#define RLM_NET_CTL_EN_CLK0_ADDR                                     0x20000040
#define RLM_NET_CTL_EN_CLK1_ADDR                                     0x40000040
#define RLM_NET_CTL_RESET0_ADDR                                      0x20000000
#define RLM_NET_CTL_RESET1_ADDR                                      0x40000000
#define RLM_SHARE_DS_CTL_RESET_ADDR                                  0x01000050
#define RLM_SHARE_TCAM_CTL_RESET_ADDR                                0x00400030
#define SHARED_PCS_SOFT_RST0_ADDR                                    0x201014f0
#define SHARED_PCS_SOFT_RST8_ADDR                                    0x202010f0
#define SHARED_PCS_SOFT_RST12_ADDR                                   0x401014f0
#define SHARED_PCS_SOFT_RST20_ADDR                                   0x402010f0
#define SUP_RESET_CTL_ADDR                                           0x00020070
#define DMA_PKT_RX_STATS0_ADDR                                       0x00016000
#define RA_QUE_CNT_ADDR                                              0x00052000
#define OAM_DS_MP_DATA_ADDR                                          0x00700000




#define   DYNAMIC_DS_EDRAM4_W_OFFSET                                       0x00
#define   DYNAMIC_DS_EDRAM8_W_OFFSET                                       0x00
#define   LPM_TCAM_KEY_OFFSET                                              0x30000000
#define   LPM_TCAM_MASK_OFFSET                                             0x40000000
#define   TCAM_KEY_OFFSET                                                  0x10000000
#define   TCAM_MASK_OFFSET                                                 0x20000000
#define   TCAM_DS_RAM4_W_BUS_OFFSET                                        0x00
#define   TCAM_DS_RAM8_W_BUS_OFFSET                                        0x00
#define   LPM_TCAM_AD_MEM_OFFSET                                           0x00

#define   TCAM_KEY_OFFSET0                                                  0x10000000
#define   TCAM_MASK_OFFSET0                                                 0x20000000
#define   TCAM_KEY_OFFSET1                                                  0x11000000
#define   TCAM_MASK_OFFSET1                                                 0x21000000
#define   TCAM_KEY_OFFSET2                                                  0x12000000
#define   TCAM_MASK_OFFSET2                                                 0x22000000
#define   TCAM_KEY_OFFSET3                                                  0x13000000
#define   TCAM_MASK_OFFSET3                                                 0x23000000
#define   TCAM_KEY_OFFSET4                                                  0x14000000
#define   TCAM_MASK_OFFSET4                                                 0x24000000
#define   TCAM_KEY_OFFSET5                                                  0x15000000
#define   TCAM_MASK_OFFSET5                                                 0x25000000
#define   TCAM_KEY_OFFSET6                                                  0x16000000
#define   TCAM_MASK_OFFSET6                                                 0x26000000

#define   TCAM_AD_OFFSET0                                                  0x17000000
#define   TCAM_AD_OFFSET1                                                  0x18000000
#define   TCAM_AD_OFFSET2                                                  0x19000000
#define   TCAM_AD_OFFSET3                                                  0x1a000000
#define   TCAM_AD_OFFSET4                                                  0x1b000000
#define   TCAM_AD_OFFSET5                                                  0x1c000000
#define   TCAM_AD_OFFSET6                                                  0x1d000000

#define   LPM_TCAM_KEY_OFFSET0                                              0x30000000
#define   LPM_TCAM_MASK_OFFSET0                                             0x40000000
#define   LPM_TCAM_KEY_OFFSET1                                              0x31000000
#define   LPM_TCAM_MASK_OFFSET1                                             0x41000000

#define   LPM_TCAM_AD_MEM_OFFSET0                                           0x00
#define   LPM_TCAM_AD_MEM_OFFSET1                                           0x00

#define   IPE_LEARNING_CACHE_MAX_INDEX                                     16
#define   DYNAMIC_DS_FDB_LOOKUP_INDEX_CAM_MAX_INDEX                        8

/**********************************************************************************
              Define Typedef, define and Data Structure
***********************************************************************************/
/**********************************************************************************
                      Define API function interfaces
***********************************************************************************/

#endif  /*end of _DRV_HUMBER_LIB_H_*/

