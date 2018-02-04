#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef int BSTElementType;
typedef struct bstNode BSTNode;
struct bstNode
{
    BSTElementType data;
    BSTNode *left;
    BSTNode *right;
};

BSTNode *createBSTNode(BSTElementType data);
BSTNode *insertBSTNode(BSTNode *root, BSTElementType data);
BSTNode *rinsertBSTNode(BSTNode *root, BSTElementType data);
BSTNode *searchBSTNode(BSTNode *root, BSTElementType data);
BSTNode *rdeleteBSTNode(BSTNode *root, BSTElementType data);

BSTNode *createRandomBST(int nodeCount, BSTElementType maxValue);
BSTNode *rsearchBSTNode(BSTNode *root, BSTElementType data);
BSTNode *maxBSTNode(BSTNode *root);
BSTNode *minBSTNode(BSTNode *root);

void print_ascii_tree(BSTNode * t);

void levelOrderTraversal(BSTNode *root);
void preOrderTraversal(BSTNode *root);
void inOrderTraversal(BSTNode *root);
void postOrderTraversal(BSTNode *root);
#endif // BST_H_INCLUDED
