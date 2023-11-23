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
    bool ret = false;
    if (IsWQEmpty(pWattingQueue))
    {
        free(pWattingQueue);
        ret = true;
    }
    else
    {
        while (1)
        {
            printf(" error \n");
        }
    }
    return ret;


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

void TravelWatingQueue(T_WAITTING_PRIORITY_QUEUE *pWattingQueue)
{
    if  (true == IsWQEmpty(pWattingQueue))
    {
        printf("is empty now\n");

    }
    else
    {
        PT_SLEEP_THREAD_NODE pTravelNode = pWattingQueue->pHead;
        int idx = 0;
        while (NULL != pTravelNode)
        {
            printf("idx : %d , when : %d\n", idx++, pTravelNode->when);
            pTravelNode = pTravelNode->next;
        }
    }

}


T_THREAD * PopWaittingQueue(T_WAITTING_PRIORITY_QUEUE *pWattingQueue)
{
    PT_SLEEP_THREAD_NODE pPopNode =  pWattingQueue->pHead;
    T_THREAD *pT = NULL;

    if  (false == IsWQEmpty(pWattingQueue))
    {
        // . Disconn PopNode with Waitting Queue
        pWattingQueue->pHead =  pPopNode->next;
        if (pWattingQueue->pHead != NULL)
        {
            (pWattingQueue->pHead)->prev = NULL;
        }
        else // Only Has one element
        {
            pWattingQueue->pTail = NULL;
        }
        pPopNode->next = NULL;

        pT = pPopNode->pThread;
        free(pPopNode);
    }

    return pT;
}




// leetcode 146
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
//
// Implement the LRUCache class:
//
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
// If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.
//
// Node operation
PT_CACHE_NODE CreateNode(int key, int value)
{
    PT_CACHE_NODE pNode = malloc(sizeof(T_CACHE_NODE));
    pNode->key           = key;
    pNode->value         = value;
    pNode->pPrev         = NULL;
    pNode->pNext         = NULL;
    pNode->pConflictNext = NULL;
    return pNode;
}
void DeleteNode(PT_CACHE_NODE pNode)
{
    // Remark :  prev, next and confilict are free by user
    pNode->pPrev         = NULL;
    pNode->pNext         = NULL;
    pNode->pConflictNext = NULL;
    free(pNode);
    pNode = NULL;
}


// Double link list operation
PT_DOUBLE_LINK_LIST  CreateDoubleList(int capacity)
{
    PT_DOUBLE_LINK_LIST pDouList = malloc(sizeof(T_DOUBLE_LINK_LIST));
    pDouList->pHead = NULL;
    pDouList->pTail = NULL;
    pDouList->size  = 0;
    // Avoid Modify const variable using error method.
    // method1 :
    //int *ptr = (int *)(&(pDouList->capacity));
    // method2
    const int *ptr = &(pDouList->capacity);
    int *ptr2 = (int * )ptr;
    *ptr2 = capacity;

    return pDouList;
}

bool IsDoubleListEmpty(PT_DOUBLE_LINK_LIST pDouList)
{
    bool ret = false;
    if (0 == pDouList->size) ret = true;

    return ret;
}

bool IsDoubleListFull(PT_DOUBLE_LINK_LIST pDouList)
{
    bool ret = false;
    if (pDouList->capacity == pDouList->size) ret = true;
    printf("full size:%d\n", pDouList->capacity);
    printf("Now size:%d\n", pDouList->size);

    return ret;
}

bool InsertInDoubleList(PT_DOUBLE_LINK_LIST pDouList, PT_CACHE_NODE pNode)
{
    bool insertSuccFlag = !(IsDoubleListFull(pDouList));

    if (insertSuccFlag)
    {
        bool emptyFlag = IsDoubleListEmpty(pDouList);
        (pDouList->size)++;

        if (emptyFlag)
        {
            pDouList->pHead = pNode;
            pDouList->pTail = pNode;
        }
        else
        {
            PT_CACHE_NODE pTailNode = pDouList->pTail;
            pTailNode->pNext = pNode;
            pNode->pPrev     = pTailNode;
            pDouList->pTail  = pNode;
        }

    }
    else
    {
        printf("Double list is full and size : %d\n", pDouList->capacity);
    }

    return insertSuccFlag;
}

PT_CACHE_NODE PopInDoubleList(PT_DOUBLE_LINK_LIST pDouList)
{
    bool emptyFlag = IsDoubleListEmpty(pDouList);

    PT_CACHE_NODE pPopNode = NULL;
    if (!emptyFlag)
    {
        //. can pop element
        (pDouList->size)--;
        pPopNode = pDouList->pHead;
        pDouList->pHead = pPopNode->pNext;

        emptyFlag = IsDoubleListEmpty(pDouList);

        if (!emptyFlag)
        {
            (pDouList->pHead)->pPrev = NULL;
        }
        else
        {
            pDouList->pTail = NULL;
        }
        pPopNode->pNext = NULL;
    }
    else
    {
        printf("can't pop because double list is empty now\n");
    }

    return pPopNode;

}

void CreateHashTable(PT_HASH_TABLE pHashTable, int capacity)
{
    pHashTable  = malloc(sizeof(PT_CACHE_NODE)* capacity);

    int idx = 0;

    for (idx = 0; idx < capacity; idx++)
    {
        pHashTable[idx] = NULL;
    }
}

PT_CACHE_NODE FindHashTable(PT_HASH_TABLE pHashTable, int key)
{


}
void InsetHashTable(PT_HASH_TABLE pHashTable, int key, int value);
