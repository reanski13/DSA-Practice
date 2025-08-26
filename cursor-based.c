#include <stdio.h> 
#define MAX 5

typedef struct{
    char elem;
    int link;
}nodeType;

typedef struct{
    nodeType Node[MAX];
    int avail;
}VirtualHeap;

typedef int List;

void initVerOne(VirtualHeap *A);
int allocSpace(VirtualHeap *A);
void deallocSpace(VirtualHeap *A, int pos);
void insertLast(VirtualHeap *A, List *L, char elem);
void display (VirtualHeap A, List L);
int main(){

    //declare a list and its head 
    VirtualHeap VH;
    List L = -1;

    //initialize
    initVerOne(&VH);

    //perform insert last then print it
    insertLast(&VH, &L, 'A');
    insertLast(&VH, &L, 'B');
    insertLast(&VH, &L, 'C');
    insertLast(&VH, &L, 'D');
    insertLast(&VH, &L, 'E');
    display(VH, L);


    return 0;
}


//initialize version 1
void initVerOne(VirtualHeap *A){
    A->avail=0;
    int i;
    for(i = A->avail; i < MAX-1; i++){
        A->Node[i].link = i+1;
    }
    A->Node[i].link = -1;
}

//allocSpace
int allocSpace(VirtualHeap *A){
    int idx = A->avail;
    if (idx != -1){
        A->avail = A->Node[idx].link;    
    }
    return idx;
}


//deallocSpace 
void deallocSpace(VirtualHeap *A, int pos){
    A->Node[pos].link = A->avail;
    A->avail = pos;
}

//insertLast
void insertLast(VirtualHeap *A, List *L, char elem){
    if (A->avail != -1){
        int *ptr, temp;
        for (ptr = L; *ptr != -1; ptr = &A->Node[*ptr].link){}
        temp = allocSpace(A);
        if (temp != -1){
            A->Node[temp].elem = elem;
            A->Node[temp].link = *ptr;
            *ptr = temp;
        }
    }
}


//display
void display (VirtualHeap A, List L){
    printf("\nCurrent List:\n");
    for(; L != -1; L = A.Node[L].link){
        printf("%c\n", A.Node[L].elem);
    }
}