#include <bits/stdc++.h>
using namespace std;

// In For Each Loops to avoid copy of objects :
// We can use references in for each loops to avoid copy of individual objects when objects are large.

int main()
{
    vector<string> vect{"geeksforgeeks practice",
                    "geeksforgeeks write",
                    "geeksforgeeks ide"};

    // We avoid copy of the whole string
    // object by using reference.
    for (const auto &x : vect)
        cout << x << endl;

    return 0;
}
