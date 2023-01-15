#include "queue_array.h"

int TakeRemainder(int idx, int MAX_SIZE)
{
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
void memcpyInQueue(P_QUEUE_ARRAY_T pQueue, void *Addr, int arrayIdx, CPY_MODE_T cpyMode)
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
        pQueue->entranceIdx = R(pQueue->entranceIdx + 1);
        memcpyInQueue(pQueue, pInputObjAddr, pQueue->entranceIdx, pQueue->sizeofObj);
    }

}
