#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <omp.h>
// -fopenmp
#define FIBCOUNT 20

// hdf5 - Google Search
// https://www.google.com/search?q=hdf5&newwindow=1&source=hp&ei=qZ7IYL2fB4ukmAXy6K2QBQ&iflsig=AINFCbYAAAAAYMisudw2sz7fky810yoUcA1Iaakn2Quq&oq=hdf5&gs_lcp=Cgdnd3Mtd2l6EAMyAggAMgIILjICCAAyAggAMgIIADICCAAyAggAMgIIADICCAAyAggAOggILhDHARCjAlCXAljFCWDSEWgAcAB4AIABwAGIAZQFkgEDMi4zmAEAoAEBqgEHZ3dzLXdperABAA&sclient=gws-wiz&ved=0ahUKEwj9l-C305nxAhULEqYKHXJ0C1IQ4dUDCAc&uact=5

// 面试题—梯度消失于梯度爆炸 - 知乎
// https://zhuanlan.zhihu.com/p/51490163#:~:text=1%20%E4%BB%80%E4%B9%88%E6%98%AF%E6%A2%AF%E5%BA%A6%E6%B6%88%E5%A4%B1,%E5%87%8F%E5%B0%91%E8%BF%99%E5%B0%B1%E6%98%AF%E6%A2%AF%E5%BA%A6%E6%B6%88%E5%A4%B1%E3%80%82

// 機器學習首部 - YouTube
// https://www.youtube.com/results?search_query=%E6%A9%9F%E5%99%A8%E5%AD%B8%E7%BF%92%E9%A6%96%E9%83%A8

// 小馬技術 - YouTube
// https://www.youtube.com/results?search_query=%E5%B0%8F%E9%A6%AC%E6%8A%80%E8%A1%93

// 初學者投資生技 新藥篇
// https://topics.cnyes.com/biotech01/

// CPU比GPU訓練神經網絡快十幾倍，英特爾：別用矩陣運算了 - 幫趣
// https://bangqu.com/94whr6.html?fbclid=IwAR0Nk1kLBai-oQXqqKbtM3vG6jnSc7LsGi5EPSwv3nthHNVdQx4YbE_dKTk

// http://hackfoldr.org/linux/

#define MIN(a, b) (a < b) ? a : b

int my_strlen(const char *s)
{
    const char *e = s;
    while (*e++)
        ;
    return e - s - 1;
}

#define SEG_COUNT 4
int segments[SEG_COUNT];
char **ans;
int ans_len;

void dfs(const char *str, int segId, int segS)
{
    int len_s = my_strlen(str);
    if (SEG_COUNT == segId)
    {
        if (len_s == segS)
        {
            char *ipAddr = (char*)malloc(sizeof(char) * (len_s + 4));
            int add = 0;
            for (int i = 0; i < SEG_COUNT; ++i)
            {
                int num = segments[i];
                if (100 <= num)
                {
                    ipAddr[add++] = num / 100 + '0';
                }
                if (10 <= num)
                {
                    ipAddr[add++] = num % 100 / 10 + '0';
                }
                ipAddr[add++] = num % 10 + '0';
                if (i != (SEG_COUNT - 1))
                {
                    ipAddr[add++] = '.';
                }
            }
            ipAddr[add] = '\0';
            ans = (char**)realloc(ans, sizeof(char*) * (ans_len + 1));
            ans[ans_len++] = ipAddr;
        }
        return;
    }
    if (len_s == segS)
    {
        return;
    }
    if ('0' == str[segS])
    {
        segments[segId] = 0;
        dfs(str, segId + 1, segS + 1);
    }
    int addr = 0;
    for (int segE = segS; segE < len_s; ++segE)
    {
        addr = addr * 10 + (str[segE] - '0');
        if (0 < addr && 0xFF >= addr)
        {
            segments[segId] = addr;
            dfs(str, segId + 1, segE + 1);
        }
        else
        {
            break;
        }
    }
}

char **restoreIpAddresses(const char *s, int *returnS)
{
    ans = (char**)malloc(0);
    ans_len = 0;
    dfs(s, 0, 0);
    *returnS = ans_len;
    return ans;
}

void *my_memmove(void *dst, const void *src, int len)
{
    char *d = (char*)dst;
    const char *s = (char*)src;
    if (d < s)
    {
        while (len--)
        {
            *d++ = *s++;
        }
    }
    else
    {
        d = (char*)dst + len - 1;
        s = (char*)src + len - 1;
        while (len--)
        {
            *d-- = *s--;
        }
    }
    return dst;
}

char *my_strcat(char *str1, const char *str2)
{
    char *p1 = str1;
    const char *p2 = str2;
    while (*p1++)
        ;
    p1--;
    while (*p2)
    {
        *p1++ = *p2++;
    }
    return str1;
}

int my_sumofn(const int n)
{
    return (0 == n) ? 0 : (n + my_sumofn(n - 1));
}

void HGFEDCBA()
{
    char x = 'H', tmpx;
    while ('A' <= x)
    {
        tmpx = x--;
        while ('A' <= tmpx)
        {
            printf("%c", tmpx--);
        }
        printf("\n");
    }
}

int fib(const int n)
{
    if (1 >= n)
    {
        return (0 == n) ? 0 : 1;
    }
    else
    {
        return (fib(n - 1) + fib(n - 2));
    }
}

int my_Atoi(const char *s)
{
    int count = 0;
    for (int i = 0; '\0' != s[i]; ++i)
    {
        count = count * 10 + (s[i] - '0');
    }
    return count;
}

int countsetbits(int n)
{
    int count = 0;
    for (; n; n >>= 1)
    {
        count += (n & 0x1);
    }
    return count;
}

#define VAL int

typedef struct node_t
{
    VAL v;
    struct node_t *n;
} node;

node *LLCreate()
{
    return NULL;
}

VAL LLGet(const node **obj, int idx)
{
    if (NULL == *obj)
    {
        return 0;
    }
    if (0 >= idx)
    {
        return (*obj)->v;
    }
    const node *c = *obj;
    while (idx--)
    {
        c = c->n;
    }
    return c->v;
}

void LLaddHead(node **obj, VAL v)
{
    node *h = (node*)malloc(sizeof(node));
    h->v = v;
    h->n = *obj;
    *obj = h;
}

void LLaddTail(node **obj, VAL v)
{
    node *t = (node*)malloc(sizeof(node));
    t->v = v;
    if (NULL == *obj)
    {
        t->n = *obj;
        *obj = t;
        return;
    }
    node *c = *obj;
    while (NULL != c->n)
    {
        c = c->n;
    }
    t->n = c->n;
    c->n = t;
}

void LLaddIdx(node **obj, int idx, VAL v)
{
    if (NULL == *obj || 0 >= idx)
    {
        LLaddHead(obj, v);
        return;
    }
    node *c = *obj, *i = (node*)malloc(sizeof(node));
    i->v = v;   idx--;
    while (idx-- && NULL != c->n) // or (idx-- & (0 != idx))
    {
        c = c->n;
    }
    i->n = c->n;
    c->n = i;
}

void LLdelIdx(node **obj, int idx)
{
    if (NULL == *obj)
    {
        return;
    }
    node *d = *obj;
    if (0 >= idx)
    {
        *obj = d->n;
        free(d);
        return;
    }
    node *c = *obj;
    idx--;
    while (idx-- && NULL != c->n->n)
    {
        c = c->n;
    }
    d = c->n;
    c->n = d->n;
    free(d);
}

int LLLengthRCV(const node *obj)
{
    return (NULL == obj) ? 0 : (1 + LLLengthRCV(obj->n));
}

void LLShow(const node **obj)
{
    const node *c = *obj;
    while (NULL != c)
    {
        printf("%d->", c->v);
        c = c->n;
    }
    printf("nullptr\n");
}

void ShowRCV(const node **obj)
{
    if (NULL == *obj)
    {
        return;
    }
    printf("%d->", (*obj)->v);
    ShowRCV((const node**)&(*obj)->n);
}

void LLShowRCV(const node **obj)
{
    ShowRCV(obj);
    printf("nullptr\n");
}

void LLFree(node *obj)
{
    if (NULL == obj)
    {
        return;
    }
    LLFree(obj->n);
    free(obj);
}

node *LLMergeTwoSorted(const node *obj1, const node *obj2)
{
    if (NULL == obj1 && NULL == obj2)
    {
        return NULL;
    }
    node *resp = (node*)malloc(sizeof(node));
    if (NULL == obj1)
    {
        resp->v = obj2->v;
        resp->n = LLMergeTwoSorted(NULL, obj2->n);
    }
    if (NULL == obj2)
    {
        resp->v = obj1->v;
        resp->n = LLMergeTwoSorted(obj1->n, NULL);
    }
    if (NULL != obj1 && NULL != obj2)
    {
        if (obj1->v <= obj2->v)
        {
            resp->v = obj1->v;
            resp->n = LLMergeTwoSorted(obj1->n, obj2);
        }
        else
        {
            resp->v = obj2->v;
            resp->n = LLMergeTwoSorted(obj1, obj2->n);
        }
    }
    return resp;
}

void ShowRCVAddr(const node **obj)
{
    if (NULL == *obj)
    {
        return;
    }
    printf("%p->", (*obj));
    ShowRCVAddr((const node**)&(*obj)->n);
}

void LLShowRCVAddr(const node **obj)
{
    ShowRCVAddr(obj);
    printf("nullptr\n");
}

void reverse(node** head)
{
    node* first;
    node* rest;

    // empty list base case
    if (*head == NULL) {
        return;
    }

    first = *head;          // suppose first = {1, 2, 3}
    rest = first->n;        // rest = {2, 3}

    // empty rest base case
    if (rest == NULL) {
        return;
    }

    reverse(&rest);         // recursively reverse the smaller {2, 3} case
                            // after: rest = {3, 2}

    printf("fnv %p: %d\n", first->n, first->n->v);
    printf("fv %p: %d\n", first, first->v);

    printf("fnn %p\n", first->n->n);

    first->n->n = first;    // put the first item at the end of the list
    first->n = NULL;        // (tricky step — make a drawing)
    *head = rest;           // fix the head pointer
}

typedef struct StackNode_t
{
    int data;
    struct StackNode_t *next;
} StackNode;

StackNode *CreatStack()
{
    return NULL;
}

void push(StackNode **obj, int data)
{
    StackNode *nn = (StackNode*)malloc(sizeof(StackNode));
    nn->data = data;
    nn->next = *obj;
    *obj = nn;
}

int pop(StackNode **obj)
{
    if (NULL == *obj)
    {
        return 0;
    }
    StackNode *d = *obj;
    int res = d->data;
    *obj = d->next;
    free(d);
    return res;
}

int peek(const StackNode *obj)
{
    return (NULL == obj) ? 0 : obj->data;
}

typedef struct qnode_t
{
    int key;
    struct qnode_t *next;
} qnode;

typedef struct queue_t
{
    qnode *rear, *front;
} queue;

queue *createQueue()
{
    queue *q = (queue*)malloc(sizeof(queue));
    q->rear = q->front = NULL;
    return q;
}

void enQueue(queue *q, int key)
{
    qnode *nn = (qnode*)malloc(sizeof(qnode));
    nn->key = key; nn->next = NULL;
    if (NULL == q->front)
    {
        q->front = q->rear = nn;
        return;
    }
    nn->next = q->rear->next;
    q->rear->next = nn;
    q->rear = nn;
}

void deQueue(queue *q)
{
    if (NULL == q->front)
    {
        return;
    }
    qnode *d = q->front;
    q->front = d->next;
    if (NULL == q->front)
    {
        q->rear = q->front = NULL;
    }
    free(d);
}

#define BUFFER_SIZE 10

void readData(unsigned *buffer, int size)
{
    for (int i = 0; i < size ; i++) {
        buffer[i] = i;
    }
}

void parse1(unsigned **buffer_p, int size)
{
    for (int i = 0; i < size ; i++) {
        printf("processing with parser1: %d\n", *((*buffer_p)++));
    }
}

void parse2(unsigned **buffer_p, int size)
{
    for (int i = 0; i < size ; i++) {
        printf("processing with parser1: %d\n", *((*buffer_p)++));
    }
}

// int robotMaze(const int m, const int n)
// {
//     // (m + n - 2)(m + n - 3)...n/(m - 1)!
//     long res = 1;
//     for (int i = n, j = 1; j < m; ++i, ++j)
//     {
//         res = res * i / j;
//         printf("j: %d\n", j);
//         printf("res: %ld\n", res);
//     }
//     return res;
// }

// void hanoi(int n, char A, char B, char C) {
//     if(n == 1) {
//         printf("Move sheet from %c to %c\n", A, C);
//     }
//     else {
//         hanoi(n-1, A, C, B);
//         hanoi(1, A, B, C);
//         hanoi(n-1, B, A, C);
//     }
// }

// //先定义结点 哈希表 以及哈希表相关的基础函数
// struct MyNode{
//     int data;
//     struct MyNode* next;
// };

// struct HashTbl{
//     int TableSize;
//     struct MyNode** TheLists;
// };

// int NextPrime(int n)
// {
//     if(n%2==0) n++;
//     for(;;n+=2)
//     {
//         for(int i=3;i<=sqrt(n);i++)
//            if(n%i==0) goto out;
//         return n;
//         out:;
//     }
// }

// int Hash(int key,int TableSize)
// {
//     int ret=abs(key)%TableSize;
//     return ret;
// }

// struct HashTbl* InitializeHashTbl(int TableSize)
// {
//     struct HashTbl* H=(struct HashTbl*)malloc(sizeof(struct HashTbl));
//     H->TableSize=NextPrime(TableSize);
//     H->TheLists=malloc(sizeof(struct MyNode*)*H->TableSize);
//     for(int i=0;i<H->TableSize;i++)
//     {
//         H->TheLists[i]=malloc(sizeof(struct MyNode));
//         H->TheLists[i]->next=NULL;
//         H->TheLists[i]->data=-1;
//     }
//     return H;
// }

// struct MyNode* Find(int key,struct HashTbl* H)
// {
//     struct MyNode* p,*l;
//     l=H->TheLists[Hash(key,H->TableSize)];
//     p=l->next;
//     while(p!=NULL&&p->data!=key)
//        p=p->next;
//     return p;
// }

// void Insert(int key,struct HashTbl* H)
// {
//     struct MyNode* Pos,*l;
//     Pos=Find(key,H);
//     if(Pos==NULL)
//     {
//         struct MyNode* NewCell=(struct MyNode*)malloc(sizeof(struct MyNode));
//         l=H->TheLists[Hash(key,H->TableSize)];
//         NewCell->next=l->next;
//         l->next=NewCell;
//         NewCell->data=key;
//     }
// }

// void FreeHashTbl(struct HashTbl* H)
// {
//     struct MyNode* temp,*deleteNode;
//     for(int i=0;i<H->TableSize;i++)
//     {
//         temp=H->TheLists[i];
//         while(temp!=NULL)
//         {
//             deleteNode=temp;
//             temp=temp->next;
//             free(deleteNode);
//         }
//     }
//     free(H);
// }

// int longestConsecutive(int* nums, int numsSize){
//     int max=0;
//     struct HashTbl* HashForNums=InitializeHashTbl(numsSize);
//     for(int i=0;i<numsSize;i++)     //第一次遍历数组————把数组的值放到哈希表中(同时去重)
//     {
//         struct MyNode* findNode=Find(nums[i],HashForNums);
//         if(findNode==NULL) Insert(nums[i],HashForNums);
//     }
//     for(int i=0;i<numsSize;i++)     //第二次遍历数组————找长连续序列长度
//     {
//         if(nums[i]==-2147483647 || Find(nums[i]-1,HashForNums)==NULL)   //只有x-1不存在的时候再往后找(注意：前一项比较条件是确保类型为int的nums[i]在减一后不越界)
//         {
//             int curMax=0,temp=0;
//             while(Find(nums[i]+temp,HashForNums)!=NULL)
//             {
//                 curMax++;
//                 temp++;
//             }
//             max=fmax(curMax,max);
//         }
//     }
//     return max;
// }
int main(int argc, char const *argv[])
{
    /* A C program to demonstrate working of memmove */

    char str1[] = "Geeks";  // Array of size 100
    char str2[] = "Quiz";   // Array of size 5

    puts("str1 before memmove ");
    puts(str1);

    printf("length of '%s' = %lu\n", str1, sizeof(str1));
    printf("length of '%s' = %lu\n", str2, sizeof(str2));

    /* Copies contents of str2 to sr1 */
    my_memmove(str1, str2, sizeof(str2));

    puts("str1 after memmove ");
    puts(str1);

    // // string concat...
    printf("\n\nstring concat...\n");
    char string_1[16] = "hello, world";
    char string_2[16] = "";
    char string_3[16] = " first... ";

    my_strcat((void*)string_3, (void*)string_1);

    printf("string_3 is = %s\n", string_3);

    // string length...
    int len = 0;

    len = my_strlen(string_1);
    printf("string1 is '%s'.\n", string_1);
    printf("the length of string_1 is %d.\n", len);

    printf("%d\n", MIN(10, 11));

    printf("%d\n", my_sumofn(5));

    // realtek interview testing...
    // printf("realtek interview testing...\n");
    // char *aptr;
    // printf("0x%x\n", aptr);
    // printf("%d\n", *aptr);
    // aptr = (char*) malloc(sizeof(char));
    // *aptr = 100;

    // printf("%d\n", *aptr);

    char chr;
    printf("Type a word...\n");
    scanf("%c", &chr);
    printf("%c ASCII code %d\n", chr, chr);

    HGFEDCBA();

    char** IpArray;
    int ArraySize = 0;
    // char str[] = "22522511135";
    char str[] = "225225035";

    printf("Restore Start...\n");
    IpArray = restoreIpAddresses(str, &ArraySize);
    printf("Restore Done...\n");
    printf("%d\n", ArraySize);
    for(int i = 0; i < ArraySize; i++)
    {
        printf("%s\n", IpArray[i]);
    }

    for (int i = 0; i < FIBCOUNT; ++i)
    {
        printf("%d ", fib(i));
    }

    char stratoi[] = "89789";
    int val = my_Atoi(stratoi);
    printf("\n%d \n", val);

    printf("set integer to 256...\n");
    int numberofcount = countsetbits(256);
    printf("The number of set bits is %d\n", numberofcount);

    int size;
    node *objt = LLCreate();
    printf("size of integer: %lu\n", sizeof(int));
    printf("size of node: %lu\n", sizeof(node));

    node test;
    printf("test: %p\n", &test);
    printf("test.v: %p\n", &(test.v));
    printf("test.n: %p\n", &(test.n));

    LLaddTail(&objt, 0);
    LLaddTail(&objt, 1);
    LLaddTail(&objt, 2);
    LLaddTail(&objt, 3);

    size = LLLengthRCV(objt);
    printf("size = %d\n", size);

    LLShow((const node**)&objt);

    LLFree(objt);

    node *obj = LLCreate();

    LLaddHead(&obj, 1);
    LLaddTail(&obj, 3);
    LLaddIdx(&obj, 1, 2);
    LLaddHead(&obj, 5);
    LLaddIdx(&obj, 4, 4);

    // LLLengthIRV(obj, &size);
    size = LLLengthRCV(obj);
    printf("size = %d\n", size);
    LLShow((const node**)&obj);

    printf("Delete idx 0 target...\n");
    LLdelIdx(&obj, 0);

    // LLLengthIRV(obj, &size);
    size = LLLengthRCV(obj);
    printf("size = %d\n", size);
    LLShow((const node**)&obj);

    printf("Add over index with value 10...\n");
    LLaddIdx(&obj, 10, 10);
    LLShow((const node**)&obj);

    printf("Delete over index 10...\n");
    LLdelIdx(&obj, 10);

    size = LLLengthRCV(obj);
    for (int i = 0; i < size; ++i)
    {
        printf("%d->", LLGet((const node**)&obj, i));
    }
    printf("nullptr\n");

    LLFree(obj);

    printf("Merge Two Sorted Linked List...\n");

    node *obj1 = LLCreate();
    node *obj2 = LLCreate();

#define MERGE_TEST 5
    for (int i = 2; i < MERGE_TEST + 2; ++i)
    {
        LLaddTail(&obj1, 2 * i + 1);
    }

    for (int i = 0; i < MERGE_TEST * 2; ++i)
    {
        LLaddTail(&obj2, 2 * i);
    }

    LLShow((const node**)&obj1);
    LLShow((const node**)&obj2);

    node *obj3 = LLMergeTwoSorted(obj1, obj2);
    printf("obj1:\n");
    LLShow((const node**)&obj1);
    printf("obj2:\n");
    LLShow((const node**)&obj2);
    printf("obj3:\n");
    LLShow((const node**)&obj3);
    LLShowRCV((const node**)&obj3);
    printf("\n");
    size = LLLengthRCV(obj3);
    for (int i = 0; i < size; ++i)
    {
        printf("%d->", LLGet((const node**)&obj3, i));
    }
    printf("nullptr\n");

// https://www.techiedelight.com/reverse-linked-list-part-2-recursive-solution/
    printf("Reverse the Linked List\n");
    LLShowRCVAddr((const node**)&obj3);
    reverse(&obj3);
    LLShowRCV((const node**)&obj3);

    LLFree(obj1);
    LLFree(obj2);
    LLFree(obj3);


// Stack - https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
// https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/
// https://www.studytonight.com/data-structures/stack-using-linked-list
// https://www.tutorialspoint.com/cplusplus-program-to-implement-stack-using-linked-list
    StackNode *root = CreatStack();
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    printf("%d popped from stack\n", pop(&root));
    printf("Top element is %d\n", peek(root));

// Queue - https://www.geeksforgeeks.org/queue-linked-list-implementation/
// https://www.geeksforgeeks.org/queue-data-structure/
    queue* q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    deQueue(q);
    printf("Queue Front : %d \n", q->front->key);
    // printf("Queue Front : %d \n", q->front->next->key);
    // printf("Queue Front : %d \n", q->front->next->next->key);
    // printf("Queue Front : %d \n", q->front->next->next->next->key);
    printf("Queue Rear : %d\n", q->rear->key);

//     // LeetCode 62
//     int mMaze = 3, nMaze = 7;
//     int resMazeNum = robotMaze(mMaze, nMaze);
//     printf("the result of Maze is %d\n", resMazeNum);

// https://followtutorials.com/2013/03/sobel-and-prewitt-edge-detector-in-c-image-processing.html
// https://www.ciaranmccann.me/first-person-shooter-c-opengl/
// https://www.ciaranmccann.me/first-person-shooter-c-opengl/
// https://github.com/CiaranMcCann/Wator-Simulation

// https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html

// https://beginnersbook.com/2014/01/c-pointer-to-pointer/
    int num = 123;

    //A normal pointer pr2
    int *pr2;

    //This pointer pr2 is a double pointer
    int **pr1;

    /* Assigning the address of variable num to the
    * pointer pr2
    */
    pr2 = &num;

    /* Assigning the address of pointer pr2 to the
    * pointer-to-pointer pr1
    */
    pr1 = &pr2;

    /* Possible ways to find value of variable num*/
    printf("\nValue of num is: %d", num);
    printf("\nValue of num using pr2 is: %d", *pr2);
    printf("\nValue of num using pr1 is: %d", **pr1);

    /*Possible ways to find address of num*/
    printf("\nAddress of num is: %p", &num);
    printf("\nAddress of num using pr2 is: %p", pr2);
    printf("\nAddress of num using pr1 is: %p", *pr1);

    /*Find value of pointer*/
    printf("\nValue of Pointer pr2 is: %p", pr2);
    printf("\nValue of Pointer pr2 using pr1 is: %p", *pr1);

    /*Ways to find address of pointer*/
    printf("\nAddress of Pointer pr2 is:%p",&pr2);
    printf("\nAddress of Pointer pr2 using pr1 is:%p",pr1);

    /*Double pointer value and address*/
    printf("\nValue of Pointer pr1 is:%p",pr1);
    printf("\nAddress of Pointer pr1 is:%p\n",&pr1);

// https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/cyu-yan-shi-xian-ha-xi-biao-by-nuclear-30-2/
//     int numarray[6] = {100, 4, 200, 1, 3, 2};
//     printf("sizeof array: %d\n", (int)(sizeof(numarray)/sizeof(int)));
//     int longestlen = 0;
//     longestlen = longestConsecutive((int*)&numarray, (int)(sizeof(numarray)/sizeof(int)));
//     printf("longest length: %d\n", longestlen);
    // int nFloor;
    // printf("請輸入盤數：");
    // scanf("%d", &nFloor);
    // hanoi(nFloor, 'A', 'B', 'C');

//     char *kmpstr = "bacbababadababacambabacaddababacasdsd";
//     char *kmpptr = "ababaca";
//     int aSize = 0;
//     printf("kmpstr: %s\n", kmpstr);
//     printf("kmpptr: %s\n", kmpptr);
//     int *a = myKMP(kmpstr, kmpptr, &aSize);
//     printf("size of kmp ans: %d\n", aSize);
//     for (int i = 0; i < aSize; ++i)
//     {
//         printf("%d\n", a[i]);
//     }

// https://www.cnblogs.com/oomusou/archive/2008/01/06/1027502.html
    int s = 0;
    printf("Number of core : %d\n", omp_get_num_procs());
    printf("Number of threads : %d\n", omp_get_num_threads());
    #pragma omp parallel for

    for(int i = 0; i <= 100; ++i)
    {
        printf("thread %d : %d\n", omp_get_thread_num(), s = s + i);
    }
    printf("res: %d\n", s);

    unsigned long ival = 10;
    printf("ival = %ld\n", ival);                   //ival = 10
    printf("sizeof ival: %lu\n", sizeof(ival));     //sizeof ival: 8
    // int **p = (int**)malloc(sizeof(int*));
    int **p;
    int *ptr;

    printf("p: %p\n", p);                           //p: (nil)
    printf("ptr: %p\n", ptr);                       //ptr: (nil)
    ival = (unsigned long) ptr;
    printf("ival = %ld\n", ival);                   //ival = 0
    // ival = (unsigned long) *p;
    p = &ival;
    printf("*p: %p\n", *p);
    // printf("sizeof p pointer: %lu\n", sizeof(p));
    // ival = (unsigned long) *p;
    // printf("ival = %ld\n", ival);

    unsigned buffer[BUFFER_SIZE];
    unsigned *bufferptr = buffer;
    readData(buffer, BUFFER_SIZE);
    parse1(&bufferptr,BUFFER_SIZE/2);
    parse2(&bufferptr,BUFFER_SIZE/2);

    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int (*aPtr)[10] = &a;
    int *aptr = a;
    printf("size of int   = %ld\n", sizeof(int));
    printf("aPtr addr     = 0x%p\n", aPtr);
    printf("aPtr addr + 1 = 0x%p\n", (aPtr + 1));
    printf("aptr addr     = 0x%p\n", aptr);
    printf("aptr addr + 1 = 0x%p\n", (aptr + 1));
    printf("a addr        = 0x%p\n", a);
    printf("a addr + 1    = 0x%p\n", (a + 1));

    printf("\n.....Done.....\n");

    return 0;
}