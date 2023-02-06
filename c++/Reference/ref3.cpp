#include <bits/stdc++.h>
using namespace std;

// In For Each Loops to modify all objects :
// We can use references in for each loops to modify all elements

int main()
{
    vector<int> vect{ 10, 20, 30, 40 };

    // We can modify elements if we
    // use reference
    for (int &x : vect)
        x = x + 5;

    // Printing elements
    for (int x : vect)
        cout << x << " ";

    return 0;
}
