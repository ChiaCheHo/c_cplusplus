#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define UNDERFLOW -2
typedef int Status;
//-----栈开始-----

typedef struct
{ //迷宫中r行c列的位置
    int r;
    int c;
} PostType; //坐标位置类型
typedef struct
{
    int ord;       // 当前位置在路径上的序号
    PostType seat; // 当前坐标
    int di;        // 从此通块走向下一通块的"方向"
} SElemType;       // 栈的元素类型

//定义链式栈的存储结构
struct LNode
{
    SElemType data;     //数据域
    struct LNode *next; //指针域
};
struct LStack
{
    struct LNode *top; //栈顶指针
};
Status InitStack(LStack &s) //操作结果：构造一个空栈S
{
    struct LNode *p;
    p = (LNode *)malloc(sizeof(LNode));
    if (!p)
    {
        printf("分配失败，退出程序");
        exit(ERROR);
    }
    s.top = p;
    p->next = NULL;
    return OK;
}
Status StackEmpty(LStack s)
//若栈s为空栈，则返回TRUE，否则FALSE
{
    if (s.top->next == NULL)
        return TRUE;
    return FALSE;
}
Status Push(LStack &s, SElemType e) //插入元素e成为新的栈顶元素
{
    struct LNode *p;
    p = (LNode *)malloc(sizeof(LNode));
    if (!p)
        exit(OVERFLOW);
    s.top->data = e;
    p->next = s.top;
    s.top = p;
    return OK;
}
Status Pop(LStack &s, SElemType &e) //删除s的栈顶元素，并且用e返回其值
{
    struct LNode *p;
    if (!(s.top->next))
        exit(UNDERFLOW);
    p = s.top;
    s.top = p->next;
    e = s.top->data;
    free(p);
    return OK;
}
Status DestroyStack(LStack &s) //操作结果：栈s被销毁
{
    struct LNode *p;
    p = s.top;
    while (p)
    {
        s.top = p->next;
        free(p);
        p = s.top;
    }
    return OK;
}
//-----栈结束------

//-----迷宫开始-------
#define MAXLEN 10 // 迷宫包括外墙最大行列数
typedef struct
{
    int r;
    int c;
    char adr[MAXLEN][MAXLEN]; // 可取' ''*' '@' '#'
} MazeType;                   // 迷宫类型
Status InitMaze(MazeType &maze)
{
    // 初始化迷宫，成功返回TRUE，否则返回FALSE
    int m, n, i, j;
    printf("输入迷宫行数和列数（包括了外墙）: ");
    scanf("%d%d", &maze.r, &maze.c); // 输入迷宫行数和列数
    for (i = 0; i <= maze.c + 1; i++)
    { // 迷宫行外墙
        maze.adr[0][i] = '#';
        maze.adr[maze.r + 1][i] = '#';
    } // for
    for (i = 0; i <= maze.r + 1; i++)
    { // 迷宫列外墙
        maze.adr[i][0] = '#';
        maze.adr[i][maze.c + 1] = '#';
    }
    for (i = 1; i <= maze.r; i++)
        for (j = 1; j <= maze.c; j++)
            maze.adr[i][j] = ' '; // 初始化迷宫
    printf("输入障碍的坐标((-1 -1)结束): ");
    scanf("%d%d", &m, &n); // 接收障碍的坐标
    while (m != -1)
    {
        if (m > maze.r || n > maze.c) // 越界
            exit(ERROR);
        maze.adr[m][n] = '#'; // 迷宫障碍用#标记
        printf("输入障碍的坐标((-1,-1)结束): ");
        scanf("%d%d", &m, &n);
    } // while
    return OK;
} // InitMaze

Status Pass(MazeType maze, PostType curpos)
{ // 当前位置可同则返回TURE,否则返回FALSE
    if (maze.adr[curpos.r]
                [curpos.c] == ' ') // 可通
        return TRUE;
    else
        return FALSE;
} // Pass

Status FootPrint(MazeType &maze, PostType curpos)
{ // 若走过并且可通，则返回TRUE,否则返回FALSE
    maze.adr[curpos.r]
            [curpos.c] = '*'; //"*"表示可通
    return OK;
} // FootPrint
PostType NextPos(PostType &curpos, int i)
{ // 指示并返回下一位置的坐标
    PostType cpos;
    cpos = curpos;
    switch (i)
    { // 1.2.3.4 分别表示东南西北方向
    case 1:
        cpos.c += 1;
        break;
    case 2:
        cpos.r += 1;
        break;
    case 3:
        cpos.c -= 1;
        break;
    case 4:
        cpos.r -= 1;
        break;
    default:
        exit(ERROR);
    }
    return cpos;
} // Nextpos
Status MarkPrint(MazeType &maze, PostType curpos)
{                                       // 曾走过，但不是通路标记，并返回OK
    maze.adr[curpos.r][curpos.c] = '@'; //"@" 表示曾走过但不通
    return OK;
} // MarkPrint

Status MazePath(MazeType &maze, PostType start, PostType end)
{ // 若迷宫maze存在通路，则求出一条同路放在栈中，并返回TRUE，否则返回FALSE
    struct LStack S;
    PostType curpos;
    int curstep; // 当前序号，1,2,3,4分别表示东南西北方向
    SElemType e;
    InitStack(S);
    curpos = start; //设置"当前位置"为"入口位置"
    curstep = 1;    // 探索第一位
    printf("以三元组形式表示迷宫路径：\n");
    do
    {
        if (Pass(maze, curpos))
        {                            // 当前位置可以通过
            FootPrint(maze, curpos); // 留下足迹
            e.ord = curstep;
            e.seat = curpos;
            e.di = 1;
            printf("%d %d %d-->", e.seat.r, e.seat.c, e.di);
            Push(S, e); // 加入路径
            if (curpos.r == end.r && curpos.c == end.c)
                if (!DestroyStack(S)) // 销毁失败
                    exit(OVERFLOW);
                else
                    return TRUE; // 到达出口
            else
            {
                curpos = NextPos(curpos, 1);
                // 下一位置是当前位置的东邻
                curstep++; // 探索下一步
            }              // else
        }                  // if
        else
        { // 当前位置不通时
            if (!StackEmpty(S))
            {
                Pop(S, e);
                while (e.di == 4 && !StackEmpty(S))
                {
                    MarkPrint(maze, e.seat);
                    Pop(S, e);
                    // 留下不能通过的标记，并退一步
                } // while
                if (e.di < 4)
                {
                    e.di++; // 换一个方向探索
                    Push(S, e);
                    curpos = NextPos(e.seat, e.di); // 设定当前位置是该方向上的相邻
                    printf("%d %d %d-->", e.seat.r, e.seat.c, e.di);
                } // if
            }     // if
        }         // else
    } while (!StackEmpty(S));
    if (!DestroyStack(S)) // 销毁栈
        exit(OVERFLOW);
    else
        return FALSE;
} // MazePath

void PrintMaze(MazeType &maze)
{ // 将标记路径信息的迷宫输出到终端
    int i, j;
    printf("\n输出迷宫(*表示通路):\n\n");
    printf(" ");
    for (i = 0; i <= maze.r + 1; i++) // 打印列数名
        printf("%4d", i);
    printf("\n\n");
    for (i = 0; i <= maze.r + 1; i++)
    {
        printf("%2d", i); // 打印行名
        for (j = 0; j <= maze.c + 1; j++)
            printf("%4c", maze.adr[i][j]); // 输出迷宫当前位置的标记
        printf("\n\n");
    }
} // PrintMaze

int main()
{ // 主函数
    MazeType maze;
    PostType start, end;
    char cmd;
    do
    {
        printf("-------创建迷宫--------\n");
        if (!InitMaze(maze))
        {
            printf("Initialization errors!!!\n");
            exit(OVERFLOW); // 初始化失败
        }
        do
        { // 输入迷宫入口坐标
            printf("\n输入迷宫入口坐标: ");
            scanf("%d%d", &start.r, &start.c);
            if (start.r > maze.r || start.c > maze.c)
            {
                printf("\nBeyond the maze!!!\n");
                continue;
            }
        } while (start.r > maze.r || start.c > maze.c);

        do
        { // 输入迷宫出口坐标
            printf("\n输入迷宫出口坐标: ");
            scanf("%d%d", &end.r, &end.c);
            if (end.r > maze.r || end.c > maze.c)
            {
                printf("\nBeyond the maze!!!\n");
                continue;
            }
        } while (end.r > maze.r || end.c > maze.c);
        if (!MazePath(maze, start, end)) //迷宫求解
            printf("\nNo path from entranceto exit!\n");
        else
            PrintMaze(maze); // 打印路径
        printf("\n需要继续创建新的迷宫吗?(y/n): ");
        scanf("%s", &cmd);
    } while (cmd == 'y' || cmd == 'Y');
}