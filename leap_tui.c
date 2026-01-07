#include <stdio.h>
#include <time.h>
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int L_MONTH[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char WEEKD[7][3] = {"Su ", "Mo ", "Tu ", "We ", "Th ", "Fr ", "Sa"};
char MONTH_NAME[12][30] = {
    "      January       ",
    "      February      ",
    "      March         ",
    "      April         ",
    "       May          ",
    "       June         ",
    "       July         ",
    "       August       ",
    "     September      ",
    "      October       ",
    "      November      ",
    "      December      "};
char LUNAR_MONTH_NAME[12][50] = {"一月", "二月", "三月", "四月", "五月", "六月", "七月", "八月", "九月", "十月", "冬月", "腊月"};
char LUNAR_DAY_NAME[30][50] =
    {
        "初一",
        "初二",
        "初三",
        "初四",
        "初五",
        "初六",
        "初七",
        "初八",
        "初九",
        "初十",
        "十一",
        "十二",
        "十三",
        "十四",
        "十五",
        "十六",
        "十七",
        "十八",
        "十九",
        "二十",
        "廿一",
        "廿二",
        "廿三",
        "廿四",
        "廿五",
        "廿六",
        "廿七",
        "廿八",
        "廿九",
        "三十",
};
#define MROWS 3
#define MCOLS 4
#define DAYH 1                                        // 日期高度
#define DAYW 3                                        // 日期宽度
#define XPAD 5                                        // 月份间的横向空白为XPAD
#define YPAD 2                                        // 月份间的纵向空白为YPAD
#define MWIDTH (XPAD + DAYW * 7)                      // 月份宽度
#define MHEIGHT (YPAD + DAYH * 7 + 2)                 // 月份高度
#define WIDTH (DAYW * 7 * MCOLS + XPAD * (MCOLS - 1)) // 总宽度
#define HEIGHT ((DAYH * 7 + YPAD + 2) * MROWS)        // 总高度
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
            attron(COLOR_PAIR(3));
            mvprintw(y0 + MHEIGHT * y, x0 + MWIDTH * x, "%s", MONTH_NAME[x + MCOLS * y]);
            attroff(COLOR_PAIR(3));
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
                attron(COLOR_PAIR(2));
                mvprintw(y0 + MHEIGHT * y, x0 + DAYW * z + MWIDTH * x, "%s", WEEKD[z]);
                attroff(COLOR_PAIR(2));
            }
        }
    }
}

void print_day(int day, int bx, int by, int x, int y, int today_day, int today_month, int today_year)
{
    if (day + 1 == today_day && bx == ((today_month - 1) % 4) && by == ((today_month - 1) / 4))
    {
        attron(COLOR_PAIR(1)); // 使用绿色颜色对
    }
    mvprintw(y + 2 + MHEIGHT * by, x * DAYW + bx * MWIDTH, "%2d", day + 1);
    if (day + 1 == today_day && bx == ((today_month - 1) % 4) && by == ((today_month - 1) / 4))
    {
        attroff(COLOR_PAIR(1)); // 关闭绿色颜色对
    }
}

void print_day_title(int year, int today_day, int today_month)
{
    int x = 0;
    int y = 0;
    int l = leap(year);
    for (int by = 0; by < MROWS; by++)
    {
        for (int bx = 0; bx < MCOLS; bx++)
        {
            x = weekday(year, bx + MCOLS * by + 1, 1);
            y = 0;
            int d;
            if (l)
            {
                d = L_MONTH[bx + MCOLS * by];
            }
            else
            {
                d = MONTH[bx + MCOLS * by];
            }
            print_day(0, bx, by, x, y, today_day, today_month, year);
            for (int a = 1; a < d; a++)
            {
                if (x == 6)
                {
                    y += 1;
                    x = 0;
                }
                else
                {
                    x++;
                }
                print_day(a, bx, by, x, y, today_day, today_month, year);
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

void today(int *t_month, int *t_year, int *t_day)
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep);
    *t_month = 1 + p->tm_mon;
    *t_year = 1900 + p->tm_year;
    *t_day = p->tm_mday;
}
// int leapMonth(int year);
// int lunarYearDays(int year);
// int leapMonthDays(int year);

// 农历年份数据，从1900到2100
const int lunarInfo[] = {
    0x04bd8, 0x04ae0, 0x0a570, 0x054d5, 0x0d260, 0x0d950, 0x16554, 0x056a0, 0x09ad0, 0x055d2,
    0x04ae0, 0x0a5b6, 0x0a4d0, 0x0d250, 0x1d255, 0x0b540, 0x0d6a0, 0x0ada2, 0x095b0, 0x14977,
    0x04970, 0x0a4b0, 0x0b4b5, 0x06a50, 0x06d40, 0x1ab54, 0x02b60, 0x09570, 0x052f2, 0x04970,
    0x06566, 0x0d4a0, 0x0ea50, 0x06e95, 0x05ad0, 0x02b60, 0x186e3, 0x092e0, 0x1c8d7, 0x0c950,
    0x0d4a0, 0x1d8a6, 0x0b550, 0x056a0, 0x1a5b4, 0x025d0, 0x092d0, 0x0d2b2, 0x0a950, 0x0b557,
    0x06ca0, 0x0b550, 0x15355, 0x04da0, 0x0a5d0, 0x14573, 0x052d0, 0x0a9a8, 0x0e950, 0x06aa0,
    0x0aea6, 0x0ab50, 0x04b60, 0x0aae4, 0x0a570, 0x05260, 0x0f263, 0x0d950, 0x05b57, 0x056a0,
    0x096d0, 0x04dd5, 0x04ad0, 0x0a4d0, 0x0d4d4, 0x0d250, 0x0d558, 0x0b540, 0x0b5a0, 0x195a6,
    0x095b0, 0x049b0, 0x0a974, 0x0a4b0, 0x0b27a, 0x06a50, 0x06d40, 0x0af46, 0x0ab60, 0x09570,
    0x04af5, 0x04970, 0x064b0, 0x074a3, 0x0ea50, 0x06b58, 0x05ac0, 0x0ab60, 0x096d5, 0x092e0,
    0x0c960, 0x0d954, 0x0d4a0, 0x0da50, 0x07552, 0x056a0, 0x0abb7, 0x025d0, 0x092d0, 0x0cab5,
    0x0a950, 0x0b4a0, 0x0baa4, 0x0ad50, 0x055d9, 0x04ba0, 0x0a5b0, 0x15176, 0x052b0, 0x0a930,
    0x07954, 0x06aa0, 0x0ad50, 0x05b52, 0x04b60, 0x0a6e6, 0x0a4e0, 0x0d260, 0x0ea65, 0x0d530,
    0x05aa0, 0x076a3, 0x096d0, 0x04bd7, 0x04ad0, 0x0a4d0, 0x1d0b6, 0x0d250, 0x0d520, 0x0dd45,
    0x0b5a0, 0x056d0, 0x055b2, 0x049b0, 0x0a577, 0x0a4b0, 0x0aa50, 0x1b255, 0x06d20, 0x0ada0};
// 获取闰月月份，如果没有闰月则返回0
int leapMonth(int year)
{
    return lunarInfo[year - 1900] & 0xf;
}
// 计算某年闰月的天数
int leapMonthDays(int year)
{
    if (leapMonth(year))
        return (lunarInfo[year - 1900] & 0x10000) ? 30 : 29;
    else
        return 0;
}
// 计算某年农历的总天数
int lunarYearDays(int year)
{
    int i, sum = 348;
    for (i = 0x8000; i > 0x8; i >>= 1)
        sum += (lunarInfo[year - 1900] & i) ? 1 : 0;
    return (sum + leapMonthDays(year));
}

// 计算某年某月的天数
int monthDays(int year, int month)
{
    return (lunarInfo[year - 1900] & (0x10000 >> month)) ? 30 : 29;
}

// 将公历转农历的函数
void solarToLunar(int year, int month, int day, int *lunarYear, int *lunarMonth, int *lunarDay)
{
    struct tm solarStart = {0, 0, 0, 31, 0, 1900 - 1900}; // 1900-1-31为基准日
    struct tm solarDate = {0, 0, 0, day, month - 1, year - 1900};
    time_t base = mktime(&solarStart);
    time_t curr = mktime(&solarDate);
    int offset = (int)((curr - base) / (60 * 60 * 24));

    *lunarYear = 1900;
    while (offset >= lunarYearDays(*lunarYear))
    {
        offset -= lunarYearDays(*lunarYear);
        (*lunarYear)++;
    }

    int leap = leapMonth(*lunarYear);
    *lunarMonth = 1;
    int isLeap = 0;
    while (offset >= monthDays(*lunarYear, *lunarMonth))
    {
        if (leap > 0 && *lunarMonth == leap + 1 && isLeap == 0)
        {
            if (offset < leapMonthDays(*lunarYear))
            {
                isLeap = 1;
                break;
            }
            offset -= leapMonthDays(*lunarYear);
            isLeap = 1;
        }
        else
        {
            offset -= monthDays(*lunarYear, *lunarMonth);
            (*lunarMonth)++;
            isLeap = 0;
        }
    }

    *lunarDay = offset + 2; // 修正日期偏差
}

int main()
{
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();

    // 廿始化颜色
    if (has_colors())
    {
        start_color();
        printf("COLORS=%d\n", COLORS);
        init_color(COLOR_BLACK, 0, 0, 0);
        init_color(COLOR_GREEN, 0, 1000, 0);
        init_pair(1, COLOR_GREEN, COLOR_BLACK); // 定义颜色对1，黑色前景，绿色背景
        init_pair(2, 15, 0);
        init_pair(3, 15, 26);
    }

    int t_month, t_year, t_day;
    int lunarYear, lunarMonth, lunarDay;
    today(&t_month, &t_year, &t_day);

    print_month_title();
    print_week_title();
    print_day_title(t_year, t_day, t_month);
    solarToLunar(t_year, t_month, t_day, &lunarYear, &lunarMonth, &lunarDay);
    print_calandar();
    mvprintw(30, 0, "今天是农历%d年%s%s", lunarYear, LUNAR_MONTH_NAME[lunarMonth - 1], LUNAR_DAY_NAME[lunarDay - 1]);

    while (1)
    {
        int c = getch();
        mvprintw(35, 0, "Press Option + Q to quit");
        if (c == 147)
        {
            break;
        }
    }

    endwin();

    return 0;
}
