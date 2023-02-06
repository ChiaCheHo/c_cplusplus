#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std; 

class Foo1 { 
public: 
    virtual void show() { // 虛擬函式 
        cout << "Foo1's show" << endl; 
    } 
}; 

class Foo2 : public Foo1 { 
public: 
    virtual void show() { // 虛擬函式 
        cout << "Foo2's show" << endl; 
    } 
}; 

void showFooByPtr(Foo1 *foo) {
    foo->show();
}

void showFooByRef(Foo1 &foo) {
    foo.show();
}

int main() {
    Foo1 f1;
    Foo2 f2;

    printf("Dynamic Method I ... \n");

    // 動態繫結 
    showFooByPtr(&f1);
    showFooByPtr(&f2);
    cout << endl;

    printf("Dynamic Method II ... \n");

    // 動態繫結 
    showFooByRef(f1); 
    showFooByRef(f2);
    cout << endl; 

    printf("Static Method I ... \n");

    // 靜態繫結 
    f1.show(); 
    f2.show(); 

    return 0;
}