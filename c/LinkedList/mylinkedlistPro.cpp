#include <iostream>
#include <string>
#include <vector>
#include <climits>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
    ListNode* head;
    size_t length;
public:
    /** Initialize your data structure here. */
    MyLinkedList():head(new ListNode(INT_MIN)),length(0) {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index<0 || index>static_cast<int>(length) - 1)
            return -1;
        ListNode *p = head->next;
        while (index) {
            p = p->next;
            --index;
        }
        return p->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *p = new ListNode(val);
        p->next = head->next;
        head->next = p;
        ++length;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *p = head;
        while (p->next) {
            p = p->next;
        }
        p->next = new ListNode(val);
        ++length;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index<0 || index>static_cast<int>(length))
            return;
        ListNode *p = head;
        while (index) {
            p = p->next;
            --index;
        }
        ListNode* tmp = new ListNode(val);
        tmp->next = p->next;
        p->next = tmp;
        ++length;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index<0 || index>static_cast<int>(length) - 1)
            return;
        ListNode *p = head;
        while (index) {
            p = p->next;
            --index;
        }
        ListNode* tmp = p->next;
        p->next = tmp->next;
        delete tmp;
        --length;
    }
};

int main(int argc, char const *argv[])
{
    MyLinkedList *linkedList = new MyLinkedList();
    int num = 0;
    linkedList->addAtTail(0);
    linkedList->addAtTail(1);
    linkedList->addAtTail(2);
    linkedList->addAtTail(3);
    linkedList->deleteAtIndex(10);
    // linkedList->addAtTail(4);
    // linkedList->addAtHead(1);
    // linkedList->addAtTail(3);
    // linkedList->addAtIndex(1,2);        //链表变为1-> 2-> 3
    num = linkedList->get(0);
    printf("%d\n", num);                //返回2
    num = linkedList->get(1);
    printf("%d\n", num);                //返回2
    num = linkedList->get(2);
    printf("%d\n", num);                //返回2
    num = linkedList->get(3);
    printf("%d\n", num);                //返回2
    // linkedList->deleteAtIndex(1);       //现在链表是1-> 3
    // num = linkedList->get(1);
    // printf("%d\n", num);


    // MyLinkedList *linkedList = new MyLinkedList();
    // int num = 0;
    // linkedList->addAtHead(1);
    // linkedList->addAtTail(3);
    // linkedList->addAtIndex(1,2);        //链表变为1-> 2-> 3
    // num = linkedList->get(1);
    // printf("%d\n", num);                //返回2
    // linkedList->deleteAtIndex(1);       //现在链表是1-> 3
    // num = linkedList->get(1);
    // printf("%d\n", num);

    return 0;
}