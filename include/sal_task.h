#ifndef __SAL_TASK_H__
#define __SAL_TASK_H__

/**
 * @file sal_task.h
 */

/**
 * @defgroup task Tasks
 * @{
 */

#if defined(_SAL_LINUX_KM)

#define SAL_TASK_PRIO_HIGH      1
#define SAL_TASK_PRIO_LOW       139
#define SAL_TASK_PRIO_RT_HIGH   1
#define SAL_TASK_PRIO_RT_LOW    99
#define SAL_TASK_PRIO_NICE_HIGH 100
#define SAL_TASK_PRIO_NICE_LOW  139
#define SAL_TASK_PRIO_DEF       120

#elif defined(_SAL_LINUX_UM)

#define SAL_TASK_PRIO_HIGH      1
#define SAL_TASK_PRIO_LOW       139
#define SAL_TASK_PRIO_RT_HIGH   1
#define SAL_TASK_PRIO_RT_LOW    99
#define SAL_TASK_PRIO_NICE_HIGH 100
#define SAL_TASK_PRIO_NICE_LOW  139
#define SAL_TASK_PRIO_DEF       120

#elif defined(_SAL_VXWORKS)

#define SAL_TASK_PRIO_HIGH      0
#define SAL_TASK_PRIO_LOW       255
#define SAL_TASK_PRIO_DEF       128
#define SAL_TASK_PRIO_NICE_HIGH 100
#define SAL_TASK_PRIO_NICE_LOW  139
#endif


/** Task Object */
typedef struct sal_task sal_task_t;

#ifdef __cplusplus
extern "C"
{
#endif

#define SAL_DEF_TASK_STACK_SIZE     (128 * 1024)

/** system time */
typedef struct sal_systime_s
{
    unsigned int tv_sec;     /* seconds */
    unsigned int tv_usec;    /* microseconds */
} sal_systime_t;

/**
 * Create a new task
 *
 * @param[out] ptask
 * @param[in]  name
 * @param[in]  stack_size
 * @param[in]  start
 * @param[in]  arg
 *
 * @return
 */
sal_err_t sal_task_create(sal_task_t** ptask,
                          char* name,
                          size_t stack_size,
                          int prio,
                          void (* start)(void*),
                          void* arg);

/**
 * Destroy the task
 *
 * @param[in] task
 */
void sal_task_destroy(sal_task_t* task);

/**
 * Exit the current executing task
 */
void sal_task_exit();

/**
 * Sleep for <em>msec</em> milliseconds
 *
 * @param[in] msec
 */
void sal_task_sleep(uint32_t msec);

/**
 * Yield the processor voluntarily to other tasks
 */
void sal_task_yield();

/**
 * Get current time
 *
 * @param tv
 */
void sal_gettime(sal_systime_t* tv);

/**
 * Get uptime since last startup
 *
 * @param ts
 */
void sal_getuptime(struct timespec* ts);

void sal_udelay(uint32 usec);

void sal_delay(uint32 sec);

/**
 * Set task's priority
 *
 * @param priority
 */
sal_err_t
sal_task_set_priority(int32 priority);

#ifdef __cplusplus
}
#endif

/**@}*/ /* End of @defgroup task */

#endif /* !__SAL_TASK_H__ */

