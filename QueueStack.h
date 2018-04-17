#include <stdio.h> 
#include <stdlib.h> 
#include "Stack.h"
typedef struct QueueStack 
{
    Stack *stack0; 
    Stack *stack1; 
} QueueStack; 

QueueStack* createQueueStack()
{
    QueueStack *q = (QueueStack*)malloc(sizeof(QueueStack)); 
    q->stack0 = createStack(); 
    q->stack1 = createStack(); 
    return q; 
}

void enque(int data, QueueStack* queueStack)
{
    push(data, queueStack->stack0);
}

void pump(QueueStack *qS)
{
    while(returnIdx(qS->stack0))
    {
        push(top(qS->stack0), qS->stack1); 
        pop(qS->stack0); 
    }
}

int queueTop(QueueStack* qS)
{
    if((returnIdx(qS->stack1) == 0) && (returnIdx(qS->stack0) == 0))
    {
        return -1; 
    }

    if((returnIdx(qS->stack1) == 0) && (returnIdx(qS->stack0)))
    {
        pump(qS); 
    }
    return top(qS->stack1); 
}

void deque(QueueStack* qS)
{
    if((returnIdx(qS->stack1) == 0) && (returnIdx(qS->stack0) == 0))
    {
        return -1; 
    }
    if((returnIdx(qS->stack1) == 0) && (returnIdx(qS->stack0)))
    {
        pump(qS); 
    }
    pop(qS->stack1); 
}