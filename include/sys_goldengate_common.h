/**
 @file sys_goldengate_common.h

 @date 2010-3-10

 @version v2.0

*/

#ifndef _SYS_GOLDENGATE_COMMON_H
#define _SYS_GOLDENGATE_COMMON_H
#ifdef __cplusplus
extern "C" {
#endif

#include "sal.h"
#include "ctc_const.h"

#include "sys_goldengate_datapath.h"


#define  SYS_COMMON_USELESS_MAC  0xffff
#define  SYS_GET_MAC_ID(lchip, gport)                          sys_goldengate_common_get_mac_id(lchip, gport)
#define  SYS_GET_CHANNEL_ID(lchip, gport)                      sys_goldengate_common_get_channel_id(lchip, gport)
#define  SYS_GET_LPORT_ID_WITH_MAC(lchip, mac_id)       sys_goldengate_common_get_lport_with_mac(lchip, mac_id)
#define  SYS_GET_LPORT_ID_WITH_CHAN(lchip, chan_id)     sys_goldengate_common_get_lport_with_chan(lchip, chan_id)
#define  SYS_MAC_IS_VALID(lchip, mac_id)                sys_goldengate_common_check_mac_valid(lchip, mac_id)




/*networks channel must be 0~51, mix channel must be 52~63!!!*/
#define SYS_DROP_CHANNEL_ID          51  /**< Drop channel id  */
#define SYS_ILOOP_CHANNEL_ID         52 /**< ILOOP channel id  */
#define SYS_ELOOP_CHANNEL_ID         53  /**< ELOOP channel id */

#define SYS_OAM_CHANNEL_ID           55  /**< OAM channel id    */
#define SYS_DMA_CHANNEL_ID           56  /**< DMA channel id    */
#define SYS_DMA_CHANNEL_RX1          57  /**< DMA channel id    */
#define SYS_DMA_CHANNEL_RX2          58  /**< DMA channel id    */
#define SYS_DMA_CHANNEL_RX3          59  /**< DMA channel id    */


#define SYS_RSV_CHANNEL_ID         63  /**< Reserve unsed channel  */
#define SYS_MAX_CHANNEL_ID          64  /**< Max channel id = 64 */
#define SYS_MAX_LOCAL_SLICE_NUM       2

#define SYS_PHY_PORT_NUM_PER_SLICE   48  /*+ max local phyport per slice*/

/*Note,the reserved port must be consecutive on same channel */
#define SYS_RSV_PORT_ELOOP_NUM     8
#define SYS_RSV_PORT_BASE              248     /*(SYS_INTERNAL_PORT_START+SYS_INTERNAL_PORT_NUM)*/
#define SYS_RSV_PORT_DROP_ID        SYS_RSV_PORT_BASE // Drop Channel . (8 queue)

/*CPU/OAM Src Port*/
#define SYS_RSV_PORT_OAM_CPU_ID          (SYS_RSV_PORT_BASE+1)

/*ELoop Channel*/
#define SYS_RSV_PORT_ELOOP_ID        (SYS_RSV_PORT_BASE+2)
#define SYS_RSV_PORT_IP_TUNNEL       SYS_RSV_PORT_ELOOP_ID
#define SYS_RSV_PORT_MIRROR          (SYS_RSV_PORT_BASE+3)

/*ILoop Channel*/
#define SYS_RSV_PORT_ILOOP_ID        (SYS_RSV_PORT_BASE+4)
#define SYS_RSV_PORT_IPE_QUE_DROP    SYS_RSV_PORT_DROP_ID

#define SYS_RSV_PORT_END          255

#define SYS_PKT_CPU_QDEST_BY_DMA     15*8  /*default defsub queue id = 120*/

#define SYS_ENCODE_DESTMAP( gchip,lport)        ((((gchip)&0x1F) << 12) | ((lport)&0xFFF))
/*to lcpu(DMA)*/
#define SYS_ENCODE_EXCP_DESTMAP(gchip, queueId) ((((gchip)&0x1F) << 12) | (1 << 9) | ((queueId)&0x1FF))
#define SYS_DESTMAP_IS_CPU(destmap) ((((destmap) >> 9)&0x7) == 1)
/*to lcpu(ETH)*/
#define SYS_ENCODE_EXCP_BY_ETH_ESTMAP(gchip, queueId) ((((gchip)&0x1F) << 12) | (5 << 9) | ((queueId)&0x1FF))
#define SYS_DESTMAP_IS_ETH_CPU(destmap) ((((destmap) >> 9)&0x7) == 5)
/*mirror to network port*/
#define SYS_ENCODE_MIRROR_DESTMAP(gchip, lport) ((((gchip)&0x1F) << 12) | (4 << 9) | ((lport)&0x1FF))

#define SYS_ENCODE_MCAST_IPE_DESTMAP( speed,group) ((1<<18)| (speed &0x3) << 16 | (group))
#define SYS_ENCODE_MCAST_NON_IPE_DESTMAP(group)    ((1<<17) | (group))


#define SYS_GOLDENGATE_DESTMAP_TO_DRV_GPORT(destmap) \
    ((((destmap >> 12) & 0x1F) << 9) | (destmap & 0x1FF)); \

#define SYS_UINT64_SET(val_64, value)  do{\
    val_64 = value[1];\
    val_64 <<= 32;\
    val_64 |= value[0];\
    }while(0)

#define SYS_GOLDENGATE_SET_HW_MAC(dest, src)     \
    {   \
        (dest)[1]= (((src)[0] << 8) | ((src)[1]));        \
        (dest)[0]= (((src)[2] << 24) | ((src)[3] << 16) | ((src)[4] << 8) | ((src)[5])); \
    }

#define SYS_GOLDENGATE_SET_USER_MAC(dest, src)     \
    {   \
        (dest)[0] = (src)[1] >> 8;          \
        (dest)[1] = (src)[1] & 0xFF;        \
        (dest)[2] = (src)[0] >> 24;         \
        (dest)[3] = ((src)[0] >> 16) & 0xFF;\
        (dest)[4] = ((src)[0] >> 8) & 0xFF; \
        (dest)[5] = (src)[0] & 0xFF;        \
    }

#define SYS_GOLDENGATE_REVERT_IP6(dest, src)     \
    {                                            \
        (dest)[3] = (src)[0];                        \
        (dest)[2] = (src)[1];                        \
        (dest)[1] = (src)[2];                        \
        (dest)[0] = (src)[3];                        \
    }
#define SYS_L4_PROTOCOL_IPV4_ICMP                        1
#define SYS_L4_PROTOCOL_IPV4_IGMP                        2
#define SYS_L4_PROTOCOL_TCP                              6
#define SYS_L4_PROTOCOL_UDP                              17
#define SYS_L4_PROTOCOL_IPV6_ICMP                        58
#define SYS_L4_PROTOCOL_GRE                              47
#define SYS_L4_PROTOCOL_IPV4                             4
#define SYS_L4_PROTOCOL_IPV6                             41
#define SYS_L4_PROTOCOL_SCTP                             132
#define SYS_SCL_BY_PASS_VLAN_PTR                         0x1500
#define SYS_MTU_MAX_SIZE     0x3FFF
#define SYS_PTP_MAX_PTP_ID     7
#define SYS_L4_USER_UDP_TYPE_VXLAN   5


#ifdef EMULATION_PLATFORM
#define DOWN_FRE_RATE 2000
#else
#define DOWN_FRE_RATE 1
#endif

typedef uint32 ds_t[32];

/*****************************************************************************************/

extern char*
sys_output_mac(mac_addr_t in_mac);

extern uint8
sys_goldengate_common_get_mac_id(uint8 lchip, uint16 gport);

extern uint8
sys_goldengate_common_get_channel_id(uint8 lchip, uint16 gport);

extern uint16
sys_goldengate_common_get_lport_with_mac(uint8 lchip, uint8 mac_id);

extern uint16
sys_goldengate_common_get_lport_with_chan(uint8 lchip, uint8 chan_id);

extern bool
sys_goldengate_common_check_mac_valid(uint8 lchip, uint8 mac_id);

extern int32
sys_goldengate_common_map_qos_policy(uint8 lchip, uint32 ctc_qos_trust, uint32* policy);

extern int32
sys_goldengate_common_unmap_qos_policy(uint8 lchip, uint32 policy, uint32* ctc_qos_trust);

extern int32
sys_goldengate_common_get_port_capability(uint8 lchip, uint16 lport, sys_datapath_lport_attr_t** p_port);

extern int32
sys_goldengate_common_get_block_mac_index(uint8 lchip, uint8 slice_id, uint8 mac_id, uint8* p_idx);

extern  uint8
sys_goldengate_common_get_mac_type(uint8 lchip, uint8 mac_id);


#ifdef __cplusplus
}
#endif

#endif

