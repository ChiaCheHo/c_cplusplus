#include <stdio.h>
#include <stdlib.h>

#define VAL int

typedef struct node_t
{
    VAL val;
    struct node_t *n;
} node;

node *LLCreate()
{
    return NULL;
}

VAL LLGet(node **obj, int idx)
{
    if(NULL == *obj)
    {
        return 0;
    }
    if(0 >= idx)
    {
        return (*obj)->val;
    }
    node *c = *obj;
    while(idx--)
    {
        c = c->n;
    }
    return c->val;
}

void LLAddHead(node **obj, VAL val)
{
    node *h = (node*)malloc(sizeof(node));
    h->val = val;
    h->n = *obj;
    *obj = h;
}

void LLAddTail(node **obj, VAL val)
{
    node* c = *obj, *t = (node*)malloc(sizeof(node));
    while(NULL != c->n)
    {
        c = c->n;
    }
    t->val = val;
    t->n = c->n;
    c->n = t;
}

void LLAddIdx(node **obj, int idx, VAL val)
{
    if(0 >= idx || NULL == *obj)
    {
        LLAddHead(obj, val);
        return;
    }
    node *c = *obj, *i = (node*)malloc(sizeof(node));
    idx--;
    while(idx--)
    {
        c = c->n;
    }
    i->val = val;
    i->n = c->n;
    c->n = i;
}

void LLDelIdx(node **obj, int idx)
{
    if(NULL == *obj)
    {
        return;
    }
    node *d = *obj;
    if(0 >= idx)
    {
        (*obj) = d->n;
        free(d);
        return;
    }
    node *c = *obj;
    idx--;
    while(idx--)
    {
        c = c->n;
    }
    d = c->n;
    c->n = d->n;
    free(d);
}

void LLFree(node *obj)
{
    if(NULL == obj)
    {
        free(obj);
        return;
    }
    LLFree(obj->n);
    free(obj);

}

void LLshowITV(node *obj)
{
    node *c = obj;
    while(NULL != c)
    {
        printf("%d ", c->val);
        c = c->n;
    }
    printf("\n");
}

void LLshowRCV(node *obj)
{
    if(NULL == obj)
    {
        return;
    }
    printf("%d ", obj->val);
    LLshowRCV(obj->n);
}

int LLLength(node *obj)
{
    return (NULL == obj) ? 0 : (1 + LLLength(obj->n));
}

node *LLMergeTwoSortedLL(node *p1, node *p2)
{
    node *resp = NULL;
    if(NULL == p1)
    {
        return p2;
    }
    if(NULL == p2)
    {
        return p1;
    }
    if(p1->val <= p2->val)
    {
        resp = p1;
        resp->n = LLMergeTwoSortedLL(p1->n, p2);
    }
    else
    {
        resp = p2;
        resp->n = LLMergeTwoSortedLL(p1, p2->n);
    }

    return resp;
}

int test(const int n)
{
    int test = n;
    printf("n = %d\n", n);
    printf("test = %d\n", test--);
    printf("test = %d\n", test--);
    printf("test = %d\n", test);
    printf("n = %d\n", n);
}

int main() {

    printf("Hello, world!\n");
    node *obj = LLCreate();
    LLAddHead(&obj, 1);
    LLAddTail(&obj, 3);
    LLAddIdx(&obj, 1, 2);
    LLAddHead(&obj, 4);
    LLAddIdx(&obj, 0, 5);

    int param = 0;
    param = LLGet(&obj, 0);
    printf("%d\n", param);
    param = LLGet(&obj, 1);
    printf("%d\n", param);
    param = LLGet(&obj, 2);
    printf("%d\n", param);
    param = LLGet(&obj, 3);
    printf("%d\n", param);
    param = LLGet(&obj, 4);
    printf("%d\n", param);

    LLDelIdx(&obj, 2);
    LLDelIdx(&obj, 0);
    LLAddHead(&obj, 6);

    LLshowITV(obj);
    // LLshowRCV(obj);
    printf("\n");

    int size = 0;
    size = LLLength(obj);
    printf("size = %d\n", size);

    node *obj1 = LLCreate();
    node *obj2 = LLCreate();
    node *obj3 = LLCreate();

    LLAddHead(&obj1, 9);
    LLAddHead(&obj1, 7);
    LLAddHead(&obj1, 5);
    LLAddHead(&obj1, 3);
    LLAddHead(&obj1, 1);

    LLAddHead(&obj2, 10);
    LLAddHead(&obj2, 8);
    LLAddHead(&obj2, 6);
    LLAddHead(&obj2, 4);
    LLAddHead(&obj2, 2);

    obj3 = LLMergeTwoSortedLL(obj1, obj2);

    printf("HAHAHA\n");
    LLshowRCV(obj3);
    printf("\n");
    printf("HAHAHAAGAIN\n");

    printf("RELEASE...\n");
    LLFree(obj);
    // printf("RELEASE...\n");
    // LLFree(obj1);
    // printf("RELEASE...\n");
    // LLFree(obj2);
    printf("RELEASE...\n");
    LLFree(obj3);

    printf("END...\n");

    return 0;
}