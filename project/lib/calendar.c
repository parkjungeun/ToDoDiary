#include<stdio.h>
#include"calendar.h"

void calandar(int year,int month)
{
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    int first_date = 0;
    int cnt = 0;

    days = (year-1) * 365 + (year-1) / 4 - (year-1) / 100 + (year-1) / 400;
    
    for(int i = 0; i < month - 1; i++)
    {
	if(i==1)
	{
	    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //윤년
	    {
		days[1] = 29;
	    }
	    else
	    {
		days[1] = 28;
	    }
	}
	days += day[i];
    }

    // 7일씩 나눠주면 전달에서 다음달로 넘어갈 때 첫주 칸을 채울 cnt
    first_date = days % 7;

    // 1년 1월 1일은 월요일 (시작은 일요일부터)


}
