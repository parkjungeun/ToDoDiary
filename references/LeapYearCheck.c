#include<stdio.h>

int main()
{
    int year;
    int res;

    printf("Enter the year : ");
    scanf("%d",&year);

    res = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    if(res == 1)
	printf("%d is leapyear\n",year);
    else
	printf("%d isn't leapyear\n",year);

    return 0;
}
