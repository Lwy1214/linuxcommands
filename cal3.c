#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

void print_month(int year, int month) {
    // 달력 출력
    printf("     %s %d\n", month_name[month], year);
    printf("Su Mo Tu We Th Fr Sa\n");

    struct tm first_day = {0};
    first_day.tm_year = year - 1900;
    first_day.tm_mon = month - 1;
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

    printf("\n");
}

int main(int argc, char* argv[]) {
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);

    if (argc == 1) {
        // 현재 날짜를 기준으로 출력
        int year = tm_info->tm_year + 1900;
        int month = tm_info->tm_mon + 1;
        print_month(year, month);
    } else if (argc == 3 && strcmp(argv[1], "-y") == 0) {
        // -y 옵션을 사용하여 연도를 지정
        int year = atoi(argv[2]);
        if (year < 1 || year > 9999) {
            fprintf(stderr, "Invalid year\n");
            return 1;
        }

        for (int month = 1; month <= 12; month++) {
            print_month(year, month);
        }
    } else if (argc == 4 && strcmp(argv[1], "-y") == 0) {
        // -y 옵션을 사용하여 연도와 월을 지정
        int year = atoi(argv[2]);
        int month = atoi(argv[3]);
        if (year < 1 || year > 9999) {
            fprintf(stderr, "Invalid year\n");
            return 1;
        }
        if (month < 1 || month > 12) {
            fprintf(stderr, "Invalid month\n");
            return 1;
        }
        print_month(year, month);
    } else {
        fprintf(stderr, "Invalid arguments\n");
        return 1;
    }

    return 0;
}
