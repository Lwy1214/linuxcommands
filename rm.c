#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: rm <file1> [<file2> ...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (remove(argv[i]) != 0) {
            printf("Error: Failed to delete file %s\n", argv[i]);
        } else {
            printf("File %s deleted successfully.\n", argv[i]);
        }
    }

    return 0;
}
