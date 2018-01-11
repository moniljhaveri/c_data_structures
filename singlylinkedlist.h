#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode(int data)
{
    node *nodeR = (node *)malloc(sizeof(node));
    nodeR->data = data;
    return nodeR;
}
void addBeginning(int data, node **head)
{
    node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void deleteBeginning(node **head)
{
    if (*head == NULL)
    {
        return;
    }
    node *copyNode = *head;
    if ((*head)->next == NULL)
    {
        *head = NULL;
    }
    else
    {
        *head = (*head)->next;
    }
    free(copyNode);
}