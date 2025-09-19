#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}*linkedList;


void initList(linkedList * A);
void insertLast(linkedList *A, int elem);
void display(linkedList A);
void deleteElem(linkedList *A, int elem);
void insertAtPosition (linkedList *A, int position, int elem);
void deleteAllOccur(linkedList *A, int elem);
void insertFirst(linkedList *A, int elem);

int main(){
    linkedList L;

    // initialize
    printf("Initializing list...\n");
    initList(&L);

    // populate with 10 elements
    printf("\nInserting 10 elements:\n");
    insertLast(&L, 1);
    insertLast(&L, 2);
    insertLast(&L, 3);
    insertLast(&L, 4);
    insertLast(&L, 5);
    insertLast(&L, 6);
    insertLast(&L, 7);
    insertLast(&L, 8);
    insertLast(&L, 8);
    insertLast(&L, 9);
    display(L);

    // delete the number 5
    printf("\nDeleting the number 5: \n");
    deleteElem(&L, 5);
    display(L);

    // insert in the 5th position
    printf("\nInserting at 5th position:\n");
    insertAtPosition(&L, 5, 69);
    display(L);


    // delete all occurences
    printf("\nDeleting all occurences of 8:\n");
    deleteAllOccur(&L, 8);
    display(L);

    // insert at first position
    printf("\nInserting 0 at first position:\n");
    insertFirst(&L, 0);
    display(L);

    return 0;
}


void initList(linkedList * A){
    *A = NULL;
}

void insertLast(linkedList *A, int elem){
    linkedList *ptr;
    for(ptr = A; *ptr != NULL; ptr = &(*ptr)->next){}
    (*ptr) = (linkedList) malloc (sizeof(struct node));
    (*ptr)->data = elem;
    (*ptr)->next = NULL;
}

void display(linkedList A){
    printf("\nCurrent List:\n");
    for(; A!=NULL; A = A->next){
        printf("\n%d", A->data);
    }
}


void deleteElem(linkedList *A, int elem){
    linkedList *ptr, temp;
    for(ptr = A; *ptr!=NULL && (*ptr)->data!=elem; ptr = &(*ptr)->next){}
    if(*ptr!=NULL){
        temp = *ptr;
        *ptr = temp->next;
        free(temp);
    }
}

void insertAtPosition (linkedList *A, int position, int elem){
    int i;
    linkedList *ptr = A;

    for(i = 0; *ptr != NULL && i < position-1; ptr = &(*ptr)->next){i++;}
    
    linkedList temp = (linkedList) malloc (sizeof(struct node));
        if (temp == NULL){
            printf("\nMemory Allocation Failed");
        }

    temp->data = elem;
    temp->next = *ptr;
    *ptr = temp;
}


void deleteAllOccur(linkedList *A, int elem){
    linkedList *ptr, temp;

    for(ptr = A; *ptr!=NULL;){
        if((*ptr)->data == elem){
            temp = *ptr;
            *ptr = temp->next;
            free(temp);
        }else{
            ptr = &(*ptr)->next;
        }
    }
}

void insertFirst(linkedList *A, int elem){
    linkedList temp = (linkedList) malloc (sizeof(struct node));
        if(temp == NULL){
            printf("\nMemory allocation failed");
        }
    temp->data = elem;
    temp->next = *A;
    *A = temp;
}