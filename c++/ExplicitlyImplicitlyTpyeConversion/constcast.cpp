#include <stdio.h>
#include <iostream>
//https://www.youtube.com/watch?v=2_-BS9UI0po

using namespace std;
// 1. The expression const_cast<T>(v) can be used to change the const or volatile qualifiers of pointers or reference.
// Where T must be a pointer, reference, or pointer-to-member type.
// 2. When we need to call some 3'rd party library where it is taking variable/object as non-const but not changing that.

void thirdPartyLibraray(int *x) {
    int k = 10;
    cout << k+*(x) << endl;
}

int main()
{
    const int a1 = 10;
    const int *b1 = &a1;
    int *d1 = const_cast<int*>(b1);
    *d1 = 15; // Invalid and Undefined Behavior!

    cout << "Invalid and Undefined Behavior!" << endl;
    cout << " a1: " << a1 << " address: " << &a1 << endl;
    cout << "*d1: " <<*d1 << " address: " << d1  << endl;

    cout << "Valid Code!" << endl;
    int a2 = 20;
    const int *b2 = &a1;
    int *d2 = const_cast<int*>(b2);
    *d2 = 30; // Valid Code!

    int constant = 26;
    const int* const_p = &constant;
    int* modifier = const_cast<int*>(const_p);
    *modifier = 3;
    cout<< "constant: "<<constant<<endl;
    cout<<"*modifier: "<<*modifier<<endl;

    const int x = 20;
    const int *px = &x;
    thirdPartyLibraray(const_cast<int*>(px));

    return 0;
}

