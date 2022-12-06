#ifndef _H_QUEUE_ARRAY
#define _H_QUEUE_ARRAY
#include"basic.h"


typedef struct QueueArray* PQUEUE_ARRAY_T;
typedef struct QueueArray
{
    ELEMENT_TYPE queueVal[MAX_SIZE];
    int first_idx;
    int last_idx;

}QueueArray;

extern PQUEUE_ARRAY_T CreateQueueArray(void);
extern RETURN PushQueueArray(PQUEUE_ARRAY_T pQueue, ELEMENT_TYPE input);
extern RETURN PopQueueArray(PQUEUE_ARRAY_T pQueue);


#endif

