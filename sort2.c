#include <stdio.h>
#define MAXINT 100

// 要求：实现两个函数以满足排序要求

// 输入数组，返回小于less_than的最大值以及个数
// 通过指针*max返回最大值
// 通过指针*count返回最大值的个数
// 例如：调用get_max_and_count(in, MAXINT, &m, &c), m为88，c为2
int swap_max(int a[10], int start);

// 循环调用get_max_and_count找出最大值放入b数组
// 直到填满b数组
void sort(int a[10]);

int main()
{
    int in[10] = {2, 5, 5, 18, 32, 60, 70, 88, 88, 5};

    // 调用sort后，out应该是：
    // 88 88 70 60 32 18 5 5 5 2
    sort(in);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", in[i]);
    }
    printf("\n");

    return 0;
}
void swap(int a[10], int ia, int ib)
{
    int temp = 0;
    temp = a[ia];
    a[ia] = a[ib];
    a[ib] = temp;
}

int swap_max(int a[10], int start)
{
    int count = 0;
    int max = 0;
    for (int i = start; i < 10; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            count = 1;
        }
        else if (a[i] == max)
        {
            count += 1;
        }
    }
    for (int i = start; i < 10; i++)
    {
        if (a[i] == max)
        {
            swap(a, i, start++);
        }
    }
    return count;
}

void sort(int a[10])
{
    int start = 0;
    int time = 1;
    while (1)
    {
        start += swap_max(a, start);
        if (start == 10)
            break;
        printf("pass%d:", time);
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        time += 1;
    }
}