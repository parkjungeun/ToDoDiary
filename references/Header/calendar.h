//#include<stdio.h>
//#include"textColorSet.h"
void calendar(int year,int month);

void calendar(int year,int month){
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0,cnt=0;
    int first_date = 0;

    days = (year-1) * 365 + (year-1) / 4 - (year-1) / 100 + (year-1) / 400;

    for(int i = 0; i < month - 1; i++)
    {
	if(i==1)
	{
	    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //윤년
		day[1] = 29;
	    else
		day[1] = 28;
	}
	days += day[i];
    }


    /* 제목 출력 */
    printf("\n\t %d년  %d월\n", year, month);
    printf("\t==============\n");
    printf("-----------------------------\n");
    textColor4set("SUN",1);
    printf(" MON TUE WED THU FRI");
    textColor4set("SAT",0);
    printf(" \n");
    printf("-----------------------------\n");


    // 7일씩 나눠주면 전달에서 다음달로 넘어갈 때 첫주 칸을 채울 cnt
    first_date = days % 7;

    // 1년 1월 1일은 월요일 (시작은 일요일부터)
    for(int i = 0; i <= first_date; i++)
    {
	printf("    ");
	cnt++;
    } 

    for(int i = 1; i <= day[month - 1]; i++)
    {
	if(cnt % 7 == 0)
	    printf("\n");
	char num[10];

	sprintf(num,"%d",i); // int -> string
	if(cnt%7==0){
		textColor4set(num,1);
	}
	else if(cnt%7==6){
		textColor4set(num,0);
	}
	else{
		printf("%4s",num);
	}
	cnt++;
    }

    printf("\n\n");
    return;
}

