#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "SinglyLinkedList.h"

typedef struct Stack
{
    unsigned int size;
    unsigned int idx;
    int *data
} Stack;

typedef struct DoubleStack
{
    unsigned int size;
    unsigned int idf;
    unsigned int idb;
    int *data;
} DoubleStack;

typedef struct IStack
{
    unsigned int size;
    unsigned int *idx;
    unsigned int i;
    unsigned int slot;
    int *data;

} IStack;

typedef struct NodeStack
{
    unsigned int size;
    unsigned int idx;
    NodeStack *top;
} NodeStack;

NodeStack *createNodeStack()
{
    NodeStack *nodeStack = (NodeStack *)malloc(sizeof(NodeStack));
    nodeStack->size = 0;
    nodeStack->idx = 0;

    return nodeStack;
}

DoubleStack *
createDoubleStack()
{
    DoubleStack *dS = (DoubleStack *)malloc(sizeof(DoubleStack));
    dS->size = 4;
    dS->data = (int *)malloc(sizeof(int) * dS->size);
    dS->idf = 0;
    dS->idb = dS->size - 1;
    return dS;
}

void dsEnlarge(DoubleStack *dS)
{
    int *newArr = (int *)malloc(sizeof(int) * dS->size * 2);
    for (int i = 0; i <= dS->idf; i++)
    {
        newArr[i] = dS->data[i];
    }
    for (int i = dS->idb; i < dS->size; i++)
    {
        newArr[i + dS->size - 1] = dS->data[i];
    }
    free(dS->data);
    dS->data = newArr;
}

void pushFront(int data, DoubleStack *dS)
{
    dS->data[dS->idf] = data;
    dS->idf++;
    if (dS->idf == (dS->size / 2))
    {
        dsEnlarge(dS);
    }
}

void pushBack(int data, DoubleStack *dS)
{
    dS->data[dS->idb] = data;
    dS->idb--;
    if (dS->idb == (dS->size / 2))
    {
        dsEnlarge(dS);
    }
}

int topFront(DoubleStack *dS)
{
    if (dS->idf == 0)
    {
        return -1;
    }
    return dS->data[dS->idf - 1];
}
int topBack(DoubleStack *dS)
{
    if (dS->idb == dS->size)
    {
        return -1;
    }
    return dS->data[dS->idb + 1];
}

void popFront(DoubleStack *dS)
{
    dS->idf--;
}

void popBack(DoubleStack *dS)
{
    dS->idb++;
}

unsigned int returnDSSize(DoubleStack *dS)
{
    return dS->size;
}

unsigned int returnSize(Stack *stack)
{
    return (stack->size);
}

unsigned int returnIdx(Stack *stack)
{
    return (stack->idx);
}

void reduce(Stack *stack)
{

    int *arr = (int *)malloc(sizeof(int) * (stack->size / 4));

    for (int i = 0; i < (stack->size / 4); i++)
    {
        arr[i] = stack->data[i];
    }

    free(stack->data);
    stack->data = arr;
    stack->size /= 4;
}

void enlarge(Stack *stack)
{
    int *arr = (int *)malloc(sizeof(int) * stack->size * 2);

    for (int i = 0; i < stack->size; i++)
    {
        arr[i] = stack->data[i];
    }

    free(stack->data);
    stack->data = NULL;
    stack->data = arr;
    stack->size *= 2;
}

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = 2;
    stack->idx = 0;
    stack->data = (int *)malloc(sizeof(int) * stack->size);
    return stack;
}

void push(int data, Stack *stack)
{
    if ((stack->idx + 1) == stack->size)
    {
        enlarge(stack);
    }
    stack->data[stack->idx] = data;
    stack->idx++;
}

int top(Stack *stack)
{
    if (stack->idx)
    {

        return stack->data[stack->idx - 1];
    }
    return stack->data[stack->idx];
}

void pop(Stack *stack)
{
    if (!stack->idx)
    {
        return;
    }
    if (stack->idx == stack->size / 4)
    {
        reduce(stack);
    }
    stack->idx--;
}
int *returnStack(int n, Stack *stack)
{
    int *arr = malloc(sizeof(int) * n);
    for (int i = n - 1; i > -1; --i)
    {
        arr[i] = stack->data[n - i - 1];
    }
    return arr;
}

IStack *createIthStack(int n)
{
    IStack *iStack = (IStack *)malloc(sizeof(IStack));
    iStack->size = 2 * n;
    iStack->data = (int *)malloc(sizeof(int) * 2 * n);
    iStack->idx = (int *)malloc(sizeof(int) * n);
    iStack->slot = 2;
    iStack->i = n;
    for (int i = 0; i < n; ++i)
    {
        iStack->idx[i] = i * iStack->slot;
    }
    return iStack;
}

void ithEnlarge(IStack *iS)
{
    int *newArr = (int *)malloc(sizeof(int) * 2 * iS->slot * iS->i);
    int n = iS->i;
    int k = iS->slot;
    iS->slot *= 2;
    iS->size *= 2;

    /*
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < k; j++) 
        {
            newArr[i*2 + j] = iS->data[i + j]; 
        } 
        iS->idx[i] = (iS->idx[i] - i*iS->slot) + (i*iS->slot * 2); 
    }
*/

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            newArr[i * 2 * k + j] = iS->data[i * k + j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        iS->idx[i] += k * i;
    }

    free(iS->data);
    iS->data = NULL;
    iS->data = newArr;
}

void pushIthStack(int i, int data, IStack *iS)
{
    if (iS->idx[i - 1] == (i * iS->slot - 1))
    {
        ithEnlarge(iS);
    }
    iS->data[iS->idx[i - 1]] = data;
    iS->idx[i - 1]++;
}

void popIthStack(int i, IStack *iS)
{
    iS->idx[i - 1]--;
}

int topIthStack(int i, IStack *iS)
{
    return iS->data[iS->idx[i - 1] - 1];
}

#endif