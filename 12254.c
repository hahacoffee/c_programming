#include <stdio.h>

long long int max = 1e9 + 7;

typedef struct{
    long long int m[3][3];
}matrix;


matrix create(){
    matrix M;
    M.m[0][0] = 1;
    M.m[0][1] = 2;
    M.m[0][2] = 1;
    M.m[1][0] = 1;
    M.m[1][1] = 0;
    M.m[1][2] = 0;
    M.m[2][0] = 0;
    M.m[2][1] = 1;
    M.m[2][2] = 0;
    return M;
}

matrix mul(matrix a, matrix b){
    matrix ans;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans.m[i][j] = 0;
            for(int k=0;k<3;k++)
                ans.m[i][j] += (a.m[i][k] * b.m[k][j])%max;
            ans.m[i][j] %= max;
        }
    }
    return ans;
}

matrix fpw(long long int x){
    if(x==1)
        return create();
    matrix half = fpw(x/2);
    if(x%2 == 0)
        return mul(half,half);
    return mul(mul(half,half),create());
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long int x;
        scanf("%lld", &x);
        if(x == 1)
            printf("%d\n", 1);
        else if(x == 2)
            printf("%d\n", 12);
        else if(x == 3)
            printf("%d\n", 13);
        else{
            matrix ans = fpw(x-3);
            printf("%lld\n", (ans.m[0][0]*13 + ans.m[0][1]*12 + ans.m[0][2]*1)%max );
        }
    }
    return 0;
}
