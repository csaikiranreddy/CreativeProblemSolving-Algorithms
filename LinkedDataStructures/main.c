#include <stdio.h>
#include <stdlib.h>
#include "LLNode.h"
#include <assert.h>
#include <time.h>
#include "Stack.h"

void insertionUnitTests()
{
    LLNode *head = NULL;

    // Insert in such a way that we get a sorted List
    head = insertSorted(head, 3);
    head = insertSorted(head, 2);
    head = insertSorted(head, 1);
    head = insertSorted(head, 6);
    head = insertSorted(head, 5);
    head = insertSorted(head, 4);

    head = insertInBegin(head, 0);
    head = insertSorted(head, 7);
    head = insertInEnd(head, 8);

    // Print the List
    traverse(head);

    // Assert that List is Sorted
    assert(isSorted(head)==true);

    // Create a New List by passing NULL as head and create Unsorted List
    LLNode *head1 = insertInBegin(NULL, 1);
    head1 = insertInBegin(head1, 2);
    traverse(head1);

    // Validate it is unsorted
    assert(isSorted(head1)!=true);
}

void searchUnitTests()
{
    LLNode *head = NULL;
    head = insertSorted(head, 3);
    head = insertSorted(head, 2);
    head = insertSorted(head, 1);

    // Search Last Node
    assert(search(head, 3)!=NULL);

    // Search First Node
    assert(search(head, 1)!=NULL);

    // Search Middle Node
    assert(search(head, 2)!=NULL);

    // Search Non-Existing Value
    assert(search(head, 5)==NULL);

}

void getLastNodeUnitTests()
{
    LLNode *head = NULL;
    head = insertSorted(head, 3);
    head = insertSorted(head, 2);
    head = insertSorted(head, 1);

    // Search Last Node
    LLNode *lastNode = getLastNode(head);
    assert(lastNode!=NULL && lastNode->data == 3);

    // Search Last Node in Empty List
    assert(getLastNode(NULL)==NULL);

    // Search Last Node in Single-Node List
    LLNode *head1 = insertInBegin(NULL, 2);
    LLNode *lastNode1 = getLastNode(head1);
    assert(lastNode1!=NULL && lastNode1->data ==2);
}

void deleteNodeUnitTests()
{
    LLNode *head = NULL;
    head = insertSorted(head, 3);
    head = insertSorted(head, 2);
    head = insertSorted(head, 1);
    head = insertInEnd(head, 1);
    head = insertInBegin(head, 3);
    head = insertInBegin(head, 2);
    traverse(head);

    assert(getNodeCount(head)==6);
    head = deleteSingleNodeWithData(head, 2);
    assert(getNodeCount(head)==5);

    head = deleteNodesWithData(head, 1);
    assert(getNodeCount(head)==3);

}

void createRandomListUnitTests()
{
    LLNode *head = createRandomLinkedList(5, 13);
    assert(getNodeCount(head)==5);

    LLNode *head1 = createRandomLinkedList(0, 5);
    assert(getNodeCount(head1)==0);
}

void reverseUnitTest()
{
    LLNode *head = createRandomLinkedList(10, 100);
    traverse(head);
    assert(getNodeCount(head)==10);
    head = reverse(head);
    assert(getNodeCount(head)==10);
    traverse(head);
}
void kthNodeFromEndTests()
{
    LLNode *head = NULL;
    head = insertSorted(head, 3);
    head = insertSorted(head, 2);
    head = insertSorted(head, 1);

    assert(getKthNodeFromEnd(head, 1)->data==3);
    assert(getKthNodeFromEnd(head, 2)->data==2);
    assert(getKthNodeFromEnd(head, 3)->data==1);
    assert(getKthNodeFromEnd(head, 4)==NULL);
    assert(getKthNodeFromEnd(head, 0)==NULL);

}
void hasCycleUnitTests()
{
    LLNode *head = createRandomLinkedList(3, 100);
    assert(hasCycle(head)==false);

    LLNode *random = getRandomNode(head);
    LLNode *lastNode = getLastNode(head);
    traverse(head);
    printf("\nRandom Node: %d", random->data);
    lastNode->next = random;
    assert(hasCycle(head)==true);
}
void deleteNodeWithGivenAddressOnlyUnitTests()
{
    LLNode *head = NULL;
    head = insertSorted(head, 3);
    head = insertSorted(head, 2);
    head = insertSorted(head, 1);
    head = insertSorted(head, 4);
    head = insertSorted(head, 5);

    traverse(head);
    deleteNodeWithAddressOnly(search(head, 3));
    traverse(head);
}

void deleteDuplicateDataNodesUnitTests()
{
    LLNode *head = createRandomLinkedList(10, 10);
    traverse(head);
    head = deleteDuplicateDataNodes(head, 50);
    traverse(head);
}
void LinkedListUnitTests()
{
    int seed = time(NULL);
    printf("\nSEED: %d", seed);
    srand(seed);

    insertionUnitTests();
    searchUnitTests();
    getLastNodeUnitTests();
    deleteNodeUnitTests();
    createRandomListUnitTests();
    reverseUnitTest();
    kthNodeFromEndTests();
    hasCycleUnitTests();
    deleteNodeWithGivenAddressOnlyUnitTests();
    deleteDuplicateDataNodesUnitTests();
    //sort(NULL);
    //getMiddleNode(NULL);
}

void stackUnitTests()
{
     Stack *s = createStack();
    push(s, 4);
    push(s, 5);
    push(s, 9);

    int v = pop(s);
    printf("\nv=%d", v);
    assert(v==9);

    int u = peek(s);
    printf("\nu=%d", u);
    assert(u==5);

    bool isEmpty = isStackEmpty(s);
    printf("\nisEmpty=%s", isEmpty?"true":"false");
    assert(isEmpty==false);

    destroyStack(s);
}
int main()
{

    return 0;
}
