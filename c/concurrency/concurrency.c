#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_NUM 16

int mails = 0;
pthread_mutex_t mutex;

typedef struct thId_t
{
    int id;
    int counter;
} thid;

void initThdList(thid *l, size_t llen) {
    thid *lptr = l;
    for (size_t i = 0; i < llen; i++)
    {
        lptr[i].id = i;
        lptr[i].counter = 0;
    }
    
}

void* routine(void *ptr) {
    thid *lptr;
    lptr = (thid *)ptr;
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
        printf("Thread %d Cnt %d: Processing mail #%d\n", lptr->id, lptr->counter, mails);
        // sleep(1);
        lptr->counter++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];
    thid thdList[THREAD_NUM];
    initThdList(thdList, THREAD_NUM);
    pthread_mutex_init(&mutex, NULL);
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_create(&th[i], NULL, &routine, (void *) &thdList[i]) != 0) {
            perror("Failed to create thread");
        }
        // Original code...
        // if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
        //     perror("Failed to create thread");
        // }
    }
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
    return 0;
}