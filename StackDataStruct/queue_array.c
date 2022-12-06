#include"queue_array.h"

PQUEUE_ARRAY_T CreateQueueArray(void)
{
    PQUEUE_ARRAY_T pQueue = (PQUEUE_ARRAY_T) malloc(sizeof(QueueArray));
    pQueue->first_idx = pQueue->last_idx = 0;

    return pQueue;
}

RETURN PushQueueArray(PQUEUE_ARRAY_T pQueue, ELEMENT_TYPE input)
{
    RETURN ret;
    if (((pQueue->last_idx + 1) % MAX_SIZE) == pQueue->first_idx)
    {
        ret.result = FULL_CYCLE_ARRAY;
        printf("queue is full\n");
    }
    else
    {
        int *pSize = &(pQueue->last_idx);
#if defined(_ELEMENT_TYPE_INT)
        pQueue->queueVal[*pSize] = input;
#elif defined(_ELEMENT_TYPE_UNION)
        if (SIGN == input.tag)
        {
            printf("THIS is SIGN\n");
            (pQueue->queueVal[(*pSize)]).sign = input.sign;
            (pQueue->queueVal[(*pSize)]).tag = input.tag;

        }
        else if (NUM == input.tag)
        {
            printf("THIS is NUM\n");
            (pQueue->queueVal[*(pSize)]).val = input.val;
            (pQueue->queueVal[(*pSize)]).tag = input.tag;
        }
#endif
        *pSize = ((*pSize) + 1) % MAX_SIZE;
    }

    return ret;
}


RETURN PopQueueArray(PQUEUE_ARRAY_T pQueue)
{
    RETURN ret;
    if (pQueue->last_idx == pQueue->first_idx)
    {
        ret.result = EMPTY;
        printf("Queue is empty, can't output\n");
    }
    else
    {
        int *pSize = &(pQueue->first_idx);
        ret.result = SUCC;
#if defined(_ELEMENT_TYPE_INT)
        ret.val = pQueue->queueVal[(*pSize)];
#elif defined(_ELEMENT_TYPE_UNION)
        if (SIGN == (pQueue->queueVal[*(pSize)]).tag)
        {
            ret.output.tag = SIGN;
            ret.output.sign = (pQueue->queueVal[(*pSize)]).sign;

        }
        else if (NUM == (pQueue->queueVal[*(pSize)]).tag)
        {
            ret.output.tag = NUM;
            ret.output.val = (pQueue->queueVal[(*pSize)]).val;
        }
#endif
        *pSize = ((*pSize) + 1) % MAX_SIZE;
    }

    return ret;

}
