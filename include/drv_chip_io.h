/**
 @file drv_chip_io.h

 @date 2011-10-09

 @version v4.28.2

 The file contains all driver I/O interface realization
*/

#ifndef _DRV_CHIP_IO_H
#define _DRV_CHIP_IO_H

#include "sal.h"
#include "drv_enum.h"
#include "drv_common.h"

typedef int32 (* DMA_TCAM_CB_FUN_P)  (uint8 lchip, uint32 trig);

/**
 @brief Embeded Tcam lkp process
  Only use for the show forwarding tools
*/
extern int32
drv_chip_tcam_lookup(uint8 chip_id_offset, uint8* key, int32 keysize,
                    bool dual_lkp, uint32* result_index);

#if ZHOUW_NOTE
/**
 @brief Real sram indirect operation I/O
*/
int32
drv_chip_indirect_sram_tbl_ioctl(uint8 chip_id_offset, uint32 index,
                                uint32 cmd, void* val);

/**
 @brief add hash entry after lkp operation on real chip
*/
extern int32
drv_chip_hash_key_add_entry(uint8 chip_id_offset, void* add_para);


/**
 @brief delete hash entry according to detailed key value on real chip
*/
extern int32
drv_chip_hash_key_del_entry_by_key(uint8 chip_id_offset, void* del_para);


/**
 @brief delete hash entry according to hash index on real chip
*/
extern int32
drv_chip_hash_key_del_entry_by_index(uint8 chip_id_offset, void* del_para);

/**
 @brief Hash lookup I/O control API on real chip
*/
extern int32
drv_chip_hash_lookup(uint8 chip_id_offset,
                      uint32* key,
                      hash_ds_ctl_cpu_key_status_t* hash_cpu_status,
                      cpu_req_hash_key_type_e cpu_hashkey_type,
                      ip_hash_rst_info_t *ip_hash_rst_info);
#endif
/**
 @brief write register data to a sram memory location on real chip
*/
extern int32
drv_chip_sram_tbl_write(uint8 chip_id_offset, tbls_id_t tbl_id,
                            uint32 index, uint32* data);


/**
 @brief write register data to a sram memory location on real chip
*/
extern int32
drv_chip_sram_tbl_read(uint8 chip_id_offset, tbls_id_t tbl_id,
                           uint32 index, uint32* data);

/**
 @brief sram write I/O control API (write data into one address) on real chip
*/
extern int32
drv_chip_write_sram_entry(uint8 chip_id_offset, uintptr addr,
                                uint32* data, int32 len);

/**
 @brief sram read I/O control API (read data from one address) on real chip
*/
extern int32
drv_chip_read_sram_entry(uint8 chip_id_offset, uintptr addr,
                                uint32* data, int32 len);

/**
 @brief write real tcam interface
*/
extern int32
drv_chip_tcam_tbl_write(uint8 chip_id_offset, tbls_id_t tbl_id,
                                uint32 index, tbl_entry_t* entry);


/**
 @brief read real tcam interface
*/
extern int32
drv_chip_tcam_tbl_read(uint8 chip_id_offset, tbls_id_t tbl_id,
                               uint32 index, tbl_entry_t *entry);

/**
 @brief remove real tcam entry interface
*/


extern int32
drv_chip_tcam_tbl_remove(uint8 chip_id_offset, tbls_id_t tbl_id, uint32 index);

/**
 @brief tcam mutex init
*/
extern int32
drv_chip_tcam_mutex_init(uint8 chip_id_offset);

extern int32
drv_chip_fib_acc_process(uint8 chip_id, uint32* i_fib_acc_cpu_req, uint32* o_fib_acc_cpu_rlt, uint8 is_store);

extern int32
drv_chip_cpu_acc_asic_lkup(uint8 chip_id, uint8 req_type, void * cpu_req, void * cpu_req1, void *cpu_rlt);

extern int32
drv_chip_ipfix_acc_process(uint8 chip_id, void* i_ipfix_req, void* o_ipfix_result);

extern int32
drv_chip_cpu_acc_get_valid(uint8 acc_type, uint8* p_valid);

extern int32
drv_chip_flow_tcam_get_blknum_index(uint8 chip_id, tbls_id_t tbl_id, uint32 index, uint32 *blknum, uint32 *local_idx, uint32 *is_sec_half);

extern int32
drv_chip_register_tcam_write_cb(DMA_TCAM_CB_FUN_P cb);

extern int32
drv_chip_set_write_tcam_mode(uint8 type, uint8 mode);

extern int32
drv_chip_write_flow_tcam_ad_entry(uint8 chip_id, uint32 blknum, uint32 index, uint32* data);

#if 0
/**
 @brief table mutex init
*/
extern int32
drv_chip_tbl_mutex_init(uint8 chip_id_offset);

/**
 @brief register mutex init
*/
extern int32
drv_chip_reg_mutex_init(uint8 chip_id_offset);
#endif
#endif

