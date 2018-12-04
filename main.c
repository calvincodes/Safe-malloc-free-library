#include <stdio.h>
#include <stdlib.h>

#ifndef MALLOC_LIBRARY_DRIVER_H
#define MALLOC_LIBRARY_DRIVER_H
#include "Driver.h"
#endif //MALLOC_LIBRARY_DRIVER_H

int main(){

    int *ptr = (int*)malloc537(10 * sizeof(int));
    int *ptr2 = (int*)malloc537(10 * sizeof(int));
    int *ptr3 = (int*)malloc537(10 * sizeof(int));
    int *ptr4 = (int*)malloc537(10 * sizeof(int));
//    free537(ptr);
    memcheck537(ptr+6, 1 * sizeof(int));
    memcheck537(ptr2+6, 3 * sizeof(int));
//    free537(ptr);
//    free537(ptr2);
//
//    int *ptr1 = (int*)malloc537(10 * sizeof(int));
//    free537(ptr1);

//    printf("%p\n", ptr);
//    TreeNode *root = NULL;
//    root = insert(root, ptr,1);
//    root = insert(root, ptr+1,1);
//    root = insert(root, ptr+2,1);
//    root = insert(root, ptr+3,1);
//    root = insert(root, ptr+4,1);
//    root = insert(root, ptr+5,1);
//    root = insert(root, ptr+6,1);
//    root = insert(root, ptr+7,1);
//    root = insert(root, ptr+8,1);
//    preOrder(root);
//    if(search(root, ptr+5)){
//        printf("\nSearch is working fine");
//    } else {
//        printf("\nSearch is failing");
//    }
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



