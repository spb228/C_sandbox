#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv)
{
    char* args[] = {"echo", "Hello", "World!", 0}; 
    execvp("echo", args); // create new process that replaces this process
    printf("execvp failed..."); // if this is called, execvp call failed
    return 0;
}
