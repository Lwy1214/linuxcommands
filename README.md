# ls.c
ls 명령어 구현 "-a", "-l", "-R" 옵션이 지원됨, 한꺼번에 쓰려면 -al 대신 -a -l 연결하는 방식

 S_ISDIR(sb.st_mode)는 파일이 디렉토리인지 확인
S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH는 각각 해당 파일의 소유자, 그룹, 그리고 다른 사용자들이 읽기, 쓰기, 실행할 수 있는 권한을 확인, 그렇지 않다면 "-" 출

getpwuid()는 주어진 사용자 ID에 해당하는 사용자 정보를 검색하여 passwd 구조체를 반환합니다.
getgrgid()는 주어진 그룹 ID에 해당하는 그룹 정보를 검색하여 group 구조체를 반환합니다.

strtok() 함수는 문자열을 일정한 구분자(delimiter)로 분리
위 코드에서 strtok(ctime(&sb.st_mtime), "\n")는 ctime() 함수가 반환한 시간 문자열에서 \n을 구분자로 사용하여 문자열을 분리합니다.
ctime으로 시간 출력.

print_directory_contents 함수는 지정된 디렉토리의 내용을 출력하는 함수입니다. 이 함수는 dirname 매개 변수로 전달된 디렉토리의 내용을 출력합니다.
 opendir 함수를 사용하여 dir 변수에 디렉토리에 대한 포인터를 할당합니다. 그러면 readdir 함수를 사용하여 디렉토리에서 파일 목록을 하나씩 읽습니다. readdir 함수는 struct dirent 구조체에 대한 포인터를 반환합니다.

perror 함수는 지정된 문자열과 errno 값에 해당하는 오류 메시지를 출력합니다. 

<img width="506" alt="myls" src="https://user-images.githubusercontent.com/72485495/231483055-b9956a15-c658-4645-9acc-0e0e89dfdaa8.png">

# ls2.c
시스템콜로 ls 구현

<img width="315" alt="ls2" src="https://user-images.githubusercontent.com/72485495/231483145-7441e750-49c3-4fa3-9e67-82ed328d8359.png">

# cp1.c

 argc와 argv[]를 매개변수로 받습니다. argc는 명령행 인수의 개수를 나타내며, argv[]는 실제 명령행 인수의 배열입니다.
argc 검사: argc가 3이 아닌 경우, 즉 소스 파일과 대상 파일 두 가지 명령행 인수가 필요한데 제공되지 않은 경우, 사용법을 출력하고 프로그램을 종료합니다.

파일 열기: fopen 함수를 사용하여 소스 파일과 대상 파일을 각각 "rb" (바이너리 읽기) 및 "wb" (바이너리 쓰기) 모드로 엽니다. 파일 열기에 실패한 경우 적절한 오류 메시지를 출력하고 프로그램을 종료합니다.

파일 복사: fgetc 함수를 사용하여 소스 파일에서 문자를 읽어온 다음 fputc 함수를 사용하여 대상 파일에 문자를 씁니다. 이 작업은 소스 파일의 끝에 도달할 때까지 반복합니다.

성공 메시지 및 파일 닫기: 파일 복사가 완료되면 "File copied successfully." 메시지를 출력합니다. 그리고 열었던 파일들을 fclose 함수를 사용하여 닫아줍니다.

![cp1](https://github.com/Lwy1214/linuxcommands/assets/72485495/0992421e-ec14-4ea3-8461-42e87e3a2694)


# rm.c
argc는 명령행 인수의 개수 , argv[]는 실제 명령행 인수의 배열
argc를 이용해서 2보다 작은 경우, 즉 파일 이름이 제공되지 않은 경우 사용법을 출력하고 프로그램을 종료합니다.

 remove 함수는 인수로 전달된 파일 이름의 파일을 삭제하고,
 파일 삭제에 실패하면 오류 메세지를 내고, 성공하면 성공 메세지를 냅니다.

![rm](https://github.com/Lwy1214/linuxcommands/assets/72485495/85001a63-ef5c-4f40-b66c-7d5cffd27b23)
