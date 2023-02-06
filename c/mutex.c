#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Counter
int counter = 0;

// Add Mutex
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// Threads
void* child(void *ptr) {
    int t = *((int*)ptr);
    for(int i = 0;i < 3;++i)
    {
        pthread_mutex_lock( &mutex1 ); // 上鎖
        int tmp = counter;
        sleep(1);
        counter = tmp + 1;
        pthread_mutex_unlock( &mutex1 ); // 解鎖
        printf("Thread %d: Counter = %d\n", t, counter);
    }
    pthread_exit(NULL);
}

// Main Program
int main() {
    pthread_t t1, t2;
    int i[2];
    /* argument to threads */
    i[0] = 0;
    i[1] = 1;
    pthread_create(&t1, NULL, child, (void*)& i[0]);
    pthread_create(&t2, NULL, child, (void*)& i[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}