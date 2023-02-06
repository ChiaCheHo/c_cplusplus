#include <stdio.h>
#include <pthread.h>
// https://www.google.com/search?q=mutex+%E9%99%B3%E9%8D%BE%E8%AA%A0&spell=1&sa=X&ved=2ahUKEwiGmbGhtL_pAhWaxosBHQPBDOUQBSgAegQIAhAq&biw=1304&bih=694
// https://medium.com/%E7%A8%8B%E5%BC%8F%E4%BA%BA%E6%9C%88%E5%88%8A/%E6%8E%A1%E7%94%A8-mutex-%E9%81%BF%E5%85%8D%E7%AB%B6%E7%88%AD%E6%83%85%E6%B3%81-bb2f141a05dc

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
#define LOOPS 10000
int counter = 0;

void *inc()
{
    for (int i=0; i<LOOPS; i++) {
        // printf("Increase Start\n");
        // pthread_mutex_lock( &mutex1 );   // 上鎖、避免競爭情況
        counter = counter + 1;           // 臨界區間、修改共用變數中
        // printf("Increase...\n");
        // pthread_mutex_unlock( &mutex1 ); // 變數修改完畢，解鎖
        // printf("Increase End\n");
    }
    pthread_exit(NULL);
}

void *dec()
{
    for (int i=0; i<LOOPS; i++) {
        // printf("Decrease Start\n");
        // pthread_mutex_lock( &mutex1 );   // 上鎖、避免競爭情況
        counter = counter - 1;           // 臨界區間、修改共用變數中
        // pthread_mutex_unlock( &mutex1 ); // 變數修改完畢，解鎖
        // printf("Decrease End\n");
    }
    // pthread_mutex_lock( &mutex1 );   // 上鎖、避免競爭情況
    // for (int i=0; i<LOOPS; i++) {
    //     // printf("Decrease Start\n");
    //     // counter = counter - 1;           // 臨界區間、修改共用變數中
    //     // printf("Decrease End\n");
    //     printf("Decrease...\n");
    // }
    // pthread_mutex_unlock( &mutex1 ); // 變數修改完畢，解鎖
    pthread_exit(NULL);
}

void *getcounter()
{
    for (size_t i = 0; i < LOOPS*2; i++)
    {
        if (0 != counter)
        {
            printf("current counter = %d\n", counter);
        }
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2, thread3;

    pthread_create( &thread3, NULL, getcounter, NULL);

    printf("Thread 1 created...\n");
    pthread_create( &thread1, NULL, inc, NULL);
    printf("Thread 2 created...\n");
    pthread_create( &thread2, NULL, dec, NULL);

    pthread_join( thread1, NULL);
    printf("thread 1 terminated...\n");
    pthread_join( thread2, NULL);
    printf("thread 2 terminated...\n");

    pthread_join( thread3, NULL);

    printf("End of Join\n");

    printf("counter=%d\n", counter);
}