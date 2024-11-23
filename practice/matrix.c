#include <stdio.h>


int main() {
    int arr[3][3] = {1,2,3,4,5,6,7,8,9},arr1[3][3] = {0}, i,j,k = 0,l = 0;

    printf("Enter data\n");
    /*
    for(i = 0;i<3;i++) {
        for(j=0;i<3;j++) {
            scanf("%d",&(arr[i][j]));
        }
    }*/
    for(i = 0;i<3;i++) {
        for(j=0;j<3;j++) {
            arr1[i][j] = arr[3-j-1][i];
        }
    }

    for(i = 0;i<3;i++) {
        for(j=0;j<3;j++) {
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
    
}
