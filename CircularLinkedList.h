#include "DoublyLinkedList.h" 
#include <stdio.h>
#include <stdlib.h>

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
    while((curr->next)&&(curr->next != *head)); 

}