#include <stdio.h>
#include <unistd.h>

int main() {
    char current_dir[1024];
    if (getcwd(current_dir, sizeof(current_dir)) != NULL) {
        printf("%s\n", current_dir);
    } else {
        perror("getcwd");
        return 1;
    }

    return 0;
}
