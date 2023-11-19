#include <stdio.h>
#include <unistd.h>
#include "Renice.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ProcessClient.h>
#include <sys/priority.h>

Renice::Renice(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Change the scheduling priority of a running process.");
    parser().registerFlag('n', "SET_PRIORITY", "Change priority level");
    parser().registerPositional("PRIORITY", "Priority level");
    parser().registerPositional("PROCESS_ID", "Process ID");
}

Renice::~Renice()
{
}

Renice::Result Renice::exec()
{
    if (arguments().get("PROCESS_ID") && arguments().get("SET_PRIORITY") && arguments().get("PRIORITY"))
    {
        ProcessID pid = atoi(arguments().get("PROCESS_ID"));
        int priority = atoi(arguments().get("PRIORITY"));

        int result = setpriority(pid, priority);
        if (result == -1) {
            ERROR("Invalid process ID or priority level (1-5)");
            return InvalidArgument;
        }
        
        return Success;
    }
    ERROR("Missing all arguments");
    return InvalidArgument;
}