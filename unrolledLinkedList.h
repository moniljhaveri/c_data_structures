#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
struct node
{
    int data;
    struct node *ptrdiff;
};

struct nodeBlock
{
    int size;
    int currSize;
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
    node->ptrdiff = node;
    return node;
}

void insertNode(int data, struct node **head)
{
    struct node *curr = *head;
}

struct nodeBlock *initNodeBlock(int data, int size)
{
    struct nodeBlock *nodeBlock = (struct nodeBlock *)malloc(sizeof(nodeBlock));
    nodeBlock->ptrdiff = NULL;
    nodeBlock->size = size;
    if (size)
    {
        nodeBlock->head = initNode(data);
    }
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
    struct node *prev = NULL;
    uintptr_t xor_ptr = ((uintptr_t)curr ^ (uintptr_t)prev);
    do
    {
        printf("%i\n", curr->data);
        xor_ptr = ((uintptr_t)curr->ptrdiff ^ (uintptr_t)prev);
        curr = prev;
        curr = (struct node *)xor_ptr;
    } while (xor_ptr != (uintptr_t)*head);
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
        curr = prev;
        curr = (struct nodeBlock *)xor_ptr;
        count++;

    } while (xor_ptr);
}