#include <stdio.h>
#include <string.h>

#define buf 128

//year,month,day
void output(char *date){
	FILE *fp;
	char str[buf];
	fp=fopen("(filename)","r");
	char readDate[9];
	//month TodoList
	if(strlen(date)==6){
		while(fgets(str,buf,fp)!=NULL){
                //날짜부분만 readDate에 넣고 strcmp로 findDate와 readDate 비교
                        if(strcmp(,)==0){
                                printf("%s\n",str);
                        }
                }
	}
	//day TodoList
	else if(strlen(date)==8){
		while(fgets(str,buf,fp)!=NULL){
		//날짜부분만 readDate에 넣고 strcmp로 findDate와 readDate 비교
			if(strcmp(,)==0){
				printf("%s\n",str);
			}
		}
	}
	fclose(fp);
}
