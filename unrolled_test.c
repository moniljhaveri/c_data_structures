#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "unrolledLinkedList.h"

int main(void)
{
    struct nodeBlock *nodeBlock = initNodeBlock(0, 2);
    insertData(1, &nodeBlock);
    insertData(2, &nodeBlock);
    insertData(3, &nodeBlock);
    printBlock(&nodeBlock);
    return 0;
}