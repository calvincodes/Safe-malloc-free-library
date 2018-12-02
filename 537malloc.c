//
// Created by Anshu on 12/1/18.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "537malloc.h"

void *malloc537(size_t size){
    if(size == 0){
        fprintf(stderr, "\nWarning : Size 0 provided for malloc\n");
    }
    void* ptr = malloc(size);
    insert(ptr, size);
    return ptr;
}
void free537(void *ptr){
    if(ptr == NULL){
        fprintf(stderr, "\nError : Given pointer is NULL\n");
        exit(-1);
    }
    disable(ptr);
    free(ptr);
}
void *realloc537(void *ptr, size_t size){
    if(ptr == NULL){
        return malloc537(size);
    } else if(size == 0){
        fprintf(stderr, "\nWarning : Size 0 provided for realloc537\n");
        free537(ptr);
        return NULL;
    } else {
        delete(ptr);
        void *newPtr = realloc(ptr, size);
        insert(newPtr, size);
        return newPtr;
    }
}
void memcheck537(void *ptr, size_t size){
    if(ptr == NULL){
        fprintf(stderr, "\nError : Requested pointer is NULL\n");
        exit(-1);
    }
    validateTreeNode(ptr, size);
}

