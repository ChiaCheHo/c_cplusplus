#include <iostream>
using namespace std;
class A
{
    protected:
        int a, b;

    public:
        A(){printf("Constructor Class A...\n");}
        ~A(){printf("Deconstructor Class A...\n");}
        void getdata(int x, int y)
        {
            a = x;
            b = y;
        }
};
class B : public A
{
    public:
        B(){printf("Constructor Class B...\n");}
        ~B(){printf("Deconstructor Class B...\n");}
        void showdata()
        {
            cout << "The value of the first protected variable(output of subclass)= " << a << endl;
            cout << "The value of the second protected variable(output of subclass)" << b << endl;
            cout << "Sum of the protected variables = " << a + b << endl;
        }
};

int main()
{
    B obj;
    obj.getdata(4, 5);
    obj.showdata();
    obj.a = 10;
    obj.b = 11;
    obj.showdata();
    return (0);
}