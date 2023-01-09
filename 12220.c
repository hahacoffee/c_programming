#include <stdio.h>
long long int a[2000000];
int main(){
	int n,k,q,ans;
  long long int f;
  long long int max = 0;
  scanf("%d%d%d", &n, &k, &q);
  for(int i=0;i<n;i++){
    scanf("%lld", &a[i]);
    if(max < a[i])
      max = a[i];
  }
  while(q--){
    int L = 0;
    int R = n-1;
    scanf("%lld", &f);
    if(f > max)
      printf("gan ni nya sai bau\n");
    else{
      if (n==1)
        printf("%d\n",1);
      else{
        int flag = 0;
        
        while(1){
          int mid = (L+R)/2;
          if(f<a[L]){
            ans = L;
            break;
          }
          else if (f == a[mid]){
            ans = mid;
            break;
          }
          else if (mid == L){
            flag = 1;
            ans = mid+1;
            break;
          }
          else if(f > a[mid])
            L = mid;
          else if(f < a[mid])
            R = mid;
        }
        if(flag == 0){
          for(int i=ans-1;i>L;i--){
            if(a[i]==a[ans])
              ans = i;
            else
              break;
          }
        }
        if(a[ans] == a[k])
          ans = 0;
        else if(ans<k){
          ans = n-k+ans;
        }
        else if(ans >= k)
          ans -= k;
      }
      printf("%d\n", ans+1);
    }
  }
}