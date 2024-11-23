#include <stdio.h>
#include<pthread.h>

int gvar = 10;

void *myfunc2(void *lvar) {
    int i = *((int *)lvar);
    printf("Gvar :%d\n",gvar);
    printf("lvar :%d\n",i);
}

void *myfunc1(void *lvar) {
    int *i = lvar;
    printf("Gvar :%d\n",gvar);
    printf("lvar :%d\n",*i);
}


int main() {
   pthread_t tid1,tid2;
   int lvar = 10;

    pthread_create(&tid1, NULL, myfunc1,(void *)&lvar);
    pthread_create(&tid2, NULL, myfunc2,(void *)&lvar);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    return 0;    
}
