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

void push(Stack *s, LLElementType data)
{
    s->top = insertInBegin(s->top, data);
    s->count++;
}

LLElementType pop(Stack *s)
{
    assert(isStackEmpty(s)==false);
    LLElementType data = s->top->data;
    s->top = deleteFirstNode(s->top);
    s->count--;
    return data;
}

LLElementType peek(Stack *s)
{
    assert(isStackEmpty(s)==false);
    LLElementType data = s->top->data;
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
