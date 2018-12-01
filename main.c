#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"

int main(){

    int *ptr = malloc(10 * sizeof(int));
    printf("%p\n", ptr);
    TreeNode *root = NULL;
    root = insert(root, ptr,1);
    root = insert(root, ptr+1,1);
    root = insert(root, ptr+2,1);
    root = insert(root, ptr+3,1);
    root = insert(root, ptr+4,1);
    root = insert(root, ptr+5,1);
    root = insert(root, ptr+6,1);
    root = insert(root, ptr+7,1);
    root = insert(root, ptr+8,1);
    preOrder(root);
    if(search(root, ptr+5)){
        printf("\nSearch is working fine");
    } else {
        printf("\nSearch is failing");
    }
//    printf("\nAfter deleting %ld \n", (intptr_t)ptr);
//    root = deleteNode(root, ptr);
//    preOrder(root);
//    printf("\nAfter deleting %ld \n", (intptr_t)ptr+4);
//    root = deleteNode(root, ptr+4);
//    preOrder(root);
//    printf("\nAfter deleting %ld \n",(intptr_t)ptr+8);
//    root = deleteNode(root, ptr+8);
//    preOrder(root);
    return 0;

}



