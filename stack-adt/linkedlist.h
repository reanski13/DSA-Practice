#ifndef ADTLINKEDLIST_H
#define ADTLINKEDLIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef char elementType;

typedef struct node{
    char elem;
    struct node *link;
}*LIST;

typedef LIST Stack;


void initialize(Stack *A){
    *A = NULL;
}


bool empty(Stack A){
    return(A == NULL) ? true:false;
}

bool full(Stack A){
    return false;
}

void push (Stack *A, elementType X){
    Stack temp = (Stack) malloc (sizeof(struct node));
    if(temp != NULL){
        temp->elem = X;
        temp->link = *A;
        *A = temp;
    }
}


void pop(Stack *A){
   if(!empty(*A)){
    Stack temp = *A;
    *A = temp->link;
    free(temp);
   }
}

elementType TOP(Stack A){
    return(A != NULL)? A->elem: '\0';
}

void insertBottom(Stack *A, elementType X){
    Stack temp;
    initialize(&temp);
    elementType top;

    while(*A != NULL){
        top = TOP(*A);
        push(&temp, top);
        pop(A);
    }

    push(A, X);

    while(temp != NULL){
        top = TOP(temp);
        push(A, top);
        pop(&temp);
    }
}


void displayStack(Stack A){
    Stack temp;
    initialize(&temp);
    elementType top;

    while(A != NULL){
        top = TOP(A);
        push(&temp, top);
        pop(&A);
    }

    while (temp != NULL){
        top = TOP(temp);
        printf("%c\n", top);
        push(&A, top);
        pop(&temp);
    }
}

#endif