#include "calendar.h"
#include "lunar.h"
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
