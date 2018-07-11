#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "SinglyLinkedList.h"
#include "QueueStack.h"
#include "minunit.h"

int tests_run = 0;

int checkParentheses(int n, char *arr)
{
    int top = -1;
    char st[n];
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == '(' || arr[i] == '{')
        {
            top++;
            st[top] = arr[i];
        }
        else if (arr[i] == ')' || arr[i] == '}')
        {
            if (st[top] == '{' && arr[i] != '}')
            {
                return 1;
            }
            else if (st[top] == '(' && arr[i] != ')')
            {
                return 1;
            }
            top--;
        }
    }
    if (top != -1)
    {
        return 1;
    }
    return 0;
}

int checkChar(char c)
{
    if (c == '(')
    {
        return 1;
    }
    else if (c == '+')
    {
        return 2;
    }
    else if (c == '-')
    {
        return 3;
    }
    else if (c == '*')
    {
        return 4;
    }
    else if (c == ')')
    {
        return 5;
    }
    return 0;
}

char *infixTopPostfix(int n, char *arr)
{
    char *rArr = (char *)malloc(sizeof(char) * n);
    char *st = (char *)malloc(sizeof(char) * n);

    int j = 0;
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        int check = checkChar(arr[i]);
        if (!check)
        {
            rArr[j] = arr[i];
            j++;
        }
        else if (top == -1)
        {
            top++;
            st[top] = arr[i];
        }
        else if (arr[i] == '(')
        {
            top++;
            st[top] = arr[i];
        }
        else if (st[top] == '(' && check)
        {
            st[top] = arr[i];
        }
        else if (arr[i] == ')')
        {
            rArr[j] = st[top];
            j++;
            top--;
            rArr[j] = st[top];
            j++;
            top--;
        }
        else
        {
            rArr[j] = st[top];
            st[top] = arr[i];
            j++;
        }
    }
    rArr[j] = st[top];

    return rArr;
}
int calc(int c0, int c1, char op)
{
    int ans = 0;
    if (op == '+')
    {
        ans = c0 + c1;
    }
    else if (op == '-')
    {
        ans = c0 - c1;
    }
    else if (op == '*')
    {
        ans = c0 * c1;
    }
    else if (op == '%')
    {
        ans = c0 % c1;
    }
    return ans;
}

int postfixEvaluation(int n, char *arr)
{
    int st1[n];
    int t1 = -1;
    for (int i = 0; i < n; ++i)
    {
        int check = checkChar(arr[i]);
        if (!check)
        {
            ++t1;
            st1[t1] = (int)arr[i] - '0';
        }
        else
        {
            int c1 = (int)st1[t1];
            --t1;
            int c0 = (int)st1[t1];
            --t1;
            int cal = calc(c0, c1, arr[i]);
            ++t1;
            st1[t1] = cal;
        }
    }
    return st1[0];
}

int infixEvaluation(int n, char *arr)
{
    int ans = 0;
    char stOp[n];
    int stNum[n];
    int topOp = -1;
    int topNum = -1;

    for (int i = 0; i < n - 1; i++)
    {
        int check = checkChar(arr[i]);
        int check1 = checkChar(arr[i + 1]);

        if (arr[i] == '(')
        {
            topOp++;
            stOp[topOp] = arr[i];
        }
        else if (arr[i] == ')')
        {
            int c1 = stNum[topNum];
            topNum--;
            int c0 = stNum[topNum];
            topOp--;
            int cal = calc(c0, c1, stOp[topOp]);
            stNum[topNum] = cal;
        }
        else if (check && !check1)
        {
            int c1 = (int)arr[i + 1] - '0';
            int c0 = stNum[topNum];
            ++topOp;
            stOp[topOp] = arr[i];
            int cal = calc(c0, c1, stOp[topOp]);
            stNum[topNum] = cal;
            topOp--;
            i++;
        }
        else if (!check && check1)
        {
            topNum++;
            stNum[topNum] = (int)arr[i] - '0';
        }
        else
        {
            topOp++;
            stOp[topOp] = arr[i];
        }
    }
    return stNum[0];
}

int getMin(Stack *stMain, Stack *stMin)
{
    static int size = 5;
    int temp;
    if (size <= 0)
        return -1;
    if (top(stMain) == 0 && top(stMin) != 0)
    {
        temp = top(stMin);
        pop(stMin);
    }
    else if (top(stMain) != 0 && top(stMin) == 0)
    {
        temp = top(stMain);
        pop(stMain);
    }
    else if (top(stMain) < top(stMin))
    {

        temp = top(stMain);
        pop(stMain);
    }
    else
    {
        temp = top(stMin);
        pop(stMin);
    }

    --size;

    return temp;
}
void populateSt(int data, Stack *stMain, Stack *stMin)
{
    static int size = 0;
    if (size == 0 || data < top(stMin))
    {
        push(data, stMin);
        ++size;
    }
    else
    {
        push(data, stMain);
    }
}

void pushInt(int data, int pointer, int *st)
{
    if (!pointer)
    {
        st[pointer] = data;
        return;
    }
    if (data < st[pointer - 1])
    {
        st[pointer] = data;
    }
    else
    {
        st[pointer] = st[pointer - 1];
    }
    return;
}
void pushIntV2(int data, int *p, int *st)
{
    int pointer = *p;
    if (!pointer)
    {
        st[pointer] = data;
        pointer++;
        *p = pointer;
        return;
    }
    if (data < st[pointer - 1])
    {
        st[pointer] = data;
        pointer++;
        *p = pointer;
    }
    return;
}
int popInt(int data, int *p, int *st)
{
    int pointer = *p;
    int tmp;
    if (data == st[pointer - 1])
    {
        *p = --pointer;
        tmp = st[pointer];
        *p = --pointer;
        return tmp;
    }
    tmp = st[pointer];

    return tmp;
}
int isPalindrone(int n, char *arr)
{
    char st[n];
    int half = n / 2;
    int p = -1;
    for (int i = 0; i < half; ++i)
    {
        p++;
        st[p] = arr[i];
    }
    for (int i = half + 1; i < n; ++i)
    {
        if (arr[i] != st[p])
        {
            return 0;
        }
        --p;
    }

    return 1;
}

int deque12(int *pointer1, int *pointer2, int *st1, int *st2)
{
    int p1 = *pointer1;
    int p2 = *pointer2;
    int tmp;
    if (p2 >= 0)
    {
        tmp = st2[p2];
        p2--;
    }
    else
    {
        if (p1 >= 0)
        {
            p2 = -1;
            int tmpP = p1;
            for (int i = 0; i <= p1; i++)
            {
                st2[tmpP] = st1[i];
                p2++;
                tmpP--;
            }
            tmp = st2[p2];
            p2--;
            p1 = -1;
        }
    }

    *pointer1 = p1;
    *pointer2 = p2;
    return tmp;
}

void enque12(int data, int *pointer1, int *pointer2, int *st1, int *st2)
{
    int p1 = *pointer1;
    p1++;
    st1[p1] = data;
    *pointer1 = p1;
}

void initM(int n, int m, int *pArr)
{
    for (int i = 0; i < n; ++i)
    {
        pArr[i] = i * m;
    }
}

void pushM(int data, int ind, int m, int *st, int *pArr)
{
    int i = pArr[ind];
    if ((i <= ((ind + 1) * m)) && ((ind * m) <= i))
    {
        st[i] = data;
        pArr[ind] = ++i;
    }
}

int popM(int ind, int m, int *st, int *pArr)
{
    int i = pArr[ind];
    int data = -1;
    if ((i <= ((ind + 1) * m)) && ((ind * m) <= i))
    {
        --i;
        data = st[i];
        pArr[ind] = i;
    }

    return data;
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

int stackInt(int n, node *head, node *sH)
{
    node *st[n];
    int i = -1;
    node *curr = sH;
    while (head)
    {
        i++;
        st[i] = head;
        head = head->next;
    }
    int d = i;
    while (curr)
    {
        i = d;
        while (i)
        {
            if (curr == st[i])
            {
                return curr->data;
            }
            --i;
        }
        curr = curr->next;
    }
    return -1;
}

int stackIntV2(int n, int m, node *h1, node *h2)
{
    node *st1[n];
    node *st2[m];
    int i = -1;
    int j = -1;
    while (h1)
    {
        i++;
        st1[i] = h1;
        h1 = h1->next;
    }

    while (h2)
    {
        j++;
        st2[j] = h2;
        h2 = h2->next;
    }
    int t = i < j ? j : i;
    node *prev = NULL;
    while (t)
    {
        if (st1[i] != st2[j])
        {
            return prev->data;
        }
        prev = st1[i];
        --i;
        --j;
        --t;
    }
    return -1;
}

int findSpan(int n, int m, int *arr)
{

    int span = 1;
    int st[n];
    int i = -1;
    for (int j = 0; j < m; ++j)
    {
        i++;
        st[i] = arr[j];
    }
    while (i > 0)
    {
        if (arr[i] < arr[m])
        {
            span++;
        }
        else
        {
            return span;
        }
        i--;
    }

    return span;
}

void onePassSpan(int n, int *arr, int *ans)
{
    int st[n];
    int top = -1;
    int p = -1;
    for (int i = 0; i < n; ++i)
    {
        while ((-1 < top) && arr[i] > arr[st[top]])
        {
            top--;
            ++p;
        }
        if (-1 == top)
        {
            p = -1;
        }
        else
        {
            p = st[top];
        }
        ++top;
        st[top] = i;
        ans[i] = i - p;
    }
}

int largestRectangle(int n, int *arr)
{
    int st[n];
    int p = -1;
    int maxArea = 0;
    for (int i = 0; i < n; ++i)
    {
        p++;
        st[p] = arr[i];
        int j = p;
        int tmpArea = 0;
        int width = 1;
        int min = arr[i];
        while (j > -1)
        {
            if (min > arr[j])
            {
                min = arr[j];
            }
            tmpArea = min * width;
            if (tmpArea > maxArea)
            {
                maxArea = tmpArea;
            }
            --j;
            width++;
        }
    }
    return maxArea;
}

static char *problem24()
{
    int arr[7] = {3, 2, 5, 6, 1, 4, 4};
    mu_assert("area != 10", 10 == largestRectangle(7, arr));
    return 0;
}

static char *problem23()
{
    int arr[6] = {6, 3, 4, 5, 2, 3};
    int *ans = (int *)malloc(sizeof(int) * 6);
    onePassSpan(6, arr, ans);
    mu_assert("m = 0 1 != 1", 1 == ans[0]);
    mu_assert("m = 1 1 != 1", 1 == ans[1]);
    mu_assert("m = 2 2 != 2", 2 == ans[2]);
    mu_assert("m = 3 3 != 1", 3 == ans[3]);
    mu_assert("m = 4 1 != 1", 1 == ans[4]);
    mu_assert("m = 5 2 != 2", 2 == ans[5]);

    return 0;
}

static char *problem22()
{
    //works for 22 and 23
    int arr[6] = {6, 3, 4, 5, 2, 3};
    mu_assert("m = 0 1 != 1", 1 == findSpan(6, 0, arr));
    mu_assert("m = 1 1 != 1", 1 == findSpan(6, 1, arr));
    mu_assert("m = 2 2 != 2", 2 == findSpan(6, 2, arr));
    mu_assert("m = 3 3 != 1", 3 == findSpan(6, 3, arr));
    mu_assert("m = 4 1 != 1", 1 == findSpan(6, 4, arr));
    mu_assert("m = 5 2 != 2", 2 == findSpan(6, 5, arr));
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
    int *st[5];
    int i = 0;
    mu_assert("V1 3 != 3", 3 == stackInt(5, head, shortHead));
    mu_assert("V2 3 != 3", 3 == stackIntV2(10, 10, head, shortHead));

    return 0;
}

static char *problem15()
{
    int n = 5;
    int m = 3;
    int *pArr = (int *)calloc(n, sizeof(int));
    initM(n, m, pArr);
    int *arr = (int *)calloc(n * m, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pushM(j, i, m, arr, pArr);
        }
    }
    mu_assert("0 3 == 3", 3 == popM(0, m, arr, pArr));
    mu_assert("1 3 == 3", 3 == popM(1, m, arr, pArr));
    mu_assert("2 3 == 3", 3 == popM(2, m, arr, pArr));
    mu_assert("3 3 == 3", 3 == popM(3, m, arr, pArr));
    mu_assert("4 3 == 3", 3 == popM(4, m, arr, pArr));
    mu_assert("0 2 == 3", 2 == popM(0, m, arr, pArr));
    mu_assert("1 2 == 3", 2 == popM(1, m, arr, pArr));
    mu_assert("2 2 == 3", 2 == popM(2, m, arr, pArr));
    mu_assert("3 2 == 3", 2 == popM(3, m, arr, pArr));
    mu_assert("4 2 == 3", 2 == popM(4, m, arr, pArr));
    return 0;
}

int pushFront14(int data, int *fP, int *bP, int *dSt)
{
    if (*fP == *bP)
    {
        return -1;
    }
    dSt[*fP] = data;
    (*fP)++;
    return 1;
}
int pushBack14(int data, int *fP, int *bP, int *dSt)
{
    if (*fP == *bP)
    {
        return -1;
    }
    dSt[*bP] = data;
    (*bP)--;
    return 1;
}

int popFront14(int *fP, int *dSt)
{
    (*fP)--;
    int i = *fP;
    int tmp = dSt[i];
    return tmp;
}

int popBack14(int *bP, int *dSt)
{
    (*bP)++;
    int i = *bP;
    int tmp = dSt[i];
    return tmp;
}

static char *problem14()
{
    int dSt[10];
    int fP = 0;
    int bP = 9;
    for (int i = 0; i < 9; ++i)
    {
        if (i % 2 == 0)
        {
            pushFront14(i, &fP, &bP, dSt);
        }
        else
        {
            pushBack14(i, &fP, &bP, dSt);
        }
    }
    mu_assert("push works when it shouldn't", -1 == pushFront14(10, &fP, &bP, dSt));
    mu_assert("8 != 8", 8 == popFront14(&fP, dSt));
    mu_assert("7 != 7", 7 == popBack14(&bP, dSt));
    return 0;
}

static char *problem12()
{
    //actually problem 14
    int n = 5;
    int arr[5] = {0, 1, 2, 3, 4};
    int st1[5];
    int st2[5];
    int p1 = -1;
    int p2 = -1;
    for (int i = 0; i < 2; ++i)
    {
        enque12(arr[i], &p1, &p2, st1, st2);
    }
    mu_assert("0 != 0", 0 == deque12(&p1, &p2, st1, st2));
    mu_assert("1 != 1", 1 == deque12(&p1, &p2, st1, st2));
    for (int i = 2; i < n; ++i)
    {
        enque12(arr[i], &p1, &p2, st1, st2);
    }
    mu_assert("2 != 2", 2 == deque12(&p1, &p2, st1, st2));
    mu_assert("3 != 3", 3 == deque12(&p1, &p2, st1, st2));
    mu_assert("4 != 4", 4 == deque12(&p1, &p2, st1, st2));

    return 0;
}

static char *problem11()
{
    //solved in problem8
    int arr[5] = {0, 1, 2, 3, 4};
    int ans[5] = {4, 3, 2, 1, 0};
    int ansArr[5];
    Stack *st1 = createStack();
    Stack *st2 = createStack();
    for (int i = 0; i < 5; ++i)
    {
        push(arr[i], st1);
    }
    for (int i = 0; i < 5; ++i)
    {
        int tmp = top(st1);
        pop(st1);
        push(tmp, st2);
    }
    for (int i = 0; i < 5; ++i)
    {
        int tmp = top(st2);
        pop(st2);
        ansArr[i] = tmp;
    }
    mu_arr_assert(5, ans, ansArr);
    return 0;
}

static char *problem8()
{
    //solves problem 9 and 10
    char arrT[7] = "abcXcba";
    char arrF[7] = "abcXcbd";

    mu_assert("arrT != 1", isPalindrone(7, arrT) == 1);
    mu_assert("arrF != 0", isPalindrone(7, arrF) == 0);
    return 0;
}

static char *problem7()
{
    //skip this for now see dynamic programming
    return 0;
}

static char *problem6()
{
    int arr[5] = {5, 2, 4, 3, 1};
    int *st = (int *)malloc(sizeof(int) * 5);
    int p = 0;
    int ans[5];

    for (int i = 0; i < 5; ++i)
    {
        pushIntV2(arr[i], &p, st);
    }
    int n = p;
    for (int i = 4; i >= 0; --i)
    {
        int tmp = popInt(arr[i], &n, st);
        ans[i] = tmp;
    }

    n = 4;
    mu_assert("min == 1", ans[n] == 1);
    --n;
    mu_assert("min == 2", ans[n] == 2);
    --n;
    mu_assert("min == 2", ans[n] == 2);
    --n;
    mu_assert("min == 2", ans[n] == 2);
    --n;
    mu_assert("min == 5", ans[n] == 5);

    return 0;
}
static char *problem5Actual()
{

    int arr[5] = {5, 2, 4, 3, 1};
    int *st = (int *)malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; ++i)
    {
        pushInt(arr[i], i, st);
    }
    int n = 4;
    mu_assert("min == 1", st[n] == 1);
    --n;
    mu_assert("min == 2", st[n] == 2);
    --n;
    mu_assert("min == 2", st[n] == 2);
    --n;
    mu_assert("min == 2", st[n] == 2);
    --n;
    mu_assert("min == 5", st[n] == 5);

    return 0;
}

static char *problem5()
{
    // Not the correct one, did not solve the correct question interesting way to get orde
    int arr[5] = {5, 2, 4, 3, 1};
    Stack *stMain = createStack();
    Stack *stMin = createStack();
    for (int i = 0; i < 5; ++i)
    {
        populateSt(arr[i], stMain, stMin);
    }

    mu_assert("getMin == 1", getMin(stMain, stMin) == 1);
    mu_assert("getMin == 2", getMin(stMain, stMin) == 2);
    mu_assert("getMin == 3", getMin(stMain, stMin) == 3);
    mu_assert("getMin == 4", getMin(stMain, stMin) == 4);
    mu_assert("getMin == 5", getMin(stMain, stMin) == 5);
    return 0;
}

static char *problem4()
{
    char eq[11] = "1*2-(3+4)+6";
    int ans = infixEvaluation(11, eq);
    mu_assert("1 != 1", ans == 1);
    char eq1[11] = "1*2-(3+4)+5";
    ans = infixEvaluation(11, eq1);
    mu_assert("0 != 0", ans == 0);
    return 0;
}

static char *problem3()
{
    char eq[11] = "1*2-(3+4)+5";
    char *postFix = infixTopPostfix(11, eq);
    int ans = postfixEvaluation(11, postFix);
    mu_assert("0 == 0", ans == 0);
    return 0;
}

static char *problem2()
{
    char arr1[13] = "{(a+b)-(b-a)}";
    char eq[11] = "A*B-(C+D)+E";
    char *ans = infixTopPostfix(11, eq);
    mu_assert("eq != ab*cd+-e+", !strcmp(ans, "AB*CD+-E+"));
    return 0;
}

static char *problem1()
{
    char arr1[13] = "{(a+b)-(b-a)}";
    char arr2[10] = "(a+b)-(b-a";
    mu_assert("arr1 != 0", checkParentheses(13, arr1) == 0);
    mu_assert("arr2 != 1", checkParentheses(11, arr2) == 1);

    return 0;
}
static char *run_problem_tests()
{
    mu_run_test(problem24);
    mu_run_test(problem23);
    mu_run_test(problem22);
    mu_run_test(problem21);
    mu_run_test(problem15);
    mu_run_test(problem14);
    mu_run_test(problem12);
    mu_run_test(problem11);
    mu_run_test(problem8);
    mu_run_test(problem7);
    mu_run_test(problem6);
    mu_run_test(problem5Actual);
    mu_run_test(problem5);
    mu_run_test(problem4);
    mu_run_test(problem3);
    mu_run_test(problem2);
    mu_run_test(problem1);
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