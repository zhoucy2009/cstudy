#include <stdio.h>
void swap(int a, int b){
    printf("addra=%p addrb=%p a=%d b=%d\n", &a, &b, a, b);
    int tmp = a;
    a = b;
    b = tmp;   
}

void swap2(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;   
}
int sum(int a, int b);
void op4(int a, int b, int r[4]);
int op_add_divide(int a, int b, float *r);
double factorial(double n);
int main(){
    int x = 1;
    int y = 2;
    int s1 = 0;
    // printf("addrx=%p addry=%p x=%d y=%d\n", &x, &y, x, y);
    // swap(x, y);
    // printf("after swap %d %d\n",x,y);
    // swap2(&x, &y);
    // printf("after swap2 %d %d\n",x,y);
    s1 = sum(x,y);
    printf("sum of x and y %d\n",s1);
    int re[4];
    op4(x,y,re);
    printf("operation 4 %d %d %d %d\n",re[0],re[1],re[2],re[3]);
    float a;
    int aa = op_add_divide(x,y,&a);
    printf("x/y in float=%.1f %d\n",a,aa);
    double n = 0;
    scanf("%lf",&n);
    double fac = factorial(n);
    printf("factorial of %lf: %.9e\n",n,fac);

}

int sum(int a, int b){
    int s = a + b;
    return s;
}

//用数组参数返回多个同类型的值
void op4(int a, int b, int r[4]){
    r[0] = a + b;
    r[1] = a - b;
    r[2] = a * b;
    r[3] = a / b;
}

//用函数返回值返回和，用指针返回商
int op_add_divide(int a, int b, float *r){
    *r = (float)a / (float)b;
    return a + b;
}

double factorial(double n){
    if(n <= 1) return 1;
    return factorial(n-1) * n;
}