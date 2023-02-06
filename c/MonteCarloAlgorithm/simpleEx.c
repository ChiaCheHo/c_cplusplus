#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
//https://openhome.cc/zh-tw/algorithm/randomness/pi/
#define N 10000000

int main(int argc, char **argv) { 
    srand(time(NULL)); 
    
    int sum = 0;
    unsigned long itr = (unsigned long)atoi(argv[1]);
    printf("itr = %lu\n", itr);
    
    unsigned long i;
    for(i = 1; i < itr; i++) { 
        double x = (double) rand() / RAND_MAX; 
        double y = (double) rand() / RAND_MAX; 
        if((x * x + y * y) < 1) {
            sum++; 
        }
    } 

    printf("PI = %f\n", (double) 4 * sum / (N - 1));
    
    return 0; 
}  
