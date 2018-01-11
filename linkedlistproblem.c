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

static char *problem1()
{
    Stack *stack = createStack(0);
    deleteBeginning(&(stack->head));
    int result = 1;
    mu_assert("error  0 != isEmptyStack(stack)", isEmptyStack(stack) == 0);
    return 0;
}
static char *run_problem1_tests()
{
    mu_run_test(problem1);
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