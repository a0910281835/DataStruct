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




#endif
