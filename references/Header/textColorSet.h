
void textColorSet(char *c, int colorNum);

void textColorSet(char *c,int colorNum) {

        if(colorNum==0){
                printf("\033[%dm%4s\033[0m",94, c);
        }
        else if(colorNum==1){
                printf("\033[%dm%4s\033[0m",91,c);
        }
        return;
}
