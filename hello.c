#include <stdio.h>
#include <string.h>

int max(int a, int b);
void encoding(char *src, char *key, char *dst);

int main(){
    /*int x,y, z_1;
    printf("Hello,world!\n");
    printf("test input z:");
    scanf("%d", &z_1);
    printf("z is %d\n", z_1);

    printf("address of x is: %p,address of y is: %p, address of z is: %p\n", &x, &y, &z_1);

    printf("Please give two numbers:");
    scanf("%d %d",&x,&y);
    printf("x is %d, y is %d\n", x, y);

    z_1=max(x,y);
    printf("the larger number is:%d\n", z_1);*/

    // 测试signed short的二进制表示
    // 知识点1: %hX打印short才能正确打印出2字节，%X会先转成4字节整数再打印就不准确了
    // 知识点2: 负数用补码表示，方便只用加法电路来做加减法，取反加一
    // 知识点3: -32768是short的最小值，对应二进制1000000000000000
    short test = -32768, test2 = -32767;
    short sum = test + test2;
    int pret = printf("sizeof short = %lu\n", sizeof(short));
    printf("return value = %d\n",pret);
    printf("test=%hX test2=%hX\n",test,test2);
    char c = 'A';
    printf("charc = %d\n",c);
    char d = c++;
    printf("chard = %c\n",d);

    c = 5;
    printf("bt = %d\n",c++ + ++c);

    // 字符串变量，本质是一个指向字符型的指针
    // 字符串常量可以表示一个以0结尾的字符串
    // 字符串变量赋值为一个字符串常量，本质是将字符串常量首地址赋予字符串变量
    // s + 7 表示指针向后跳过了7个字符，打出“grade ..."
    char *s = "Effort grade is 0 out of 7.", *p;
    printf("wdw=%s\n",s);
    printf("skip7=%s\n", s + 7);

    // 同样的数据，赋给一个整数指针
    int *pi = s;
    // 打印地址和首地址指向的字符内容
    printf("address of s = %p, content of address s = %c\n", s, *s);
    // 打印相同的地址，以及首地址取出的四个字节数据代表的整数，也就是Effo这头四个字母的数据表示的整数
    printf("address of i = %p, content of address s = %d\n", pi, *pi);
    // 打印头四个字母代表的整数，和后面四个字母rt g表示的整数
    // 注意整数指针加一，内存向后跳了sizeof(int)=4个字节
    // 如果是long *p加一，后跳8个字节
    // https://www.baeldung.com/cs/big-endian-vs-little-endian 这台电脑的芯片apple m1，是little endians
    printf("char2int:%d %d\n", *pi, *(pi+1));
    
    p = s;
    while (1) {
        printf("%c %d\n", *p, *p);
        p++;
        if (*p == 0) {
            printf("TAIL = %d\n", *p);
            break;
        }
    }

    p = s;
    do {
        printf("%c %d\n", *p, *p);
    } while(*p++);
    printf("index of 1000.0 = %e \n", 1000.0);
    printf("index of 0.001 = %e \n", 0.001);
    int i = 1, j = 100, k = 3;
    printf("%d\n",1<j<1);

    char *s1 = "ABCDEFGHIJKLMNOP";
    char *key = "HELLO";
    char dst[64], dst2[64];
    encoding(s1, key, dst);
    printf("dst1=%s\n", dst);
    encoding(dst, key, dst2);
    printf("dst2=%s\n", dst2);
                 
}
 
int max(int a, int b) {
    if(a>b)
        return a;
    else
        return b;
}

void encoding(char *src, char *key, char *dst) {
    int i = 0;
    int keylen = strlen(key);
    while(1) {
        if (src[i] != 0) {
            dst[i] = src[i] ^ key[i % keylen];
            printf("111...i=%d", dst[i]);
        } else {
            printf("222...i=%d\n", i);
            dst[i] = 0;
            break;
        }
        i++;
    }
}