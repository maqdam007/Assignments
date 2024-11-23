#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct slist {
    char bName[20];
    char aName[20];
    char pubName[20];
    int serial;
    struct slist *next;
} slist;

slist *head;

void Create_list(slist * head) {
    if(head == NULL) {
        head = (slist *)malloc(sizeof(slist ) * sizeof(int));
        if(head == NULL) {
            printf("Couldnot malloc\n");
            return;
        }
        printf("Cretaed list\n");
    }
}

slist *AddelementFirst(slist * head, slist *element) {
    slist *ptr = NULL;
    if(head == NULL) {
        head = (slist *)malloc(sizeof(slist ) * sizeof(int));
        if(head == NULL) {
            printf("Couldnot malloc\n");
            return NULL;
        }
        printf("Cretaed list\n");
        strcpy(head->bName, element->bName);
        strcpy(head->aName, element->aName);
        strcpy(head->pubName, element->pubName);
        head->serial = element->serial;
    }else {
        ptr = (slist *)malloc(sizeof(slist ) * sizeof(int));
        if(ptr == NULL) {
            printf("Couldnot malloc\n");
            return NULL;
        }
        printf("Cretaed list\n");
        strcpy(ptr->bName, element->bName);
        strcpy(ptr->aName, element->aName);
        strcpy(ptr->pubName, element->pubName);
        ptr->serial = element->serial;
        ptr->next = head;
        head = ptr;
    }
    return head;
}

void Delelement(slist *head, int serial) {
    if(head == NULL) {
        printf("No list to search\n");
        return;
    }else {
        slist *ptr = head,*prev = NULL;
        int flag = 0;
        while(ptr) {
            if(ptr->serial == serial) {
                prev->next = ptr->next;
                free(ptr);
                flag = 1;
                break;
            }
            prev = ptr;
            ptr = ptr->next;   
        }
        if(flag) {
            printf("Could not find the mentioned serial no.in list\n");
        }
    }
}

slist *AddelementLast(slist * head, slist *element) {
    slist *ptr = head;
    if(head == NULL) {
        head = (slist *)malloc(sizeof(slist ) * sizeof(int));
        if(head == NULL) {
            printf("Couldnot malloc\n");
            return NULL;
        }
        printf("Cretaed list\n");
        strcpy(head->bName, element->bName);
        strcpy(head->aName, element->aName);
        strcpy(head->pubName, element->pubName);
        head->serial = element->serial;
    }else {
        while((ptr) && (ptr->serial >= element->serial)) {
            ptr = ptr->next;
        }
        if(ptr->next == NULL) {
            ptr->next = (slist *)malloc(sizeof(slist ) * sizeof(int));
            if(ptr->next == NULL) {
                printf("Couldnot malloc\n");
                return NULL;
            }
            printf("Created list\n");
            strcpy(ptr->next->bName, element->bName);
            strcpy(ptr->next->aName, element->aName);
            strcpy(ptr->next->pubName, element->pubName);
            ptr->next->serial = element->serial;
        } else {
            slist *str = NULL;
            str = (slist *)malloc(sizeof(slist ) * sizeof(int));
            if(str == NULL) {
                printf("Couldnot malloc\n");
                return NULL;
            }
            printf("Cretaed list\n");
            strcpy(str->bName, element->bName);
            strcpy(str->aName, element->aName);
            strcpy(str->pubName, element->pubName);
            str->serial = element->serial;
            str->next = ptr->next;
            ptr->next = str;
        }
    }
    return head;
}


int main() {
//    slist *head;
    int op = 0,serial = 0;
    slist *element = NULL;

    element = (slist *)malloc(sizeof(slist ) * sizeof(int));
    if(element == NULL) {
        printf("Couldnot malloc\n");
        return 0;
    }
    while(1) {

        printf("Enter the opration:\n");
        /*    printf("1.Create list\n2.Addelement First\n3.Addelement last\n4.Addelement
              After\n5.DeleteElement\n6.Print all the books\n");*/
        printf("1.Create list\n2.Addelement \n3.DeleteElement\n4.Print all the books\n");
        scanf("%d",&op);

        switch(op) {

            case 1:
                head = Create_list(head);
                if(head == NULL) {
                    printf("Could not add element\n");
                }else {
                    printf("Added successfully\n");   
                }              
                break;
            case 2:

                printf("Enter serial no:\n"); 
                scanf("%d",&(element->serial));
                getchar();
                printf("Enter Book Name:\n"); 
                scanf("%[^\n]",element->bName);
                printf("Enter Author Name:\n"); 
                scanf("%[^\n]",element->aName);
                printf("Enter Publisher Name:\n"); 
                scanf("%[^\n]",element->pubName);
                head = AddelementLast(head,element);
                break;
            case 3:

                printf("Enter serial ID to be deleted\n");
                scanf("%d",&serial);
                Delelement(head,serial);
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;

        }



    }

    return 0;    
}

























