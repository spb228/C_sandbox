#ifdef __linux__
#define _GNU_SOURCE
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#endif
#include "stdlib.h"
#include "stdio.h"

/* 
pthread mutex
pthread spin lock
pthread condition
pthread semaphore
pthread barrier
*/

sem_t* sem;

void* thread_body(void* arg)
{
    printf("first thread called\n");
    int* shared_var_ptr = (int*) arg;
    sem_wait(sem);
    (*shared_var_ptr)++; 
    printf("[THREAD_1] value of shared_variable = %d\n", (int)*shared_var_ptr);
    sem_post(sem);
    return NULL;
}

void* thread_body_2(void* arg)
{
    printf("second thread called\n");
    int* shared_var_ptr = (int*) arg;
    sem_wait(sem);
    (*shared_var_ptr) += 2;
    printf("[THREAD_2] value of shared_variable = %d\n", (int)*shared_var_ptr);
    sem_post(sem);
    return NULL; 
}

int main(void)
{
    printf("starting main...\n");

    sem_t local_sem; 
    sem = &local_sem; 
    sem_init(sem, 0, 1);

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

    sem_destroy(sem);
    
    return 0;
}

