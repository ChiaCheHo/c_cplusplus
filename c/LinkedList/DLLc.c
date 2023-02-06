#include <stdlib.h>
#include <stdio.h>

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
    if (NULL == *obj)
    {
        return 0;
    }
    if (0 > index)
    {
        return (*obj)->val;
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
    if (0 >= index)
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

void LLDelIndex(node **obj, int index)
{
    if (NULL == *obj)
    {
        return;
    }
    node *d = *obj;
    if (0 >= index)
    {
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
    d = c;
    c->n = d->n;
    free(d);
}

void LLFree(node *obj)
{
    while(NULL != obj->n)
    {
        LLFree(obj->n);
        obj->n = NULL;
    }
    free(obj);
    // printf("HAHAHAFREE\n");
}

// Iterative
void LLLengthIRV(node *obj, int *size)
{
    node *c = obj;
    *size = 0;
    while(NULL != c)
    {
        c = c->n;
        (*size)++;
    }
}

// Recursive
int LLLengthRCV(node *obj)
{
    // return (NULL == obj) ? 0 : (1 + LLLengthRCV(obj->n));
    if (NULL == obj)
    {
        return 0;
    }
    return 1 + LLLengthRCV(obj->n);
}

void LLShow(node **obj)
{
    node *c = *obj;
    while(NULL != c)
    {
        printf("%d ", c->val);
        c = c->n;
    }
    printf("\n");
}

node *LLMergeTwoSortedLL(node *p1, node *p2)
{
    node *rep = NULL;
    if (NULL == p1)
    {
        return p2;
    }
    else if (NULL == p2)
    {
        return p1;
    }
    if (p1->val <= p2->val)
    {
        rep = p1;
        rep->n = LLMergeTwoSortedLL(p1->n, p2);
    }
    else
    {
        rep = p2;
        rep->n = LLMergeTwoSortedLL(p1, p2->n);
    }
    return rep;
}

node *LLMergeTwoSortedLL(node *p1, node *p2)
{
    node *rep = NULL;
    if (NULL == p1)
    {
        return p2;
    }
    if (NULL == p2)
    {
        return p1;
    }
    if (p1->val <= p2->val)
    {
        rep = p1;
        rep->n = LLMergeTwoSortedLL(p1->n, p2);
    }
    else
    {
        rep = p2;
        rep->n = LLMergeTwoSortedLL(p1, p2->n);
    }
    return rep;
}

int main(int argc, char const *argv[])
{
    node *obj = LLCreat();
    int size;

    LLaddHead(&obj, 1);
    LLaddTail(&obj, 3);
    LLaddIndex(&obj, 1, 2);
    LLaddHead(&obj, 5);
    LLaddIndex(&obj, 4, 4);

    // LLLengthIRV(obj, &size);
    size = LLLengthRCV(obj);
    printf("size %d\n", size);
    LLShow(&obj);

    LLDelIndex(&obj, 0);

    // LLLengthIRV(obj, &size);
    size = LLLengthRCV(obj);
    printf("size %d\n", size);
    LLShow(&obj);

    LLFree(obj);

    printf("Merge Two Sorted Linked List...\n");

    node *obj1 = LLCreat();
    node *obj2 = LLCreat();

    LLaddHead(&obj1, 9);
    LLaddHead(&obj1, 7);
    LLaddHead(&obj1, 5);
    LLaddHead(&obj1, 3);
    LLaddHead(&obj1, 1);
    LLShow(&obj1);

    LLaddHead(&obj2, 10);
    LLaddHead(&obj2, 8);
    LLaddHead(&obj2, 6);
    LLaddHead(&obj2, 4);
    LLaddHead(&obj2, 2);
    LLShow(&obj2);

    node *obj3 = LLMergeTwoSortedLL(obj1, obj2);
    LLShow(&obj3);

    printf("HAHAHA\n");

    LLFree(obj1);
    LLFree(obj2);
    LLFree(obj3);

    return 0;
}