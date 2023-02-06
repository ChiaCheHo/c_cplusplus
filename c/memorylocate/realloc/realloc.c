#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size = 0;

    printf("請輸入陣列長度：");
    scanf("%d", &size);
    int *arr1 = malloc(size * sizeof(int));

    printf("指定元素值：\n");
    for(int i = 0; i < size; i++) {
        printf("arr1[%d] = ", i);
        scanf("%d" , arr1 + i);
    }

    printf("顯示元素值：\n");
    for(int i = 0; i < size; i++) {
        printf("arr1[%d] = %d\n", i, *(arr1+i));
    }

    int *arr2 = realloc(arr1, sizeof(int) * size * 2);
    printf("顯示元素值：\n");
    for(int i = 0; i < size * 2; i++) {
        printf("arr2[%d] = %d\n", i, *(arr2+i));
    }

    printf("arr1 address: %p\n", arr1);
    printf("arr2 address: %p\n", arr2);

    free(arr2);

    // 在這邊要注意的是，上例中，arr1 與 arr2 的位址相同並不保證，
    // realloc() 會需要複製資料來改變記憶體的大小，若原位址有足夠的空間，
    // 則使用原位址調整記憶體的大小，若空間不足，則重新尋找足夠的空間來進行配置，
    // 在這個情況下，realloc() 前舊位址的空間會被釋放掉，
    // 因此，必須使用 realloc() 傳回的新位址，而不該使用舊位址，
    // 若 realloc() 失敗，則傳回空指標（null）。
    // 最好是進行檢查：
    // int *arr2 = realloc(arr1, sizeof(int) * size * 2);
    // if(!arr2) {
        // arr1 = arr2;
    // }
    // ....
    // free(arr1);

    return 0;
}