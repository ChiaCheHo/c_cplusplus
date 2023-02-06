#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void push(int number, stack **stk_ptr)
{
    printf("number   : %d\n", number);
    // printf("0x%x\n", **stk_ptr);
    stack *stk, *tmp;
    // printf("stk_ptr  : 0x%x\n", stk_ptr);
    stk = *stk_ptr;
    printf("*stk_ptr : 0x%x\n", *stk_ptr);
    tmp = malloc(sizeof(stack));
    tmp->number = number;
    tmp->next = stk;
    printf("NextSize : %d\n", sizeof(tmp->next));
    stk = tmp;
    printf("stk      : 0x%x\n", stk);
    *stk_ptr = stk;

    // Testing used
    // printf("IntSize  : %d\n", sizeof(int));
    // printf("LongSize : %d\n", sizeof(long));
    // printf("TmpSize  : %d\n", sizeof(stack));
}

int pop(stack **stk_ptr)
{
    int number;
    stack *stk, *tmp;
    stk = *stk_ptr;
    tmp = stk;
    number = tmp->number;
    stk = stk->next;
    free(tmp);
    *stk_ptr = stk;
    return number;
}