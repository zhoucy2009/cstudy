#include <stdio.h>
int main() {
    char carray[6] = {'h','e','l','l','o',0};
    printf("carray=%s\n", carray);
    printf("carray=%s\n", carray+1);
    for(int q = 0; q < 6; q++){
        if (carray[q] == 0) {
            printf("\n");
            break;
        }
        printf("%c",carray[q]);
        
    }
    unsigned long s = 0;
    printf("size of u =%lu size of ul=%lu size of ull=%lu\n", sizeof(unsigned), sizeof(unsigned long), sizeof(unsigned long long));

    for(int a = 1; a <= 100000; a++ ){
        s+=a;
        // printf("a=%d, s=%lld\n", a, s);
    }
    printf("sum=%ld\n",s);

    unsigned char a = 0, n;
    printf("input n:");
    scanf("%d",(int *)&n);
    while (n++) {
        printf("%d\n",a*2);
        a = a + 1;
    }

    printf("input n:");
    scanf("%d",(int *)&n);
    do {
        printf("%d\n",a*2);
        a = a + 1;
    } while (--n); 
    printf("n=%d\n",n);

    for(int i = 0; i <= 10; i++) {
        if(i == 5) continue;
        printf("i=%d\n",i);
    }

    for(int i = 0; i < 10; i++, printf("%d", i));
}