#include <stdio.h>

int main()
{
    int request=0;			//선택지 선택
    bool res;				//로그인 성공여부 
    int year, month;			//달력의 년,월 입력받는 변수 
    char day[50], plan[50];		//일정저장할때 사용하는 변수 
    char re_day[50], re_plan[50], n;	//반복되는 일정 저장할때 사용하는 변수 
    int Men_month, Men_day;		//월경일 계산할 때 필요한 변수 
    int pw;			//password
    

    printf("\t\tDIARY PASSWORD : ");
    scanf("%d",&pw);
    res = login(pw);

    if( res == true )
    {
	do
	{
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
		    printf("반복되는 날짜와 일정 반복 년수를 입력하시오 : ");
		    scanf("%s %s %d",&re_day, &re_plan, &n);

		    anniversary(re_day, re_plan, &n);	
		    fflush(day);  fflush(plan);		break;
		case 5:
		    printf("월경일을 입력하시오 (월 일) : ");
		    scanf("%d %d",&Men_month, &Men_day);
			    
		    Menstruation(Men_month, Men_day);	break;
		case 6:
		    printf("Bye Bye!\n");
		    return 0;
		default:
		    break;
	    }
	}while ( request != 6 );
    }
    else // res == false
    {

    }
 
    return 0;
}
