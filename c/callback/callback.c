#include <stdio.h>

struct table
{
	char id;
	void *func;
};

void *funcA(){printf("...This is funcA...\n");}
void *funcB(){printf("...This is funcB...\n");}
void *funcC(){printf("...This is funcC...\n");}
void *funcD(){printf("...This is funcD...\n");}

const struct table tb[] = {{1, funcA}, {2, funcB}, {3, funcC}, {4, funcD}};
const struct table test[] = {{1, funcA}};

void (*func)(void);

int main(int argc, char *argv[])
{
	int index = 1, count = 4;
	for (int i = 0; i < count; i++)
	{
		if (index == tb[i].id)
		{
			func = tb[i].func;
			func();
		}
		index ++;
	}

	printf("...If call the call back function here...\n");
	func();

	char a;
	printf("%ld\n", sizeof(tb));
	printf("%ld\n", sizeof(index));
	printf("%ld\n", sizeof(func));
	printf("%ld\n", sizeof(test));
	return 0;
}

// int main(void) {
// 	printf("Hello\n");
// 	return 0;
// }