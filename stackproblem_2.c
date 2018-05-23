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