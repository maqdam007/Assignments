#include <stdio.h>

int toggle(int num) {
    int temp = 1;

    while(temp <= num) {
        num= num^temp;
        temp = temp<<1;
    }

    return num;
}

int bittoggle(int num, int pos) {
    int mask = 1, bit = 0,result;

    bit = 1 << pos;
    result = num & bit;
    num=~num;
    bit = ~bit;
    num = num & bit;
    result = result | num;
    result = ~result;

    return result;
}

int main() {
    int num = 14;

    num = toggle(num);
    // num = bittoggle(15,2);
    printf("%d\n",num);

    return 0;
}
