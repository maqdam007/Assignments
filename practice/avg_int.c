#include <stdio.h>

int main() {
    int a = 10, b=11, avg, n=2,carry =0;
    //avg = (a+b)/n;
    
    if((a%n) > 0 &&  (b%n) > 0) {
        carry = 1;   
    } 
    avg = (a/n) + (b/n) + carry;
    printf("%d\n",avg);
    return 0;
}
