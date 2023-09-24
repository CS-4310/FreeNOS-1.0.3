#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Wait.h"

Wait::Wait(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Wait for a process to change state");
    parser().registerPositional("PID", "The ID of the process to wait on");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
    //TODO Implement command

    // Done
    return Success;
}
