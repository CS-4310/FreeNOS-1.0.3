#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ProcessClient.h>
#include "Wait.h"

Wait::Wait(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Wait for a process to end");
    parser().registerPositional("PID", "The ID of the process to wait on");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec() {
    ProcessID pid = (atoi(arguments().get("PID")));
    waitpid(pid, 0, 0);

    return Success;
}