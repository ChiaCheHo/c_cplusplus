#include <signal.h>
#include <stdio.h>
void *SigCatcher(int n)
{
    printf("Ha Ha, you can't kill me\n");
    signal(SIGINT,(void (*))SigCatcher);
    return (void *)NULL;
}

int main()
{
    int i;

    signal(SIGINT,(void (*))SigCatcher);
    for (i=0;i<10;i++) {
        sleep(1);
        printf("Just woke up, i is %d\n",i);
    }
    return 0;
}