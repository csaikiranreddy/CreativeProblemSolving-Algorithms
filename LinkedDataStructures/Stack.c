#include "Stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

Stack *createStack()
{
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    s->count = 0;
    return s;
}

void push(Stack *s, int data)
{
    s->top = insertInBegin(s->top, data);
    //s->count++;
    s->count = s->count + 1;
}

int pop(Stack *s)
{
    assert(s->top!=NULL);
    int data = s->top->data;

    s->top = deleteFirstNode(s->top);
    s->count = s->count - 1;
    return data;
}
int peek(Stack *s)
{
    assert(s->top!=NULL);
    return (s->top->data);
}
bool isStackEmpty(Stack *s)
{
    if(s->top==NULL)
        return true;
    return false;
    // OR
    //return (s->top==NULL)
}
void destroyStack(Stack *s)
{
    // Call Linked List Deletion
    free(s);
}
