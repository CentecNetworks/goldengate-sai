/****************************************************************************
 * drv_model_hash.h  Provides driver model hash handle function declaration.
 *
 * Copyright (C) 2012 Centec Networks Inc.  All rights reserved.
 *
 * Modify History:
 * Revision:    V1.0
 * Author       JiangSZ.
 * Date:        2012-11-27.
 * Reason:      Create for AutoGen hash module.
 ****************************************************************************/
#ifndef _DRV_MODEL_HASH_H_
#define _DRV_MODEL_HASH_H_

#include "sal.h"
#include "drv_enum.h"
#include "drv_tbl_reg.h"

extern uint32 hash_debug_on ;

#define MODEL_HASH_DEBUG_INFO(fmt, args...)  \
    do\
    {\
        if (hash_debug_on)\
        {\
            sal_printf(fmt, ##args);\
        }\
    }\
    while (0)

#define MAX_CRC_NUM 10
#define MAX_LEVEL_NUM 10

#define BIT2BYTE(bit) (((bit)+7)/8)
#define BYTE2WORD(byte) (((byte)+3)/4)

#define DRV_HASH_85BIT_KEY_LENGTH   11
#define DRV_HASH_170BIT_KEY_LENGTH   22
#define DRV_HASH_340BIT_KEY_LENGTH   44

enum hash_op_type_e
{
    HASH_OP_TP_ADD_BY_KEY,
    HASH_OP_TP_DEL_BY_KEY,
    HASH_OP_TP_ADD_BY_INDEX,
    HASH_OP_TP_DEL_BY_INDEX,
    HASH_OP_TP_MAX_VALUE,
};
typedef enum hash_op_type_e hash_op_type_t;


enum hash_module_e
{
    HASH_MODULE_EGRESS_XC,
    HASH_MODULE_FIB_HOST0,
    HASH_MODULE_FIB_HOST1,
    HASH_MODULE_FLOW,
    HASH_MODULE_IPFIX,
    HASH_MODULE_USERID,
    HASH_MODULE_NUM,
};
typedef enum hash_module_e hash_module_t;

enum hash_free_type_e
{
    HASH_FREE_TYPE_NORMAL,
    HASH_FREE_TYPE_FLOW,
    HASH_FREE_TYPE_EGRESSXCOAM,
    HASH_FREE_TYPE_NUM,
};
typedef enum hash_free_type_e hash_free_type_t;


enum l3_type_e
{
    L3_TYPE_TCP,
    L3_TYPE_UDP,
};

typedef enum l3_type_e l3_type_t;


struct level_lookup_info_s
{
    uint32 chip_id;
    uint8* key_data;
    uint32 align_unit;
    uint32 key_bits;
    uint32 polynomial;
    uint32 poly_len;
    uint32 depth;
    uint32 bucket_num;
    uint32 key_index_base;
    uint8* mask;
    uint32 type;
    tbls_id_t key_table_id;
    fld_id_t ad_index_field_id;
    tbls_id_t cam_table_id;
    hash_module_t hash_module;
    uint32 hash_type;
};

typedef struct level_lookup_info_s level_lookup_info_t;

struct level_lookup_result_s
{
    uint32 lookup_result_valid  ;
    uint32 free_num             ;
    uint32 ad_index             ;
    uint32 free_valid           ;

    uint32 key_index            ;
    uint32 aging_index          ;
    uint32 pointer              ;
    uint32 cam_depth            ;
    uint32 aging_base           ;
    uint32 level_en             ;
    uint32 cam_index            ;
    uint32 cam_units            ;
    uint32 pending              ;
    uint32 have_extra           ;
};

typedef struct level_lookup_result_s level_lookup_result_t;

struct key_lookup_result_s
{
   uint32 bucket_index;
};
typedef struct key_lookup_result_s key_lookup_result_t;

struct key_lookup_info_s
{
    uint8* key_data;
    uint32 key_bits;
    uint32 polynomial;
    uint32 poly_len;
    uint32 type;
    uint32 crc_bits;
};
typedef struct key_lookup_info_s key_lookup_info_t;


struct hash_lookup_info_s
{
    uint8 chip_id;
    uint8 hash_type;
    uint8 is_write;
    uint8 rsv0;

    uint8* p_ds_key;
    hash_module_t hash_module;

};
typedef struct hash_lookup_info_s hash_lookup_info_t;

struct hash_lookup_result_s
{
    uint32  key_index ;
    uint32  aging_index;
    uint32  ad_index;
    uint32  lookup_result_valid;
    uint32  free;
    uint32  conflict;
    uint32  is_cam;
    uint32  cam_index;
    uint32  cam_units;
    uint32  pending;
    uint32  is_blackhole;
    tbls_id_t ad_table_id;
    void *  extra;
    level_lookup_result_t level_result[MAX_LEVEL_NUM];
};
typedef struct hash_lookup_result_s hash_lookup_result_t;

struct hash_io_by_key_para_s
{
    //input
    uint8 chip_id;
    uint8 hash_type;
    uint8 hash_module;
    uint8 rsv0;

    uint8 aging_timer;
    uint8 hw_aging;

    uint32* key;

    //output
    uint8 is_cam;
    uint8 is_valid;
    uint8 is_conflict;
    uint8 is_blackhole;
};
typedef struct hash_io_by_key_para_s hash_io_by_key_para_t;

struct hash_io_by_idx_para_s
{
    uint8  chip_id;
    uint32 table_id;
    uint32 table_index;
    uint32* key;
};
typedef struct hash_io_by_idx_para_s hash_io_by_idx_para_t;

struct ds_3word_hash_key_s
{
    uint32 field[DRV_WORDS_PER_ENTRY];
};
typedef struct ds_3word_hash_key_s ds_3word_hash_key_t;

struct ds_6word_hash_key_s
{
    uint32 field[DRV_WORDS_PER_ENTRY * 2];
};
typedef struct ds_6word_hash_key_s ds_6word_hash_key_t;

struct ds_12word_hash_key_s
{
    uint32 field[DRV_WORDS_PER_ENTRY * 4];
};
typedef struct ds_12word_hash_key_s ds_12word_hash_key_t;


extern int32
drv_model_hash_lookup(hash_lookup_info_t* p_lookup_info, hash_lookup_result_t* p_lookup_result);

extern uint32
drv_hash_lookup_check_hash_type(hash_module_t, uint32);

/*
extern int32
drv_hash_lookup_get_key_info_index(hash_module_t , uint32 ,uint8 *);
*/

extern int32
drv_model_hash_key_add_by_key(hash_io_by_key_para_t* p_para);
extern int32
drv_model_hash_key_delete_by_key(hash_io_by_key_para_t* p_para);

extern int32
drv_model_hash_key_add_by_index(hash_io_by_idx_para_t* p_para);

extern int32
drv_model_hash_key_delete_by_index(hash_io_by_idx_para_t* p_para);

int32
drv_hash_lookup_get_key_info_index(hash_module_t hash_module, uint32 hash_type,uint8 * p_index);

extern int32
drv_model_hash_combined_key( uint8* dest_key, uint8* src_key, uint32 len, uint32 tbl_id);

extern int32
drv_model_hash_un_combined_key( uint8* dest_key, uint8* src_key, uint32 len, uint32 tbl_id);

extern void
_array_un_shift_left(uint8* dst, uint8* src, uint32 shift, uint32 len);

extern int32
drv_model_hash_mask_key( uint8* dest_key, uint8* src_key, hash_module_t hash_module, uint32 key_type);


#endif

