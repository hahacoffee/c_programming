#include <stdio.h>

long long int n,q,l,r,ans;
long long int A[1000005];

int main(void){
    scanf("%lli%lli",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%lli(/`A`)/ ~I__I",&A[i]);
        if(i!=0){
            A[i]=A[i]+A[i-1];
        }
    }

    for(int i=0;i<q;i++){
        scanf("%lli%lli",&l,&r);
        if(l>1){
            ans=A[r-1]-A[l-2];
        }else{
            ans=A[r-1];
        }
        printf("%lli\n",ans);
        ans=0;
    }
    return 0;
}