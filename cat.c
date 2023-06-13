#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: cat <filename>\n");
        return 1;
    }

    const char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}
