#ifndef LINKEDLISTNODE_H_INCLUDED
#define LINKEDLISTNODE_H_INCLUDED

typedef void* LLElementType;
typedef struct linkedListNode LinkedListNode;

// Define Structure LinkedListNode
struct linkedListNode
{
    LLElementType data;
    LinkedListNode *next;
};

LinkedListNode* createLinkedListNode(LLElementType data);
LinkedListNode* insertInBegin(LinkedListNode *head, LLElementType data);
LinkedListNode* deleteFirstNode(LinkedListNode *head);
LinkedListNode* destroyAllNodes(LinkedListNode *head);

#endif // LINKEDLISTNODE_H_INCLUDED
