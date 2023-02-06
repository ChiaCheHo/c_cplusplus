#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void f(int *&d)
{
	d = new int(1024);
}

int main(void)
{
	// your code goes here
	// printf("hello\n");
	int *y=NULL;
	f(y);
	if (y != NULL)
		cout << "OK! y= " << *y << endl;
	else
		cout << "memory allocation fail" << endl;

	delete y;
	// system("pause");
	return 0;
}