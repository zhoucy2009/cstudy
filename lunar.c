#include <stdio.h>
#include <time.h>

int leapMonth(int year);
int lunarYearDays(int year);
int leapMonthDays(int year);

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
    0x0b5a0, 0x056d0, 0x055b2, 0x049b0, 0x0a577, 0x0a4b0, 0x0aa50, 0x1b255, 0x06d20, 0x0ada0
};

// 计算某年农历的总天数
int lunarYearDays(int year) {
    int i, sum = 348;
    for (i = 0x8000; i > 0x8; i >>= 1)
        sum += (lunarInfo[year - 1900] & i) ? 1 : 0;
    return (sum + leapMonthDays(year));
}

// 计算某年闰月的天数
int leapMonthDays(int year) {
    if (leapMonth(year))
        return (lunarInfo[year - 1900] & 0x10000) ? 30 : 29;
    else
        return 0;
}

// 获取闰月月份，如果没有闰月则返回0
int leapMonth(int year) {
    return lunarInfo[year - 1900] & 0xf;
}

// 计算某年某月的天数
int monthDays(int year, int month) {
    return (lunarInfo[year - 1900] & (0x10000 >> month)) ? 30 : 29;
}

// 将公历转农历的函数
void solarToLunar(int year, int month, int day, int* lunarYear, int* lunarMonth, int* lunarDay) {
    struct tm solarStart = {0, 0, 0, 31, 0, 1900 - 1900};  // 1900-1-31为基准日
    struct tm solarDate = {0, 0, 0, day, month - 1, year - 1900};
    time_t base = mktime(&solarStart);
    time_t curr = mktime(&solarDate);
    int offset = (int)((curr - base) / (60 * 60 * 24));

    *lunarYear = 1900;
    while (offset >= lunarYearDays(*lunarYear)) {
        offset -= lunarYearDays(*lunarYear);
        (*lunarYear)++;
    }

    int leap = leapMonth(*lunarYear);
    *lunarMonth = 1;
    int isLeap = 0;
    while (offset >= monthDays(*lunarYear, *lunarMonth)) {
        if (leap > 0 && *lunarMonth == leap + 1 && isLeap == 0) {
            if (offset < leapMonthDays(*lunarYear)) {
                isLeap = 1;
                break;
            }
            offset -= leapMonthDays(*lunarYear);
            isLeap = 1;
        }
        else {
            offset -= monthDays(*lunarYear, *lunarMonth);
            (*lunarMonth)++;
            isLeap = 0;
        }
    }

    *lunarDay = offset + 2;  // 修正日期偏差
}

int main() {
    int year, month, day;
    int lunarYear, lunarMonth, lunarDay;

    printf("请输入公历日期(年 月 日)：");
    scanf("%d %d %d", &year, &month, &day);

    solarToLunar(year, month, day, &lunarYear, &lunarMonth, &lunarDay);

    printf("对应的农历日期是：%d年%s%d月%d日\n", lunarYear, (leapMonth(lunarYear) && lunarMonth == leapMonth(lunarYear) + 1) ? "闰" : "", lunarMonth, lunarDay);

    return 0;
}


