#include <iostream>  //請參閱9.4節說明
using namespace std; //請參閱9.4節說明
// https://www.ptt.cc/bbs/C_and_CPP/M.1314107407.A.E72.html

class Student //自定Student資料
{
    int student_id;
    char student_name[40];

public:
    friend istream &operator>>(istream &in, Student &obj)
    {
        in >> obj.student_id >> obj.student_name;
        return in;
    }
    friend ostream &operator<<(ostream &out, Student &obj)
    {
        out << obj.student_id << '\t' << obj.student_name;
        return out;
    }
};

struct mylink //定義mylink資料結構
{
    Student data; // Student型態資料
    mylink *next; // mylink型態指標
};

class linklist //串列資料類別
{
    mylink *firstPtr; //串列起始指標
    mylink *lastPtr;  //串列結束指標
public:
    linklist() { firstPtr = lastPtr = NULL; } //建立者
    void addFront(Student obj);               //宣告插入第一項原型
    void addBack(Student obj);                //宣告插入最後項原型
    void showItem();                          //宣告顯示串列原型
};

void linklist::addFront(Student obj) //定義插入第一項函數
{
    mylink *newPtr = new mylink;
    newPtr->data = obj;
    if (firstPtr == NULL)
    {
        firstPtr = lastPtr = newPtr;
        lastPtr->next = NULL;
    }
    else
    {
        newPtr->next = firstPtr;
        firstPtr = newPtr;
    }
}

void linklist::addBack(Student obj) //定義插入最後項函數
{
    mylink *newPtr = new mylink;
    newPtr->data = obj;
    if (firstPtr == NULL)
    {
        firstPtr = lastPtr = newPtr;
        lastPtr->next = NULL;
    }
    else
    {
        lastPtr->next = newPtr;
        lastPtr = newPtr;
        lastPtr->next = NULL;
    }
}

void linklist::showItem() //定義顯示串列資料函數
{
    mylink *currentPtr = firstPtr;
    while (currentPtr != NULL)
    {
        cout << currentPtr->data << endl;
        currentPtr = currentPtr->next;
    }
}

int main()
{
    Student studata; //定義Student物件
    linklist ls;     //定義linklist物件
    char n;

    while (1)
    {
        cout << "1.插入第一項  2.插入最後項 3.顯示表單 0.結束  請選擇(1,2,3或0): ";
        cin >> n;
        switch (n)
        {
        case '1':
            cout << "請輸入學號與姓名：";
            cin >> studata;
            ls.addFront(studata);
            ls.showItem();
            break;
        case '2':
            cout << "請輸入學號與姓名：";
            cin >> studata;
            ls.addBack(studata);
            ls.showItem();
            break;
        case '3':
            cout << "列出表單：\n";
            ls.showItem();
            break;
        case '0':
            return 0;
        }
        cout << endl;
    }
}