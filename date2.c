#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int useUTC = 0;  // -u 옵션 사용 여부

    // 명령줄 인자 파싱
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0) {
            useUTC = 1;
        } else {
            fprintf(stderr, "Invalid option: %s\n", argv[i]);
            return 1;
        }
    }

    // 현재 시간 정보 가져오기
    time_t now;
    time(&now);

    // 시간 정보 포맷 설정
    const char* format = useUTC ? "%Y-%m-%d %H:%M:%S UTC" : "%Y-%m-%d %H:%M:%S";

    // 시간 출력
    char timeStr[100];
    strftime(timeStr, sizeof(timeStr), format, useUTC ? gmtime(&now) : localtime(&now));
    printf("%s\n", timeStr);

    return 0;
}
