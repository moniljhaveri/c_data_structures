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
    mu_assert("min == 2", st[n] == 5);

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