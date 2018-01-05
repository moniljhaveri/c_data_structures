#include "DoublyLinkedList.h" 
#include <stdio.h>
#include <stdlib.h>

void insertEndCircularNode(int data, struct Node ** head); 
struct Node* initCircularNode(int data){
    struct Node* head = createNode(data); 
    head->next = head; 
    head->prev = head; 
    return head; 
}

int countCircularNode(struct Node** head){
    struct Node* curr = *head; 
    int count = 1;
    while((curr->next)&&(curr->next != *head)){
        count++; 
        curr = curr->next; 
    } 
    return count; 
}
void insertBeginningCircularNode(int data, struct Node** head){
    struct Node* curr = *head; 
    struct Node* newNode = createNode(data); 
    while((curr->next != *head)){
        curr = curr->next; 
    }
    curr->next = newNode; 
    newNode->next = *head; 
    newNode->prev = (*head)->prev; 
    (*head)->prev = newNode; 
    *head = newNode; 
}

void insertEndCircularNode(int data, struct Node ** head){
    struct Node* newNode = createNode(data); 
    struct Node* curr = *head;
    while(curr->next != *head){
        curr = curr->next; 
    }
    curr->next = newNode;
    newNode->prev = curr; 
    newNode->next = *head; 

}

void printCircular(struct Node** head){
    struct Node* curr = *head; 

    //printf("%i test \n", (*head)->data); 
    if(*head == NULL){
        return; 
    }

    do{
        printf("%i\n", curr->data); 
        curr = curr->next; 
    }
    while(curr != *head); 

}