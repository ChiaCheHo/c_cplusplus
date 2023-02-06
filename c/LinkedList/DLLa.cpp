#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

class MyLinkedList {
public:

    /** Initialize your data structure here. */
    MyLinkedList() {
        head_ = tail_ = nullptr;
        size_ = 0;
    }

    // 析构函数 destructor (C++ 不像JAVA没有garbage collection) 需自已管理内存空间,避免memory leak
    // 有垃级回收机制对程序员来说就一定是好事吗？？？
    ~MyLinkedList() {
        while (head_) {
            auto node = head_;
            head_ = head_->next;
            delete node;
        }
        head_ = tail_ = nullptr;
        size_ = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size_) return -1; // illegal index
        auto node = head_;
        while (index--)
            node = node->next;
        return node->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        head_ = new ListNode(val, head_);
        if (size_++ == 0) // nice 妙啊 ...
            tail_ = head_;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto node = new ListNode(val);
        if (size_++ == 0) // nice
            head_ = tail_ = node;
        else
            tail_ = tail_->next = node;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size_) return; // illegal index
        if (index == 0) return addAtHead(val);
        if (index == size_) return addAtTail(val);
        ListNode dummy{0, head_};
        ListNode* prev = &dummy;
        while (index--)
            prev = prev->next;

        prev->next = new ListNode(val, prev->next);
        ++size_;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size_) return; // illegal index

        ListNode dummy{0, head_};
        ListNode* prev = &dummy;
        for (int i = 0; i < index; ++i)
            prev = prev->next;

        auto node_to_delete = prev->next;
        prev->next = prev->next->next;
        if (index == 0) head_ = prev->next;
        if (index == size_ - 1) tail_ = prev;

        delete node_to_delete;
        --size_;
    }

private:
    struct ListNode {
        int val;
        ListNode* next;
        // constructor 0
        ListNode(int x) : ListNode(x, nullptr) {}
        // constructor 1
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    ListNode* head_; // 头指针
    ListNode* tail_; // 尾指针
    int size_;
};

int main(int argc, char const *argv[])
{
    MyLinkedList *linkedList = new MyLinkedList();
    int num = 0;
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1,2);        //链表变为1-> 2-> 3
    num = linkedList->get(1);
    printf("%d\n", num);                //返回2
    linkedList->deleteAtIndex(1);       //现在链表是1-> 3
    num = linkedList->get(1);
    printf("%d\n", num);

    return 0;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// 作者：SupermanBlues
// 链接：https://leetcode-cn.com/problems/design-linked-list/solution/lei-si-la-by-supermanblues/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。