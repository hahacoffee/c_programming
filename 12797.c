#include <stdio.h>
#define SIZE 100002

long long int P[SIZE];
long long int T,A,B,C,D,sum;

void Prefix(){
    for(long long int i=1;i<SIZE;i++){
        P[i]=P[i-1]+P[i];
    }
}

int main(void){
    scanf("%lld",&T);
    for(long long int k=0;k<T;k++){
        scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
        for(long long int x=A;x<=B;x++){
            P[x+B]++;
            P[x+C+1]--;
        }
        Prefix();
        Prefix();
        sum=0;
        for(long long int z=C;z<=D;z++){
            sum+=P[SIZE-1]-P[z];
        }
        printf("%lld\n",sum);
        for(long long int j=0;j<SIZE;j++){
            P[j]=0;
        }
    }
    return 0;
}
