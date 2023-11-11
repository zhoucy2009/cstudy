#include <stdio.h>
#include <ctype.h> 
int main(){
    int move = 18;
    char a;
    int m;
    printf("Enter the alphebet you want to discode:");
    scanf("%c",&a);
    printf("Enter how many········································ places you want to move:");
    scanf("%d",&m);
    if (isalpha(a))
    {
        int aftmv = (a-'a'+ m)%26 +'a';
        printf("%c\n",aftmv);
    }
}