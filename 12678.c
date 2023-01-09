#include <stdio.h>

long int t,ans,tans,a,b,X[1000001];

long int cal(long int x){
    ans=0;
    while(x){
        if(x%10 == 1) ans++;
        x/=10;
    }
    return ans;
}

int main(void){

    scanf("%li",&t);

    for(long int i =0;i<1000001;i++){
        X[i+1]=cal(i+1);
        X[i+1]=X[i+1]+X[i];
    }

    for(long int i =0;i<t;i++){
        scanf("%li%li",&a,&b);
        tans=X[b]-X[a-1];
        printf("%li\n",tans);
    }

    return 0;
}