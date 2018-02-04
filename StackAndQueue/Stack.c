#include "Stack.h"
#include <stdlib.h>
#include <assert.h>

Stack *createStack()
{
    Stack *s = malloc(sizeof(Stack));
    s->count = 0 ;
    s->top = NULL;
    return s;
}

void push(Stack *s, ElementType data)
{
    s->top = insertInBegin(s->top, data);
    s->count++;
}

ElementType pop(Stack *s)
{
    assert(isStackEmpty(s)==false);
    ElementType data = s->top->data;
    s->top = deleteFirstNode(s->top);
    s->count--;
    return data;
}

ElementType peek(Stack *s)
{
    assert(isStackEmpty(s)==false);
    ElementType data = s->top->data;
    return data;
}

bool isStackEmpty(Stack *s)
{
    return (s->top ==NULL);
}

Stack * destroyStack(Stack *s)
{
    s->top = destroyAllNodes(s->top);
    s->count = 0;
    free(s->top);
    return NULL;
}
