#include <stdio.h>
#include "SinglyLinkedList.h"
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
void recursiveReverseLinkedList(node **head, node **prev, node** head_ptr){
    node *curr = *head;
    if(curr == NULL){
        return; 
    }
    node *next= curr->next;
    node *p = *prev;
    if(p->data == -1){
        p = NULL;  
    }
    if(curr->next == NULL){
        *head_ptr = curr; 
    }
    curr->next = p; 
    recursiveReverseLinkedList(&next, &curr, &*head_ptr); 

}

void createBranchList(node **head, node** end, int position){
    node *endNode = *end;
    node *curr = *head; 
    int count = 0; 
    while(endNode->next){
        endNode = endNode->next;
    }
    while(position != count){
        curr = curr->next; 
        count++; 
    }
    endNode->next = curr; 
}
int findIntersectionNode(node** head1, node ** head2){
    node *curr1 = *head1;
    while(curr1){
        node *curr2 = *head2; 
        while(curr2){
            if (curr1 == curr2){
                return curr1->data; 
            }
            curr2 = curr2->next; 
        }
        curr1 = curr1->next; 
    }
    return 0; 

}
int fastIntersectionNode(node ** head1, node** head2){
    int count1 = 0;  
    int count2 = 0; 
    node *curr1 = *head1; 
    node *curr2 = *head2;

    while(curr1){
        count1++; 
        curr1 = curr1->next; 
    }
    while(curr2){
        count2++; 
        curr2 = curr2->next; 
    }
    node *largestList = (count1 > count2) ? *head1 : *head2; 
    node *smallestList = (count1 < count2) ? *head1 : *head2; 
    int numSteps = abs(count1 - count2); 
    for(int i = 0; i < numSteps; i++){
        largestList = largestList->next;
    }
    while(largestList){
        if(largestList == smallestList){
            return smallestList->data; 
        }
        largestList = largestList->next; 
        smallestList = smallestList->next; 
    }

    return 0; 
}

int findMiddleLinkedList(node **head){
    node *slowPtr = *head; 
    node *fastPtr = *head; 
    while(fastPtr && fastPtr->next){
        slowPtr = slowPtr->next; 
        fastPtr = fastPtr->next->next; 
    }
    return slowPtr->data; 
}

void addNodeEnd(node **head, int data){
    node *curr = *head; 
    while(curr->next){
        curr = curr->next; 
    }
    node *newNode = createNode(data);     
    curr->next = newNode; 
} 

node *copyLinkedList(node **head){
    node *curr = *head; 
    node *newList = createNode(curr->data); 
    while(curr)
    {
        
    }

}

static char *problem28(){
    return 0; 
}

static char *problem27() {
    node *head = createNode(1);
    addBeginning(2, &head);
    addBeginning(3, &head);
    addBeginning(4, &head);
    addBeginning(5, &head);
    mu_assert("error 3 != findMiddleLinkedList", 3 == findMiddleLinkedList(&head));
    return 0; 
}

static char *problem23(){
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

static char *problem17(){
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
    //reverseLinkedList(&head);
    recursiveReverseLinkedList(&head, &prev, &head); 
    printNode(&head);
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