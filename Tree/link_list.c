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
    //. pBeCompared > pCompare  ret :  true
    //. pBeCompared <= pCompare   ret : false
    //
    bool ret = false;
    if (pBeCompared->when >= pCompare->when)
        ret = true;
    else
        ret = false;
    return ret;
}



// "when" is less , proirity is high. then sorting to head.
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
        printf("waiting queue is not idle\n");
        //pNode->next = (pWattingQueue->pHead);
        //(pWattingQueue->pHead)->prev = pNode;
        //(pWattingQueue->pHead) = pNode;
        //unnessarySortFlag = true;

        PT_SLEEP_THREAD_NODE pCurrent = pWattingQueue->pTail;
        bool moreThanFlag = comparePrevNode(pCurrent, pNode);

        while (true == moreThanFlag)
        {

            if ((pCurrent->prev) != NULL)
            {
                pCurrent = pCurrent->prev;
            }
            else
            {
                break;
            }

            moreThanFlag = comparePrevNode(pCurrent, pNode);
        }

        // .exit while has two cases
        //


        // . this element's "when" is smaller , then sorting to head
        if (moreThanFlag == true)
        {
            pCurrent->prev = pNode;
            pNode->next = pCurrent;
            pWattingQueue->pHead = pNode;
        }
        else // . pCurrent < pNode
        {
            if (NULL != pCurrent->next)
            {
                (pCurrent->next)->prev = pNode;
                pNode->next = (pCurrent->next);
            }

            pCurrent->next = pNode;
            pNode->prev = pCurrent;
        }
    }

}
