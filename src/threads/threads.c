#ifdef __linux__
#define _GNU_SOURCE
#include <unistd.h>
#include <pthread.h>
#endif
#include "stdlib.h"
#include "stdio.h"

pthread_mutex_t mtx;

void* thread_body(void* arg)
{
    printf("first thread called\n");
    int* shared_var_ptr = (int*) arg;
    pthread_mutex_lock(&mtx); 
    (*shared_var_ptr)++;
    printf("[THREAD_1] value of shared_variable = %d\n", (int)*shared_var_ptr);
    pthread_mutex_unlock(&mtx);
    return NULL;
}

void* thread_body_2(void* arg)
{
    printf("second thread called\n");
    int* shared_var_ptr = (int*) arg;
    pthread_mutex_lock(&mtx); 
    (*shared_var_ptr) += 2;
    printf("[THREAD_2] value of shared_variable = %d\n", (int)*shared_var_ptr);
    pthread_mutex_unlock(&mtx);
    return NULL; 
}

int main(void)
{
    printf("starting main...\n");

    pthread_mutex_init(&mtx, NULL);

    pthread_t thread_1; 
    pthread_t thread_2; 

    int shared_variable = 0;

    int result = pthread_create(&thread_1, NULL, thread_body, &shared_variable);
    if (result)
    {
        printf("Error: thread could not be created...\n");
        exit(1);
    }

    result = pthread_create(&thread_2, NULL, thread_body_2, &shared_variable);
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

    result = pthread_join(thread_2, NULL);
    if (result)
    {
        printf("thread could not be joined...\n");
        exit(2);
    }

    printf("All threads joined\n");

    pthread_mutex_destroy(&mtx);
    
    return 0;
}

