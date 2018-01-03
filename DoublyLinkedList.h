#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *createNode(int data);
void insertNodeDoublyLinked(int data, struct Node **head);

struct Node *createNode(int data)
{
    // creates and allocates the memory for a doubly linked list
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertNodeBeginningDoublyLinked(int data, struct Node **head)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertNodeMiddleLinked(int whereTo, int data, struct Node **head)
{
    struct Node *node = createNode(data);
    struct Node *curr = *head;

    while (curr->next)
    {
        if (curr->data == whereTo)
        {
            node->next = curr->next;
            (curr->next)->prev = node;
            node->prev = curr;
            curr->next = node;
        }
        curr = curr->next;
    }
    return;
}

void printTest()
{
    printf("Hello world\n");
}