# include <stdio.h>
# include <stdlib.h>

// 将一个数值各位存入数组 a 中，如 128，将 8, 2, 1分别存入 a[0], a[1], a[2] 中
void DividingNumber(int k, int a[], int *size)
{
    int i = 0;

    while(k > 9)
    {
        a[i++] = k%10;
        k = k / 10;
    }
    a[i] = k;
    *size = i + 1;
    // printf("temp[%d] = %d\n", i, a[i]);
}

// 主要实现的子函数
int* selfDividingNumbers(int left, int right, int* returnSize)
{
    // 注意这里必须加 static，因为，最终返回的是 a 的首地址，如果不加static，a数组将会作为临时变量，
    // 执行完这个函数，a马上就会清除内存，加上static，就为全局变量，等程序完全执行完，a才会消失。
    static int a[1000000];
    int temp[100];
    int i, j;
    int size = 0;
    int flag = 0;

    for(i = left; i <= right; i ++)
    {
        DividingNumber(i, temp, &size);
        flag = 0;
        // printf("size = %d\n", size);
        for (j = 0; j < size; j ++)
        {
            if ( temp[j] == 0)
            {

            }
            else
            {
                if (i % temp[j] == 0)
                {
                    flag ++;
                }
            }
        }

        if(flag == size)
        {
            a[(*returnSize) ++] = i;
        }
    }

    return a;
}

void main(int argc, char *argv[])
{
    int *a;
    int size = 0;
    int i = 0;

    printf("From %s to %s ...\n", argv[1], argv[2]);

    a = selfDividingNumbers(atoi(argv[1]), atoi(argv[2]), &size);
    for (i = 0; i < size; i ++)
    {
        printf("%d ", *(a + i));
    }
    printf("\n\n");

    // printf("%d\n", sizeof(int));

/*  用于测试 DividingNumber 子函数的正确性
    int a[4];
    int size;
    int i;

    DividingNumber(128, a, &size);
    for (i = 0; i < size; i ++)
    {
        printf("%d -> %d \n", i, *(a + i));
    }
*/

}

// 作者：cb_guo
// 链接：https://www.jianshu.com/p/ba1d613d6c0a
// 來源：简书
// 简书著作权归作者所有，任何形式的转载都请联系作者获得授权并注明出处。