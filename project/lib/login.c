#include "login.h"
#include <string.h>
#include <stdio.h>

int login()
{
    char pw[10];			//password
    int cnt=0;

    while(cnt!=3)
    {
	printf("\t\tDIARY PASSWORD : ");
	scanf("%s", pw);

	if(strcmp(pw,"1234")==0) 
	    return 1;
	else{
	    cnt++;
	    printf("\t\t비밀번호 오류 기회 %d번 남음\n",3-cnt);
	}
    }
    printf("\t\t비밀번호 3회 오류...\n"); 
    return 0;
}
