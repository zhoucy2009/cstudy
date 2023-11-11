#include <stdio.h>
#include <string.h>
int main(){
    int n = 10;
    int a[n];
    for(int i=0; i<10; i++){
        a[i] = i+1;
    }
    int *p = a;
    printf("%d,%d\n",a[0],*(p+1));
    int b[2][2] = {1,2,3,4};
    int c[2][2];
    int *p2 = (int *)b;
    printf("%d,%d\n",b[1][0],*(p2+2));
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            scanf("%d",&c[i][j]);
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    char s[20] = {'h','e','l','l','o',0};
    printf("%s %d\n",s,s[19]);
    char s2[] = {"hello"};
    printf("%s\n",strcat(s,s2));
    char s3[20];
    printf("%d\n",s3[19]);


}