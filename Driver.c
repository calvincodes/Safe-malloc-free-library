//
// Created by Anshu on 12/1/18.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "Driver.h"

void *malloc537(size_t size){
    if(size == 0){
        fprintf(stderr, "Warning : Size 0 provided for malloc");
    }
    void* ptr = malloc(size);
    insert(ptr, size);
    return ptr;
}
void free537(void *ptr){
    if(ptr == NULL){
        fprintf(stderr, "Error : Requested pointer is NULL");
        exit(-1);
    }
    delete(ptr);
    free(ptr);
}
void *realloc537(void *ptr, size_t size){
    if(ptr == NULL){
        return malloc537(size);
    } else if(size == 0){
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

}
