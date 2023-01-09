#include <stdio.h>

int N,ans,temp;
int A[1001];
int gcd(int a,int b);

int main(void){
    scanf("%i",&N);
    for(int i=0;i<N;i++){
        scanf("%i",&A[i]);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j!=i){
                temp = gcd(A[i],A[j]);
                if(ans<temp) ans = temp;
            }
        }
    }

    printf("%i\n",ans);
    return 0;
}

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
