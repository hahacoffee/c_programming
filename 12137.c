#include<stdio.h>

int n;
long int ans,an,k,A[21];

long int num(long int id,long int sum);

int main(void){

    scanf("%d%li",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%li",&A[i]);
    }
    printf("%li\n",num(0,0));
    return 0;
}

long int num(long int id,long int sum){
    if(sum == k){
        return 1;
    }
    else if( (id>(n-1)) || (sum>k) ){
        return 0;
    }
    else{
        return (num(id+1,sum+A[id])+num(id+1,sum));
    }
}
