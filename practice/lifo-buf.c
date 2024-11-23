#include <stdio.h>
#include <string.h>

//#define BUFFER 500
#define BUFFER 50

int iLen = 0, iFront = -1, iShift = 0;
char pszStr[BUFFER] = {0};

void enQstr(char *psStr) {
    int i = 0; 

    iLen = strlen(psStr);
    i = iLen;
    printf("Len(%s) : %d\n",psStr, iLen);

    if(iFront == -1) {
        strcpy(pszStr,psStr);
        iFront = iLen;
    } else {
        iShift = iFront;
        iFront = iFront + iLen;
        while(--iShift >= 0) {
            if (iLen + iShift < BUFFER) {
                pszStr[iLen + iShift] = pszStr[iShift];
            }
        }

        while(--i >= 0) {
            pszStr[i] = psStr[i];     
        }
    }
    printf("Total Buffer : %d\nLast Buff : %d\n",iFront, iLen);
}

int main() {
    char ch = '\0',psStr[BUFFER] = {0};
    int i = 0;

    while(1) {
        printf("1.Enter string : \t2.Print buffer : \n");
        scanf("%d",&i);
        getchar();
        if(i == 1) {
            printf("Enter the string : \n");
            scanf("%[^\n]",psStr);
            getchar();
            enQstr(psStr);
        } else {
            printf("Buffer : %s\n",pszStr);
        }
        printf("Do you want to continue(Y/y)?");
        ch = getchar();
        getchar();
        printf("%c\n",ch);
        if(!((ch == 'y') || (ch == 'Y'))) { 
            break;     
        }
    }
    return 0;
}
