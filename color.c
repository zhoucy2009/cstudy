#include <stdio.h>
#include <unistd.h>
void color_print(unsigned char fr, unsigned char fg, unsigned char fb, unsigned char br, unsigned char bg, unsigned char bb, char *s){
    printf("\033[38;2;%d;%d;%d;48;2;%d;%d;%dm%s\033[0m",fr,fg,fb,br,bg,bb,s);
}
int main(){
    for(int i=0;i<10;i++){
        color_print(255-i*20,i*20,0,0,0,0,"hello,world!\r");
        fflush(stdout);
        usleep(100000);
    }
}