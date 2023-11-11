#include <stdio.h>
#define MAXINT 100
void bucket_sort(int *in, int *out, int slen)
{   
    int outidx = 0;
    int bucket[MAXINT + 1];
    for (int i = 0; i < MAXINT + 1; i++)
    {
        bucket[i] = 0;
    }
    for (int i = 0; i < slen; i++)
    {
        bucket[in[i]]++;
    }
    for (int i = 0; i < MAXINT + 1; i++)
    {
        if (bucket[i] == 0)
            continue;
        //printf("%d:%d\n", i,bucket[i]);
        for (int j = 0; j < bucket[i]; j++)
        {
            out[outidx++] = i;
        }
    }
}
int main(){
    int score[13] = {98, 100, 76, 0, 0, 88, 92, 45, 60, 100, 88, 88, 88};
    int out[13];
    bucket_sort(score, out, 13);
    for (int i=0; i<13; i++){
        printf("%d ",out[i]);
    }
    printf("\n");
}
