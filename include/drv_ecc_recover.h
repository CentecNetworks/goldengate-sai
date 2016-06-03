/****************************************************************************
 * @date 2015-03-10  The file contains all ecc error fatal interrupt resume realization.
 *
 * Copyright:    (c)2015 Centec Networks Inc.  All rights reserved.
 *
 * Modify History:
 * Revision:     v0.1
 * Date:         2015-03-10
 * Reason:       Create for Goldengate v3.0
 ****************************************************************************/

#ifndef _DRV_GG_ECC_RECOVER_H
#define _DRV_GG_ECC_RECOVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sal.h"

#define DRV_PE_MAX_ENTRY_WORD                          32

/* Normal interrupt */
/* BufRetrvInterruptNormal */
#define  DRV_ECC_INTR_epeIntfCutFifoNormal                     0  /* no recover, no rec */
#define  DRV_ECC_INTR_EpeIntfDataFifoNormal                    1  /* no recover, no rec */
#define  DRV_ECC_INTR_brBufPtrFifo0                            4  /* no recover, no rec */
#define  DRV_ECC_INTR_brBufPtrFifo1                            5  /* no recover, no rec */
#define  DRV_ECC_INTR_brBufPtrFifo2                            6  /* no recover, no rec */
#define  DRV_ECC_INTR_brBufPtrFifo3                            7  /* no recover, no rec */

/* BufStoreInterruptNormal */
#define  DRV_ECC_INTR_pktErrStatsMemSlice0                     0  /* no recover */
#define  DRV_ECC_INTR_pktErrStatsMemSlice1                     1  /* no recover */
#define  DRV_ECC_INTR_IgrPortTcPriMapSlice0                    4
#define  DRV_ECC_INTR_IgrPortTcPriMapSlice1                    5
#define  DRV_ECC_INTR_IgrCondDisProfIdSlice0                   6
#define  DRV_ECC_INTR_IgrCondDisProfIdSlice1                   7
#define  DRV_ECC_INTR_IgrPortTcMinProfIdSlice0                 8
#define  DRV_ECC_INTR_IgrPortTcMinProfIdSlice1                 9
#define  DRV_ECC_INTR_IgrPortTcThrdProfIdSlice0               10
#define  DRV_ECC_INTR_IgrPortTcThrdProfIdSlice1               11
#define  DRV_ECC_INTR_IgrPortCntSlice0                        12  /* no recover */
#define  DRV_ECC_INTR_IgrPortCntSlice1                        13  /* no recover */
#define  DRV_ECC_INTR_IgrPortTcCntSlice0                      14  /* no recover */
#define  DRV_ECC_INTR_IgrPortTcCntSlice1                      15  /* no recover */
#define  DRV_ECC_INTR_bsChanInfoSlice0                        16  /* no recover */
#define  DRV_ECC_INTR_bsChanInfoSlice1                        17  /* no recover */
#define  DRV_ECC_INTR_elpDataFifoSlice0                       18  /* no recover, no rec */
#define  DRV_ECC_INTR_elpDataFifoSlice1                       19  /* no recover, no rec */
#define  DRV_ECC_INTR_IgrPortTcThrdProfile                    20
#define  DRV_ECC_INTR_IgrPortThrdProfile                      21
#define  DRV_ECC_INTR_IgrPriToTcMap                           28

/* DmaCtlInterruptNormal */
#define  DRV_ECC_INTR_dmaPktRxMem                             16  /* no recover */
#define  DRV_ECC_INTR_dmaDescCache                            17  /* no recover */
#define  DRV_ECC_INTR_dmaRegRdMem                             18  /* no recover */
#define  DRV_ECC_INTR_dmaRegWrMem                             19  /* no recover */
#define  DRV_ECC_INTR_fibAccInData                            20  /* no recover, no rec */
#define  DRV_ECC_INTR_flowAccInData                           21  /* no recover, no rec */
#define  DRV_ECC_INTR_ipe0SdcInData                           22  /* no recover, no rec */
#define  DRV_ECC_INTR_ipe1SdcInData                           23  /* no recover, no rec */
#define  DRV_ECC_INTR_policingSdcInData                       24  /* no recover, no rec */
#define  DRV_ECC_INTR_alOutRd                                 29  /* no recover, no rec */
#define  DRV_ECC_INTR_dmaPktTxFifo                            35  /* no recover, no rec */

/* EgrOamHashInterruptNormal */
#define  DRV_ECC_INTR_VlanXlateDefault                         0

/* EpeAclOamInterruptNormal */

/* EpeHdrEditInterruptNormal */
#define  DRV_ECC_INTR_PacketHeaderEditTunnel                   0
#define  DRV_ECC_INTR_epeHdrEditFrHdrProcHdrCtlFifo            1  /* no recover, no rec */
#define  DRV_ECC_INTR_epeHdrEditIngressHdrFifo                 2  /* no recover, no rec */
#define  DRV_ECC_INTR_epeHdrEditL2HdrFifo                      3  /* no recover, no rec */
#define  DRV_ECC_INTR_epeHdrEditL3HdrFifo                      4  /* no recover, no rec */
#define  DRV_ECC_INTR_epeHdrEditPktDataFifo                    5  /* no recover, no rec */
#define  DRV_ECC_INTR_epeHdrEditChBufRam                       6  /* no recover, no EpeHdrEditChBufRam tbl */
#define  DRV_ECC_INTR_epeHdrEditPktInfoHdrProcFifo             8  /* no recover, no rec */

/* EpeHdrProcInterruptNormal */
#define  DRV_ECC_INTR_hdrProcInputBypassPIFifo                 0  /* no recover, no rec */
#define  DRV_ECC_INTR_hdrProcInputBypassPRFifo                 1  /* no recover, no rec */
#define  DRV_ECC_INTR_EgressPortMac                            2
#define  DRV_ECC_INTR_L3Edit3W3rd                              3
#define  DRV_ECC_INTR_PortLinkAgg                              4
#define  DRV_ECC_INTR_EgressVsi                                5
#define  DRV_ECC_INTR_Ipv6NatPrefix                            6
#define  DRV_ECC_INTR_L2Edit6WOuter                            7
#define  DRV_ECC_INTR_l2L3EditPipe1Fifo                        8  /* no recover, no rec */
#define  DRV_ECC_INTR_l2L3EditDataFifo                         9  /* no recover, no rec */
#define  DRV_ECC_INTR_LatencyMonCnt                           10  /* no recover */
#define  DRV_ECC_INTR_LatencyWatermark                        11  /* no recover */

/* EpeNextHopInterruptNormal */

/* FibAccInterruptNormal */
#define  DRV_ECC_INTR_MacLimitThresholdCnt                     0  /* MacLimitThreshold   */
#define  DRV_ECC_INTR_MacLimitCount                            1  /* no recover */
#define  DRV_ECC_INTR_MacLimitThresholdIdx                     2  /* DsMacLimitThreshold */
#define  DRV_ECC_INTR_fibAccLearnOutFifo                       5  /* no recover, no rec */

/* FibEngineInterruptNormal */

/* FlowAccInterruptNormal */
#define  DRV_ECC_INTR_IpfixEgrPortCfg                          0
#define  DRV_ECC_INTR_IpfixEgrPortSamplingCount                1  /* no recover */
#define  DRV_ECC_INTR_IpfixIngPortCfg                          2
#define  DRV_ECC_INTR_IpfixIngPortSamplingCount                3  /* no recover */
#define  DRV_ECC_INTR_flowAccFrTcamIgr1Fifo                    4  /* no recover, no rec */
#define  DRV_ECC_INTR_flowAccFrTcamIgr0Fifo                    5  /* no recover, no rec */
#define  DRV_ECC_INTR_flowAccFrTcamEgr0Fifo                    6  /* no recover, no rec */
#define  DRV_ECC_INTR_flowAccFrTcamEgr1Fifo                    7  /* no recover, no rec */
#define  DRV_ECC_INTR_flowAccKeyGenFifo                        9  /* no recover, no rec */

/* FlowTcamInterruptNormal */
#define  DRV_ECC_INTR_FlowTcamAd0                              0
#define  DRV_ECC_INTR_FlowTcamAd1                              1
#define  DRV_ECC_INTR_FlowTcamAd2                              2
#define  DRV_ECC_INTR_FlowTcamAd3                              3
#define  DRV_ECC_INTR_FlowTcamAd4                              4
#define  DRV_ECC_INTR_FlowTcamAd5                              5
#define  DRV_ECC_INTR_FlowTcamAd6                              6
#define  DRV_ECC_INTR_flowTcamBistReqMem                       7  /* no recover */

/* GlobalStatsInterruptNormal */
#define  DRV_ECC_INTR_cacheRamOverflow                        37  /* ignore */

#define  DRV_ECC_INTR_Stats                                    0  /* no recover */
#define  DRV_ECC_INTR_eEEStatsSlice0Ram                        1  /* no recover */
#define  DRV_ECC_INTR_eEEStatsSlice1Ram                        2  /* no recover */
#define  DRV_ECC_INTR_rxInbdStatsSlice0Ram                     3  /* no recover */
#define  DRV_ECC_INTR_rxInbdStatsSlice1Ram                     4  /* no recover */
#define  DRV_ECC_INTR_txInbdStatsEpeSlice0Ram                  5  /* no recover */
#define  DRV_ECC_INTR_txInbdStatsEpeSlice1Ram                  6  /* no recover */
#define  DRV_ECC_INTR_txInbdStatsPauseSlice0Ram                7  /* no recover */
#define  DRV_ECC_INTR_txInbdStatsPauseSlice1Ram                8  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheDequeueSlice0               9  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheDequeueSlice1              10  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheEnqueueSlice0              11  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheEnqueueSlice1              12  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheEpeAclSlice0               13  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheEpeAclSlice1               14  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheEpeFwdSlice0               15  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheEpeFwdSlice1               16  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheEpeIntfSlice0              17  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheEpeIntfSlice1              18  /* no recover */
#define  DRV_ECC_INTR_EgressPortLogStatsSlice0                19  /* no recover */
#define  DRV_ECC_INTR_EgressPortLogStatsSlice1                20  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheIpeAcl0Slice0              21  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheIpeAcl0Slice1              22  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheIpeAcl1Slice0              23  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheIpeAcl1Slice1              24  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheIpeAcl2Slice0              25  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheIpeAcl2Slice1              26  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheIpeAcl3Slice0              27  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheIpeAcl3Slice1              28  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheIpeFwdSlice0               29  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheIpeFwdSlice1               30  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheIpeIntfSlice0              31  /* no recover */
#define  DRV_ECC_INTR_StatsRamCacheIpeIntfSlice1              32  /* no recover */
#define  DRV_ECC_INTR_IngressPortLogStatsSlice0               33  /* no recover */
#define  DRV_ECC_INTR_IngressPortLogStatsSlice1               34  /* no recover */
#define  DRV_ECC_INTR_StatsRamCachePolicingSlice0             35  /* no recover */
#define  DRV_ECC_INTR_StatsRamCachePolicingSlice1             36  /* no recover */

/* I2CMasterInterruptNormal */
#define  DRV_ECC_INTR_i2CMasterDataMem                         0  /* no recover */

/* IpeForwardInterruptNormal */
#define  DRV_ECC_INTR_QCN                                      1
#define  DRV_ECC_INTR_ipeFwdSopMsgMem                          3  /* no recover, no record */
#define  DRV_ECC_INTR_SrcChannel                               8  /* no recover */

/* IpeHdrAdjInterruptNormal */
#define  DRV_ECC_INTR_PhyPort                                  0

/* IpeIntfMapInterruptNormal */
#define  DRV_ECC_INTR_PhyPortExt                               0
#define  DRV_ECC_INTR_RouterMac                                1
#define  DRV_ECC_INTR_SrcInterface                             2
#define  DRV_ECC_INTR_SrcPort                                  3
#define  DRV_ECC_INTR_VlanActionProfile                        4
#define  DRV_ECC_INTR_VlanRangeProfile                         5
#define  DRV_ECC_INTR_Vlan2Ptr                                12

/* IpeLkupMgrInterruptNormal */
#define  DRV_ECC_INTR_IpeClassificationDscpMap                 0
#define  DRV_ECC_INTR_AclVlanActionProfile                     2

/* IpePktProcInterruptNormal */
#define  DRV_ECC_INTR_BidiPimGroup                             0
#define  DRV_ECC_INTR_EcmpGroup                                1
#define  DRV_ECC_INTR_EcmpMember                               2
#define  DRV_ECC_INTR_Rpf                                      3   /* rtl bug */
#define  DRV_ECC_INTR_Vrf                                      4
#define  DRV_ECC_INTR_Vsi                                      5

/* LpmTcamIpInterruptNormal */
#define  DRV_ECC_INTR_LpmTcamIpAdRam                           0

/* LpmTcamNatInterruptNormal */
#define  DRV_ECC_INTR_LpmTcamNatAdRam                          0
#define  DRV_ECC_INTR_lpmTcamNatBistReqMem                     1  /* no recover */

/* MetFifoInterruptNormal */
#define  DRV_ECC_INTR_msMetFifoTypeError                      12  /* ignore */
#define  DRV_ECC_INTR_msg1SourcePortError                      4  /* ignore */
#define  DRV_ECC_INTR_msg0SourcePortError                      3  /* ignore */

#define  DRV_ECC_INTR_MetLinkAggregateBitmap                   0
#define  DRV_ECC_INTR_MetLinkAggregatePort                     1
#define  DRV_ECC_INTR_MetFifoExcp                              2
#define  DRV_ECC_INTR_met0DsMetResFifo                         5  /* no recover, no record */
#define  DRV_ECC_INTR_met1DsMetResFifo                         6  /* no recover, no record */
#define  DRV_ECC_INTR_met0BmpResFifo                           7  /* no recover, no record */
#define  DRV_ECC_INTR_met1BmpResFifo                           8  /* no recover, no record */
#define  DRV_ECC_INTR_metMcastTrackFifoNormal                  9  /* no recover, no record */
#define  DRV_ECC_INTR_met0BmpReqFifo                          10  /* no recover, no record */
#define  DRV_ECC_INTR_met1BmpReqFifo                          11  /* no recover, no record */

/* NetRxInterruptNormal */
#define  DRV_ECC_INTR_netRxSch0HighFifo                        8   /* no recover, no record */
#define  DRV_ECC_INTR_netRxSch1HighFifo                        9   /* no recover, no record */
#define  DRV_ECC_INTR_netRxSch2HighFifo                       10  /* no recover, no record */
#define  DRV_ECC_INTR_netRxSch3HighFifo                       11  /* no recover, no record */
#define  DRV_ECC_INTR_netRxSch0LowFifo                        12  /* no recover, no record */
#define  DRV_ECC_INTR_netRxSch1LowFifo                        13  /* no recover, no record */
#define  DRV_ECC_INTR_netRxSch2LowFifo                        14  /* no recover, no record */
#define  DRV_ECC_INTR_netRxSch3LowFifo                        15  /* no recover, no record */
#define  DRV_ECC_INTR_ChannelizeIngFc                         16
#define  DRV_ECC_INTR_ChannelizeMode                          17
#define  DRV_ECC_INTR_netRxPktBuf0RdData                      18  /* no recover, no record */
#define  DRV_ECC_INTR_netRxPktBuf1RdData                      19  /* no recover, no record */
#define  DRV_ECC_INTR_netRxPktBuf2RdData                      20  /* no recover, no record */
#define  DRV_ECC_INTR_netRxPktBuf3RdData                      21  /* no recover, no record */
#define  DRV_ECC_INTR_pauseTimerMemRd                         22  /* no recover, no record */

/* NetTxInterruptNormal */
#define  DRV_ECC_INTR_netTxHdrBuf0                             5  /* no recover, no recover */
#define  DRV_ECC_INTR_netTxHdrBuf1                             6  /* no recover, no recover */
#define  DRV_ECC_INTR_netTxHdrBuf2                             7  /* no recover, no recover */
#define  DRV_ECC_INTR_netTxHdrBuf3                             8  /* no recover, no recover */
#define  DRV_ECC_INTR_netTxDsIbLppInfo                        14  /* no recover, no recover */
#define  DRV_ECC_INTR_netTxPktBuf0                            20  /* no recover, no recover */
#define  DRV_ECC_INTR_netTxPktBuf1                            21  /* no recover, no recover */
#define  DRV_ECC_INTR_netTxPktBuf2                            22  /* no recover, no recover */
#define  DRV_ECC_INTR_netTxPktBuf3                            23  /* no recover, no recover */

/* OobFcInterruptNormal */
#define  DRV_ECC_INTR_oobFcCal                                 0  /* no recover */
#define  DRV_ECC_INTR_oobFcGrpMap                              1  /* no recover */

/* PbCtlInterruptNormal */

/* PktProcDsInterruptNormal */
#define  DRV_ECC_INTR_StpState                                 0
#define  DRV_ECC_INTR_VlanStatus                               1
#define  DRV_ECC_INTR_Vlan                                     2
#define  DRV_ECC_INTR_VlanProfile                              3
#define  DRV_ECC_INTR_EthLmProfile                             4

/* PolicingInterruptNormal */
#define  DRV_ECC_INTR_PolicerCountCommit                       4  /* no recover */
#define  DRV_ECC_INTR_PolicerCountExcess                       5  /* no recover */
#define  DRV_ECC_INTR_PolicerControl                           6
#define  DRV_ECC_INTR_PolicerProfile                           7

/* QMgrDeqSliceInterruptNormal */
#define  DRV_ECC_INTR_ChanShpProfile                           0
#define  DRV_ECC_INTR_QueShpProfId                             1
#define  DRV_ECC_INTR_QueShpProfile                            2
#define  DRV_ECC_INTR_GrpShpProfile                            3
#define  DRV_ECC_INTR_qMgrGrpUpdReqFifo                        4  /* no recover, no recover */
#define  DRV_ECC_INTR_SchServiceProfile0                       8
#define  DRV_ECC_INTR_qMgrQReadAckFifo                         9  /* no recover, no recover */
#define  DRV_ECC_INTR_qMgrQReadAckNbFifo                      10  /* no recover, no recover */
#define  DRV_ECC_INTR_SchServiceProfile1                      11
#define  DRV_ECC_INTR_RaGrpWfqState                           12  /* no recover, no RaGrpWfqState tbl */
#define  DRV_ECC_INTR_GrpSchState                             13  /* no recover, no DsGrpSchState tbl */
#define  DRV_ECC_INTR_bufRetrvBufPtrMem                       15


/* QMgrEnqInterruptNormal */
#define  DRV_ECC_INTR_EgrResrcCtl                              0
#define  DRV_ECC_INTR_LinkAggregateMember                      1
#define  DRV_ECC_INTR_LinkAggregateMemberSet                   2
#define  DRV_ECC_INTR_LinkAggregationPort                      3
#define  DRV_ECC_INTR_QueueNumGenCtl                           5
#define  DRV_ECC_INTR_QueueSelectMap                           8
#define  DRV_ECC_INTR_QueThrdProfile                           9
#define  DRV_ECC_INTR_LinkAggregateChannelMemberSet           10
#define  DRV_ECC_INTR_LinkAggregateChannelMember              12  /* no recover */

/* QMgrMsgStoreInterruptNormal */

/* ShareDlbInterruptNormal */
#define  DRV_ECC_INTR_DlbFlowStateRight                        0  /* no recover */
#define  DRV_ECC_INTR_DlbFlowStateLeft                         1  /* no recover */

/* ShareEfdInterruptNormal */

/* TsEngineInterruptNormal */
#define  DRV_ECC_INTR_tsEngineMacTxTsCaptureFifo               2

/* OamProcInterruptNormal */
#define DRV_ECC_INTR_BfdV6Addr                                 1
#define DRV_ECC_INTR_PortProperty                              2
#define DRV_ECC_INTR_oamTxMsgFifo                              3

/* OamFwdInterruptNormal */

/* XqmacInterruptNormal */
#define  DRV_ECC_INTR_statsRam                                 8  /* no recover, no record */

/* Fatal interrupt */
/* BufRetrvInterruptFatal */
#define  DRV_ECC_INTR_bufRetrvBufPtrMem                       15  /* no recover */
#define  DRV_ECC_INTR_epeIntfDataFifoFatal                    16  /* no recover, no record */
#define  DRV_ECC_INTR_epeIntfCutFifoFatal                     17  /* no recover, no record */
#define  DRV_ECC_INTR_bufPtrTrackFifo0                        20  /* no recover, no record */
#define  DRV_ECC_INTR_bufPtrTrackFifo1                        21  /* no recover, no record */
#define  DRV_ECC_INTR_bufRetrvRcdUpdateMsgFifo                22  /* no recover, no record */
#define  DRV_ECC_INTR_bufRetrvStatsUpdMsgFifo                 23  /* no recover, no record */
#define  DRV_ECC_INTR_bufRetrvPktMsgMem                       24  /* no recover */
#define  DRV_ECC_INTR_bufRetrvMsgParkMem                      25  /* no recover */
#define  DRV_ECC_INTR_miscIntfDataMem                         26  /* no recover, no MiscIntfDataMem tbl  */
#define  DRV_ECC_INTR_bufRetrvBufPtrMsgTrackRam               27  /* no recover, no BufRetrvBufPtrMsgTrackRam */

/* BufStoreInterruptFatal */
#define  DRV_ECC_INTR_pktMsgFifoSlice0                        50  /* no recover, no record */
#define  DRV_ECC_INTR_pktMsgFifoSlice1                        51  /* no recover, no record */
#define  DRV_ECC_INTR_bsMetFifoRelease0Fifo                   52  /* no recover, no record */
#define  DRV_ECC_INTR_bsMetFifoRelease1Fifo                   53  /* no recover, no record */
#define  DRV_ECC_INTR_bufStoreLinkListL                       54  /* no recover, no BufStoreLinkListL tbl */
#define  DRV_ECC_INTR_bufStoreLinkListH                       55  /* no recover, no BufStoreLinkListH tbl */
#define  DRV_ECC_INTR_bufStoreFreeListLRam                    56  /* no recover */
#define  DRV_ECC_INTR_bufStoreFreeListHRam                    57  /* no recover */
#define  DRV_ECC_INTR_ipeDataFifoSlice0                       58  /* no recover, no record */
#define  DRV_ECC_INTR_ipeDataFifoSlice1                       59  /* no recover, no record */
#define  DRV_ECC_INTR_trackInfoFifoSlice0                     60  /* no recover, no record */
#define  DRV_ECC_INTR_trackInfoFifoSlice1                     61  /* no recover, no record */

/* DsAgingInterruptFatal */
#define  DRV_ECC_INTR_AgingStatusTcam                         30  /* no recover */
#define  DRV_ECC_INTR_AgingStatusFib                          31  /* no recover */
#define  DRV_ECC_INTR_Aging                                   32

/* DynamicDsAdInterruptFatal */
#define  DRV_ECC_INTR_IpMacRam0                               14
#define  DRV_ECC_INTR_IpMacRam1                               15
#define  DRV_ECC_INTR_IpMacRam2                               16
#define  DRV_ECC_INTR_IpMacRam3                               17
#define  DRV_ECC_INTR_NextHopMetRam0                          18
#define  DRV_ECC_INTR_NextHopMetRam1                          19

/* DynamicDsHashInterruptFatal */
#define  DRV_ECC_INTR_SharedRam0                              30
#define  DRV_ECC_INTR_SharedRam1                              31
#define  DRV_ECC_INTR_SharedRam2                              32
#define  DRV_ECC_INTR_SharedRam3                              33
#define  DRV_ECC_INTR_SharedRam4                              34
#define  DRV_ECC_INTR_SharedRam5                              35
#define  DRV_ECC_INTR_SharedRam6                              36
#define  DRV_ECC_INTR_UserIdHashRam0                          37
#define  DRV_ECC_INTR_UserIdHashRam1                          38
#define  DRV_ECC_INTR_UserIdAdRam                             39

/* DynamicDsShareInterruptFatal */
#define  DRV_ECC_INTR_L2L3EditRam0                            24
#define  DRV_ECC_INTR_L2L3EditRam1                            25
#define  DRV_ECC_INTR_Fwd                                     26

/* EgrOamHashInterruptFatal */
#define  DRV_ECC_INTR_oamHashLkupMgrInputFifo                 13  /* no recover, no record */
#define  DRV_ECC_INTR_oamHashAclInputFifo                     14  /* no recover, no record */

/* EpeAclOamInterruptFatal */
#define  DRV_ECC_INTR_epeClaEopInfoFifo                       31  /* no recover, no record */

/* EpeHdrEditInterruptFatal */
#define  DRV_ECC_INTR_epeHdrEditPktCtlFifo                    23  /* no recover, no record */

/* EpeNextHopInterruptFatal */
#define  DRV_ECC_INTR_DestInterface                           25
#define  DRV_ECC_INTR_EgressVlanRangeProfile                  26
#define  DRV_ECC_INTR_EpeEditPriorityMap                      27
#define  DRV_ECC_INTR_PortIsolation                           28
#define  DRV_ECC_INTR_DestPort                                29
#define  DRV_ECC_INTR_VlanTagBitMap                           30

/* FibEngineInterruptFatal */
#define  DRV_ECC_INTR_fibLpmCtlFifo                           44
#define  DRV_ECC_INTR_fibHost0KeyTrackFifo                    37
#define  DRV_ECC_INTR_fibMacSaKeyResultFifo                   34

/* MetFifoInterruptFatal */
#define  DRV_ECC_INTR_metMsgMem                               30  /* no recover */
#define  DRV_ECC_INTR_metRcdMem                               31  /* no recover */
#define  DRV_ECC_INTR_metMcastTrackFifoFatal                  39  /* no recover, no record */
#define  DRV_ECC_INTR_metBr1RcdFifo                           48  /* no recover, no record */
#define  DRV_ECC_INTR_metBr0RcdFifo                           49  /* no recover, no record */
#define  DRV_ECC_INTR_metEnqRcdFifo                           58  /* no recover, no record */

/* PbCtlInterruptFatal */
#define  DRV_ECC_INTR_hBankLAddrMemReadData                    0  /* no recover, no record */
#define  DRV_ECC_INTR_hBankRAddrMemReadData                    1  /* no recover, no record */
#define  DRV_ECC_INTR_lBankLAddrMemReadData                    2  /* no recover, no record */
#define  DRV_ECC_INTR_lBankRAddrMemReadData                    3  /* no recover, no record */
#define  DRV_ECC_INTR_pbCtlBs0DataFifo                        16  /* no recover, no record */
#define  DRV_ECC_INTR_pbCtlBs1DataFifo                        17  /* no recover, no record */
#define  DRV_ECC_INTR_pktBufHBankL                            18  /* no recover, no record */
#define  DRV_ECC_INTR_pktBufHBankR                            19  /* no recover, no record */
#define  DRV_ECC_INTR_pktBufLBankR                            20  /* no recover, no record */
#define  DRV_ECC_INTR_pktBufLBankL                            21  /* no recover, no record */

/* QMgrMsgStoreInterruptFatal */
#define  DRV_ECC_INTR_MsgFreePtr                              5  /* no recover */
#define  DRV_ECC_INTR_QueEntryH0BARdData                      6  /* no recover, no record */
#define  DRV_ECC_INTR_QueEntryH1BARdData                      7  /* no recover, no record */
#define  DRV_ECC_INTR_QueEntryL0BARdData                      8  /* no recover, no record */
#define  DRV_ECC_INTR_QueEntryL1BARdData                      9  /* no recover, no record */
#define  DRV_ECC_INTR_MsgLinkTail0                           10  /* no recover */
#define  DRV_ECC_INTR_MsgUsedList0                           11  /* no recover */
#define  DRV_ECC_INTR_MsgUsedList1                           12  /* no recover */
#define  DRV_ECC_INTR_MsgLinkHead0                           13  /* no recover */
#define  DRV_ECC_INTR_MsgLinkTail1                           14  /* no recover */
#define  DRV_ECC_INTR_MsgLinkHead1                           15  /* no recover */
#define  DRV_ECC_INTR_MsgLinkCache                           16  /* no recover */

/* OamParserInterruptFatal */
#define  DRV_ECC_INTR_oamParserPktFifo                        1  /* no recover, no record */

/* ShareEfdInterruptFatal */
#define  DRV_ECC_INTR_ElephantFlowDetect0                     4  /* no recover */
#define  DRV_ECC_INTR_ElephantFlowDetect1                     5  /* no recover */
#define  DRV_ECC_INTR_ElephantFlowDetect2                     6  /* no recover */
#define  DRV_ECC_INTR_ElephantFlowDetect3                     7  /* no recover */
#define  DRV_ECC_INTR_ElephantFlowState                       8  /* no recover */

/* ShareStormCtlInterruptFatal */
#define  DRV_ECC_INTR_VlanStormCtl                            2
#define  DRV_ECC_INTR_PortStormCtl                            3
#define  DRV_ECC_INTR_VlanStormCount                          4  /* no recover */
#define  DRV_ECC_INTR_PortStormCount                          5  /* no recover */

/* OamAutoGenPktInterruptFatal */
#define DRV_ECC_INTR_autoGenPktPktHdr                         0

enum drv_ecc_recover_action_e
{
    DRV_ECC_RECOVER_ACTION_NONE,
    DRV_ECC_RECOVER_ACTION_REMOVE,
    DRV_ECC_RECOVER_ACTION_OVERWRITE,
    DRV_ECC_RECOVER_ACTION_NUM
};
typedef enum drv_ecc_recover_action_e drv_ecc_recover_action_t;

enum drv_ecc_scan_type_e
{
    DRV_ECC_SCAN_TYPE_TCAM,
    DRV_ECC_SCAN_TYPE_SBE,
    DRV_ECC_SCAN_TYPE_NUM
};
typedef enum drv_ecc_scan_type_e drv_ecc_scan_type_t;

/* memory mapping type */
enum drv_ecc_mem_type_e
{
    /* Normal interrupt */
    /* BufStoreInterruptNormal */
    DRV_ECC_MEM_IgrPortTcPriMap,
    DRV_ECC_MEM_IgrCondDisProfId,
    DRV_ECC_MEM_IgrPortTcMinProfId,
    DRV_ECC_MEM_IgrPortTcThrdProfId,
    DRV_ECC_MEM_IgrPortTcThrdProfile,
    DRV_ECC_MEM_IgrPortThrdProfile,
    DRV_ECC_MEM_IgrPriToTcMap,

    /* EgrOamHashInterruptNormal */
    DRV_ECC_MEM_VlanXlateDefault,

    /* EpeHdrEditInterruptNormal */
    DRV_ECC_MEM_PacketHeaderEditTunnel,

    /* EpeHdrProcInterruptNormal */
    DRV_ECC_MEM_EgressPortMac,
    DRV_ECC_MEM_L3Edit3W3rd,
    DRV_ECC_MEM_PortLinkAgg,
    DRV_ECC_MEM_EgressVsi,
    DRV_ECC_MEM_Ipv6NatPrefix,
    DRV_ECC_MEM_L2Edit6WOuter,

    /* FibAccInterruptNormal */
    DRV_ECC_MEM_MacLimitThresholdCnt,
    DRV_ECC_MEM_MacLimitThresholdIdx,

    /* FlowAccInterruptNormal */
    DRV_ECC_MEM_IpfixEgrPortCfg,
    DRV_ECC_MEM_IpfixIngPortCfg,

    /* IpeForwardInterruptNormal */
    DRV_ECC_MEM_Qcn,
    DRV_ECC_MEM_SrcChannel,

    /* IpeHdrAdjInterruptNormal */
    DRV_ECC_MEM_PhyPort,

    /* IpeIntfMapInterruptNormal */
    DRV_ECC_MEM_PhyPortExt,
    DRV_ECC_MEM_RouterMac,
    DRV_ECC_MEM_SrcInterface,
    DRV_ECC_MEM_SrcPort,
    DRV_ECC_MEM_VlanActionProfile,
    DRV_ECC_MEM_VlanRangeProfile,
    DRV_ECC_MEM_Vlan2Ptr,

    /* IpeLkupMgrInterruptNormal */
    DRV_ECC_MEM_IpeClassificationDscpMap,
    DRV_ECC_MEM_AclVlanActionProfile,

    /* IpePktProcInterruptNormal */
    DRV_ECC_MEM_BidiPimGroup,
    DRV_ECC_MEM_EcmpGroup,
    DRV_ECC_MEM_EcmpMember,
    DRV_ECC_MEM_Vrf,
    DRV_ECC_MEM_Vsi,

    /* MetFifoInterruptNormal */
    DRV_ECC_MEM_MetLinkAggregateBitmap,
    DRV_ECC_MEM_MetLinkAggregatePort,
    DRV_ECC_MEM_MetFifoExcp,

    /* NetRxInterruptNormal */
    DRV_ECC_MEM_ChannelizeIngFc0,
    DRV_ECC_MEM_ChannelizeIngFc1,

    DRV_ECC_MEM_ChannelizeMode0,
    DRV_ECC_MEM_ChannelizeMode1,

    /* PktProcDsInterruptNormal */
    DRV_ECC_MEM_StpState,
    DRV_ECC_MEM_VlanStatus,
    DRV_ECC_MEM_Vlan,
    DRV_ECC_MEM_VlanProfile,
    DRV_ECC_MEM_EthLmProfile,

    /* PolicingInterruptNormal */
    DRV_ECC_MEM_PolicerControl,
    DRV_ECC_MEM_PolicerProfile,

    /* QMgrDeqSliceInterruptNormal */
    DRV_ECC_MEM_ChanShpProfile,
    DRV_ECC_MEM_QueShpProfId,
    DRV_ECC_MEM_QueShpProfile,
    DRV_ECC_MEM_GrpShpProfile,
    DRV_ECC_MEM_SchServiceProfile,

    /* QMgrEnqInterruptNormal */
    DRV_ECC_MEM_EgrResrcCtl,
    DRV_ECC_MEM_LinkAggregateMember,
    DRV_ECC_MEM_LinkAggregateMemberSet,
    DRV_ECC_MEM_LinkAggregationPort,
    DRV_ECC_MEM_QueueNumGenCtl,
    DRV_ECC_MEM_QueueSelectMap,
    DRV_ECC_MEM_QueThrdProfile,
    DRV_ECC_MEM_LinkAggregateChannelMemberSet,

    /* Fatal interrupt */
    /* DsAgingInterruptFatal */
    DRV_ECC_MEM_Aging,

    /* DynamicDsShareInterruptFatal */
    DRV_ECC_MEM_Fwd,

    /* EpeNextHopInterruptFatal */
    DRV_ECC_MEM_DestInterface,
    DRV_ECC_MEM_EgressVlanRangeProfile,
    DRV_ECC_MEM_EpeEditPriorityMap,
    DRV_ECC_MEM_PortIsolation,
    DRV_ECC_MEM_DestPort,
    DRV_ECC_MEM_VlanTagBitMap,

    /* ShareStormCtlInterruptFatal */
    DRV_ECC_MEM_VlanStormCtl,
    DRV_ECC_MEM_PortStormCtl,

    /* OamProcInterruptNormal */
    DRV_ECC_MEM_BfdV6Addr,
    DRV_ECC_MEM_PortProperty,

    /* OamAutoGenPktInterruptFatal */
    DRV_ECC_MEM_AutoGenPktPktHdr,

    /* DynamicDsHashInterruptFatal */
    DRV_ECC_MEM_SharedRam0,
    DRV_ECC_MEM_SharedRam1,
    DRV_ECC_MEM_SharedRam2,
    DRV_ECC_MEM_SharedRam3,
    DRV_ECC_MEM_SharedRam4,
    DRV_ECC_MEM_SharedRam5,
    DRV_ECC_MEM_SharedRam6,

    /* DynamicDsAdInterruptFatal */
    DRV_ECC_MEM_IpMacRam0,
    DRV_ECC_MEM_IpMacRam1,
    DRV_ECC_MEM_IpMacRam2,
    DRV_ECC_MEM_IpMacRam3,

    /* DynamicDsHashInterruptFatal */
    DRV_ECC_MEM_UserIdHashRam0,
    DRV_ECC_MEM_UserIdHashRam1,
    DRV_ECC_MEM_UserIdAdRam,

    /* DynamicDsShareInterruptFatal */
    DRV_ECC_MEM_L2L3EditRam0,
    DRV_ECC_MEM_L2L3EditRam1,

    /* DynamicDsAdInterruptFatal */
    DRV_ECC_MEM_NextHopMetRam0,
    DRV_ECC_MEM_NextHopMetRam1,

    DRV_ECC_MEM_TCAM_KEY0,
    DRV_ECC_MEM_TCAM_KEY1,
    DRV_ECC_MEM_TCAM_KEY2,
    DRV_ECC_MEM_TCAM_KEY3,
    DRV_ECC_MEM_TCAM_KEY4,
    DRV_ECC_MEM_TCAM_KEY5,
    DRV_ECC_MEM_TCAM_KEY6,

    DRV_ECC_MEM_TCAM_KEY7,
    DRV_ECC_MEM_TCAM_KEY8,

    /* FlowTcamInterruptNormal */
    DRV_ECC_MEM_FlowTcamAd0,
    DRV_ECC_MEM_FlowTcamAd1,
    DRV_ECC_MEM_FlowTcamAd2,
    DRV_ECC_MEM_FlowTcamAd3,
    DRV_ECC_MEM_FlowTcamAd4,
    DRV_ECC_MEM_FlowTcamAd5,
    DRV_ECC_MEM_FlowTcamAd6,

    /* LpmTcamIpInterruptNormal */
    DRV_ECC_MEM_LpmTcamIpAdRam,

    /* LpmTcamNatInterruptNormal */
    DRV_ECC_MEM_LpmTcamNatAdRam,

    DRV_ECC_MEM_NUM,

    DRV_ECC_MEM_IGNORE = DRV_ECC_MEM_NUM,
    DRV_ECC_MEM_INVALID = DRV_ECC_MEM_NUM
};
typedef enum drv_ecc_mem_type_e drv_ecc_mem_type_t;

struct drv_ecc_intr_param_s
{
    tbls_id_t  intr_tblid;       /**< interrupt tbl id */
    uint32*    p_bmp;            /**< bitmap of interrupt status */
    uint16     total_bit_num;    /**< total bit num */
    uint16     valid_bit_count;  /**< valid bit count */
};
typedef struct drv_ecc_intr_param_s drv_ecc_intr_param_t;

struct drv_ecc_recover_init_s
{
    uint32  tcam_scan_en     :1;        /**< enable tcam scan */
    uint32  sbe_scan_en      :1;        /**< enable single bit error scan */
    uint32  ecc_recover_en   :1;        /**< enable ecc/parity error recover */
    uint32  rsv              :29;
    uint32  tcam_scan_burst_entry_num;  /**< tcam key scan entries num per burst */
    uint32  tcam_scan_interval;         /**< tcam key scan all time interval, unit is ms */
    uint32  sbe_scan_interval;          /**< single bit error scan all time interval, unit is ms */
};
typedef struct drv_ecc_recover_init_s drv_ecc_recover_init_t;

typedef int32 (* drv_ecc_event_fn)(uint8 gchip, void* p_data);

/**
 @brief The function get interrupt bits's field id and action type
*/
int32
drv_ecc_recover_get_intr_info(tbls_id_t tblid, uint8 intr_bit, uint8* p_fldid, uint8* p_action_type, uint8* p_ecc_or_parity);

/**
 @brief The function compare cached tcam data/mask with data/mask read from hw,
        if compare failed, recover from cached data/mask and send tcam error event log.
*/
extern int32
drv_ecc_recover_tcam(uint8 chip_id, drv_ecc_mem_type_t mem_type,
                     uint32 entry_offset, tbl_entry_t* p_tbl_entry,
                     drv_ecc_recover_action_t* p_recover_action);

/**
 @brief The function provide user register ecc event monitor
*/
extern int32
drv_ecc_recover_register_event_cb(drv_ecc_event_fn cb);

/**
 @brief The function write tbl data to ecc error recover memory for resume
*/
extern int32
drv_ecc_recover_store(uint8 chip_id, uint32 mem_id,
                      uint32 tbl_idx, tbl_entry_t* p_tbl_entry);

/**
 @brief The function recover the ecc error memory with handle info
*/
extern int32
drv_ecc_recover_restore(uint8 chip_id, drv_ecc_intr_param_t* p_intr_param);

/**
 @brief Set scan burst entry num and interval time(ms)
*/
extern int32
drv_ecc_recover_set_tcam_scan_cfg(uint32 burst_entry_num, uint32 burst_interval);

/**
 @brief The function set mac hw learning
*/
extern void
drv_ecc_recover_set_hw_learning(uint8 enable);

/**
 @brief The function get ecc recover status
*/
extern uint8
drv_ecc_recover_get_enable(void);

/**
 @brief The function get ecc error recover/ignore restore memory/tbl count
*/
int32
drv_ecc_recover_get_status(uint8 chip_id, drv_ecc_mem_type_t mem_type, uint32* p_cnt);

/**
 @brief The function show ecc error recover restore memory count
*/
extern int32
drv_ecc_recover_show_status(uint8 chip_id, uint32 is_all);

/**
 @brief Set tcam or single bit error memory can mode
*/
int32
drv_ecc_recover_set_mem_scan_mode(drv_ecc_scan_type_t type, uint8 mode, uint8 scan_interval);

/**
 @brief Get tcam or single bit error memory can mode
*/
int32
drv_ecc_recover_get_mem_scan_mode(drv_ecc_scan_type_t type, uint8* p_mode, uint8* p_scan_interval);

/**
 @brief The function init chip's mapping memory for ecc error recover
*/
extern int32
drv_ecc_recover_init(drv_ecc_recover_init_t* p_init);

#ifdef __cplusplus
}
#endif

#endif

