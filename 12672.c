#include <stdio.h>

int main(void){
    int A,B,C,SUM;
    scanf("%d%d%d",&A,&B,&C);
    SUM=(A+B+C)/2;
    printf("%d %d %d\n",SUM-B,SUM-C,SUM-A);
    return 0;
}