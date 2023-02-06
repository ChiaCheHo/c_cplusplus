#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList_t
{
    int val;
    struct LinkedList_t *next;
} LinkedList;

LinkedList *myLinkedListCreate()
{
    LinkedList *obj = (LinkedList*)malloc(sizeof(LinkedList));
    obj->val = 0;
    obj->next = NULL;
    return obj;
}

int myLinkedListGet(LinkedList *obj, int index)
{
    if (0 > index && NULL == obj->next)
        return -1;
    int now = 0;
    LinkedList *p = obj->next;
    while(now < index)
    {
        now++; p = p->next;
    }
    if (p != NULL)
    {
        return p->val;
    }
    return -1;
}

void myLinkedListAddAtHead(LinkedList *obj, int val)
{
    if (NULL == obj)
        return;

    LinkedList *p = obj, *h = (LinkedList*)malloc(sizeof(LinkedList));
    h->val = val;
    h->next = p->next;
    p->next = h;
}

void myLinkedListAddAtTail(LinkedList *obj, int val)
{
    if (NULL == obj)
        return;
    LinkedList *p = obj, *t = (LinkedList*)malloc(sizeof(LinkedList));
    while(NULL != p->next)
        p = p->next;

    t->val = val;
    t->next = p->next;
    p->next = t;
}

void myLinkedListAddAtIndex(LinkedList *obj, int index, int val)
{
    if (0 > index)
        return;
    int now = 0;
    LinkedList *p = obj->next, *i = (LinkedList*)malloc(sizeof(LinkedList));
    while(now < (index - 1))
    {
        now++; p = p->next;
    }
    i->val = val;
    i->next = p->next;
    p->next = i;
}

void myLinkedListDeleteAtIndex(LinkedList *obj, int index)
{
    if (0 > index || NULL == obj->next)
        return;
    int now = 0;
    LinkedList *p = obj->next, *d;
    while(now < (index - 1))
    {
        now++; p = p->next;
    }
    d = p->next;
    p->next = d->next;
    free(d);
}

void myLinkedListFree(LinkedList *obj)
{
    while(NULL != obj->next)
    {
        myLinkedListFree(obj->next);
        obj->next = NULL;
    }
    free(obj);
}

int main(int argc, char const *argv[])
{
    LinkedList* obj = myLinkedListCreate();
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