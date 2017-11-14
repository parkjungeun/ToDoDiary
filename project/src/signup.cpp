// ~$ signup ID PW
//#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>
using namespace std;

#define USER_PATH "~/ToDoDiary/project/userInfo/"

int main(int argc,char *argv[]){ 
   int idfd;
   int pwfd;
   if(argc != 3){
      cout<<"parameter : ID PW"<<endl;
      exit(0);
   }
   idfd=open("~/ToDoDiary/project/userInfo/userID.txt",O_WRONLY|O_TRUNC);
   write(idfd,argv[1],sizeof(argv[1]));
   close(idfd);
   pwfd=open("~/ToDoDiary/project/userInfo/userPW.txt",O_WRONLY|O_TRUNC);
   write(idfd,argv[2],sizeof(argv[2]));
   close(pwfd);
   cout<<"OK"<<endl;
}

