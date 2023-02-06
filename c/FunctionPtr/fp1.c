#include <stdio.h>
// A normal function with an int parameter
// and void return type
void fun(int a, double b)
{
    printf("Value of a is %d\n", a);
    printf("Value of a is %lf\n", b);
}

int main()
{
    // fun_ptr is a pointer to function fun()
    void (*fun_ptr)(int, double) = &fun;

    /* The above line is equivalent of following two
    void (*fun_ptr)(int);
    fun_ptr = &fun;
    */

    // Invoking fun() using fun_ptr
    (*fun_ptr)(10, 10.123);

    fun_ptr(10, 10.123);

    return 0;
}
