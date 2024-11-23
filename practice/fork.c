#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

pid_t childPid = 0;
pid_t parentPid = 0; 

int main () {
    int ret;
    ret = fork();
    if (ret == 0) {
        printf("child\n");
    } else {
        printf("parent\n");
    }
    return 0;
}