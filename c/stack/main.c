#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char *argv[])
{
    printf("hello\n");
    stack *stk = NULL;
    printf("stk      : 0x%x\n", stk);
    printf("&stk     : 0x%x\n", &stk);
    printf("Go into PUSH function...\n");
    push(7, &stk);
    push(2, &stk);
    push(9, &stk);
    push(12, &stk);
    printf("(%d)\n", pop(&stk));
    printf("(%d)\n", pop(&stk));
    printf("(%d)\n", pop(&stk));
    printf("(%d)\n", pop(&stk));
    printf("stk:  0x%x\n", stk);
    printf("&stk: 0x%x\n", &stk);
    printf("(%d)\n", pop(&stk));
    return 0;
}