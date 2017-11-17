#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void input(char* day, char* plan);

int main()
{
    char day[10];
    char plan[50];
    printf("날짜와 일정을 입력하시오 : ");
    scanf("%s %s",day,plan);
    input(day,plan);
    return 0;
}

void input(char* day, char* plan)
{
    int fd;
    fd = open("plan.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);

    if( fd == -1 )  //open failure
    {
	printf("일정을 저장하는데 실패하였습니다.\n");
	perror("open");
	exit(0);
    }
    else	    //open successful
    {
	write(fd, day, strlen(day));
	write(fd, " ", 1);
	write(fd, plan, strlen(plan));
	write(fd, "\n", 1);
	close(fd);
	printf("일정 저장 성공!\n");
    }
    return;
}
