#include <stdio.h>

void Function()
{
    printf("Call Function!\n");
}

int main()
{
    void (*p)();
    p = Function;
    (*p)();
    return 0;
}
