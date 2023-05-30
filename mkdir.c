#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: mkdir <directory>\n");
        return 1;
    }

    const char* directory = argv[1];

    int status = mkdir(directory, 0755);
    if (status != 0) {
        printf("Error creating directory!\n");
        exit(1);
    }

    printf("Directory created successfully.\n");

    return 0;
}
