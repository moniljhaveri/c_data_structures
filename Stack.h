#include <stdio.h> 
#include <stdlib.h> 

typedef struct Stack
{
    unsigned int size; 
    unsigned int idx; 
    int *data
} Stack; 

Stack* createStack()
{
    Stack *stack = (stack*)malloc(sizeof(Stack)); 
    stack.size = 2;  
    stack.idx = 0; 
    stack.data = (int*)malloc(sizeof(int) * stack.size); 
    return stack; 
}

void push(int data, Stack *stack)
{
    if((stack.idx + 1) == stack.size)
    {
        enlarge(stack); 
    }
    stack.data[stack.idx] = data; 
    stack.idx++; 
}

void enlarge(Stack *stack)
{
    int *arr = (int*)malloc(sizeof(int) * stack.size * 2); 
    
    for(int i = 0; i < stack.size; i++)
    {
        arr[i] = stack.data[i]; 
    }

    free(stack.data); 
    stack.data = arr; 
    stack.size *= 2; 
}

int top(Stack *stack)
{
    return stack.data[stack.idx]; 
}

void pop(Stack *stack)
{
    if(!stack.idx)
    {
        return; 
    }
    if(stack.idx == stack.size/4)
    {
        reduce(stack); 
    }
    stack.idx--; 
}
void reduce(Stack *stack)
{

    int *arr = (int*)malloc(sizeof(int) * (stack.size /4)); 
    
    for(int i = 0; i < (stack.size/4); i++)
    {
        arr[i] = stack.data[i]; 
    }

    free(stack.data); 
    stack.data = arr; 
    stack.size /= 4; 
}