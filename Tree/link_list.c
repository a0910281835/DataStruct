#include "link_list.h"
//#define _PRINTF
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
#if defined(_PRINTF)
            printf(" error \n");
#endif
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
#if defined(_PRINTF)
        printf("is empty now\n");
#endif

    }
    else
    {
        PT_SLEEP_THREAD_NODE pTravelNode = pWattingQueue->pHead;
        int idx = 0;
        while (NULL != pTravelNode)
        {
#if defined(_PRINTF)
            printf("idx : %d , when : %d\n", idx++, pTravelNode->when);
#endif
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

//-------------------------------Node Structure--------------------------------------------------
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
#if defined(_PRINTF)
    printf("full size:%d\n", pDouList->capacity);
    printf("Now size:%d\n", pDouList->size);
#endif

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
#if defined(_PRINTF)
        printf("Double list is full and size : %d\n", pDouList->capacity);
#endif
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
#if defined(_PRINTF)
        printf("can't pop because double list is empty now\n");
#endif
    }

    return pPopNode;
}

// This function that very nice to relaize how to restart the value
PT_CACHE_NODE TakeOutNodeInDoubleList(PT_CACHE_NODE pPopNode, PT_DOUBLE_LINK_LIST pDouList)
{
    //Check This Node is head or tail and cancel connect
    pDouList->size--;
    if (pDouList->pHead == pPopNode)
    {
        pDouList->pHead = pPopNode->pNext;
    }
    if (pDouList->pTail == pPopNode)
    {
        pDouList->pTail = pPopNode->pPrev;
    }

    //Cancel Node relation of prev and next and Connect prev and next
    PT_CACHE_NODE pNodePrev = pPopNode->pPrev;
    PT_CACHE_NODE pNodeNext = pPopNode->pNext;

    if (pNodePrev != NULL)
    {
        pNodePrev->pNext = pNodeNext;
    }
    if (pNodeNext != NULL)
    {
        pNodeNext->pPrev = pNodePrev;
    }


    pPopNode->pNext = NULL;
    pPopNode->pPrev = NULL;

    return pPopNode;
}

void TravelDoubleList(PT_DOUBLE_LINK_LIST pDouList)
{
    PT_CACHE_NODE pTraveNode = pDouList->pHead;
    int idx = 1;

#if defined(_PRINTF)
    printf("-----Show The Double list element---\n");
#endif
    while (NULL != pTraveNode)
    {
#if defined(_PRINTF)
        printf("idx: %1d , key: %1d, value: %1d\n", idx, pTraveNode->key, pTraveNode->value);
#endif
        pTraveNode = pTraveNode->pNext;
        idx++;
    }
#if defined(_PRINTF)
    printf("----------------------------------\n");
#endif
}

int transOddNum(int capacity)
{
    if (!(capacity & 0x1))
    {
        capacity++;
    }

    return capacity;
}



PT_HASH_TABLE CreateHashTable(int capacity)
{
    // Capacity use odd or prime number
    PT_HASH_TABLE pHashTable = malloc(sizeof(T_HASH_TABLE));
    pHashTable->pHashMapping = malloc(sizeof(PT_CACHE_NODE) * capacity);
    int idx = 0;

    for (idx = 0; idx < capacity; idx++)
    {
        (pHashTable->pHashMapping)[idx] = NULL;
    }

    const int *ptr = &(pHashTable->capacity);
    int *ptr2 = (int *)ptr;
    *ptr2 = capacity;
    ptr2 = NULL;
    return pHashTable;
}

// Find Node and if not the pointer point to NULL.
PT_CACHE_NODE FindHashTable(PT_HASH_TABLE pHashTable, int key, bool* pFindNodeFlag)
{
    int capacity = pHashTable->capacity;

    int mappingIdx = key % capacity;

    PT_CACHE_NODE pCheckNode = (pHashTable->pHashMapping)[mappingIdx];

    *pFindNodeFlag = false;

    while (pCheckNode != NULL)
    {
        if (key == (pCheckNode->key))
        {
            *pFindNodeFlag = true;
            break;
        }

        pCheckNode = pCheckNode->pConflictNext;
    }

    return pCheckNode;
}

// This function don't check hashtable with this node, But need to support create Node and return.
void InsetHashTable(PT_HASH_TABLE pHashTable, PT_CACHE_NODE pNode)
{
    bool findNodeFlag = false;
    int key = pNode->key;
    FindHashTable(pHashTable, key, &(findNodeFlag));

    if (!findNodeFlag)
    {
        int mappingIdx = key % (pHashTable->capacity);
        PT_CACHE_NODE pFirstKeyNode = (pHashTable->pHashMapping)[mappingIdx];
        pNode->pConflictNext = pFirstKeyNode;
        (pHashTable->pHashMapping)[mappingIdx] = pNode;
    }
}

void DeleteNodeInHash(PT_HASH_TABLE pHashTable, PT_CACHE_NODE pNode)
{
    //This Node must be exist in Hash, then This Hash is not empty for this key
    int capacity = pHashTable->capacity;
    int key = pNode->key;
    int mappingIdx = key % capacity;
    PT_CACHE_NODE pCurrentNode = (pHashTable->pHashMapping)[mappingIdx];

    if (pCurrentNode->key == key)
    {
        //Start Point is This Node
        (pHashTable->pHashMapping)[mappingIdx] = pCurrentNode->pConflictNext;
        pCurrentNode->pConflictNext = NULL;
    }
    else
    {
        PT_CACHE_NODE pNextKey = pCurrentNode->pConflictNext;
        while (pNextKey != NULL)
        {
            if (pNextKey->key == key)
            {
                // Delete the connect
                pCurrentNode->pConflictNext = pNextKey->pConflictNext;
                break;
            }
            pCurrentNode = pNextKey;
            pNextKey = pCurrentNode->pConflictNext;
        }

        pNode->pConflictNext = NULL;
    }

}

void TravelHashMapping(PT_HASH_TABLE pHashTable)
{
    int hashSize = pHashTable->capacity;
    int idx = 0;
    for (idx = 0; idx < hashSize; idx++)
    {

        PT_CACHE_NODE pThisLinkNode = pHashTable->pHashMapping[idx];
#if defined(_PRINTF)
        printf("------idx : %1d\n", idx);
#endif
        while (NULL != pThisLinkNode)
        {
#if defined(_PRINTF)
            printf("key : %1d, value : %1d\n", pThisLinkNode->key, pThisLinkNode->value);
#endif
            pThisLinkNode = pThisLinkNode->pConflictNext;
        }
    }
#if defined(_PRINTF)
    printf("-----end---\n");
#endif

}

LRUCache* lRUCacheCreate(int capacity)
{
    LRUCache* pLruCachae = malloc(sizeof(LRUCache));
    // Hash using odd number
    int hashCap = transOddNum(capacity);
    pLruCachae->pHashTable = CreateHashTable(hashCap);
    pLruCachae->pDoublist = CreateDoubleList(capacity);

    return pLruCachae;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    //-----------------------------------------------
    //Condtion 1 : if this node not exist in This Cache
    // step 1 : Create Node
    // step 2 : Check Double is full or not
    // step 3 : kick Out last key in Hash and DoubleList
    // step 4 : Insert This Node in Hash and DoubleList
    //
    //Condtion 2 : if this Node exist Update this Node inform

    int retFindFlag = lRUCacheGet(obj, key);

    if (retFindFlag < 0)
    {
        PT_CACHE_NODE pNode = CreateNode(key, value);
        bool fullFlag       = IsDoubleListFull(obj->pDoublist);

        if (fullFlag)
        {
            PT_CACHE_NODE pPopNode = PopInDoubleList(obj->pDoublist);
            DeleteNodeInHash((obj->pHashTable), pPopNode);
#if defined(_PRINTF)
            printf("delete least not used node key :%1d, value:%1d\n", pPopNode->key, pPopNode->value);
#endif
            DeleteNode(pPopNode);
        }

        InsetHashTable((obj->pHashTable), pNode);
        InsertInDoubleList((obj->pDoublist), pNode);
    }
}


int lRUCacheGet(LRUCache* obj, int key)
{
    //Slow Thinking
    //Purpose : Update key information
    //Step1 : check this Key exist in Cache by hash and if not exist then return -1
    //if exist then Grap The Node and kick out DoubleList and then Inset DoubleList
    //
    bool findFlag = false;
    PT_CACHE_NODE pNode =  FindHashTable(obj->pHashTable, key, &findFlag);

    if (findFlag)
    {
        pNode = TakeOutNodeInDoubleList(pNode, obj->pDoublist);
        InsertInDoubleList((obj->pDoublist), pNode);
        int value = pNode->value;
        return value;
    }
    else
    {
        return -1;
    }
}

void lRUCacheFree(LRUCache* obj)
{
    // Purpose : effect Delete
    // Step1 : using Double list to clear Node.
    // Step2 : clear Double List Pointer
    // Step3 : clear HashMpping Array
    // Step4 : clear cache
    PT_DOUBLE_LINK_LIST pDouList   = obj->pDoublist;
    PT_HASH_TABLE       pHashTable = obj->pHashTable;
    // step1:
    PT_CACHE_NODE pTraveNode = pDouList->pHead;
    while (NULL != pTraveNode)
    {
        PT_CACHE_NODE pDeleteNode = pTraveNode;
        pTraveNode = pTraveNode->pNext;
        DeleteNode(pDeleteNode);
    }

    //step2:
    pDouList->pHead = NULL;
    pDouList->pTail = NULL;
    free(pDouList);
    //step3:
    int cap = pHashTable->capacity;
    int idx = 0;
    for (idx = 0; idx < cap; idx++)
    {
        pHashTable->pHashMapping[idx] = NULL;
    }

    free(pHashTable->pHashMapping);
    free(pHashTable);

    //step4:

    free(obj);


}
