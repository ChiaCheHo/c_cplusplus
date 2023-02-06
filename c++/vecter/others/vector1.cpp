#include <vector>
#include<iostream>
using namespace std;

void vec1(){
    vector<int> vec;    // 宣告一個裝 int 的 vector
                        // 現在 vec 是空的
    vec.push_back(10);
    vec.push_back(20);  // 經過三次 push_back
    vec.push_back(30);  // vec 是 [10, 20, 30]

    int length = vec.size();        // length = 3
    for(int i=0 ; i<length ; i++){
        cout << vec[i] << endl;     // 輸出 10, 20, 30
    }
}

void vec2(){
    vector<int> vec;

    for(int i=0 ; i<5 ; i++){
       vec.push_back(i * 10);       // [0, 10, 20, 30, 40]
    }

    for(int i=0 ; i<vec.size() ; i++){
        cout << vec[i] << endl;     // 輸出 0, 10, 20, 30, 40
    }
}

void vec3(){
    vector<int> vec;

    for(int i=0 ; i<5 ; i++){
       vec.push_back(i * 10);       // [0, 10, 20, 30, 40]
    }

    vec.pop_back();     // 移除 40
    vec.pop_back();     // 移除 30

    for(int i=0 ; i<vec.size() ; i++){  // vec.size() = 3
        cout << vec[i] << endl;         // 輸出 0, 10, 20
    }
}

int main()
{
    printf("\nvec1\n");
    vec1();
    printf("\nvec1\n");
    vec2();
    printf("\nvec1\n");
    vec3();
    return 0;
}
