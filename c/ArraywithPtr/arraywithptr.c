#include <stdio.h>
#include <stdlib.h>
//https://www.twblogs.net/a/5e4ffadfbd9eee101df8e10a
int main()
{
    //定義陣列，包含10個int*
    int*b[10];
    for(int i =0; i < 10; i++) {
        b[i] = (int*)malloc(sizeof(int));
        *b[i] = i;
    }

    int*(*a)[10] = &b; // a指向這個陣列 
    
    for(int i =0; i < 10; i++) {
        printf("%d ", *(*a)[i]); // 輸出
        free((b)[i]); // 釋放
    }
    // free(*b);
}

// #include <iostream>
// int main()
// {
//     // 定義數組，包含10個int*
//     int* b[10];
//     for(int i = 0; i < 10; ++i)
//         b[i] = new int(i+1);

//     int* (*a)[10] = &b; // a指向這個數組 

//     for(int i = 0; i < 10; ++i)
//     {
//         // printf("%d ", *(*a)[i]); // 輸出
//         std::cout << *(*a)[i] << std::endl;
//         delete (*a)[i]; // 釋放
//     }
// }

