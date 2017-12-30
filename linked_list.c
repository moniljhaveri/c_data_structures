#include <stdio.h>
#include <stdlib.h>

struct Node
{
    // singly linked list
    int data;
    struct Node *next;
};
struct Node *traverseLinkedList(struct Node *node);
void addNode(int data, struct Node *linkedList);
struct Node *createNode(int data);
struct Node *deleteNode(int data, struct Node *head);

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
struct Node *traverseLinkedList(struct Node *node)
{
    while (node->next)
    {
        node = node->next;
    }
    return node;
}
void addNode(int data, struct Node *linkedList)
{
    struct Node *newNode = createNode(data);
    struct Node *endNode = traverseLinkedList(linkedList);
    endNode->next = newNode;
}

struct Node *deleteNode(int data, struct Node *node)
{
    struct Node *head = node;
    struct Node *prevNode;
    if (node->data == data)
    {
        head = node->next;
        return head;
    }
    prevNode = node;
    node = node->next;
    while (node != NULL)
    {
        if (node->data == data)
        {
            prevNode->next = node->next;
            return head;
        }
        prevNode = node;
        node = node->next;
    }
    return head;
}
void printData(struct Node *node)
{
    while (node->next != NULL)
    {
        printf("%i\n", node->data);
        node = node->next;
    }
    printf("%i\n", node->data);
}
int main()
{
    struct Node *head;
    struct Node *lList = createNode(10);
    head = lList;
    addNode(11, head);
    addNode(12, head);
    addNode(13, head);
    addNode(14, head);
    addNode(15, head);
    head = lList;
    head = deleteNode(10, head);
    printData(head);
    printf("\n");
    head = deleteNode(15, head);
    printData(head);
    return 0;
}