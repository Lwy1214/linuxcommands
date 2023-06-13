#include <stdio.h>

#define MAX_LINE_LENGTH 1024
#define DEFAULT_LINES 10

void print_head(FILE* file, int numLines) {
    char line[MAX_LINE_LENGTH];
    int linesPrinted = 0;

    while (linesPrinted < numLines && fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        linesPrinted++;
    }
}

int main(int argc, char* argv[]) {
    FILE* file;

    if (argc == 1) {
        // 입력 파일이 지정되지 않은 경우 표준 입력으로부터 읽어옴
        print_head(stdin, DEFAULT_LINES);
    } else {
        // 입력 파일을 순서대로 처리
        for (int i = 1; i < argc; i++) {
            file = fopen(argv[i], "r");
            if (file == NULL) {
                fprintf(stderr, "Cannot open file: %s\n", argv[i]);
                continue;
            }

            printf("==> %s <==\n", argv[i]);
            print_head(file, DEFAULT_LINES);

            fclose(file);
        }
    }

    return 0;
}
