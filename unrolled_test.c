#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "unrolledLinkedList.h"

int main(void)
{
    struct nodeBlock *nodeBlock0 = initNodeBlock(0, 2);

    insertData(1, &nodeBlock0);
    insertData(3, &nodeBlock0);
    insertData(2, &nodeBlock0);
    insertData(4, &nodeBlock0);

    printBlock(&nodeBlock0);
    return 0;
}