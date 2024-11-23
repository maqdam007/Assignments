#include <stdio.h>

/*Solution find odd or unpaired num in arr */
int solution(int A[], int N) {
    int odd = 0, i = 0,j = 0,flag = 0;

    for(i = 0; i < N; i++) {
        if(A[i] == -1)
            continue;
        odd = A[i];
        flag = 0;
        for (j=i+1; j < N; j++){
            if(A[j] == -1)
                continue; 
            if(A[j] == odd){
                flag = 1;
                A[i] = -1;
                A[j] = -1;
                break;
            }
        }
        if(flag == 0)
            break;
    }
    return odd;
}

int main() {
    int N;
    printf("Enter arr length:");
    scanf("%d",&N);
    int i,arr[N];

    printf("\nEnter arr elements:\n");
    for(i = 0; i < N; i++) {
        scanf("%d",&arr[i]);
    }

    printf("Odd element : %d\n",solution(arr,N));
    
    return 0;    
}

