#include<iostream>
using namespace std;

int fun(int &x)
{
    return x;
}
int main()
{
    int x = 10;
    int &ref = x;
    cout << fun(ref) << endl;
    // cout << fun(10);
    return 0;
}
