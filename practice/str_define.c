#include <stdio.h>
#include <stdlib.h>

#define file "/tmp/file.txt"

struct str {
    int a;
    int *ptr;
  };

int main() {

    FILE *fptr;
    struct str a;
    struct str *ptr;

    fptr = fopen(file,"r+");

    ptr = (struct str *) (malloc(sizeof(struct str) * sizeof(int)));

    a.a = 5;
    ptr->a = 10;

    printf("a : %d\n",a.a);
    printf("ptr ->a : %d\n",ptr->a);
   
    fclose(fptr);
    free(ptr);

    return 0; 
}
