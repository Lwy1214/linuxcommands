#include <stdio.h>
#include <stdlib.h>

void count_file(const char* filename, int* lines, int* words, int* bytes) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    int ch;
    int prev_ch = ' ';
    *lines = *words = *bytes = 0;

    while ((ch = fgetc(file)) != EOF) {
        (*bytes)++;

        if (ch == '\n')
            (*lines)++;

        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (prev_ch != ' ' && prev_ch != '\t' && prev_ch != '\n')
                (*words)++;
        }

        prev_ch = ch;
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int lines, words, bytes;
    count_file(argv[1], &lines, &words, &bytes);

    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Bytes: %d\n", bytes);

    return 0;
}
