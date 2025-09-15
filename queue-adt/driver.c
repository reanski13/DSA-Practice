#include<stdio.h>
#include<string.h>
#include "llqueue.h"

int main() {
    Queue Q;
    initialize(&Q);

    // Task 1: Enqueueing elements
    printf("Task 1: Enqueueing elements into the queue\n");
    enqueue(&Q, 'c');
    enqueue(&Q, 's');
    enqueue(&Q, 'u');
    enqueue(&Q, 'c');
    enqueue(&Q, 'n');
    displayQueue(Q);

    // Task 2: Dequeueing elements
    printf("\nTask 2: Dequeueing elements from the front\n");
    dequeue(&Q);
    displayQueue(Q);
    printf("\n");
    dequeue(&Q);
    displayQueue(Q);

    // Task 3: Peeking at front
    printf("\nTask 3: Peeking at the front of the queue\n");
    printf("Front element: %c\n", FRONT(Q));

    // Task 4: Checking empty/full
    printf("\nTask 4: Checking if queue is empty or full\n");
    Queue emptyQueue;
    initialize(&emptyQueue);
    
    printf("Empty queue: ");
    displayQueue(emptyQueue);
    isEmpty(emptyQueue) ? printf("Queue is empty\n") : printf("Queue is not empty\n");
    
    printf("Main queue: ");
    displayQueue(Q);
    isFull(Q) ? printf("Queue is full\n") : printf("Queue is not full\n");

    // Task 5: Adding more elements
    printf("\nTask 5: Inserting elements at the rear\n");
    enqueue(&Q, 't');
    enqueue(&Q, 'c');
    displayQueue(Q);

    // Edge case testing
    printf("\nTesting edge cases:\n");
    printf("Front of empty queue: '%c'\n", FRONT(emptyQueue));
    
    // Test dequeue on empty queue (should do nothing)
    dequeue(&emptyQueue);
    printf("After dequeue on empty queue: ");
    displayQueue(emptyQueue);

    return 0;
}