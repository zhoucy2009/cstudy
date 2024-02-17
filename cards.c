#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    char cards[52];
    for (int c = 1; c <= 52; c++)
    {
        cards[c - 1] = c;
    }
    char dest_cards[52];
    srand(time(NULL));
    int count = 0;
    int invalid = 0;
    while (1)
    {
        int move = rand() % 52;
        if (cards[move] != 0)
        {
            dest_cards[count] = cards[move];
            cards[move] = 0;
            printf("%d ", dest_cards[count]);
            count++;
        }
        else
        {
            invalid++;
        }
        if (count == 52)
            break;
    }
    printf("\ninvalid=%d\n", invalid);

    //shuffle
    int pick = 52;
    char cards2[52];
    for (int c = 1; c <= 52; c++)
    {
        cards2[c - 1] = c;
    }
    srand(time(NULL));
    while (1)
    {
        // 记不清优先级要加括弧
        // ERROR: int swap = rand() % pick - 1;
        int swap = rand() % (pick - 1);
        if ((pick - 1) > 1)
        {
            /*int tmp = cards2[swap];
            cards2[swap] = cards2[pick - 1];
            cards2[pick - 1] = tmp;*/
            // 下节课讲什么时候交换两个值需要指针（地址）
            //  ERROR: char *a = &cards2[pick]; 会越界
            char *a = &cards2[pick - 1];
            char *b = &cards2[swap];
            char tmp = *a;
            *a = *b;
            *b = tmp;
            // 没有赋值不起作用
            // ERROR：pick - 1;
            pick -= 1;
        }
        else
        {
            break;
        }
        // ERROR：按%s打印这些值都是不可见字符或乱码，而且%s一定要用0结尾，找不到0会一直打印
        // printf("%s",cards2);
    }
    for (int i = 0; i < 52; i++)
    {
        printf("%d ", cards2[i]);
    }
    printf("\n");
}