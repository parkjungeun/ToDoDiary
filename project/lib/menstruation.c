#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "menstruation.h"

void menstruation(char* Men, int period)
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int s = atoi(Men);  //string -> int
    int year = s / 10000;
    int month = (s - year*10000) / 100;
    int day =  (s - year*10000 - month*100);
    
    if(year > 10000 || month > 13 || day > days[month-1])
    {
	printf("\t\t날짜를 올바르게 입력하시오.\n");
	return ;
    }

    printf("\t\t월경 시작일 : %d년 %d월 %d일\n", year, month, day);

    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //윤년
	days[1] = 29;
    else
	days[1] = 28;

    day = day+period;

    if( day > days[month-1] )
    { 
	while(day > days[month-1])
	{
	    day-=days[month-1];

	    if(month>12)
		month=1;
	    else
		month+=1;
	}

	if(month>12)
	{
	    month=1;
	    year+=1;
	}
	printf("\n\t\t다음 월경 예정일 :  %d년 %d월 %d일\n", year, month, day);
    }
    else 
    {
	printf("\n\t\t다음 월경 예정일 : %d년 %d월 %d일\n", year, month, day);
    }

    char ch;
    printf("\n\t\t나가기 (press y) : ");
    do{
	fflush(stdin);
	scanf("%c", &ch);
	if(ch != 'y'){
	    printf("\n\t\t나가기 (press y) : ");
	}
    }while(ch!='y');
    
    return;
}

