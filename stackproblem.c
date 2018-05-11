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

int getMin(Stack *minStack)
{
    return top(minStack);
}

void minPush(int data, Stack *mainStack, Stack *minStack)
{
    if (returnSize(minStack) == 0)
    {
        push(data, minStack);
    }
    push(data, mainStack);
    if (data < top(minStack))
    {
        push(data, minStack);
    }
}
void minPop(Stack *mainStack, Stack *minStack)
{
    if (returnIdx(mainStack) == 0)
    {
        return;
    }
    if (top(mainStack) == top(minStack))
    {
        pop(minStack);
    }

    pop(mainStack);

    if (top(mainStack) < top(minStack))
    {
        push(top(mainStack), minStack);
    }
}

int checkPalindrone(int *arr)
{
    int c = 0;
    Stack *newStack = createStack();
    while ((char)arr[c] != 'X')
    {
        push(arr[c], newStack);
        c++;
    }
    int n = 2 * c;
    c++;
    for (int i = c; i < n; ++i)
    {
        if (top(newStack) != arr[i])
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

    for (int i = 0; i < n / 2; i++)
    {
        curr = curr->next;
        push(curr->data, stack);
    }

    while (curr)
    {
        if (curr->data != top(stack))
        {
            return 0;
        }
        curr = curr->next;
        pop(stack);
    }
    return 1;
}

Stack *reverseStack(Stack *stack)
{
    Stack *returnStack = createStack();

    while (returnIdx(stack))
    {
        push(top(stack), returnStack);
        pop(stack);
    }

    return returnStack;
}

static char *pStackTest()
{
    node *nSt = createListOfSize(4);
    node *copy = nSt;
    pStack *pSt = createPStack(nSt);
    nSt = nSt->next;
    addPStack(nSt, pSt);
    nSt = nSt->next;
    addPStack(nSt, pSt);
    nSt = nSt->next;
    addPStack(nSt, pSt);
    mu_assert("node* !=  node* 1", topPStack(pSt) == nSt);
    nSt = copy;
    popPStack(pSt);
    mu_assert("node* !=  node* 2", topPStack(pSt) == nSt->next->next);
    popPStack(pSt);
    mu_assert("node* !=  node* 3", topPStack(pSt) == nSt->next);

    return 0;
}

static char *llStackTest()
{
    llStack *llSt = createllStack(10);
    //testllStack(9, llSt);
    addllStack(9, llSt);
    mu_assert("top 9 != 9", topllStack(llSt));
    popllStack(llSt);
    mu_assert("top 10 != 10", topllStack(llSt) == 10);
    return 0;
}

int dumblookup(int val)
{
    if (val == 6)
    {
        return 0;
    }
    else if (val == 3)
    {
        return 1;
    }
    else if (val == 4)
    {
        return 2;
    }
    else if (val == 5)
    {
        return 3;
    }
    else if (val == 2)
    {
        return 4;
    }
    return -1;
}
int checkPairs(Stack *st)
{
    Stack *newSt = createStack();
    int n = (st->idx / 2) * 2 - 1;
    int count = 0;
    while (count < n)
    {
        count++;
        int tp = top(st);
        pop(st);
        push(tp, newSt);
        int test = abs(top(newSt) - top(st));
        if (test != 1)
        {
            return 0;
        }
        else
        {
            pop(st);
            pop(newSt);
            count++;
        }
    }

    return 1;
}

static char* problem28()
{
    int n = 9; 
    int arr[9] = {0, 1, 2, 3, 3, 2, 1, 0, 4}; 
    Stack *st = createStack(); 
    for(int i = 0; i < n; ++i)
    {
        int tmp = arr[i]; 
        if(!st->idx){
            push(tmp, st); 
        }
        else if(top(st) == tmp)
        {
             pop(st);  
        }
        else 
        {
            push(tmp, st); 
        }
    }
    mu_assert("4 != 4", top(st) == 4);


    return 0; 
}

static char *problem27()
{
    int n = 9;
    int arr[9] = {4, 5, -2, -3, 11, 10, 5, 6, 20};
    int arr1[9] = {4, 5, -2, -3, 11, 10, 5, 100, 20};
    Stack *st = createStack();
    Stack *st1 = createStack();
    for (int i = 0; i < 9; i++)
    {
        push(arr[n - i - 1], st);
    }
    for (int i = 0; i < 9; i++)
    {
        push(arr1[n - i - 1], st1);
    }
    mu_assert("1 != 1", checkPairs(st) == 1);
    mu_assert("0 != 0", checkPairs(st1) == 0);
    return 0;
}

static char *problem26()
{
    //come back to
    return 0;
}

static char *problem24()
{
    int arr[7] = {6, 2, 5, 4, 5, 1, 6};
    int n = 7;

    Stack *st = createStack();
    int area = 0;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        if (!st->idx || arr[top(st)] < arr[i])
        {
            push(i, st);
        }
        else
        {
            tmp = top(st);
            pop(st);
            while (arr[tmp] < arr[i])
            {
                int tmpArea = arr[top(st)] * (i - top(st) - 1);
                if (tmpArea > area)
                {
                    area = tmpArea;
                }
            }
            push(i, st);
        }
    }
    while (st->idx)
    {
        int tmpArea = arr[top(st)] * (n - top(st) - 1);
        if (tmpArea > area)
        {
            area = tmpArea;
        }
        pop(st);
    }
    mu_assert("area != 12", area == 12);

    return 0;
}
static char *problem22()
{
    int arr[5] = {6, 3, 4, 5, 2};
    int n = 5;
    int s[5];

    Stack *st = createStack();
    for (int i = 0; i < n; ++i)
    {
        int p = arr[i];
        int count = i;
        while (st->idx && (top(st) < p))
        {
            pop(st);
        }
        int ind = 0;
        if (st->idx)
        {
            ind = dumblookup(top(st));
        }
        int c = i - ind;
        if (!c)
        {
            c = 1;
        }
        s[i] = c;
        push(p, st);
    }
    int ans[5] = {1, 1, 2, 3, 1};
    mu_assert("span != span", mu_arr_assert(5, s, ans));

    return 0;
}

static char *problem21()
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

    pStack *nStack1 = createPStack(head);
    head = head->next;
    NodeStack *nStack2 = createPStack(&shortHead);
    shortHead = shortHead->next;

    head = head->next;
    shortHead = shortHead->next;

    while (head != NULL)
    {
        addPStack(head, nStack1);
        head = head->next;
    }
    while (shortHead)
    {
        addPStack(shortHead, nStack2);
        shortHead = shortHead->next;
    }

    node *prev = NULL;
    while (topPStack(nStack1) == topPStack(nStack2))
    {
        prev = topPStack(nStack1);
        popPStack(nStack1);
        popPStack(nStack2);
    }
    mu_assert("branch 3 != 3", prev->data == 3);

    return 0;
}

static char *problem17()
{
    IStack *iS = createIthStack(4);
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 4; j >= 1; --j)
        {
            pushIthStack(i, j, iS);
        }
    }

    mu_assert("pushIthStack 1 != 4", topIthStack(1, iS) == 1);
    mu_assert("pushIthStack 2 != 4", topIthStack(2, iS) == 1);
    mu_assert("pushIthStack 3 != 4", topIthStack(3, iS) == 1);
    popIthStack(4, iS);
    mu_assert("pushIthStack 4 != 4", topIthStack(4, iS) == 2);
    return 0;
}

static char *problem14()
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

static char *problem13()
{
    // do next chapter
    return 0;
}

static char *problem12()
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

static char *problem11()
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

static char *problem9()
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

static char *problem8()
{
    int corrArr[7] = {1, 2, 3, 'X', 3, 2, 1};
    int incArr[7] = {1, 2, 3, 'X', 4, 2, 1};
    mu_assert("corrArr 1 == 1", checkPalindrone(corrArr) == 1);
    mu_assert("incArr 0 == 0", checkPalindrone(incArr) == 0);
    return 0;
}

static char *problem5()
{
    //also solves problem 6
    Stack *mainStack = createStack();
    Stack *minStack = createStack();
    minStack->data[0] = 2147483647;
    minStack->data[1] = 2147483647;
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

static char *problem4()
{
    //do in c++ or come back to
    return 0;
}
static char *problem3()
{
    //do in c++ or come back to
    return 0;
}
static char *problem2()
{
    //do in c++ or come back to
    return 0;
}
static char *problem1()
{
    //do in c++ or come back to
    int corArr[10] = {0, 1, 2, 3, 4, 3, 2, 1, 0};
    int incArr[9] = {0, 2, 3, 4, 3, 2, 1, 0};
    return 0;
}

static char *run_problem_tests()
{
    mu_run_test(pStackTest);
    mu_run_test(llStackTest);
    mu_run_test(problem28);
    mu_run_test(problem27);
    mu_run_test(problem24);
    mu_run_test(problem22);
    mu_run_test(problem21);
    mu_run_test(problem17);
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