#include <stdio.h>
#include <stdlib.h>

struct Node
{
    // singly linked list
    int data;
    struct Node *next;
};
struct Node *traverseLinkedList(struct Node *node);
void addNodeEnd(int data, struct Node *linkedList);
struct Node *createNode(int data);
struct Node *deleteNode(int data, struct Node *head);
void addNodeBeginning(int data, struct Node **head_ptr, struct Node *head);

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

void addNodeEnd(int data, struct Node *linkedList)
{
    struct Node *newNode = createNode(data);
    struct Node *endNode = traverseLinkedList(linkedList);
    endNode->next = newNode;
}

void addNodeBeginning(int data, struct Node **head_ptr, struct Node *head)
{
    struct Node *newHead = createNode(data);
    newHead->next = head;
    *head_ptr = newHead;
}

struct Node *deleteNode(int data, struct Node *node)
{
    struct Node *head = node;
    struct Node *prevNode;
    if (node->data == data)
    {
        if (node->next != NULL)
        {
            head = node->next;
            return head;
        }
        free(node);
        free(head);
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
    addNodeEnd(11, head);
    addNodeEnd(12, head);
    addNodeEnd(13, head);
    addNodeEnd(14, head);
    addNodeEnd(15, head);
    head = lList;
    head = deleteNode(10, head);
    head = deleteNode(11, head);
    head = deleteNode(12, head);
    head = deleteNode(13, head);
    head = deleteNode(14, head);
    addNodeBeginning(10, &head, head);
    addNodeBeginning(11, &head, head);
    addNodeBeginning(12, &head, head);
    addNodeBeginning(13, &head, head);
    addNodeBeginning(14, &head, head);
    printData(head);
    return 0;
}