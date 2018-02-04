#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

void stackUnitTests()
{
    printf("\nStack Unit Tests\n");
    Stack *s = createStack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    while(!isStackEmpty(s))
    {
        printf("Peek: %d ", peek(s));
        printf("Pop: %d ", pop(s));
        printf("Count: %d\n", s->count);
    }
    s = destroyStack(s);
}

void queueUnitTests()
{
    printf("\nQueue Unit Tests\n");
    Queue *q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    while(!isQueueEmpty(q))
    {
        printf("Dequeue: %d ", dequeue(q));
        printf("Count: %d\n", q->count);
    }
    q = destroyQueue(q);
}

void runUnitTests()
{
    stackUnitTests();
    queueUnitTests();
}

int main()
{
    runUnitTests();
    return 0;
}
