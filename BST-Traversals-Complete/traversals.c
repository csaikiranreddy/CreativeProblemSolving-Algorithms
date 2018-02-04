#include "BST.h"
#include "Queue.h"
#include <stdio.h>
#include "Stack.h"

void levelOrderTraversal(BSTNode *root)
{
    if(root==NULL)
        return;
    printf("\nLevel Order Traversal: ");
    Queue *q = createQueue();
    enqueue(q, root);
    while(1)
    {
        if(isQueueEmpty(q))
            break;
        BSTNode *tmp = dequeue(q);
        printf("%d ", tmp->data);
        if(tmp->left!=NULL)
            enqueue(q, tmp->left);
        if(tmp->right!=NULL)
            enqueue(q, tmp->right);
    }

    destroyQueue(q);
}

void preOrderTraversal(BSTNode *root)
{
    if(root==NULL)
        return;
    printf("\nPre-Order Traversal: ");
    Stack *s = createStack();
    BSTNode *tmp = root;
    while(1)
    {
        // PRINT AND GO LEFT
        while(tmp!=NULL)
        {
            printf("%d ", tmp->data);
            push(s, tmp);
            tmp = tmp->left;
        }

        // POP
        if(isStackEmpty(s))
            break;
        tmp = pop(s);

        // Move to the right of popped
        tmp = tmp->right;
    }
    destroyStack(s);
}

void inOrderTraversal(BSTNode *root)
{
    if(root==NULL)
        return;
    printf("\nIn-Order Traversal: ");
    Stack *s = createStack();
    BSTNode *tmp = root;
    while(1)
    {
        // PRINT AND GO LEFT
        while(tmp!=NULL)
        {
            push(s, tmp);
            tmp = tmp->left;
        }

        // POP
        if(isStackEmpty(s))
            break;
        tmp = pop(s);
        printf("%d ", tmp->data);

        // Move to the right of popped
        tmp = tmp->right;
    }
    destroyStack(s);
}


void postOrderTraversal(BSTNode *root)
{
    if(root==NULL)
        return;
    printf("\nPost-Order Traversal: ");

    BSTNode *tmp = root;
    BSTNode *p;

    Stack *s = createStack();

    while(1)
    {
        // Moving to the left
        while(tmp!=NULL)
        {
            if(tmp->right!=NULL)
                push(s, tmp->right);
            push(s, tmp);
            tmp = tmp->left;
        }

        if(isStackEmpty(s))
            break;
        tmp = pop(s);
        if(isStackEmpty(s))
        {
            printf("%d ", tmp->data);
            break;
        }
        p = pop(s);

        if(p == tmp->right)
        {
            push(s, tmp);
            tmp = tmp->right;
        }
        else
        {
            printf("%d ", tmp->data);
            push(s, p);
            tmp = NULL;
        }
    }

    destroyStack(s);
}












