#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdbool.h>
#include "LLNode.h"

typedef struct stack Stack;

struct stack
{
    LLNode *top;
    int count;
};

Stack *createStack();
void push(Stack *s, int data);
int pop(Stack *s);
int peek(Stack *s);
bool isStackEmpty(Stack *s);
void destroyStack(Stack *s);

#endif // STACK_H_INCLUDED
