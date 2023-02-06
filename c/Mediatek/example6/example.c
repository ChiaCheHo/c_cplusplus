#include<stdio.h>
#include <stdlib.h>

void main() {
    int a[5] ={1,2,3,4,5};
	int *p = (int *)(&a+1);

	printf("%d\n", *(a+1));
	// printf("%d\n", &a);
	// printf("%d\n", p);
	// printf("%d\n", (*p));
	printf("%d\n", *(p-1));
    
}
