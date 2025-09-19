#include <stdio.h>
#define MAX 6

typedef struct{
    char data;
    int link;
}nodeType;

typedef struct{
    nodeType Nodes[MAX];
    int avail;
}VirtualHeap;

typedef int List;


int main(){
    VirtualHeap VH;
    List L;

    return 0;
}


void initVirtualHeap1(VirtualHeap *A){
    A->avail = 0;
    int idx;
    for(idx = A->avail; idx < MAX-1; idx++){
        A->Nodes[idx].link = idx+1;
    }
    A->Nodes[idx].link = -1;
}

void initVirtualHeap2(VirtualHeap *A){
    A->avail = MAX-1;
    int idx;
    for(idx = A->avail; idx > 0; idx--){
        A->Nodes[idx].link = idx-1;
    }
    A->Nodes[idx].link = -1;
}

int allocSpace(VirtualHeap *A){
    int i = A->avail;
    if (i != -1){
        A->avail = A->Nodes[i].link;
    }
    return i;
}

void deallocSpace(VirtualHeap *A, int pos){
    A->Nodes[pos].link = A->avail;
    A->avail = pos;
}

void initLIST(List *A){
    *A = -1;
}

void insertFirst(VirtualHeap *A, List *L, char elem){
    if (A->avail != -1){
        int temp = allocSpace(A);
        if (temp != -1){
            A->Nodes[temp].data = elem;
            A->Nodes[temp].link = *L;
            *L = temp;
        }
    }
}

void insertLast(VirtualHeap *A, List *L, char elem){
    if (A->avail != -1){
        int *ptr, temp;
        for(ptr = L; *ptr != -1; ptr = &A->Nodes[*ptr].link){}
        temp = allocSpace(A);
        if (temp != -1){
            A->Nodes[temp].data = elem;
            A->Nodes[temp].link = *ptr;
            *ptr = temp;
        }
    }
}


void insertSorted(VirtualHeap *A, List *L, char elem){
    if(A->avail != -1){
        int *ptr, temp;
        for(ptr = L; *ptr != -1 && elem > A->Nodes[*ptr].data; ptr = &A->Nodes[*ptr].link){}
        temp = allocSpace(A);
        if (temp != -1){
            A->Nodes[temp].data = elem;
            A->Nodes[temp].link = *ptr;
            *ptr = temp;
        }
    }
}


void deleteElem (VirtualHeap *A, List *L, char elem){
    if(A->avail != -1){
        int *ptr, temp;
        for(ptr = L; *ptr != -1 && elem != A->Nodes[*ptr].data; ptr = &A->Nodes[*ptr].link){}
        if(*ptr != -1){
            temp = *ptr;
            *ptr = A->Nodes[temp].link;
            deallocSpace(A, temp);
        }
    }
}