#include <iostream>

using namespace std;

struct B {
    int m = 0;
    void hello() const {
        std::cout << "Hello world, this is B!\n";
    }
};
struct D : B {
    void hello() const {
        std::cout << "Hello world, this is D!\n";
    }
};
 
int main()
{
    //array - to - pointer followed by upcast
    D a[10];
    for(int i = 0; i < 10; i++)
    {
        a[i].hello();
    }
    B* dp = static_cast<B*>(a);
    dp->hello();
 
    // system("PAUSE");
}
