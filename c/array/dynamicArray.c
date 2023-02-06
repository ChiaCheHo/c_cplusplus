#include <stdio.h>
#include <stdlib.h>//要使用malloc是要包含此標頭檔案
#include <memory.h>//要使用memset是要包含此標頭檔案
//https://www.itread01.com/article/1531981452.html
int main()
{
    int m, n;
    //scanf只是遇到回車符的時候結束，並沒有把回車符輸入，因此輸入流中還有一個回車符
    scanf("%d%d", &m,&n);
    //把輸入流中的回車符讀走
    getchar();
    int **p;
    //二級指標所在地址申請記憶體
    p = (int**)malloc(m*(sizeof(int*)));
    int i, j;
    //一級指標所在地址申請記憶體
    for (i = 0; i<m; i++)
        p[i] = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            p[i][j] = i + j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            //輸出每個元素及地址，每行的列與列之間的地址時連續的，行與行之間的地址不連續 
            printf("%d %p ", p[i][j], &p[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++) free(p[i]);  
        free(p);
    //讓程式停頓，好看到輸出
    getchar();
    return 0;
}