#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "LinkedListNode.h"
#include <stdbool.h>

typedef struct stack Stack;
struct stack
{
    LinkedListNode *top;
    int count;
};

Stack *createStack();
void push(Stack *s, LLElementType data);
LLElementType pop(Stack *s);
LLElementType peek(Stack *s);
bool isStackEmpty(Stack *s);
Stack * destroyStack(Stack *s);


#endif // STACK_H_INCLUDED
