// http://angelonotes.blogspot.com/2012/02/pthreadsemaphore.html
// gcc -Wall -Wextra -pedantic -Wconversion -Wshadow -o semaphonre semaphonre.c -lm -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>

long double sum = 0;
sem_t* semaphores;

struct thread_data
{
    unsigned long thread_id;
    unsigned long thread_count;
    unsigned long n;
};

void* Threading(void* rank)
{
    unsigned long my_rank = ((struct thread_data*) rank) -> thread_id;
    unsigned long my_n = ((struct thread_data*) rank) -> n / ((struct thread_data*) rank) -> thread_count;
    unsigned long my_first_i = my_n * my_rank;
    unsigned long my_last_i = my_first_i + my_n;
    long double my_sum = 0;
    long double factor = my_first_i % 2 == 0 ? 1 : -1;
    unsigned long i;

    printf("thread %ld: my_first_i = %ld, my_last_i = %ld \n", my_rank, my_first_i, my_last_i);

    for (i = my_first_i; i < my_last_i; i++, factor = -factor)
        my_sum += factor / (2 * i + 1);

    /* 打開 semaphore */
    sem_post(&semaphores[((struct thread_data*) rank) -> thread_id]);
    /* 等待 semaphore 打開的訊號 */
    /* 也可以設定為等待上一個 thread_id 完成後，再執行 thread_id + 1，形成次序。 */
    sem_wait(&semaphores[((struct thread_data*) rank) -> thread_id]);
    sum += my_sum;

    return NULL;    // pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
    unsigned long thread;
    unsigned long thread_count = strtoul(argv[1], NULL, 10);
    unsigned long n = strtoul(argv[2], NULL, 10);
    struct thread_data* thread_array = malloc(thread_count * sizeof(struct thread_data));
    pthread_t* thread_handles = malloc(thread_count * sizeof(pthread_t));

    semaphores = malloc(thread_count * sizeof(sem_t));

    /* 呼叫 argc，避免 -Wextra 編譯警告 */
    printf("Input argument numbers: %d\n", argc);

    /* 初始化 semaphores */
    for (thread = 0; thread < thread_count; thread++)
        sem_init(&semaphores[thread], 0, 0);

    /* 分流 thread */
    for (thread = 0; thread < thread_count; thread++)
    {
        thread_array[thread].thread_id = thread;
        thread_array[thread].thread_count = thread_count;
        thread_array[thread].n = n;
        pthread_create(&thread_handles[thread], NULL, Threading, (void*) &thread_array[thread]);
    }

    /* 合流 thread */
    for (thread = 0; thread < thread_count; thread++)
    {
        pthread_join(thread_handles[thread], NULL);
        /* 終止 semaphores */
        sem_destroy(&semaphores[thread]);
    }

    printf("With n = %lu terms and %lu threads,\n", n, thread_count);
    printf("\tOur estimate of pi = %.15Lf\n", 4 * sum);
    printf("\tpi = %.15f\n", 4.0 * atan(1.0));

    free(thread_array);
    free(semaphores);
    free(thread_handles);
    return 0;
}