/**
 @file ctc_stacking.h

 @author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2009-11-11

 @version v2.0

   This file contains all stacking related data structure, enum, macro and proto.
*/

#ifndef _CTC_STK_H
#define _CTC_STK_H
#ifdef __cplusplus
extern "C" {
#endif

#include "sal_types.h"
#include "ctc_const.h"
/****************************************************************
*
* Defines and Macros
*
****************************************************************/

/**
 @defgroup stacking STACKING
 @{
*/

/**
 @brief  define stacking trunk load banlance mode
*/
enum ctc_stacking_load_mode_e
{
    CTC_STK_LOAD_STATIC,    /**< [GB.GG]stacking uplink trunk use static load balance by packetHash%trunkMembers */
    CTC_STK_LOAD_DYNAMIC,    /**< [GB.GG]stacking uplink trunk use dynamic load balance by monitor traffic from the trunk member */
    CTC_STK_LOAD_STATIC_FAILOVER, /**< [GB.GG]stacking uplink trunk use failover to automatic switch to other member when member is linkdown */
    CTC_STK_LOAD_MODE_MAX
};
typedef enum ctc_stacking_load_mode_e ctc_stacking_load_mode_t;

/**
 @brief  define stacking trunk cloud header type
*/
enum ctc_stacking_hdr_flag_e
{
    CTC_STK_HDR_WITH_NONE,        /**< [GB.GG]stacking without cloud header */
    CTC_STK_HDR_WITH_L2,          /**< [GB.GG]stacking with L2 cloud header */
    CTC_STK_HDR_WITH_L2_AND_IPV4, /**< [GB.GG]stacking with L2 + IPv4  cloud header */
    CTC_STK_HDR_WITH_L2_AND_IPV6, /**< [GB.GG]stacking with L2 + IPv6 cloud header  */
    CTC_STK_HDR_WITH_IPV4,        /**< [GB.GG]stacking with IPv4 cloud header       */
    CTC_STK_HDR_WITH_IPV6         /**< [GB.GG]stacking with IPv6 cloud header       */
};
typedef enum ctc_stacking_hdr_flag_e ctc_stacking_hdr_flag_t;

/**
 @brief  define stacking property value
*/
enum ctc_stacking_prop_type_e
{
    CTC_STK_PROP_GLOBAL_CONFIG,           /**< [GB.GG]set stacking global confiure, p_value, point to ctc_stacking_glb_cfg_t*/
    CTC_STK_PROP_MCAST_STOP_RCHIP,         /** [GB.GG]set mcast stop remote chip bitmap,   p_value, point to ctc_stacking_stop_rchip_t*/
    CTC_STK_PROP_BREAK_EN,                /**< [GB.GG]if stacking exist break point , set enable(value = 1) or disable(value = 0) */
    CTC_STK_PROP_FULL_MESH_EN,            /**< [GB.GG]if stacking topo is fullmesh,  set enable(value = 1) or disable(value = 0)  */
    CTC_STK_PROP_MCAST_BREAK_POINT        /**< [GB.GG]Set mcast break point, use for ring topo, p_value, point to ctc_stacking_mcast_break_point_t*/
};
typedef enum ctc_stacking_prop_type_e ctc_stacking_prop_type_t;

/**
 @brief  define stacking cloud header global configure
*/
struct ctc_stacking_hdr_glb_s
{
    uint8  mac_da_chk_en;      /**< [GB.GG]if set, cloud header packet mac da field with be check against port mac or system mac*/
    uint8  ether_type_chk_en;  /**< [GB.GG]if set, cloud header packet ether_type field with be check against ether_type */
    uint8  cos;                /**< [GB.GG]cloud header vlan cos if exsit vlan*/
    uint8  ip_protocol;        /**< [GB.GG]cloud header ip protocol if exsit ip header, default is 255*/

    uint16 vlan_tpid;          /**< [GB.GG]cloud header vlan tpid*/
    uint16 ether_type;         /**< [GB.GG]cloud header ether type*/

    uint8  ip_ttl;             /**< [GB.GG]cloud header ip ttl if exsit ip header, default is 255*/
    uint8  ip_dscp;            /**< [GB.GG]cloud header ip dscp if exsit ip header, default is 63*/
    uint8  udp_en;             /**< [GB.GG]cloud header encap with udp header*/
    uint8  is_ipv4;            /**< [GB.GG]cloud header encap with ipv4 or ipv6*/

    union
    {
        ip_addr_t ipv4;             /**< [GB.GG]cloud heade ipv4 sourec address */
        ipv6_addr_t ipv6;           /**< [GB.GG]cloud heade ipv6 sourec address */
    } ipsa;

    uint16 udp_src_port;            /**< [GB.GG]cloud header udp source port if udp_en*/
    uint16 udp_dest_port;           /**< [GB.GG]cloud header udp destination port if udp_en*/
};
typedef struct ctc_stacking_hdr_glb_s ctc_stacking_hdr_glb_t;


/**
@brief  define stacking fabric global configure
*/
struct ctc_stacking_inter_connect_glb_s
{
     #define CTC_INTER_CONNECT_MEMBER_NUM  4
    uint8  mode;                                                        /**< [GB] Two-Chips inter-connect. 0, stacking mode; 1 interlaken mode*/
    uint16  member_port[CTC_MAX_LOCAL_CHIP_NUM][CTC_INTER_CONNECT_MEMBER_NUM];/**< [GB] Member Port is valid for stacking mode£¬Port is lport*/
    uint8  member_num;                                                  /**< [GB] Member port num for stacking mode, max is CTC_STACKING_MEMBER_NUM*/
};
typedef struct ctc_stacking_inter_connect_glb_s ctc_stacking_inter_connect_glb_t;


/**
 @brief  define stacking global configure
*/
struct ctc_stacking_glb_cfg_s
{
    ctc_stacking_hdr_glb_t hdr_glb;   /**< [GB.GG]cloud header global configure*/
    ctc_stacking_inter_connect_glb_t connect_glb;   /**< [GB]Two-Chips inter-connect global configure*/
    uint8  fabric_mode;             /**< [GG]the fabric mode of distributed system, 0:normal mode; 1:spine-leaf mode*/
};
typedef struct ctc_stacking_glb_cfg_s ctc_stacking_glb_cfg_t;

/**
 @brief  define stacking cloud header data structure
*/
struct ctc_stacking_hdr_encap_s
{
    uint32 hdr_flag;   /**< [GB.GG]encap cloud header type, refer to ctc_stacking_hdr_flag_t*/

    mac_addr_t mac_da; /**< [GB.GG]cloud header mac da if exist l2 header*/
    mac_addr_t mac_sa; /**< [GB.GG]cloud header mac sa if exist l2 header*/

    uint8  vlan_valid; /**< [GB.GG]if set, cloud header will encap vlan when using l2 header */
    uint8  rsv0;
    uint16 vlan_id;   /**< [GB.GG]cloud header vlan id if exist vlan */

    union
    {
        ip_addr_t ipv4;             /**< [GB.GG]cloud heade ipv4 destination address */
        ipv6_addr_t ipv6;           /**< [GB.GG]cloud heade ipv6 destination address */
    } ipda;

};
typedef struct ctc_stacking_hdr_encap_s ctc_stacking_hdr_encap_t;

/**
 @brief  define stacking extend mode data structure
*/
struct ctc_stacking_extend_s
{
    uint8  gchip;          /**< [GB.GG ]local gchip id, only usefull when enable extend mode*/
    uint8  enable;         /**< [GB.GG ] use gchip for extend mode*/
};
typedef struct ctc_stacking_extend_s ctc_stacking_extend_t;

/**
 @brief  define stacking trunk (uplink) data structure
*/
struct ctc_stacking_trunk_s
{
    uint8                trunk_id;       /**< [GB.GG] uplink trunk id <1-63>*/
    uint8               remote_gchip;    /**< [GB.GG] remote chip id from uplink trunk id, used for ucast path select*/
    uint32              gport;           /**< [GB.GG] uplink trunk member port used for load banlance */
    ctc_stacking_load_mode_t     load_mode;   /**< [GB.GG] uplink load banlance mode*/
    ctc_stacking_hdr_encap_t     encap_hdr;   /**< [GB.GG] uplink cloud header*/
    ctc_stacking_extend_t        extend;      /**< [GB.GG] usefull when internal is stacking connect*/
};
typedef struct ctc_stacking_trunk_s ctc_stacking_trunk_t;

/**
 @brief  define stacking keeplive member type
*/
enum ctc_stacking_keeplive_member_type_e
{
    CTC_STK_KEEPLIVE_MEMBER_TRUNK,           /**< [GB.GG]keepLive member is trunk(path select)*/
    CTC_STK_KEEPLIVE_MEMBER_PORT,            /**< [GB.GG]keepLive member is gport(master cpu port)*/
    CTC_STK_KEEPLIVE_MEMBER_MAX
};
typedef enum ctc_stacking_keeplive_member_type_e ctc_stacking_keeplive_member_type_t;

/**
 @brief  define stacking keeplive group data structure
*/
struct ctc_stacking_keeplive_s
{
    uint8  mem_type;      /**< [GB.GG] keeplive member type, refer to ctc_stacking_keeplive_member_type_t*/
    uint8  trunk_id;      /**< [GB.GG] uplink trunk id <1-63>, select one path which keeplive packet go through*/
    uint32  cpu_gport;    /**< [GB.GG] assign the master cpu port which need receive the keeplive packet*/

    ctc_stacking_extend_t extend; /**< [GB.GG] usefull when internal is stacking connect*/

};
typedef struct ctc_stacking_keeplive_s ctc_stacking_keeplive_t;


/**
 @brief  define stacking mcast stop remote chip configure
*/
struct ctc_stacking_stop_rchip_s
{
    uint32 rchip_bitmap;                       /**<[GB.GG] remote chip bitmap*/
    ctc_stacking_extend_t        extend;       /**<[GB.GG] usefull when internal is stacking connect*/
};
typedef struct ctc_stacking_stop_rchip_s ctc_stacking_stop_rchip_t;

/**
 @brief  define stacking mcast break point configure
*/
struct ctc_stacking_mcast_break_point_s
{
    uint8  trunk_id;                        /**<[GB.GG] Trunk id to set point*/
    uint8  enable;                          /**<[GB.GG] If set, trunk port will disable mcast transmit, else enable*/
};
typedef struct ctc_stacking_mcast_break_point_s ctc_stacking_mcast_break_point_t;

/**
 @brief  define stacking property data structure
*/
struct ctc_stacking_property_s
{
    uint32 prop_type;           /**< [GB.GG] confiure prorperty type , refer to ctc_stacking_property_type_t*/
    uint32 value;               /**< [GB.GG] confiure prorperty vlaue */
    void*  p_value;             /**< [GB.GG] confiure prorperty complex vlaue */

    ctc_stacking_glb_cfg_t glb_cfg;  /**< [GB.GG]confiure global configure vlaue */
};
typedef struct ctc_stacking_property_s ctc_stacking_property_t;

/**@} end of @defgroup  stacking STACKING */

#ifdef __cplusplus
}
#endif

#endif

