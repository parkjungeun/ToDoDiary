#include <stdio.h>

int main()
{
    int request=0, res=0;
    int year, month;
    char day[50], plan[50];
    char re_day[50], re_plan[50];
    int Men_month, Men_day;

//    res = login();

    if( res == 1 )
    {
	while ( num != 6 )
	{
	    printf("==================================\n");
	    printf("1. Viewing calendar\n");
	    printf("2. Viewing a schedule\n");
	    printf("3. Enter schedule\n");
	    printf("4. Enter recurring events\n");
	    printf("5. Enter Menstruation day\n");
	    printf("6. Close\n");
	    printf("==================================\n");
	    
	    scanf("%d", &request);

	    switch(request)
	    {
		case 1:	
		    printf("년 월을 입력하시오 : ");
		    scanf("%d %d",&year,&month);
		    calendar(year,month);		break;
		case 2:
		    //output();		break;
		case 3:
		    printf("날짜와 일정을 입력하시오 : ");
		    scanf("%s %s",&day, &plan);
		    //input(day, plan);		break;
		case 4:
		    printf("반복되는 날짜와 일정을 입력하시오 : ");
		    scanf("%s %s",&re_day, &re_plan);
		    //recurringEvent(re_day, re_plan);	break;
		case 5:
		    printf("월경일을 입력하시오 (월 일) : ");
		    scanf("%d %d",&Men_month, &Men_day);
		    //Menstruation(Men_month, Men_day);	break;
		case 6:
		    return 0;
		default:
		    break;
	    }
	}	
    }
    else // res == 0
    {
	// exit or re-input
    }

    return 0;
}
