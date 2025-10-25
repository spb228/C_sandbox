#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/*
 IPC Techniques
 * shared memory // pull-based
 * filesystem // pull-based
 * posix signals // push-based
 * posix pipes // push-based
 * posix message queues // push-based
 * unix domain sockets // push-based
 * network sockets // push-based
*/

int main(int argc, char** argv)
{
    printf("hello from ipc main!\n");

    return 0; 
}
