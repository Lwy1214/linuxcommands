#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    if (now == -1) {
        perror("time");
        return 1;
    }

    struct tm* tm_info = localtime(&now);
    if (tm_info == NULL) {
        perror("localtime");
        return 1;
    }

    char buffer[256];
    if (strftime(buffer, sizeof(buffer), "%c", tm_info) == 0) {
        fprintf(stderr, "strftime failed\n");
        return 1;
    }

    printf("%s\n", buffer);

    return 0;
}
