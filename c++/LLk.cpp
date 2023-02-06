#include <iostream>
#include <stdio.h>

#define VAL int

class LinkedList
{
private:
    struct node
    {
        VAL v;
        struct node *n;
        node() {}
        node(VAL v) : node(v, NULL) {}
        node(VAL v, node *n) : v(v), n(n) {}
    };
private:
    node *head;
    size_t length;
public:
    LinkedList() : head(NULL), length(0) {}
    ~LinkedList()
    {
        this->LLFree(head);
    }
    VAL get(int idx)
    {
        if (NULL == head)
        {
            return 0;
        }
        if (0 >= idx)
        {
            return head->v;
        }
        node *c = head;
        while (idx--)
        {
            c = c->n;
        }
        return c->v;
    }
    void addHead(VAL v)
    {
        node *h = new node(v, head);
        head = h;
    }
    void addTail(VAL v)
    {
        node *t = new node(v, head);
        if (NULL == head)
        {
            head = t;
            return;
        }
        node *c = head;
        while (NULL != c->n)
        {
            c = c->n;
        }
        t->n = c->n;
        c->n = t;
    }
    void addIdx(int idx, VAL v)
    {
        if (NULL == head || 0 >= idx)
        {
            this->addHead(v);
            return;
        }
        node *c = head;
        idx--;
        while (idx-- && NULL != c->n)
        {
            c = c->n;
        }
        node*i = new node(v, c->n);
        c->n = i;
    }
    void delIdx(int idx)
    {
        if (NULL == head)
        {
            return;
        }
        node *d = head;
        if (0 >= idx)
        {
            head = d->n;
            delete d;
            return;
        }
        node *c = head;
        idx--;
        while (idx-- && NULL != c->n->n)
        {
            c = c->n;
        }
        d = c->n;
        c->n = d->n;
        delete d;
    }
    int LenRcv(node *c)
    {
        return (NULL == c) ? 0 : (1 + this->LenRcv(c->n));
    }
    int Length()
    {
        length = this->LenRcv(head);
        std::cout << "size = " << length << std::endl;
        return length;
    }
    void LLShow()
    {
        node *c = head;
        while (NULL != c)
        {
            std::cout << c->v << "->";
            c = c->n;
        }
        std::cout << "nullptr" << std::endl;
    }
    void ShowRCV(node *c)
    {
        if (NULL == c)
        {
            return;
        }
        std::cout << c->v << "->";
        this->ShowRCV(c->n);
    }
    void Show()
    {
        this->ShowRCV(head);
        std::cout << "nullptr" << std::endl;
    }
    void LLFree(node *obj)
    {
        if (NULL == obj)
        {
            return;
        }
        this->LLFree(obj->n);
        delete obj;
    }
    void Free()
    {
        this->LLFree(head);
        head = NULL;
        length = 0;
    }
    node *Merge(const node *p1, const node *p2)
    {
        if (NULL == p1 && NULL == p2)
        {
            return NULL;
        }
        node *resp = new node();
        if (NULL == p1)
        {
            resp->v = p2->v;
            resp->n = this->Merge(NULL, p2->n);
        }
        if (NULL == p2)
        {
            resp->v = p1->v;
            resp->n = this->Merge(p1->n, NULL);
        }
        if (NULL != p1 && NULL != p2)
        {
            if (p1->v <= p2->v)
            {
                resp->v = p1->v;
                resp->n = this->Merge(p1->n, p2);
            }
            else
            {
                resp->v = p2->v;
                resp->n = this->Merge(p1, p2->n);
            }
        }
        return resp;
    }
    void MergeTwoSortedLL(const LinkedList *obj1, const LinkedList *obj2)
    {
        head = this->Merge(obj1->head, obj2->head);
    }
};

int main(int argc, char const *argv[])
{
    std::cout << "Hello World" << std::endl;
    int size = 0;
    LinkedList *objt = new LinkedList();

    objt->Length();

#define AddTail 10

    // First Test
    for (int i = 0; i < AddTail; ++i)
    {
        objt->addTail(i);
    }
    size = objt->Length();
    objt->LLShow();
    objt->Free();
    // Free Function Test
    for (int i = 0; i < (AddTail / 2); ++i)
    {
        objt->addTail(i);
    }
    size = objt->Length();
    objt->Show();
    objt->Free();

    LinkedList *obj = new LinkedList();

    obj->addHead(1);
    obj->addTail(3);
    obj->addIdx(1, 2);
    obj->addHead(5);
    obj->addIdx(4, 4);

    size = obj->Length();
    obj->Show();

    printf("Delete idx 0 target...\n");
    obj->delIdx(0);

    size = obj->Length();
    obj->Show();

    printf("Add over size index of Linked List via 10...\n");
    obj->addIdx(10, 10);
    size = obj->Length();
    obj->Show();

    printf("Delete over size index of Linked List via 10...\n");
    obj->delIdx(10);

    size = obj->Length();
    for (int i = 0; i < size; ++i)
    {
        printf("%d->", obj->get(i));
    }
    printf("nullptr\n");

    obj->Free();

    printf("Merge Two Sorted Linked List...\n");

#define MERGE_TEST 5
    LinkedList *obj1 = new LinkedList();
    LinkedList *obj2 = new LinkedList();

    for (int i = 2; i < MERGE_TEST + 2; ++i)
    {
        obj1->addTail(2 * i + 1);
    }
    std::cout << "obj1" << std::endl;
    obj1->Show();

    for (int i = 0; i < MERGE_TEST * 2; ++i)
    {
        obj2->addTail(2 * i);
    }
    std::cout << "obj2" << std::endl;
    obj2->Show();

    std::cout << "Merge two Sorted linkes list..." << std::endl;
    LinkedList *obj3 = new LinkedList();
    obj3->MergeTwoSortedLL(obj1, obj2);
    size = obj3->Length();
    std::cout << "obj1" << std::endl;
    obj1->Show();
    std::cout << "obj2" << std::endl;
    obj2->Show();
    std::cout << "obj3" << std::endl;
    obj3->Show();
    for (int i = 0; i < size; ++i)
    {
        printf("%d->", obj3->get(i));
    }
    printf("nullptr\n");
    obj3->Free();

    printf("END...\n");
    return 0;
}
