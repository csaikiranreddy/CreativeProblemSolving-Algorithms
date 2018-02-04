#ifndef LLNODE_H_INCLUDED
#define LLNODE_H_INCLUDED
#include <stdbool.h>

typedef struct llnode LLNode;

struct llnode
{
    int data;
    LLNode *next;
};

// INSERTION FUNCTIONS
LLNode *insertInBegin(LLNode *head, int data);
LLNode *insertInEnd(LLNode *head, int data);
LLNode *insertSorted(LLNode *head, int data);

// TRAVERSE
void traverse(LLNode *head);

// SEARCH
LLNode *search(LLNode *head, int data);
LLNode *getLastNode(LLNode *head);
LLNode *getKthNodeFromEnd(LLNode *head, int k);
LLNode *getMiddleNode(LLNode *head);

// DELETE NODE
LLNode *deleteNodesWithData(LLNode *head, int data);
LLNode *deleteSingleNodeWithData(LLNode *head, int data);
void deleteNodeWithAddressOnly(LLNode *node);
LLNode *deleteDuplicateDataNodes(LLNode *head, int maxValue);
LLNode *deleteFirstNode(LLNode *head);
void destroyLinkedList(LLNode *head);

// LIST PROPERTIES
int getNodeCount(LLNode *head);

// RANDOM FUNCTIONS
LLNode *getRandomNode(LLNode *head);
LLNode *createRandomLinkedList(int nodeCount, int maxValue);

// VALIDATION
bool isSorted(LLNode *head);
bool hasCycle(LLNode *head);

// REVERSAL
LLNode *reverse(LLNode *head);

// Sort
LLNode *sort(LLNode *head);

#endif // LLNODE_H_INCLUDED
