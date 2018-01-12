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

int findNthNodeFromEnd(node **head, int n)
{
    node *pTemp = *head;
    node *pNth = NULL;
    for (int i = 0; i < n; i++)
    {
        pTemp = pTemp->next;
    }
    while (pTemp)
    {
        if (pNth == NULL)
        {
            pNth = *head;
        }
        else
        {
            pNth = pNth->next;
        }
        pTemp = pTemp->next;
    }
    if (pNth)
    {
        return pNth->data;
    }

    return -1;
}

static char *problem2()
{
    //find nth node from teh
    node *head = createNode(0);
    addBeginning(1, &head);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);
    addBeginning(5, &head);
    addBeginning(6, &head);
    mu_assert("error 1 != NthFromTheEnd ", findNthNodeFromEnd(&head, 1) == 1);
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