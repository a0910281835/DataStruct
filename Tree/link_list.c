#include "link_list.h"
//typedef struct T_THREAD * PT_THREAD;

T_WAITTING_PRIORITY_QUEUE * CreateWaittingQueue(void)
{
    T_WAITTING_PRIORITY_QUEUE * pWattingQueue = malloc(sizeof(T_WAITTING_PRIORITY_QUEUE));
    pWattingQueue->pHead  = NULL;
    pWattingQueue->pTail  = NULL;
    return pWattingQueue;
}

bool IsWQEmpty(T_WAITTING_PRIORITY_QUEUE *pWattingQueue)
{
    bool ret = 0;

    if (pWattingQueue->pHead == NULL) ret = 1;

    return ret;
}

bool DeleteWaittingQueue(T_WAITTING_PRIORITY_QUEUE *pWattingQueue)
{
    if (IsWQEmpty(pWattingQueue))
    {
        free(pWattingQueue);
    }
    else
    {
        while (1)
        {
            printf(" error \n");
        }
    }


}

PT_SLEEP_THREAD_NODE CreateDoubleListNode(T_THREAD *pT, int timing)
{
    PT_SLEEP_THREAD_NODE pNode = malloc(sizeof(T_SLEEP_THREAD_NODE));
    pNode->pThread = pT;
    pNode->when = timing;
    pNode->next = NULL;
    pNode->prev = NULL;
    return pNode;
}



static bool comparePrevNode(PT_SLEEP_THREAD_NODE pBeCompared, PT_SLEEP_THREAD_NODE pCompare)
{
    //. pBeCompared >= pCompare  ret :  false
    //. pBeCompared < pCompare   ret :  true
    //
    bool ret = false;
    if (pBeCompared->when >= pCompare->when)
        ret = false;
    else
        ret = true;
    return ret;
}

void InsertSleepList(T_WAITTING_PRIORITY_QUEUE *pWattingQueue, T_THREAD *pThread, int sleepTiming)
{
    PT_SLEEP_THREAD_NODE pNode = CreateDoubleListNode(pThread, sleepTiming);

    if (IsWQEmpty(pWattingQueue))
    {
        pWattingQueue->pHead = pNode;
        pWattingQueue->pTail = pNode;
    }
    else
    {
        //bool unnessarySortFlag = false;
        //printf("waiting queue is not idle\n");
        //pNode->next = (pWattingQueue->pHead);
        //(pWattingQueue->pHead)->prev = pNode;
        //(pWattingQueue->pHead) = pNode;
        //unnessarySortFlag = true;

        PT_SLEEP_THREAD_NODE pCurrent = pWattingQueue->pTail;

        while (pCurrent != NULL)
        {

        }
    }

    //Sorting

}
