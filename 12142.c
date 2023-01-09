#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare(const void* a,const void* b){
  char ** va = (char**)a;
  char ** vb = (char**)b; 
  char c[3000];
  char d[3000];
  strcpy(c,(*va));
  strcat(c,(*vb));
  strcpy(d,(*vb));
  strcat(d,(*va));
  return strcmp(d,c);
}
char str[103][1005];
char* ptrs[103];
int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    for(int i=0;i<n;i++){
      scanf("%s", str[i]);
      ptrs[i] = str[i];
    }
    qsort(ptrs, n, sizeof(char *), compare);
    for (int i=0; i<n; ++i)
      printf("%s", ptrs[i]);
    printf("\n");
  }
}