typedef struct S_stack
{
    long number;
    // int test;
    struct S_stack *next;
}stack;

void push(int number, stack **stk_ptr);
int pop(stack **stk_ptr);