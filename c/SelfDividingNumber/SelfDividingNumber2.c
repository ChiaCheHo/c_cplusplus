# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool isDividingNumbers(int num)
{
    int tmp = num;
    int dig = 0;

    while(tmp)
    {
        dig = tmp % 10;
        if(0 == dig || num % dig)
            return false;
        tmp /= 10;
    }

    return true;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* selfDividingNumbers(int left, int right, int* returnSize)
{
    *returnSize = 0;
    int size = 32;
    /*malloc 32 int at begin*/
    int *res = (int *)malloc( size * sizeof(int));

    for(int i = left;i <= right;i++)
    {
        if(isDividingNumbers(i))
        {
            if((*returnSize + 1) % 31==0)
            {
                size += 32;
                res = (int *)realloc(res,sizeof(int)*size);
            }
            res[(*returnSize)++] = i;
            // printf("%d\n", i);
        }
    }

    return res;
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
}