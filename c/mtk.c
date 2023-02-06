#include <stdio.h>
#define SUM(a, b) a + b

void func()
{
    static int i = 0;
    i++;
    printf("%d", i);
}
#define SWAP(a, b) \
    temp = a;      \
    a = b;         \
    b = temp;
static int a1 = 1;
int a2 = 2;
int main()
{
    printf("Hello World\n");
    int a = 320;
    char *ptr;
    ptr = (char *)&a;
    printf("%d\n", *ptr);
    // char d[8] = {1,2,3,4,5,6,7,8};
    // printf("\n%x", (unsigned int) &d[0]);
    // short *a = (short*)&d[0];
    // int b = *a;
    // printf("\n%d", b);

    // int i = 10;
    // int j = 0;
    // while (i-- != 0)
    // {
    // j++;
    // }
    // printf("\n%d", j);
    // int a=0, b=0, c=0, d=0, i, result=0;
    // for(i = 0, a = 0; ++i < 5; a++)
    // {}
    // for(i = 5, b = 0; --i; b++)
    // {}
    // for(i = 0, c = 0; i++ < 5; c++)
    // {}
    // for(i = 5, d = 0; i--; d++)
    // {}
    // result = a*b*c*d;
    // printf("\n%d", d);
    // int a = SUM(3, 4) * 5;
    // printf("\n%d", a);
    // // func(func(func(func(func(func(func(func())))))));
    // func();func();func();func();func();func();func();func();

    // int data[6] = {1, 2, 3, 11 ,22 ,33};
    // int *a = data;
    // int *b = data + 3;
    // int c = *a+++*b++;
    // int d = *++a+*++b;
    // printf("%d, %d", c, d);

    // int i ,j, temp;
    // i = 5;
    // j = 10;
    // temp = 0;
    // if(i > j) SWAP(i, j);
    // printf("%d %d %d\n", i, j , temp);

    int i, j, m, n;
    i = 8;
    j = 10;
    m = ++i;
    n = j++;
    printf("%d %d %d %d", i, j, m, n);

    static int a3;
    int a4;
    printf("\n0x%x 0x%x 0x%x", (unsigned int)&a1, (unsigned int)&a3, (unsigned int)&a4);
    printf("\n0x%x", (unsigned int)&a2);

    return 0;
    return 0;
}