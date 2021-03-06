#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "input.h"

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
	printf("\t\t일정 저장 성공!\n");

	char ch[2];
	printf("\n\t\t나가기 (press y) : ");
	while(1)
        {
            fflush(stdin);
            scanf("%s", ch);
	    if(strcmp(ch, "y") == 0)
		break;
	    else
		printf("\n\t\t나가기 (press y) : ");
        }
    }
    return;
}
