#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_lock(&myMutex)
pthread_mutex_unlock(&myMutex);

int compute_closest_to_zero(int n, int ts[n])
{
    // Write your code here
    // To debug: fprintf(stderr, "Debug messages...\n");'
    int i = 0, posSmallest = -1, negSmallest = ts[0];

    if((n == 0) || ((n != 0) && (ts == NULL))) {
        printf ("Here - 1 %d\n", n);
        return 0;
    } else {
        if(n == 1)
            return ts[0];
        for(i = 0; i < n; i++){
            printf ("ts[%d] : %d\n", i, ts[i]);
            if(ts[i] == 0) {
                printf ("Here - 2 %d\n", ts[i]);
                return 0;
            }
            else if ((ts[i] < 0) && ( ts[i] > negSmallest)) {
                printf ("Here - 3 %d\n", ts[i]);
                negSmallest = ts[i];
            } else if (ts[i] > 0) {
                if(posSmallest == -1)
                    posSmallest = ts[i];
                else if(ts[i] < posSmallest) {
                    printf ("Here - 4 %d\n", ts[i]);
                    posSmallest = ts[i];
                }
            }
        }
        if(posSmallest != -1) {
            if(posSmallest == abs(negSmallest)) {
                printf ("Here - 5 %d\n",posSmallest);
                return posSmallest;
            } else {
                if(posSmallest > abs(negSmallest)) {
                    printf ("Here - 6 %d\n",negSmallest);
                    return negSmallest;
                } else  {
                    printf ("Here - 7 %d\n",posSmallest);
                    return posSmallest;
                }
            }
        } else 
            return negSmallest;
    }
    return -1;
}

/* Ignore and do not change the code below */\
int main()
{
    int n;
    scanf("%d", &n);
    int ts[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ts[i]);
    }
    int std_out_fd = dup(1);
    dup2(2, 1);
    int solution = compute_closest_to_zero(n, ts);
    dup2(std_out_fd, 1);
    printf("%d\n", solution);

    return 0;
}
/* Ignore and do not change the code above */