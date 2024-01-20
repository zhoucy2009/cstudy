#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum country {
    China,
    India,
    Singapore,
    Malaysia,
    Indonesia,
    Korea,
    Japan,
    America,
    UK
} Country;

char *country_to_str(Country ct) {
    // 一定要加static，将字符串放在所有函数都可见的静态数据区。
    // 否则，栈上数据出函数之后就无效了
    static char cstr[9][32] = {
        "China",
        "India",
        "Singapore",
        "Malaysia",
        "Indonesia",
        "Korea",
        "Japan",
        "America",
        "UK",
    };
    // 枚举值是从零开始的整数
    return (char *)&cstr[ct];
} 

typedef struct student
{
    int num;
    Country ct;
    char name[64];
    char sex;
    float score[2];
} Student;

void print_student2(Student s1)
{
    printf("-------------------------------------------------\n");
    printf("Number=%d\nName=%s\nSex=%c\nScore1=%f\nScore2=%f\n", s1.num, s1.name, s1.sex, s1.score[0], s1.score[1]);//值传递，效率不高，因为需要复制结构体的所有字段
    printf("-------------------------------------------------\n\n");
}

void print_student(Student *s1)
{
    printf("-------------------------------------------------\n");
    printf("Number=%d\nCountry=%s\nName=%s\nSex=%c\nScore1=%f\nScore2=%f\n", s1->num, country_to_str(s1->ct), s1->name, s1->sex, s1->score[0], s1->score[1]);//地址传递，效率高，不需要复制结构体的所有字段
    printf("-------------------------------------------------\n\n");
}

float add_score(float score)
{
    if (score == 6.0)
    {
        return score;
    }
    float sa = (float)(rand() % (60 - (int)(score * 10))) / 10.0;
    return score + sa;
}

int main()
{
    Student s1 = {9, China, "Dengzhanbiao", 'M', {1, 1}};
    print_student(&s1);

    Student ss[4] = {
        {9, China, "Dengzhanbiao", 'M', {1, 1}},
        {10, Japan, "Wangfei", 'M', {2, 3}},
        {11, Indonesia, "Tiechui", 'M', {5, 6}},
        {12, Korea, "Liben", 'M', {6, 6}}};
    float ts = 0.0;
    float avrs = 0.0;
    for (int i = 0; i < 4; i++)
    {
        srand(time(NULL));
        for (int j = 0; j < 2; j++)
            ss[i].score[j] = add_score(ss[i].score[j]);
        print_student(&ss[i]);
        ts += (ss[i].score[0] + ss[i].score[1]);
    }
    avrs = ts / 8.0;
    printf("averange score = %f\n", avrs);
    s1 = ss[2];
    print_student(&s1);

    Student *ms1 = (Student *)malloc(sizeof(Student));
    print_student(ms1);
    ms1->num = 9;
    snprintf(ms1->name, 64, "%s%d", "dengjianguo", 2);
    ms1->ct = China;
    ms1->sex = 'M';
    ms1->score[0] = 1.0;
    ms1->score[1] = 1.0;
    print_student(ms1);

    Student *mss = (Student *)calloc(4, sizeof(Student));
    print_student(&mss[1]);
    free(ms1);
    free(mss);
}