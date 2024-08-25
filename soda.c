#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int calculate(int a)
{
    int empty = 0;
    int drunken = 0;
    for (int i = a; i > 0; i--)
    {
        drunken += 1;
        empty += 1;
        printf("I have %d sodas\n", i);
        printf("I drink %d sodas\n", drunken);
        printf("I have %d empties\n", empty);
        if (empty == 2)
        {
            empty = 0;
            i += 1;
        }
        else
        {
            continue;
        }
    }
    return drunken;
}
int main()
{
    int a = 7;
    int n = 0;
    n = calculate(a);
    printf("number drunken is:%d\n", n);
}