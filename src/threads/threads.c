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
    printf("passed in %d\n", *(int*)(arg));
    return NULL;
}

void* thread_body_2(void* arg)
{
    printf("hello from second thread\n");
    return NULL; 
}

int main(void)
{
    printf("starting main...\n");

    pthread_t thread_1; 
    int a = 10;

    int result = pthread_create(&thread_1, NULL, thread_body, &a);
    if (result)
    {
        printf("Error: thread could not be created...\n");
        exit(1);
    }

    pthread_t thread_2; 
    result = pthread_create(&thread_2, NULL, thread_body_2, NULL);

    result = pthread_join(thread_1, NULL);
    result = pthread_join(thread_2, NULL);

    if (result)
    {
        printf("thread could not be joined...\n");
        exit(2);
    }

    printf("All threads joined\n");
    
    return 0;
}

