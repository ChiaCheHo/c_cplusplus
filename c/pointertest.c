// The output of this program can be different
// in different runs. Note that the program
// prints address of a variable and a variable
// can be assigned different address in different
// runs.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;

    // Prints address of x
    printf("the address of x pointer is %p", &x);

    printf("\n");

    char *a;
    a = (char*)malloc(sizeof(char));
    *a = 100;
    printf("a = %d", *a);
    free(a);

    return 0;
}
