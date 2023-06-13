#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define DEFAULT_LINES 10

void print_tail(FILE* file, int numLines) {
    char** lines = malloc(numLines * sizeof(char*));
    int currLine = 0;
    int totalLines = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL) {
        if (lines[currLine] != NULL) {
            free(lines[currLine]);
        }
        lines[currLine] = strdup(line);

        currLine = (currLine + 1) % numLines;
        totalLines++;
    }

    int startLine = currLine;
    int linesToPrint = totalLines < numLines ? totalLines : numLines;

    for (int i = 0; i < linesToPrint; i++) {
        printf("%s", lines[startLine]);
        startLine = (startLine + 1) % numLines;
    }

    for (int i = 0; i < numLines; i++) {
        free(lines[i]);
    }
    free(lines);
}

int main(int argc, char* argv[]) {
    FILE* file;

    if (argc == 1) {
        // 입력 파일이 지정되지 않은 경우 표준 입력으로부터 읽어옴
        print_tail(stdin, DEFAULT_LINES);
    } else {
        // 입력 파일을 순서대로 처리
        for (int i = 1; i < argc; i++) {
            file = fopen(argv[i], "r");
            if (file == NULL) {
                fprintf(stderr, "Cannot open file: %s\n", argv[i]);
                continue;
            }

            printf("==> %s <==\n", argv[i]);
            print_tail(file, DEFAULT_LINES);

            fclose(file);
        }
    }

    return 0;
}
