#include <stdio.h>
#include <unistd.h>
#include "Renice.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ProcessClient.h>

Renice::Renice(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Alters the scheduling priority of a running process.");
    parse().registerPositional("PRIORITY", "change the scheduling priority to this level");
    parse().registerPositional("PROCESS_ID", "change the scheduling priority of this process");
    parser().registerFlag('n', "priority", "change priority level");
}

Renice::~Renice()
{
}

Renice::Result Renice::exec()
{
    if (arguments().getFlags().count() > 0)
    {
        ProcessClient client;
        ProcessID pid = atoi(arguments().get("PID"));
        int priority = atoi(arguments().get("PRIORITY"));
        if (priority < 1 || priority > 5)
        {
            return InvalidArgument;
        }
        client.setPriority(pid, priority);
        return Success;
    }
    return InvalidArgument;
}