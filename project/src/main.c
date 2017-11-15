#include <stdio.h>

int main()
{
    int request=0, res=0;

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
		    calendar();		break;
		case 2:
		    //output();		break;
		case 3:
		    //input();		break;
		case 4:
		    //recurringEvent();	break;
		case 5:
		    //Menstruation();	break;
		case 6:
		    //return 0;
		default:
		    //break;
	    }
	}	
    }
    else // res == 0
    {
	// exit or re-input
    }

    return 0;
}
