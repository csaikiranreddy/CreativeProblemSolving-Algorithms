#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include <assert.h>
#include "Stack.h"
#include "Queue.h"
#include "LinkedListNode.h"

int insertionUnitTests()
{
    BSTNode *root = NULL;
    root = insertBSTNode(root, 5);

    root = insertBSTNode(root, 3);
    root = insertBSTNode(root, 1);
    root = insertBSTNode(root, 4);

    root = insertBSTNode(root, 7);
    root = insertBSTNode(root, 6);
    root = insertBSTNode(root, 9);

    print_ascii_tree(root);

    return 0;
}

void searchUnitTests()
{
    BSTNode *root = createRandomBST(20, 100);
    print_ascii_tree(root);
    assert(rsearchBSTNode(root, 81)!=NULL);
    assert(rsearchBSTNode(root, 100)==NULL);
    assert(searchBSTNode(root, 81)!=NULL);
    assert(searchBSTNode(root, 100)==NULL);
}

void minMaxUnitTests()
{
    BSTNode *root = createRandomBST(20, 100);
    print_ascii_tree(root);
    assert(0==minBSTNode(root)->data);
    assert(95==maxBSTNode(root)->data);
}

void deleteUnitTests()
{
    BSTNode *root = createRandomBST(20, 100);
    print_ascii_tree(root);
    assert(searchBSTNode(root, 61)!=NULL);
    root = rdeleteBSTNode(root, 61);
    assert(searchBSTNode(root, 61)==NULL);
    print_ascii_tree(root);
    root = rdeleteBSTNode(root, 45);
    root = rdeleteBSTNode(root, 62);
    print_ascii_tree(root);
    root = rdeleteBSTNode(root, 41);
    root = rdeleteBSTNode(root, 95);
    print_ascii_tree(root);

    BSTNode *root1 = createBSTNode(5);
    print_ascii_tree(root1);
    root1 = rdeleteBSTNode(root1, 5);
    print_ascii_tree(root1);
}

void traversalsUnitTests()
{
    BSTNode *root = createRandomBST(20, 100);
    print_ascii_tree(root);
    levelOrderTraversal(root);
    preOrderTraversal(root);
    inOrderTraversal(root);
    postOrderTraversal(root);
}

int main()
{
    //insertionUnitTests();
    //searchUnitTests();
    //minMaxUnitTests();
    //deleteUnitTests();
    traversalsUnitTests();
    return 0;
}
