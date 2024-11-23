#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *ptr = NULL, *tmpPtr = NULL;

    ptr = (char *)malloc(16);
    if(ptr != NULL) {
        strcpy(ptr,"HelloWorld\0"); 
        printf("%s\n",ptr);
        tmpPtr = realloc(ptr,32);
        strcpy(tmpPtr,"Welcome to world\0"); 
        printf("%s\n",ptr);
        
        printf("%s\n",tmpPtr);
        ptr = tmpPtr;
        printf("%s\n",ptr);
        free(ptr);
    }

    return 0;    
}
