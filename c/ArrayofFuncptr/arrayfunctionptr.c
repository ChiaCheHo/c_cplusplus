#include <stdio.h>
// https://blog.xuite.net/jesonchung/scienceview/93554778#
#define fun(n) int func_##n() {printf("%s", __func__); return n;}
/* https://stackoverflow.com/questions/5018059/passing-the-value-of-a-variable-to-macro-in-c
#define bridge(n)  
#define arrangefunc(n) func_##n() 16

Substituting the value of i into the macro is impossible, since macro substitutions happen before your code is compiled. The C/C++ pre-processor is just that, a "pre-compile" time text processor. As such, it operates on the text found as-is in your source code.*/

fun(1)
fun(2)
fun(3)
fun(4)
fun(5)
fun(6)
fun(7)
fun(8)
//fun(9)
//fun(10)
int funcptr9()
{
    printf("%s", __func__);
    return 9;
}
int funcptr10()
{
    printf("%s", __func__);
    return 10;
}
int main() 
{
    //定義陣列，包含10個指向這些函式的指標 
    int(*a[10])() = {&func_1, &func_2,&func_3, &func_4,&func_5, &func_6, &func_7,&func_8, &funcptr9,&funcptr10};
    printf("a array:\n");
    for(int i = 0; i < 10; i++)
    {
        printf("\nreturn value: %d\n", (*a[i])());
        // 呼叫這10個函式 
    }
    printf("---------------------------------------\n");

    printf("b array:\n");
    int(*b[1])();
    b[0] = &funcptr9;
    printf("\nreturn value: %d\n", (*b[0])());

    /*int test = 1;
    arrangefunc(test);*/
    return 0;
}
