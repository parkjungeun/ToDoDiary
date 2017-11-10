//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <time.h>
#include <Windows.h>

void setColor(unsigned short text,unsigned short back){
   SetConsoleTextAttribute(GetStdHandle(STD_OUPUT_HANDLE),text|(back<<4));
}

int main(){
   int i;
   srand(time(0));
   for(i=0;i<16;i++){
      unsigned short text = reand()%16;
      unsigned short back = rand()%16;

      setColor(text,back);
      printf("SetColor(%d,%d)\n",text,back);
   }
   return 0;
}
