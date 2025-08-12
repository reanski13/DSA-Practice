#include <stdio.h>
#define SIZE 20

typedef struct {
    int array[SIZE];
    int count;
}numList;


void initList (numList *A);
void deleteElem(numList *A, int elem);
void insertLast(numList *A, int elem);
void deleteAllOccur(numList *A, int elem);
void insertAtPosition(numList *A, int elem, int position);
void displayList (numList A);

int main(){
    numList L;

    //initialize list
    initList(&L);

    //insert 5 elements at the end of the array
    printf("\nInserting elements at last:\n");
    insertLast(&L, 1);
    insertLast(&L, 2);
    insertLast(&L, 3);
    insertLast(&L, 4);
    insertLast(&L, 4);
    insertLast(&L, 5);
    insertLast(&L, 6);
    insertLast(&L, 7);
    insertLast(&L, 8);
    displayList(L);

    //delete 1 element
    printf("\nDeleting number 5:\n");
    deleteElem(&L, 5);
    displayList(L);

    //insert a new element at the deleted position
    printf("\nInserting 67 6th (array[5]) position:\n");
    insertAtPosition(&L, 67, 5);
    displayList(L);


    //delete all occurrences of the same element
    printf("\n Deleting all occurences of the number 4:\n");
    deleteAllOccur(&L, 4);
    displayList(L);

    return 0;
}

void initList (numList *A){
    A->count = 0;
}

void deleteElem(numList *A, int elem){
    int i;
    for(i = 0; i < A->count; i++) {
        if (A->array[i] == elem){
            for(; i < A->count; i++){
                A->array[i] = A->array[i+1];
            }
            A->count--;
        }
    }

    if (i == A->count){
        printf("The element could not be found.");
    }
}


void deleteAllOccur(numList *A, int elem){
    int i, j;
    for(i = 0; i < A->count;){
        if(elem == A->array[i]){
            for(j = i; j < A->count-1; j++){
                A->array[j] = A->array[j+1];
            }
            A->count--;
        } else {
            i++;
        }
    }
}


void insertLast(numList *A, int elem){
    A->array[A->count++] = elem;
}


void insertAtPosition(numList *A, int elem, int position){
    int i;
    for(i = A->count; i > position; i--){
        A->array[i] = A->array[i-1];
    }
    A->count++;
    A->array[position] = elem;
}



void displayList (numList A){
    ("\nThis is the current array:\n");
    int i;
    for(i = 0; i < A.count; i++){
        printf("%d\n", A.array[i]);
    }
}