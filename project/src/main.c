#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "move.h"
#include "anniversary.h"
#include "menstruation.h"
#include "calendar.h"
#include "input.h"
#include "output.h"
#include "login.h"

int main()
{
    int request=0;			//선택지 선택
    int res;				//로그인 성공여부 
    int year, month;			//달력의 년,월 입력받는 변수 
    char day[50], plan[50];		//일정저장할때 사용하는 변수 
    char re_day[50], re_plan[50];	//반복되는 일정 저장할때 사용하는 변수 
    int n;
    char Men[10];
    int  period;		//월경일 계산할 때 필요한 변수 
    char showPlan[50];			//저장된 일정 볼때 사용하는 변수

    system("clear");

    res = login();

    if( res == 1 )
    {
	system("clear");
	do
	{
	    move(0,0);
	    printf("\n\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t|\t  1. Viewing calendar   \t\t|\n");
	    printf("\t|\t  2. Viewing a schedule  \t\t|\n");
	    printf("\t|\t  3. Enter schedule    \t\t\t|\n");
	    printf("\t|\t  4. Enter recurring events    \t\t|\n");
	    printf("\t|\t  5. Enter Menstruation day     \t|\n");
	    printf("\t|\t  6. Close    \t\t\t\t|\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\n");

	    printf("\t\tPlease Enter the number : ");
	    scanf("%d", &request);

	    switch(request)
	    {
		case 1:
		    printf("\t\t년 월을 입력하시오 : ");
		    scanf("%d %d", &year,&month);
		    system("clear");
		    move(0,0);
		    calendar(year, month);
		    break;
		case 2:
		    printf("\t    일정을 보고 싶은 날을 선택하시오 : ");
		    scanf("%s",showPlan);
		    printf("\t%s Plans :\n",showPlan);

		    output(showPlan);
		    break;
		case 3:
		    printf("\t\t날짜와 일정을 입력하시오 : ");
		    scanf("%s %s",day, plan);

		    input(day, plan);
		    fflush(stdin);
   	  	    break;
		case 4:
		    printf("\t    반복되는 날짜와 일정, 반복 년수를 입력하시오 : ");
		    scanf("%s %s %d",re_day, re_plan, &n);

		    anniversary(re_day, re_plan, n);
		    fflush(stdin);
		    break;
		case 5:
		    printf("\t\t월경일을 입력하시오 (날짜 주기) : ");
		    scanf("%s %d",Men, &period);
		    
		    menstruation(Men, period);	
		    fflush(stdin);					
		    break;
		case 6:
		    system("clear");
		    move(0,0);
		    for(int i=3; i>=0; i--)
		    {
			move(25,10);		
			printf("After a few Sencond.....%ds\n",i);
			sleep(1);
		    }
		    printf("\n\t\t\t\tBye Bye!\n\n\n\n\n\n");
		    return 0;
		default:
		    printf("\n\t\t  Please Enter correctly\n");
		    sleep(1);
		    fflush(stdin);
		    break;
	    }
	system("clear");
	}while ( request != 6 );
    }
    else // res == false
    {
	return 0;
    }
 
    return 0;
}
