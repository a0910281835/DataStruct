#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"queue_array.h"


pQueueArray CreateQueueArray(void)
{
    pQueueArray pQueue = (pQueueArray) malloc(sizeof(QueueArray));
    pQueue->first_idx = pQueue->last_idx = 0;

    return pQueue;
}

RETURN PushQueueArray(pQueueArray pQueue, ELEMENT_T input)
{
    RETURN result;
    if (((pQueue->last_idx + 1) % MAX_SIZE) == pQueue->first_idx)
    {
        result.size_cond = FULL;
    }
    else
    {
        int *pSize = &(pQueue->last_idx);
        pQueue->queueVal[*pSize] = input;
        result.size_cond = SUCC;
        result.output = input;
        *pSize = ((*pSize) + 1) % MAX_SIZE;
    }

    return result;
}


RETURN PopQueueArray(pQueueArray pQueue)
{
    RETURN result;
    if (pQueue->last_idx == pQueue->first_idx)
    {
        result.size_cond = EMPTY;
    }
    else
    {
        int *pSize = &(pQueue->first_idx);
        result.size_cond = SUCC;
        result.output = pQueue->queueVal[(*pSize)];
        *pSize = ((*pSize) + 1) % MAX_SIZE;
    }

    return result;

}
