# README #

# A Safe malloc/free library
## Authors

* **Arpit Jain**
* **Anshu Verma**


A tool to check for memory errors, dynamic memory 
head allocation and check for memory allocation errors

## Task List

This project is divided in the following major modules.

* **malloc537**:
    * allocating the memory by calling malloc()
    * this function will record a tuple (addri, leni), for the memory that you allocate in the heap. 
    
* **free537**:
    * This function will first check to make sure that freeing the memory specified by ptr makes sense, then will call free() to do the actual free. *
    * Freeing memory that has not be allocated with malloc537(). *
    * Freeing memory that is not the first byte of the range of memory that was allocated. *
    * Freeing memory that was previously freed (double free). *
* **realloc537**:    
    * If ptr is NULL,then this follows the specification of malloc537()*
    * If size is zero and ptr is not NULL,then this follows the specification of free537()*
    **
* **memcheck537**:
   * This function checks to see the address range specified by address ptr and length size are fully within a range allocated by malloc537() and memory not yet freed by free537()*
   * When an error is detected, then print out a detailed and informative error message and exit the program (with a -1 status)*

