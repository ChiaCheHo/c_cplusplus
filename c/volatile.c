#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// gcc volatile.c -o volatile -lpthread -O2

// volatile bool done = false;
bool done = false;

void *tfunc(void *arg)
{
    sleep(1);
    done = true;
    return NULL;
}

void *stopfunc(void *arg)
{
    printf("Enter character 'e' to quit...\n");
    char *flag = (char*)malloc(sizeof(char));
    *flag = getchar();
    pthread_exit((void *) flag); // 傳回結果
    // char c;dfsf
    // c = getchar();
    // (char)*arg = c;
    // pthread_exit((void *) flag); // 傳回結果
}


int main(int argc, char const *argv[])
{
    pthread_t t1, t2;
    char *flag = NULL;
    void *ret;
    pthread_create(&t1, NULL, tfunc, NULL);
    // pthread_create(&t2, NULL, stopfunc, NULL);
    printf("Wainting...\n");
    while (!done)   //spin
    {
        // pthread_join(t2, &ret);
        // flag = (char*)ret;
        // printf("flag = %s\n", flag);
        // if (*flag == 'e')
        // {
        //     done = true;
        // }
        // int i;
        // char *t="#";

        // for(i=0;i<=100;i++)
        // {
        //     printf("[%s %d", t,i);
        //     printf("\r");
        //     fflush(stdout);
        //     usleep(59000);
        // }
    }
    printf("Ok. Moving on.\n");
    return 0;
}
