#include <stdio.h>

int X,now,start,last,broke,sum;

int main(void){

    scanf("%d%d",&X,&broke);

    for(int i=0;i<X;i++){

        scanf("%d",&now);

        if(now-start>broke){
            start = last;
            sum++;
        }else if(now-start==broke){
            start = now;
            if(i!=X-1) sum++;
        }

        if(now-start>broke){
            printf("The Legend Falls.\n");
            break;
        }

        if(i==X-1){
            printf("%d\n",sum);
        }

        last = now;
    }

    return 0;
}
