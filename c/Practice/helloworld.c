#include <stdio.h>
#include <stdlib.h>

void main()
{
    printf("Hello World\n");
    char *a;
    a = (char*)malloc(sizeof(char));
    *a = 100;
    printf("%d\n", *a);
    free(a);
}