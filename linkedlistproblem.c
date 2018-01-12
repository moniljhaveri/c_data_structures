#include <stdio.h>
#include "singlylinkedlist.h"
#include "minunit.h"
int tests_run = 0;
typedef struct Stack
{
    int size;
    node *head;

} Stack;

Stack *createStack(data)
{
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack->head = createNode(data);
    newStack->size = 1;
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
    stack->size--;
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
int sizeStack(Stack *stack)
{
    return stack->size;
}

int findNthNode(Stack *stack, int n)
{
    int count = 1;
    node *curr = stack->head;
    while (curr)
    {
        if (count == n)
        {
            return curr->data;
        }
        count++;
        curr = curr->next;
    }
    return -1;
}

static char *problem2()
{
    Stack *stack = createStack(0);
    push(1, stack);
    push(1, stack);
    push(1, stack);
    push(1, stack);
    push(1, stack);
    push(2, stack);
    push(2, stack);
    push(2, stack);
    push(2, stack);
    push(2, stack);
    push(2, stack);
    push(2, stack);
    mu_assert("error  13 != size", sizeStack(stack) == 13);
    mu_assert("error  1 != 3rd node", findNthNode(stack, 3) == 2);
    mu_assert("error  -1 != 14th node", findNthNode(stack, 14) == -1);
    return 0;
}

static char *problem1()
{
    Stack *stack = createStack(0);
    mu_assert("error  1 == stackSize", sizeStack(stack) == 1);
    push(1, stack);
    mu_assert("error  2 != size", sizeStack(stack) == 2);
    mu_assert("error  1 != stack", peak(stack) == 1);
    pop(stack);
    pop(stack);
    int result = 1;
    mu_assert("error  0 != isEmptyStack(stack)", isEmptyStack(stack) == 0);
    return 0;
}
static char *run_problem1_tests()
{
    mu_run_test(problem1);
    mu_run_test(problem2);
    return 0;
}

int main(void)
{
    char *result = run_problem1_tests();
    if (result != 0)
    {
        printf("%s\n", result);
    }
    else
    {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}