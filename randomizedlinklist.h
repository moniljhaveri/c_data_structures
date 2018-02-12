#ifndef RANDOMIZEDLINKLIST_H
#define RANDOMIZEDLINKLIST_H
#include <stdlib.h>
#include <time.h>
typedef struct rand_node
{
    int data;
    rand_node *next;
    rand_node *rand;
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
        curr->next = newNode;
        curr = curr->next;
    }

    curr = head;
    rand_node *copy = head;
    while (curr)
    {
        int randN = rand() % n;
        for (int i = 0; i < randN; ++i)
        {
            copy = copy->next;
        }
        curr->rand = copy;
        copy = head;
        curr = curr->next;
    }

    while (curr)
    {
    }
}

#endif