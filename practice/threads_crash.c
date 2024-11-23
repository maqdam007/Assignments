#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;

void *my_func(void *args) {
    printf("Thread - %d\n",++count);
    if(count == 3) {
        printf("calling exit\n");
        exit(0);
    } /*else 
        sleep(5);*/
    printf("crashed proof count : %d\n",count);
}

int main() {
    pthread_t tid,tid2,tid3,tid4;
    pthread_create(&tid,NULL,&my_func,NULL);
    pthread_create(&tid2,NULL,&my_func,NULL);
    pthread_create(&tid3,NULL,&my_func,NULL);
    pthread_create(&tid4,NULL,&my_func,NULL);

    pthread_join(tid,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);
}
