#ifndef LLQUEUE_H
#define LLQUEUE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char element;
    struct node* link;
}*LIST;

typedef struct{
    LIST front;
    LIST rear;
}Queue;


void initialize(Queue *A){
    A->front = NULL;
    A->rear = NULL;
}

bool isEmpty(Queue A){
    return (A.front==NULL && A.rear == NULL)? true:false;
}

bool isFull(Queue A){
    return false;
}

void enqueue(Queue *A, char x){
    
    LIST temp = (LIST) malloc (sizeof(struct node));
    if(temp != NULL){
        temp->element = x;
        temp->link = NULL; 

        if(!isEmpty(*A)){
            A->rear->link = temp;
            A->rear = temp;
        } else{
            A->front = temp;
            A->rear = temp;
        }
    }
}

void dequeue(Queue *A){
    //delete first
    if(!isEmpty(*A)){
        LIST temp = A->front;
        A->front = temp->link;

        if(A->front == NULL){
            A->rear = NULL;
        }
        free(temp);
    }
}


char FRONT(Queue A){
    return(!isEmpty(A)) ? A.front->element :  '\0';
}

void displayQueue(Queue A){
    if(!isEmpty(A)){
        char front;
        Queue temp;
        initialize(&temp);

        while(!isEmpty(A)){
            front = FRONT(A);
            printf("%c\n", front);
            enqueue(&temp, front);
            dequeue(&A);
        }

        while(!isEmpty(temp)){
            front = FRONT(temp);
            enqueue(&A, front);
            dequeue(&temp);
        }
    }
    
}

#endif