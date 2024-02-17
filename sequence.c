#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shuffle(char cards2[52])
{
    int pick = 52;
    for (int c = 1; c <= 52; c++)
    {
        cards2[c - 1] = c;
    }
    srand(time(NULL));
    while (1)
    {
        int swap = rand() % (pick - 1);
        if ((pick - 1) >= 1)
        {

            char *a = &cards2[pick - 1];
            char *b = &cards2[swap];
            char tmp = *a;
            *a = *b;
            *b = tmp;
            pick -= 1;
        }
        else
        {
            break;
        }
    }
}
void split(char cards2[52], char scards[4][13])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            scards[i][j] = 0;
        }
    }
    for (int i = 0; i < 20; i++)
    {
        int c = (cards2[i] - 1) / 13;
        int n = cards2[i] - c * 13 - 1;
        scards[c][n] = 1;
    }
}
void print20(char cards2[52])
{
    char *color = "shcd";
    for (int i = 0; i < 20; i++)
    {
        int c = (cards2[i] - 1) / 13;
        int n = cards2[i] - c * 13;
        printf("%c%d ", color[c], n);
    }
}
void find_flush(char scards[4][13], char ret[4], char end[4])
{
    int count = 0;
    int max = 0;
    int e = 0;
    for (int i = 0; i < 4; i++)
    {
        count = 0;
        max = 0;
        e = 0;
        for (int j = 0; j < 13; j++)
        {
            if (scards[i][j] == 1)
            {
                count++;
            }
            if (scards[i][j] == 0 || j == 12)
            {
                if(count >= 3){
                    if(count>max){
                        max = count;
                        printf("max=%d\n",max);
                        e = j==12?j:j-1;
                    }
                    //printf("find a flush:%d\n",max);
                }
                count = 0;
            }
            printf("%d\n",count);
        }
        ret[i] = max;
        end[i] = e;
    }
}
int main()
{
    char cards2[52];
    shuffle(cards2);
    char bugy[20] = {26,51,33,48,21,23,52,37,30,12,20,4,39,50,35,36,40,25,24,49};
    for(int i = 0;i < 20; i++){
        cards2[i] = bugy[i];
    }
    print20(cards2);
    printf("\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d,", cards2[i]);
    }
    printf("\n");
    char scards[4][13];
    split(cards2, scards);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            printf("%d", scards[i][j]);
        }
        printf("\n");
    }
    char ret[4];
    char end[4];
    char *color = "shcd";
    find_flush(scards,ret,end);
    for (int i = 0; i < 4; i++)
    {
        printf("%c:", color[i]);
        if(ret[i]) {
            printf("len = %d...", ret[i]);
            for (int n=ret[i]; n>0; n--) {
                printf("%d ", end[i] - n + 2);
            }
            printf("\n");
        } else {
            printf("not found...\n");
        }
    }
}