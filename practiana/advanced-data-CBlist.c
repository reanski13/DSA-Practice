#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct{
    char fullname[50];
    int age;
    char course[8];
    int yrLvl;
}studRec;

typedef struct{
    studRec students;
    int link;
}nodeType;

typedef struct{
    nodeType Nodes[MAX];
    int avail;
}VirtualHeap;

typedef int List;



void initVH(VirtualHeap *A){
    A->avail = 0;
    int idx;
    for(idx = A->avail; idx < MAX-1; idx++){
        A->Nodes[idx].link = idx+1;
    }
    A->Nodes[idx].link = -1;
}

int allocSpace(VirtualHeap *A){
    int idx = A->avail;
    if (idx != -1){
        A->avail = A->Nodes[idx].link;
    }
    return idx;
}

void deallocSpace(VirtualHeap *A, int pos){
    A->Nodes[pos].link = A->avail;
    A->avail = pos;
}

void insertLast(VirtualHeap *A, List *L, char fullname[], int age, char course[], int yrLvl){
    if(A->avail != -1){
        int *ptr, temp;
        for(ptr = L; *ptr != -1; ptr = &A->Nodes[*ptr].link){}
        temp = allocSpace(A);
        if (temp != -1){  
            A->Nodes[temp].students.age = age;
            A->Nodes[temp].students.yrLvl = yrLvl;
            strcpy(A->Nodes[temp].students.fullname, fullname);
            strcpy(A->Nodes[temp].students.course, course);
            A->Nodes[temp].link = *ptr;
            *ptr = temp;
        }
    }
}

void display(VirtualHeap A, List L){
    printf("\nCurrent Record:\n");
    printf("%-20s %-20s %-20s %-20s\n", "Full Name", "Course", "Age", "Year Level");
    for(; L!=-1; L = A.Nodes[L].link){
        printf("%-20s %-20s %-20d %-20d\n", A.Nodes[L].students.fullname, A.Nodes[L].students.course, A.Nodes[L].students.age, A.Nodes[L].students.yrLvl);
    }
}


int main(){
    VirtualHeap VH;
    List L = -1;

    initVH(&VH);

    //insert 5 studRecs
    insertLast(&VH, &L, "Atheena Arcena", 22, "BSCS", 2);
    insertLast(&VH, &L, "Ethan Dalocanog", 17, "BSCS", 3);
    display(VH, L);

    return 0;
}



