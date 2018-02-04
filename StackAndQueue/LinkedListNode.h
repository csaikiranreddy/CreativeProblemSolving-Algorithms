#ifndef LINKEDLISTNODE_H_INCLUDED
#define LINKEDLISTNODE_H_INCLUDED

typedef int ElementType;
typedef struct linkedListNode LinkedListNode;

// Define Structure LinkedListNode
struct linkedListNode
{
    ElementType data;
    LinkedListNode *next;
};

LinkedListNode* createLinkedListNode(ElementType data);
LinkedListNode* insertInBegin(LinkedListNode *head, ElementType data);
LinkedListNode* deleteFirstNode(LinkedListNode *head);
LinkedListNode* destroyAllNodes(LinkedListNode *head);

#endif // LINKEDLISTNODE_H_INCLUDED
