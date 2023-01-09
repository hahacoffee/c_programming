#include <stdio.h>

char C;
int N,pointer,num;
int S[26];

int main(void){
    scanf("%d",&num);
    if(num>1){
        getchar();
        while(C=getchar()){
            if(C=='\n') break;
            N=C-'a';
            if(S[N]!=1){
                S[N]=1;
            }else{
                pointer=1;
            }

        }
    }else{
        getchar();
        pointer=1;
    }

    if(pointer){
        printf("I'm the god of Knuckles!\n");
    }else{
        printf("Different makes perfect\n");
    }

    return 0;
}
