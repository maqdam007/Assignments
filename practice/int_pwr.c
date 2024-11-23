#include <stdio.h>

int power(int num) {
    while(num != 1) {
        if(num %2 != 0)
            return 0;
            
        num = num/2;
    }    
   return 1; 
}

int main() {
    int num = 60, result;
    
    result = power(num);
    if(result == 0)
        printf("No\n");
    else 
        printf("Yes\n");
    return 0;
}
