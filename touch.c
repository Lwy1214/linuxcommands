#include <stdio.h>
#include <utime.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [file2] ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (utime(argv[i], NULL) != 0) {
            // 파일이 존재하지 않으면 새로 생성
            FILE* file = fopen(argv[i], "w");
            if (file == NULL) {
                perror("Error creating file");
                return 1;
            }
            fclose(file);
        }
    }

    return 0;
}
