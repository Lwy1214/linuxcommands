#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 월 이름을 저장하는 배열
const char* month_name[] = {
    " ", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// 각 월의 날짜 수를 저장하는 배열
const int days_per_month[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

// 윤년인지 확인하는 함수
int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0)
            return 1;
    }
    return 0;
}

int main() {
    time_t now = time(NULL);
    if (now == -1) {
        perror("time");
        return 1;
    }

    struct tm* tm_info = localtime(&now);
    if (tm_info == NULL) {
        perror("localtime");
        return 1;
    }

    int year = tm_info->tm_year + 1900;
    int month = tm_info->tm_mon + 1;

    // 달력 출력
    printf("     %s %d\n", month_name[month], year);
    printf("Su Mo Tu We Th Fr Sa\n");

    struct tm first_day = *tm_info;
    first_day.tm_mday = 1;
    mktime(&first_day);
    int weekday = first_day.tm_wday;

    int days_in_month = days_per_month[month];
    if (month == 2 && is_leap_year(year))
        days_in_month = 29;

    for (int i = 0; i < weekday; i++)
        printf("   ");

    for (int day = 1; day <= days_in_month; day++) {
        printf("%2d ", day);

        if ((weekday + day) % 7 == 0 || day == days_in_month)
            printf("\n");
    }

    return 0;
}
