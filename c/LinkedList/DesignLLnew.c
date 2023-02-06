#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MyLinkedList_t{
    int val;
    struct MyLinkedList_t *next;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    printf("Creat...\n");
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->val = 0;
    obj->next = NULL;
    printf("Obj : 0x%x\n", obj);
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index)
{
    printf("Get...index : %d\n", index);
    if (index < 0 || obj->next == NULL)
        return -1;

    int now = 0;
    MyLinkedList *p = obj->next;
    while(p != NULL && now < index)
    {
        now++;
        p = p->next;
    }
    printf("now : %d, p : 0x%x, p->val : %d\n", now, p, p->val);
    if(p != NULL)
        return p->val;
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    printf("addAtHead...\n");
    MyLinkedList *p = obj, *i = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    i->val = val;
    i->next = p->next;
    p->next = i;
    printf("obj : 0x%x, head : 0x%x, head->val : %d\n", p, i, i->val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
    printf("addAtTail...\n");
    MyLinkedList *p = obj;
    MyLinkedList *s = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    s->val = val;
    s->next = NULL;

    while(p->next != NULL)
        p = p->next;

    p->next = s;
    printf("tail : 0x%x, tail->val : %d\n", s, s->val);
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
    printf("addAtIndex...\n");
    if (index <= 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    int now = 0;
    MyLinkedList *c = obj->next;
    while((c->next != NULL) && (now < index))
    {
        if (now == index - 1) {
            break;
        }
        now++;
        c = c->next;
    }
    MyLinkedList* i = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    i->val = val;
    i->next = c->next;
    c->next = i;
    printf("c : 0x%x, c->next : 0x%x(val : %d), indexptr : 0x%x, i->next : 0x%x, now : %d, index->val : %d\n",\
     c, c->next, c->next->val, i, i->next, now, i->val);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
    printf("deleteAtIndex...\n");
    if (0 > index || NULL == obj->next)
    {
        return;
    }
    if (0 == index)
    {
        obj->next = obj->next->next;
        return;
    }
    MyLinkedList* c = obj->next;
    int now = 0;
    while((c->next != NULL) && (now < index))
    {
        if (now == index - 1) {
            break;
        }
        now++;
        c = c->next;
    }
    if (now == (index - 1))
    {
        MyLinkedList* tmp = c->next;
        c->next = c->next->next;
        printf("now : %d, tmp : 0x%x\n", now, tmp);
        free(tmp);
    }

}

void myNodeFree(MyLinkedList* Node) {
    if (Node->next != NULL)
    {
        myNodeFree(Node->next);
        Node->next = NULL;
    }
    free(Node);
}

void myLinkedListFree(MyLinkedList* obj) {
    myNodeFree(obj);
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