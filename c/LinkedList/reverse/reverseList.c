
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL)
        return NULL;
    if (head -> next == NULL)
        return head;
    struct ListNode *newHead = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return newHead;
}



作者：wpy1010011010
链接：https://leetcode-cn.com/problems/reverse-linked-list/solution/cyu-yan-fan-zhuan-lian-biao-fang-fa-zong-jie-by-sh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。