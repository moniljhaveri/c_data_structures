#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct ADTNode
{
    int data;
    struct ADTNode *ptrdiff;
};

struct ADTNode *createADTNode(int data)
{

    struct ADTNode *node = (struct ADTNode *)malloc(sizeof(struct ADTNode));
    node->data = data;
    node->ptrdiff = NULL;
    return node;
}

void printADTNodes(struct ADTNode **head)
{

    if (*head == NULL)
    {
        printf("No ADT Nodes allocated\n");
        return;
    }
    struct ADTNode *curr0 = *head;
    struct ADTNode *prev = NULL;
    uintptr_t xor_ptr = ((uintptr_t)curr0->ptrdiff ^ (uintptr_t)prev);
    do
    {
        printf("%i\n", curr0->data);
        xor_ptr = ((uintptr_t)curr0->ptrdiff ^ (uintptr_t)prev);
        prev = curr0;
        curr0 = (struct ADTNode *)xor_ptr;

    } while (xor_ptr);
    return;
}

void insertBeginningADTList(int data, struct ADTNode **head)
{
    struct ADTNode *node = createADTNode(data);
    struct ADTNode *curr = *head;
    uintptr_t xor_ptr = ((uintptr_t)curr ^ (uintptr_t)NULL);
    node->ptrdiff = (struct ADTNode *)xor_ptr;
    xor_ptr = ((uintptr_t)node ^ (uintptr_t)curr->ptrdiff);
    curr->ptrdiff = (struct ADTNode *)xor_ptr;
    *head = node;
}

void insertEndADTList(int data, struct ADTNode **head)
{
    struct ADTNode *node = createADTNode(data);
    struct ADTNode *curr = *head;
    struct ADTNode *prev = NULL;
    uintptr_t xor_ptr = ((uintptr_t)curr ^ (uintptr_t)prev);
    uintptr_t tmp_ptr = ((uintptr_t)curr ^ (uintptr_t)prev);
    while (xor_ptr)
    {
        xor_ptr = ((uintptr_t)curr->ptrdiff ^ (uintptr_t)prev);
        tmp_ptr = ((uintptr_t)curr->ptrdiff ^ (uintptr_t)node);
        prev = curr;
        curr = (struct ADTNode *)xor_ptr;
    }
    xor_ptr = ((uintptr_t)NULL ^ (uintptr_t)prev);
    node->ptrdiff = (struct ADTNode *)xor_ptr;
    prev->ptrdiff = (struct ADTNode *)tmp_ptr;
}

void deleteBeginningADTNode(struct ADTNode **head)
{
    struct ADTNode *curr = *head;
    struct ADTNode *prev = NULL;
    if (curr->ptrdiff == 0)
    {
        free(curr);
        *head = NULL;
        return;
    }
    struct ADTNode *nextNode = curr->ptrdiff;
    uintptr_t xor_ptr = ((uintptr_t)curr ^ (uintptr_t)nextNode->ptrdiff);
    nextNode->ptrdiff = (struct ADTNode *)xor_ptr;
    free(curr);
    *head = nextNode;
}
