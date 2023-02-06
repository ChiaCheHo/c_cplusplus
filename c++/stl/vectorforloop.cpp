// INTEGER VECTOR EXAMPLE
// CPP program to illustrate
// Implementation of begin() function
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // declaration of vector container
    vector<int> myvector{ 1, 2, 3, 4, 5 };

    // using begin() to print vector
    for (auto it = myvector.begin();
        it != myvector.end(); ++it)
        cout << ' ' << *it;

    printf("\n");

    // declaration of vector container
    vector<string> mystrvector{ "computer",
                             "science", "portal" };

    // using end() to print vector
    for (auto it = mystrvector.begin();
         it != mystrvector.end(); ++it)
    {
        cout << ' ' << *it;
        printf("%d\n", it);
    }

    return 0;
}
