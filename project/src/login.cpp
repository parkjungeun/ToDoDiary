#include <streamio>
#include <sys.stat.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc,char *argv[]){

   if(argc!=3){
      cout<<"parameter : ID PW"<<endl;
      exit(0);
   }
   string id="hy";
   string pw="1234";
   if(argv[1]==id){
      if(argv[2]==pw){
         while{
            //실행파일들이 모아져있는 디렉토리의 파일이름을 다 읽어올 동안 반복
            chmod();
         }
      }
   }


   return 0;
}
