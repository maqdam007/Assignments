#include <stdio.h>

void print(int A[], int N) {
    int i;
    for(i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    /*
     *a = *a + *b;
     *b = *a - *b;
     *a = *a - *b;*/

}

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
   array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 

    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i],&arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return(i+1); 
} 

/*
   int partition(int A[], int l, int r){
   int pivot = A[l];

   while(l <= r) {
   while(A[l] < pivot && l <= r) {
   l++;
   }
   while(A[r] > pivot && l <= r) {
   r--;
   }
   if (l < r){
   swap(&A[l],&A[r]);
   }
   l++;r--;
   }

   return l;    
   } */

void quicksort (int A[], int l, int r){
    int split;
    if(l < r) {
        split = partition(A,l,r);
        quicksort(A,l,split-1);
        quicksort(A,split,r);
    }
}

int solution(int A[], int N) {
    int i, odd = 0, flag = 0;

    print(A,N);
    quicksort(A,0,N-1);
    print(A,N);

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
