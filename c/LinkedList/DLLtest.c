#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MyLinkedList_t
{
    int val;
    struct MyLinkedList_t *next;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    printf("\n...Creat...\n");
    MyLinkedList *obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->val = 0;
    obj->next = NULL;
    printf("Obj : 0x%x\n", obj);
    return obj;
}

int myLinkedListGet(MyLinkedList *obj, int index)
{
    printf("\n...Get...index : %d\n", index);
    if (index < 0 || obj->next ==NULL)
        return -1;
    int now = 0;
    MyLinkedList *p = obj->next;
    while(now < index)
    {
        now++;
        p = p->next;
    }
    printf("now : %d, p : 0x%x, p->val : %d\n", now, p, p->val);
    if(p != NULL)
        return p->val;
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    printf("\n...addAtHead...\n");
    MyLinkedList *p = obj, *h = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    h->val = val;
    h->next = p->next;
    p->next = h;
    printf("obj : 0x%x, head : 0x%x, head->val : %d\n", p, h, h->val);
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    printf("\n...addAtTail...\n");
    MyLinkedList *p = obj, *t = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    while(p->next != NULL)
        p = p->next;
    t->val = val;
    t->next = p->next;
    p->next = t;
    printf("tail : 0x%x, tail->val : %d\n", t, t->val);
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    printf("\n...addAtIndex...\n");
    if (0 >= index)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    int now = 0;
    MyLinkedList *p = obj->next;
    while(now < index && now != (index - 1))
    {
        now++;
        p = p->next;
    }
    MyLinkedList *i = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    i->val = val;
    i->next = p->next;
    p->next = i;
    printf("c : 0x%x, c->next : 0x%x(val : %d), indexptr : 0x%x, i->next : 0x%x, now : %d, index->val : %d\n",\
     p, p->next, p->next->val, i, i->next, now, i->val);
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    printf("\n...deleteAtIndex...\n");
    if (0 > index || NULL == obj->next)
    {
        return;
    }
    int now = 0;
    MyLinkedList *p = obj->next;
    while(now < index && now != (index - 1))
    {
        now++;
        p = p->next;
    }
    MyLinkedList *d = p->next;
    p->next = p->next->next;
    printf("now : %d, d : 0x%x\n", now, d);
    free(d);
}

void myLinkedListFree(MyLinkedList *obj)
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