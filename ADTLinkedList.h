#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct ADTNode {
    int data;  
    struct ADTNode* ptrdiff; 
}; 

struct ADTNode* createADTNode(int data){

    struct ADTNode* node = (struct ADTNode*)malloc(sizeof(struct ADTNode)); 
    node->data = data; 
    node->ptrdiff = NULL; 
    return node; 
}

void printADTNodes(struct ADTNode** head ){

    struct ADTNode *curr0 = *head; 
    struct ADTNode *prev = NULL; 
    uintptr_t xor_ptr = ((uintptr_t)curr0->ptrdiff ^ (uintptr_t)prev); 
    do {
        printf("%i\n", curr0->data); 
        xor_ptr = ((uintptr_t)curr0->ptrdiff ^ (uintptr_t)prev); 
        prev = curr0; 
        curr0 = (struct ADTNode *)xor_ptr; 

    }
    while(xor_ptr); 
    return; 
}

void insertBeginningADTList(int data, struct ADTNode** head){
    struct ADTNode* node = createADTNode(data); 
    struct ADTNode* curr = *head; 
    uintptr_t xor_ptr = ((uintptr_t)curr ^ (uintptr_t)NULL); 
    node->ptrdiff = (struct ADTNode*)xor_ptr; 
    xor_ptr = ((uintptr_t)node ^ (uintptr_t)curr->ptrdiff);
    curr->ptrdiff = (struct ADTNode*)xor_ptr; 
    *head = node;  
}