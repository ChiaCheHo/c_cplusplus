class MyLinkedList {

    private ListNode head;
    private int length;  //要注意長度和索引的區別，最大索引比長度小1

    /** Initialize your data structure here. */
    public MyLinkedList() {
        length = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        ListNode node = head;
        if(index > length -1)
            return  -1;
        else{
            for(int i=0;i<index;i++)
                node = node.next;
        }
        return node.val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        ListNode node = new ListNode(val);
        if(length == 0)
            head = node;
        else{
            node.next = head;
            head = node;
        }
        length++;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        ListNode node = new ListNode(val);
        if(length == 0)
            head = node;
        else{
            ListNode tail = head;
            for(int i=0;i<length-1;i++)
                tail = tail.next;
            tail.next = node;
        }
        length++;
    }

    /** Add a node of value val before the index-th node in the linked list.
     *  If index equals to the length of linked list, the node will be appended to the end of linked list.
     * If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        ListNode tail = head;
        ListNode node = new ListNode(val);
        if(index == length){
            addAtTail(val);
        }else if(index > length)
            return;
        else{
            for(int i=0;i<index-1;i++){
                tail = tail.next;
            }
            node.next = tail.next;
            tail.next = node;
            length++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        ListNode pre = head;
        ListNode next;
        if(index>length-1)
            return;
        else{
            for(int i=0;i<index-1;i++)
                pre = pre.next;
            next = pre.next.next;
            pre.next = next;
            length--;
        }

    }

    class ListNode{
        private int val;
        private ListNode next;
        public ListNode(){}
        public ListNode(int val){
            this.val = val;
        }
    }
}

int main(int argc, char const *argv[])
{
    MyLinkedList *linkedList = new MyLinkedList();
    int num = 0;
    linkedList->addAtHead(1);
    // linkedList->addAtTail(3);
    // linkedList->addAtIndex(1,2);        //链表变为1-> 2-> 3
    // num = linkedList->get(1);
    // printf("%d\n", num); //返回2
    // linkedList->deleteAtIndex(1);       //现在链表是1-> 3
    // num = linkedList->get(1);
    // printf("%d\n", num);

    return 0;
}