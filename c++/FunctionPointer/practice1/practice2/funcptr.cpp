#include <iostream>

using namespace std;

int fun();

int main()
{
	int (*ptr)() = fun;
	int addr1 = (int)fun;
	int addr2 = (int)ptr;

	fun();
	ptr();

	return 0;
}

int fun()
{
	printf("Hello\n");
}