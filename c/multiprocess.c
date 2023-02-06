#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <math.h>

#define SEED time(NULL)
#define INTERVAL 1000000000

int g_maxPlaces;
double g_piDigits = 0;

void CalculatePi()
{
    // write code to calculate pi to g_maxPlaces
    // Update g_g_piDigits as you go
    srand( SEED );
    int i, count, n = INTERVAL;
    double x,y,z,pi;

    // printf("n = ");
    // scanf("%d", &n);

    count = 0;

    for(i = 0; i < n; ++i)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        z = x * x + y * y;
        if( z <= 1 ) count++;
    }

    pi = (double) count / n * 4;
    g_piDigits = pi;
    // Final Estimated Value
    // cout << "\nFinal Estimation of Pi = " << pi;
    printf("\nFinal Estimation of Pi = %f\n", g_piDigits);
} // CalculatePi()

int main()
{
    g_maxPlaces = 200000;
    pthread_t t1;
    // CalculatePi(); // OLD CODE: Don't do this! Instead, do...
    // StartThread(CalculatePi);
    printf("Starting Calculating PI parameter...\n");
    pthread_create(&t1, NULL, (void*) &CalculatePi, NULL);
    int times = 0;
    while (g_piDigits <= g_maxPlaces)
    {
        // printf("%f\r", g_piDigits);
        printf("%d\r", times++);
        if (0.0 != g_piDigits)
        {
            printf("%f\n", g_piDigits);
            break;
        }
    } // while
    pthread_join(t1, NULL);
} // main(