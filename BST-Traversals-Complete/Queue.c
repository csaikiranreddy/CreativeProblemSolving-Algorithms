#include "Queue.h"
#include <stdlib.h>
#include <assert.h>

Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue));
    q->count=0;
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, LLElementType data)
{
    LinkedListNode *newNode = createLinkedListNode(data);
    if(q->front==NULL)
        q->front = q->rear = newNode;
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->count++;
}

LLElementType dequeue(Queue *q)
{
    assert(isQueueEmpty(q)==false);
    LLElementType data = q->front->data;
    q->front = deleteFirstNode(q->front);
    if(q->front == NULL)
        q->rear = NULL;
    else if(q->front->next == NULL)
        q->rear = q->front;
    q->count--;
    return data;
}

bool isQueueEmpty(Queue *q)
{
    return (q->count==0);
}
Queue *destroyQueue(Queue *q)
{
    q->front = q->rear = destroyAllNodes(q->front);
    q->count = 0;
    free(q);
    return NULL;
}
