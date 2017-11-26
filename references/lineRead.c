#include <stdio.h>
#include <string.h>

#define buf 128

int main(){
	FILE *fp;
	char str[buf];
	fp=fopen("(filename)","r");
	fgets(str,buf,fp);
	//printf("%s",str);
	//fgets(str,buf,fp);
	//printf("%s",str);

	fclose(fp);

	return 0;
}
