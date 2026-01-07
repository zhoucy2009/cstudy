#ifndef _LUNAR_H
#define _LUNAR_H
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
// #include <locale.h>
char LUNAR_MONTH_NAME[12][50];
char LUNAR_DAY_NAME[30][50];
// 获取闰月月份，如果没有闰月则返回0
int leapMonth(int year);
// 计算某年闰月的天数
int leapMonthDays(int year);
// 计算某年农历的总天数
int lunarYearDays(int year);
// 计算某年某月的天数
int monthDays(int year, int month);
// 将公历转农历的函数
void solarToLunar(int year, int month, int day, int *lunarYear, int *lunarMonth, int *lunarDay);
#endif