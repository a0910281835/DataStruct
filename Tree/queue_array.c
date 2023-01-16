#include "queue_array.h"

static int TakeRemainder(int idx, int MAX_SIZE)
{
    // TODO : Use define to chek MAX_SIZE is 2^power, then reduce runtime for remainder
    int remainderVal = 0;
    remainderVal = idx & 0x3ff;
    return remainderVal;
}


P_QUEUE_ARRAY_T CreatQueueArray(size_t sizeofSpecialObj)
{
    //P_QUEUE_ARRAY_T pQueue = (P_QUEUE_ARRAY_T) malloc(sizeof(QUEUE_ARRAY_T));
    P_QUEUE_ARRAY_T pQueue = (P_QUEUE_ARRAY_T) malloc(sizeof(QUEUE_ARRAY_T));
    pQueue->pQueueBox = malloc(MAX_SIZE * sizeofSpecialObj);
    pQueue->entranceIdx = pQueue->exitIdx = R(0);
    pQueue->sizeofObj = sizeofSpecialObj;
    return pQueue;
}
static void memcpyInQueue(P_QUEUE_ARRAY_T pQueue, void *Addr, int arrayIdx, CPY_MODE_T cpyMode)
{
    int cpyByteNum = pQueue->sizeofObj;
    void *srcAddr = (((char *)pQueue->pQueueBox) + (arrayIdx * cpyByteNum));
    if (INPUT_CPY_TO_STACK == cpyMode)
    {
        memcpyMySelf(srcAddr, Addr, cpyByteNum);
    }
    else if (STACK_CPY_TO_OUTPUT == cpyMode)
    {
        memcpyMySelf(Addr, srcAddr, cpyByteNum);
    }

}

void PushQueue(P_QUEUE_ARRAY_T pQueue, void *pInputObjAddr)
{
    if (R(pQueue->entranceIdx + 1) == pQueue->exitIdx)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        memcpyInQueue(pQueue, pInputObjAddr, pQueue->entranceIdx, INPUT_CPY_TO_STACK);
        pQueue->entranceIdx = R(pQueue->entranceIdx + 1);
    }

}

void PopQueue(P_QUEUE_ARRAY_T pQueue, void *pOutputObjAddr)
{
    if (pQueue->entranceIdx == pQueue->exitIdx)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        memcpyInQueue(pQueue, pOutputObjAddr, pQueue->exitIdx, STACK_CPY_TO_OUTPUT);
        pQueue->exitIdx = R(pQueue->exitIdx + 1);
    }

}
 
NUM_T SizeQueue(P_QUEUE_ARRAY_T pQueue)
{
    NUM_T current_size = 0;

    if (pQueue->exitIdx > pQueue->entranceIdx)
    {
        current_size += MAX_SIZE;
    }

    current_size += (pQueue->entranceIdx - pQueue->exitIdx);

    return current_size;
}

DECIDE_T isQueueState(P_QUEUE_ARRAY_T pQueue, SIZE_STATE_T sizeState)
{
    DECIDE_T decide = NO;

    NUM_T current_size = SizeQueue(pQueue);

    if (sizeState == current_size) decide = YES;

    return decide;

}
DECIDE_T IsEmptyQueue(P_QUEUE_ARRAY_T pQueue)
{
    DECIDE_T decide = isQueueState(pQueue, EMPTY_SIZE);

    return decide;

}

DECIDE_T IsFullQueue(P_QUEUE_ARRAY_T pQueue)
{
    DECIDE_T decide = isQueueState(pQueue, MAX_SIZE);

    return decide;

}
