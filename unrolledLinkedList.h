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
