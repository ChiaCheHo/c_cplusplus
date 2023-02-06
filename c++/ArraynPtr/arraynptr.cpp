#include <stdio.h>
#include <string.h>
// https://www.codevscolor.com/c-print-elements-array-address-each-element
// http://www.cchsu.com/arthur/prg_bg5/c/5.9.htm
int main()
{
    printf("Hello World\n");
    char s1[20], s2[20], s3[20];
    char *lineptr[3];
    
    strcpy(s1, "I am a student.");
    strcpy(s2, "I am a teacher.");
    strcpy(s3, "I am a an audiance.");
    
    lineptr[0] =s1;
    lineptr[1] =s2;
    lineptr[2] =s3;

    // printf("%p\n",lineptr);
    // printf("%p\n",(lineptr + 1));
    printf("%p\n", &lineptr[0]);
    printf("%p\n", &lineptr[1]);
    
    printf("%s %s\n", lineptr[0], *(lineptr + 1));
    printf("%s\n", *lineptr);
    // c/c++ priority...
    printf("%s\n", ++*lineptr);
    printf("%s\n", (2+*lineptr));

    return 0;
}

