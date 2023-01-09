#include <stdio.h>

int n,X,MAX;
int COL[1002],ROW[1002];

int min(int a,int b){
    return a<b?a:b;
}

int max(int a,int b){
    return a>b?a:b;
}

int main(void){
    scanf("%i",&n);

    for(int i=0;i<n;i++){
        MAX = 0;
        for(int j=0;j<n;j++){
            scanf("%i",&X);
            MAX=max(X,MAX);
            if(i==0){
                COL[j]=X;
            }else{
                COL[j]=min(X,COL[j]);
            }
        }
        ROW[i] = MAX;
    }

    for(int i=0;i<n;i++){
        if(i==n-1){
            printf("%i\n",ROW[i]);
            break;
        }
        printf("%i ",ROW[i]);
    }
    for(int i=0;i<n;i++){
        if(i==n-1){
            printf("%i\n",COL[i]);
            break;
        }
        printf("%i ",COL[i]);
    }
    return 0;
}
