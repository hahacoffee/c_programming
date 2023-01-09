#include "function.h"

int BS(int* a, int target, int len){
    int L = 0;
    int R = len-1;
    int mid = 0;
    int answer = 0;
    while(L<R){
        mid = L+((R-L+1)/2);
        if(a[mid]>target) R = mid;
        else if(a[mid]< target) L = mid;
        else if(a[mid]== target){
            answer = mid;
            break;
        }
        if((R-L+1)/2==1){
            mid = L;
            if(a[mid]== target){
                answer = mid;
                break;
            }
        }
    }
    return answer;
}
