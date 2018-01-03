#include "DoublyLinkedList" 

struct Node* initCircularNode(int data){
    struct Node* head = createNode(data); 
    head->next = head; 
    head->prev = head; 

}