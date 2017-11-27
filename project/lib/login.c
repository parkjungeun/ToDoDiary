#include "login.h"
#include <string.h>

int login(char *password){
	if(strcmp(password,"1234")==0) return 1;
	else return 0;
}
