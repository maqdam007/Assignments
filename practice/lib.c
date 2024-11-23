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

slist *head = NULL;

void Create_list(void) {
    if(head == NULL) {
        head = (slist *)malloc(sizeof(slist ) * sizeof(int));
        if(head == NULL) {
            printf("Couldnot malloc\n");
            return;
        }
        printf("Cretaed list\n");
    }
}

void Delelement(void) {
    if(head == NULL) {
        printf("No list to search\n");
        return;
    }else {
        slist *ptr = head,*prev = NULL;
        int serial = 0;
        printf("Enter serial ID to be deleted\n");
        scanf("%d",&serial);
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
            printf("Could find the mentioned serial no.in list\n");
        }
    }
}

void AddelementLast(void) {
    slist *ptr = head;
    if(head == NULL) {
        head = (slist *)malloc(sizeof(slist ) * sizeof(int));
        if(head == NULL) {
            printf("Could not malloc\n");
            return;
        }

        slist *element = NULL;
        element = (slist *)malloc(sizeof(slist ) * sizeof(int));
        if(element == NULL) {
            printf("Couldnot malloc\n");
            return;
        }
        printf("Enter serial no:\n"); 
        scanf("%d",&(element->serial));
        getchar();
        printf("Enter Book Name:\n"); 
        scanf("%[^\n]",element->bName);
        getchar();
        printf("Enter Author Name:\n"); 
        scanf("%[^\n]",element->aName);
        getchar();
        printf("Enter Publisher Name:\n"); 
        scanf("%[^\n]",element->pubName);
        getchar();
        printf("Cretaed list\n");
        strcpy(head->bName, element->bName);
        strcpy(head->aName, element->aName);
        strcpy(head->pubName, element->pubName);
        head->serial = element->serial;
        free(element);
    }else {
        slist *element = NULL,*prev = NULL;

        element = (slist *)malloc(sizeof(slist ) * sizeof(int));
        if(element == NULL) {
            printf("Couldnot malloc\n");
            return;
        }
        while((ptr) && (ptr->serial >= element->serial)) {
            prev = ptr;
            ptr = ptr->next;
        }
        printf("Enter serial no:\n"); 
        scanf("%d",&(element->serial));
        getchar();
        printf("Enter Book Name:\n"); 
        scanf("%[^\n]",element->bName);
        getchar();
        printf("Enter Author Name:\n"); 
        scanf("%[^\n]",element->aName);
        getchar();
        printf("Enter Publisher Name:\n"); 
        scanf("%[^\n]",element->pubName);
        getchar();
        ptr = prev;
        if(ptr->next == NULL) {
            ptr->next = (slist *)malloc(sizeof(slist ) * sizeof(int));
            if(ptr == NULL) {
                printf("Couldnot malloc\n");
                free(element);
                return;
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
                free(element);
                return;
            }
            printf("Cretaed list\n");
            strcpy(str->bName, element->bName);
            strcpy(str->aName, element->aName);
            strcpy(str->pubName, element->pubName);
            str->serial = element->serial;
            str->next = ptr->next;
            ptr->next = str;
        }
        free(element);
    }
}

void printlist () {
    slist *ptr = head;
    while(ptr) {
        printf("Serial : %d\n",ptr->serial);
        printf("Book Name : %s\n",ptr->bName);
        printf("Author Name : %s\n",ptr->aName);
        printf("Publisher Name : %s\n",ptr->pubName);
        ptr = ptr->next; 
    }
}

int main() {
    //    slist *head;
    int op = 0;
    while(1) {

        printf("Enter the opration:\n");
        /*    printf("1.Create list\n2.Addelement First\n3.Addelement last\n4.Addelement
              After\n5.DeleteElement\n6.Print all the books\n");*/
        printf("1.Addelement \n2.DeleteElement\n3.Print all the books\n");
        scanf("%d",&op);

        switch(op) {

            case 1:
                AddelementLast();
                break;
            case 2:
                Delelement();
                break;
            case 3:
                printlist();
                break;
            default:
                break;

        }



    }

    return 0;    
}

























