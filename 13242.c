#include <stdio.h>

#define SIZE 200001

long long int T,n,m,a[SIZE],L,R,ans,day;

long long int maxcode(long long int d){
    long long int code = 0;
    long long int count = 0;
    long long int penalty = 0;

    for(long long int i=0;i<n;i++){
        if(a[i]>penalty){
            code = code + a[i] - penalty;
        }
        count++;
        if(count==d){
            count = 0;
            penalty++;
        }
    }

    return code;
}

void Quicksort(long long int A[SIZE],long long int left,long long int right){
    long long int ll = left;
    long long int rr = right;
    long long int p = A[(ll+rr)/2];
    while(ll <=rr){
        while(A[ll]>p){
            ll++;
        }
        while(A[rr]<p){
            rr--;
        }
        if(ll<=rr){
            long long int temp;
            temp=A[ll];
            A[ll]=A[rr];
            A[rr]=temp;
            ll++;
            rr--;
        }
    }
    if(rr>left) Quicksort(A,left,rr);
    if(ll<right) Quicksort(A,ll,right);
}

int main(){
    scanf("%i",&T);
    for(int num=0;num<T;num++){

        scanf("%lli%lli",&n,&m);
        for(long long int i=0;i<n;i++){
            scanf("%lli",&a[i]);
        }

        Quicksort(a,0,n-1);

        L = 1;
        R = n+1;
        ans = -1;

        while(L<R){
            day =(L+R)/2;
            if(maxcode(day)>m){
                ans = day;
                R = day;
            }else{
                L = day + 1;
            }
        }
        printf("%lli\n",ans);
    }
    return 0;
}
