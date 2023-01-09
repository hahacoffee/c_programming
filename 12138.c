#include <stdio.h>
long int n,q,m,l,r,ans,val[1000000];
int main(void){

    scanf("%li%li",&n,&q);
    for(long int i =0;i<n;i++){
        scanf("%li",&val[i]);
        if(val[i]<0){val[i]=0;}
        if(i!=0){
            val[i]=val[i]+val[i-1];
        }
    }

    for(long int i=0;i<q;i++){
        scanf("%li%li%li",&l,&r,&m);
        ans = val[l+m-2]-val[l-2];
        printf("%li\n",ans);
        ans=0;
    }
    return 0;
}