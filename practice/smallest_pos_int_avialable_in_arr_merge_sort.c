#include <stdio.h>
void printArr(int A[],int N) {
    int i;

    for(i =0; i <N;i++) {
        printf("%d\n",A[i]);
    }
}

void merge(int A[],int l,int m, int r) {
    /*Initialinzing to with the length of left and right half*/
    int n1 = m - l +1;
    int n2 = r - m;

    int L[n1], R[n2]; //temp copying the left and right half

    int i,j,k;

    //Initializing the temp array for left half
    for(i=0;i<n1;i++) {
        L[i] = A[l+i];
    }

    //Initializing the temp array for right half
    for(j=0;j<n2;j++) {
        R[j] = A[m+j+1];
    }
    
    i = 0; k = l; j = 0; // Initializing so that i points to left half,
                        // j points to right half and k points to main array

    /*Compairing for length left out for left and right*/
    while(i < n1 && j < n2) {
        /*Compairing left and right half elements*/
        if(L[i] <= R[j]){
            A[k] = L[i]; //Copying the smaller element to main array.
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++; //pointing to main array element
    }

    /*Copying the remaining of left array to main*/
    while(i<n1) {
        A[k++] = L[i++];
    }
    /*Copying the remaining of right array to main*/
    while(j<n2) {
        A[k++] = R[j++];
    }
}

void mergesort(int A[], int l, int r) {
    
    //Dividing till elements becomes indiviuals
    if(l < r){
        //same as l+r/2, to avoid overflow of l and r for large values
        int m = l +(r - l)/2;

        mergesort(A,l,m); //divinding the array in left half 
        mergesort(A,m+1,r); //divinding the array in right half
        
        merge(A,l,m,r); //checking the element for greater and merging at correct place
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

