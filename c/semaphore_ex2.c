/* Includes */
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h>  /* Semaphore */

/* prototype for thread routine */
void handler ( void *ptr );

/* global vars */
/* semaphores are declared global so they can be accessed
    in main() and in thread routine,
    here, the semaphore is used as a mutex */
sem_t mutex;
int counter; /* shared variable */


typedef struct thId_t
{
    int id;
    int counter;
} thid;

int main()
{
    thid t1, t2;
    pthread_t thread_a;
    pthread_t thread_b;

    /* argument to threads */
    t1.id = 1;
    t2.id = 2;
    t1.counter = 0;
    t2.counter = 0;

    sem_init(&mutex, 0, 1);      /* initialize mutex to 1 - binary semaphore */
                                /* second param = 0 - semaphore is local */

    /* Note: you can check if thread has been successfully created by checking return value of
    pthread_create */
    pthread_create (&thread_a, NULL, (void *) &handler, (void *) &t1);
    pthread_create (&thread_b, NULL, (void *) &handler, (void *) &t2);

    // 特別標註一下，join是表示要等這個thread結束才會繼續執行下去，否則主程式結束了thread還沒結束怎麼行呢XD
    pthread_join(thread_a, NULL);
    printf("1st\n");
    pthread_join(thread_b, NULL);
    printf("2nd\n");

    /* destroy semaphore */
    sem_destroy(&mutex);

    printf("t1.counter = %d, t2.counter = %d\n", t1.counter, t2.counter);

    /* exit */
    exit(0);
}

void handler(void *ptr )
{
    thid *x;
    x = ((thid *) ptr);
    printf("Thread %d: Waiting to enter critical section(region)...\n", x->id);
    /* down semaphore */
    sem_wait(&mutex);
    /* START CRITICAL REGION */
    printf("Thread %d: Now in critical section(region)...\n", x->id);
    printf("Thread %d: Counter Value: %d\n", x->id, counter);
    printf("Thread %d: Incrementing Counter...\n", x->id);
    counter++;
    counter--;
    printf("Thread %d: New Counter Value: %d\n", x->id, counter);
    printf("Thread %d: Exiting critical section(region)...\n", x->id);

    for (int i = 0; i < 1000; ++i)
    {
        printf("x.counter = %d\n", x->counter++);
        printf("Thread %d: in End Loop %d...\n", x->id, i);
        counter++;
        printf("counter = %d\n", counter);
    }

    sem_post(&mutex);
    /* END CRITICAL REGION */
    /* up semaphore */

    /* exit thread */
    pthread_exit(0);
}