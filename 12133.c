#include<stdio.h>

char A[100001],B[100001];
int judge(char a[],char b[],int al,int ar,int bl,int br){
    if(is_equal(a,b,al,ar,bl,br)){
        return 1;
    }
    else if((ar-al)%2==1){
        return 0;
    }
    else if((br-bl)%2==1){
        return 0;
    }
    else{
        int amid,bmid;
        amid = (al+ar)/2;
        bmid = (bl+br)/2;
        if(judge(a,b,al,amid,bl,bmid) && judge(a,b,amid,ar,bmid,br)) {
            return 1;
        }else if(judge(a,b,al,amid,bmid,br) && judge(a,b,amid,ar,bl,bmid)) {
            return 1;
        }else{
            return 0;
        }

    }
}

int is_equal(char x[],char y[],int xl,int xr,int yl,int yr){

    int s1=(xr-xl);
    int s2=(yr-yl);
    if(s1!=s2){
        return 0;
    }
    else{
        for(int i=0;i<s1;i++){
            if(x[xl+i]!=y[yl+i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void){
    scanf("%100000s",&A);
    scanf("%100000s",&B);
    if(judge(A,B,0,strlen(A),0,strlen(B))) {
        printf("YES\n");
    }
    else printf("NO\n");
    return 0;
}
