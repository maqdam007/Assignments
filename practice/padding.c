#include <stdio.h>

#pragma pack(push,1)

struct padding {
    char a;
    char b;
    double d;
    char c;
    int i;   
};
#pragma pack(pop)

struct padding_2 {
    char a;
    char b;
    double d;
    char c;
    int i;   
};

int main() {
   struct padding a;
   struct padding_2 b;

   printf("Size of struct with push %ld\n",sizeof(a)); 
   printf("Size of struct wo push %ld\n",sizeof(b)); 
   return 1; 
}
