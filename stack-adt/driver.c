#include<stdio.h>
#include<string.h>
#include "ADTArray.h"
//#include "linkedlist.h"
// #include "arraylist.h"
// #include "cblist.h"

int main() {

    Stack S;
    initialize(&S);

    //pushing elements into the stack
    printf("Task 1: Pushing elements into the stack\n");

    push(&S, 'c');
    push(&S, 's');
    push(&S, 'u');
    push(&S, 'c');
    push(&S, 'n');
    displayStack(S);

    //popping an element
    printf("\nTask 2: Popping elements from the top of the stack\n");

    pop(&S);
    displayStack(S);
    printf("\n");
    pop(&S);
    displayStack(S);    

    //returning top element
    printf("\nTask 3: Peeking at the top of the stack\n");
    printf("%c\n", TOP(S));

    //checking if empty or full
    printf("\nTask 4: Checking if stack is empty or full\n");

    Stack emp;
    initialize(&emp);
    Stack puno;
    initialize(&puno);
    char word[] = "mississippi";
    for(int i = 0; i < strlen(word); i++){
        push(&puno, word[i]);
    }
    printf("\nDisplaying empty stack:\n");
    displayStack(emp);
    empty(emp) == 1 ? printf("Stack is empty\n") : printf("Stack is not empty\n");
    printf("Displaying full stack:\n");
    displayStack(puno);
    full(puno) == 1 ? printf("Stack is full\n") : printf("Stack is not full\n");


    //inserting at bottom
    printf("\nTask 5: Inserting element at the bottom of the stack\n");
    insertBottom(&S, 't');
    insertBottom(&S, 'c');
    displayStack(S);

    //more checking
    printf("\nEmpty checking\n");
    printf("Top element: %c", TOP(emp));


    return 0;
}