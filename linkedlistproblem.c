#include <stdio.h>
#include "SinglyLinkedList.h"
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
int checkForCircular(node **head)
{
    node *slowPtr = *head;
    node *fastPtr = *head;
    while (slowPtr)
    {
        if (fastPtr->next)
        {

            fastPtr = fastPtr->next->next;
        }
        else
        {
            return 0;
        }

        slowPtr = slowPtr->next;
        if ((slowPtr == NULL) || (fastPtr == NULL))
        {
            return 0;
        }
        if (slowPtr == fastPtr)
        {
            return 1;
        }
    }
}
int fastStartCircularNode(node **head)
{
    // a faster way to answer question 10
    node *slowPtr = *head;
    node *fastPtr = *head;

    while (fastPtr && slowPtr && fastPtr->next)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
        if (slowPtr == fastPtr)
        {
            break;
        }
    }
    slowPtr = *head;
    while (slowPtr != fastPtr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }

    return fastPtr->data;
}
int findStartingCircularNode(node **head)
{
    node *slowPtr = *head;
    node *fastPtr = *head;
    while (fastPtr->next && fastPtr && slowPtr)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
        if (slowPtr == fastPtr)
        {
            break;
        }
    }
    node *checkPtr = fastPtr;
    slowPtr = *head;
    while (1)
    {
        fastPtr = fastPtr->next;
        while (fastPtr->next != checkPtr)
        {
            if (fastPtr == slowPtr)
            {
                return fastPtr->data;
            }
            fastPtr = fastPtr->next;
        }
        slowPtr = slowPtr->next;
    }
    return 0;
}
int findLengthOfLinkedList(node **head)
{
    node *slowPtr = *head;
    node *fastPtr = *head;
    int count = 0;
    int isCycle = 0;
    while (fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            isCycle = 1;
            break;
        }
    }
    slowPtr = *head;
    if (isCycle)
    {
        while (slowPtr != fastPtr)
        {

            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
            count++;
        }
        fastPtr = fastPtr->next;
        count++;
        while (slowPtr != fastPtr)
        {

            fastPtr = fastPtr->next;
            count++;
        }
    }
    else
    {
        while (slowPtr)
        {
            count++;
            slowPtr = slowPtr->next;
        }
    }

    return count;
}

static char *problem14()
{
    node *head = createCircularList(0);
    addToCircularList(1, &head);
    addToCircularList(2, &head);
    addToCircularList(3, &head);
    addToCircularList(4, &head);
    addBeginning(100, &head);
    addBeginning(110, &head);

    node *sHead = createNode(0);
    addBeginning(1, &sHead);
    addBeginning(2, &sHead);
    addBeginning(3, &sHead);
    addBeginning(4, &sHead);

    mu_assert("error 7 != findLengthOfLinkedList", 7 == findLengthOfLinkedList(&head));
    mu_assert("error 5 != findLengthOfLinkedList", 5 == findLengthOfLinkedList(&sHead));
    return 0;
}

static char *problem11()
{
    node *head = createCircularList(0);
    addToCircularList(1, &head);
    addToCircularList(2, &head);
    addToCircularList(3, &head);
    addToCircularList(4, &head);
    addBeginning(100, &head);
    addBeginning(110, &head);
    int ans = -1;
    if (checkForCircular(&head))
    {
        ans = findStartingCircularNode(&head);
    }
    mu_assert("error 4 != findStartCircularNode", 4 == findStartingCircularNode(&head));
    mu_assert("error 4 != fastStartCircularNode", 4 == fastStartCircularNode(&head));
    return 0;
}
static char *problem6()
{
    //find if a linked list is
    node *head = createCircularList(0);
    addToCircularList(1, &head);
    addToCircularList(2, &head);
    addToCircularList(3, &head);
    addToCircularList(4, &head);
    addBeginning(100, &head);
    addBeginning(110, &head);

    node *sHead = createNode(0);
    addBeginning(1, &sHead);
    addBeginning(2, &sHead);
    addBeginning(3, &sHead);
    addBeginning(4, &sHead);
    mu_assert("error 1 != checkForCircular", checkForCircular(&head) == 1);
    mu_assert("error 0 != checkForCircular", checkForCircular(&sHead) == 0);
    return 0;
}

static char *problem2()
{
    //find nth node from the end
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
static char *run_problem_tests()
{
    mu_run_test(problem1);
    mu_run_test(problem2);
    mu_run_test(problem6);
    mu_run_test(problem11);
    mu_run_test(problem14);
    return 0;
}

int main(void)
{
    char *result = run_problem_tests();
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