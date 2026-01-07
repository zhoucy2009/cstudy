#ifndef _CALENDAR_H
#define _CALENDAR_H
#include <stdio.h>
#include <time.h>
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
// 是否闰年
int leap(int year);
// 给定日期返回是一年中的第几天
int calculate(int year, int month, int date);
// 给定日期判断是周几
int weekday(int year, int month, int date);
void print_month_title();
void print_week_title();
void print_day(int day, int bx, int by, int x, int y, int today_day, int today_month, int today_year);
void print_day_title(int year, int today_day, int today_month);
void print_calandar();
void today(int *t_month, int *t_year, int *t_day);
#endif