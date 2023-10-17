#ifndef _H_LINK_LIST
#define _H_LINK_LIST
#include "basic.h"


#define T_THREAD int
#define bool char


typedef  T_THREAD * PT_THREAD; 

typedef struct T_SLEEP_THREAD_NODE
{
    int when;
    T_THREAD *pThread;
    T_THREAD * next;
    T_THREAD * prev;
}T_SLEEP_THREAD_NODE;


typedef struct T_SLEEP_THREAD_NODE * PT_SLEEP_THREAD_NODE;

typedef struct T_WAITTING_PRIORITY_QUEUE
{
    PT_SLEEP_THREAD_NODE pHead;
    PT_SLEEP_THREAD_NODE pTail;

}T_WAITTING_PRIORITY_QUEUE;


bool IsWQEmpty(T_WAITTING_PRIORITY_QUEUE *pWattingQueu);

T_WAITTING_PRIORITY_QUEUE * CreateWaittingQueue(void);
bool DeleteWaittingQueue(T_WAITTING_PRIORITY_QUEUE *pWattingQueue);




#endif
