#include <stdio.h>
int main()
{
    char a;
    printf("Please input a character:");
    //&a 表示取a变量的地址，a&b表示a，b两个整数按位与，a&&b表示a，b逻辑与。
    scanf("%c",&a);
    if (a<32)
        printf("this is a control character\n");
    else if (a>='0' && a<='9')
        printf("this is a digital\n");
    else if (a>='A' && a<='Z')
        printf("this is a capital letter\n");
    else if (a>='a' && a<='z')
        printf("this is a lowercase\n");
    else {
        printf("this is an other character\n");
    }

    // 作业：将上述分支判断用switch语句实现！！！
    // case后只可以跟精确值或者范围，浮点数无法switch
    switch (a) {
        case 0 ... 31: 
            printf("a<32\n");
            printf("this is a control character\n");
            break;
        case '0' ... '9':
            printf("a>='0' && a<='9'\n");
            printf("this is a digital\n");
            break;
        case 'A' ... 'Z': 
            printf("a>='A' && a<='Z'\n");
            printf("this is a capital letter\n");
            break;
        case 'a' ... 'z': 
            printf("a>='a' && a<='z'\n");
            printf("this is a lowercase\n");
            break;
        default:
            printf("this is an other character\n");
    }

    if (!((a>='0' && a<='9') || (a>='a' && a<='z') || (a>='A' && a<='Z')))
        printf("This is not a password letter\n");
    else 
        printf("THIS IS A PASSWORD LETTER\n");
    
    if (a=='w')printf("This is w\n");
    printf("Please input a number:");
    int b;
    scanf("%d",&b);
    if (b%2)
        printf("b is an odd number\n");
    else
        printf("b is an even number\n");

    printf("hahaha, b is an %s number\n", b%2 ? "odd" : "even");
    switch (b) {
        case 1: printf("b==1\n");break;
        case 2: printf("b==2\n");break;
        case 3: 
            printf("b==3\n");
            printf("hahahaha....3\n");break;
        case 4: printf("b==4\n");break;
        case 5: printf("b==5\n");break;
        case 6: printf("b==6\n");break;
        case 7: printf("b==7\n");break;
        case 8 ... 20: printf("b is 8-20\n");//break;
        default:printf("b is not 1-7\n");
    }
}