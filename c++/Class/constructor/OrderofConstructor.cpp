#include <iostream>
using namespace std;

class Foo1 {
public:
    int x;
    Foo1(int i) {
        cout << "Foo1 constructor" << endl;
        x = i;
    }

    ~Foo1() {
        cout << "Foo1 deconstructor" << endl;
    }
};

class Foo2 : public Foo1 {
public:
    Foo2() {
        cout << "Foo2 constructor" << endl;
    }

    ~Foo2() {
        cout << "Foo2 deconstructor" << endl;
    }
};

int main() {
    Foo2 f;

    cout << endl;

    return 0;
}