/****************************************************************************
 * drv_hash_db.h
 *
 * Copyright: (c)2011 Centec Networks Inc.  All rights reserved.

 * Modify History:
 * Revision:     V2.0.
 * Author:       ZhouW
 * Date:         2011-05-12.
 * Reason:       Create for GreatBelt v2.0.
 *
 * Revision:     V4.2.1
 * Revisor:      XuZx
 * Date:         2011-07-07.
 * Reason:       Revise for GreatBelt v4.2.1
 ****************************************************************************/

#ifndef _DRV_HASH_DB_H
#define _DRV_HASH_DB_H

#include "sal.h"
#include "drv_lib.h"

/**********************************************************************************
              Define Typedef, define and Data Structure
***********************************************************************************/

#define MAX_KEY_BYTE 48
#define NO_DS_AD_INDEX 0xFFFF

#define DRV_HASH_DB_BUCKET_NUM(HASH_MOD, LEVEL_IDX)   hash_db[HASH_MOD].p_level[LEVEL_IDX].bucket_num
#define DRV_HASH_DB_DEPTH(HASH_MOD, LEVEL_IDX)        hash_db[HASH_MOD].p_level[LEVEL_IDX].depth
#define DRV_HASH_DB_LEVEL_NUM(HASH_MOD)               hash_db[HASH_MOD].level_num
#define DRV_HASH_DB_KEY_NUM(HASH_MOD)                 hash_db[HASH_MOD].key_num
#define DRV_HASH_DB_KEY_TYPE(HASH_MOD, KEY_TYPE)      hash_db[HASH_MOD].key_mask_ad[KEY_TYPE].hash_type
#define DRV_HASH_DB_KEY_TBLID(HASH_MOD, KEY_TYPE)     hash_db[HASH_MOD].key_mask_ad[KEY_TYPE].key_table_id
#define DRV_HASH_DB_AD_TBLID(HASH_MOD, KEY_TYPE)      hash_db[HASH_MOD].key_mask_ad[KEY_TYPE].ad_table_id
#define DRV_HASH_DB_AD_IDXFLD(HASH_MOD, KEY_TYPE)     hash_db[HASH_MOD].key_mask_ad[KEY_TYPE].ad_index_field_id
#define DRV_HASH_DB_CAM_TBLID(HASH_MOD)               hash_db[HASH_MOD].cam_table_id

#define DRV_HASH_DB_RESET(HASH_MOD, LEVEL_NUM) \
    do\
    {\
        uint8 level = 0; \
        for (level = 0; level < LEVEL_NUM; level++) \
        { \
            DRV_HASH_DB_DEPTH(HASH_MOD, level) = 0; \
        } \
        DRV_HASH_DB_LEVEL_NUM(HASH_MOD) = LEVEL_NUM;\
    } while(0)

enum calculate_type_e
{
    HASH_CRC = 0,
    HASH_XOR  =1,
};

enum drv_hash_db_module_type_e
{
    DRV_HASH_DB_MODULE_EGRESS_XC,
    DRV_HASH_DB_MODULE_FIB_HOST0,
    DRV_HASH_DB_MODULE_FIB_HOST1,
    DRV_HASH_DB_MODULE_FLOW,
    DRV_HASH_DB_MODULE_IPFIX,
    DRV_HASH_DB_MODULE_USERID,
    DRV_HASH_DB_MODULE_NUM
};
typedef enum drv_hash_db_module_type_e drv_hash_db_module_type_t;

struct hash_crc_s
{
    uint32 type;
    uint32 poly;
    uint32 poly_len;
};

typedef struct hash_crc_s hash_crc_t;

struct hash_level_s
{
    uint32 depth;
    uint32 bucket_num ;
};

typedef struct hash_level_s hash_level_t;

struct key_mask_ad_info_s {
    uint32 hash_type;
    tbls_id_t key_table_id;
    tbls_id_t ad_table_id;
    fld_id_t ad_index_field_id;
    uint32 bits_per_unit;
    uint32 align_unit;
    uint8 mask[MAX_KEY_BYTE];
    uint8 is_ad[MAX_KEY_BYTE];
};
typedef struct key_mask_ad_info_s key_mask_ad_info_t;

struct hash_db_s {
    uint32 key_num;
    key_mask_ad_info_t *key_mask_ad;
    uint32 crc_num;
    hash_crc_t  *p_crc;
    uint32 level_num;
    hash_level_t *p_level;
    tbls_id_t cam_table_id;
};
typedef struct hash_db_s  hash_db_t;

extern hash_db_t hash_db[];

#endif

