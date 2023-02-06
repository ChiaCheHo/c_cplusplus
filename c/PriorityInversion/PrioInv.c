#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>

int THREAD_NUM;
int WORKLOAD;

#ifdef USE_SPINLOCK
pthread_spinlock_t spinlock;
#else
pthread_mutex_t mutex;
#endif

void *worker(void *arg) {
#ifdef USE_SPINLOCK
    pthread_spin_lock(&spinlock);
#else
    pthread_mutex_lock(&mutex);
#endif
    for(int i=0; i<WORKLOAD; ++i) {
        asm("nop");
    }
#ifdef USE_SPINLOCK
    pthread_spin_unlock(&spinlock);
#else
    pthread_mutex_unlock(&mutex);
#endif
}

int main(int argc, char *argv[]) {
    int THREAD_NUM = atoi(argv[1]);
    int WORKLOAD = atoi(argv[2]);

    double duration;
    struct timeval start, end;
#ifdef USE_SPINLOCK
    pthread_spin_init(&spinlock, 0);
#else
    pthread_mutex_init(&mutex, NULL);
#endif

    gettimeofday(&start, NULL);
    pthread_t tpool[THREAD_NUM];
    for(int i=0; i<THREAD_NUM; ++i) {
        pthread_create(&tpool[i], NULL, worker, NULL);
    }
    for(int i=0; i<THREAD_NUM; ++i) {
        pthread_join(tpool[i], NULL);
    }
    gettimeofday(&end, NULL);
    duration = (end.tv_sec - start.tv_sec) * 1000 +
        (double)(end.tv_usec - start.tv_usec) / 1000.0f;
    //printf("#Elapsed_time: %.3lf ms\n", duration);
    printf("%.3lf", duration);

#ifdef USE_SPINLOCK
    pthread_spin_destroy(&spinlock);
#else
    pthread_mutex_destroy(&mutex);
#endif

    return 0;
}