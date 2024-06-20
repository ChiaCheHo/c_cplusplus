#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

sem_t semaphore;
int shared_resource = 0;

void *thread_function(void *arg) {
    int thread_num = *(int *)arg;
    
    for (int i = 0; i < 5; i++) {
        sem_wait(&semaphore);  // 等待信号量，进入临界区

        // 临界区代码
        int temp = shared_resource;
        printf("Thread %d: read shared_resource = %d\n", thread_num, temp);
        temp++;
        printf("Thread %d: incrementing shared_resource to %d\n", thread_num, temp);
        shared_resource = temp;

        sem_post(&semaphore);  // 释放信号量，离开临界区

        sleep(1);  // 模拟工作
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_nums[NUM_THREADS];

    // 初始化信号量，初值为1，表示只允许一个线程进入临界区
    sem_init(&semaphore, 0, 2);

    // 创建线程
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_nums[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_nums[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // 等待所有线程完成
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // 销毁信号量
    sem_destroy(&semaphore);

    return 0;
}
