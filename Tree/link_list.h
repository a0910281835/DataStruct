#ifndef _H_LINK_LIST
#define _H_LINK_LIST
#include "basic.h"


#define T_THREAD int


typedef  T_THREAD * PT_THREAD;

typedef struct T_SLEEP_THREAD_NODE * PT_SLEEP_THREAD_NODE;

typedef struct T_SLEEP_THREAD_NODE
{
    int when;
    T_THREAD *pThread;
    PT_SLEEP_THREAD_NODE    next;
    PT_SLEEP_THREAD_NODE prev;
}T_SLEEP_THREAD_NODE;



typedef struct T_WAITTING_PRIORITY_QUEUE
{
    PT_SLEEP_THREAD_NODE pHead;//.output
    PT_SLEEP_THREAD_NODE pTail;//.input

}T_WAITTING_PRIORITY_QUEUE;


bool IsWQEmpty(T_WAITTING_PRIORITY_QUEUE *pWattingQueu);

T_WAITTING_PRIORITY_QUEUE * CreateWaittingQueue(void);
bool DeleteWaittingQueue(T_WAITTING_PRIORITY_QUEUE *pWattingQueue);
PT_SLEEP_THREAD_NODE CreateDoubleListNode(T_THREAD *pT, int timing);
void InsertSleepList(T_WAITTING_PRIORITY_QUEUE *pWattingQueue, T_THREAD *pThread, int sleepTiming);
void TravelWatingQueue(T_WAITTING_PRIORITY_QUEUE *pWattingQueue);
T_THREAD * PopWaittingQueue(T_WAITTING_PRIORITY_QUEUE *pWattingQueue);


// leetcode 146 LRU algorithm
//
// hashing and double link list

//  Define Node Struct and operation
typedef struct T_CACHE_NODE * PT_CACHE_NODE;
typedef struct T_CACHE_NODE
{
    int key;
    int value;
    PT_CACHE_NODE pPrev;
    PT_CACHE_NODE pNext;
    PT_CACHE_NODE pConflictNext;

}T_CACHE_NODE;

PT_CACHE_NODE CreateNode(int key, int value);
void DeleteNode(PT_CACHE_NODE pNode);



// Double link list with operation
typedef struct T_DOUBLE_LINK_LIST * PT_DOUBLE_LINK_LIST;
typedef struct T_DOUBLE_LINK_LIST
{
    PT_CACHE_NODE pHead;
    PT_CACHE_NODE pTail;
    int size;

}T_DOUBLE_LINK_LIST;

T_DOUBLE_LINK_LIST * CreateDoubleList(void);
bool IsDoubleListEmpty(T_DOUBLE_LINK_LIST * pFifo);
bool IsDoubleListFull(T_DOUBLE_LINK_LIST * pFifo);
void InsertInDoubleList(T_DOUBLE_LINK_LIST * pFifo, PT_CACHE_NODE pNode);
PT_CACHE_NODE PopInDoubleList(T_DOUBLE_LINK_LIST * pFifo);


typedef struct T_CACHE_NODE ** PT_HASH_TABLE;
PT_CACHE_NODE FindHashTable(PT_HASH_TABLE pHashTable, int key);
void InsetHashTable(PT_HASH_TABLE pHashTable, int key, int value);




typedef struct LRUCache
{
    PT_DOUBLE_LINK_LIST pDoublist;
    PT_HASH_TABLE pHashTable;
}T_LRU_CACHE;

typedef struct LRUCache LRUCache;

LRUCache* lRUCacheCreate(int capacity);
int lRUCacheGet(LRUCache* obj, int key);
void lRUCachePut(LRUCache* obj, int key, int value);
void lRUCacheFree(LRUCache* obj);



#endif
