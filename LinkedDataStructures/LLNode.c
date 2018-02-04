#include "LLNode.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

LLNode *createLinkedListNode(int data)
{
    LLNode *node = malloc(sizeof(LLNode));
    node->data=data;
    node->next=NULL;
    return node;
}

LLNode *insertInBegin(LLNode *head, int data)
{
    LLNode *node = createLinkedListNode(data);
    node->next = head;
    return node;
}

LLNode *insertInEnd(LLNode *head, int data)
{
    LLNode *node = createLinkedListNode(data);
    if(head==NULL)
        return node;
    LLNode *cur  = head;
    while(cur->next!=NULL)
        cur = cur->next;

    cur->next = node;
    return head;
}

LLNode *createRandomLinkedList(int nodeCount, int maxValue)
{
    LLNode *head = NULL;
    int i;
    for(i=1; i<=nodeCount; i++)
    {
        if(rand()%2==0)
            head = insertInBegin(head, rand()%(maxValue+1));
        else
            head = insertInEnd(head, rand()%(maxValue+1));

    }
    return head;
}

void traverse(LLNode *head)
{
    printf("\nTraverse: ");
    while(head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int getNodeCount(LLNode *head)
{
    int count = 0;
    while(head!=NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

LLNode *search(LLNode *head, int data)
{
    while(head!=NULL)
    {
        if(head->data == data)
            return head;
        head = head->next;
    }
    return NULL;
}

LLNode *getRandomNode(LLNode *head)
{
    int n = getNodeCount(head);
    if(n==0)
        return NULL;
    int randPosition = rand()%n;
    int i;
    for(i=0; i<randPosition; i++)
        head = head->next;
    return head;
}

LLNode *deleteSingleNodeWithData(LLNode *head, int data)
{
    if(head==NULL)
        return NULL;
    if(head->data == data)
    {
        LLNode *next = head->next;
        free(head);
        return next;
    }
    LLNode *cur = head, *prev = NULL;
    while(cur!=NULL)
    {
        if(cur->data == data)
        {
            prev->next = cur->next;
            free(cur);
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    return head;
}
LLNode *deleteNodesWithData(LLNode *head, int data)
{
    if(head==NULL)
        return NULL;

    // Keep Removing Nodes from front if they match data
    LLNode *cur = head, *prev = NULL, *next;
    while(head->data == data)
    {
        next = head->next;
        free(head);
        head = next;
        if(head == NULL)
            return NULL;
    }

    cur = head;

    // Remove Non-Head Nodes
    while(cur!=NULL)
    {
        if(cur->data==data)
        {
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
            continue;
        }
        prev = cur;
        cur = cur->next;
    }
    return head;
}

LLNode *insertSorted(LLNode *head, int data)
{
    LLNode *node = createLinkedListNode(data);
    if(head==NULL)
        return node;
    if(data <= head->data)
    {
        node->next = head;
        return node;
    }

    LLNode *cur = head, *prev=NULL;
    while(cur!=NULL && data > cur->data)
    {
        prev = cur;
        cur = cur->next;
    }

    if(cur==NULL)
        prev->next = node;
    else
    {
        node->next = cur;
        prev->next = node;
    }
    return head;
}

bool isSorted(LLNode *head)
{
    if(head==NULL || head->next == NULL)
        return true;

    LLNode *cur = head, *next = head->next;
    while(next!=NULL)
    {
        if(cur->data > next->data)
            return false;
        cur = cur->next;
        next = next->next;
    }
    return true;
}

LLNode *getLastNode(LLNode *head)
{
    if(head==NULL)
        return NULL;
    while(head->next!=NULL)
        head = head->next;
    return head;
}

LLNode *reverse(LLNode *head)
{
    if(head==NULL || head->next==NULL)
        return head;
    LLNode *prev = NULL, *cur = head, *next = NULL;

    while(cur!=NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}


LLNode *getKthNodeFromEnd(LLNode *head, int k)
{
    if(head==NULL || k<=0)
        return NULL;

    LLNode *fast = head, *slow = head;
    int i;
    for(i=1;i<=k;i++)
    {
        if(fast==NULL)
            return NULL;
        fast = fast->next;
    }

    while(fast!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

bool hasCycle(LLNode *head)
{
    if(head==NULL || head->next==NULL)
        return false;
    LLNode *fp  = head->next, *sp = head;

    while(1)
    {
        if(fp==NULL || fp->next==NULL)
            return false;
        fp = fp->next->next;
        sp = sp->next;
        if(sp==fp)
            return true;
    }
}
void deleteNodeWithAddressOnly(LLNode *node)
{
    assert(node->next!=NULL);
    LLNode *nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
    free(nextNode);
}

LLNode *deleteDuplicateDataNodes(LLNode *head, int maxValue)
{
    if(head==NULL || head->next==NULL)
        return head;
    int count[maxValue+1];
    int i;
    for(i=0;i<=maxValue;i++)
        count[i] = 0;

    LLNode *cur = head, *prev=NULL;

    while(cur!=NULL)
    {
        if(count[cur->data]==0)
        {
            count[cur->data] = 1;
        }
        else
        {
            // Delete Current Node
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
            continue;
        }
        prev=cur;
        cur = cur->next;
    }
    return head;
}

LLNode *sort(LLNode *head)
{
    assert(false);
}

LLNode *getMiddleNode(LLNode *head)
{
    assert(false);
}

LLNode *deleteFirstNode(LLNode *head)
{
    assert(head!=NULL);
    LLNode *next = head->next;
    free(head);
    return next;
}

void destroyLinkedList(LLNode *head)
{
    assert(false);
}
