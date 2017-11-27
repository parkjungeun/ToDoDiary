#include <stdio.h>
#include "../include/kbhit.h"
#include "../include/getch.h"
#include "../include/calendar.h"

void textColorSet(char *c,int colorNum);
void calendar(int year,int month);

void calendar_key(){
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
         else if(key==113) return;
      }
   }
   return;

}
