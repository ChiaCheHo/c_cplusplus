#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define VAL int

typedef struct node_t
{
    VAL val;
    struct node_t *n;
} node;

node *LLCreat()
{
    return NULL;
}

VAL LLGet(node **obj, int index)
{
    if (0 > index || NULL == *obj)
    {
        return -1;
    }
    node *c = *obj;
    while(index--)
    {
        c = c->n;
    }
    return c->val;
}

void LLaddHead(node **obj, int val)
{
    node *h = (node*)malloc(sizeof(node));
    h->val = val;
    h->n = *obj;
    *obj = h;
}

void LLaddTail(node **obj, int val)
{
    node *c = *obj, *t = (node*)malloc(sizeof(node));
    while(NULL != c->n)
    {
        c = c->n;
    }
    t->val = val;
    t->n = c->n;
    c->n = t;
}

void LLaddIndex(node **obj, int index, int val)
{
    if (0 >= index || NULL == *obj)
    {
        LLaddHead(obj, val);
    }
    node *c = *obj, *i = (node*)malloc(sizeof(node));
    index--;
    while(index--)
    {
        c = c->n;
    }
    i->val = val;
    i->n = c->n;
    c->n = i;
}

void LLdelIndex(node **obj, int index)
{
    if (0 > index || NULL == *obj)
    {
        return;
    }
    node *d;
    if (0 == index)
    {
        d = *obj;
        *obj = d->n;
        free(d);
        return;
    }
    node *c = *obj;
    index--;
    while(index--)
    {
        c = c->n;
    }
    d = c->n;
    c->n = d->n;
    free(d);
}

void LLfree(node *obj)
{
    while(NULL != obj->n)
    {
        LLfree(obj->n);
        obj->n = NULL;
    }
    free(obj);
}

int main(int argc, char const *argv[])
{
    printf("Hello World\n");
    node *obj = LLCreat();
    printf("obj : 0x%x\n", &obj);
    int param = 0;
    LLaddHead(&obj, 1);
    LLaddTail(&obj, 3);
    LLaddIndex(&obj, 1, 2);
    LLaddHead(&obj, 4);

    printf("\n...first...\n");
    param = LLGet(&obj, 0);
    printf("%d\n", param);
    param = LLGet(&obj, 1);
    printf("%d\n", param);
    param = LLGet(&obj, 2);
    printf("%d\n", param);
    param = LLGet(&obj, 3);
    printf("%d\n", param);

    printf("\n...second...\n");
    LLdelIndex(&obj, 0);
    param = LLGet(&obj, 0);
    printf("%d\n", param);
    param = LLGet(&obj, 1);
    printf("%d\n", param);
    param = LLGet(&obj, 2);
    printf("%d\n", param);

    LLfree(obj);
    return 0;
}