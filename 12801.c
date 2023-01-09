#include <stdio.h>

int T,n,m,a[200001];

int page(int day){
    int code = 0;
    for(int i=0;i<day;i++){
        code += a[i];
    }
    int count = 0;
    int c = 1;
    for(int i=day;i<n;i++){
        count++;
        if(a[i]>c) code += (a[i]-c);
        if(count==day){
            count = 0;
            c++;
        }
    }

    return code;
}

int main(){
    scanf("%i",&T);
    for(int num=0;num<T;num++){
        scanf("%i%i",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%i",&a[i]);
        }
        int L = 1;
        int R = n+1;
        int ans = -1;
        while(L<R){
            int day =(L+R)/2;
            if(page(day)>=m){
                ans = day;
                R = day;
            }else{
                L = day + 1;
            }
        }
        printf("%i\n",ans);
    }
    return 0;
}
