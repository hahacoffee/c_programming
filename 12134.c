#include <stdio.h>

int main(void){

int x1,y1,x2,y2,xx,yy;

scanf("%d.%d%d.%d",&x1,&y1,&x2,&y2);

yy=(y1*y2+((x1*y2*100)%10000)+((x2*y1*100)%10000));
xx=(x1*x2+((x1*y2*100)/10000)+((x2*y1*100)/10000))+yy/10000;

printf("%d.%04d\n",xx,yy%10000);
return 0;

}
