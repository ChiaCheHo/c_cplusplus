#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <vector>

using namespace std;

// http://larry850806.github.io/2016/06/06/STL1/

int main()
{
    printf("Vector Practice 1\n");
    // Declare a int type vector and the vec is empty.
    vector<int> vec1;

    // Go through 3 times push_back, vec is [10, 20, 30].
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);

    // The length of vec shall be 3.
    int length = vec1.size();

    printf("length: %ld\n", vec1.size());

    for (int i = 0; i < length; i++)
    {
        // The ouput shall be 10, 20, 30.
        cout << vec1[i] << endl;
    }
    // cout << vec1.front() << endl;
    // cout << vec1.back() << endl;

    printf("Vector Practice 2\n");

    vector<int> vec2;

    for (int i = 0; i < 5; i++)
    {
        vec2.push_back(i * 10);
    }

    for (int i = 0; i < vec2.size(); i++)
    {
        cout << vec2[i] << endl;
    }

    printf("Vector Practice 3\n");

    vector<int> vec3;

    for(int i=0 ; i<5 ; i++){
       vec3.push_back(i * 10);       // [0, 10, 20, 30, 40]
    }

    vec3.pop_back();     // 移除 40
    vec3.pop_back();     // 移除 30

    for(int i=0 ; i<vec3.size() ; i++){  // vec.size() = 3
        cout << vec3[i] << endl;         // 輸出 0, 10, 20
    }

    return 1;
}