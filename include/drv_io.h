/**
  @file drv_io.h

  @date 2010-02-26

  @version v5.1

  The file implement driver IOCTL defines and macros
*/

#ifndef _DRV_IO_H_
#define _DRV_IO_H_

/*#include "drv_tbl_reg.h"*/
#include "drv_enum.h"
#include "drv_common.h"
#include "drv_chip_info.h"



/**********************************************************************************
              Define Typedef, define and Data Structure
***********************************************************************************/
#define DRV_IOCTL           drv_ioctl_api
#define DRV_TCAM_TBL_REMOVE drv_tcam_tbl_remove
#define DRV_HASH_KEY_IOCTL  drv_hash_key_ioctl
#define DRV_HASH_LOOKUP     drv_hash_lookup
#define DRV_SET_FIELD_ADDR  drv_set_field
#define DRV_GET_FIELD       drv_get_field


#define DRV_SET_FIELD_V(tbl_id, field_id, entry, value) \
    {                                                       \
        uint32 vl = value;                                  \
        drv_set_field(tbl_id, field_id, entry, &vl);        \
    }
#define DRV_SET_FIELD_A(t,f,d,v)    drv_set_field(t,f,d,(uint32*)v)
#define DRV_GET_FIELD_V             drv_get_field_value
#define DRV_GET_FIELD_A(t,f,d,v)    drv_get_field(t,f,d,(uint32*)v)

#define DRV_SET_FLD(X, T, f, ...)         DRV_SET_FIELD_ ## X(T ##_t, T ## _ ## f,  ##__VA_ARGS__)
#define DRV_GET_FLD(X, T, f, ...)        DRV_GET_FIELD_ ## X(T ##_t, T ## _ ## f,  ##__VA_ARGS__)



#define DRV_IO_DATA_SIZE                16
#define DRV_IO_DEBUG_CACHE_SIZE         256

typedef enum chip_io_op_s
{
    CHIP_IO_OP_IOCTL,          /*[GB,GG]*/
    CHIP_IO_OP_TCAM_REMOVE,    /*[GB,GG]*/
    CHIP_IO_OP_HASH_KEY_IOCTL, /*[GB]*/
    CHIP_IO_OP_HASH_LOOKUP,    /*[GB]*/
    CHIP_IO_OP_FIB_ACC,        /*[GG]*/
    CHIP_IO_OP_CPU_ACC,        /*[GG]*/
    CHIP_IO_OP_IPFIX_ACC,      /*[GG]*/
    CHIP_IO_OP_DMA_DUMP,       /*[GG]*/
    CHIP_IO_OP_MAX,
} chip_io_op_t;

typedef struct chip_io_para_s
{
    chip_io_op_t op;
    union
    {
        struct
        {
            uint8 chip_id;
            uint32 index;
            uint32 cmd;
            void* val;
        } ioctl;

        struct
        {
            uint8 chip_id;
            tbls_id_t tbl_id;
            uint32 index;
        } tcam_remove;

        struct
        {
            void* p_para;
            hash_op_type_t op_type;
        } hash_key_ioctl;

        struct
        {
            hash_lookup_info_t* info;
            hash_lookup_result_t* result;
        } hash_lookup;

        struct
        {
            uint8 chip_id;
            uint8 acc_type;
            drv_fib_acc_in_t* in;
            drv_fib_acc_out_t* out;
        } fib_acc;

        struct
        {
            uint8 chip_id;
            uint8 acc_type;
            drv_cpu_acc_in_t* in;
            drv_cpu_acc_out_t* out;
        } cpu_acc;

        struct
        {
            uint8 chip_id;
            uint8 acc_type;
            drv_ipfix_acc_in_t* in;
            drv_ipfix_acc_out_t* out;
        } ipfix_acc;

        struct
        {
            uint8 chip_id;
            uint8 rsv;
            uint16 threshold;
            void* val;
        } dma_dump;
    } u;
} chip_io_para_t;

/* Driver IO entry */
typedef struct
{
    sal_systime_t   tv;             /* timestamp */
    chip_io_para_t  io;             /* IO parameter */
    uint8 data[DRV_IO_DATA_SIZE];   /* used to store content of pointer in IO parameter */
} drv_io_debug_cache_entry_t;

/* Driver IO cache */
typedef struct
{
    uint32          count;
    uint32          index;
    drv_io_debug_cache_entry_t entry[DRV_IO_DEBUG_CACHE_SIZE];
} drv_io_debug_cache_info_t;

typedef int32 (* DRV_IO_AGENT_CALLBACK)(uint8, void*);
typedef struct
{
    DRV_IO_AGENT_CALLBACK       chip_agent_cb;  /* chip_agent callback */
    DRV_IO_AGENT_CALLBACK       debug_cb;       /* debug callback */
    uint32                      debug_stats[CHIP_IO_OP_MAX];
    uint32                      debug_action;
    drv_io_debug_cache_info_t   cache;
} drv_io_t;




/**********************************************************************************
                      Define API function interfaces
***********************************************************************************/

/**
 @brief judge the IO is real ASIC for EADP
*/
extern int32
drv_io_is_asic();

extern int32
drv_ioctl_api(uint8 chip_id, int32 index, uint32 cmd, void* val);

/**
 @brief the table I/O control API
*/
extern int32
drv_ioctl(uint8 chip_id, int32 index, uint32 cmd, void* val );

/**
 @brief add or modify tcam data
*/
extern int32
drv_tcam_tbl_add(uint8 chip_id, int32 index, uint32 cmd, void* val);
/**
 @brief remove tcam entry interface according to key id and index
*/
extern int32
drv_tcam_tbl_remove(uint8 chip_id, tbls_id_t tbl_id, uint32 index);

/**
 @brief hash driver I/O interface include write and delete operation
*/
extern int32
drv_hash_key_ioctl(void*, hash_op_type_t);


/**
 @brief hash lookup
*/
extern int32
drv_hash_lookup(hash_lookup_info_t* p_lookup_info, hash_lookup_result_t* p_lookup_result);

/**
 @brief get acl lookup bitmap
*/
extern int32
drv_get_acl_lookup_bitmap(uint8 chip_id, uint8 lookup_index, uint32* lookup_bitmap);

/**
 @brief set acl lookup bitmap
*/
extern int32
drv_set_acl_lookup_bitmap(uint8 chip_id, uint8 lookup_index, uint32 lookup_bitmap);

/**
 @brief get tcam lookup bitmap
*/
extern int32
drv_get_tcam_lookup_bitmap(uint32 mem_id, uint32 *bitmap);

/**
 @brief set tcam lookup bitmap
*/
extern int32
drv_set_tcam_lookup_bitmap(uint32 mem_id, uint32 bitmap);

extern int32
drv_get_hash_lookup_bitmap(uint32 hash_module, uint32 *bitmap, uint32 *extra_mode);
extern int32
drv_set_hash_lookup_bitmap(uint32 hash_module, uint32 bitmap, uint32 extra_mode);

extern int32
drv_get_dynamic_ram_couple_mode(uint32 *couple_mode);
extern int32
drv_set_dynamic_ram_couple_mode(uint32 couple_mode);


/**
 @brief init drv IO
*/
int32
drv_io_init();
#endif /*end of _DRV_IO_H*/

