#ifndef __SAL_H__
#define __SAL_H__

/**
 * @file kal.h
 */

#include "sal_types.h"

#define _SAL_DEBUG
#if defined(_SAL_LINUX_KM)
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/string.h>
#include <linux/errno.h>
#include <linux/interrupt.h>
#include <linux/semaphore.h>
#include <linux/ctype.h>
#include <linux/fcntl.h>
#include <linux/sched.h>
#include <linux/random.h>
#elif defined(_SAL_LINUX_UM)
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <ctype.h>
#include <semaphore.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <linux/if_ether.h>
#include <linux/sockios.h>
#include <netpacket/packet.h>
#include <sys/un.h>
#include <time.h>
#elif defined(_SAL_VXWORKS)
#include <vxWorks.h>
#include <taskLib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/times.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <timers.h>
#include <sockLib.h>
#include <inetLib.h>
#include <time.h>
#define _SDK_NOT_READLINE_
#endif

#include "sal_error.h"
#include "sal_log.h"
#include "sal_mem.h"
#include "sal_task.h"
#include "sal_event.h"
#include "sal_mutex.h"
#include "sal_timer.h"
#include "sal_intr.h"
#include "sal_slab.h"
#include "sal_memmngr.h"
#include "sal_sock.h"
#include "sal_file.h"
extern void sal_free(void *p);
extern void *sal_malloc(size_t size);
extern void *sal_calloc(size_t size);

#define BOOLEAN_BIT(b) ((b) ? 1 : 0)

#undef sal_memcpy
#define sal_memcpy    memcpy

#undef sal_memset
#define sal_memset  memset

#undef sal_memcmp
#define sal_memcmp   memcmp

#undef sal_memmove
#define sal_memmove  memmove
/*string*/
#undef sal_vprintf
#define sal_vprintf vprintf

#undef sal_sprintf
#define sal_sprintf sprintf

#undef sal_sscanf
#define sal_sscanf sscanf

#undef sal_strcpy
#define sal_strcpy strcpy

#undef sal_strncpy
#define sal_strncpy strncpy

#undef sal_strcat
#define sal_strcat strcat

#undef sal_strncat
#define sal_strncat strncat

#undef sal_strcmp
#define sal_strcmp strcmp

#undef sal_strncmp
#define sal_strncmp strncmp

#undef sal_strlen
#define sal_strlen strlen

#undef sal_snprintf
#define sal_snprintf snprintf

#undef sal_vsnprintf
#define sal_vsnprintf vsnprintf

#undef sal_vsprintf
#define sal_vsprintf vsprintf

#undef sal_strtos32
#undef sal_strtou32
#undef sal_strtou64
#undef sal_atoi
#undef sal_strtol
#undef sal_strtol
#if defined(_SAL_LINUX_KM)
#define sal_strtou32(x, y, z) simple_strtoul((char*)x, (char**)y, z)
#define sal_strtos32(x, y, z) simple_strtol((char*)x, (char**)y, z)
#define sal_strtou64(x, y, z) simple_strtoull((char*)x, (char**)y, z)
#define sal_atoi(x) simple_strtol((char*)x, NULL, 10)
#define sal_strtol(x, y, z) simple_strtol((char*)x, (char**)y, z)

#define random sal_get_rand

#undef sal_fprintf
#define sal_fprintf sal_fprintf

int sal_get_rand();
#undef sal_rand
#define sal_rand sal_get_rand
#else
#define sal_atoi atoi
#define sal_strtos32(x, y, z) strtol((char*)x, (char**)y, z)
#define sal_strtou32(x, y, z) strtoul((char*)x, (char**)y, z)
#define sal_strtou64(x, y, z) strtoull((char*)x, (char**)y, z)
#define sal_strtol strtol

#undef sal_rand
#define sal_rand rand


/*memory */
#undef sal_malloc
#define sal_malloc   malloc

#undef sal_realloc
#define sal_realloc realloc

#undef sal_free
#define sal_free   free

#undef sal_time
#define sal_time time

#undef sal_ctime
#define sal_ctime ctime

#endif

#undef sal_strchr
#define sal_strchr strchr

#undef sal_strstr
#define sal_strstr strstr

#undef sal_strrchr
#define sal_strrchr strrchr

#undef sal_strspn
#define sal_strspn strspn

#undef sal_strerror
#define sal_strerror strerror

#undef sal_strtok
#define sal_strtok strtok

#undef sal_strtok_r
#define sal_strtok_r strtok_r

#undef sal_tolower
#undef sal_toupper
#define sal_tolower tolower
#define sal_toupper toupper

#undef sal_isspace
#undef sal_isdigit
#undef sal_isxdigit
#undef sal_isalpha
#undef sal_isalnum
#undef sal_isupper
#undef sal_islower
#define sal_isspace isspace
#define sal_isdigit isdigit
#define sal_isxdigit isxdigit
#define sal_isalpha isalpha
#define sal_isalnum isalnum
#define sal_isupper isupper
#define sal_islower islower
#define sal_isprint isprint

#undef sal_ntohl
#undef sal_htonl
#undef sal_ntohs
#undef sal_htons

#define sal_ntohl ntohl
#define sal_htonl htonl
#define sal_ntohs ntohs
#define sal_htons htons

#define sal_printf  sal_print_func

#define sal_eadp_printf(enable,FMT, ...)\
        if(enable)\
        {\
            sal_print_func(FMT, ##__VA_ARGS__);\
        }\

#ifdef _SAL_LINUX_UM

#undef sal_strcasecmp
#define sal_strcasecmp strcasecmp

#undef sal_strncasecmp
#define sal_strncasecmp strncasecmp

#undef sal_inet_pton
#define sal_inet_pton inet_pton

#undef sal_inet_ntop
#define sal_inet_ntop inet_ntop

#undef sal_qsort
#define sal_qsort qsort

#elif defined (_SAL_LINUX_KM) || defined (_SAL_VXWORKS)
extern const char* sal_inet_ntop(int32 af, void* src, char* dst, uint32 size);
extern int sal_inet_pton(int32 af, const char* src, void* dst);
extern int sal_strcasecmp(const char* s1, const char* s2);
extern int sal_strncasecmp(const char* s1, const char* s2, int32 n);
extern void sal_qsort(void *const pbase, size_t total_elems, size_t size, int (*cmp)(const void*, const void*));
#endif


#define SET_BIT(flag, bit)      (flag) = (flag) | (1 << (bit))
#define CLEAR_BIT(flag, bit)    (flag) = (flag) & (~(1 << (bit)))
#define IS_BIT_SET(flag, bit)   (((flag) & (1 << (bit))) ? 1 : 0)

#define SET_BIT_RANGE(dst, src, s_bit, len) \
    { \
        uint8 i = 0; \
        for (i = 0; i < len; i++) \
        { \
            if (IS_BIT_SET(src, i)) \
            { \
                SET_BIT(dst, (s_bit + i)); \
            } \
            else \
            { \
                CLEAR_BIT(dst, (s_bit + i)); \
            } \
        } \
    }

#ifdef _SAL_VXWORKS
#define PTR_TO_INT(x)       ((uint32)(((uint32)(x)) & 0xFFFFFFFF))
#define INT_TO_PTR(x)       ((void*)(uint32)(x))

#if 0
struct in6_addr
{
    union
    {
        uint8       u6_addr8[16];
        uint16      u6_addr16[8];
        uint32      u6_addr32[4];
    }
    in6_u;
#define s6_addr         in6_u.u6_addr8
#define s6_addr16       in6_u.u6_addr16
#define s6_addr32       in6_u.u6_addr32
};
#endif

#ifndef AF_INET6
#define AF_INET6    10  /* IP version 6 */
#endif

#endif

#ifdef _SAL_LINUX_KM
#ifndef AF_INET6
#define AF_INET6    10  /* IP version 6 */
#endif

#ifndef AF_INET
#define AF_INET    9  /* IP version 4 */
#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif

extern sal_err_t sal_init(void);
extern void sal_deinit(void);

#ifdef __cplusplus
}
#endif

#endif /* !__SAL_H__ */

