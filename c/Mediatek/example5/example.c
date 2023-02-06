#include<stdio.h>
#include <stdlib.h>

int fun(int x);

void main() {
    printf("%d\n", (fun(456)));
    printf("%d\n", (fun(123)));
    printf("%d\n", (fun(789)));
    
}

int fun(int x) {

   int count = 0;
   while(x){
      count++;
      x = x & (x-1);
   }

   return count;
}      
