#include <stdio.h>

long int max(long int a,long int b)
{
    return a>b?a:b;
}

long int min(long int a,long int b)
{
    return a<b?a:b;
}

long int t,n,m,k,ans,head,tail;
long int temp,X[5001];

int main(void){

    scanf("%li",&t);

    for(long int num=0;num<t;num++){

        ans = 0;
        scanf("%li%li%li",&n,&m,&k);

        if(k>(m-1)){
            k=m-1;
        }

        for(long int i=0;i<n;i++){
            scanf("%li",&X[i]);
        }

        long int *ptr1=X;
        long int *ptr2=X+(n-1);
        long int *ptrt1,*ptrt2;


            for(long int j=0;j<=k;j++){

                ptrt1=ptr1+j;
                ptrt2=ptr2-(k-j);
                temp = 1000000001;
                for(long int l=0;l<=(m-k-1);l++){

                    head = *(ptrt1+l);
                    tail = *(ptrt2-((m-k-1)-l));
                    temp=min(max(head,tail),temp);

                }
                ans = max(ans,temp);
            }

        printf("%li\n",ans);

    }

    return 0;
}

