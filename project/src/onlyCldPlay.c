#include<stdio.h>
#include "../include/kbhit.h"
#include "../include/getch.h"

void textColorSet(char *c,int colorNum);
void calendar(int year,int month);

int main(){
   int key;
   int i;
   int year;
   int month;
   printf("write year and month\n");
   scanf("%d %d",&year,&month);
   calendar(year,month);
   while(1){
      printf("Press the keyboard. left=a, right=d, exit=q\n");
      if(kbhit()){
         key=getch();
	 //left  a
         if(key==97){
	    month--;
	    if(month<1){
		year--;
		month=12;
	    }
            calendar(year,month);
         }
	 //right d
         else if(key==100){
	    month++;
	    if(month>12){
		year++;
		month=1;
	    }
	    calendar(year,month);
         }
	 //exit q
         else if(key==113) return 0;
      }
   }
   return 0;

}

void textColorSet(char *c,int colorNum) {

        if(colorNum==0){
        	printf("\033[%dm%4s\033[0m",94, c);
	}
	else if(colorNum==1){
		printf("\033[%dm%4s\033[0m",91,c);
	}
	return;
}

void calendar(int year,int month)
{
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0, cnt=0;
    int first_date = 0;

    days = ((year-1) * 365) + ((year-1) / 4) - ((year-1) / 100) + ((year-1) / 400);

    for(int i = 0; i < month - 1; i++)
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
    printf("\n\t %d년  %d월\n", year, month);
    printf("\t==============\n");
    printf("-----------------------------\n");
    printf(" SUN MON TUE WED THU FRI SAT \n");
    printf("-----------------------------\n");


    // 7일씩 나눠주면 전달에서 다음달로 넘어갈 때 첫주 칸을 채울 cnt
    first_date = days % 7;

    //1년 1월 1일은 월요일 (시작은 일요일부터)
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

	sprintf(num, "%d",i); // int -> string

	if(cnt%7==0){
		textColorSet(num,0);
	}
	else if(cnt%7==6){
		textColorSet(num,1);
	}
	else{
		printf("%4s",num);
	}
	cnt++;
    }

    printf("\n\n");
    return;
}
