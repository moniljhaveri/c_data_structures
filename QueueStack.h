#include <stdio.h> 
#include <stdlib.h> 
#include <Stack.h> 

typedef struct QueueStack 
{
    Stack *stack0; 
    Stack *stack1; 
} QueueStack; 

QueueStack* createQueueStack()
{
    QueueStack *q = (QueueStack*)malloc(sizeof(QueueStack)); 
    return q; 
}

void enque(int data, QueueStack* queueStack)
{
    push(data, queueStack->stack0);
}
