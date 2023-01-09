#include <stdio.h>

long long int n,numC,Accu,p,count;
long long int A[200001][4];

int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i][0]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&A[i][1]);
    }
    for(int i=0;i<n;i++){
            for(int k=0;k<numC;k++){
                if(A[k][2]==A[i][1]){
                    A[i][3]=0;
                    count = 1;
                    break;
                }
            }
        if(count == 0){
           for(int j=p;j<n;j++){
                if(A[j][0]==A[i][1]){
                    p=p+Accu+1;
                    A[i][3]=Accu+1;
                    Accu=0;
                    break;
                }else{
                    A[numC][2]=A[j][0];
                    Accu++;
                    numC++;
                }
            }
            if(A[i][1]==A[n-1][0]){break;}
        }
        count=0;
    }

    for(int i=0;i<n-1;i++){
        printf("%d ",A[i][3]);
    }
    printf("%d\n",A[n-1][3]);

    return 0;
}
