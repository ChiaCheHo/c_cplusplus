#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
// https://openhome.cc/zh-tw/algorithm/numbers/narcissistic/
int main()
{
    int num, count = 1, rem, sum;
    while(count <= 500) {
        num = count;
        sum =0;
        while(num) {
            rem = num % 10;
            sum = sum + (rem * rem * rem);
            num = num / 10;
        }
        if(count == sum) {
            printf("%d is a Armstrong number\n", count);
        }
        count++;
    }

    return 0;
}

// int isNarcissistic(double);
// void narcissistic(double*, int);

// int main(void) { 
//     double armstrongs[88] = {0};
//     narcissistic(armstrongs, 3);
//     int i;
//     for(i = 0; armstrongs[i] != 0; i++) {
//         printf("%.0f\n", armstrongs[i]);
//     }
//     return 0; 
// } 

// int isNarcissistic(double number) {
//     int digits[39] = {0};
//     double num = number;
//     int i;
//     for(i = 0; num != 0; i++) {
//         digits[i] = (int) num % 10;
//         num = (int) (num / 10);
//     }
//     double sum = 0.0;
//     int j;
//     for(j = 0; j <= i; j++) {
//         sum += pow(digits[j], i);
//     }
//     return sum == number;
// }

// void narcissistic(double* armstrongs , int n) {
//     double bound = pow(10, n < 40 ? n : 39);
//     double i;
//     int j;
//     for(i = 0, j = 0; i < bound; i++) if(isNarcissistic(i)) {
//         armstrongs[j] = i; j++;
//     }
// }
