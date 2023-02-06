#include <stdio.h>
// https://blog.xuite.net/jesonchung/scienceview/93554778#
#define fun(n) int func_##n() {printf("%s", __func__); return n;} 
fun(1) 
fun(2) 
fun(3) 
fun(4) 
fun(5) 
fun(6) 
fun(7) 
fun(8) 
fun(9) 
fun(10) 
int main() 
{
    //定義陣列，包含10個指向這些函式的指標 
    int(*a[10])() = {&func_1, &func_2,&func_3, &func_4,&func_5, &func_6, &func_7,&func_8, &func_9,&func_10};

    for(int i =0; i < 10; i++)
    {
        printf("\nreturn value: %d\n", (*a[i])());
        // 呼叫這10個函式 
    }
}