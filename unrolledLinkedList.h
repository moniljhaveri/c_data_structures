#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
struct node
{
    // cannot do circular linked list with xor linked list
    // changing to singulary linked list
    int data;
    struct node *next;
};

struct nodeBlock
{
    int maxNodes;
    int currNodes;
    struct node *head;
    struct nodeBlock *ptrdiff;
};

struct node *createNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(node));
    node->data = data;
    return node;
}

struct node *initNode(int data)
{
    struct node *node = createNode(data);
    node->next = node;
    return node;
}

struct nodeBlock *initNodeBlock(int data, int size)
{
    struct nodeBlock *nodeBlock = (struct nodeBlock *)malloc(sizeof(nodeBlock));
    nodeBlock->ptrdiff = NULL;
    if (size == 0)
    {
        return nodeBlock;
    }
    nodeBlock->maxNodes = size;
    nodeBlock->head = initNode(data);
    nodeBlock->currNodes++;
    return nodeBlock;
}

void printNode(struct node **head)
{
    if (*head == NULL)
    {
        printf("No nodes allocated\n");
        return;
    }
    struct node *curr = *head;
    do
    {
        printf("%i\n", curr->data);
        curr = curr->next;
    } while (curr != *head);
}

void printBlock(struct nodeBlock **block)
{
    struct nodeBlock *curr = *block;
    struct nodeBlock *prev = NULL;
    uintptr_t xor_ptr = ((uintptr_t)curr->ptrdiff ^ (uintptr_t)prev);
    int count = 0;
    do
    {
        printf("Block %i\n", count);
        printNode(&curr->head);
        xor_ptr = ((uintptr_t)curr->ptrdiff ^ (uintptr_t)prev);
        prev = curr;
        curr = (struct nodeBlock *)xor_ptr;
        count++;

    } while (xor_ptr);
}

void insertNode(int data, struct node **head)
{
    struct node *curr = *head;
    struct node *newNode = createNode(data);
    newNode->next = curr;
    while (curr->next != *head)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    *head = newNode;
}

void insertData(int data, struct nodeBlock **block)
{

    struct nodeBlock *curr = *block;
    struct nodeBlock *prev = NULL;
    struct nodeBlock *newBlock = initNodeBlock(data, curr->maxNodes);
    uintptr_t xor_ptr = ((uintptr_t)curr ^ (uintptr_t)prev);
    uintptr_t tmp_ptr = ((uintptr_t)curr ^ (uintptr_t)prev);
    while (xor_ptr)
    {
        xor_ptr = ((uintptr_t)curr->ptrdiff ^ (uintptr_t)prev);
        tmp_ptr = ((uintptr_t)curr->ptrdiff ^ (uintptr_t)newBlock);
        prev = curr;
        curr = (struct nodeBlock *)xor_ptr;
    }
    if (prev->currNodes >= prev->maxNodes)
    {
        xor_ptr = ((uintptr_t)NULL ^ (uintptr_t)prev);
        newBlock->ptrdiff = (struct nodeBlock *)xor_ptr;
        prev->ptrdiff = (struct nodeBlock *)tmp_ptr;
    }
    else
    {
        insertNode(data, &prev->head);
        prev->currNodes++;
        free(newBlock);
    }
}