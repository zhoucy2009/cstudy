#include <stdio.h>
#include <time.h>
int MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int L_MONTH[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char WEEKD[7][3] = {"Su","Mo", "Tu", "We", "Th", "Fr", "Sa"};
char MONTH_NAME[12][10] = {
    "January", "February", "March", "April", 
    "May", "June", "July", "August", 
    "September", "October", "November", "December"
};
#define MROWS 3
#define MCOLS 4
#define DAYH  1  // 日期高度
#define DAYW  3  // 日期宽度
#define XPAD  5  // 月份间的横向空白为XPAD
#define YPAD  2  // 月份间的纵向空白为YPAD
#define MWIDTH (XPAD + DAYW * 7)           // 月份宽度
#define MHEIGHT (YPAD + DAYH * 7 + 2)      //月份高度
#define WIDTH  (DAYW * 7 * MCOLS + XPAD * (MCOLS - 1))   //总宽度
#define HEIGHT ((DAYH * 7 + YPAD + 2) * MROWS) //总高度
char CALANDAR_BUFFER[HEIGHT][WIDTH];

// 是否闰年
int leap(int year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

// 给定日期返回是一年中的第几天
int calculate(int year, int month, int date)
{
    int number = 0;
    int judge = leap(year);
    for (int i = 0; i < month - 1; i++)
    {
        number += MONTH[i];
    }
    number += date;
    if (judge == 1)
    {
        if (month > 2)
        {
            number += 1;
        }
    }
    return number;
}

// 给定日期判断是周几
int weekday(int year, int month, int date)
{
    int w = 0;
    int leap_y = 0;
    int dy /*days of year*/ = 0;
    int dmd /*days of month and date*/ = 0;
    int wd /*week day*/ = 0;
    if (year - 1900 == 0)
    {
        wd = calculate(year, month, date) % 7;
    }
    if (year - 1900 > 0)
    {
        for (int i = 1900; i < year; i++)
        {
            leap_y += leap(i);
        }
        dy = leap_y * 366 + (year - 1900 - leap_y) * 365;
        dmd = calculate(year, month, date);
        wd = (dy + dmd) % 7;
    }
    return wd;
}

void print_month_title()
{
    int x0 = 0;
    int y0 = 0;
    for (int y = 0; y < MROWS; y++)
    {
        for (int x = 0; x < MCOLS; x++)
        {
            sprintf(&CALANDAR_BUFFER[y0 + MHEIGHT * y][x0 + MWIDTH * x], "%s", MONTH_NAME[x + MCOLS * y]);
            // printf("%d,%d,%d\n", y0 + dy * y, x0 + dx * x, x + 3 * y);
        }
    }
}

void print_week_title()
{
    int x0 = 0;
    int y0 = 1;
    for (int y = 0; y < MROWS; y++)
    {
        for (int x = 0; x < MCOLS; x++)
        {
            for (int z = 0; z < 7; z++)
            {
                sprintf(&CALANDAR_BUFFER[y0 + MHEIGHT * y][x0 + DAYW * z + MWIDTH * x], "%s", WEEKD[z]);
            }
        }
    }
}

void print_day(int day, int bx, int by, int x, int y) {
    sprintf(&CALANDAR_BUFFER[y + 2 + MHEIGHT * by][x * DAYW + bx * MWIDTH], "%d", day + 1);
}

void print_day_title(int year)
{
    int x = 0;
    int y = 0;
    int count = 0;
    int l = leap(year);
    for (int by = 0; by < MROWS; by++)
    {
        for (int bx = 0; bx < MCOLS; bx++)
        {
            x = weekday(year, bx + MCOLS * by + 1, 1);
            y = 0;
            int d;
            if (l) {
                d = L_MONTH[bx + MCOLS * by];
            } else {
                d = MONTH[bx +  MCOLS * by];
            }
            print_day(0, bx, by, x, y);
            for(int a=1; a<d; a++){
                if(x==6){
                    y += 1;
                    x = 0;
                } else {
                    x++;
                }
                print_day(a, bx, by, x, y);
            }
        }
    }
}

void print_calandar()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (CALANDAR_BUFFER[y][x] == 0)
            {
                printf("%c", ' ');
            }
            else
            {
                printf("%c", CALANDAR_BUFFER[y][x]);
            }
        }
        printf("\n");
    }
}
void today(int *t_month,int *t_year,int *t_day){
    time_t timep;
    struct tm *p;
    time(&timep);
    p=localtime(&timep);
    *t_month = 1+p->tm_mon;
    *t_year = 1900+p->tm_year;
    *t_day = p->tm_mday;
    printf("%d,%d,%d\n",1900+p->tm_year,1+p->tm_mon,p->tm_mday);
}
void color(){
    printf("\033[0:2H");
}

int main()
{
    int t_month,t_year,t_day;
    today(&t_month,&t_year,&t_day);
    // printf("Enter the year:");
    // scanf("%d",&year);
    printf("\033[2J");
    print_month_title();
    print_week_title();
    print_day_title(t_year);
    print_calandar();
}
