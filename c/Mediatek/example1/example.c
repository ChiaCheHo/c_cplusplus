#include <stdio.h>
#include <stdlib.h>

void chartest();

void main() {
    int Cnt = 10;
    const char *pc = "Welcome";
    // char *e;

    printf("   Cnt: %d\n", Cnt);
    printf("   pc  : 0x%d\n", pc);

    printf("...Go into the loop...\n");

    while(*pc++)
    {
        Cnt++;
        printf("   Cnt : %d\n", Cnt);
        printf("   pc  : 0x%d\n", pc);
        // e = strchr(pc, 'e');
        // printf("%s\n", e);
    }

    printf("...Out of the loop...\n");

    // What is the final value of Cnt?

    printf("   Cnt : %d\n", Cnt);
    printf("   pc  : 0x%d\n", pc);

    // chartest();
}

void chartest() {

    printf("Char Test : \n");
    char s1[] = "Hello World";
    char *s2  = "Hello World";

    printf("%lu\n", sizeof(s1));
    printf("%lu\n", sizeof(s2));
}