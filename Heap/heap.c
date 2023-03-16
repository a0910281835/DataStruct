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

void InsertMaxHeap(P_HEAP_T pHeap, int val)
{
    DECIDE_T ret = IsFullHeap(pHeap);

    if (YES == ret)
    {
        printf("Can't insert, beacuse heap is full. you can decide extern heap\n");
    }
    else
    {
        int childIdx = ++(pHeap->size);
        int parentIdx = (childIdx >> 1);
        int child = val;
        int *pParentVal = &(pHeap->array[parentIdx]);
        int *pChildVal  = &(pHeap->array[childIdx]);
        while (*pParentVal < child)
        {
            *pChildVal = *pParentVal;
            childIdx = parentIdx;
            parentIdx >>= 1;
            pChildVal  = &(pHeap->array[childIdx]);
            pParentVal = &(pHeap->array[parentIdx]);

        }

        pHeap->array[childIdx] = child;
    }
}

int DeleteMaxHeap(P_HEAP_T pHeap)
{
    DECIDE_T ret = IsEmptyHeap(pHeap);
    int retVal = pHeap->array[1];

    if (YES == ret)
    {
        printf("heap is empty, Can delete anything\n");
        return pHeap->array[0];
    }
    else
    {
        int parentIdx = 1;
        int childIdx  = 1 << 1;
        int *array = (pHeap->array);
        int parentVal = array[pHeap->size];
        int childVal  = array[childIdx];
        int size = --(pHeap->size);

        int idx = 0;
        while (1)
        {
            //Compare Son's value
            if ((childIdx < size) && (array[childIdx] < array[childIdx + 1]))
            {
                childIdx += 1;
                childVal = array[childIdx];
            }

            if (parentVal < childVal)
            {
                array[parentIdx] = childVal;
                parentIdx = childIdx;
                childIdx <<= 1;
                childVal = array[childIdx];

            }
            else break;
        }

        array[parentIdx] = parentVal;



    }

    return retVal;
}

DECIDE_T IsMaxHeap(P_HEAP_T pHeap)
{
    DECIDE_T ret = YES;
    int size = pHeap->size;
    int idx = (size >> 1);
    int childIdx;
    int *array = (pHeap->array);

    for ( ; idx > 0 ; idx--)
    {
        childIdx = (idx << 1);
        if ((childIdx < size) && (array[childIdx] < array[childIdx + 1]))
        {
            childIdx += 1;
        }

        if (array[idx] < array[childIdx])
        {
            ret = NO;
            break;
        }
    }

    return ret;

}

int maxProduct(int* nums, int numsSize)
{
    int maxVal    = 0;
    int secMaxVal = 0;
    int idx = 0;

    for (idx = 0; idx < numsSize; idx++)
    {
        if (nums[idx] > secMaxVal)
        {
            if (nums[idx] > maxVal)
            {
                maxVal = nums[idx];
            }
            else
            {
                secMaxVal = nums[idx];
            }

        }

    }

    return (maxVal - 1) * (secMaxVal - 1);
}


int uniquePathsRecursive(int m, int n)
{
    //Method1 : recursive
    if ((1 == m) || (1 == n))
    {
        return 1;
    }
    else
    {
        return (uniquePathsRecursive(m-1, n) + uniquePathsRecursive(m, n-1));

    }

}
