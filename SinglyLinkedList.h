#ifndef __SINGLYLINKEDLIST_H
#define __SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct pNode
{
    node **data;
    struct pNode *next;
} pNode;

pNode *createPNode(node *data)
{
    pNode *pN = (pNode *)malloc(sizeof(pNode));
    pN->data = data;
    pN->next = NULL;
    return pN;
}
node *
createNode(int data)
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

void addEnd(int data, node **head)
{
    node *newNode = createNode(data);
    node *curr = *head;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = newNode;
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

node *createListOfSize(int n)
{
    node *head = createNode(0);
    for (int i = 1; i < n; i++)
    {
        addEnd(i, &head);
    }
    return head;
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

void deleteNodeCircular(node **head)
{
    node *curr = *head;
    node *copy = *head;
    node *next = curr->next;
    node *prev = NULL;
    if (curr->next == curr)
    {
        return;
    }
    do
    {
        prev = curr;
        curr = curr->next;

    } while (curr != copy);
    prev->next = next;
    *head = next;
    free(curr);
}

void printNode(node **head)
{
    node *curr = *head;
    node *copy = *head;

    while (curr)
    {
        printf("%i\n", curr->data);
        if (curr->next == copy)
        {
            return;
        }
        curr = curr->next;
    }

    return;
}

int *returnNodeArr(int n, node **head)
{
    int *returnArr = (int *)malloc(sizeof(int) * n);
    node *curr = *head;
    for (int i = 0; i < n; i++)
    {
        if (!curr)
        {
            printf("Error: Linked List is null \n");
            break;
        }
        returnArr[i] = curr->data;
        curr = curr->next;
    }
    return returnArr;
}
#endif