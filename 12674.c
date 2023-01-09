#include <stdio.h>

long int t,r,g,b,ans,temp,cmpr,least;

int main(void){


    scanf("%li",&t);
    for(long int i =0;i<t;i++){
        scanf("%li%li%li",&r,&g,&b);
        if(r>g){temp=r;
                r=g;
                g=temp;}
        if(g>b){temp=g;
                g=b;
                b=temp;}
        if(r>g){temp=r;
                r=g;
                g=temp;}
        cmpr=(g+b-r)/2;
        if(cmpr>g){
            least=g;
        }else{
            least=cmpr;
        }
        ans=r+least;
        printf("%li\n",ans);
    }

    return 0;
}