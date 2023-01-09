#include <stdio.h>

int main(void){
    float x;
    int S[32];
    while(scanf("%f", &x)!=EOF){
        void *ptr = (void*)&x;
        int out = *((int*)ptr);
        if(out>=0){
           for(int i=0;i<32;i++){
            S[31-i]=out%2;
            out/=2;
            }
            for(int i=0;i<32;i++){
                printf("%i",S[i]);
            }
            printf("\n");
        }else if(out<0){
            out = ((-1)*out)-1;
            for(int i=0;i<32;i++){
            S[31-i]=out%2;
            out/=2;
            }
            for(int i=0;i<32;i++){
                if(S[i]==1){
                    S[i]=0;
                }
                else{
                    S[i]=1;
                }
                printf("%i",S[i]);
            }
            printf("\n");
        }

    }

    return 0;
}
