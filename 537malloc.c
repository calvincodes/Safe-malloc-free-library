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
    if(ptr == NULL){
        fprintf(stderr, "\nMalloc failed to allocate memory\n");
        exit(-1);
    }
    insert(ptr, size);
    return ptr;
}
void free537(void *ptr){
    if(ptr == NULL){
        fprintf(stderr, "\nError : Given pointer for free537 is NULL\n");
        exit(-1);
    }
    disable(ptr);
    free(ptr);
}
void *realloc537(void *ptr, size_t size){
    if(ptr == NULL){
        return malloc537(size);
    }  else if(size == 0){
        fprintf(stderr, "\nWarning : Size 0 provided for realloc537\n");
        free537(ptr);
        return NULL;
    } else {
        delete(ptr);
        void *newPtr = realloc(ptr, size);
        if(newPtr == NULL){
            fprintf(stderr, "\nRemalloc failed to allocate memory\n");
            exit(-1);
        }
        insert(newPtr, size);
        return newPtr;
    }
}
void memcheck537(void *ptr, size_t size){
    if(ptr == NULL){
        fprintf(stderr, "\nError : Given pointer for memcheck is NULL\n");
        exit(-1);
    }
    if(size == 0){
        fprintf(stderr, "\nWarning : Size 0 provided for memcheck\n");
    }
    validateTreeNode(ptr, size);
}

