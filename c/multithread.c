#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 50
// Let us create a global variable to change it in threads
int g = 0;
// Add Mutex
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
// The function to be executed by all threads
void *myThreadFun(void *vargp)
{
    // Locked
    pthread_mutex_lock( &mutex1 );
    // Store the value argument passed to this thread
    long *myid = (long *)vargp;

    // Let us create a static variable to observe its changes
    static int s = 0;

    // Change static and global variables
    ++s; ++g;

    for (int i = 0; i < (NUM_THREADS / 2); ++i)
    {
        // Print the argument, static and global variables
        printf("Thread ID: %ld, Static: %d, Global: %d\n", *myid, ++s, ++g);
    }
    // // Print the argument, static and global variables
    // printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
    // Unlocked
    pthread_mutex_unlock( &mutex1 );

    return NULL;
}

// Result:
// Thread ID: 13709096, Static: 2, Global: 2
// Thread ID: 13709096, Static: 4, Global: 4
// Thread ID: 13709096, Static: 6, Global: 6

int main()
{
    int i;
    int result_code;
    pthread_t threads[NUM_THREADS];

    // Let us create threads
    for (i = 0; i < NUM_THREADS; i++)
        pthread_create(&threads[i], NULL, myThreadFun, (void *)&threads[i]);

    for (i = 0; i < NUM_THREADS; i++)
    {
        result_code = pthread_join(threads[i], NULL);
        assert(!result_code);
        printf("IN MAIN: Thread %d has ended.\n", i);
    }
    pthread_exit(NULL);
    return 0;
}
