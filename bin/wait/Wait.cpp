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
    const ProcessClient process;
    ProcessID pid = (atoi(arguments().get("PID")));

    ProcessClient::Info info;

    const ProcessClient::Result result = process.processInfo(pid, info);

    if (result == ProcessClient::NotFound) {
        ERROR("No process with that ID exists!");
        return InvalidArgument;
    }

    waitpid(pid, 0, 0);

    return Success;
}