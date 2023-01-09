#include <stdio.h>
#define SIZE 301

int T,n,q,temp;
int S[3][SIZE];
int W[SIZE],P[SIZE];

void Prefix(int *T,int x){
    if(x == 0){
        for(int i=1;i<SIZE;i++){
            if(T[i]==1){
                P[i]=P[i-1]+1;
            }else{
                P[i]=P[i-1];
            }
        }
    }else{
        for(int i=0;i<SIZE;i++){
            P[i]=0;
        }
    }

}

int range(int a,int b){

    int TW[SIZE];
    int max = 0;
    int min = 32767;

    for(int i=0;i<=n;i++){
        TW[i] = W[i];
    }

    for(int i = S[0][a];i<=S[1][a];i++){
        TW[i]--;
    }
    for(int i = S[0][b];i<=S[1][b];i++){
        TW[i]--;
    }

    for(int i=0;i<=n;i++){
        if(TW[i]>0) max++;
    }

    Prefix(TW,0);

    for(int i=0;i<q;i++){
        if(i!=a && i!=b && min>(P[S[1][i]] - P[(S[0][i]-1)]) ) {
            min = (P[S[1][i]] - P[(S[0][i]-1)]);
        }
    }

    Prefix(TW,1);

    return max - min;
}

int main(){

    scanf("%i",&T);

    for(int num = 0;num <T;num++){

        int ans = 0;
        scanf("%i%i",&n,&q);
        for(int i =0;i<q;i++){
            scanf("%i%i",&S[0][i],&S[1][i]);
            for(int j=S[0][i];j<=S[1][i];j++){
                W[j]++;
            }
        }


        for(int i=0;i<q-1;i++){
            for(int j =i+1;j<q;j++){
                temp = range(i,j);
                if(ans<temp){
                    ans = temp;
                }
            }
        }
        printf("%i\n",ans);
        for(int i=0;i<SIZE;i++){
            W[i]=0;
        }
    }
    return 0;
}
