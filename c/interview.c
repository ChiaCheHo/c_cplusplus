#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gx = 0;
int* gptr = NULL;

int *f1(void)
{
    // int gx;
    gx = 10;
    return(&gx);
}

int *f2(void)
{
    // int* gptr;
    gptr = (int*) malloc(sizeof(int));
    *gptr = 10;
    return gptr;
}

#define square(a) a*a
#define MIN(a, b) a < b ? a : b
int *f3(void)
{
    int *ptr;
    ptr = (int*) malloc(sizeof(int));
    return ptr;
}

void e(int n)
{
    if(n < 3)
    {
        e(++n);
        printf("%d\n", n);
        e(++n);
    }
}

void func1(void)
{
    printf("func1\n");
}
void func2(void)
{
    printf("func2\n");
}
void func3(void)
{
    printf("func3\n");
}
void func4(void)
{
    printf("func4\n");
}
void func5(void)
{
    printf("func5\n");
}
void func6(void)
{
    printf("func6\n");
}

void (*func[])(void) = {func1, func2, func3, func4, func5, func6};

void swap()
{
    int x, y;

    printf("Enter 2 numbers:\n");
    scanf("%d%d", &x, &y);

    printf("x = %d\ny = %d\n", x, y);

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    printf("x = %d\ny = %d\n", x, y);
}

int sumofN(int n)
{
    printf("%d\n", n);
    return n==0 ? 0: n + sumofN(n-1);
}

char *my_strcat(char *s1, const char *s2)
{
    // Self Practice
    // char *p1 = s1;
    // const char *p2 = s2;

    // while(*p1)
    //     p1++;
    // while(*p2)
    //     *p1++ = *p2++;

    // 1
    // https://dotblogs.com.tw/Ace_Dream/2016/01/06/strcat_strncat
    // 阿夢程式設計
    // char *save = s1;
    // while (*save != 0)
    // {
    //     save++;//記住s1的最後一個位置
    // }
    // for (; *s2 != '\0'; save++, s2++)
    // {
    //     *save = *s2;//s1最後一個位置的下一個位置開始append s2的值
    // }
    // *save = '\0';//save的第1個為null的空間 = '\0' 在這空間之後還是null
    // return(save);

    // 2
    // https://edisonx.pixnet.net/blog/post/76558463
    // http://pl-learning-blog.logdown.com/posts/1084611
    // https://chris701203.pixnet.net/blog/post/22436040
    char *ptr_1 = s1;
    const char *ptr_2 = s2;

    while(*ptr_1)
        ptr_1++;

    while(*ptr_1++ = *ptr_2++)
        ;
    // while(*ptr_2){
    //     *ptr_1 = *ptr_2;
    //     *ptr_1++;
    //     *ptr_2++;
    // }
    *ptr_1 = '\0';
    return s1;
}

int my_strlen(const char* p)
{
    const char* beg = p;
    while(*p)
        ++p;
    printf("beg ptr = %p\n", beg);
    printf("end ptr = %p\n", p);
    printf("beg ptr dif end ptr = %d\n", (int)(p-beg));
    return p-beg;
}

void *my_memmove(void* des, const void* src, int n)
{
    char* d = des;
    const char* s = (char*)src;

    if(d<s)
    {
        while(n--)
        {
            *d = *s;
            des++;
            src++;
        }
    }
    else
    {
        d += (n-1);
        s += (n-1);
        while(n--)
        {
            *d-- = *s--;
        }
    }
    return d;
}
int main(void)
{
    int ref[] = {8, 4, 0, 2};
    int *ptr;
    int index;
    ptr = ref;
    for (index = 0; index < 3; index++, ptr++)
    {
        printf("index = %d\n", index);
        printf("%d %d\n", ref[index], *ptr);
    }
    (*ptr)++;
    printf("index = %d\n", index);
    printf("%d %d\n", ref[index], *ptr);
    printf("\nHello World @@\n");

    int *testptr1 = f1();
    printf("f1 return, %p\n", testptr1);
    int *testptr2 = f2();
    printf("f2 return, %p\n", testptr2);
    int *testptr3 = f3();
    printf("f3 return, %p\n", testptr3);

    printf("e function\n");
    int a = 0;
    e(a);
    printf("End of e function\n");

    int count = 6;
    for (int i = 0; i < count; ++i)
    {
        printf("%i\n", i);
        func[i]();
    }

    // 2. ask: the value of *(a+1), (*p-1)?
    // https://blog.csdn.net/irlwh/article/details/57417508
    // https://blog.csdn.net/jjjcainiao/article/details/20608039
    // https://www.ptt.cc/bbs/C_and_CPP/M.1372361924.A.D2B.html
    printf("size of 'int' is %ld\n", sizeof(int));
    int arr[5] ={1,2,3,4,5};
    int *p = (int *)(&arr+1);

    printf("arr       = %p\n", arr);       // arr       = 0x7ffc79e3d500 // arr    = 0061FED8
    printf("&arr      = %p\n", &arr);      // &arr      = 0x7ffc79e3d500 // &arr   = 0061FED8
    printf("arr+1     = %p\n", arr+1);     // arr+1     = 0x7ffc79e3d504 // arr+1  = 0061FEDC
    printf("p         = %p\n", p);         // p         = 0x7ffc79e3d514 // p      = 0061FEEC
    printf("&arr+1    = %p\n", (&arr+1));  // &arr+1    = 0x7ffc79e3d514 // &arr+1 = 0061FEEC
    printf("*(p+5)    = %d\n", *(p+5));    // *(p+5)    = 0              // *(p+5) = 2003136493
    printf("*(p+4)    = %d\n", *(p+4));    // *(p+4)    = 0              // *(p+4) = 6422280
    printf("*(p+3)    = %d\n", *(p+3));    // *(p+3)    = 0              // *(p+3) = 2
    printf("*(p+2)    = %d\n", *(p+2));    // *(p+2)    = 0              // *(p+2) = 1
    printf("*(p+1)    = %d\n", *(p+1));    // *(p+1)    = 0              // *(p+1) = 4
    printf("*(&arr)   = %p\n", *(&arr));   // *(&arr)   = 2044974336     // *(&arr)= 6422232
    printf("*(&arr+1) = %p\n", *(&arr+1)); // *(&arr+1) = 2044974356     // *(&arr+1) = 6422252
    printf("*(p)      = %d\n", *(p));      // *(p)      = 0              // *(p)   = 8
    printf("(p-1)     = %p\n", (p-1));     // (p-1)     = 0x7ffc79e3d510 //
    printf("*(p-1)    = %d\n", *(p-1));    // *(p-1)    = 5              // *(p-1) = 5
    printf("(p-2)     = %p\n", (p-2));     // (p-2)     = 0x7ffc79e3d50c //
    printf("*(p-2)    = %d\n", *(p-2));    // *(p-2)    = 4              // *(p-2) = 4
    printf("(p-3)     = %p\n", (p-3));     // (p-3)     = 0x7ffc79e3d508 //
    printf("*(p-3)    = %d\n", *(p-3));    // *(p-3)    = 3              // *(p-3) = 3
    printf("(p-4)     = %p\n", (p-4));     // (p-4)     = 0x7ffc79e3d504 //
    printf("*(p-4)    = %d\n", *(p-4));    // *(p-4)    = 2              // *(p-4) = 2
    printf("(p-5)     = %p\n", (p-5));     // (p-5)     = 0x7ffc79e3d500 //
    printf("*(p-5)    = %d\n", *(p-5));    // *(p-5)    = 1              // *(p-5) = 1
    printf("*(arr+1)  = %d\n", *(arr+1));  // *(arr+1)  = 2              // *(arr+1) = 2
    printf("*(arr+2)  = %d\n", *(arr+2));  // *(arr+2)  = 3              // *(arr+2) = 3
    printf("(*p+1)    = %d\n", (*p+1));    // (*p+1)    = 1              // (*p+1) = 9
    printf("(*p)      = %d\n", (*p));      // (*p)      = 0              // (*p)   = 8
    printf("(*p-1)    = %d\n", (*p-1));    // (*p-1)    = -1             // (*p-1) = 7
    printf("(*p-2)    = %d\n", (*p-2));    // (*p-2)    = -2             // (*p-2) = 6
    printf("(*p-3)    = %d\n", (*p-3));    // (*p-3)    = -3             // (*p-3) = 5
    printf("(*p-4)    = %d\n", (*p-4));    // (*p-4)    = -4             // (*p-4) = 4

    // swap();

    printf("%d\n", square(10));

    printf("%d\n", sumofN(10));

    // string functions test

    // string copy...
    char string_1[16] = "hello, world";
    char string_2[16] = "";

    printf("string_2 is = %s\n", string_2);

    strcpy(string_2, string_1);

    printf("string_2 is = %s\n", string_2);

    // string concat...
    char string_3[16] = " first... ";

    printf("string_3 is = %s\n", string_3);

    my_strcat(string_3, string_1);

    printf("string_3 is = %s\n", string_3);

    // string length...
    int len = 0;

    len = my_strlen(string_1);
    printf("the length of string_1 is %d.\n", len);

    printf("%d\n", MIN(10, 11));

    // realtek interview testing...
    char *aptr;
    printf("%p\n", aptr);
    aptr = (char*) malloc(sizeof(char));
    *aptr = 100;

    printf("%d\n", *aptr);

    /* A C program to demonstrate working of memmove */

    char str1[] = "Geeks"; // Array of size 100
    char str2[] = "Quiz"; // Array of size 5

    puts("str1 before memmove ");
    puts(str1);

    /* Copies contents of str2 to sr1 */
    my_memmove(str1, str2, sizeof(str2));

    puts("\nstr1 after memmove ");
    puts(str1);

    static int x = 5;
    static int *xptr = &x;
    printf("(int) p   => %p\n",xptr);
    printf("(int) p++ => %p\n",xptr++);
    printf("After p++ => %p\n",xptr);
    x = 5; xptr = &x;
    printf("(int) ++p => %p\n",++xptr);
    x = 5; xptr = &x;
    printf("++*p      => %d\n",++*xptr);
    x = 5; xptr = &x;
    printf("++(*p)    => %d\n",++(*xptr));
    x = 5; xptr = &x;
    printf("++*(p)    => %d\n",++*(xptr));
    x = 5; xptr = &x;
    printf("*p++      => %d\n",*xptr++);
    x = 5; xptr = &x;
    printf("(*p)++    => %d\n",(*xptr)++);
    x = 5; xptr = &x;
    printf("*(p)++    => %d\n",*(xptr)++);
    x = 5; xptr = &x;
    printf("*++p      => %d\n",*++xptr);
    x = 5; xptr = &x;
    printf("*(++p)    => %d\n",*(++xptr));

    int array[] = {1,2,3,4,5,6};
    int *arrayPtr;
    arrayPtr = array;

    *(arrayPtr++) += 100;
    *(++arrayPtr) += 100;

    // printf("%d\n", (int)(sizeof(array)/sizeof(int)));

    for (int i = 0; i < sizeof(array)/sizeof(int); ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}