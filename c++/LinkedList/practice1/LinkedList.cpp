#include <iostream>
using namespace std;

struct List{
    char *name;
    int age;
    List *next;
};

List *createList(char*name, int age);
void addANode(List *&ptr, char*name, int age); //要用參考才能改變ptr引數的指向位址
void deleteList(List *head);
void printfList(List *head);

int main(){
    List *head = createList("Mike", 18);
    List *ptr = head;
    addANode(ptr, "Bill", 20);
    addANode(ptr, "Lisa", 15);
    addANode(ptr, "Jeff", 29);

    ptr = head;
    printfList(ptr);

    deleteList(head);
    return 0;
}

List *createList(char*name, int age){
    List *head = new List;
    if (!head){
        cout << "memory configuration error" << endl;
        // cout << "配置記憶體失敗" << endl;
        exit(1);
    }
    head->name = name;
    head->age = age;
    head->next = NULL;
    return head;
}
void addANode(List *&ptr, char*name, int age){
    List *newnode = new List;
    if (!newnode){
        cout << "memory configuration fail" << endl;
        // cout << "配置記憶體失敗" << endl;
        exit(1);
    }
    newnode->name = name;
    newnode->age = age;
    newnode->next = NULL;
    ptr->next = newnode;
    ptr = ptr->next;
}

void printfList(List *ptr){
    while (ptr != NULL){
        cout << "Name：" << ptr->name << '\t' << "Age：" << ptr->age << endl;
        // cout << "姓名：" << ptr->name << '\t' << "年齡：" << ptr->age << endl;
        ptr = ptr->next;
    }
}

void deleteList(List *head){
    while (head != NULL){
        List *delptr = head;
        head = head->next;
        delete delptr;
    }
}