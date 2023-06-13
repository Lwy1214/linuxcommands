#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    const char* source = argv[1];
    const char* destination = argv[2];

    int result = rename(source, destination);
    if (result == 0) {
        printf("File moved successfully.\n");
    } else {
        perror("Error moving file");
        return 1;
    }

    return 0;
}
