//
// Created by Anshu on 12/1/18.
//

#ifndef MALLOC_LIBRARY_TREENODE_H
#define MALLOC_LIBRARY_TREENODE_H

#endif //MALLOC_LIBRARY_TREENODE_H

typedef struct TreeNode
{
    void* address;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
    int length;
} TreeNode;

int max(int a, int b);

int height(TreeNode *node);

TreeNode* newNode(void* address, int size);

TreeNode* insert(TreeNode* node, void* address, int length);

TreeNode* deleteNode(TreeNode* root, void* address);

void preOrder(TreeNode *root);

TreeNode* search(TreeNode* root, void* address);