//
// Created by Anshu on 12/1/18.
//
#include<stdio.h>
#include<stdlib.h>
#include "TreeNode.h"

TreeNode *root = NULL;

int height(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

// A utility function to get maximum of two integers
int max(int a, int b) {
    return (a > b)? a : b;
}


/* Helper function that allocates a new node with the given address and
    NULL left and right pointers. */
TreeNode* newNode(void* address, size_t length) {
    TreeNode* node = (TreeNode*)
            malloc(sizeof(TreeNode));
    node->address   = address;
    node->length    = length;
    node->left      = NULL;
    node->right     = NULL;
    node->height    = 1;  // new node is initially added at leaf
    node->active    = true;
    return(node);
}

TreeNode *rightRotate(TreeNode *y)
{
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
TreeNode *leftRotate(TreeNode *x) {
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(TreeNode*N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a address in the subtree rooted
// with node and returns the new root of the subtree.

TreeNode* insertNode(TreeNode* node, void* address, size_t length)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(address, length));

    if (address < node->address)
        node->left  = insertNode(node->left, address, length);
    else if (address > node->address)
        node->right = insertNode(node->right, address, length);
    else {
        // Equal address are not allowed in BST
        node->active = true;
        node->length = length;
        return node;
    }

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && address < node->left->address)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && address > node->right->address)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && address > node->left->address)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && address < node->right->address)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

TreeNode* insert(void* address, size_t length){
    root = insertNode(root, address, length);
    return root;
}

TreeNode * minValueNode(TreeNode* node)
{
    TreeNode* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}


// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.

TreeNode* deleteNode(TreeNode* root, void* address)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if ( address < root->address )
        root->left = deleteNode(root->left, address);

        // If the key to be deleted is greater than the
        // root's key, then it lies in right subtree
    else if( address > root->address )
        root->right = deleteNode(root->right, address);

        // if key is same as root's key, then This is
        // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            TreeNode *temp = root->left ? root->left :
                                root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of
            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            TreeNode* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->address = temp->address;
            root->length = temp->length;
            root->active = temp->active;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->address);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

TreeNode* isValidNode(TreeNode* root, void* address){
    if(root == NULL){
        return NULL;
    }
    if(root->address == address){
        return root;
    }
    else if(root->address < address && (root->address + root->length) > address){
        fprintf(stderr, "\nError: Not the first byte of the address %p\n", address);
        exit(-1);
    } else if(root->address > address){
        return isValidNode(root->left, address);
    } else{
        return isValidNode(root->right, address);
    }

}

TreeNode* isValidTreeNode(TreeNode* root, void* address, size_t size){
    if(root == NULL){
        return NULL;
    }
    if(root->address <= address && root->address + root->length >= address + size){
        return root;
    }
    else if (root->address <= address &&  root->address + root->length >= address && root->address + root->length < address + size){
        fprintf(stderr, "\nError : Address is valid but size is overflowing allocated range\n");
        exit(-1);
    }
    else if(root->address > address){
        return isValidTreeNode(root->left, address, size);
    } else{
        return isValidTreeNode(root->right, address, size);
    }

}

void validateTreeNode(void *address, size_t size){
    TreeNode *node = isValidTreeNode(root, address, size);
    if(node == NULL){
        fprintf(stderr, "\nError : Invalid memory access. Memory not allocated yet %p\n", address);
        exit(-1);
    }
    if (!node->active) {
        fprintf(stderr, "\ndouble free or corruption: %p\n", address);
        exit(-1);
    }
}

void disable(void* address){
    TreeNode *node = isValidNode(root, address);
    if(node == NULL){
        fprintf(stderr, "\nError: Requested memory is not available %p\n", address);
        exit(-1);
    }
    if (!node->active) {
        fprintf(stderr, "\ndouble free or corruption: %p\n", address);
        exit(-1);
    }
    node->active = false;
    node->length = 0;
    return;
}

void delete(void* address){
    TreeNode *node = isValidNode(root, address);
    if(node == NULL){
        fprintf(stderr, "\nError: Requested memory is already freed up or not available %p\n", address);
        exit(-1);
    }
    root = deleteNode(root, address);
    return;
}

void preOrder(TreeNode *root)
{
    if(root != NULL)
    {
//        printf("%ld ", (__intptr_t)root->address);
        preOrder(root->left);
        preOrder(root->right);
    }
}

