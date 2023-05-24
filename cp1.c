#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: cp <source_file> <destination_file>\n");
        return 1;
    }

    FILE* source = fopen(argv[1], "rb");
    if (source == NULL) {
        printf("Error: Failed to open source file.\n");
        return 1;
    }

    FILE* destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        printf("Error: Failed to create destination file.\n");
        fclose(source);
        return 1;
    }

    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(destination);

    return 0;
}
