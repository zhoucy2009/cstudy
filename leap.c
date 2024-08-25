#include <stdio.h>
#include <string.h>
int MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int L_MONTH[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char WEEKD[7][3] = {"Su","Mo", "Tu", "We", "Th", "Fr", "Sa"};
char MONTH_NAME[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const int DAYH = 1;
const int DAYW = 3;
const int XPAD = 5;
// 月份间的纵向空白为YPAD
const int YPAD = 2;
const int WIDTH = DAYW * 7 * 3 + XPAD * 2;
const int HEIGHT = (DAYH * 7 + YPAD + 2) * 4;
char CALANDAR_BUFFER[HEIGHT][WIDTH];
int leap(int year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
    // int a = year % 100;
    // if (a == 0)
    // {
    //     if (year % 400 == 0)
    //     {
    //         return 1;
    //     }
    //     else
    //     {
    //         return 0;
    //     }
    // }
    // else
    // {
    //     if (year % 4 == 0)
    //     {
    //         return 1;
    //     }
    //     else
    //     {
    //         return 0;
    //     }
    // }
}
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
    int dx = XPAD + DAYW * 7;
    int dy = YPAD + DAYH * 7 + 2;
    int x0 = 0;
    int y0 = 0;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            sprintf(&CALANDAR_BUFFER[y0 + dy * y][x0 + dx * x], "%s", MONTH_NAME[x + 3 * y]);
            // printf("%d,%d,%d\n", y0 + dy * y, x0 + dx * x, x + 3 * y);
        }
    }
}
void print_week_title()
{
    int dx = XPAD + DAYW * 7;
    int dy = YPAD + DAYH * 7 + 2;
    int x0 = 0;
    int y0 = 1;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            for (int z = 0; z < 7; z++)
            {
                sprintf(&CALANDAR_BUFFER[y0 + dy * y][x0 + DAYW * z + (DAYW * 7 + XPAD) * x], "%s", WEEKD[z]);
            }
        }
    }
}

void print_day(int day, int bx, int by, int x, int y) {
    int dy = YPAD + DAYH * 7 + 2;
    int dx = XPAD + DAYW * 7;
    sprintf(&CALANDAR_BUFFER[y + 2 + dy * by][x * DAYW + bx * dx], "%d", day + 1);
}

void print_day_title(int year)
{
    int dx = XPAD + DAYW * 7;
    int dy = YPAD + DAYH * 7 + 2;
    int x = 0;
    int y = 0;
    int count = 0;
    for (int by = 0; by < 4; by++)
    {
        for (int bx = 0; bx < 3; bx++)
        {
            x = weekday(year, bx + 3 * by + 1, 1);
            y = 0;
            int d = MONTH[bx + 3 * by];
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
int main()
{
    // memset(CALANDAR_BUFFER,' ', sizeof(CALANDAR_BUFFER));
    // for(int y=0;y<HEIGHT;y++){
    //     for(int x = 0;x<WIDTH; x++){
    //         CALANDAR_BUFFER[y][x] = 'a'+y%26;
    //     }
    // }
    // int year, month, date;
    // printf("Type the year,month,date:");
    // scanf("%d,%d,%d", &year, &month, &date);
    // int r = weekday(year, month, date);
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%c", WEEKD[r][i]);
    // }
    int year = 2024;
    printf("%d\n", year);
    print_month_title();
    print_week_title();
    print_day_title(year);
    print_calandar();
}