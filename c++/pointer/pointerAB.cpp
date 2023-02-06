#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void)
{
	// your code goes here
	int A=0;
	int B=1;
	int *pA=&A,*pB=&B;
	int *&rpA=pA,*&rpB=pB;
	cout<<*pA<<' '<<*pB<<endl;
	cout<<*rpA<<' '<<*rpB<<endl;
	rpA=&B,rpB=&A;
	cout<<*pA<<' '<<*pB<<endl;
	// system("pause");
	return 0;
}