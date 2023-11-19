
#include <FreeNOS/User.h>
#include "sys/priority.h"
#include "sys/types.h"
#include <ProcessClient.h>

int setpriority(pid_t pid, int priority_level)
{   
    const ProcessClient process;
    ProcessClient::Info info;

    const ProcessClient::Result infoResult = process.processInfo(pid, info);
    if (infoResult != ProcessClient::Success) {
        return -1;
    }

    info.kernelState.priority_level = priority_level;

    API::Result resultPriority = ProcessCtl(pid, SetPriorityLevel, (Address) &info.kernelState);
    if (resultPriority != API::Success) {
        return -1;
    }
    return priority_level;
}
