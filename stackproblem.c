#include <stdio.h> 
#include "Stack.h" 
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
    mu_assert("top 2 == 2", top(stack) == 2); 
    return 0; 
}

static char *run_problem_tests()
{
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