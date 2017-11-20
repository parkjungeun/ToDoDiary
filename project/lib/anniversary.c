#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "anniversary.h"

void anniversary(char* day, char* plan, int num) //앞으로 몇년동안 쓸지 num
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
	int s = atoi(day);  //string -> int
	char buf[10];

	for(int i=1;i<=num;i++)
	{
	    s+=10000;
	    sprintf(buf, "%d", s);
	    write(fd, buf, strlen(buf));
 	    write(fd, " ", 1);
	    write(fd, plan, strlen(plan));
	    write(fd, "\n", 1);
	}
	close(fd);
	printf("일정 저장 성공!\n");
    }
    return;
}
