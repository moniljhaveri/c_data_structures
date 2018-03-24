#include <stdio.h> 
#include "Stack.h" 
#include "SinglyLinkedList.h"
#include "QueueStack.h" 
#include "minunit.h"

int tests_run = 0;

static char *testStackClass()
{
    Stack *stack = createStack(); 
    push(1, stack); 
    push(2, stack); 
    push(3, stack); 
    push(4, stack); 
    push(5, stack); 
    push(6, stack); 
    mu_assert("push size 8 != 8", returnSize(stack) == 8); 
    pop(stack); 
    pop(stack); 
    pop(stack); 
    pop(stack); 
    pop(stack); 
    mu_assert("pop size 2 != 2", returnSize(stack) == 2); 
    pop(stack); 
    pop(stack); 
    mu_assert("pop size 0 != 0", returnIdx(stack) == 0); 
    mu_assert("top 1 == 1", top(stack) == 1); 
    return 0; 
}

int getMin(Stack *minStack)
{
    return top(minStack);     
}

void minPush(int data, Stack *mainStack, Stack *minStack)
{
    if(returnSize(minStack) == 0)
    {
        push(data, minStack); 
    }
    push(data, mainStack); 
    if(data < top(minStack))
    {
        push(data, minStack); 
    }
}
void minPop(Stack *mainStack, Stack *minStack)
{
    if(returnIdx(mainStack) == 0)
    {
        return;  
    }
    if(top(mainStack) == top(minStack))
    {
        pop(minStack); 
    }

    pop(mainStack); 

    if(top(mainStack) < top(minStack))
    {
        push(top(mainStack), minStack); 
    }
}

int checkPalindrone(int *arr)
{
    int c = 0;  
    Stack *newStack = createStack(); 
    while((char)arr[c] != 'X')
    {
        push(arr[c], newStack); 
        c++;  
    }
    int n = 2*c; 
    c++; 
    for(int i = c; i < n; ++i)
    {
        if(top(newStack) != arr[i])
        {
            return 0; 
        }
        pop(newStack); 
    }

    return 1; 
}

int llCheckPalindrome(int n, node **head)
{
    node *curr = *head; 
    Stack *stack = createStack(); 
    push(curr->data, stack); 

    for(int i = 0; i < n/2; i++)
    {
        curr = curr->next; 
        push(curr->data, stack); 
    }

    while(curr){
        if(curr->data != top(stack))
        {
            return 0; 
        }
        curr = curr->next; 
        pop(stack); 
    }
    return 1; 
}

Stack* reverseStack(Stack *stack) 
{
    Stack *returnStack = createStack(); 

    while(returnIdx(stack))
    {
        push(top(stack), returnStack); 
        pop(stack); 
    }

    return returnStack; 
    
}

static char* problem14() 
{
    DoubleStack *dS = createDoubleStack();  
    pushFront(1, dS); 
    pushFront(2, dS); 
    pushFront(3, dS); 
    mu_assert("pushFront 3 != 3", topFront(dS) == 3); 
    pushBack(101, dS); 
    pushBack(102, dS); 
    pushBack(103, dS); 
    mu_assert("pushBack 103 == 103", topBack(dS) == 103); 
    popFront(dS); 
    popFront(dS); 
    mu_assert("popFront 1 != 1", topFront(dS) == 1); 
    popBack(dS); 
    popBack(dS); 
    mu_assert("popFront 101 != 101", topBack(dS) == 101); 

    return 0; 
}

static char* problem13()
{
    // do next chapter 
    return 0; 
}

static char* problem12()
{
    QueueStack *qS = createQueueStack(); 
    enque(1, qS); 
    enque(2, qS); 
    enque(3, qS); 
    mu_assert("problem 12 1 == 1", queueTop(qS) == 1); 
    deque(qS); 
    mu_assert("problem 12 2 == 2", queueTop(qS) == 2); 
    deque(qS); 
    mu_assert("problem 12 3 == 3", queueTop(qS) == 3);  

    return 0; 
}

static char* problem11()
{
    Stack *stack = createStack(); 
    push(1, stack); 
    push(2, stack); 
    push(3, stack); 
    stack = reverseStack(stack); 
    int corrArr[3] = {1, 2, 3}; 
    int *expArr = returnStack(3, stack); 
    mu_assert("problem11 1 == 1", mu_arr_assert(3, expArr, corrArr)); 

    return 0; 
}

static char* problem9()
{ 
    //do problem 8 using linkedLists 
    node *cll = createNode(1); 
    addBeginning(2, &cll); 
    addBeginning(3, &cll); 
    addBeginning(2, &cll); 
    addBeginning(1, &cll); 

    node *ll = createNode(1); 
    addBeginning(2, &ll); 
    addBeginning(3, &ll); 
    addBeginning(2, &ll); 
    addBeginning(3, &ll); 
    mu_assert("cll 1 == 1", (llCheckPalindrome(5, &cll) == 1)); 
    mu_assert("ll 0 == 0", (llCheckPalindrome(5, &ll) == 0)); 
    return 0; 
}

static char* problem8()
{
    int corrArr[7] = {1, 2, 3, 'X', 3, 2, 1}; 
    int incArr[7] = {1, 2, 3, 'X', 4, 2, 1}; 
    mu_assert("corrArr 1 == 1", checkPalindrone(corrArr) == 1); 
    mu_assert("incArr 0 == 0", checkPalindrone(incArr) == 0); 
    return 0; 
}

static char* problem5()
{
    //also solves problem 6 
    Stack *mainStack = createStack(); 
    Stack *minStack = createStack(); 
    minStack->data[0] =  2147483647;
    minStack->data[1] =  2147483647;
    minPush(10, mainStack, minStack); 
    minPush(13, mainStack, minStack); 
    minPush(14, mainStack, minStack); 
    minPush(1, mainStack, minStack); 
    minPush(3, mainStack, minStack); 
    mu_assert("minTop 1 == 1", top(minStack) == 1); 
    minPop(mainStack, minStack); 
    minPop(mainStack, minStack); 
    mu_assert("minTop 10 == 10", top(minStack) == 10); 

    return 0; 
}


static char* problem4()
{
    //do in c++ or come back to 
    return 0; 
}
static char* problem3()
{
    //do in c++ or come back to 
    return 0; 
}
static char* problem2()
{
    //do in c++ or come back to 
    return 0; 
}
static char* problem1()
{
    //do in c++ or come back to 
    int corArr[10] = {0, 1, 2, 3, 4, 3, 2, 1, 0};
    int incArr[9] = {0, 2, 3, 4, 3, 2, 1, 0};
    return 0; 
}

static char *run_problem_tests()
{
    mu_run_test(problem14); 
    mu_run_test(problem12); 
    mu_run_test(problem11); 
    mu_run_test(problem9); 
    mu_run_test(problem8); 
    mu_run_test(problem5); 
    mu_run_test(testStackClass); 
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