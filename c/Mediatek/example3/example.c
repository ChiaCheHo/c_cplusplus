#include<stdio.h>
#include <stdlib.h>

void main() {

    int a[]={6,7,8,9,10};
	int *p=a;
	*(p++)+=123;
	*(++p)+=123;

	printf("The content of array a is:");
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
        printf("%d ", a[i]);
    }

    printf("\n");

}
