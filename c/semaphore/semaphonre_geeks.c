// C program to demonstrate working of Semaphores
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{
    //wait
    sem_wait(&mutex);
    printf("\n%d thread: Entered..\n", *((int *)arg));

    //critical section
    sleep(4);

    //signal
    printf("\n%d thread: Just Exiting...\n", *((int *)arg));
    sem_post(&mutex);

    pthread_exit(NULL);
}

int main()
{
    int i[2];
    /* argument to threads */
    i[0] = 0;
    i[1] = 1;
    sem_init(&mutex, 0, 1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,thread,(void *) &i[0]);
    sleep(2);
    pthread_create(&t2,NULL,thread,(void *) &i[1]);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}
