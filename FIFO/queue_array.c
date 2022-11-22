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
    if (FULL == ((pQueue->last_idx - pQueue->first_idx) % MAX_SIZE))
    {
        result.size_cond = FULL;
    }
    else
    {
        int *pSize = &(pQueue->last_idx);
        pQueue->queueVal[(*pSize % MAX_SIZE)] = input;
        result.size_cond = SUCC;
        result.output = input;
        *pSize = (++(*pSize)) % MAX_SIZE;
    }

    return result;
}

