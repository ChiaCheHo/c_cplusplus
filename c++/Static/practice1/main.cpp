#include <iostream>
#include <chrono>
using namespace std;

void greeting() {
    static int counter = 0;
    ++counter;
    cout << "Greeting function has been called " 
         << counter << " times" << endl;
}

int main() {
    
    for (int i = 0 ; i < 10; i++)
        greeting();

    return 0; 
}