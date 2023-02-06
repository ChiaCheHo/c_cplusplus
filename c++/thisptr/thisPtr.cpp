#include <iostream>
using namespace std;

class thisPtr
{
    int x;

private:
    /* data */
public:
    thisPtr(/* args */);
    thisPtr(int a) : x(a) {}
    ~thisPtr();
    int get()
    {
        return this->x;
    }
    // the compiler will ultimately add this one, like below
    // int get(thisPtr *const this)
    // {
    //     return this->x;
    // }
    void set(int a) { this->x = a; }
    // the compiler will ultimately add this one, like below
    // void set(thisPtr *const this, int a)
    // {
    //     this->x = a;
    // }
    void print()
    {
        cout << this->x << endl;
    }
};

thisPtr::thisPtr(/* args */)
{
}

thisPtr::~thisPtr()
{
}

int main(int argc, char const *argv[])
{
    /* code */
    thisPtr b1;
    thisPtr b2(10);
    cout << b2.get() << endl;
    b2.set(20);
    b2.print();

    return 0;
}
