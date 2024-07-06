#include <stdio.h>
#include <ctype.h>
/*
size empty push pop top
*/
typedef struct _stack_t
{
    int data[1024];
    int count;
} stack;

int size(stack *ps)
{
    // return (*ps).count;
    return ps->count;
}

int empty(stack *ps)
{
    return ps->count == 0;
}

int full(stack *ps)
{
    return ps->count == 1024;
}

int push(stack *ps, int n)
{
    if (ps->count >= 1024)
    {
        return -1;
    }
    ps->data[ps->count] = n;
    ps->count++;
    return 0;
}

int pop(stack *ps, int *n)
{
    // printf("n addr=%p val=%d\n",n,*n);
    if (empty(ps))
    {
        return -1;
    }
    ps->count--;
    *n = ps->data[ps->count];
    return 0;
}

int top(stack *ps, int *n)
{
    if (empty(ps))
    {
        return -1;
    }
    *n = ps->data[ps->count - 1];
    return 0;
}

void init(stack *ps)
{
    ps->count = 0;
}

char priority[128];

void priority_init()
{
    priority['+'] = 4;
    priority['-'] = 4;
    priority['*'] = 3;
    priority['/'] = 3;
    priority['('] = 1;
    priority[')'] = 1;
}

int priority_cmp(char op1, char op2)
{
    return priority[op2] - priority[op1];
}
int calc_op(stack *nums, stack *ops, int nowop)
{
    int a, b, op;
    pop(ops, &op);
    printf("op %c is <= %c\n", nowop, op);
    printf("get op from stack %c\n", op);
    if (0 != pop(nums, &b))
    {
        printf("pop failed\n");
        return -1;
    }
    if (0 != pop(nums, &a))
    {
        printf("pop failed\n");
        return 0;
    }
    printf("get b from stack %d\n", b);
    printf("get a from stack %d\n", a);
    switch (op)
    {
    case '+':
    {
        printf("push %d into stack\n", a + b);
        push(nums, a + b);
        break;
    }
    case '-':
    {
        printf("push %d into stack\n", a - b);
        push(nums, a - b);
        break;
    }
    case '*':
    {
        printf("push %d into stack\n", a * b);
        push(nums, a * b);
        break;
    }
    case '/':
    {
        printf("push %d into stack\n", a / b);
        push(nums, a / b);
        break;
    }
    }
    return 1;
}
int calc(char *exp, int *result)
{
    if (NULL == exp || NULL == result)
        return -1;
    stack nums, ops;
    init(&nums);
    init(&ops);
    int index = 0;
    int flag = 0;
    int temp = 0;
    int op;
    while (0 != *exp)
    {
        if (isdigit(*exp))
        {
            printf("char is %c\n", *exp);
            if (1 == flag)
            {
                pop(&nums, &temp);
                printf("pop from stack num %d\n", temp);
            }
            else
                temp = 0;
            flag = 1;
            temp = 10 * temp + *exp - '0';
            printf("push %d to stack\n", temp);
            push(&nums, temp);
        }
        else if ('/' == *exp || '*' == *exp || '+' == *exp || '-' == *exp)
        {
            flag = 0;
            printf("OP is %c\n", *exp);
            while ((ops.count > 0) && (0 == top(&ops, &op)) && '(' != op && ')' != op && (priority_cmp(*exp, op) <= 0))
            {
                calc_op(&nums, &ops, *exp);
            }
            printf("push %c to stack ops\n", *exp);
            push(&ops, *exp);
        }
        else if ('(' == *exp)
        {
            printf("push ( to stack ops\n");
            flag = 0;
            push(&ops, *exp);
        }
        else if (')' == *exp)
        {
            printf("deal with ) in ops\n");
            flag = 0;
            while (0 == top(&ops, &op) && '(' != op)
            {
                calc_op(&nums, &ops, *exp);
            }
            pop(&ops, &op);
        }
        else
        {
            flag = 0;
        }
        printf("flag is %d\n\n", flag);
        exp++;
    }
    while ((!empty(&ops)) && (!empty(&nums)))
    {
        if (!calc_op(&nums, &ops, 0))
            printf("exp is error\n");
    }
    pop(&nums, &temp);
    if ((!empty(&ops)) || (!empty(&nums)))
        printf("result is %d\n", temp);
    *result = temp;
    return 0;
}
/*int main()
{
    stack s, s2;
    init(&s);
    for (int i = 0; i < 10; i++)
    {
        push(&s, i);
    }
    printf("stack size:%d\n", size(&s));
    s2 = s;
    int on = 0;
    printf("on addr = %p val = %d\n",&on,on);
    for (int j = 0; j < 10; j++)
    {
        pop(&s, &on);
        printf("pop:%d\n", on);
    }
    printf("stack size:%d\n", size(&s));
    printf("pop empty stack ret: %d\n", pop(&s, &on));
}*/
int main(int argc, char *argv[])
{
    int result;
    priority_init();
    //char exp[] = "6*(12+3*3)*8 + 5";
    char exp[] = "1-9+7*8-5";
    calc(exp, &result);
    printf("result is %d\n", result);
    return 0;
}