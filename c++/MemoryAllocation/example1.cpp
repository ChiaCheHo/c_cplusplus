#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
// https://www.796t.com/content/1549238418.html
char s1[] = "ni";
char s2[] = "";
string n = "n";
string i= "i";

int main(int argc, char* argv[])
{
	//C++中，記憶體分成5個區，他們分別是堆、棧、自由儲存區、全域性/靜態儲存區和常量儲存區。

	//棧空間
	int a=0;
	int b=0;
	printf("Stack(棧空間)\n");
	printf("%p\n",&argc);
	printf("%p\n",&a);
	printf("%p\n",&b);
	printf("---------------------------\n");

	//全域性與靜態空間
	printf("data(全域性與靜態空間)\n");
	printf("%p\n",&s1);
	printf("%p\n",&s2);
	printf("---------------------------\n");

	//自由儲存區
	printf("heap(自由儲存區)\n");
	char **r;
	char *p0 =(char*)malloc(4); //p0指向堆
	r = &p0;
	printf("%p\n",*r);
	printf("---------------------------\n");

	//堆空間
	printf("Heap(堆空間)\n");
	char *newp = new char;
	r = &newp;
	printf("%p\n",*r);
	printf("---------------------------\n");

	//常量儲存區
	printf("常量儲存區\n");
	p0 = "ni"; //p0不再指向堆，而是常量區
	r = &p0;
	printf("%p\n",*r);
	
	printf("********************************************\n");

	p0 =(char *) malloc(4); //p0重新指向自由儲存區
	r = &p0;
	printf("%p\n",*r);
	char str[] = "ni";
	int i = 0;
	for(i=0;i<3;i++)
		p0[i] = str[i];
	r = &p0;
	printf("%p\n",*r);//p0依然指向自由儲存區的同一個地址，所以動態串要通過這種方式來去改變串的內容
					  //不然在使用realloc時會報錯
	printf("---------------------------\n");
	free(p0);
	return 0;
}
