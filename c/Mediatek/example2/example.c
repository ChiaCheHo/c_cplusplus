#include<stdio.h>
#include <stdlib.h>

#define DAYS_OF_MONTH(n) \
(6 == n || 9 == n || 11 == n)?30:31
void main() {
    int count = 13;
    for (int i = 6; i < count; ++i)
    {
        printf("The %dth has %d days\n", i, DAYS_OF_MONTH(i));
    }
}
