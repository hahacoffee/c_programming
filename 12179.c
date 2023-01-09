#include <stdio.h>

int n,ans;

void queen(int row_now);
int check(int x,int y);

int col[50],cnt[50],cnt2[50];

int main(void)
{
    scanf("%i",&n);
    queen(0);
    printf("%i\n",ans);
    return 0;
}

int check(int x,int y){
    if(col[y] == 0 && cnt[x-y+15] == 0 && cnt2[x+y] == 0) return 1;
    else return 0;
}

void queen(int row_now){
    if(row_now == n) ans++;
    else{
        for(int y = 0;y<n;y++){
            if(check(row_now,y) == 1){
                col[y] = 1;
                cnt[row_now - y + 15] = 1;
                cnt2[row_now + y] = 1;
                queen(row_now + 1);
                col[y] = 0;
                cnt[row_now - y + 15] = 0;
                cnt2[row_now + y] = 0;
            }
        }
    }
}

