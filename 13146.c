#include <stdio.h>

int main(void){

    double a,b;
    int z;

    scanf("%lf%lf%d",&a,&b,&z);

    printf("%.*lf\n",z,a*b);

    return 0;
}