#include <stdio.h>
#include <string.h>

#define buf 128

//year,month,day
void output(char *date){
	FILE *fp;
	char str[buf];
	char saveStr[30][buf];
	int cnt=0;
	fp=fopen("plan.txt","r");
	char readDate[9]={0,};
	if(strlen(date)==4){
		while(fgets(str,buf,fp)!=NULL){
			//날짜부분만 readDate에 넣고 strcmp로 비교
			strncpy(readDate,str,4);
			if(strcmp(readDate,date)==0){
				strcpy(saveStr[cnt],str);
				cnt++;
			}
		}
	}
	else if(strlen(date)==6){
		while(fgets(str,buf,fp)!=NULL){
			strncpy(readDate,str,6);
			if(strcmp(readDate,date)==0){
				strcpy(saveStr[cnt],str);
				cnt++;
			}
		}
	}
	fclose(fp);
	int i;
	if(cnt==0){
		printf("\n\t\t일정이 없습니다.\n");
	}
	else{
		for(i=0;i<cnt;i++){
			printf("\t\t일정 %d : %s\n",i+1,saveStr[i]);
		}
	}

	char ch[2];
	printf("\n\t\t나가기 (press y) : ");
	while(1)
        {
            fflush(stdin);
            scanf("%s", ch);
	    if(strcmp(ch, "y") == 0)
		break;
	    else
		printf("\n\t\t나가기 (press y) : ");
        }
	return;
}
