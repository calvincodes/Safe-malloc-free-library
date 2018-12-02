//
// Created by Anshu on 12/1/18.
//


#include <stdbool.h>

#ifndef MALLOC_LIBRARY_TREENODE_H
#define MALLOC_LIBRARY_TREENODE_H

#endif //MALLOC_LIBRARY_TREENODE_H

typedef struct TreeNode
{
    void* address;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
    size_t length;
    bool active;
} TreeNode;

//


TreeNode* newNode(void* address, size_t size);

TreeNode* insert(void* address, size_t length);

void disable(void* address);

void delete(void* address);

void preOrder(TreeNode *root);

void validateTreeNode(void *address, size_t size);