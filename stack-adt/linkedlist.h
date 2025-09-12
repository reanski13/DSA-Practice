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

void push (Stack *A, elementType X){
    Stack temp = (Stack) malloc (sizeof(struct node));
    if(temp != NULL){
        temp->elem = X;
        temp->link = *A;
        *A = temp;
    }
}


void pop(Stack *A){
   if(*A != NULL){
    Stack temp = *A;
    *A = temp->link;
    free(temp);
   }
}

elementType TOP(Stack A){
    return(A != NULL)? A->elem: '\0';
}

#endif