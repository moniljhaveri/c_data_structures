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
    nodeR->next = NULL;
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

node *createCircularList(int data)
{
    node *head = createNode(data);
    head->next = head;
    return head;
}

void addToCircularList(int data, node **head)
{
    node *newNode = createNode(data);
    node *curr = *head;
    while (curr->next != *head)
    {
        curr = curr->next;
    }
    newNode->next = *head;
    curr->next = newNode;
    *head = newNode;
}

void printNode(node **head)
{
    node *curr = *head;
    int checkCircular = 0;
    while (curr)
    {
        printf("%i\n", curr->data);
        if (curr->next == *head)
        {
            return;
        }
        curr = curr->next;
    }
    return;
}