#include <stdio.h>

void merge(int A[],int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r -m;
    int L[n1],R[n2];

    int i,j,k;
    for(i = 0;i<n1;i++) {
        L[i] = A[i+l];
    }
    for(j =0 ;j<n2;j++) {
        R[j] = A[m+j+1];
    }

    i=0;j=0;k=l;

    while((i<n1) && (j<n2)){
        if(L[i] < R[j])
        {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        A[k++] = L[i++];
    }
    while(j<n2)
    {
        A[k++] = R[j++];
    }
}

void mergesort(int A[],int l,int r) {
    if(l<r) {
        int m = l+(r-l)/2;
        mergesort(A,l,m);
        mergesort(A,m+1,r);

        merge(A,l,m,r);
    }
}

int solution(int A[], int N) {
    int i, odd = 0, flag = 0;

    mergesort(A,0,N-1);

    for(i=0;i<N;i++) {
        if(A[i] == A[i+1]) {
            A[i] = A[i+1] = -1;
            ++i;
        } else {
            odd = A[i];
        }
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
