#include <stdio.h>

char str;

int main(void){

    while(1){
        str = getchar();
        if(str == EOF) break;
        printf("%c",str);
    }

    return 0;
}
