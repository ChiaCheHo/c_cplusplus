// https://www.knowprogram.com/c-programming/pyramid-star-pattern-c/
#include <stdio.h>

#include <stdio.h>
void fullPyramid(int r)
{
    int c, space;
    static int stars = -1;

    if (r <= 0)
        return;

    space = r - 1;
    stars += 2;

    for (c = 0; c < space; c++)
        printf(" "); // space

    for (c = 0; c < stars; c++)
        printf("*"); // star

    printf("\n");

    fullPyramid(--r);
}

void myStarPattern()
{
    int num = 0;
    printf("Type a number...\n");
    scanf("%d", &num);
    for (int i = 0; i < num; ++i)
    {
        for (int j = 0; j < (num - (i + 1)) + (i * 2 + 1); ++j)
        {
            if (j < ((num - i) - 1))
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    fullPyramid(n);

    myStarPattern();
    return 0;
}