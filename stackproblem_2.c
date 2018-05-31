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