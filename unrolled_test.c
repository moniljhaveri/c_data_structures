#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "unrolledLinkedList.h"

int main(void)
{
    struct nodeBlock *nodeBlock = initNodeBlock(0, 1);
    printBlock(&nodeBlock);
    return 0;
}