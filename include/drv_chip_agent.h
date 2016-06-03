#ifndef _DRV_CHIP_AGENT_H_
#define _DRV_CHIP_AGENT_H_

#include "sal.h"
#include "drv_io.h"

#define GG_HEADER_LEN       40
#define GG_CPUMAC_HDR_LEN   32 /* MacDa + MacSa + VlanTag(4B) + EtherType(2B) + Rsv(2B) ??? */

#define MAX_ACC_BUF_IN  34   /* buf in  max table size is 32*/
#define MAX_ACC_BUF_OUT 34   /* buf out for ipfix max data size use 34*/
#define MAX_DMA_NUM 16*32    /* DMA_IPFIX_ACC_FIFO_BYTES(64=16words)*DMA_NUM */
#define MAX_DMA_EXT_NUM 2*32 /* sys_dma_desc_ts_t(8=2 words)*DMA_NUM */

#define DRV_CHIP_AGT_LOG            sal_printf

#define DRV_EADP_DBG_INFO(enable,FMT, ...)\
        if(enable)\
        {\
            DRV_DBG_INFO(FMT, ##__VA_ARGS__);\
        }\

typedef enum
{
    DRV_CHIP_AGT_E_NONE = 0,                /**< NO error */

    DRV_CHIP_AGT_E_GEN = -20000,
    DRV_CHIP_AGT_E_TASK,
    DRV_CHIP_AGT_E_MUTEX_CREAT,
    DRV_CHIP_AGT_E_MODE_SERVER,
    DRV_CHIP_AGT_E_MODE_CLIENT,
    DRV_CHIP_AGT_E_SOCK_SYNC_TO,
    DRV_CHIP_AGT_E_SOCK_ERROR,
    DRV_CHIP_AGT_E_SOCK_CREAT,
    DRV_CHIP_AGT_E_SOCK_EXIST,
    DRV_CHIP_AGT_E_SOCK_NONEXIST,
    DRV_CHIP_AGT_E_SOCK_SET_OPT,
    DRV_CHIP_AGT_E_SOCK_ADDR,
    DRV_CHIP_AGT_E_SOCK_CONNECT,
    DRV_CHIP_AGT_E_SOCK_NOT_CONNECT,
    DRV_CHIP_AGT_E_SOCK_BIND,
    DRV_CHIP_AGT_E_SOCK_LISTEN,
    DRV_CHIP_AGT_E_MSG_LEN,
    DRV_CHIP_AGT_E_MSG_LEN_EXCEED,
    DRV_CHIP_AGT_E_MSG_IO_TYPE,
    DRV_CHIP_AGT_E_IO_UNSUP,
    DRV_CHIP_AGT_E_VER_MISMATCH,
    DRV_CHIP_AGT_E_DATE_MISMATCH,
    DRV_CHIP_AGT_E_PROFILE_MISMATCH,
    DRV_CHIP_AGT_E_ENGINE_MISMATCH,
    DRV_CHIP_AGT_E_DECODE_NULL_PTR,
    DRV_CHIP_AGT_E_DECODE_ZERO_LEN,
    DRV_CHIP_AGT_E_SIM_DGB_ACT_SAME,
    DRV_CHIP_AGT_E_SIM_DGB_ACT_LOCAL_PRINTF,
    DRV_CHIP_AGT_E_SIM_DGB_ACT_REMOTE_PRINTF,
    DRV_CHIP_AGT_E_SIM_DGB_ACT_REMOTE_FILE,
    DRV_CHIP_AGT_E_MAX
}drv_chip_agt_err_t;

enum chip_agent_dma_op_type_e
{
    CHIP_AGENT_DMA_INFO_TYPE_LEARN,
    CHIP_AGENT_DMA_INFO_TYPE_HASHDUMP,
    CHIP_AGENT_DMA_INFO_TYPE_IPFIX,
    CHIP_AGENT_DMA_INFO_TYPE_SDC,
    CHIP_AGENT_DMA_INFO_TYPE_MONITOR,
    CHIP_AGENT_DMA_INFO_TYPE_AGING,
    CHIP_AGENT_DMA_INFO_TYPE_MAX
};
typedef  enum chip_agent_dma_op_type_e chip_agent_dma_op_type_t;

#define CHIP_AGT_BUF_SIZE       5120
#define CHIP_AGT_DBG_SOCK(FMT, ...) \
    CTC_DEBUG_OUT(chipagent, chipagent, CHIP_AGT_SOCKET, CTC_DEBUG_LEVEL_INFO, FMT, ##__VA_ARGS__)

#define CHIP_AGT_DBG_CODE(FMT, ...) \
    CTC_DEBUG_OUT(chipagent, chipagent, CHIP_AGT_CODE, CTC_DEBUG_LEVEL_INFO, FMT, ##__VA_ARGS__)

#define CHIP_AGT_LOCK(mutex_type) \
    if (mutex_type) sal_mutex_lock(mutex_type)

#define CHIP_AGT_UNLOCK(mutex_type) \
    if (mutex_type) sal_mutex_unlock(mutex_type)



/* parameter for CHIP_AGT_MSG_MODEL */
typedef struct
{
    uint32 type;
    uint32 param_count;
    uint32 param[5];
    int32 ret;
} chip_agent_msg_model_para_t;

/* parameter for CHIP_AGT_MSG_INIT */
typedef struct chip_agent_msg_init_para_s
{
    uint8 profile_type;
    uint8 endian;
    uint8 ver_len;
    uint8 date_len;
    uint32 is_asic;
    uint32 sim_debug_action;
    uint32 sim_packet_debug;
    int32 ret;
    char* ver;
    char* date;
} chip_agent_msg_init_para_t;

/* parameter for CHIP_AGT_MSG_CTRL */
typedef struct
{
    uint32 action;
    uint32 type;
    uint32 flag;
    uint32 enable;
    int32 ret;
} chip_agent_msg_ctrl_para_t;

/* parameter for CHIP_AGT_MSG_IO common header */
typedef struct
{
    uint8 op;
    uint8 chip_id;
    uint16 len;
} chip_agent_msg_io_hdr_t;

/* parameter for CHIP_AGT_MSG_IO ioctl */
typedef struct
{
    chip_agent_msg_io_hdr_t hdr;
    uint32 index;
    uint32 cmd;
    uint32 fld_val;     /* for field IO */
    int32 ret;
    uint32 val_len;
    uint32 mask_len;
    void* val;
    void* mask;
} chip_agent_msg_io_para_t;


/* parameter for CHIP_AGT_MSG_IO ioctl */
typedef struct
{
    chip_agent_msg_io_hdr_t hdr;
    uint32 index;
    uint32 cmd;
    //drv_fib_acc_in_t drv_fib;
} chip_agent_msg_io_acc_para_t;

/* parameter for CHIP_AGT_MSG_IO tcam remove */
typedef struct
{
    chip_agent_msg_io_hdr_t hdr;
    uint32 index;
    uint32 table_id;
    int32 ret;
} chip_agent_msg_tcam_remove_para_t;

/* parameter for CHIP_AGT_MSG_IO hash ioctl */
typedef struct
{
    chip_agent_msg_io_hdr_t hdr;
    uint32 hash_op;
    uint32 index;
    uint32 table_id;
    uint32 hash_module;
    uint32 hash_type;
    int32 ret;
    uint32 val_len;
    void* val;
} chip_agent_msg_hash_ioctl_para_t;

/* parameter for CHIP_AGT_MSG_IO hash lookup */
typedef struct
{
    chip_agent_msg_io_hdr_t hdr;
    uint32 key_index;
    uint32 ad_index;
    uint8 hash_module;
    uint8 hash_type;
    uint8 valid;
    uint8 free;
    uint8 conflict;
    uint8 rev[3];
    int32 ret;
    uint32 val_len;
    void* val;
} chip_agent_msg_hash_lookup_para_t;

/* parameter for CHIP_AGT_MSG_IO fib acc */
typedef struct
{
    chip_agent_msg_io_hdr_t hdr;
    uint32 acc_op_type;
    uint32 ret;
    uint32 acc_buf_in[MAX_ACC_BUF_IN];   /*buf in  max table size is 32*/
    uint32 acc_buf_out[MAX_ACC_BUF_OUT]; /*buf out*/
} chip_agent_msg_fib_acc_t;

/* parameter for CHIP_AGT_MSG_IO dma dump */
typedef struct
{
    chip_agent_msg_io_hdr_t hdr;
    uint32 ret;
    uint16 threshold;
    uint16 entry_num;
    uint32 acc_buf_out[MAX_DMA_NUM]; /*buf out*/
} chip_agent_msg_dma_dump_t;

/* parameter for CHIP_AGT_MSG_PACKET */
typedef struct
{
    uint32 pkt_len;
    uint32 pkt_mode;
    uint8* pkt;
} chip_agent_msg_pkt_para_t;

/* parameter for CHIP_AGT_MSG_PACKET_RX_INFO */
typedef struct
{
    uint32 pkt_len;
    uint32 pkt_mode;
    uint32 dma_chan;    /**< [GB] DMA Channel ID of packet RX */
    uint32 buf_count;   /**< [GB] Count of packet buffer array */
    uint32 pkt_buf_len;
    uint8* pkt;
} chip_agent_msg_pkt_rx_para_t;

/* parameter for CHIP_AGT_MSG_INTERRUPT */
typedef struct
{
    uint32 group;
} chip_agent_msg_interrupt_para_t;

/* parameter for CHIP_AGT_MSG_INTERRUPT */
typedef struct
{
    uint32 lchip;
    uint32 buf[MAX_DMA_NUM];   /*buf in  max table size is 32*/
} chip_agent_msg_interrupt_oam_t;

/* parameter for CHIP_AGT_MSG_DMA common header */
typedef struct
{
    uint8 op;
    uint8 chip_id;
    uint16 num;
    uint32 data_buf[MAX_DMA_NUM];
    uint32 data_ext[MAX_DMA_EXT_NUM];
} chip_agent_msg_dma_para_t;

/* parameter for CHIP_AGT_MSG_LOG */
typedef struct
{
    uint32 len;
    uint8* data;
} chip_agent_msg_log_para_t;

struct drv_learn_aging_info_s
{
    uint32 key_index;

    mac_addr_t   mac;
    uint16 vsi_id;

    uint16 damac_index;
    uint8 is_mac_hash;
    uint8 valid;
    uint8 is_aging;
};
typedef struct drv_learn_aging_info_s  drv_learn_aging_info_t;



#define ENCODE_PUTC(V)                      \
    do {                                    \
        *(*pnt) = (V) & 0xFF;               \
        (*pnt)++;                           \
        (*size)--;                          \
    } while (0)

#define ENCODE_PUTW(V)                      \
    do {                                    \
        *(*pnt) = ((V) >> 8) & 0xFF;        \
        *(*pnt + 1) = (V) & 0xFF;           \
        *pnt += 2;                          \
        *size -= 2;                         \
    } while (0)

#define ENCODE_PUTL(V)                      \
    do {                                    \
        *(*pnt) = ((V) >> 24) & 0xFF;       \
        *(*pnt + 1) = ((V) >> 16) & 0xFF;   \
        *(*pnt + 2) = ((V) >> 8) & 0xFF;    \
        *(*pnt + 3) = (V) & 0xFF;           \
        *pnt += 4;                          \
        *size -= 4;                         \
    } while (0)

#define ENCODE_PUT_EMPTY(L)                 \
    do {                                    \
        sal_memset((void*)(*pnt), 0, (L));  \
        *pnt += (L);                        \
        *size -= (L);                       \
    } while (0)

#define ENCODE_PUT(P, L)                                    \
    do {                                                    \
        sal_memcpy((void*)(*pnt), (void*)(P), (L));         \
        *pnt += (L);                                        \
        *size -= (L);                                       \
    } while (0)

#define DECODE_GETC(V)                                      \
    do {                                                    \
        (V) = **pnt;                                        \
        (*pnt)++;                                           \
        (*size)--;                                          \
    } while (0)

#define DECODE_GETW(V)                                      \
    do {                                                    \
        (V) = ((*(*pnt)) << 8)                              \
            + (*(*pnt + 1));                              \
        *pnt += 2;                                          \
        *size -= 2;                                         \
    } while (0)

#define DECODE_GETL(V)                                      \
    do {                                                    \
        (V) = ((uint32_t)(*(*pnt)) << 24)                   \
            + ((uint32_t)(*(*pnt + 1)) << 16)             \
            + ((uint32_t)(*(*pnt + 2)) << 8)              \
            + (uint32_t)(*(*pnt + 3));                    \
        *pnt += 4;                                          \
        *size -= 4;                                         \
    } while (0)

#define DECODE_GET(V, L)                                    \
    do {                                                    \
        sal_memcpy((void*)(V), (const void*)(*pnt), (L));   \
        *pnt += (L);                                        \
        *size -= (L);                                       \
    } while (0)

#define DECODE_GET_EMPTY(L)                                 \
    do {                                                    \
        *pnt += (L);                                        \
        *size -= (L);                                       \
    } while (0)

#define CHIP_AGT_DECODE_BUF(P, L)                           \
    do {                                                    \
        if (L)                                              \
        {                                                   \
            if ((P))                                        \
            {                                               \
                DECODE_GET((P), (L));                       \
            }                                               \
            else                                            \
            {                                               \
                return DRV_CHIP_AGT_E_DECODE_NULL_PTR;          \
            }                                               \
        }                                                   \
    } while (0)

typedef void (* DRV_EADP_INTR_DISPATCH_CB)(void* p_data);
typedef int32 (* DRV_EADP_PKT_RX_CB)(uint8* pkt, uint32 mode, uint32 pkt_len);

typedef struct
{
    DRV_EADP_INTR_DISPATCH_CB   eadp_intr_dispatch_cb;
    DRV_EADP_PKT_RX_CB          eadp_pkt_rx_cb;
} drv_chip_agent_t;




/**
 @brief define drv chip agent mode
*/
enum drv_chip_agent_mode_e
{
    DRV_CHIP_AGT_MODE_NONE = 0,
    DRV_CHIP_AGT_MODE_CLIENT,
    DRV_CHIP_AGT_MODE_SERVER,
    DRV_CHIP_AGT_MODE_MAX
};
typedef enum drv_chip_agent_mode_e drv_chip_agent_mode_t;



int32 drv_chip_agent_mode(void);
int32 _chip_agent_encode_init(uint8* buf, chip_agent_msg_init_para_t* para, uint32* req_len);
int32 _chip_agent_decode_init(uint8* buf, chip_agent_msg_init_para_t* para, uint32 len);
int32 _chip_agent_encode_model(uint8* buf, chip_agent_msg_model_para_t* para, uint32* req_len);
int32 _chip_agent_decode_model(uint8* buf, chip_agent_msg_model_para_t* para, uint32 len);
int32 _chip_agent_encode_ctrl(uint8* buf, chip_agent_msg_ctrl_para_t* para, uint32* req_len);
int32 _chip_agent_decode_ctrl(uint8* buf, chip_agent_msg_ctrl_para_t* para, uint32 len);
int32 _chip_agent_encode_pkt(uint8* buf, chip_agent_msg_pkt_para_t* para, uint32* req_len);
int32 _chip_agent_decode_pkt(uint8* buf, chip_agent_msg_pkt_para_t* para, uint32 len);
int32 _chip_agent_encode_log(uint8* buf, chip_agent_msg_log_para_t* para, uint32* req_len);
int32 _chip_agent_decode_log(uint8* buf, chip_agent_msg_log_para_t* para, uint32 len);
int32 _chip_agent_encode_interrupt(uint8* buf, chip_agent_msg_interrupt_para_t* para, uint32* req_len);
int32 _chip_agent_decode_interrupt(uint8* buf, chip_agent_msg_interrupt_para_t* para, uint32 len);
int32 _chip_agent_encode_io_ioctl(uint8* buf, chip_agent_msg_io_para_t* para, uint32* req_len);
int32 _chip_agent_decode_io_header(uint8* buf, chip_agent_msg_io_hdr_t* hdr, uint32 len);
int32 _chip_agent_decode_io_ioctl(uint8* buf, chip_agent_msg_io_para_t* para, uint32 len);
int32 _chip_agent_encode_io_hash_ioctl(uint8* buf, chip_agent_msg_hash_ioctl_para_t* para, uint32* req_len);
int32 _chip_agent_decode_io_hash_ioctl(uint8* buf, chip_agent_msg_hash_ioctl_para_t* para, uint32 len);
int32 _chip_agent_encode_io_hash_lookup(uint8* buf, chip_agent_msg_hash_lookup_para_t* para, uint32* req_len);
int32 _chip_agent_decode_io_hash_lookup(uint8* buf, chip_agent_msg_hash_lookup_para_t* para, uint32 len);
int32 _chip_agent_encode_io_tcam_remove(uint8* buf, chip_agent_msg_tcam_remove_para_t* para, uint32* req_len);
int32 _chip_agent_decode_io_tcam_remove(uint8* buf, chip_agent_msg_tcam_remove_para_t* para, uint32 len);
int32 _chip_agent_encode_dma(uint8* buf, chip_agent_msg_dma_para_t* para, uint32* req_len);
int32 _chip_agent_decode_dma(uint8* buf, chip_agent_msg_dma_para_t* para, uint32 len);
int32 _chip_agent_decode_gg_header(uint8* buffer, int32 len, ms_packet_header_t* p_header);
int32 _chip_agent_encode_io_fib_acc_ioctl(uint8* buf, chip_agent_msg_fib_acc_t* para, uint32* req_len);
int32 _chip_agent_decode_io_fib_acc_ioctl(uint8* buf, chip_agent_msg_fib_acc_t* para, uint32 len);
int32 _chip_agent_encode_io_dma_dump_ioctl(uint8* buf, chip_agent_msg_dma_dump_t* para, uint32* req_len);
int32 _chip_agent_decode_io_dma_dump_ioctl(uint8* buf, chip_agent_msg_dma_dump_t* para, uint32 len);
int32 chip_agent_intr_cb(uint32 irq);
int32 drv_register_intr_dispatch_cb(DRV_EADP_INTR_DISPATCH_CB cb);
int32 drv_register_pkt_rx_cb(DRV_EADP_PKT_RX_CB cb);

int32 _chip_agent_fib_acc_type_copy_data(uint8 fib_acc_type, chip_agent_msg_fib_acc_t* para, drv_fib_acc_in_t* in, drv_fib_acc_out_t* out);
int32 _chip_agent_cpu_acc_type_copy_data(uint8 cpu_acc_type, chip_agent_msg_fib_acc_t* para, drv_cpu_acc_in_t* in, drv_cpu_acc_out_t* out);
int32 _chip_agent_ipfix_acc_type_copy_data(chip_agent_msg_fib_acc_t* para, drv_ipfix_acc_in_t* in, drv_ipfix_acc_out_t* out);
char* _chip_agent_io_op_str(chip_io_op_t op);
char* _chip_agent_cmd_action_str(uint32 action);
char* _chip_agent_hash_op_str(hash_op_type_t op);
char* _chip_agent_cmd_fib_acc_type_str(uint32 action);
char* _chip_agent_cmd_cpu_acc_type_str(uint32 action);
char* _chip_agent_cmd_ipfix_acc_type_str(uint32 action);

//int32 chip_agent_client_recv(chip_agent_sock_session_t* p_session, chip_agent_msg_hdr_t* p_hdr);

#endif
