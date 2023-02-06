#include <stdio.h>
#define NUMBER B85800 // this can be defined in the command line

#define VAL(str) #str
#define TOSTRING(str) VAL(str)

unsigned char part1[10] = TOSTRING(NUMBER); // generates "B85800"
unsigned char part2[10] = VAL(NUMBER);      // generates "NUMBER"

void my_print(unsigned char *s, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}

#define STR_VALUE(arg) #arg
#define FUNCTION_NAME(name) STR_VALUE(name)

#define TEST_FUNC test_func
#define TEST_FUNC_NAME FUNCTION_NAME(TEST_FUNC)

static void TEST_FUNC(void)
{
    printf("In function %s\n", TEST_FUNC_NAME);
}

int main()
{
    printf("Hello World\n");
    my_print(part1, 10);
    my_print(part2, 10);

    puts(TEST_FUNC_NAME);
    TEST_FUNC();

    return 0;
}
