#include "heap.h"

P_HEAP_T CreateHeap(NUM_T size)
{
    P_HEAP_T pHeap = malloc(sizeof(HEAP_T));
    pHeap->capacity = size;
    pHeap->size = 0;
    pHeap->array = malloc(sizeof(int) * (pHeap->capacity + 1));
    pHeap->array[0] = INT_MAX;

    return pHeap;
}
DECIDE_T IsFullHeap(P_HEAP_T pHeap)
{
    DECIDE_T ret = NO;
    if (pHeap->size == pHeap->capacity)
    {
        ret = YES;
        printf("Heap is Full");
    }

    return ret;
}
DECIDE_T IsEmptyHeap(P_HEAP_T pHeap)
{
    DECIDE_T ret = NO;
    if (pHeap->size == EMPTY_SIZE)
    {
        ret = YES;
        printf("Heap is empty");
    }

    return ret;
}
