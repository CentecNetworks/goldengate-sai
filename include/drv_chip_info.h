/**
 @file drv_chip_info.h

 @date 2010-02-25

 @version v5.1

 The file contains all tables and regs' struct declaration
*/

#ifndef _DRV_CHIP_INFO_H_
#define _DRV_CHIP_INFO_H_

#if (HOST_IS_LE == 1)
#include "oam_drv_struct_le.h"
#endif

#if (HOST_IS_LE == 0)
#include "oam_drv_struct_be.h"
#endif

#include "sal.h"
#include "drv_lib.h"
#include "drv_model_hash.h"
/**********************************************************************************
                      Define API function interfaces
***********************************************************************************/
struct ip_hash_rst_info_s
{
    bool      left_is_conflict;
    bool      left_is_valid;
    uint32   left_index;

    bool      right_is_conflict;
    bool      right_is_valid;
    uint32   right_index;
};
typedef struct ip_hash_rst_info_s ip_hash_rst_info_t;

/* Define cpu req hash key type */
enum cpu_req_hash_key_type_e
{
    CPU_HASH_KEY_TYPE_IPV4_UCAST,
    CPU_HASH_KEY_TYPE_IPV4_MCAST,
    CPU_HASH_KEY_TYPE_IPV6_UCAST,
    CPU_HASH_KEY_TYPE_IPV6_MCAST,
    CPU_HASH_KEY_TYPE_IPV4_RPF,
    CPU_HASH_KEY_TYPE_IPV6_RPF,
    CPU_HASH_KEY_TYPE_IPV6_HOST,
    CPU_HASH_KEY_TYPE_MAC_DA,
    CPU_HASH_KEY_TYPE_MAC_SA,
    CPU_HASH_KEY_TYPE_FCOE,
    CPU_HASH_KEY_TYPE_FCOE_RPF,
    CPU_HASH_KEY_TYPE_TRILL_UCAST,
    CPU_HASH_KEY_TYPE_TRILL_MCAST,
    CPU_HASH_KEY_TYPE_MCAST_VLAN,
    CPU_HASH_KEY_TYPE_IPV4_16,
    CPU_HASH_KEY_TYPE_MCAST_SG,
    CPU_HASH_KEY_TYPE_IPV6_64,
    CPU_HASH_KEY_TYPE_IPV6_MCAST_SG,
    CPU_HASH_KEY_TYPE_IPV4_8,
    CPU_HASH_KEY_TYPE_MCAST_XG,
    CPU_HASH_KEY_TYPE_IPV6_32,
    CPU_HASH_KEY_TYPE_IPV6_XG,
    CPU_HASH_KEY_TYPE_MAX,
};
typedef enum cpu_req_hash_key_type_e cpu_req_hash_key_type_t;

/**
 @brief define the byte order
*/
enum host_type_e
{
    HOST_LE = 0,     /**< little edian */
    HOST_BE = 1,     /**< big edian */
};
typedef enum host_type_e host_type_t;

/**
*/
enum drv_work_env_type_e
{
    NO_CMODEL = 0,
    WITH_CMODEL = 1,
    MAX_ENV_OP_TYPE = 2,
};
typedef enum drv_work_env_type_e drv_work_env_type_t;

enum drv_work_platform_type_e
{
    HW_PLATFORM = 0,
    SW_SIM_PLATFORM = 1,
    MAX_WORK_PLATFORM = 2,
};
typedef enum drv_work_platform_type_e drv_work_platform_type_t;

/* driver io callback function set struct */
struct drv_io_callback_fun_s
{
    int32(*drv_sram_tbl_read)(uint8, tbls_id_t, uint32, uint32*);
    int32(*drv_sram_tbl_write)(uint8, tbls_id_t, uint32, uint32*);
    int32(*drv_sram_read_entry)(uint8, uintptr, uint32*, int32);
    int32(*drv_sram_write_entry)(uint8, uintptr, uint32*, int32);
    int32(*drv_indirect_sram_tbl_ioctl)(uint8, uint32, uint32, void*);

    int32(*drv_tcam_tbl_read)(uint8, tbls_id_t, uint32, tbl_entry_t*);
    int32(*drv_tcam_tbl_write)(uint8, tbls_id_t, uint32, tbl_entry_t*);
    int32(*drv_tcam_tbl_remove)(uint8, tbls_id_t, uint32);

    int32(*drv_hash_key_add_by_key)(hash_io_by_key_para_t*);
    int32(*drv_hash_key_add_by_index)(hash_io_by_idx_para_t*);
    int32(*drv_hash_key_del_by_key)(hash_io_by_key_para_t*);
    int32(*drv_hash_key_del_by_index)(hash_io_by_idx_para_t*);
    int32(*drv_hash_lookup)(hash_lookup_info_t*, hash_lookup_result_t*);

    int32(*drv_set_field)(tbls_id_t, fld_id_t, void*, uint32*);
    int32(*drv_get_field)(tbls_id_t, fld_id_t, void*, uint32*);

    int32(*drv_sram_ds_to_entry)(tbls_id_t, void*, uint32*);
    int32(*drv_sram_entry_to_ds)(tbls_id_t, uint32*, void*);
    int32(*drv_tcam_ds_to_entry)(tbls_id_t, void*, void*);
    int32(*drv_tcam_entry_to_ds) (tbls_id_t, void*, void*);
    int32(*drv_fib_acc_process) (uint8 , uint32* , uint32*, uint8);
    int32(*drv_cpu_acc_asic_lkup) (uint8 , uint8 , void*, void*, void*);
    int32(*drv_ipfix_acc_process) (uint8 , void* , void* ) ;
};
typedef struct drv_io_callback_fun_s drv_io_callback_fun_t;

enum drv_access_type_e
{
    DRV_PCI_ACCESS,
    DRV_I2C_ACCESS,

    DRV_MAX_ACCESS_TYPE
};
typedef enum drv_access_type_e drv_access_type_t;
/**
  @define external use Vars
*/
extern drv_io_callback_fun_t drv_io_api;

/**
  @define driver init interface
*/
extern int32
drv_init(uint8 chip_num, uint8 chip_id_base);

/**
  @define get chip number interface
*/
extern int32
drv_get_chipnum(uint8 *chipnum);

/**
  @define get chip id base
*/
extern int32
drv_get_chipid_base(uint8 *chipid_base);

/**
  @driver get chip id from chip offset
*/
extern int32
drv_get_chipid_from_offset(uint8 chip_id_offset, uint8 *chip_id);

/**
  @driver get memory register infomation interface
*/
extern int32
drv_get_memory_info(uint32 mem_id, tables_info_t *prt_mem_info);

/**
  @driver g get driver work  platform  type
*/
extern int32
drv_get_platform_type(drv_work_platform_type_t *platform_type);


/**
  @driver get driver work  environmnet type
*/
extern int32
drv_get_workenv_type(drv_work_env_type_t *workenv_type);

#endif /*end of _DRV_CHIP_INFO_H_*/

