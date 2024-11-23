#include <stdio.h>
void printArr(int A[],int N) {
    int i;

    for(i =0; i <N;i++) {
        printf("%d\n",A[i]);
    }
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}

void sort(int A[], int N){
    int i,j;
    for(i=0;i<N-1;i++){
        for(j=0; j<N-i-1; j++)
            if(A[j] > A[j+1])
                swap(&A[j],&A[j+1]);
    }
}
/*Solution to find smallest missing integer in arr*/
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i, smallest = 1, negflag = 0;

    sort(A,N);

    for(i = 0; i < N; i++){

        if((smallest >= A[i]) ){
            smallest = A[i] + 1;
        }
        if(A[i] > 0)  { 
            negflag = 1;
        }
    }
    if(negflag == 0){
        return 1;
    }
    return smallest;
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

    printf("Smallest element : %d\n",solution(arr,N));
    
    return 0;    
}
