#include "BST.h"
#include <stdlib.h>

BSTNode *createBSTNode(BSTElementType data)
{
    BSTNode *node = malloc(sizeof(BSTNode));
    node->left = node->right = NULL;
    node->data = data;
    return node;
}

BSTNode *rinsertBSTNode(BSTNode *root, BSTElementType data)
{
    if(root==NULL)
        return createBSTNode(data);
    /*  Not Required
        if(root->data < data && root->right ==NULL)
        {
            root->right = createBSTNode(data);
            return root;
        }

        if(root->data > data && root->left ==NULL)
        {
            root->left = createBSTNode(data);
            return root;
        }
        */
    if(root->data == data)
        return root;
    if(root->data > data)
        root->left = rinsertBSTNode(root->left, data);
    else
        root->right = rinsertBSTNode(root->right, data);
    return root;
}

BSTNode *insertBSTNode(BSTNode *root, BSTElementType data)
{
    BSTNode *node = createBSTNode(data);

    if(root==NULL)
        return node;

    BSTNode *tmp = root;
    while(tmp!=NULL)
    {
        if(tmp->data==data)
            return root;
        if(tmp->data > data)
        {
            if(tmp->left ==NULL)
            {
                tmp->left = node;
                break;
            }
            tmp = tmp->left;
        }
        else
        {
            if(tmp->right ==NULL)
            {
                tmp->right = node;
                break;
            }
            tmp = tmp->right;
        }
    }

    return root;
}

BSTNode *createRandomBST(int nodeCount, BSTElementType maxValue)
{
    int i;
    BSTElementType j;
    BSTNode *root=NULL;
    for(i=1; i<=nodeCount; i++)
    {
        j = rand()%maxValue;
        root = insertBSTNode(root, j);
    }
    return root;
}

BSTNode *rsearchBSTNode(BSTNode *root, BSTElementType data)
{
    if(root==NULL)
        return NULL;
    if(root->data == data)
        return root;

    if(data < root->data)
        return rsearchBSTNode(root->left, data);
    return rsearchBSTNode(root->right, data);
}

BSTNode *searchBSTNode(BSTNode *root, BSTElementType data)
{
    BSTNode *tmp = root;
    while(tmp!=NULL)
    {
        if(tmp->data==data)
            return tmp;
        if(tmp->data < data)
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    return NULL;
}

BSTNode *maxBSTNode(BSTNode *root)
{
    if(root==NULL)
        return NULL;
    BSTNode *tmp = root;
    while(tmp->right!=NULL)
    {
        tmp = tmp->right;
    }
    return tmp;
}

BSTNode *minBSTNode(BSTNode *root)
{
    if(root==NULL)
        return NULL;
    BSTNode *tmp = root;
    while(tmp->left!=NULL)
    {
        tmp = tmp->left;
    }
    return tmp;
}

BSTNode *rdeleteBSTNode(BSTNode *root, BSTElementType data)
{
    BSTNode *tmp;
    BSTNode *maxInLeftSubtree;
    if(root->data == data)
    {
        // No Children
        if(root->left ==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        // Only Right Child
        if(root->left ==NULL)
        {
            tmp=root->right;
            free(root);
            return tmp;
        }

        // Only Left Child
        if(root->right ==NULL)
        {
            tmp=root->left;
            free(root);
            return tmp;
        }

        // Both Children
        maxInLeftSubtree = maxBSTNode(root->left);
        int t = root->data;
        root->data = maxInLeftSubtree->data;
        maxInLeftSubtree->data = t;

        root->left = rdeleteBSTNode(root->left, t);
        return root;
    }
    if(data < root->data)
    {
        root->left = rdeleteBSTNode(root->left, data);
    }
    else
    {
        root->right = rdeleteBSTNode(root->right, data);
    }

    return root;
}
