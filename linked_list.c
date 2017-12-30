#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node testNode;
    testNode.data = 13;
    printf("%i\n", testNode.data);
    return 0;
}