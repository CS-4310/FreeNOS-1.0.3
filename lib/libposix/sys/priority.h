#ifndef __LIBPOSIX_PRIORITY_H
#define __LIBPOSIX_PRIORITY_H

#include <Macros.h>
#include "types.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libposix
 * @{
 */

/**
 * @brief Set the priority level of a process
 *
 * @param pid Process ID of process to set priority on.
 * @param priority_level Priority level to set.
 *
 * @return Priority level set on success or -1 on error
 */
extern C int setpriority(pid_t pid, int priority_level);

/**
 * @}
 * @}
 */

#endif /* __LIBPOSIX_PRIORITY_H */
