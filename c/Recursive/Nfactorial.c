#include<stdio.h>
#include<stdlib.h>

int factorial(int x)
{
    return (0 >= x) ? 1 : factorial(x - 1) * x;
}

void main()
{
    int input = 5;
    printf("%d\n", factorial(input));
}