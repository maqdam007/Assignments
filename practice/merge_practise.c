#include <stdio.h>

void printArr(int A[], int N) {
    int i =0;
    for(i = 0;i< N; i++) {
        printf("%d ",A[i]);       
    }
    printf("\n");
}

void merge (int A[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    
    int i,j,k,L[n1],R[n2];

    for(i=0;i<n1;i++){
        L[i] = A[l+i];
    }
    for(j=0;j<n2;j++){
        R[j] = A[m+1+j];
    }
    i=0,j=0,k =l;
    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1) {
        A[k++] = L[i++];
    }
    while(j<n2) {
        A[k++] = R[j++];
    }
}

void mergesort (int A[],int l, int r) {
    if(l<r) {

        int m = l+(r-l)/2;

        mergesort(A,l,m);
        mergesort(A,m+1,r);
        
        merge(A,l,m,r);
    }
}

/*Solution to find smallest missing integer in arr*/
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i, smallest = 1, negflag = 0;

    mergesort(A,0,N-1);

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
    printArr(arr,N);

    printf("Smallest element : %d\n",solution(arr,N));
    
    printArr(arr,N);

    return 0;    
}
