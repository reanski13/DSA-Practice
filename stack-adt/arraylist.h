#ifndef ADTARRAYLIST_H
#define ADTARRAYLIST_H
#include <stdio.h>
#include <stdbool.h>
#define MAX 10


typedef char elementType;

typedef struct{
    elementType elems[MAX];
    int top;
}Stack;

void initialize(Stack *A){
    A->top = -1;
}

bool empty(Stack A){
    return(A.top == -1) ? true : false;
}

bool full(Stack A){
    return(A.top == MAX-1) ? true: false;
}

void push (Stack *A, elementType X){
    if(!full(*A)){
        A->elems[++A->top] = X; 
    }
}

void pop(Stack *A){
    if(!empty(*A)){
        A->top--;
    }
}

elementType TOP(Stack A){
    return(!empty(A)) ? A.elems[A.top] : '\0';
}

void insertBottom(Stack *A, elementType X){
    Stack temp;
    initialize(&temp);
    elementType top;

    while(!empty(*A)){
        top = TOP(*A);
        push(&temp, top);
        pop(A);
    }

    push(A, X);

    while(!empty(temp)){
        top = TOP(temp);
        push(A, top);
        pop(&temp);
    }
}


void displayStack(Stack A){
    Stack temp;
    initialize(&temp);
    elementType top;

    while(!empty(A)){
        top = TOP(A);
        push(&temp, top);
        pop(&A);
    }

    while(!empty(temp)){
        top = TOP(temp);
        printf("%c\n", top);
        push(&A, top);
        pop(&temp);
    }
}





#endif