#include <stdio.h>
#include "SinglyLinkedList.h"
#include "RandomizedLinkList.h"
#include <math.h>
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
    return 0;
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
void insertSortedList(int data, node **head)
{
    node *curr = *head;
    node *prev = NULL;
    node *newNode = createNode(data);
    if (data <= curr->data)
    {
        newNode->next = curr;
        *head = newNode;
        return;
    }
    while (curr->next)
    {
        if (data < curr->data)
        {
            newNode->next = curr;
            prev->next = newNode;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    curr->next = newNode;
}
int returnNodePosition(int position, node **head)
{
    int count = 0;
    node *curr = *head;
    while (curr)
    {
        if (position == count)
        {
            return curr->data;
        }
        count++;
        curr = curr->next;
    }
    return -1;
}
void reverseLinkedList(node **head)
{
    node *curr = *head;
    node *prev = NULL;
    node *next = curr->next;

    while (next)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    *head = curr;
}
void recursiveReverseLinkedList(node **head, node **prev, node **head_ptr)
{
    node *curr = *head;
    if (curr == NULL)
    {
        return;
    }
    node *next = curr->next;
    node *p = *prev;
    if (p->data == -1)
    {
        p = NULL;
    }
    if (curr->next == NULL)
    {
        *head_ptr = curr;
    }
    curr->next = p;
    recursiveReverseLinkedList(&next, &curr, &*head_ptr);
}

void createBranchList(node **head, node **end, int position)
{
    node *endNode = *end;
    node *curr = *head;
    int count = 0;
    while (endNode->next)
    {
        endNode = endNode->next;
    }
    while (position != count)
    {
        curr = curr->next;
        count++;
    }
    endNode->next = curr;
}
int findIntersectionNode(node **head1, node **head2)
{
    node *curr1 = *head1;
    while (curr1)
    {
        node *curr2 = *head2;
        while (curr2)
        {
            if (curr1 == curr2)
            {
                return curr1->data;
            }
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
    return 0;
}
int fastIntersectionNode(node **head1, node **head2)
{
    int count1 = 0;
    int count2 = 0;
    node *curr1 = *head1;
    node *curr2 = *head2;

    while (curr1)
    {
        count1++;
        curr1 = curr1->next;
    }
    while (curr2)
    {
        count2++;
        curr2 = curr2->next;
    }
    node *largestList = (count1 > count2) ? *head1 : *head2;
    node *smallestList = (count1 < count2) ? *head1 : *head2;
    int numSteps = abs(count1 - count2);
    for (int i = 0; i < numSteps; i++)
    {
        largestList = largestList->next;
    }
    while (largestList)
    {
        if (largestList == smallestList)
        {
            return smallestList->data;
        }
        largestList = largestList->next;
        smallestList = smallestList->next;
    }

    return 0;
}

int findMiddleLinkedList(node **head)
{
    node *slowPtr = *head;
    node *fastPtr = *head;
    while (fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr->data;
}

void addNodeEnd(node **head, int data)
{
    node *curr = *head;
    while (curr->next)
    {
        curr = curr->next;
    }
    node *newNode = createNode(data);
    curr->next = newNode;
}

node *copyLinkedList(node **head)
{
    node *curr = *head;
    node *newList = createNode(curr->data);
    curr = curr->next;
    while (curr)
    {
        addNodeEnd(&newList, curr->data);
        curr = curr->next;
    }
    return newList;
}

void displayNodeFromEnd(node **head)
{
    node *copiedList = copyLinkedList(head);
    reverseLinkedList(&copiedList);
    while (copiedList)
    {
        printf("%i\n", copiedList->data);
        copiedList = copiedList->next;
    }
}
void printReverseLinkedList(node **head)
{
    if (!*head)
    {
        return;
    }
    printReverseLinkedList(&(*head)->next);
    printf("%d \n", (*head)->data);
}

int recursiveEvenOddLinkedList(node **head, int count)
{
    if (!*head)
    {
        return (count % 2);
    }
    return recursiveEvenOddLinkedList(&(*head)->next, ++count);
}
int iterativeEvenOddLinkedList(node **head)
{
    node *curr = *head;
    while (curr && curr->next)
    {
        curr = curr->next->next;
    }
    if (curr)
    {
        return 1;
    }
    return 0;
}
node *efficientMergeSort(node **head1, node **head2)
{
    node *curr1 = *head1;
    node *curr2 = *head2;
    node *itPtr = curr1->data < curr2->data ? curr1 : curr2;
    node *returnPtr = itPtr;
    node *largePtr = curr1->data < curr2->data ? curr2 : curr1;
    node *prev = NULL;
    while (itPtr)
    {
        if (itPtr->data > largePtr->data)
        {
            prev->next = largePtr;
            node *tmpPtr = itPtr;
            itPtr = largePtr;
            largePtr = tmpPtr;
        }
        prev = itPtr;
        itPtr = itPtr->next;
    }
    if (largePtr)
    {
        prev->next = largePtr;
    }
    return returnPtr;
}

void insertOrdered(node **head, int data)
{
    node *curr = *head;
    node *prev = NULL;
    node *newNode = createNode(data);

    if (data < curr->data)
    {
        newNode->next = curr;
        *head = newNode;
        return;
    }
    while (curr && (data > curr->data))
    {
        prev = curr;
        curr = curr->next;
    }
    newNode->next = prev->next;
    prev->next = newNode;
}

void mergSortedLists(node **list1, node **list2)
{
    node *curr1 = *list1;
    while (curr1)
    {
        insertOrdered(list2, curr1->data);
        curr1 = curr1->next;
    }
}

void recursivereverseTwoLinkedList(node **head)
{
    // this is simple there is a better way to do this
    node *curr = *head;
    if (!curr)
    {
        return;
    }
    recursivereverseTwoLinkedList(&curr->next->next);
    int tmp = curr->data;
    curr->data = curr->next->data;
    curr->next->data = tmp;
}

void itertativeReverseTwoNodeList(node **head)
{
    node *curr = *head;
    node *prev = NULL;
    while (curr && curr->next)
    {
        int tmp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = tmp;
        prev = curr;
        curr = curr->next->next;
    }
}

void iterativeTwoNodeReverse(node **head)
{
    node *curr = *head;
    int count = 0;
    node *tmp;
    node *prev = NULL;
    while (curr && curr->next)
    {
        if (!count)
        {
            *head = curr->next;
            count++;
        }
        tmp = curr->next;
        curr->next = curr->next->next;
        tmp->next = curr;
        prev = curr;
        curr = curr->next;
        prev->next = curr->next;
    }
    prev->next = curr;
}
node *splitCircularLinkedList(node **head)
{
    node *copy = *head;
    node *slowPtr = *head;
    node *fastPtr = *head;
    do
    {
        slowPtr = slowPtr->next;
        if (fastPtr->next->next == copy)
        {
            fastPtr = fastPtr->next;
            break;
        }
        fastPtr = fastPtr->next->next;

    } while ((fastPtr != copy) && (fastPtr->next != copy));
    node *tmp = slowPtr->next;
    slowPtr->next = copy;
    fastPtr->next = tmp;
    return tmp;
}
int isPalindrome(node **head)
{
    node *slowPtr = *head;
    node *fastPtr = *head;
    node *curr = *head;
    while (fastPtr && fastPtr->next)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    node *tmp = copyLinkedList(&slowPtr);
    reverseLinkedList(&tmp);
    while (curr != slowPtr)
    {
        if (tmp->data != curr->data)
        {
            return 0;
        }
        tmp = tmp->next;
        curr = curr->next;
    }
    return 1;
}

void *reverseKNodes(int k, node **head, int size, int ind)
{
    node *curr = *head;
    node *prev = NULL;
    node *tmpPtr = *head;
    node *tmp;
    for (int i = 0; i < k; i++)
    {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
        ind++;
    }
    if ((ind + k - 1) < size - 1)
    {
        for (int i = 0; i < k - 1; i++)
        {
            curr = curr->next;
        }
    }
    (*head)->next = curr;
}

void k_prob_switch(int k, node **head)
{
    int count = 0;
    int count1 = 0;
    int size = 0;
    int sw = 0;
    node *curr = *head;
    node *headPtr = *head;
    node *tmpPtr = *head;
    node *prev = NULL;

    while (curr)
    {
        curr = curr->next;
        size++;
    }
    curr = *head;
    node *nodePtr;
    for (int i = 1; i < k; i++)
    {
        tmpPtr = tmpPtr->next;
    }
    int mod = size / k;

    while (count < mod)
    {
        prev = curr;
        for (int i = 0; i < k; i++)
        {
            curr = curr->next;
        }
        reverseKNodes(k, &prev, size, count1);
        count1 += k;
        count += 1;
    }
    *head = tmpPtr;
}

int josephusCircle(int n, int m, node **head)
{
    node *curr = *head;
    int count = 1;
    while (n > 1)
    {
        if ((count % m) == 0)
        {
            n--;
            deleteNodeCircular(&curr);
        }
        else
        {
            curr = curr->next;
        }
        count++;
    }
    return curr->data;
}

rand_node *copyRandNode(rand_node *node)
{
    rand_node *newNode = (rand_node *)malloc(sizeof(rand_node));

    newNode->data = node->data;
    newNode->next = NULL;

    return newNode;
}

rand_node *copyRandLinkedList(rand_node **head)
{
    rand_node *newNode;
    rand_node *curr = *head;
    newNode = copyRandNode(curr);
    rand_node *cpy = newNode;
    curr = curr->next;
    while (curr)
    {
        rand_node *tmp = copyRandNode(curr);
        newNode->next = tmp;
        newNode = newNode->next;
        curr = curr->next;
    }

    curr = *head;
    newNode = cpy;
    while (curr)
    {
        int count = 0;
        rand_node *tmp = *head;
        while (tmp != curr->rand)
        {
            tmp = tmp->next;
            count++;
        }
        rand_node *tmpCpy = cpy;
        for (int i = 0; i < count; i++)
        {
            tmpCpy = tmpCpy->next;
        }
        newNode->rand = tmpCpy;
        curr = curr->next;
        newNode = newNode->next;
    }
    return cpy;
}
node *simpleEvenOdd(node **head)
{
    node *curr = *head;
    node *sortedList = createNode(curr->data);
    curr = curr->next;
    while (curr)
    {
        if ((curr->data % 2) == 0)
        {
            addBeginning(curr->data, &sortedList);
        }
        else
        {

            addEnd(curr->data, &sortedList);
        }
        curr = curr->next;
    }
    return sortedList;
}

node *betterEvenOdd(node **head)
{
    node *curr = *head;
    node *evenList = createNode(curr->data);
    node *oddList = createNode(curr->data);
    node **deleteFirst = ((curr->data) % 2 == 0) ? &oddList : &evenList;
    curr = curr->next;
    while (curr)
    {
        if ((curr->data % 2) == 0)
        {
            addBeginning(curr->data, &evenList);
        }
        else
        {
            addEnd(curr->data, &oddList);
        }
        curr = curr->next;
    }

    deleteBeginning(deleteFirst);
    curr = evenList;

    while (curr->next)
    {
        curr = curr->next;
    }

    curr->next = oddList;
    return evenList;
}

int modularNode(int k, node **head)
{
    int count = 0;
    node *curr = *head;
    while (curr)
    {
        curr = curr->next;
        count++;
    }
    int n = count / k;
    curr = *head;
    for (int i = 0; i < n * k; i++)
    {
        curr = curr->next;
    }
    return curr->data;
}
int endModularNode(int k, node **head)
{
    int count = 0;
    node *curr = *head;
    while (curr)
    {
        curr = curr->next;
        count++;
    }
    count -= k;
    curr = *head;
    for (int i = 0; i < count; i++)
    {
        curr = curr->next;
    }

    return curr->data;
}

int squareRootNode(node **head)
{
    node *curr = *head;
    double count = 0.0;
    while (curr)
    {
        curr = curr->next;
        count++;
    }
    int n = (int)sqrt(count);
    curr = *head;
    int count1 = 0;
    for (int i = 1; i < n; ++i)
    {
        curr = curr->next;
        count1++;
    }
    return curr->data;
}

node *mergeList49(node **head1, node **head2)
{
    node *h1 = *head1;
    node *h2 = *head2;

    int c1 = 0;
    int c2 = 0;

    while (h1)
    {
        c1++;
        h1 = h1->next;
    }

    while (h2)
    {
        c2++;
        h2 = h2->next;
    }

    node *lHead = (c1 < c2) ? *head2 : *head1;
    node *sHead = (c1 < c2) ? *head1 : *head2;
    node *rHead = sHead;
    node *prev;
    while (sHead)
    {

        node *sTmp = sHead->next;
        node *lTmp = lHead->next;
        sHead->next = lHead;
        lHead->next = sTmp;
        prev = sHead;
        sHead = sTmp;
        lHead = lTmp;
    }
    prev = prev->next;
    prev->next = lHead;

    return rHead;
}
void inplaceEvenOdd(node **head)
{
    node *curr = *head;
    node *lastPtr;

    int last = 0;

    while (curr->next)
    {
        curr = curr->next;
        lastPtr = curr;
    }

    curr = *head;
    node *prev;

    while (curr)
    {
        if (((curr->data % 2) != 0))
        {
            if (curr->data == last)
            {
                return;
            }

            last = curr->data;
            node *tmp = curr->next;
            curr->next = NULL;
            lastPtr->next = curr;
            lastPtr = curr;
            prev->next = tmp;
        }

        prev = curr;
        curr = curr->next;
    }
}

static char *problem51()
{
    node *head = createListOfSize(6);
    inplaceEvenOdd(&head);
    printf("problem 51 \n");
    printNode(&head);

    return 0;
}

static char *problem49()
{
    node *head1 = createListOfSize(2);
    reverseLinkedList(&head1);
    node *head2 = createListOfSize(4);
    node *ans = mergeList49(&head1, &head2);
    int *arr = returnNodeArr(6, &ans);
    int expArr[6] = {1, 0, 0, 1, 2, 3};
    mu_assert("error problem 49  != 1", mu_arr_assert(6, expArr, arr) == 1);
    return 0;
}

static char *problem47()
{
    node *head = createListOfSize(4);
    mu_assert("error problem 47  != 1", squareRootNode(&head) == 1);
    return 0;
}

static char *problem46()
{
    node *head = createListOfSize(19);

    mu_assert("error problem 46  != 16", endModularNode(3, &head) == 16);
    return 0;
}

static char *problem45()
{
    node *head = createNode(0);
    addBeginning(1, &head);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);

    mu_assert("error problem45 k != 3", modularNode(2, &head) == 0);
    return 0;
}

static char *problem43()
{
    node *head = createNode(0);
    addBeginning(1, &head);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);
    node *ans = simpleEvenOdd(&head);
    node *ansBetter = betterEvenOdd(&head);
    int arr[5] = {0, 2, 4, 3, 1};
    int *arrAns = returnNodeArr(5, &ans);
    int *arrBett = returnNodeArr(5, &ansBetter);

    mu_assert("error problem43 simple", mu_arr_assert(5, arr, arrAns) == 1);
    mu_assert("error problem43 better", mu_arr_assert(5, arrBett, arrAns) == 1);
    return 0;
}

static char *problem42()
{
    rand_node *head = createRandLinkList(4);
    rand_node *copyHead = copyRandLinkedList(&head);
    int *arr = returnRandNodeArr(4, &head);
    int *arrCopy = returnRandNodeArr(4, &copyHead);
    mu_assert("error problem42 ", mu_arr_assert(8, arr, arrCopy) == 1);
    return 0;
}

static char *problem40()
{
    node *head = createCircularList(0);
    addToCircularList(1, &head);
    addToCircularList(2, &head);
    addToCircularList(3, &head);
    addToCircularList(4, &head);
    addToCircularList(5, &head);
    addToCircularList(6, &head);
    addToCircularList(7, &head);
    addToCircularList(8, &head);
    addToCircularList(9, &head);
    addToCircularList(10, &head);
    mu_assert("error problem40 k != 4", josephusCircle(11, 2, &head) == 4);
    return 0;
}

static char *problem38()
{
    node *head = createNode(0);
    addBeginning(1, &head);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);
    addBeginning(5, &head);
    addBeginning(6, &head);
    addBeginning(7, &head);
    addBeginning(8, &head);
    addBeginning(9, &head);
    reverseLinkedList(&head);
    node *head1 = createNode(1);
    addBeginning(2, &head1);
    addBeginning(3, &head1);
    addBeginning(4, &head1);
    addBeginning(5, &head1);
    addBeginning(6, &head1);
    addBeginning(7, &head1);
    addBeginning(8, &head1);
    addBeginning(9, &head1);
    addBeginning(10, &head1);
    reverseLinkedList(&head1);
    k_prob_switch(3, &head);
    k_prob_switch(4, &head1);
    int headExp[10] = {2, 1, 0, 5, 4, 3, 8, 7, 6, 9};
    int headExp1[10] = {4, 3, 2, 1, 8, 7, 6, 5, 9, 10};
    int *headInt = returnNodeArr(10, &head);
    int *headInt1 = returnNodeArr(10, &head1);
    mu_assert("error problem38 k = 3", mu_arr_assert(10, headExp, headInt) == 1);
    mu_assert("error problem38 k = 4", mu_arr_assert(10, headExp1, headInt1) == 1);

    return 0;
}

static char *problem37()
{
    node *head = createNode(0);
    addBeginning(1, &head);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);
    addBeginning(5, &head);
    addBeginning(4, &head);
    addBeginning(3, &head);
    addBeginning(2, &head);
    addBeginning(1, &head);
    addBeginning(0, &head);
    mu_assert("error 1 != isPalindrome", 1 == isPalindrome(&head));
    return 0;
}

static char *problem35()
{
    node *head = createCircularList(0);
    addToCircularList(1, &head);
    addToCircularList(2, &head);
    addToCircularList(3, &head);
    addToCircularList(4, &head);
    //reverseLinkedList(&head);
    node *splitHead = splitCircularLinkedList(&head);
    int *headInt = returnNodeArr(3, &head);
    int *splitInt = returnNodeArr(2, &splitHead);
    int ansArr[2];
    int headExp[3] = {4, 3, 2};
    int splitExp[2] = {1, 0};
    ansArr[0] = mu_arr_assert(3, headExp, headInt);
    ansArr[1] = mu_arr_assert(2, splitExp, splitInt);
    mu_assert("error head != 1", 1 == ansArr[0]);
    mu_assert("error split != 1", 1 == ansArr[1]);
    return 0;
}

static char *problem32()
{
    node *head = createNode(0);
    addBeginning(1, &head);
    addBeginning(2, &head);
    addBeginning(10, &head);
    addBeginning(11, &head);
    addBeginning(12, &head);
    addBeginning(13, &head);
    reverseLinkedList(&head);
    iterativeTwoNodeReverse(&head);
    int headExp[7] = {1, 0, 10, 2, 12, 11, 13};
    int *headInt = returnNodeArr(7, &head);
    mu_assert("error problem32", mu_arr_assert(7, headExp, headInt) == 1);
    return 0;
}

static char *problem31()
{
    node *head = createNode(0);
    addBeginning(1, &head);
    addBeginning(2, &head);
    addBeginning(10, &head);
    addBeginning(11, &head);
    addBeginning(12, &head);
    reverseLinkedList(&head);
    node *head1 = createNode(3);
    addBeginning(4, &head1);
    addBeginning(5, &head1);
    addBeginning(6, &head1);
    addBeginning(7, &head1);
    addBeginning(7, &head1);
    addBeginning(13, &head1);
    reverseLinkedList(&head1);
    //mergSortedLists(&head, &head1);
    int headExp[13] = {0, 1, 2, 3, 4, 5, 6, 7, 7, 10, 11, 12, 13};
    node *head3 = efficientMergeSort(&head, &head1);
    int *headInt = returnNodeArr(13, &head3);
    mu_assert("error efficientMergeSort != 1", 1 == mu_arr_assert(13, headInt, headExp));
    return 0;
}

static char *problem29()
{
    node *head = createNode(0);
    addBeginning(1, &head);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);
    addBeginning(5, &head);
    mu_assert("error 0 != recursiveevenoddlinkedlist", 0 == recursiveEvenOddLinkedList(&head, 0));
    mu_assert("error 0 != iterativeEvenoddlinkedlist", 0 == iterativeEvenOddLinkedList(&head));
    addBeginning(6, &head);
    mu_assert("error 1 != recursiveEvenOddLinkedList", 1 == recursiveEvenOddLinkedList(&head, 0));
    mu_assert("error 1 != iterativeEvenoddlinkedlist", 1 == iterativeEvenOddLinkedList(&head));
    return 0;
}

static char *problem28()
{
    node *head = createNode(0);
    addBeginning(1, &head);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);
    addBeginning(5, &head);
    //displayNodeFromEnd(&head);
    printf("recursive solution \n");
    printReverseLinkedList(&head);
    return 0;
}

static char *problem27()
{
    node *head = createNode(1);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);
    addBeginning(5, &head);
    mu_assert("error 3 != findMiddleLinkedList", 3 == findMiddleLinkedList(&head));
    return 0;
}

static char *problem23()
{
    node *head = createNode(1);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);
    addBeginning(5, &head);
    node *shortHead = createNode(10);
    addBeginning(20, &shortHead);
    addBeginning(30, &shortHead);
    addBeginning(40, &shortHead);
    createBranchList(&head, &shortHead, 2);
    mu_assert("error 3 != findIntersectionNode", 3 == fastIntersectionNode(&head, &shortHead));
    return 0;
}

static char *problem17()
{
    node *head = createNode(1);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);
    addBeginning(5, &head);
    node *shortHead = createNode(10);
    addBeginning(20, &shortHead);
    addBeginning(30, &shortHead);
    addBeginning(40, &shortHead);
    createBranchList(&head, &shortHead, 2);
    mu_assert("error 3 != findIntersectionNode", 3 == findIntersectionNode(&head, &shortHead));
    return 0;
}
static char *problem16()
{
    node *head = createNode(1);
    node *prev = createNode(-1);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);
    addBeginning(5, &head);
    recursiveReverseLinkedList(&head, &prev, &head);
    int headInt[5] = {1, 2, 3, 4, 5};
    int *headExp = returnNodeArr(5, &head);
    mu_assert("error problem16 != 1", 1 == mu_arr_assert(5, headInt, headExp));
    return 0;
}

static char *problem15()
{
    node *head = createNode(1);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);
    addBeginning(5, &head);
    insertSortedList(0, &head);
    insertSortedList(6, &head);
    mu_assert("error 0 != insertSortedList", 0 == returnNodePosition(0, &head));
    mu_assert("error 6 != insertSortedList", 6 == returnNodePosition(6, &head));
    return 0;
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
    mu_run_test(problem15);
    mu_run_test(problem16);
    mu_run_test(problem17);
    mu_run_test(problem23);
    mu_run_test(problem27);
    mu_run_test(problem28);
    mu_run_test(problem29);
    mu_run_test(problem31);
    mu_run_test(problem32);
    mu_run_test(problem35);
    mu_run_test(problem37);
    mu_run_test(problem38);
    mu_run_test(problem40);
    mu_run_test(problem40);
    mu_run_test(problem42);
    mu_run_test(problem43);
    mu_run_test(problem45);
    mu_run_test(problem46);
    mu_run_test(problem47);
    mu_run_test(problem49);
    mu_run_test(problem51);
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