
/**
  @file drv_acc.h

  @date 2010-02-26

  @version v5.1

  The file implement driver acc IOCTL defines and macros
*/

#ifndef _DRV_ACC_H_
#define _DRV_ACC_H_
#ifdef __cplusplus
extern "C" {
#endif

#define HASH_KEY_LENGTH_MODE_SINGLE      0
#define HASH_KEY_LENGTH_MODE_DOUBLE      1
#define HASH_KEY_LENGTH_MODE_QUAD        2

#define FIB_HOST0_CAM_NUM          ( 32 )
#define FIB_HOST1_CAM_NUM          ( 32 )
#define FLOW_HASH_CAM_NUM          ( 32 )
#define USER_ID_HASH_CAM_NUM       ( 32 )
#define XC_OAM_HASH_CAM_NUM        ( 128 )

/* add for fib acc start */
enum drv_fib_acc_type_e
{
    DRV_FIB_ACC_WRITE_MAC_BY_IDX      ,/* 0 */
    DRV_FIB_ACC_WRITE_MAC_BY_KEY      ,/* 1 */
    DRV_FIB_ACC_DEL_MAC_BY_IDX        ,/* 2 */
    DRV_FIB_ACC_DEL_MAC_BY_KEY        ,/* 3 */
    DRV_FIB_ACC_LKP_MAC               ,/* 4 */
    DRV_FIB_ACC_FLUSH_MAC_BY_PORT_VLAN,/* 5 */
    DRV_FIB_ACC_FLUSH_MAC_ALL         ,/* 6 */
    DRV_FIB_ACC_FLUSH_MAC_BY_MAC_PORT ,/* 7 */
    DRV_FIB_ACC_LKP_FIB0              ,/* 8 */
    DRV_FIB_ACC_WRITE_FIB0_BY_KEY     ,/* 9 */
    DRV_FIB_ACC_READ_FIB0_BY_IDX      ,/* 10 */
    DRV_FIB_ACC_WRITE_FIB0_BY_IDX     ,/* 11 */
    DRV_FIB_ACC_UPDATE_MAC_LIMIT      ,/* 12 */
    DRV_FIB_ACC_READ_MAC_LIMIT        ,/* 13 */
    DRV_FIB_ACC_WRITE_MAC_LIMIT       ,/* 14 */
    DRV_FIB_ACC_DUMP_MAC_BY_PORT_VLAN ,/* 15 */
    DRV_FIB_ACC_DUMP_MAC_ALL,          // this type share with DRV_FIB_ACC_FLUSH_MAC_ALL in hardware
    DRV_FIB_ACC_TYPE_NUM

};
typedef enum drv_fib_acc_type_e drv_fib_acc_type_t;

enum drv_fib_acc_mac_flag_e
{
    DRV_FIB_ACC_PORT_MAC_LIMIT_EN   =  (0x1),
    DRV_FIB_ACC_VLAN_MAC_LIMIT_EN   =  (0x1 << 1),
    DRV_FIB_ACC_DYNAMIC_MAC_LIMIT_EN=  (0x1 << 2),
    DRV_FIB_ACC_PROFILE_MAC_LIMIT_EN=  (0x1 << 3),
    DRV_FIB_ACC_CPU_KNOWN_ORG_PORT  =  (0x1 << 4),
    DRV_FIB_ACC_STATIC_COUNT_EN     =  (0x1 << 5),
    DRV_FIB_ACC_MAC_FLAG_NUM
};
typedef enum drv_fib_acc_mac_flag_e drv_fib_acc_mac_flag_t;

enum drv_fib_acc_flush_flag_e
{
    DRV_FIB_ACC_FLUSH_BY_PORT                 =  (0x1),
    DRV_FIB_ACC_FLUSH_BY_VSI                  =  (0x1 << 1),
    DRV_FIB_ACC_FLUSH_STATIC                  =  (0x1 << 2),
    DRV_FIB_ACC_FLUSH_DYNAMIC                 =  (0x1 << 3),
    DRV_FIB_ACC_FLUSH_MCAST                   =  (0x1 << 4),
    DRV_FIB_ACC_FLUSH_APS                     =  (0x1 << 5),
    DRV_FIB_ACC_FLUSH_LOGIC_PORT              =  (0x1 << 6),
    DRV_FIB_ACC_FLUSH_DEC_STATIC_PORT_LIMIT   =  (0x1 << 7),
    DRV_FIB_ACC_FLUSH_DEC_DYNAMIC_PORT_LIMIT  =  (0x1 << 8),
    DRV_FIB_ACC_FLUSH_DEC_STATIC_VLAN_LIMIT   =  (0x1 << 9),
    DRV_FIB_ACC_FLUSH_DEC_DYNAMIC_VLAN_LIMIT  =  (0x1 << 10),
    DRV_FIB_ACC_FLUSH_DEC_DYNAMIC_LIMIT       =  (0x1 << 11),
    DRV_FIB_ACC_FLUSH_DEC_SYSTEM_LIMIT        =  (0x1 << 12),
    DRV_FIB_ACC_FLUSH_FLAG_NUM
};
typedef enum drv_fib_acc_flush_flag_e drv_fib_acc_flush_flag_t;

enum drv_fib_acc_dump_flag_e
{
    DRV_FIB_ACC_DUMP_BY_PORT                 =  (0x1),
    DRV_FIB_ACC_DUMP_BY_VSI                  =  (0x1 << 1),
    DRV_FIB_ACC_DUMP_STATIC                  =  (0x1 << 2),
    DRV_FIB_ACC_DUMP_DYNAMIC                 =  (0x1 << 3),
    DRV_FIB_ACC_DUMP_MCAST                   =  (0x1 << 4),
    DRV_FIB_ACC_DUMP_LOGIC_PORT              =  (0x1 << 5),
    DRV_FIB_ACC_DUMP_FLAG_NUM
};
typedef enum drv_fib_acc_dump_flag_e drv_fib_acc_dump_flag_t;

enum drv_fib_acc_mac_limit_type_e
{
    DRV_FIB_ACC_UPDATE_PORT_VLAN_MAC_LIMIT,
    DRV_FIB_ACC_UPDATE_DYNAMIC_MAC_LIMIT,
    DRV_FIB_ACC_UPDATE_PROFILE_MAC_LIMIT,
    DRV_FIB_ACC_UPDATE_MAC_LIMIT_NUM
};
typedef enum drv_fib_acc_mac_limit_type_e drv_fib_acc_mac_limit_type_t;

typedef uint32 drv_fib_acc_fib_data_t[6];
typedef uint32 drv_fib_acc_rw_data_t[20];


/* add for cpu lookup acc start */
enum drv_cpu_acc_type_e
{
    DRV_CPU_LOOKUP_ACC_FIB_HOST1,
    DRV_CPU_ALLOC_ACC_FIB_HOST1,
    DRV_CPU_ADD_ACC_FIB_HOST1,
    DRV_CPU_DEL_ACC_FIB_HOST1,
    DRV_CPU_ADD_ACC_FIB_HOST1_BY_IDX,
    DRV_CPU_DEL_ACC_FIB_HOST1_BY_IDX,
    DRV_CPU_READ_ACC_FIB_HOST1_BY_IDX,

    DRV_CPU_LOOKUP_ACC_USER_ID,
    DRV_CPU_ALLOC_ACC_USER_ID,
    DRV_CPU_ADD_ACC_USER_ID,
    DRV_CPU_DEL_ACC_USER_ID,
    DRV_CPU_ADD_ACC_USER_ID_BY_IDX,
    DRV_CPU_DEL_ACC_USER_ID_BY_IDX,
    DRV_CPU_READ_ACC_USER_ID_BY_IDX,

    DRV_CPU_LOOKUP_ACC_XC_OAM,
    DRV_CPU_ALLOC_ACC_XC_OAM,
    DRV_CPU_ADD_ACC_XC_OAM,
    DRV_CPU_DEL_ACC_XC_OAM,
    DRV_CPU_ADD_ACC_XC_OAM_BY_IDX,
    DRV_CPU_DEL_ACC_XC_OAM_BY_IDX,
    DRV_CPU_READ_ACC_XC_OAM_BY_IDX,

    DRV_CPU_LOOKUP_ACC_FLOW_HASH,
    DRV_CPU_ALLOC_ACC_FLOW_HASH,
    DRV_CPU_ADD_ACC_FLOW_HASH,
    DRV_CPU_DEL_ACC_FLOW_HASH,
    DRV_CPU_ADD_ACC_FLOW_HASH_BY_IDX,
    DRV_CPU_DEL_ACC_FLOW_HASH_BY_IDX,
    DRV_CPU_READ_ACC_FLOW_HASH_BY_IDX,

    DRV_CPU_ACC_TYPE_NUM
};
typedef enum drv_cpu_acc_type_e drv_cpu_acc_type_t;



/* add for fib acc start */
enum drv_ipfix_acc_type_e
{
    DRV_IPFIX_ACC_WRITE_KEY_BY_IDX,         /* 0 */
    DRV_IPFIX_ACC_WRITE_AD_BY_IDX,          /* 1 */
    DRV_IPFIX_ACC_WRITE_BY_KEY,               /* 2, only used for write key */

    DRV_IPFIX_ACC_LKP_BY_KEY,                  /* 3, only used for key lookup */
    DRV_IPFIX_ACC_LKP_KEY_BY_IDX,           /* 4 */
    DRV_IPFIX_ACC_LKP_AD_BY_IDX,             /* 5 */

    DRV_IPFIX_ACC_DEL_KEY_BY_IDX,           /* 6 */
    DRV_IPFIX_ACC_DEL_AD_BY_IDX,            /* 7 */
    DRV_IPFIX_ACC_DEL_BY_KEY,                 /* 8, only used for key delete  */

    DRV_IPFIX_ACC_TYPE_NUM
};
typedef enum drv_ipfix_acc_type_e drv_ipfix_acc_type_t;


enum drv_ipfix_acc_req_type_e
{
    DRV_IPFIX_REQ_WRITE_BY_IDX,
    DRV_IPFIX_REQ_WRITE_BY_KEY,
    DRV_IPFIX_REQ_LKP_BY_KEY,
    DRV_IPFIX_REQ_LKP_BY_IDX
};
typedef enum drv_ipfix_acc_req_type_e drv_ipfix_acc_req_type_t;

typedef uint32 drv_ipfix_acc_fib_data_t[6];
typedef uint32 drv_ipfix_acc_rw_data_t[20];

#if (HOST_IS_LE == 1)

struct drv_fib_acc_in_mac_s
{
    hw_mac_addr_t   mac;        /* by key*/
    uint16      fid;        /* by key */
    uint16      flag;       /* mac limit and other flags drv_fib_acc_mac_flag_t */
    uint32      key_index;  /* by index */
    uint32      ad_index;   /* add */
    uint16      learning_port;/* add ,for mac limit usage */
    uint16      original_port;/* add/del ,for mac limit usage */
    uint8       aging_timer;/* add, for aging usage*/
    uint8       hw_aging_en;/* add, for aging usage*/
    uint8       rsv0[2];
};
typedef struct drv_fib_acc_in_mac_s drv_fib_acc_in_mac_t;

struct drv_fib_acc_in_mac_flush_s
{
    uint16 flag;/* flush type by port or vsi or port+vsi and static or dynamic and so on drv_fib_acc_flush_flag_t*/
    uint16 rsv0;

    uint16 fid;
    uint16 port;/* gport or logic port */

    hw_mac_addr_t  mac;/* flush with mac*/
};
typedef struct drv_fib_acc_in_mac_flush_s drv_fib_acc_in_mac_flush_t;

struct drv_fib_acc_in_fib_s
{
    uint8   key_type;
    uint8   overwrite_en;
    uint8   is_del;
    uint8   rsv0[1];
    void *  data;
};
typedef struct drv_fib_acc_in_fib_s drv_fib_acc_in_fib_t;

struct drv_fib_acc_in_rw_s
{
    uint32 tbl_id;
    uint32 key_index;
    void * data;
};
typedef struct drv_fib_acc_in_rw_s drv_fib_acc_in_rw_t;


struct drv_fib_acc_in_mac_limit_s
{
    uint8 type; /* drv_fib_acc_mac_limit_type_t */
    uint8 is_decrease; /* if set decrease mac limit else increase */
    uint8 security_status; /* discard or not */
    uint8 mac_limit_update_en;

    uint16 mac_limit_index; /* mac limit count index */
    uint8  mac_securiy_index; /* mac security index */
    uint8  mac_securiy_array_index; /* mac security index */

    uint8 mac_security_update_en;
    uint8 rsv0[3];

    uint32 update_counter; /* increase/decrease number or new count*/


}; /* update mac limit*/
typedef struct drv_fib_acc_in_mac_limit_s drv_fib_acc_in_mac_limit_t;

struct drv_fib_acc_in_dump_s
{
    uint16 flag;/* dump type by port or vsi or port+vsi and static or dynamic and so on drv_fib_acc_dump_flag_t*/
    uint16 rsv0;

    uint16 fid;
    uint16 port;/* gport or logic port */

    uint32 min_index; /* dump start key index and this key is included*/
    uint32 max_index; /* dump end key index and this key is excluded*/

    uint32 threshold_cnt;  /*[SDK_Modify] dump threshold */
};
typedef struct drv_fib_acc_in_dump_s drv_fib_acc_in_dump_t;

union drv_fib_acc_in_u
{
    drv_fib_acc_in_mac_t        mac;
    drv_fib_acc_in_mac_flush_t  mac_flush;
    drv_fib_acc_in_fib_t        fib;
    drv_fib_acc_in_rw_t         rw;
    drv_fib_acc_in_mac_limit_t  mac_limit;
    drv_fib_acc_in_dump_t       dump;
};
typedef union drv_fib_acc_in_u drv_fib_acc_in_t;

union drv_fib_acc_out_u
{
    struct
    {
        uint32  key_index;
        uint32  ad_index;

        uint8   conflict;
        uint8   hit;
        uint8   free;
        uint8   pending; // mac limit reach;
    }
    mac;

    struct
    {
        uint32  key_index;
        uint32  ad_index;
        uint8   conflict;
        uint8   hit;
        uint8   free;
        uint8   rsv0;
    }
    fib;


    struct
    {
        drv_fib_acc_rw_data_t data;
    }
    read;

    struct
    {
        uint8 security_status; /* discard or not */
        uint8 rsv0[3];

        uint32 counter;
    }
    mac_limit;

    struct
    {
        uint8 dma_full; /* dam full dump op fail */
        uint8 continuing;  /* [SDK_Modify]need query again */
        uint8 rsv0[2];

        uint32 last_index; /* fail on this key index */
        uint32 count;   /* [SDK_Modify] query result count */

    }dump;
}
;
typedef union drv_fib_acc_out_u drv_fib_acc_out_t;

struct drv_cpu_acc_in_s
{
    uint32 tbl_id;   //used for normal lkp/add/del type
    uint32 key_index;//used for add/del by index type

    void * data;     //used for normal lkp/add/del type and add by index type
};
typedef struct drv_cpu_acc_in_s drv_cpu_acc_in_t;

struct drv_cpu_acc_out_s
{
    //include cam index
    //for fib_host1/flow/userId 0~31 is cam index
    //for xc_oam 0~15 is cam index
    uint32  key_index;

    uint8   conflict;
    uint8   hit;
    uint8   free;
    uint8   rsv0;

    uint32 data[MAX_ENTRY_BYTE/4]; //used only for read by index
};
typedef struct drv_cpu_acc_out_s drv_cpu_acc_out_t;
/* add for cpu lookup acc end */


struct drv_ipfix_acc_in_s
{
    uint32 tbl_id;
    uint32 index;   /*key index or ad index*/
    uint8 type;      /*0:170 bit,1:340bit*/
    uint8 rsv[3];
    void* data;
};
typedef struct drv_ipfix_acc_in_s drv_ipfix_acc_in_t;

struct drv_ipfix_acc_out_s
{
    uint32  key_index;

    uint8   conflict;
    uint8   hit;                /* only used by lookup by key */
    uint8   free;              /* only used by lookup by key */
    uint8   invalid_idx;

    uint32 data[MAX_ENTRY_BYTE/4]; //used only for read by index
};
typedef struct drv_ipfix_acc_out_s drv_ipfix_acc_out_t;
/* add for ipfix acc end */


#else


struct drv_fib_acc_in_mac_s
{
    hw_mac_addr_t   mac;        /* by key*/
    uint16      flag;       /* mac limit and other flags drv_fib_acc_mac_flag_t */
    uint16      fid;        /* by key */
    uint32      key_index;  /* by index */
    uint32      ad_index;   /* add */
    uint16      original_port;/* add/del ,for mac limit usage */
    uint16      learning_port;/* add ,for mac limit usage */
    uint8       rsv0[2];
    uint8       hw_aging_en;/* add, for aging usage*/
    uint8       aging_timer;/* add, for aging usage*/
};
typedef struct drv_fib_acc_in_mac_s drv_fib_acc_in_mac_t;

struct drv_fib_acc_in_mac_flush_s
{
    uint16 rsv0;
    uint16 flag;/* flush type by port or vsi or port+vsi and static or dynamic and so on drv_fib_acc_flush_flag_t*/
    uint16 port;/* gport or logic port */
    uint16 fid;
    hw_mac_addr_t  mac;/* flush with mac*/
};
typedef struct drv_fib_acc_in_mac_flush_s drv_fib_acc_in_mac_flush_t;

struct drv_fib_acc_in_fib_s
{
    uint8   rsv0[1];
    uint8   is_del;
    uint8   overwrite_en;
    uint8   key_type;
    void *  data;
};
typedef struct drv_fib_acc_in_fib_s drv_fib_acc_in_fib_t;

struct drv_fib_acc_in_rw_s
{
    uint32 tbl_id;
    uint32 key_index;
    void * data;
};
typedef struct drv_fib_acc_in_rw_s drv_fib_acc_in_rw_t;


struct drv_fib_acc_in_mac_limit_s
{
    uint8 mac_limit_update_en;
    uint8 security_status; /* discard or not */
    uint8 is_decrease; /* if set decrease mac limit else increase */
    uint8 type; /* drv_fib_acc_mac_limit_type_t */
    uint8  mac_securiy_array_index; /* mac security index */
    uint8  mac_securiy_index; /* mac security index */
    uint16 mac_limit_index; /* mac limit count index */
    uint8 rsv0[3];
    uint8 mac_security_update_en;
    uint32 update_counter; /* increase/decrease number or new count*/

}; /* update mac limit*/
typedef struct drv_fib_acc_in_mac_limit_s drv_fib_acc_in_mac_limit_t;

struct drv_fib_acc_in_dump_s
{
    uint16 rsv0;
    uint16 flag;/* dump type by port or vsi or port+vsi and static or dynamic and so on drv_fib_acc_dump_flag_t*/
    uint16 port;/* gport or logic port */
    uint16 fid;
    uint32 min_index; /* dump start key index and this key is included*/
    uint32 max_index; /* dump end key index and this key is excluded*/
    uint32 threshold_cnt;  /*[SDK_Modify] dump threshold */
};
typedef struct drv_fib_acc_in_dump_s drv_fib_acc_in_dump_t;

union drv_fib_acc_in_u
{
    drv_fib_acc_in_mac_t        mac;
    drv_fib_acc_in_mac_flush_t  mac_flush;
    drv_fib_acc_in_fib_t        fib;
    drv_fib_acc_in_rw_t         rw;
    drv_fib_acc_in_mac_limit_t  mac_limit;
    drv_fib_acc_in_dump_t       dump;
};
typedef union drv_fib_acc_in_u drv_fib_acc_in_t;

union drv_fib_acc_out_u
{
    struct
    {
        uint32  key_index;
        uint32  ad_index;
        uint8   pending; // mac limit reach;
        uint8   free;
        uint8   hit;
        uint8   conflict;
    }
    mac;

    struct
    {
        uint32  key_index;
        uint32  ad_index;
        uint8   rsv0;
        uint8   free;
        uint8   hit;
        uint8   conflict;

    }
    fib;


    struct
    {
        drv_fib_acc_rw_data_t data;
    }
    read;

    struct
    {
        uint8 rsv0[3];
        uint8 security_status; /* discard or not */
        uint32 counter;
    }
    mac_limit;

    struct
    {
        uint8 rsv0[2];
        uint8 continuing;  /* [SDK_Modify]need query again */
        uint8 dma_full; /* dam full dump op fail */
        uint32 last_index; /* fail on this key index */
        uint32 count;   /* [SDK_Modify] query result count */

    }dump;
}
;
typedef union drv_fib_acc_out_u drv_fib_acc_out_t;



struct drv_cpu_acc_in_s
{
    uint32 tbl_id;   //used for normal lkp/add/del type
    uint32 key_index;//used for add/del by index type

    void * data;     //used for normal lkp/add/del type and add by index type
};
typedef struct drv_cpu_acc_in_s drv_cpu_acc_in_t;

struct drv_cpu_acc_out_s
{
    //include cam index
    //for fib_host1/flow/userId 0~31 is cam index
    //for xc_oam 0~15 is cam index
    uint32  key_index;

    uint8   rsv0;
    uint8   free;
    uint8   hit;
    uint8   conflict;

    uint32 data[MAX_ENTRY_BYTE/4]; //used only for read by index
};
typedef struct drv_cpu_acc_out_s drv_cpu_acc_out_t;
/* add for cpu lookup acc end */



struct drv_ipfix_acc_in_s
{
    uint32 tbl_id;
    uint32 index;   /*key index or ad index*/

    uint8 rsv[3];
    uint8 type;      /*0:170 bit,1:340bit*/

    void* data;
};
typedef struct drv_ipfix_acc_in_s drv_ipfix_acc_in_t;

struct drv_ipfix_acc_out_s
{
    uint32  key_index;

    uint8   invalid_idx;
    uint8   free;              /* only used by lookup by key */
    uint8   hit;                /* only used by lookup by key */
    uint8   conflict;

    uint32 data[MAX_ENTRY_BYTE/4]; //used only for read by index
};
typedef struct drv_ipfix_acc_out_s drv_ipfix_acc_out_t;
/* add for ipfix acc end */

#endif


extern int32
drv_fib_acc(uint8 chip_id, uint8 acc_type, drv_fib_acc_in_t* fib_acc_in, drv_fib_acc_out_t* fib_acc_out);

extern int32
drv_cpu_acc(uint8 chip_id, uint8 acc_type, drv_cpu_acc_in_t* in,drv_cpu_acc_out_t* out );

extern int32
drv_ipfix_acc(uint8 chip_id, uint8 acc_type, drv_ipfix_acc_in_t* acc_in, drv_ipfix_acc_out_t* acc_out);

#ifdef __cplusplus
}
#endif
#endif /*end of _DRV_ACC_H*/
