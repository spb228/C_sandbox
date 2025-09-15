#ifdef __linux__
#define _GNU_SOURCE
#include <unistd.h>
#include <pthread.h>
#endif
#include "stdlib.h"
#include "stdio.h"

void* thread_body(void* arg)
{
    printf("hello from first thread\n");
    return NULL;
}

int main(void)
{
    printf("starting main...\n");

    pthread_t thread_1; 

    int result = pthread_create(&thread_1, NULL, thread_body, NULL);
    if (result)
    {
        printf("Error: thread could not be created...\n");
        exit(1);
    }

    result = pthread_join(thread_1, NULL);

    if (result)
    {
        printf("thread could not be joined...\n");
        exit(2);
    }
    
    return 0;
}

