#include "stdlib.h"
#include "stdio.h"
#include "heap.h"


char *resultString[2] = {"NO", "YES"};

int main(void)
{

    P_HEAP_T pHeap = CreateHeap(20);

    DECIDE_T ret = IsEmptyHeap(pHeap);
    printf("%d\n", pHeap->array[0]);
    printf("%s is empty\n",resultString[ret]);

    return 1;

}
