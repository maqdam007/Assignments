#include <stdio.h>

extern int *ptr;

void func(void){
    *ptr = *ptr + 5;
    printf("static in different file is %d", *ptr);
}