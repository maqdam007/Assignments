#include <stdio.h>


int solution(int H[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int lar1 = 0, lar2 = 0, i = 0,j = 0, k = 0,smallest = 0;

    for(i=0;i<N;i++){
        if(lar1 < H[i]){
            lar1 = H[i];
        }
    }
    smallest = lar1 * N;
//    printf("Smallest %d\n",smallest);
    lar1 = 0;
    for(i=0;i<N;i++) {
        for(k = 0;k <= i; k++){
            if(lar1 < H[k]){
                lar1 = H[k];
            }
         //   printf("lar1 %d\n",lar1);
        }
        lar1 = k * lar1;
     //   printf("lar1 %d,%d\n",lar1,k);
        for (j=i+1;j<N;j++){
                if(lar2 < H[j]) {
                    lar2 = H[j];
                }
       //         printf("lar2 %d\n",lar2);
            }
        lar2 = (j - k)* lar2;
   //     printf("lar2 %d,%d\n",lar2,j);

        if(smallest > (lar1 + lar2)){
                smallest = lar1+lar2;
            }
        lar1=0;lar2=0;
 //       printf("Smallest %d\n",smallest);
    }
    printf("Smallest %d\n",smallest);

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

    printf("Smallest Area of blanket required : %d\n",solution(arr,N));
    
    return 0;    
}
