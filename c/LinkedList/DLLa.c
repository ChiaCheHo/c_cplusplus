#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAL int

typedef struct MyLinkedList_t
{
    VAL val;
    struct MyLinkedList_t *n;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    return NULL;
}

VAL myLinkedListGet(MyLinkedList **obj, int index)
{
    if (0 > index || NULL == *obj)
    {
        return -1;
    }
    MyLinkedList *c = *obj;
    while(index--)
    {
        c = c->n;
    }
    return c->val;
}

void myLinkedListAddAtHead(MyLinkedList **obj, int val)
{
    MyLinkedList *h = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    h->val = val;
    h->n = *obj;
    *obj = h;
}

void myLinkedListAddAtTail(MyLinkedList **obj, int val)
{
    MyLinkedList *c = *obj, *t = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    while(NULL != c->n)
    {
        c = c->n;
    }
    t->val = val;
    t->n = c->n;
    c->n = t;
}

void myLinkedListAddAtIndex(MyLinkedList **obj, int index, int val)
{
    if (0 >= index)
    {
        myLinkedListAddAtHead(obj, val);
    }
    MyLinkedList *c = *obj, *i = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    index--;
    while(index--)
    {
        c = c->n;
    }
    i->val = val;
    i->n = c->n;
    c->n = i;
}

void myLinkedListDeleteAtIndex(MyLinkedList **obj, int index)
{
    if (0 > index || NULL == *obj)
    {
        return;
    }
    MyLinkedList *c = *obj, *d;
    index--;
    while(index--)
    {
        c = c->n;
    }
    d = c->n;
    c->n = d->n;
    free(d);
}

void myLinkedListFree(MyLinkedList *obj)
{
    while(NULL != obj->n)
    {
        myLinkedListFree(obj->n);
        obj->n = NULL;
    }
    free(obj);
}

int main(int argc, char const *argv[])
{   // MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList
    // linkedList.addAtHead(1);
    // linkedList.addAtTail(3);
    // linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
    // linkedList.get(1);            // returns 2
    // linkedList.deleteAtIndex(1);  // now the linked list is 1->3
    // linkedList.get(1);            // returns 3
    printf("Hello Woreld\n");
    MyLinkedList* obj = myLinkedListCreate();
    int param_1;
    myLinkedListAddAtHead(&obj, 1);
    myLinkedListAddAtTail(&obj, 3);
    myLinkedListAddAtIndex(&obj, 1, 2);

    myLinkedListAddAtHead(&obj, 4);

    // printf("\n1:\n");
    param_1 = myLinkedListGet(&obj, 0);
    printf("%d\n", param_1);
    // printf("CMD Get...%d\n", param_1);

    // printf("\n2:\n");
    param_1 = myLinkedListGet(&obj, 1);
    printf("%d\n", param_1);
    // printf("CMD Get...%d\n", param_1);

    // printf("\n3:\n");
    param_1 = myLinkedListGet(&obj, 2);
    printf("%d\n", param_1);
    // printf("CMD Get...%d\n", param_1);

    // printf("\n3:\n");
    param_1 = myLinkedListGet(&obj, 3);
    printf("%d\n", param_1);
    // printf("CMD Get...%d\n", param_1);

    myLinkedListDeleteAtIndex(&obj, 1);
    param_1 = myLinkedListGet(&obj, 1);
    printf("%d\n", param_1);
    // printf("CMD Get...%d\n", param_1);
    myLinkedListFree(obj);

    printf("\n.....Done.....\n");
    return 0;
}