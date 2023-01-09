#include <stdio.h>

long long int a[100005];
long long int b[100005];
long long int c[100005];
long long int n,k;

long long int sum;

void quicksort(long long int *arr, long long int low, long long int high,long long int *arr2,long long int *arr3)
{
  long long int pivot, x, j, temp , temp2 ,temp3;

  if(low < high) {
    pivot = low;
    x = low;
    j = high;
    while(x < j) {
      while(arr[x] <= arr[pivot] && x <= high)
        x++;
      while(arr[j] > arr[pivot] && j >= low)
        j--;
      if(x < j) {
        temp = arr[x];
        arr[x] = arr[j];
        arr[j] = temp;

        temp2 = arr2[x];
        arr2[x] = arr2[j];
        arr2[j] = temp2;

        temp3 = arr3[x];
        arr3[x] = arr3[j];
        arr3[j] = temp3;
      }
    }
    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;

    temp2 = arr2[j];
    arr2[j] = arr2[pivot];
    arr2[pivot] = temp2;

    temp3 = arr3[j];
    arr3[j] = arr3[pivot];
    arr3[pivot] = temp3;

    quicksort(arr, low, j-1,arr2,arr3);
    quicksort(arr, j+1, high,arr2,arr3);
  }
}

int main(){
  scanf("%lld%lld", &n, &k);
  for(long long int i=0;i<n;i++)
    scanf("%lld", &a[i]);
  for(long long int i=0;i<n;i++){
    scanf("%lld", &b[i]);
    c[i] = a[i]-b[i];
  }
  quicksort(c,0,n-1,a,b);
  sum = 0;
  for(long long int i=0;i<n;i++){
    if(i<k){
        sum+=a[i];
    }else if(c[i]<=0){
        sum+=a[i];
    }else{
        sum+=b[i];
    }
  }
  printf("%lld\n",sum);

}
