#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct{
    int *arr;
    int count;
} numList;

void initList(numList *A);
void insertLast (numList *A, int elem);
void display (numList A);
void deleteElem (numList *A, int elem);
void insertAtPosition (numList *A, int position, int elem);
void deleteAllOccur(numList *A, int elem);
void insertFirstPosition (numList *A, int elem);

int main() {
    numList L;

    // initiate
    initList(&L);
    printf("Initiating list...\n");

    // populate with 10 elements (insertLast)
    printf("\nInserting 10 elements.\n");
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

    // delete the number 7
    printf("\nDeleting the number 7:\n");
    deleteElem(&L, 7);
    display(L);

    // insert in the 7th position
    printf("\nInserting at the 7th position:\n");
    insertAtPosition(&L, 6, 67);
    display(L);

    // delete all occurences of the number 8
    printf("\nDeleting all occurences of 8:\n");
    deleteAllOccur(&L, 8);
    display(L);

    // insert the number 0 in the first position
    printf("\nInserting the number 0 in the first position:\n");
    insertFirstPosition(&L, 0);
    display(L);

    return 0;
}

void initList(numList *A){
    A->count = 0;
    A->arr = (int *) malloc (sizeof(int)*SIZE);
    if (A->arr == NULL){
        printf("Malloc Failed");
    }
}


void insertLast (numList *A, int elem){
    A->arr[A->count++] = elem;
}

void display (numList A){
    int i;
    printf("\nCurrent List:\n");
    for(i = 0; i < A.count; i++){
        printf("\n%d", A.arr[i]);
    }
    
}

void deleteElem (numList *A, int elem){
    int i, j;
    for (i = 0; i < A->count; i++){
        if (elem == A->arr[i]){
            for(j = i; j < A->count-1; j++){
                A->arr[j] = A->arr[j+1];
            }
        }
    }
    A->count--;
}


void insertAtPosition (numList *A, int position, int elem){
    int i;

    for (i = A->count; i > position; i--){
        A->arr[i] = A->arr[i-1];
    }
    A->count++;
    A->arr[position] = elem;
}

void deleteAllOccur(numList *A, int elem){
    int i, j;
    for(i = 0; i < A->count;){
        if(elem == A->arr[i]){
            for(j = i; j < A->count-1; j++){
                A->arr[j] = A->arr[j+1];
            }
            A->count--;
        } else{
            i++;
        }

    }
}


void insertFirstPosition (numList *A, int elem){
    int i;
    for(i = A->count; i > 0; i--){
        A->arr[i] = A->arr[i-1];
    }
    A->count++;
    A->arr[0] = elem;
}