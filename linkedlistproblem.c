#include <stdio.h>
#include "singlylinkedlist.h"
typedef struct Stack
{
    int size;
    node *head;

} Stack;

Stack *createStack(data)
{
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack->head = createNode(data);
    return newStack;
}

void push(int data, Stack *stack)
{
    stack->size++;
    addBeginning(data, &stack->head);
}

void pop(Stack *stack)
{
    deleteBeginning(&(stack->head));
}

int peak(Stack *stack)
{
    int data = stack->head->data;
    return data;
}

int isEmptyStack(Stack *stack)
{
    if (stack->size)
    {
        return 1;
    }
    return 0;
}

void problem1()
{
    Stack *stack = createStack(0);
    deleteBeginning(&(stack->head));
    printf("%i\n", isEmptyStack(stack));
}

int main(void)
{
    problem1();
    return 0;
}