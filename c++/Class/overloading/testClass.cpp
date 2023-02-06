#include <iostream>

using namespace std;

class Box
{
public:
    Box(int h = 10, int w = 10, int len = 10);
    // Box(int h, int w, int len):height(h), width(w), length(len);
    int volume();

private:
    int height;
    int width;
    int length;
};

Box::Box(int h, int w, int len)
{
    height = h;
    width = w;
    length = len;
}

int Box::volume()
{
    return (height * width * length);
}

int main()
{
    cout << "Hello World";
    Box box1;
    cout << "The volume of box1 is " << box1.volume() << endl;
    Box box2(15);
    cout << "The volume of box1 is " << box2.volume() << endl;
    Box box3(15, 30);
    cout << "The volume of box1 is " << box3.volume() << endl;
    Box box4(15, 30, 20);
    cout << "The volume of box1 is " << box4.volume() << endl;
    return 0;
}
/*
關於構造函數的重載的幾點說明：
1、調用構造函數時不必給出實參的構造函數，稱為默認構造函數(default constructor)。顯然，無參的構造函數屬於默認構造函數。一個類只能有一個默認構造函數。如果在建立對象時選用的是無參構造函數，應注意正確書寫定義對象的語句。
2、儘管在一個類中可以包含多個構造函數，但是對於每一個對象來說，建立對象時只執行其中一個構造函數，並非每個構造函數都被執行。
*/
