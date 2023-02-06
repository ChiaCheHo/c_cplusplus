// 1.高斯列主消元法

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
#define EPS 1e-10 //定义EPS为1乘以10的-10次方
void main()
{
    float A[N][N + 1]; //定义zengguang矩阵

    float sum = 0;
    int i, j, k;
    int n;
    int flag = 1;

    while (flag)
    {
        printf("请输入系数矩阵的大小：");
        scanf("%d", &n);
        if (n > N)
        {
            printf("矩阵过大！\n");
            continue;
        }
        flag = 0;
    }
    printf("请输入系数矩阵值：\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    /*显示原始矩阵*/
    printf("\n原始矩阵：\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%0.3f ", A[i][j]);
        printf("\n");
    }
    printf("\n\n");

    int x[N];
    int Pr, t, total;
    for (k = 1; k < N; k++)
    {
        Pr = k - 1;
        for (i = k; i < N; i++)
        {
            if (abs(A[i][k - 1]) > abs(A[Pr][k - 1]))
            {
                Pr = i;
            }
        } // End For i
        if (abs(A[i][k - 1]) < EPS)
        {
            printf("主元接近于0，方法失效\n");
            exit(0);
        }
        if (Pr > k - 1)
        {
            for (j = k - 1; j < N + 1; j++)
            {
                t = A[k - 1][j];
                A[k - 1][j] = A[Pr][j];
                A[Pr][j] = t;
            } // End For j
        }     // End if
        for (i = k; i < N; i++)
        {
            t = A[i][k - 1] / A[k - 1][k - 1];
            for (j = k - 1; j < N + 1; j++)
            {
                A[i][j] = A[i][j] - t * A[k - 1][j];
            } // End For j
        }     // End For i
    }         // End For k
    if (abs(A[N - 1][N - 1]) < EPS)
    {
        printf("主元接近于0，方法失效\n");
        exit(0);
    } // End If
    x[N - 1] = A[N - 1][N] / A[N - 1][N - 1];
    for (i = N - 2; i >= 0; i--)
    {
        total = A[i][N];
        for (j = N - 1; j >= i + 1; j--)
        {
            total -= A[i][j] * x[j];
        }
        x[i] = total / A[i][i];
    } // End For i
    for (i = 0; i < N; i++)
    {
        printf("\nx[%d]=%d\n", (i + 1), x[i]);
    } // End For i
}

// 2. LU分解法

#include <stdio.h>
#include <stdlib.h>

#define N 10 //矩阵大小范围

/*
 * 使用已经求出的x，向前计算x（供getx()调用）
 * float a[][]   矩阵U
 * float x[]     方程组解
 * int   i       解的序号（数组X元素序号）
 * int   n       矩阵大小
 * return        公式中需要的和
 */
float getmx(float a[N][N], float x[N], int i, int n)
{
    float mx = 0;
    int r;
    for (r = i + 1; r < n; r++)
    {
        mx += a[i][r] * x[r];
    }
    return mx;
}

/*
 * 使用已经求出的y，向前计算y（供gety()调用）
 * float a[][]   矩阵L
 * float y[]     数组Y
 * int   i       数组Y元素序号
 * int   n       矩阵大小
 * return        公式中需要的和
 */
float getmy(float a[N][N], float y[N], int i, int n)
{
    float my = 0;
    int r;
    for (r = 0; r < n; r++)
    {
        if (i != r)
            my += a[i][r] * y[r];
    }
    return my;
}

/*
 * 解方程组，计算某x
 * float a[][]   矩阵U
 * float x[]     方程组解
 * int   i       解的序号
 * int   n       矩阵大小
 * return        方程组的第i个解（数组X的第i个元素值）
 */
float getx(float a[N][N], float b[N], float x[N], int i, int n)
{
    float result;

    if (i == n - 1) //计算最后一个x的值
        result = (float)(b[i] / a[n - 1][n - 1]);
    else //计算其他x值（对于公式中的求和部分，需要调用getmx()函数）
        result = (float)((b[i] - getmx(a, x, i, n)) / a[i][i]);

    return result;
}

/*
 * 解数组Y，计算其中一元素值
 * float a[][]   矩阵L
 * float y[]     数组Y
 * int   i       数组Y元素序号
 * int   n       矩阵大小
 * return        数组Y的第i个元素值
 */
float gety(float a[N][N], float b[N], float y[N], int i, int n)
{
    float result;

    if (i == 0) //计算第一个y的值
        result = float(b[i] / a[i][i]);
    else //计算其他y值（对于公式中的求和部分，需要调用getmy()函数）
        result = float((b[i] - getmy(a, y, i, n)) / a[i][i]);

    return result;
}

void main()
{
    float l[N][N] = {0}; //定义L矩阵
    float u[N][N] = {0}; //定义U矩阵
    float y[N] = {0};    //定义数组Y
    float x[N] = {0};    //定义数组X
    float a[N][N];       //定义系数矩阵
    float b[N];          //定义右端项
    float sum = 0;
    int i, j, k;
    int n;
    int flag = 1;

    while (flag)
    {
        printf("请输入系数矩阵的大小：");
        scanf("%d", &n);
        if (n > N)
        {
            printf("矩阵过大！\n");
            continue;
        }
        flag = 0;
    }
    printf("请输入系数矩阵值：\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    printf("请输入右端项数组：\n");
    for (i = 0; i < n; i++)
    {
        printf("b[%d]: ", i);
        scanf("%f", &b[i]);
    }

    /*显示原始矩阵*/
    printf("\n原始矩阵：\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%0.3f ", a[i][j]);
        printf("\n");
    }
    printf("\n\n");

    /*初始化矩阵l*/
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                l[i][j] = 1;
        }
    }

    /*开始LU分解*/
    /*第一步：对矩阵U的首行进行计算*/
    for (i = 0; i < n; i++)
    {
        u[0][i] = (float)(a[0][i] / l[0][0]);
    }
    /*第二步：逐步进行LU分解*/
    for (i = 0; i < n - 1; i++)
    {
        /*对“L列”进行计算*/
        for (j = i + 1; j < n; j++)
        {
            for (k = 0, sum = 0; k < n; k++)
            {
                if (k != i)
                    sum += l[j][k] * u[k][i];
            }
            l[j][i] = (float)((a[j][i] - sum) / u[i][i]);
        }
        /*对“U行”进行计算*/
        for (j = i + 1; j < n; j++)
        {
            for (k = 0, sum = 0; k < n; k++)
            {
                if (k != i + 1)
                    sum += l[i + 1][k] * u[k][j];
            }
            u[i + 1][j] = (float)((a[i + 1][j] - sum));
        }
    }

    /*输出矩阵l*/
    printf("矩阵L：\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%0.3f ", l[i][j]);
        }
        printf("\n");
    }

    /*输出矩阵u*/
    printf("\n矩阵U：\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%0.3f ", u[i][j]);
        }
        printf("\n");
    }

    /*回代方式计算数组Y*/
    for (i = 0; i < n; i++)
    {
        y[i] = gety(l, b, y, i, n);
    }

    /*显示数组Y*/
    printf("\n\n数组Y：\n");
    for (i = 0; i < n; i++)
    {
        printf("y%d = %0.3f\n", i + 1, y[i]);
    }

    /*回代方式计算数组X*/
    for (i = n - 1; i >= 0; i--)
    {
        x[i] = getx(u, y, x, i, n);
    }

    /*显示数组X*/
    printf("\n\n数组X：\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %0.3f\n", i + 1, x[i]);
    }
}

// 3.雅克比迭代法

#include "stdio.h"
#include "math.h"
#define N 3
#define M 27
void main()
{
    int i, j, k = 1;
    float a[N][N], b[N], sum, x[N];
    printf("请按行输入原增广矩阵：\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%f", &a[i][j]);
        }
        scanf("%f", &b[i]);
    }
    printf("你输入的增广矩阵为:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("%f \n", b[i]);
    }

    for (i = 0; i < N; i++)
    {
        x[i] = 0;
    }
    while (k <= M)
    {
        printf("第%d次迭代的结果为：\n", k++);
        for (i = 0; i < N; i++)
        {
            sum = 0;
            for (j = 0; j < N; j++)
            {
                sum = sum + a[i][j] * x[j];
            }
            x[i] = x[i] + (b[i] - sum) / a[i][i];
            printf("x(%d)=%f\n", i + 1, x[i]);
        }
        printf("\n");
    }
}