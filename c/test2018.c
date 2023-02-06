#include <stdio.h>

int main(void) {
// your code goes here
int r1 = 0, r2=0, r3=0, r4=0;
int t1=1, t2=2, t3=4;

r2 = (r1 = t1+10, t2+10, t3+10);
r4 = r3 = t1+10, t2+10, t3+10;

printf("r1 = %d, r2 = %d, r3 = %d, r4 = %d\r\n", r1, r2, r3, r4);

return 0;
}