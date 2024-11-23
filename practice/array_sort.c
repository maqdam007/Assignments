#include <stdio.h>

int main() {
//    int arr[] = {0,1,0,1,0,1,0,1};   
    int arr[] = {0,1,1,1,0,1,0,1};   
    int i = 0, n=8;
    int h = n-1, l=0;

    if (arr[l] == 0) {
        l++;
    }
    for(i=0; i < n;i++) {
        if(arr[i] > arr[i+1]) {
            arr[l] = 0;
            arr[i+1] = 1;
            l++;
        } 
    }
    
    for(i =0;i<n;i++) {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}
