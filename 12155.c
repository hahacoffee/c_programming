#include <stdio.h>
int pt[2000][2];
int visited[2000]={0};
int n, r, ans1, ans2;
void dfs(int now){
  int flag = 0;
  visited[now] = 1;
  for(int i=0;i<n;i++){
    int dis = (pt[now][0]-pt[i][0])*(pt[now][0]-pt[i][0])+(pt[now][1]-pt[i][1])*(pt[now][1]-pt[i][1]);
    if(dis <= r*r && i!=now){
      flag++;
      if(visited[i] != 1)
        dfs(i);
    }
  }
  if(flag == 0)
    ans1++;
}
int main(){
  scanf("%d%d", &n, &r);
  for(int i=0;i<n;i++)
    scanf("%d%d", &pt[i][0], &pt[i][1]);
  for(int i=0;i<n;i++){
    if(visited[i] == 0){
      ans2++;
      dfs(i);
    }
  }
  printf("%d %d\n", ans1, ans2-ans1);
}