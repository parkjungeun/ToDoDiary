#include <stdio.h>

int main()
{
    int request=0, res=0;		//선택지 선택, 로그인 성공여부 
    int year, month;			//달력의 년,월 입력받는 변수 
    char day[50], plan[50];		//일정저장할때 사용하는 변수 
    char re_day[50], re_plan[50];	//반복되는 일정 저장할때 사용하는 변수 
    int Men_month, Men_day;		//월경일 계산할 때 필요한 변수 

   //res = login();

    if( res == 1 ){
	while ( request != 6 ){
	    printf("==================================\n");
	    printf("1. Viewing calendar\n");
	    printf("2. Viewing a schedule\n");
	    printf("3. Enter schedule\n");
	    printf("4. Enter recurring events\n");
	    printf("5. Enter Menstruation day\n");
	    printf("6. Close\n");
	    printf("==================================\n");
	    
	    scanf("%d", &request);

	    switch(request){
		case 1:	
		    printf("년 월을 입력하시오 : ");
		    scanf("%d %d",&year,&month);
		    calendar(year,month);		break;
		case 2:
		    //printf("일정을 보고 싶은 년도와 달을 선택하시오 : ");
		    //scanf("%d %d",&year,&month);

		    //calendar(year,month);
		    //output();		break;
		case 3:
		    printf("날짜와 일정을 입력하시오 : ");
		    scanf("%s %s",&day, &plan);

		    input(day, plan);	
		    fflush(day);  fflush(plan);		break;
		case 4:
		    printf("반복되는 날짜와 일정을 입력하시오 : ");
		    scanf("%s %s",&re_day, &re_plan);

		    //recurringEvent(re_day, re_plan);	
		    fflush(day);  fflush(plan);		break;
		case 5:
		    printf("월경일을 입력하시오 (월 일) : ");
		    scanf("%d %d",&Men_month, &Men_day);
			    
		    Menstruation(Men_month, Men_day);	break;
		case 6:
		    return 0;
		default:
		    break;
		}
	    }
	}
	else{ // res == 0

	}
 
    return 0;
}
