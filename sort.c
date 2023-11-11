#include <stdio.h>
#define MAXINT 100

// 要求：实现两个函数以满足排序要求

// 输入数组，返回小于less_than的最大值以及个数
// 通过指针*max返回最大值
// 通过指针*count返回最大值的个数
// 例如：调用get_max_and_count(in, MAXINT, &m, &c), m为88，c为2
void get_max_and_count(int a[10], int less_than, int *max, int *count);

// 循环调用get_max_and_count找出最大值放入b数组
// 直到填满b数组
void sort(int a[10], int b[10]);

int main()
{
    int in[10] = {2, 5, 5, 18, 32, 60, 70, 88, 88, 5};
    int out[10];

    // 调用sort后，out应该是：
    // 88 88 70 60 32 18 5 5 5 2
    sort(in, out);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", out[i]);
    }
    printf("\n");

    return 0;
}

void get_max_and_count(int a[10], int less_than, int *max, int *count)
{

    *count = 0;
    *max = 0;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] >= less_than)
        {
            continue;
        }
        if (a[i] > *max)
        {
            *max = a[i]; // 默认数组中第一个元素为最大，一旦有比第一个大的，刷新最大
            *count = 1;
        }
        else if (a[i] == *max)
        {
            *count += 1;
        }
    }
}

void sort(int a[10], int b[10])
{
    int f = 0;
    int less_than = MAXINT;
    int max;
    int count;
    while (1)
    {
        get_max_and_count(a, less_than, &max, &count);
        printf("after gm max = %d, count = %d\n", max, count);
        for (int i = 0; i < count; i++)
        {
            b[f++] = max;
        }
        if (f == 10)
        {
            break;
        }
        less_than = max;
    }
}