//파일 경로만 추가하면 ㅇㅋㅇㅋ
#include <stdio.h>
#include <string.h>

#define buf 128

//year,month,day
void output(char *date){
	FILE *fp;
	char str[buf];
	fp=fopen("plan.txt","r");
	char readDate[9]={0,};
	if(strlen(date)==8){
		while(fgets(str,buf,fp)!=NULL){
			//날짜부분만 readDate에 넣고 strcmp로 비교
			strncpy(readDate,str,8);
			if(strcmp(readDate,date)==0){
				printf("%s\n",str);
			}
		}
	}
	else if(strlen(date)==6){
		while(fgets(str,buf,fp)!=NULL){
			strncpy(readDate,str,6);
			if(strcmp(readDate,date)==0){
				printf("%s\n",str);
			}
		}
	}
	fclose(fp);
}
