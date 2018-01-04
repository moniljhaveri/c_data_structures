#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
/*
struct Node
{
    // singly linked list
    int data;
    struct Node *next;
};
*/
struct Node *traverseLinkedList(struct Node *node);
void addNodeEnd(int data, struct Node *linkedList);
struct Node *deleteNode(int data, struct Node *head);
void addNodeBeginning(int data, struct Node **head_ptr, struct Node *head);
void addNodeMiddle(int whereTo, int data, struct Node *head);
void deleteFirstNode(struct Node **head);
void deleteLastNode(struct Node *head);

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
void addNodeMiddle(int whereTo, int data, struct Node *head)
{
    struct Node *nodeToAdd = createNode(data);
    struct Node *cur = head;
    while (cur)
    {
        if (cur->data == whereTo)
        {

            nodeToAdd->next = cur->next;
            cur->next = nodeToAdd;
            return;
        }
        cur = cur->next;
    }
}
void deleteFirstNode(struct Node **head)
{
    struct Node **pp;
    pp = (*head)->next;
    *head = pp;
}
void deleteLastNode(struct Node *head)
{

    while ((head->next)->next)
    {
        head = head->next;
    }
    head->next = NULL;
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
    /*
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
    addNodeMiddle(14, 55, head);
    addNodeMiddle(14, 56, head);
    addNodeMiddle(14, 57, head);
    addNodeMiddle(14, 58, head);
    printData(head);
    deleteFirstNode(&head);
    printf("\n");
    printData(head);
    deleteLastNode(head);
    printf("\n");
    printData(head);
    struct Node *head;
    struct Node *doublyLinkedList = createNode(2);
    head = doublyLinkedList;
    insertNodeBeginningDoublyLinked(3, &head);
    insertNodeBeginningDoublyLinked(4, &head);
    insertNodeBeginningDoublyLinked(2, &head);
    insertNodeBeginningDoublyLinked(5, &head);
    printData(head);
    printf("\n");
    insertNodeMiddleDoublyLinked(3, 100, &head);
    deleteNodeBeginningDoublyNodeLinked(&head);
    deleteNodeEndDoublyNodeLinked(&head);
    printData(head);
    printf("Delete Middle\n");
    deleteNodeMiddleDoublyNodeLinked(3, &head);
    printData(head);
    */
    struct Node* head = initCircularNode(0); 
    int count = countCircularNode(&head); 
    insertBeginningCircularNode(3, &head); 
    insertBeginningCircularNode(4, &head); 
    insertBeginningCircularNode(5, &head); 
    printCircular(&head); 
    return 0;
}