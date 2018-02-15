#ifndef RANDOMIZEDLINKLIST_H
#define RANDOMIZEDLINKLIST_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef struct rand_node
{
    int data;
    struct rand_node *next;
    struct rand_node *rand;
} rand_node;

rand_node *createRandLinkList(int n)
{
    srand(time(NULL));
    rand_node *head = (rand_node *)malloc(sizeof(rand_node));
    head->data = 0;
    rand_node *curr = head;
    for (int i = 1; i < n; i++)
    {
        rand_node *newNode = (rand_node *)malloc(sizeof(rand_node));
        newNode->data = i;
        newNode->next = NULL;
        curr->next = newNode;
        curr = curr->next;
    }

    curr = head;
    rand_node *copy = head;
    while (curr)
    {
        int randN = (rand() % n);
        for (int i = 0; i < randN; ++i)
        {
            copy = copy->next;
        }
        curr->rand = copy;
        copy = head;
        curr = curr->next;
    }
    return head;
}

void printRandNode(rand_node **head)
{
    rand_node *curr = *head;
    rand_node *copy = *head;

    while (curr)
    {
        printf("curr %i rand %i \n", curr->data, curr->rand->data);
        if (curr->next == copy)
        {
            return;
        }
        curr = curr->next;
    }

    return;
}

char *returnRandNodeArr(int n, rand_node **head)
{
    int *arr = (int *)malloc(sizeof(int) * n * 2);
    rand_node *curr = *head;
    for (int i = 0; i < 2 * n - 1; i = i + 2)
    {
        arr[i] = curr->data;
        arr[i + 1] = curr->rand->data;
        curr = curr->next;
    }
    return arr;
}
#endif