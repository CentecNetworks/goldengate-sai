/*
 * drv_register.h
 *
 *  Created on: Nov 6, 2012
 *      Author: chenn
 */

#ifndef DRV_REGISTER_H_
#define DRV_REGISTER_H_

#include <stddef.h>

enum ACLMETADATATYPE {
    DRV_ACLMETADATATYPE_INVALID                  = 0x0,
    DRV_ACLMETADATATYPE_METADATA                 = 0x1,
    DRV_ACLMETADATATYPE_FID                      = 0x2,
    DRV_ACLMETADATATYPE_VRFID                    = 0x3,
};
enum ACLQOSKEYTYPE {
    DRV_ACLQOSKEYTYPE_MACKEY160                  = 0x0,
    DRV_ACLQOSKEYTYPE_MACKEY320                  = 0x1,
    DRV_ACLQOSKEYTYPE_L3KEY160                   = 0x2,
    DRV_ACLQOSKEYTYPE_MACL3KEY320                = 0x3,
    DRV_ACLQOSKEYTYPE_IPV6KEY640                 = 0x4,
};
enum BFDSTAT {
    DRV_BFDSTAT_ADMIN_DOWN                       = 0x0,
    DRV_BFDSTAT_DOWN                             = 0x1,
    DRV_BFDSTAT_INIT                             = 0x2,
    DRV_BFDSTAT_UP                               = 0x3,
};
enum CFIACTIONTYPE {
    DRV_CFIACTIONTYPE_NONE                       = 0x0,
    DRV_CFIACTIONTYPE_SWAP                       = 0x1,
    DRV_CFIACTIONTYPE_USER                       = 0x2,
};
enum CHANNELID {
    DRV_CHANNELID_SGMAC                          = 0x0,
    DRV_CHANNELID_LOOPBACK                       = 0x1,
    DRV_CHANNELID_NETWORKPORT                    = 0x2,
};
enum COLORTYPE {
    DRV_COLORTYPE_RESERVED                       = 0x0,
    DRV_COLORTYPE_RED                            = 0x1,
    DRV_COLORTYPE_YELLOW                         = 0x2,
    DRV_COLORTYPE_GREEN                          = 0x3,
};
enum COSACTIONTYPE {
    DRV_COSACTIONTYPE_NONE                       = 0x0,
    DRV_COSACTIONTYPE_SWAP                       = 0x1,
    DRV_COSACTIONTYPE_USER                       = 0x2,
};
enum DESTDS {
    DRV_DESTDS_ACLTCAMKEY                        = 0x0,
    DRV_DESTDS_FLOWHASHKEY                       = 0x1,
    DRV_DESTDS_USERIDFLOWCAMKEY                  = 0x2,
};
enum EDITTYPE {
    DRV_EDITTYPE_TYPE12W                         = 0x0,
    DRV_EDITTYPE_TYPE6W                          = 0x1,
    DRV_EDITTYPE_TYPE3W                          = 0x2,
};
enum EPEEXCEPTIONINDEX {
    DRV_EPEEXCEPTIONINDEX_EGRESS_VLANXLATE_EXCEPTION = 0x0,
    DRV_EPEEXCEPTIONINDEX_PARSER_LENGTH_ERROR    = 0x1,
    DRV_EPEEXCEPTIONINDEX_TTL_CHECK_FAIL         = 0x2,
    DRV_EPEEXCEPTIONINDEX_OAM_1                  = 0x3,
    DRV_EPEEXCEPTIONINDEX_OAM_2                  = 0x4,
    DRV_EPEEXCEPTIONINDEX_MTU_CHECK_FAIL         = 0x5,
    DRV_EPEEXCEPTIONINDEX_STRIP_OFFSET_ERROR     = 0x6,
    DRV_EPEEXCEPTIONINDEX_ICMP_ERROR_MESSAGE     = 0x7,
};
enum EPEIFSTATSTYPE {
    DRV_EPEIFSTATSTYPE_PORT                      = 0x0,
    DRV_EPEIFSTATSTYPE_L3IF                      = 0x1,
    DRV_EPEIFSTATSTYPE_NEXTHOP                   = 0x2,
    DRV_EPEIFSTATSTYPE_VLANXLATE                 = 0x3,
    DRV_EPEIFSTATSTYPE_L3EDIT                    = 0x4,
};
enum EPELMPACKETTYPE {
    DRV_EPELMPACKETTYPE_NONE                     = 0x0,
    DRV_EPELMPACKETTYPE_ETH_CCM                  = 0x8,
    DRV_EPELMPACKETTYPE_ETH_LMM                  = 0x9,
    DRV_EPELMPACKETTYPE_ETH_LMR                  = 0xa,
    DRV_EPELMPACKETTYPE_ACH                      = 0xb,
    DRV_EPELMPACKETTYPE_MPLSTPY1731_CCM          = 0xc,
    DRV_EPELMPACKETTYPE_MPLSTPY1731_LMM          = 0xd,
    DRV_EPELMPACKETTYPE_MPLSTPY1731_LMR          = 0xe,
    DRV_EPELMPACKETTYPE_ACH_DLMDM                = 0xf,
};
enum FATALEXCEPTION {
    DRV_FATALEXCEPTION_UC_IP_HDR_ERROR_OR_MARTION_ADDR = 0x0,
    DRV_FATALEXCEPTION_UC_IP_OPTIONS             = 0x1,
    DRV_FATALEXCEPTION_UC_GRE_UNKNOWN_OPT_PROTOCAL = 0x2,
    DRV_FATALEXCEPTION_UC_ISATAP_SRC_ADDR_CHK_FAIL = 0x3,
    DRV_FATALEXCEPTION_UC_IPTTL_CHK_FAIL         = 0x4,
    DRV_FATALEXCEPTION_UC_RPF_CHK_FAIL           = 0x5,
    DRV_FATALEXCEPTION_UC_OR_MC_MORERPF          = 0x6,
    DRV_FATALEXCEPTION_UC_LINKID_CHK_FAIL        = 0x7,
    DRV_FATALEXCEPTION_MPLS_LABEL_OUTOFRANGE     = 0x8,
    DRV_FATALEXCEPTION_MPLS_SBIT_ERROR           = 0x9,
    DRV_FATALEXCEPTION_MPLS_TTL_CHK_FAIL         = 0xa,
    DRV_FATALEXCEPTION_FCOE_VIRTUAL_LINK_CHK_FAIL = 0xb,
    DRV_FATALEXCEPTION_IGMP_SNOOPING_PKT         = 0xc,
    DRV_FATALEXCEPTION_TRILL_OPTION              = 0xd,
    DRV_FATALEXCEPTION_TRILL_TTL_CHK_FAIL        = 0xe,
    DRV_FATALEXCEPTION_VXLAN_OR_NVGRE_CHK_FAIL   = 0xf,
};
enum FIB2NDHASHKEYSUBTYPE {
    DRV_FIB2NDHASHKEYSUBTYPE_FCOERPF             = 0x0,
    DRV_FIB2NDHASHKEYSUBTYPE_TRILLMC             = 0x1,
    DRV_FIB2NDHASHKEYSUBTYPE_IPV6MC              = 0x2,
    DRV_FIB2NDHASHKEYSUBTYPE_MACIPV6MC           = 0x3,
};
enum FIBDAKEYTYPE {
    DRV_FIBDAKEYTYPE_IPV4UCAST                   = 0x0,
    DRV_FIBDAKEYTYPE_IPV6UCAST                   = 0x1,
    DRV_FIBDAKEYTYPE_IPV4MCAST                   = 0x2,
    DRV_FIBDAKEYTYPE_IPV6MCAST                   = 0x3,
    DRV_FIBDAKEYTYPE_FCOE                        = 0x4,
    DRV_FIBDAKEYTYPE_TRILLUCAST                  = 0x5,
    DRV_FIBDAKEYTYPE_TRILLMCAST                  = 0x6,
    DRV_FIBDAKEYTYPE_RESERVED                    = 0x7,
};
enum FIBLPMTCAMKEYTYPE {
    DRV_FIBLPMTCAMKEYTYPE_IPV4UCAST              = 0x0,
    DRV_FIBLPMTCAMKEYTYPE_IPV6UCAST              = 0x1,
};
enum FIBNATPBRTCAMKEYTYPE {
    DRV_FIBNATPBRTCAMKEYTYPE_IPV4PBR             = 0x0,
    DRV_FIBNATPBRTCAMKEYTYPE_IPV6PBR             = 0x1,
    DRV_FIBNATPBRTCAMKEYTYPE_IPV4NAT             = 0x2,
    DRV_FIBNATPBRTCAMKEYTYPE_IPV6NAT             = 0x3,
};
enum FIBSAKEYTYPE {
    DRV_FIBSAKEYTYPE_IPV4RPF                     = 0x0,
    DRV_FIBSAKEYTYPE_IPV6RPF                     = 0x1,
    DRV_FIBSAKEYTYPE_IPV4PBR                     = 0x2,
    DRV_FIBSAKEYTYPE_IPV6PBR                     = 0x3,
    DRV_FIBSAKEYTYPE_IPV4NATSA                   = 0x4,
    DRV_FIBSAKEYTYPE_IPV6NATSA                   = 0x5,
    DRV_FIBSAKEYTYPE_FCOERPF                     = 0x6,
};
enum FLOWPORTTYPE {
    DRV_FLOWPORTTYPE_BITMAP                      = 0x0,
    DRV_FLOWPORTTYPE_GPORT                       = 0x1,
    DRV_FLOWPORTTYPE_LPORT                       = 0x2,
    DRV_FLOWPORTTYPE_METADATA                    = 0x3,
};
enum FLOWTCAMLOOKUPTYPE {
    DRV_FLOWTCAMLOOKUPTYPE_TCAML2KEY             = 0x0,
    DRV_FLOWTCAMLOOKUPTYPE_TCAML2L3KEY           = 0x1,
    DRV_FLOWTCAMLOOKUPTYPE_TCAML3KEY             = 0x2,
    DRV_FLOWTCAMLOOKUPTYPE_TCAMVLANKEY           = 0x3,
};
enum FWDPTRDERIVE {
    DRV_FWDPTRDERIVE_PP                          = 0x0,
    DRV_FWDPTRDERIVE_FLOW                        = 0x1,
};
enum GLBFDBCAMNUM {
    DRV_GLBFDBCAMNUM_FDB_CAM_NUM                 = 0x20,
};
enum GLBPARLEN {
    DRV_GLBPARLEN_PARSER_LENGTH                  = 0x90,
};
enum HASHKEYLENGTHMODE {
    DRV_HASHKEYLENGTHMODE_SINGLE                 = 0x0,
    DRV_HASHKEYLENGTHMODE_DOUBLE                 = 0x1,
    DRV_HASHKEYLENGTHMODE_QUAD                   = 0x2,
};
enum HASHPOLY {
    DRV_HASHPOLY_ECMP_CRC8                       = 0x0,
    DRV_HASHPOLY_LINKAGG_CRC8                    = 0x1,
    DRV_HASHPOLY_XOR8                            = 0x2,
    DRV_HASHPOLY_FLOWPOLY1                       = 0x3,
    DRV_HASHPOLY_FLOWPOLY2                       = 0x4,
    DRV_HASHPOLY_FLOWPOLY3                       = 0x5,
    DRV_HASHPOLY_FLOWPOLY4                       = 0x6,
    DRV_HASHPOLY_FLOWPOLY5                       = 0x7,
    DRV_HASHPOLY_FLOWPOLY6                       = 0x8,
    DRV_HASHPOLY_FLOWPOLY7                       = 0x9,
    DRV_HASHPOLY_FLOWPOLY8                       = 0xa,
    DRV_HASHPOLY_SYMMETRICALV4                   = 0xb,
    DRV_HASHPOLY_SYMMETRICALV6                   = 0xc,
};
enum IPEEXCEPTIONINDEX {
    DRV_IPEEXCEPTIONINDEX_USERID_EXCEPTION       = 0x0,
    DRV_IPEEXCEPTIONINDEX_PROTOCOL_VLAN_EXCEPTION = 0x1,
    DRV_IPEEXCEPTIONINDEX_BRIDGE_EXCEPTION       = 0x2,
    DRV_IPEEXCEPTIONINDEX_ROUTE_EXCEPTION        = 0x3,
    DRV_IPEEXCEPTIONINDEX_ICMP_REDIRECT_EXCEPTION = 0x4,
    DRV_IPEEXCEPTIONINDEX_LEARNING_CACHE_FULL_EXCEPTION = 0x5,
    DRV_IPEEXCEPTIONINDEX_ROUTE_MULTICAST_RPFFAILURE_EXCEPTION = 0x6,
    DRV_IPEEXCEPTIONINDEX_OTHER_EXCEPTION        = 0x7,
};
enum IPEEXPIDX2SUBIDX {
    DRV_IPEEXPIDX2SUBIDX_MACSA_EXCP              = 0x3f,
    DRV_IPEEXPIDX2SUBIDX_SRC_MISMATCH_EXCP       = 0x3e,
    DRV_IPEEXPIDX2SUBIDX_PORT_SECURITY_EXCP      = 0x3d,
    DRV_IPEEXPIDX2SUBIDX_PROFILE_SECURITY_EXCP   = 0x3c,
    DRV_IPEEXPIDX2SUBIDX_VSI_SECURITY_EXCP       = 0x3b,
    DRV_IPEEXPIDX2SUBIDX_STORM_CTL_EXCP          = 0x3a,
    DRV_IPEEXPIDX2SUBIDX_PTP_EXCP                = 0x39,
    DRV_IPEEXPIDX2SUBIDX_PARSER_LEN_ERR_EXCP     = 0x38,
    DRV_IPEEXPIDX2SUBIDX_SYSTEM_SECURITY_EXCP    = 0x37,
    DRV_IPEEXPIDX2SUBIDX_MAC_SA_IS_PORTMAC       = 0x36,
    DRV_IPEEXPIDX2SUBIDX_MAC_DA_IS_PORTMAC       = 0x35,
    DRV_IPEEXPIDX2SUBIDX_MAC_SA_CONFLICT         = 0x34,
};
enum IPEEXPIDX3SUBIDX {
    DRV_IPEEXPIDX3SUBIDX_MCAST_TUNNEL_FRAG_EXCP  = 0x3f,
};
enum IPEEXPIDX7SUBIDX {
    DRV_IPEEXPIDX7SUBIDX_SGMAC_CTL_MSG           = 0x0,
    DRV_IPEEXPIDX7SUBIDX_PARSER_LEN_ERR          = 0x1,
    DRV_IPEEXPIDX7SUBIDX_PBB_TCI_NCA             = 0x2,
    DRV_IPEEXPIDX7SUBIDX_PTP_EXCP_TO_CPU         = 0x3,
    DRV_IPEEXPIDX7SUBIDX_PTP_FATAL_EXCP_TO_CPU   = 0x4,
    DRV_IPEEXPIDX7SUBIDX_PLD_OFFSET_ERR          = 0x5,
    DRV_IPEEXPIDX7SUBIDX_ACL_EXCP_TO_CPU         = 0x6,
    DRV_IPEEXPIDX7SUBIDX_ENTROPY_IS_RESERVED_LABEL = 0x7,
    DRV_IPEEXPIDX7SUBIDX_ETH_OAM_ERR             = 0x8,
    DRV_IPEEXPIDX7SUBIDX_MPLS_OAM_TTL_CHK_FAIL   = 0x9,
    DRV_IPEEXPIDX7SUBIDX_MPLS_TMPLS_OAM          = 0xa,
    DRV_IPEEXPIDX7SUBIDX_DCN_EXCP                = 0xb,
    DRV_IPEEXPIDX7SUBIDX_VXLAN_NVGRE_INNER_VTAG_CHK = 0xc,
    DRV_IPEEXPIDX7SUBIDX_ACH_ERR                 = 0xd,
    DRV_IPEEXPIDX7SUBIDX_SECTION_OAM_EXCP        = 0xe,
    DRV_IPEEXPIDX7SUBIDX_OAM_HASH_LKP_CONFLICT   = 0xf,
    DRV_IPEEXPIDX7SUBIDX_NO_MEP_MIP_DIS          = 0x10,
    DRV_IPEEXPIDX7SUBIDX_FLOW_DEBUG              = 0x11,
    DRV_IPEEXPIDX7SUBIDX_IPFIX_HASHCONFLICT      = 0x12,
    DRV_IPEEXPIDX7SUBIDX_FIND_NEW_ELEPHANT_FLOW  = 0x13,
    DRV_IPEEXPIDX7SUBIDX_VXLAN_FLAG_CHK_ERROR    = 0x14,
    DRV_IPEEXPIDX7SUBIDX_QUE_DROP_SPAN_EXCP      = 0x15,
};
enum IPEIFSTATSTYPE {
    DRV_IPEIFSTATSTYPE_LOGIC                     = 0x0,
    DRV_IPEIFSTATSTYPE_PORT                      = 0x1,
    DRV_IPEIFSTATSTYPE_L3IF                      = 0x2,
};
enum IPELMPACKETTYPE {
    DRV_IPELMPACKETTYPE_CCM                      = 0x4,
    DRV_IPELMPACKETTYPE_LMM                      = 0x5,
    DRV_IPELMPACKETTYPE_LMR                      = 0x6,
    DRV_IPELMPACKETTYPE_ACH                      = 0x7,
    DRV_IPELMPACKETTYPE_NONE                     = 0x0,
};
enum IPFIXEXPORTREASON {
    DRV_IPFIXEXPORTREASON_NO_EXPORT              = 0x0,
    DRV_IPFIXEXPORTREASON_EXPIRED                = 0x1,
    DRV_IPFIXEXPORTREASON_TCP_SESSION_CLOSE      = 0x2,
    DRV_IPFIXEXPORTREASON_PACKET_COUNT_OVERFLOW  = 0x3,
    DRV_IPFIXEXPORTREASON_BYTE_COUNT_OVERFLOW    = 0x4,
    DRV_IPFIXEXPORTREASON_TS_COUNT_OVERFLOW      = 0x5,
    DRV_IPFIXEXPORTREASON_CONFLICT_EXPORT        = 0x6,
};
enum IPV4KEYTYPE {
    DRV_IPV4KEYTYPE_IPUC                         = 0x0,
    DRV_IPV4KEYTYPE_IPMC                         = 0x1,
    DRV_IPV4KEYTYPE_L2MC                         = 0x2,
    DRV_IPV4KEYTYPE_NATSA                        = 0x3,
};
enum L2EDITEXTTYPE {
    DRV_L2EDITEXTTYPE_NONE                       = 0x0,
    DRV_L2EDITEXTTYPE_ETHERNET                   = 0x1,
    DRV_L2EDITEXTTYPE_MPLS                       = 0x2,
    DRV_L2EDITEXTTYPE_NOL2EDIT                   = 0x3,
};
enum L2REWRITETYPE {
    DRV_L2REWRITETYPE_NONE                       = 0x0,
    DRV_L2REWRITETYPE_LOOPBACK                   = 0x1,
    DRV_L2REWRITETYPE_ETH4W                      = 0x2,
    DRV_L2REWRITETYPE_ETH8W                      = 0x3,
    DRV_L2REWRITETYPE_MAC_SWAP                   = 0x4,
    DRV_L2REWRITETYPE_L2FLEX                     = 0x5,
    DRV_L2REWRITETYPE_PBB4W                      = 0x6,
    DRV_L2REWRITETYPE_PBB8W                      = 0x7,
    DRV_L2REWRITETYPE_OF                         = 0x8,
    DRV_L2REWRITETYPE_INNER_SWAP                 = 0x9,
    DRV_L2REWRITETYPE_INNER_DS_LITE              = 0xa,
};
enum L2TYPE {
    DRV_L2TYPE_NONE                              = 0x0,
    DRV_L2TYPE_ETHV2                             = 0x1,
    DRV_L2TYPE_ETHSAP                            = 0x2,
    DRV_L2TYPE_ETHSNAP                           = 0x3,
};
enum L3IFTYPE {
    DRV_L3IFTYPE_EXTERNAL                        = 0x0,
    DRV_L3IFTYPE_INTERNAL                        = 0x1,
};
enum L3PACKETTYPE {
    DRV_L3PACKETTYPE_IPV4                        = 0x0,
    DRV_L3PACKETTYPE_ARP                         = 0x1,
    DRV_L3PACKETTYPE_MPLS                        = 0x2,
    DRV_L3PACKETTYPE_RESERVE                     = 0x3,
};
enum L3REWRITETYPE {
    DRV_L3REWRITETYPE_NONE                       = 0x0,
    DRV_L3REWRITETYPE_MPLS4W                     = 0x1,
    DRV_L3REWRITETYPE_RESERVED                   = 0x2,
    DRV_L3REWRITETYPE_NAT4W                      = 0x3,
    DRV_L3REWRITETYPE_NAT8W                      = 0x4,
    DRV_L3REWRITETYPE_TUNNELV4                   = 0x5,
    DRV_L3REWRITETYPE_TUNNELV6                   = 0x6,
    DRV_L3REWRITETYPE_L3FLEX                     = 0x7,
    DRV_L3REWRITETYPE_OF8W                       = 0x8,
    DRV_L3REWRITETYPE_OF16W                      = 0x9,
    DRV_L3REWRITETYPE_LOOPBACK                   = 0xa,
    DRV_L3REWRITETYPE_TRILL                      = 0xb,
};
enum L3TYPE {
    DRV_L3TYPE_NONE                              = 0x0,
    DRV_L3TYPE_IP                                = 0x1,
    DRV_L3TYPE_IPV4                              = 0x2,
    DRV_L3TYPE_IPV6                              = 0x3,
    DRV_L3TYPE_MPLS                              = 0x4,
    DRV_L3TYPE_MPLSUP                            = 0x5,
    DRV_L3TYPE_ARP                               = 0x6,
    DRV_L3TYPE_FCOE                              = 0x7,
    DRV_L3TYPE_TRILL                             = 0x8,
    DRV_L3TYPE_ETHEROAM                          = 0x9,
    DRV_L3TYPE_SLOWPROTO                         = 0xa,
    DRV_L3TYPE_CMAC                              = 0xb,
    DRV_L3TYPE_PTP                               = 0xc,
    DRV_L3TYPE_FLEXIBLE                          = 0xf,
};
enum L4TYPE {
    DRV_L4TYPE_NONE                              = 0x0,
    DRV_L4TYPE_TCP                               = 0x1,
    DRV_L4TYPE_UDP                               = 0x2,
    DRV_L4TYPE_GRE                               = 0x3,
    DRV_L4TYPE_IPINIP                            = 0x4,
    DRV_L4TYPE_V6INIP                            = 0x5,
    DRV_L4TYPE_ICMP                              = 0x6,
    DRV_L4TYPE_IGMP                              = 0x7,
    DRV_L4TYPE_IPINV6                            = 0x8,
    DRV_L4TYPE_PBBITAGOAM                        = 0x9,
    DRV_L4TYPE_ACHOAM                            = 0xa,
    DRV_L4TYPE_V6INV6                            = 0xb,
    DRV_L4TYPE_RDP                               = 0xc,
    DRV_L4TYPE_SCTP                              = 0xd,
    DRV_L4TYPE_DCCP                              = 0xe,
    DRV_L4TYPE_FLEXIBLE                          = 0xf,
};
enum LAYER4USERACHOAMTYPE {
    DRV_LAYER4USERACHOAMTYPE_NONE                = 0x0,
    DRV_LAYER4USERACHOAMTYPE_ACHY1731            = 0x1,
    DRV_LAYER4USERACHOAMTYPE_ACHBFD              = 0x2,
    DRV_LAYER4USERACHOAMTYPE_ACHCC               = 0x3,
    DRV_LAYER4USERACHOAMTYPE_ACHCV               = 0x4,
    DRV_LAYER4USERACHOAMTYPE_ACHDLM              = 0x5,
    DRV_LAYER4USERACHOAMTYPE_ACHILM              = 0x6,
    DRV_LAYER4USERACHOAMTYPE_ACHILMDM            = 0x7,
    DRV_LAYER4USERACHOAMTYPE_ACHDLMDM            = 0x8,
    DRV_LAYER4USERACHOAMTYPE_ACHDM               = 0x9,
    DRV_LAYER4USERACHOAMTYPE_MCC                 = 0xa,
    DRV_LAYER4USERACHOAMTYPE_SCC                 = 0xb,
};
enum LAYER4USERUDPTYPE {
    DRV_LAYER4USERUDPTYPE_NONE                   = 0x0,
    DRV_LAYER4USERUDPTYPE_BFD                    = 0x1,
    DRV_LAYER4USERUDPTYPE_UDPPTP                 = 0x2,
    DRV_LAYER4USERUDPTYPE_CAPWAP                 = 0x3,
    DRV_LAYER4USERUDPTYPE_NTP                    = 0x4,
    DRV_LAYER4USERUDPTYPE_VXLAN                  = 0x5,
};
enum LMLOOKUPTYPE {
    DRV_LMLOOKUPTYPE_NONE                        = 0x0,
    DRV_LMLOOKUPTYPE_ETHERLM                     = 0x1,
    DRV_LMLOOKUPTYPE_MPLSLM                      = 0x2,
};
enum LPMTCAMKEYSIZE {
    DRV_LPMTCAMKEYSIZE_LPMTCAMHALFKEY            = 0x0,
    DRV_LPMTCAMKEYSIZE_LPMTCAMSINGLEKEY          = 0x1,
    DRV_LPMTCAMKEYSIZE_LPMTCAMDOUBLEKEY          = 0x2,
};
enum LPMTCAMYPE {
    DRV_LPMTCAMYPE_LPMIPV4UCAST                  = 0x0,
    DRV_LPMTCAMYPE_LPMIPV6UCAST                  = 0x1,
    DRV_LPMTCAMYPE_LPMIPV4RPF                    = 0x2,
    DRV_LPMTCAMYPE_LPMIPV6RPF                    = 0x3,
    DRV_LPMTCAMYPE_LPMIPV4PBR                    = 0x4,
    DRV_LPMTCAMYPE_LPMIPV6PBR                    = 0x5,
    DRV_LPMTCAMYPE_IPV4NAT                       = 0x6,
    DRV_LPMTCAMYPE_IPV6NAT                       = 0x7,
};
enum MASKSELECTTYPE {
    DRV_MASKSELECTTYPE_ECMP                      = 0x0,
    DRV_MASKSELECTTYPE_LINKAGG                   = 0x1,
    DRV_MASKSELECTTYPE_FLOW                      = 0x2,
};
enum MEPTYPE {
    DRV_MEPTYPE_ETH_CCM_MEP                      = 0x0,
    DRV_MEPTYPE_PBT_CCM_MEP                      = 0x1,
    DRV_MEPTYPE_TRILL_BFD_MEP                    = 0x2,
    DRV_MEPTYPE_FFD_MEP                          = 0x3,
    DRV_MEPTYPE_CV1_MEP                          = 0x4,
    DRV_MEPTYPE_BFD_MEP                          = 0x5,
    DRV_MEPTYPE_ACH_Y1731_MEP                    = 0x6,
    DRV_MEPTYPE_ACH_BFD_MEP                      = 0x7,
};
enum MICROFLOWMETADATATYPE {
    DRV_MICROFLOWMETADATATYPE_METADATA           = 0x0,
    DRV_MICROFLOWMETADATATYPE_LOGICPORT          = 0x1,
    DRV_MICROFLOWMETADATATYPE_GLOBALPORT         = 0x2,
    DRV_MICROFLOWMETADATATYPE_VLANPTR            = 0x3,
};
enum MUXTYPE {
    DRV_MUXTYPE_NOMUX                            = 0x0,
    DRV_MUXTYPE_MUXDEMUX                         = 0x1,
    DRV_MUXTYPE_EVB                              = 0x2,
    DRV_MUXTYPE_CB_DOWNLINK                      = 0x3,
    DRV_MUXTYPE_PE_DOWNLINK_WITH_CASCADE_PORT    = 0x4,
    DRV_MUXTYPE_PE_UPLINK                        = 0x5,
    DRV_MUXTYPE_BHDR_WITHOUT_TUNNEL              = 0x6,
    DRV_MUXTYPE_BHDR_WITH_L2                     = 0x7,
    DRV_MUXTYPE_BHDR_WITH_L2_IPV4                = 0x8,
    DRV_MUXTYPE_BHDR_WITH_L2_IPV6                = 0x9,
    DRV_MUXTYPE_BHDR_IPV4                        = 0xa,
    DRV_MUXTYPE_BHDR_IPV6                        = 0xb,
};
enum NEWTTLPACKETTYPE {
    DRV_NEWTTLPACKETTYPE_IPV4                    = 0x0,
    DRV_NEWTTLPACKETTYPE_IPV6                    = 0x1,
    DRV_NEWTTLPACKETTYPE_MPLS                    = 0x2,
    DRV_NEWTTLPACKETTYPE_TRILL                   = 0x3,
};
enum NHPSHARETYPE {
    DRV_NHPSHARETYPE_L2EDIT_PLUS_L3EDIT_OP       = 0x0,
    DRV_NHPSHARETYPE_VLANTAG_OP                  = 0x1,
    DRV_NHPSHARETYPE_L2EDIT_PLUS_STAG_OP         = 0x2,
};
enum OAMEXCEPTIONTYPE {
    DRV_OAMEXCEPTIONTYPE_NONE                    = 0x0,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_INVALID   = 0x1,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_LB        = 0x2,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_LT        = 0x3,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_LM        = 0x4,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_DM        = 0x5,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_TST       = 0x6,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_APS       = 0x7,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_SCC       = 0x8,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_MCC       = 0x9,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_CSF       = 0xa,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_BIG_CCM   = 0xb,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_LEARN_CCM = 0xc,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_DEFECT    = 0xd,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_PBX_OAM       = 0xe,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_HIGH_VER  = 0xf,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_TLV       = 0x10,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_ETH_OTHER     = 0x11,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_BFD_INVALID   = 0x12,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_BFD_LEARN     = 0x13,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_BIG_BFD       = 0x14,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_BFD_TIMER_NEG = 0x15,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_TP_SCC        = 0x16,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_TP_MCC        = 0x17,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_TP_CSF        = 0x18,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_TP_LB         = 0x19,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_TP_DLM        = 0x1a,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_TP_DM         = 0x1b,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_TP_FM         = 0x1c,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_BFD_OTHER     = 0x1d,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_BFD_DISC_MISMATCH = 0x1e,
    DRV_OAMEXCEPTIONTYPE_EXCEPTION_TP_CV         = 0x20,
};
enum OAMLOOKUPTYPE {
    DRV_OAMLOOKUPTYPE_NONE                       = 0x0,
    DRV_OAMLOOKUPTYPE_MPLSLABEL                  = 0x1,
    DRV_OAMLOOKUPTYPE_MPLSSECTION                = 0x2,
    DRV_OAMLOOKUPTYPE_ETHEROAM                   = 0x3,
    DRV_OAMLOOKUPTYPE_BFDOAM                     = 0x4,
    DRV_OAMLOOKUPTYPE_ETHERRMEP                  = 0x5,
};
enum OAMOPCODE {
    DRV_OAMOPCODE_CCM                            = 0x1,
    DRV_OAMOPCODE_LBR                            = 0x2,
    DRV_OAMOPCODE_LBM                            = 0x3,
    DRV_OAMOPCODE_LTR                            = 0x4,
    DRV_OAMOPCODE_LTM                            = 0x5,
    DRV_OAMOPCODE_AIS                            = 0x21,
    DRV_OAMOPCODE_LCK                            = 0x23,
    DRV_OAMOPCODE_TST                            = 0x25,
    DRV_OAMOPCODE_LINEARAPS                      = 0x27,
    DRV_OAMOPCODE_RINGAPS                        = 0x28,
    DRV_OAMOPCODE_MCC                            = 0x29,
    DRV_OAMOPCODE_LMR                            = 0x2a,
    DRV_OAMOPCODE_LMM                            = 0x2b,
    DRV_OAMOPCODE__1DM                           = 0x2d,
    DRV_OAMOPCODE_DMR                            = 0x2e,
    DRV_OAMOPCODE_DMM                            = 0x2f,
};
enum OAMTYPE {
    DRV_OAMTYPE_NONE                             = 0x0,
    DRV_OAMTYPE_ETHER_CCM                        = 0x1,
    DRV_OAMTYPE_ETHER_APS                        = 0x2,
    DRV_OAMTYPE_ETHER_1DM                        = 0x3,
    DRV_OAMTYPE_ETHER_DMM                        = 0x4,
    DRV_OAMTYPE_ETHER_DMR                        = 0x5,
    DRV_OAMTYPE_ETHER_RAPS                       = 0x6,
    DRV_OAMTYPE_ETHER_LBM                        = 0x7,
    DRV_OAMTYPE_ETHER_LBR                        = 0x8,
    DRV_OAMTYPE_ETHER_LMR                        = 0x9,
    DRV_OAMTYPE_ETHER_LMM                        = 0xa,
    DRV_OAMTYPE_MPLSTP_LBM                       = 0xb,
    DRV_OAMTYPE_ETHER_TST                        = 0xc,
    DRV_OAMTYPE_ETHER_LTR                        = 0xd,
    DRV_OAMTYPE_ETHER_LTM                        = 0xe,
    DRV_OAMTYPE_ETHER_OTHER                      = 0xf,
    DRV_OAMTYPE_MPLSTP_DM                        = 0x10,
    DRV_OAMTYPE_MPLSTP_DLM                       = 0x11,
    DRV_OAMTYPE_MPLSTP_DLMDM                     = 0x12,
    DRV_OAMTYPE_MPLSTP_CV                        = 0x13,
    DRV_OAMTYPE_MPLSTP_CSF                       = 0x14,
    DRV_OAMTYPE_ETHER_CSF                        = 0x15,
    DRV_OAMTYPE_ETHER_MCC                        = 0x16,
    DRV_OAMTYPE_MPLS_OTHER                       = 0x17,
    DRV_OAMTYPE_MPLSTP_MCC                       = 0x18,
    DRV_OAMTYPE_MPLSTP_FM                        = 0x19,
    DRV_OAMTYPE_RESERVED                         = 0x1a,
    DRV_OAMTYPE_RESERVED1                        = 0x1b,
    DRV_OAMTYPE_MPLS_OAM                         = 0x1c,
    DRV_OAMTYPE_BFD_OAM                          = 0x1d,
    DRV_OAMTYPE_ETHER_SCC                        = 0x1e,
    DRV_OAMTYPE_MPLSTP_SCC                       = 0x1f,
};
enum OPERATIONTYPE {
    DRV_OPERATIONTYPE_NORMAL                     = 0x0,
    DRV_OPERATIONTYPE_LMTX                       = 0x1,
    DRV_OPERATIONTYPE_RESERVED                   = 0x2,
    DRV_OPERATIONTYPE_DMTX                       = 0x3,
    DRV_OPERATIONTYPE_C2C                        = 0x4,
    DRV_OPERATIONTYPE_PTP                        = 0x5,
    DRV_OPERATIONTYPE_NAT                        = 0x6,
    DRV_OPERATIONTYPE_OAM                        = 0x7,
};
enum OTHEREXCEPTIONSUBINDEX {
    DRV_OTHEREXCEPTIONSUBINDEX_SGMAC_CTL_MSG     = 0x1,
    DRV_OTHEREXCEPTIONSUBINDEX_PARSER_LENGTH_ERROR = 0x2,
    DRV_OTHEREXCEPTIONSUBINDEX_PBBTCI_NCA        = 0x3,
    DRV_OTHEREXCEPTIONSUBINDEX_PTP               = 0x4,
    DRV_OTHEREXCEPTIONSUBINDEX_PAYLOAD_OFFSET_ERROR = 0x5,
    DRV_OTHEREXCEPTIONSUBINDEX_ACL_EXCEPTION_TO_CPU = 0x6,
    DRV_OTHEREXCEPTIONSUBINDEX_ETHERNET_OAM_ERROR = 0x8,
};
enum OUTEROPERATIONTYPE {
    DRV_OUTEROPERATIONTYPE_NORMAL                = 0x0,
    DRV_OUTEROPERATIONTYPE_RESERVED1             = 0x1,
    DRV_OUTEROPERATIONTYPE_RESERVED2             = 0x2,
    DRV_OUTEROPERATIONTYPE_DMTX                  = 0x3,
    DRV_OUTEROPERATIONTYPE_C2C                   = 0x4,
    DRV_OUTEROPERATIONTYPE_PTP                   = 0x5,
    DRV_OUTEROPERATIONTYPE_NAT                   = 0x6,
    DRV_OUTEROPERATIONTYPE_OAM                   = 0x7,
};
enum PACKETTYPE {
    DRV_PACKETTYPE_ETHERNET                      = 0x0,
    DRV_PACKETTYPE_IPV4                          = 0x1,
    DRV_PACKETTYPE_MPLS                          = 0x2,
    DRV_PACKETTYPE_IPV6                          = 0x3,
    DRV_PACKETTYPE_MPLSUP                        = 0x4,
    DRV_PACKETTYPE_IP                            = 0x5,
    DRV_PACKETTYPE_FLEXIBLE                      = 0x6,
    DRV_PACKETTYPE_RESERVED                      = 0x7,
};
enum PARSERTYPE {
    DRV_PARSERTYPE_IPEHEADERADJUST               = 0x0,
    DRV_PARSERTYPE_IPETUNNEL                     = 0x1,
};
enum PAYLOADOPERATION {
    DRV_PAYLOADOPERATION_NONE                    = 0x0,
    DRV_PAYLOADOPERATION_ROUTE                   = 0x1,
    DRV_PAYLOADOPERATION_BRIDGE                  = 0x2,
    DRV_PAYLOADOPERATION_BRIDGE_VPLS             = 0x3,
    DRV_PAYLOADOPERATION_BRIDGE_INNER            = 0x4,
    DRV_PAYLOADOPERATION_MIRROR                  = 0x5,
    DRV_PAYLOADOPERATION_ROUTE_NOTTL             = 0x6,
    DRV_PAYLOADOPERATION_ROUTE_COMPACT           = 0x7,
};
enum PBBPORTTYPE {
    DRV_PBBPORTTYPE_NONEPBBPORT                  = 0x0,
    DRV_PBBPORTTYPE_PIP                          = 0x1,
    DRV_PBBPORTTYPE_CBP                          = 0x2,
    DRV_PBBPORTTYPE_PNP                          = 0x3,
    DRV_PBBPORTTYPE_CNP                          = 0x4,
};
enum PTPMESSAGETYPE {
    DRV_PTPMESSAGETYPE_SYNC                      = 0x0,
    DRV_PTPMESSAGETYPE_DELAY_REQ                 = 0x1,
    DRV_PTPMESSAGETYPE_PDELAY_REQ                = 0x2,
    DRV_PTPMESSAGETYPE_PDELAY_RESP               = 0x3,
    DRV_PTPMESSAGETYPE_FOLLOWUP                  = 0x8,
    DRV_PTPMESSAGETYPE_DELAYR_RESP               = 0x9,
    DRV_PTPMESSAGETYPE_PDELAY_RESP_FOLLOWUP      = 0xa,
    DRV_PTPMESSAGETYPE_ANNOUNCE                  = 0xb,
    DRV_PTPMESSAGETYPE_SINGNALING                = 0xc,
    DRV_PTPMESSAGETYPE_MANAGEMENT                = 0xd,
};
enum PTPOFFSETTYPE {
    DRV_PTPOFFSETTYPE_PTPV1                      = 0x0,
    DRV_PTPOFFSETTYPE_PTPV2                      = 0x1,
    DRV_PTPOFFSETTYPE_RESERVED                   = 0x2,
    DRV_PTPOFFSETTYPE_OTHER                      = 0x3,
};
enum PTPOPMODE {
    DRV_PTPOPMODE_NONE                           = 0x0,
    DRV_PTPOPMODE_CAPTURE                        = 0x1,
    DRV_PTPOPMODE_REPLACE                        = 0x2,
};
enum QOSPOLICY {
    DRV_QOSPOLICY_INVALID                        = 0x0,
    DRV_QOSPOLICY_TRUST_PORT                     = 0x1,
    DRV_QOSPOLICY_COPY_OUTER                     = 0x2,
    DRV_QOSPOLICY_TRUST_COS                      = 0x3,
    DRV_QOSPOLICY_TRUST_DSCP                     = 0x4,
    DRV_QOSPOLICY_TRUST_IP_PREC                  = 0x5,
    DRV_QOSPOLICY_TRUST_STAG_COS                 = 0x6,
    DRV_QOSPOLICY_TRUST_CTAG_COS                 = 0x7,
};
enum RANDOMFUNCID {
    DRV_RANDOMFUNCID_INGRESS_PORT                = 0x0,
    DRV_RANDOMFUNCID_EGRESS_PORT                 = 0x1,
    DRV_RANDOMFUNCID_INGRESS_SCL0                = 0x2,
    DRV_RANDOMFUNCID_INGRESS_SCL1                = 0x3,
    DRV_RANDOMFUNCID_INGRESS_ACL0                = 0x4,
    DRV_RANDOMFUNCID_INGRESS_ACL1                = 0x5,
    DRV_RANDOMFUNCID_INGRESS_ACL2                = 0x6,
    DRV_RANDOMFUNCID_INGRESS_ACL3                = 0x7,
    DRV_RANDOMFUNCID_EGRESS_ACL0                 = 0x8,
    DRV_RANDOMFUNCID_EGRESS_EXCP                 = 0x9,
    DRV_RANDOMFUNCID_ECMP                        = 0xa,
    DRV_RANDOMFUNCID_AGG                         = 0xb,
};
enum RANGE {
    DRV_RANGE__8WTO4W_UP                         = 0x0,
    DRV_RANGE__8WTO4W_DOWN                       = 0x1,
    DRV_RANGE__4WTO8W_UP                         = 0x2,
    DRV_RANGE__4WTO8W_DOWN                       = 0x3,
    DRV_RANGE_UP6W                               = 0x4,
    DRV_RANGE_UP3W                               = 0x5,
    DRV_RANGE_DOWN6W                             = 0x6,
    DRV_RANGE_DOWN3W                             = 0x7,
};
enum RDTYPE {
    DRV_RDTYPE_RD_12WORD_EN                      = 0x0,
    DRV_RDTYPE_RD_6WORD_EN                       = 0x1,
    DRV_RDTYPE_RD_3WORD_EN                       = 0x2,
};
enum RXOAMTYPE {
    DRV_RXOAMTYPE_NONE                           = 0x0,
    DRV_RXOAMTYPE_ETHEROAM                       = 0x1,
    DRV_RXOAMTYPE_IPBFD                          = 0x2,
    DRV_RXOAMTYPE_PBTOAM                         = 0x3,
    DRV_RXOAMTYPE_PBBBSI                         = 0x4,
    DRV_RXOAMTYPE_PBBBV                          = 0x5,
    DRV_RXOAMTYPE_MPLSOAM                        = 0x6,
    DRV_RXOAMTYPE_MPLSBFD                        = 0x7,
    DRV_RXOAMTYPE_ACHOAM                         = 0x8,
    DRV_RXOAMTYPE_TRILLBFD                       = 0xa,
};
enum SERVICEPOLICERMODE {
    DRV_SERVICEPOLICERMODE_MEF_HBWP              = 0x0,
    DRV_SERVICEPOLICERMODE_TRIPLY_PLAY           = 0x1,
};
enum SHARETYPE {
    DRV_SHARETYPE_NONE                           = 0x0,
    DRV_SHARETYPE_NAT                            = 0x1,
    DRV_SHARETYPE_LMTX                           = 0x2,
    DRV_SHARETYPE_PTP                            = 0x3,
    DRV_SHARETYPE_OAM                            = 0x4,
    DRV_SHARETYPE_DMTX                           = 0x5,
};
enum STATSTYPE {
    DRV_STATSTYPE_POLICING                       = 0x0,
    DRV_STATSTYPE_IPEINTERFACE                   = 0x1,
    DRV_STATSTYPE_IPEFWD                         = 0x2,
    DRV_STATSTYPE_IPEACL0                        = 0x3,
    DRV_STATSTYPE_IPEACL1                        = 0x4,
    DRV_STATSTYPE_IPEACL2                        = 0x5,
    DRV_STATSTYPE_IPEACL3                        = 0x6,
    DRV_STATSTYPE_EPEINTERFACE                   = 0x7,
    DRV_STATSTYPE_EPEFWD                         = 0x8,
    DRV_STATSTYPE_EPEACL0                        = 0x9,
    DRV_STATSTYPE_ENQUEUE                        = 0xa,
    DRV_STATSTYPE_DEQUEUE                        = 0xb,
};
enum TCAMINTERFACEID {
    DRV_TCAMINTERFACEID_USERID                   = 0x0,
    DRV_TCAMINTERFACEID_INGACL                   = 0x1,
    DRV_TCAMINTERFACEID_EGRACL                   = 0x2,
    DRV_TCAMINTERFACEID_RESERVED                 = 0x3,
};
enum TCAMKEYSIZE {
    DRV_TCAMKEYSIZE_TCAMKEYSIZE160               = 0x0,
    DRV_TCAMKEYSIZE_TCAMKEYSIZE320               = 0x1,
    DRV_TCAMKEYSIZE_TCAMKEYSIZE640               = 0x2,
};
enum TCAMKEYTYPE {
    DRV_TCAMKEYTYPE_MACKEY160                    = 0x0,
    DRV_TCAMKEYTYPE_MACL3KEY320                  = 0x1,
    DRV_TCAMKEYTYPE_L3KEY160                     = 0x2,
    DRV_TCAMKEYTYPE_IPV6KEY640                   = 0x3,
};
enum TMMSGTYPE {
    DRV_TMMSGTYPE_NONE                           = 0x0,
    DRV_TMMSGTYPE_EOP                            = 0x1,
    DRV_TMMSGTYPE_SOP                            = 0x2,
    DRV_TMMSGTYPE_SOP_EOP                        = 0x3,
};
enum UDFTYPE {
    DRV_UDFTYPE_L2UDF                            = 0x0,
    DRV_UDFTYPE_L3UDF                            = 0x1,
    DRV_UDFTYPE_L4UDF                            = 0x2,
    DRV_UDFTYPE_METADATA                         = 0x3,
};
enum VLANIDACTIONTYPE {
    DRV_VLANIDACTIONTYPE_NONE                    = 0x0,
    DRV_VLANIDACTIONTYPE_SWAP                    = 0x1,
    DRV_VLANIDACTIONTYPE_USER                    = 0x2,
};
enum VTAGACTIONTYPE {
    DRV_VTAGACTIONTYPE_NONE                      = 0x0,
    DRV_VTAGACTIONTYPE_MODIFY                    = 0x1,
    DRV_VTAGACTIONTYPE_ADD                       = 0x2,
    DRV_VTAGACTIONTYPE_DELETE                    = 0x3,
};
enum EGRESSXCOAMHASHTYPE {
    EGRESSXCOAMHASHTYPE_DISABLE              = 0x0,
    EGRESSXCOAMHASHTYPE_DOUBLEVLANPORT       = 0x1,
    EGRESSXCOAMHASHTYPE_SVLANPORT            = 0x2,
    EGRESSXCOAMHASHTYPE_CVLANPORT            = 0x3,
    EGRESSXCOAMHASHTYPE_SVLANCOSPORT         = 0x4,
    EGRESSXCOAMHASHTYPE_CVLANCOSPORT         = 0x5,
    EGRESSXCOAMHASHTYPE_PORTVLANCROSS        = 0x6,
    EGRESSXCOAMHASHTYPE_PORTCROSS            = 0x7,
    EGRESSXCOAMHASHTYPE_PORT                 = 0x8,
    EGRESSXCOAMHASHTYPE_SVLANPORTMAC         = 0x9,
    EGRESSXCOAMHASHTYPE_TUNNELPBB            = 0xa,
    EGRESSXCOAMHASHTYPE_ETH                  = 0x10,
    EGRESSXCOAMHASHTYPE_BFD                  = 0x11,
    EGRESSXCOAMHASHTYPE_MPLSLABEL            = 0x12,
    EGRESSXCOAMHASHTYPE_MPLSSECTION          = 0x13,
    EGRESSXCOAMHASHTYPE_RMEP                 = 0x14,
};

enum FIBHOST0PRIMARYHASHTYPE {
    FIBHOST0PRIMARYHASHTYPE_FCOE             = 0x0,
    FIBHOST0PRIMARYHASHTYPE_IPV4             = 0x1,
    FIBHOST0PRIMARYHASHTYPE_IPV6MCAST        = 0x2,
    FIBHOST0PRIMARYHASHTYPE_IPV6UCAST        = 0x3,
    FIBHOST0PRIMARYHASHTYPE_MAC              = 0x4,
    FIBHOST0PRIMARYHASHTYPE_MACIPV6MCAST     = 0x5,
    FIBHOST0PRIMARYHASHTYPE_TRILL            = 0x6,
};

enum FIBHOST1PRIMARYHASHTYPE {
    FIBHOST1PRIMARYHASHTYPE_IPV4             = 0x0,
    FIBHOST1PRIMARYHASHTYPE_IPV6NATDA        = 0x1,
    FIBHOST1PRIMARYHASHTYPE_IPV6NATSA        = 0x2,
    FIBHOST1PRIMARYHASHTYPE_OTHER            = 0x3,
};

enum FLOWHASHTYPE {
    FLOWHASHTYPE_INVALID                     = 0x0,
    FLOWHASHTYPE_L2                          = 0x1,
    FLOWHASHTYPE_L2L3                        = 0x2,
    FLOWHASHTYPE_L3IPV4                      = 0x3,
    FLOWHASHTYPE_L3IPV6                      = 0x4,
    FLOWHASHTYPE_L3MPLS                      = 0x5,
};

enum IPFIXHASHTYPE {
    IPFIXHASHTYPE_INVALID                    = 0x0,
    IPFIXHASHTYPE_L2                         = 0x1,
    IPFIXHASHTYPE_L2L3                       = 0x2,
    IPFIXHASHTYPE_L3IPV4                     = 0x3,
    IPFIXHASHTYPE_L3IPV6                     = 0x4,
    IPFIXHASHTYPE_L3MPLS                     = 0x5,
};

enum OAMHASHTYPE {
    OAMHASHTYPE_ETH                          = 0x0,
    OAMHASHTYPE_BFD                          = 0x1,
    OAMHASHTYPE_MPLSLABEL                    = 0x2,
    OAMHASHTYPE_MPLSSECTION                  = 0x3,
    OAMHASHTYPE_RMEP                         = 0x4,
};

enum USERIDHASHTYPE {
    USERIDHASHTYPE_DISABLE                   = 0x0,
    USERIDHASHTYPE_DOUBLEVLANPORT            = 0x1,
    USERIDHASHTYPE_SVLANPORT                 = 0x2,
    USERIDHASHTYPE_CVLANPORT                 = 0x3,
    USERIDHASHTYPE_SVLANCOSPORT              = 0x4,
    USERIDHASHTYPE_CVLANCOSPORT              = 0x5,
    USERIDHASHTYPE_MACPORT                   = 0x6,
    USERIDHASHTYPE_IPV4PORT                  = 0x7,
    USERIDHASHTYPE_MAC                       = 0x8,
    USERIDHASHTYPE_IPV4SA                    = 0x9,
    USERIDHASHTYPE_PORT                      = 0xa,
    USERIDHASHTYPE_SVLANMACSA                = 0xb,
    USERIDHASHTYPE_SVLAN                     = 0xc,
    USERIDHASHTYPE_IPV6SA                    = 0xd,
    USERIDHASHTYPE_IPV6PORT                  = 0xe,
    USERIDHASHTYPE_TUNNELIPV4                = 0xf,
    USERIDHASHTYPE_TUNNELIPV4GREKEY          = 0x10,
    USERIDHASHTYPE_TUNNELIPV4UDP             = 0x11,
    USERIDHASHTYPE_TUNNELPBB                 = 0x12,
    USERIDHASHTYPE_TUNNELTRILLUCRPF          = 0x13,
    USERIDHASHTYPE_TUNNELTRILLUCDECAP        = 0x14,
    USERIDHASHTYPE_TUNNELTRILLMCRPF          = 0x15,
    USERIDHASHTYPE_TUNNELTRILLMCDECAP        = 0x16,
    USERIDHASHTYPE_TUNNELTRILLMCADJ          = 0x17,
    USERIDHASHTYPE_TUNNELIPV4RPF             = 0x18,
    USERIDHASHTYPE_TUNNELIPV4UCVXLANMODE0    = 0x19,
    USERIDHASHTYPE_TUNNELIPV4UCVXLANMODE1    = 0x1a,
    USERIDHASHTYPE_TUNNELIPV6UCVXLANMODE0    = 0x1b,
    USERIDHASHTYPE_TUNNELIPV6UCVXLANMODE1    = 0x1c,
    USERIDHASHTYPE_TUNNELIPV4UCNVGREMODE0    = 0x1d,
    USERIDHASHTYPE_TUNNELIPV4UCNVGREMODE1    = 0x1e,
    USERIDHASHTYPE_TUNNELIPV6UCNVGREMODE0    = 0x1f,
    USERIDHASHTYPE_TUNNELIPV6UCNVGREMODE1    = 0x20,
    USERIDHASHTYPE_TUNNELIPV4MCVXLANMODE0    = 0x21,
    USERIDHASHTYPE_TUNNELIPV4VXLANMODE1      = 0x22,
    USERIDHASHTYPE_TUNNELIPV6MCVXLANMODE0    = 0x23,
    USERIDHASHTYPE_TUNNELIPV6MCVXLANMODE1    = 0x24,
    USERIDHASHTYPE_TUNNELIPV4MCNVGREMODE0    = 0x25,
    USERIDHASHTYPE_TUNNELIPV4NVGREMODE1      = 0x26,
    USERIDHASHTYPE_TUNNELIPV6MCNVGREMODE0    = 0x27,
    USERIDHASHTYPE_TUNNELIPV6MCNVGREMODE1    = 0x28,
    USERIDHASHTYPE_TUNNELIPV4DA              = 0x29,
    USERIDHASHTYPE_TUNNELMPLS                = 0x2a,
    USERIDHASHTYPE_SCLFLOWL2                 = 0x2b,
};

enum USERIDPORTHASHTYPE {
    USERIDPORTHASHTYPE_DISABLE               = 0x0,
    USERIDPORTHASHTYPE_DOUBLEVLANPORT        = 0x1,
    USERIDPORTHASHTYPE_SVLANPORT             = 0x2,
    USERIDPORTHASHTYPE_CVLANPORT             = 0x3,
    USERIDPORTHASHTYPE_SVLANCOSPORT          = 0x4,
    USERIDPORTHASHTYPE_CVLANCOSPORT          = 0x5,
    USERIDPORTHASHTYPE_MACPORT               = 0x6,
    USERIDPORTHASHTYPE_IPSAPORT              = 0x7,
    USERIDPORTHASHTYPE_MAC                   = 0x8,
    USERIDPORTHASHTYPE_IPSA                  = 0x9,
    USERIDPORTHASHTYPE_PORT                  = 0xa,
    USERIDPORTHASHTYPE_SVLANMACSA            = 0xb,
    USERIDPORTHASHTYPE_SVLAN                 = 0xc,
    USERIDPORTHASHTYPE_TUNNEL                = 0x1d,
    USERIDPORTHASHTYPE_SCLFLOW               = 0x1e,
    USERIDPORTHASHTYPE_TRILL                 = 0x1f,
};

enum FIBHOST0HASHTYPE {
    FIBHOST0HASHTYPE_FCOE                    = 0x0,
    FIBHOST0HASHTYPE_IPV4                    = 0x1,
    FIBHOST0HASHTYPE_IPV6MCAST               = 0x2,
    FIBHOST0HASHTYPE_IPV6UCAST               = 0x3,
    FIBHOST0HASHTYPE_MAC                     = 0x4,
    FIBHOST0HASHTYPE_MACIPV6MCAST            = 0x5,
    FIBHOST0HASHTYPE_TRILL                   = 0x6,
};

enum FIBHOST1HASHTYPE {
    FIBHOST1HASHTYPE_FCOERPF                 = 0x0,
    FIBHOST1HASHTYPE_IPV4MCAST               = 0x1,
    FIBHOST1HASHTYPE_IPV4NATDAPORT           = 0x2,
    FIBHOST1HASHTYPE_IPV4NATSAPORT           = 0x3,
    FIBHOST1HASHTYPE_IPV6MCAST               = 0x4,
    FIBHOST1HASHTYPE_IPV6NATDAPORT           = 0x5,
    FIBHOST1HASHTYPE_IPV6NATSAPORT           = 0x6,
    FIBHOST1HASHTYPE_MACIPV4MCAST            = 0x7,
    FIBHOST1HASHTYPE_MACIPV6MCAST            = 0x8,
    FIBHOST1HASHTYPE_TRILLMCASTVLAN          = 0x9,
};




enum ds_slice_type_e
{
    SLICE_Share,
    SLICE_Duplicated,
    SLICE_Cascade,
    SLICE_PreCascade,
    SLICE_Default,
};
typedef enum ds_slice_type_e ds_slice_type_t;

typedef enum ds_op_type {
    Op_Default = 1,
    Op_ReadMux = 2,
    Op_DisBurst = 4,
    Op_DisWriteMask = 8,
} ds_op_type_t;

enum dup_address_offset_type_e
{
    SLICE_Addr_All,
    SLICE_Addr_0,
    SLICE_Addr_1,
    SLICE_Addr_Invalid,
};
typedef enum dup_address_offset_type_e dup_address_offset_type_t;


/* table extended property type */
enum ext_content_type_s
{
    EXT_INFO_TYPE_NORMAL = 0,
    EXT_INFO_TYPE_TCAM,
    EXT_INFO_TYPE_TCAM_AD,
    EXT_INFO_TYPE_TCAM_LPM_AD, /*SDK Modify*/
    EXT_INFO_TYPE_TCAM_NAT_AD, /*SDK Modify*/

    EXT_INFO_TYPE_LPM_TCAM_IP,
    EXT_INFO_TYPE_LPM_TCAM_NAT,
    EXT_INFO_TYPE_DESC,
    EXT_INFO_TYPE_DBG,
    EXT_INFO_TYPE_DYNAMIC,
    EXT_INFO_TYPE_INVALID,
};
typedef enum ext_content_type_s ext_content_type_t;

/* Unified tables extended property structure */
struct tbls_ext_info_s
{
    ext_content_type_t ext_content_type;
    void *ptr_ext_content;
    struct tbls_ext_info_s *ptr_next;
};
typedef struct tbls_ext_info_s tbls_ext_info_t;

typedef struct {
        int word_offset;
        int start;
		int bits;
}segs_t;

typedef struct {
        char *ptr_field_name;
        int bits;
        int seg_num;
        segs_t *ptr_seg;
}fields_t;

typedef unsigned long addrs_t;


typedef struct tables_info_s {
        char *ptr_tbl_name;
        int slicetype;
        int optype;
        int entry;
        int word;
        int addr_num;
        addrs_t *addrs;
        int field_num;
        fields_t *ptr_fields;
        tbls_ext_info_t *ptr_ext_info;
}tables_info_t;

#endif /* DRV_REGISTER_H_ */
