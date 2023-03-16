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

    int idx = 0;
    for (idx = 0; idx < 5; idx++)
    {
        InsertMaxHeap(pHeap, 12 + idx);
    }
    for (idx = 1; idx <= pHeap->size; idx++)
    {
        printf("%d\n", pHeap->array[idx]);
    }

    int delete = DeleteMaxHeap(pHeap);
    printf("Delete Element : %2d\n", delete);
    for (idx = 1; idx <= pHeap->size; idx++)
    {
        printf("%d\n", pHeap->array[idx]);
    }



    ret = IsMaxHeap(pHeap);
    printf("%s is MAX Heap\n",resultString[ret]);



    return 1;

}
