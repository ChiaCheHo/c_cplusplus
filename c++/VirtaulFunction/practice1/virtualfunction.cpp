#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <vector>
#include "virtualfunction.h"

#define Test 1

int main(void)
{
#if Test

    A *a = new B();
    a->foo();   // 在这里，a虽然是指向A的指针，但是被调用的函数(foo)却是B的!
    printf("Original\n");
    return 0;

#else

    B test;
    A *a = &test;
    a->foo();   // 在这里，a虽然是指向A的指针，但是被调用的函数(foo)却是B的!
    printf("test\n");
    return 0;

#endif
}
// ---------------------
// 作者：hackbuteer1
// 来源：CSDN
// 原文：https://blog.csdn.net/hackbuteer1/article/details/7558868
// 版权声明：本文为博主原创文章，转载请附上博文链接！