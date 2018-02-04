#include "LinkedListNode.h"
#include <stdlib.h>
#include <assert.h>

LinkedListNode* createLinkedListNode(LLElementType data)
{
    LinkedListNode *newNode = malloc(sizeof(LinkedListNode));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

LinkedListNode* insertInBegin(LinkedListNode *head, LLElementType data)
{
    LinkedListNode *newNode = createLinkedListNode(data);
    newNode->next = head;
    return newNode;
}

LinkedListNode* deleteFirstNode(LinkedListNode *head)
{
    assert(head!=NULL);
    LinkedListNode *first = head;
    head = head->next;
    free(first);
    return head;
}

LinkedListNode* destroyAllNodes(LinkedListNode *head)
{
    LinkedListNode *next;
    while(head!=NULL)
    {
        next = head->next;
        free(head);
        head = next;
    }
    return NULL;
}
