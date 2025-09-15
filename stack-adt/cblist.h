#ifndef CBLIST_H
#define CBLIST_H
#define MAX 10

typedef char elementType;

typedef struct{
    elementType data;
    int link;
}nodeType;

typedef struct{
    nodeType nodes[MAX];
    int avail;
}VirtualHeap;

typedef struct{
    VirtualHeap *VH;
    int top;
}Stack;


//helper functions for cb_lists

    void initializeVH(VirtualHeap *A){
        A->avail = 0;
        int i;
        for(i = 0; i < MAX-1; i++){
            A->nodes[i].link = i+1;
        }
        A->nodes[i].link = -1;
    }

    int allocSpace(VirtualHeap *A){
        int pos = A->avail;
        if(pos != 0){
            A->avail = A->nodes[pos].link;
        }
        return pos;
    }

    void deallocSpace(VirtualHeap *A, int pos){
        if (pos > 0 && pos < MAX-1){
            A->nodes[pos].link = A->avail;
            A->avail = pos;
        }
    }

//end of helper functions



void initialize(Stack *A){
    initializeVH(A->VH);
    A->top = -1; 
}

bool empty(Stack A){
    return(A.top == -1) ? true:false;
}

bool full(Stack A){
    return(A.top == MAX-1) ? true:false;
}

void push(Stack *A, elementType X){
    if(!full(*A)){
        int temp = allocSpace(A->VH);
        if(temp != -1){
            A->VH->nodes[temp].data = X;
            A->VH->nodes[temp].link = A->top;
            A->top = temp;
        }
    }
}

void pop(Stack *A){
    if(!empty(*A)){
        int temp = A->top;
        A->top = A->VH->nodes[temp].link;
        deallocSpace(A->VH, temp);
    }
}

elementType TOP(Stack A){
    return(!empty(A)) ? A.VH->nodes[A.top].data:'\0';
}

void insertBottom(Stack *A, elementType X){
    Stack temp;
    
}




#endif