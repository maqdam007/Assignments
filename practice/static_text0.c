#include <stdio.h>

void func(void);

int *ptr;
int main(){
    static int a = 5;
    ptr = &a;
    //*ptr = *ptr + 5;
    func();
    printf("static in different file is %d", *ptr);
}