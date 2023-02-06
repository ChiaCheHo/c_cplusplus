#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
執行用時 : 64 ms, 在Design Linked List的C提交中擊敗了94.00% 的用戶
內存消耗 : 15.2 MB, 在Design Linked List的C提交中擊敗了12.40% 的用戶
*/

/**
* Your MyLinkedList struct will be instantiated and called as such:
* MyLinkedList* obj = myLinkedListCreate();
* int param_1 = myLinkedListGet(obj, index);
* myLinkedListAddAtHead(obj, val);
* myLinkedListAddAtTail(obj, val);
* myLinkedListAddAtIndex(obj, index, val);
* myLinkedListDeleteAtIndex(obj, index);
* myLinkedListFree(obj);
*/

typedef int Elemtype;

typedef struct Node{
    Elemtype data; //數據域
    struct Node *next; //指向下一個結點
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    obj->next=NULL; //頭結點指向空
    return obj;
}//定義了一個帶頭節點的單鏈表,並返回頭指針

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *p=obj->next;
    int j=0;
    while(p != NULL && j < index) //從第0個節點開始找到第index個結點，並用p指向第index個節點
    {
        j++;
        p=p->next;
    }
    if(p==NULL||index<0) return -1;//p指向爲NULL(即第index個節點不存在)或者index無效，則返回-1;---重點考慮---
    else
    {
        return p->data;
    }
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    //頭插法
    MyLinkedList *p=obj,*s=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    s->data=val;
    s->next=p->next;
    p->next=s;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    //尾插法
    MyLinkedList *p=obj;

    MyLinkedList *s=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    s->data=val;
    s->next=NULL; //尾結點指向空

    while(p->next!=NULL) //找到尾結點
    {
        p=p->next;
    }
    p->next=s;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *p=obj->next,*q=obj;
    int j=0;

    while(p != NULL && j < index)//從第0個節點開始找到第index個結點，並用p指向第index個節點，q指向第index個的前驅結點
    {
        j++;
        p=p->next;
        q=q->next;
    }
    if(p!=NULL||j>=index)//---重點考慮--- p！=NULL時插入，j==index時插入即index爲最後一個節點的下一個節點，p==NULL&&index<=0時插入即單鏈表沒有結點
    //if單鏈表沒有結點，index<=0時插入，index>0時不插入；if index>鏈表長度即p==NULL時，則不插入（if index爲最後一個節點的下一個節點，則插在最後即index等於鏈表長度）
    {
        p=(MyLinkedList *)malloc(sizeof(MyLinkedList));
        p->data=val;
        p->next=q->next;
        q->next=p;
    }
}
/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int j=0;
    MyLinkedList *p = obj->next,*q = obj;
    while(p!=NULL&&j<index)//從第0個節點開始找到第index個結點，並用p指向第index個節點，q指向第index個的前驅結點
    {
        j++;
        p = p->next;
        q = q->next;
    }
    //if(p==NULL||j>index) return;
    //else
    if(p!=NULL&&index>=0)//第index個結點存在，則刪除,index<0即index爲無效值，則不刪除
    {
        q->next=p->next;
        free(p);
        p = q->next;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *p=obj,*q=p->next;
    while(q!=NULL)
    {
        free(p);
        p=q;
        q=q->next;
    }
    free(p);//釋放最後一個結點

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
    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtTail(obj, 3);
    myLinkedListAddAtIndex(obj, 1, 2);
    param_1 = myLinkedListGet(obj, 1);
    printf("%d\n", param_1);
    myLinkedListDeleteAtIndex(obj, 1);
    param_1 = myLinkedListGet(obj, 1);
    printf("%d\n", param_1);
    myLinkedListFree(obj);
    return 0;
}

/*
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[0],[1],[-1]]

["MyLinkedList","get","addAtIndex","get","get","addAtIndex","addAtIndex","get","deleteAtIndex","deleteAtIndex","addAtIndex","get"]
[[],[0],[1,2],[0],[1],[0,1],[1,2],[0],[0],[1],[2,4],[1]]

["MyLinkedList","addAtIndex","get","deleteAtIndex"]
[[],[-1,0],[0],[-1]]
預期：[null,null,0,null]

["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[0],[0]]

["MyLinkedList","get","addAtIndex","get","get","addAtIndex","get","get"]
[[],[0],[1,2],[0],[1],[0,1],[0],[1]]

測試用例，對index爲0的刪除
["MyLinkedList","addAtHead","deleteAtIndex","get"]
[[],[1],[0],[0]]

["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[4,2],[1],[-1],[1]]
預期：[null,null,null,null,3,null,3]

["MyLinkedList","addAtHead","addAtHead","deleteAtIndex","addAtIndex","addAtTail","addAtIndex","addAtTail","addAtHead","addAtHead","addAtHead","addAtTail","addAtTail","addAtHead","addAtTail","addAtTail","addAtHead","addAtTail","deleteAtIndex","addAtTail","addAtTail","get","addAtIndex","addAtHead","get","get","addAtHead","get","addAtIndex","addAtTail","addAtIndex","addAtHead","addAtHead","addAtHead","get","addAtHead","addAtIndex","addAtTail","addAtHead","addAtIndex","get","addAtTail","addAtTail","addAtIndex","addAtIndex","addAtHead","addAtHead","get","addAtTail","addAtIndex","addAtIndex","addAtHead","deleteAtIndex","addAtIndex","addAtHead","deleteAtIndex","addAtTail","deleteAtIndex","addAtTail","addAtHead","addAtTail","addAtTail","addAtHead","addAtTail","addAtIndex","deleteAtIndex","addAtHead","addAtHead","addAtHead","addAtTail","get","addAtIndex","addAtTail","addAtTail","addAtTail","deleteAtIndex","get","addAtHead","get","get","addAtTail","deleteAtIndex","addAtTail","addAtIndex","addAtHead","addAtIndex","addAtTail","get","addAtIndex","addAtIndex","addAtHead","addAtHead","get","get","get","addAtIndex","addAtHead","addAtIndex","addAtHead","addAtTail","addAtIndex","get"]
[[],[38],[45],[2],[1,24],[36],[3,72],[76],[7],[36],[34],[91],[69],[37],[38],[4],[66],[38],[14],[12],[32],[5],[7,5],[74],[7],[13],[11],[8],[10,9],[19],[3,76],[7],[37],[99],[10],[12],[1,20],[29],[42],[21,52],[11],[44],[47],[6,27],[31,85],[59],[57],[4],[99],[13,83],[10,34],[48],[9],[22,64],[69],[33],[5],[18],[87],[42],[1],[35],[31],[67],[36,46],[23],[64],[81],[29],[50],[23],[36,63],[8],[19],[98],[22],[28],[42],[24],[34],[32],[25],[53],[55,76],[38],[23,98],[27],[18],[44,27],[16,8],[70],[15],[9],[27],[59],[40,50],[15],[11,57],[80],[50],[23,37],[12]]

*/