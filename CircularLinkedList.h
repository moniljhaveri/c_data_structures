#include "DoublyLinkedList.h" 

struct Node* initCircularNode(int data){
    struct Node* head = createNode(data); 
    head->next = head; 
    head->prev = head; 
    return head; 
}

int countCircularNode(struct Node** head){
    struct Node* curr = *head; 
    int count = 1;
    while((curr->next)&&(curr != *head)){
        count++; 
        curr = curr->next; 
    } 
    return count; 

}