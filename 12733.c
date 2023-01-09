#include <stdio.h>
#include <string.h>

int t;
long long int x,ADD,L,s_len,t_len,left;
long long int MOD = 1000000007;
char S[10000007];
char T[10000007];

int main(void){

    scanf("%d",&t);
    for(int test=0;test<t;test++){
        scanf("%lli",&x);
        scanf("%s",&S);
        L = strlen(S);
        s_len = L;
        for(long long int i=0;i<x;i++){
            left = (S[i]-'0')-1;
            ADD = (((L-(i+1))%MOD)*(left%MOD))%MOD;
            L = (L+ADD)%MOD;

            if(s_len <=x && (S[i]-'0') >1){
                long long int t = 0;
                for(long long int k=i+1;k<s_len;k++){
                    T[t]=S[k];
                    t++;
                }
                t_len = strlen(T);
                for(long long int j=0;j<left;j++){
                    if((s_len+t_len)<=x){
                        strcat(S,T);
                        s_len += t_len;
                    }else{
                        strcat(S,T);
                        s_len += t_len;
                        break;
                    }
                }
                memset(T, 0, t_len);
            }
            if(L<0) L+=MOD;

        }
        memset(S, 0, s_len);
        printf("%lli\n",L);
    }
    return 0;
}
