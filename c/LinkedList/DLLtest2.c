#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MyLinkedList_t
{
    int val;
    struct MyLinkedList_t *n;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->val = 0;
    obj->n = NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList *obj, int index)
{
    if (0 > index || obj->n == NULL)
    {
        return -1;
    }
    int now = 0;
    MyLinkedList *p = obj->n;
    while(now < index)
    {
        if (NULL == p)
            return -1;
        now++; p = p->n;
    }
    if (p != NULL)
    {
        printf("Get CMD ... %d ...\n", now);
        return p->val;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    MyLinkedList *p = obj, *h = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    h->val = val;
    h->n = p->n;
    p->n = h;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    MyLinkedList *p = obj, *t = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    while(NULL != p->n)
        p = p->n;
    t->val = val;
    t->n = p->n;
    p->n = t;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    if (0 >= index)
        myLinkedListAddAtHead(obj, val);
    int now = 0;
    MyLinkedList *p = obj->n;
    while(NULL != p->n)
    {
        if (now == (index - 1))
        {
            break;
        }
        now++; p = p->n;
    }
    if (now != (index - 1))
    {
        return;
    }
    MyLinkedList *i = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    i->val = val;
    i->n = p->n;
    p->n = i;
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    if (0 > index || NULL == obj->n)
        return;
    int now = 0;
    MyLinkedList *p = obj->n, *d;
    while(NULL != p->n)
    {
        if (now == (index - 1))
        {
            break;
        }
        now++; p = p->n;
    }
    d = p->n;
    p->n = d->n;
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
{
    // MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList
    // linkedList.addAtHead(1);
    // linkedList.addAtTail(3);
    // linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
    // linkedList.get(1);            // returns 2
    // linkedList.deleteAtIndex(1);  // now the linked list is 1->3
    // linkedList.get(1);            // returns 3
    MyLinkedList* obj = myLinkedListCreate();
    int param_1;
    printf("\n");
    myLinkedListAddAtHead(obj, 1);
    printf("\n");
    myLinkedListAddAtTail(obj, 3);
    printf("\n");
    myLinkedListAddAtIndex(obj, 1, 2);
    printf("\n");
    param_1 = myLinkedListGet(obj, 0);
    printf("CMD Get...%d\n", param_1);
    printf("\n");
    param_1 = myLinkedListGet(obj, 1);
    printf("CMD Get...%d\n", param_1);
    printf("\n");
    param_1 = myLinkedListGet(obj, 2);
    printf("CMD Get...%d\n", param_1);
    printf("\n");
    myLinkedListDeleteAtIndex(obj, 1);
    printf("\n");
    param_1 = myLinkedListGet(obj, 1);
    printf("CMD Get...%d\n", param_1);
    myLinkedListFree(obj);

    printf("\n.....Done.....\n");
    return 0;
}