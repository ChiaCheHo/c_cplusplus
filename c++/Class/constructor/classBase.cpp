#include <iostream>
using namespace std;
class Base
{
    public:
    int x;
    // parameterized constructor
    Base(int i)
    {
        x = i;
        cout << "Base Parameterized Constructor\n";
    }
};

class Derived : public Base
{
    public:
    int y;
    int z;
    // parameterized constructor
    Derived(int j, int v):Base(j), z()
    {
        y = j;
        z = v;
        cout << "Derived Parameterized Constructor\n";
    }
};

int main()
{
    Derived d(55, 10);
    printf("x = %d,\ny = %d,\nz = %d", d.x, d.y, d.z);
}