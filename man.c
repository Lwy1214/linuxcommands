#include <stdlib.h>
#include <stdio.h>

int main() {
    char command[100];
    printf("Enter the command: ");
    fgets(command, sizeof(command), stdin);
    
    // 개행 문자 제거
    command[strcspn(command, "\n")] = '\0';

    char man_command[100];
    sprintf(man_command, "man %s", command);
    
    system(man_command);

    return 0;
}
