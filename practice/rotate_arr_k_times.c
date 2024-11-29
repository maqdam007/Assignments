#include <stdio.h>

struct Results {
    int * A;
    int N; // Length of the array
};

/*Rotate a array k times to right and replace first element with last after each loop*/
struct Results solution(int A[], int N, int K) {

    int i,last = 0,next = 0, prev = 0;
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    result.A = A;
    result.N = N;

    while(K--){
        last = A[N-1];
        prev = A[0];
        for(i = 1; i < N;i++) {
            next = A[i];
            A[i] = prev;
            prev = next;
        }
        A[0] = last;
    }

    return result;
}

int main() {
    int N,K;
    printf("Enter arr length:");
    scanf("%d",&N);
    
    printf("Enter rotation times:");
    scanf("%d",&K);
    
    int i,arr[N];
    struct Results result;

    printf("\nEnter arr elements:\n");
    for(i = 0; i < N; i++) {
        scanf("%d",&arr[i]);
    }

    result = solution(arr,N,K);

    for(i=0;i<N;i++){
        printf("%d ",result.A[i]);    
    }
    printf("\n");
    return 0;    
}
