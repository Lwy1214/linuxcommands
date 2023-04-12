#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void print_file_info(struct stat sb, char* name) {
    // 파일 종류 출력
    printf((S_ISDIR(sb.st_mode)) ? "d" : "-");
    printf((sb.st_mode & S_IRUSR) ? "r" : "-");
    printf((sb.st_mode & S_IWUSR) ? "w" : "-");
    printf((sb.st_mode & S_IXUSR) ? "x" : "-");
    printf((sb.st_mode & S_IRGRP) ? "r" : "-");
    printf((sb.st_mode & S_IWGRP) ? "w" : "-");
    printf((sb.st_mode & S_IXGRP) ? "x" : "-");
    printf((sb.st_mode & S_IROTH) ? "r" : "-");
    printf((sb.st_mode & S_IWOTH) ? "w" : "-");
    printf((sb.st_mode & S_IXOTH) ? "x" : "-");

    // 링크 수, 소유자, 그룹, 크기, 수정일 출력
    printf(" %ld", (long)sb.st_nlink);
    printf(" %s", getpwuid(sb.st_uid)->pw_name);
    printf(" %s", getgrgid(sb.st_gid)->gr_name);
    printf(" %lld", (long long)sb.st_size);
    printf(" %s", strtok(ctime(&sb.st_mtime), "\n"));
    printf(" %s\n", name);
}

void print_directory_contents(char* dirname, int all_flag, int long_flag) {
    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir(dirname)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (all_flag == 0 && ent->d_name[0] == '.') {
                continue;
            }

            char path[1024];
            sprintf(path, "%s/%s", dirname, ent->d_name);

            struct stat sb;
            if (lstat(path, &sb) == -1) {
                perror("lstat");
                exit(EXIT_FAILURE);
            }

            if (long_flag) {
                print_file_info(sb, ent->d_name);
            } else {
                printf("%s\n", ent->d_name);
            }

            if (S_ISDIR(sb.st_mode) && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                print_directory_contents(path, all_flag, long_flag);
            }
        }
        closedir(dir);
    } else {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {
    int all_flag = 0;
    int long_flag = 0;
    char* dirname = ".";

    // 옵션 인식
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            all_flag = 1;
        }

else if (strcmp(argv[i], "-l") == 0) {
            long_flag = 1;
        } else if (argv[i][0] != '-') {
            dirname = argv[i];
        } else {
            fprintf(stderr, "ls: invalid option -- '%s'\n", argv[i]+1);
            fprintf(stderr, "Try 'ls --help' for more information.\n");
            exit(EXIT_FAILURE);
        }
    }

    // 디렉토리 내용 출력
    print_directory_contents(dirname, all_flag, long_flag);

    return EXIT_SUCCESS;
}
