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
void deleteNodeBeginningDoublyNodeLinked(struct Node **head);
void deleteNodeEndDoublyNodeLinked(struct Node **head);
void deleteNodeMiddleDoublyNodeLinked(int deleteData, struct Node **head);

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
    ((*head)->next)->prev = *head;
}

void insertNodeMiddleDoublyLinked(int whereTo, int data, struct Node **head)
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
void deleteNodeBeginningDoublyNodeLinked(struct Node **head)
{
    struct Node *deleteNode = *head;
    free(deleteNode);
    *head = (*head)->next;
    (*head)->prev = NULL;
}

void deleteNodeEndDoublyNodeLinked(struct Node **head)
{
    struct Node *curr = *head;
    while ((curr->next)->next)
    {
        curr = curr->next;
    }
    struct Node *deleteNode = curr->next;
    curr->next = NULL;
    free(deleteNode);
}
void deleteNodeMiddleDoublyNodeLinked(int deleteData, struct Node **head)
{
    struct Node *curr = *head;
    while (curr->next)
    {
        if (curr->data == deleteData)
        {
            struct Node *deleteNode = curr;
            (curr->prev)->next = curr->next;
            (curr->next)->prev = curr->prev;
            free(deleteNode);
            return;
        }
        curr = curr->next;
    }
}

void printTest()
{
    printf("Hello world\n");
}