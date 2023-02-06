#include <stdio.h>

typedef struct process
{
    char name[10];
    int burst_time;
} process;

void process_scheduler(process *proc, int n)
{
    int i;
    printf("Process Name\tBurst Time\n");
    for (i = 0; i < n; i++)
        printf("%s\t\t%d\n", proc[i].name, proc[i].burst_time);
    printf("\n");
    printf("Running Processes...\n");
    for (i = 0; i < n; i++)
        printf("Running %s for %d seconds.\n", proc[i].name, proc[i].burst_time);
}

int main()
{
    process proc[] = { {"P1", 10}, {"P2", 5}, {"P3", 8} };
    // n processes
    int n = sizeof(proc) / sizeof(proc[0]);
    process_scheduler(proc, n);
    return 0;
}

