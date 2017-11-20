#include <stdio.h>
#include "kbhit.h"
#include "getch.h"

int main(){
   int key;
   int i;
   while(1){
      if(kbhit()){
         key=getch();
         if(key==119) printf("up\n");
         else if(key==97) printf("left\n");
         else if(key==100) printf("right\n");
         else if(key==115) printf("down\n");
         else if(key==113) return 0;
      }
   }
   return 0;
}
