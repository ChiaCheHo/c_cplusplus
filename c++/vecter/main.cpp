#include<vector>
#include<iostream>
using namespace std;

int main(){
    vector<string> vec;     //定义个一个字符串容器
    vector<string> hi;
    string str;
    str="abc";
    vec.push_back(str);     //把字符串str压进容器
    vec.push_back("def");   //把字符串"def"压进容器
    vec.push_back("123");
    for(int i=0; i<vec.size();i++){
        cout<<vec[i]<<endl; //打印容器的内容
    }
    cout<<endl;
    vec.pop_back();         //取出容器中最后一个
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<endl; //打印容器的内容
    }
    cout<<endl;
    hi.resize(4,"abc");     //一次性压进4个abc
    for(int i=0;i<hi.size();i++){
        cout<<hi[i]<<endl;
    }
    cout<<endl;
    str.push_back('d');     //在字符串str之后加'd'
    cout<<str<<endl;

    return 0;
}

// ---------------------
// 本文来自 踢树叶 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/geekdoe/article/details/50731833?utm_source=copy