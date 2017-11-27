#include<stdio.h>
#include "calendar.h"
#include "../include/kbhit.h"
#include "../include/getch.h"

void showcalendar(int year,int month)
{
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0, cnt=0; 
    int first_date = 0;
    int i;
    days = ((year-1) * 365) + ((year-1) / 4) - ((year-1) / 100) + ((year-1) / 400);
    
    for(i = 0; i < month - 1; i++)
    {
	if(i==1)
	{
	    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //윤년여부
		day[1] = 29;
	    else
		day[1] = 28;
	}
	days += day[i];	 //입력받은 달 전까지의 전체 일수 구하기
    }


    /* 제목 출력 */
    printf("\n\t\t\t %d년  %d월\n", year, month);
    printf("\t\t\t==============\n");
    printf("\t\t-----------------------------\n");
    printf("\t\t SUN MON TUE WED THU FRI SAT \n");
    printf("\t\t-----------------------------\n");


    // 7일씩 나눠주면 전달에서 다음달로 넘어갈 때 첫주 칸을 채울 cnt
    first_date = days % 7;

    //1년 1월 1일은 월요일 (시작은 일요일부터)
    printf("\t\t");
    for(i = 0; i <= first_date; i++)
    {
	printf("    ");
	cnt++;
    } 

    for(i = 1; i <= day[month - 1]; i++)
    {
	if(cnt % 7 == 0)
	    printf("\n\t\t");
	char num[10];

	sprintf(num, "%d",i); // int -> string
	
	if(cnt%7==0){
		printf("\033[%dm%4s\033[0m",91, num);
	}
	else if(cnt%7==6){
		printf("\033[%dm%4s\033[0m",94, num);
	}
	else{
		printf("%4s",num);
	}
	cnt++;
    }

    printf("\n\n");
    return;
}

void calendar(int y,int m){
   int key;
   int year=y;
   int month=m;

   showcalendar(year,month);
   while(1)
   {
      printf("\t    Press the keyboard. left=a, right=d, exit=q");
      if(kbhit()){
         key=getch();
	 //left  a
         if(key=='a'){
	    month--;
	    if(month<1){
		year--;
		month=12;
	    }
         }
	 //right d
         else if(key=='d'){
	    month++;
	    if(month>12){
		year++;
		month=1;
	    }
         }
	 //up w
         else if(key=='w'){
	    year++;
         }
	 //down s
         else if(key=='s'){
	    year--;
         }
	 //exit q
         else if(key=='q') return;
	 showcalendar(year,month);
	 printf("\n");
      }
   }
   return;

}

