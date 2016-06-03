/**
 @file chip_agent.h

 @date 2012-08-16

 @version v2.0

provide the common defination and functions for chip agent
*/
#ifndef _CHIP_AGENT_H_
#define _CHIP_AGENT_H_

#define CHIP_AGT_LOG            sal_printf
#define CHIP_AGT_ERR            sal_printf

#define CHIP_AGT_STR            "Chip Agent "
#define CHIP_AGT_SOCK_STR       "Chip Agent Socket "

#define CHIP_AGT_CACHE_SIZE     64
#define CHIP_AGT_IO_BUF_SIZE    512
#define CHIP_AGT_BUF_SIZE       5120
#define CHIP_AGT_SOCKET_RCV_BUFF 32768
#define CHIP_AGT_SYNC_10MS_MAX  100
#define CHIP_AGT_SYNC_SEC_MAX   5
#define CHIP_AGT_SYNC_CNT       (CHIP_AGT_SYNC_10MS_MAX * CHIP_AGT_SYNC_SEC_MAX)

/* GoldenGate chip's info */
#define GG_BRIDGE_HEADER_LEN     40
//#define GG_CPUMAC_HDR_LEN 18 /* MacDa + MacSa + VlanTag(4B) + EtherType(2B) */

#define CHIP_AGT_MAX_SERVER     30

#define SWAP32(x) \
    ((uint32)( \
         (((uint32)(x) & (uint32)0x000000ffUL) << 24) | \
         (((uint32)(x) & (uint32)0x0000ff00UL) << 8) | \
         (((uint32)(x) & (uint32)0x00ff0000UL) >> 8) | \
         (((uint32)(x) & (uint32)0xff000000UL) >> 24)))

typedef enum
{
    CHIP_AGT_E_NONE = 0,                /**< NO error */

    CHIP_AGT_E_GEN = -20000,
    CHIP_AGT_E_TASK,
    CHIP_AGT_E_MUTEX_CREAT,
    CHIP_AGT_E_MODE_SERVER,
    CHIP_AGT_E_MODE_CLIENT,
    CHIP_AGT_E_SOCK_SYNC_TO,
    CHIP_AGT_E_SOCK_ERROR,
    CHIP_AGT_E_SOCK_CREAT,
    CHIP_AGT_E_SOCK_EXIST,
    CHIP_AGT_E_SOCK_NONEXIST,
    CHIP_AGT_E_SOCK_SET_OPT,
    CHIP_AGT_E_SOCK_ADDR,
    CHIP_AGT_E_SOCK_CONNECT,
    CHIP_AGT_E_SOCK_NOT_CONNECT,
    CHIP_AGT_E_SOCK_BIND,
    CHIP_AGT_E_SOCK_LISTEN,
    CHIP_AGT_E_MSG_LEN,
    CHIP_AGT_E_MSG_LEN_EXCEED,
    CHIP_AGT_E_MSG_IO_TYPE,
    CHIP_AGT_E_IO_UNSUP,
    CHIP_AGT_E_VER_MISMATCH,
    CHIP_AGT_E_DATE_MISMATCH,
    CHIP_AGT_E_PROFILE_MISMATCH,
    CHIP_AGT_E_ENGINE_MISMATCH,
    CHIP_AGT_E_DECODE_NULL_PTR,
    CHIP_AGT_E_DECODE_ZERO_LEN,
    CHIP_AGT_E_SIM_DGB_ACT_SAME,
    CHIP_AGT_E_SIM_DGB_ACT_LOCAL_PRINTF,
    CHIP_AGT_E_SIM_DGB_ACT_REMOTE_PRINTF,
    CHIP_AGT_E_SIM_DGB_ACT_REMOTE_FILE,
    CHIP_AGT_E_MAX
} chip_agt_err_t;

typedef enum
{
    CHIP_AGT_MODE_NONE = 0,
    CHIP_AGT_MODE_CLIENT,
    CHIP_AGT_MODE_SERVER,
    CHIP_AGT_MODE_MAX
} chip_agent_mode_t;

typedef enum
{
    CHIP_AGT_MODEL_TYPE_OAM = 0,
    CHIP_AGT_MODEL_TYPE_MAX
} chip_agt_model_type_t;

typedef enum
{
    CHIP_AGT_CTRL_ACT_SET = 0,
    CHIP_AGT_CTRL_ACT_GET,
    CHIP_AGT_CTRL_ACT_MAX
} chip_agt_ctrl_action_t;

typedef enum
{
    CHIP_AGT_CTRL_DBG_NET = 0,
    CHIP_AGT_CTRL_DBG_CHIP,
    CHIP_AGT_CTRL_DBG_ACTION,
    CHIP_AGT_CTRL_TYPE_MAX
} chip_agt_ctrl_type_t;

typedef enum chip_agent_msg_type_e
{
    CHIP_AGT_MSG_INIT = 0x0,/*[GB,GG]*/
    CHIP_AGT_MSG_MODEL,     /*[GB]*/
    CHIP_AGT_MSG_CTRL,      /*[GB]*/
    CHIP_AGT_MSG_IO,        /*[GB,GG]*/
    CHIP_AGT_MSG_RESP,      /*[GB,GG]*/
    CHIP_AGT_MSG_PACKET,    /*[GB,GG]*/
    CHIP_AGT_MSG_INTERRUPT, /*[GB]*/
    CHIP_AGT_MSG_DMA,       /*[GB,GG]*/
    CHIP_AGT_MSG_LOG,       /*[GB]*/
    CHIP_AGT_MSG_RX_PACKET,    /*[GG]*/
    CHIP_AGT_MSG_OAM_ISR,    /*[GG]*/
    CHIP_AGT_MSG_DMA_PACKET,
    CHIP_AGT_MSG_MAX
} chip_agent_msg_type_t;

typedef enum
{
    CHIP_AGT_ENDIAN_OP_NONE,
    CHIP_AGT_ENDIAN_OP_LITTLE_TO_BIG,
    CHIP_AGT_ENDIAN_OP_BIG_TO_LITTLE,
} chip_agent_endian_op_t;

typedef enum
{
    CHIP_AGT_SOCK_SYNC = 0,
    CHIP_AGT_SOCK_ASYNC,
    CHIP_AGT_SOCK_MAX
} chip_agent_sock_mode_t;

typedef int32 (* CHIP_AGENT_INTR_CALLBACK)(uint32);

typedef int32 (* CHIP_AGENT_PKT_RX_CALLBACK)(void*);

typedef struct chip_agent_stats_normal_s
{
    uint32 tx;
    uint32 rx;
} chip_agent_stats_normal_t;

typedef struct chip_agent_stats_abnormal_s
{
    uint32  invalid;
    uint32  version_mismatch;
    uint32  seq_mismatch;
    uint32  syn_seq_mismatch;
} chip_agent_stats_abnormal_t;

typedef struct chip_agent_sock_stats_s
{
    chip_agent_stats_normal_t normal[CHIP_AGT_MSG_MAX];
    chip_agent_stats_abnormal_t abnormal;
} chip_agent_sock_stats_t;

typedef struct
{
    sal_systime_t   tv;
    uint32          seq;
    uint32          len;
    uint8           data[CHIP_AGT_IO_BUF_SIZE];
} chip_agent_cache_entry_t;

typedef struct
{
    uint32          count;
    uint32          index;
    chip_agent_cache_entry_t entry[CHIP_AGT_CACHE_SIZE];
} chip_agent_cache_info_t;

typedef struct
{
    chip_agent_cache_info_t tx;
    chip_agent_cache_info_t rx;
} chip_agent_cache_t;

typedef struct chip_agent_sock_session_s
{
    uint32      is_server;                  /* is server or client */
    uint32      tx_seq;                     /* TX sequence ID */
    uint32      rx_seq;                     /* RX sequence ID */
    int32       sock;                       /* read/write socket FD */
    sal_task_t* t_read;                     /* read task : only sync session */
    uint8       buf[CHIP_AGT_BUF_SIZE];     /* RX buffer */
    uint32      buf_len;                    /* buffer length */
    uint32      connected;                  /* connected state */
    sal_mutex_t*            p_tx_mutex;     /* mutex for TX */
    chip_agent_sock_mode_t  mode;           /* sync or async */
    chip_agent_sock_stats_t stats;          /* statistics */
    uint32 server_id;                       /* for client to lookup which client struct*/
} chip_agent_sock_session_t;

typedef struct chip_agent_sock_single_client_s
{
    struct sal_sockaddr_in      addr;                       /* server address */
    sal_task_t*                 t_connect;                  /* connecting task */
    chip_agent_sock_session_t   session[CHIP_AGT_SOCK_MAX]; /* connection session : sync and async */
    chip_agent_cache_t          drvio_cache;                /* cache for drv IO */
    uint32                      disconnect_count;           /* disconnect count */
    uint32                      init_disconnect_count;      /* init check fail disconnect count */
    sal_mutex_t*                p_sync_mutex;               /* mutex for sync read */
    uint32                      sync_s[CHIP_AGT_SYNC_SEC_MAX]; /* sync IO statistics in seconds */
    uint32                      sync_10ms[CHIP_AGT_SYNC_10MS_MAX]; /* sync IO statistics in 10ms */
} chip_agent_sock_single_client_t;

typedef struct chip_agent_sock_client_s
{
    chip_agent_sock_single_client_t client_single[CHIP_AGT_MAX_SERVER];
    uint32                      sync_timeout;               /* timeout for sync session */
    uint32                      sim_debug_action;           /* server's simulator debug action */
    FILE*                       sim_debug_fp;               /* simulator debug log file */
    CHIP_AGENT_INTR_CALLBACK    p_intr_cb;                  /* interrupt callback */
    CHIP_AGENT_PKT_RX_CALLBACK  p_pkt_rx_cb;                /* packet rx callback */
} chip_agent_sock_client_t;

typedef struct chip_agent_sock_server_s
{
    int32                       sock;                       /* listen FD */
    struct sal_sockaddr_in      client_addr;                /* conntected client address */
    uint32                      sim_debug_action;           /* server's simulator debug action */
    sal_task_t*                 t_accept;                   /* accept task */
    chip_agent_endian_op_t      endian_op;                  /* endian operation */
    chip_agent_sock_session_t   session[CHIP_AGT_SOCK_MAX]; /* connection session : sync and async */
    chip_agent_cache_t          drvio_cache;                /* cache for drv IO */
    uint32                      disconnect_count;           /* disconnect count */
    uint32                      sync_s[CHIP_AGT_SYNC_SEC_MAX]; /* sync IO statistics in seconds */
    uint32                      sync_10ms[CHIP_AGT_SYNC_10MS_MAX]; /* sync IO statistics in 10ms */
    uint32                      init_success;                   /*init_success when equal 1*/
    CHIP_AGENT_PKT_RX_CALLBACK  p_pkt_rx_cb;                /* packet rx callback */
} chip_agent_sock_server_t;

typedef struct
{
    uint32      print_pkt_rx;
    uint32      is_asic;
    uint32      standalone;
    uint32      mirror_port;
    uint32      tcp_port;
    uint32      dma_tcp_port;
    uint32      server_count;
    char        addr[CHIP_AGT_MAX_SERVER][20];
    char        gw[20];
} chip_agent_config_t;

typedef struct chip_agent_s
{
    chip_agent_mode_t             mode;
    chip_agent_config_t           cfg;
    chip_agent_sock_client_t      client;
    chip_agent_sock_server_t      server;
    chip_agent_sock_client_t      dma_client;
    chip_agent_sock_server_t      dma_server;
} chip_agent_t;

typedef enum chip_agent_dma_op_s
{
    CHIP_AGENT_DMA_OP_HW_LEARNING, /* [GB] */
    CHIP_AGENT_DMA_OP_HW_STATS,    /* [GB] */
    CHIP_AGENT_DMA_OP_PACKET,      /* [GB] */
} chip_agent_dma_op_t;

/* error string */
char*
chip_agent_error_str(int32 error);

/* Config APIs */
uint32
chip_agent_get_mode();

uint32
chip_agent_engine_is_asic();

int32
chip_agent_init_cfg(const char* file_name, chip_agent_t* p_agent);

int32
chip_agent_init_mode();

/* Client APIs */
int32
chip_agent_client_send_init(void* param);

int32
chip_agent_client_send_pkt(uint8 server_id, uint8* pkt, uint32 len, uint32 mode);

int32
chip_agent_client_register_intr_cb(CHIP_AGENT_INTR_CALLBACK cb);

int32
chip_agent_client_register_pkt_rx_cb(CHIP_AGENT_PKT_RX_CALLBACK cb);

int32
chip_agent_server_register_pkt_rx_cb(CHIP_AGENT_PKT_RX_CALLBACK cb);

/* Server APIs */
int32
chip_agent_server_send_pkt(uint8* pkt, uint32 len, uint32 mode);

int32
chip_agent_server_send_interrupt(uint32 group);

int32
chip_agent_server_log(char* buf, uint32 len);

int32
chip_agent_server_set_sim_dbg_action(uint32 action);

uint32
chip_agent_server_get_sim_dbg_action();

int32
chip_agent_server_set_sim_chip_model(uint32 flags, uint32 is_set);

uint32
chip_agent_server_get_sim_chip_model();

int32
ctc_chip_agent_init();

extern int32
chip_agent_client_set_ctrl_en(uint32 module, uint32 flag, uint32 enable);

int32
_chip_agent_do_send_pkt_dma_socket(uint8* pkt, uint32 len, uint32 mode);

int32
chip_agent_dma_sync_info_func(uint8 gchip, void* info);

int32
chip_agent_dma_sync_learning_func(uint8 gchip, void* info);    

int32
chip_agent_dma_sync_aging_func(uint8 gchip, void* info);    

void
chip_agent_ipfix_export(void* info, void* userdata);

void
chip_agent_monitor_export(void* info, void* userdata);

int32
agent_agent_pkt_rx(void* p_pkt_rx);

int32
agent_agent_pkt_tx(void* p_pkt_tx);

#endif /*end of _CHIP_AGENT_H_*/

