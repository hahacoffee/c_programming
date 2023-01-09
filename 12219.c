#include <stdio.h>

long long int fpw(long long int x,long long int y,long long int m){
    long long int res;
    if(y==0){
        if(m == 1){
            return 0;
        }else{
            return 1%m;
        }
    }
    res = fpw(x,y/2,m);
    res=((res%m)*(res%m))%m;
    if(y%2==1){
        res=((res%m)*(x%m))%m;
    }
    return res%m;
}

long long int XX,YY,MM,ANS;

int main(void){
    scanf("%lli%lli%lli",&XX,&YY,&MM);
    ANS = fpw(XX,YY,MM);
    printf("%lli\n",ANS);
    return 0;
}
