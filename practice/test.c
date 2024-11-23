#include <stdio.h>
#include <stdlib.h>

typedef struct dlist {
    int data;
    struct dlist *next,*prev;
    } dlist;

dlist *head = NULL;


void Create_dlist(int data) {
    if(head == NULL) {
        head = (dlist *) malloc(sizeof(dlist) *sizeof(int));
        if(head == NULL) {
            printf("Malloc fail\n");
            return;
        }
        head->data = data;
        head->next = NULL;
        head->prev = NULL;
    } else {
        dlist * ptr = head;

        while(ptr->next) {
            ptr =ptr->next;
        }
       ptr->next =(dlist *) malloc(sizeof(dlist) *sizeof(int));
        if(ptr->next == NULL) {
            printf("Malloc fail\n");
            return;
        }
        ptr->next->data = data;
        ptr->next->next = NULL;
        ptr->next->prev = ptr;
    }
}

void delete_dlist (int data) {
    dlist *ptr = head, *str;
    int flag = 0;
    while(ptr) {
        if((ptr->data == data) && (ptr->next == NULL)) {
            ptr->prev->next = NULL;
            free(ptr);
            flag = 1;
        } else if (ptr->data == data) {
            if(ptr->prev == NULL) {
                ptr->next->prev = NULL;
                head = ptr->next;
                free(ptr);
            }else {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
            }
            flag = 1;
        }
        ptr = ptr->next;
    }
    if(flag == 0) {
        printf("could not find element\n");    
    }else
        printf("%d element deleted\n",data);    
}

void printdlist(void) {
    dlist *ptr =head;    
    while(ptr) {
        printf("data : %d\n",ptr->data);     
        ptr = ptr->next;
    }
}


int main() {
    int data = 3;
    Create_dlist(1);
    Create_dlist(2);
    Create_dlist(3);
    printdlist ();
    delete_dlist(data);
    printdlist ();

    return 0;
}
