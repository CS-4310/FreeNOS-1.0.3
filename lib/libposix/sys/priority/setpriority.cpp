
#include <FreeNOS/User.h>
#include "sys/priority.h"
#include "sys/types.h"

int setpriority(pid_t pid, int priority_level)
{
    const ulong result = (ulong) ProcessCtl(pid, SetPriorityLevel, (Address) priority_level);
    if (result == 0) {
        return priority_level;
    }
    return result;
}
