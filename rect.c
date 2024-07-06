#include <stdio.h>
#include <stdlib.h>
int cauculate(char *height, int len)
{
    int sle;
    int area;
    int max = 0;
    int ele;
    int length = 0;
    for (int i = 0; i < len; i++)
    {
        int h = height[i];
        for (int j = i; j >= 0; j--)
        {
            if (height[j] >= h) {
                sle = j;
            } else {
                break;
            }
        }
        for (int k = i; k < len; k++)
        {
            if (height[k] >= h) {
                ele = k;
            } else {
                break;
            }
        }
        

        // for (int j = i; j >= 0; j--)
        // {
        //     if (height[j] < height[i])
        //     {
        //         sle = j + 1;
        //         break;
        //     }
        //     if(j == 0){
        //         sle = j;
        //     }
        // }
        // for (int k = i; k < len; k++)
        // {
        //     if (height[k] < height[i])
        //     {
        //         ele = k - 1;
        //         break;
        //     }
        //     if (len - 1 == k){
        //         ele = k;
        //     }
        // }
        area = height[i] * (ele - sle + 1);
        if (area > max)
        {
            max = area;
        }
       printf("height:%d,start:%d,end:%d,area:%d\n",height[i],sle,ele,area);
    }
    return max;
}
int main()
{
    char height[9] = {2, 4, 5, 3, 4, 6, 5, 2, 4};
    cauculate(height, 9);
}