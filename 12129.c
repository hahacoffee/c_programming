#include <stdio.h>

int main(void){

int a,b;

scanf("%d%d",&a,&b);

if(a>b){
    if(b*2<=a){printf("%d %d\n",b,b*2);}

}else{
    if(a*2<=b){printf("%d %d\n",a,a*2);}
}

return 0;

}