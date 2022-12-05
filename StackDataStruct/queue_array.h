#ifndef _H_QUEUE_ARRAY
#define _H_QUEUE_ARRAY
#include"basic.h"


typedef struct QueueArray* pQueueArray;
typedef struct QueueArray
{
    ELEMENT_TYPE queueVal[MAX_SIZE];
    int first_idx;
    int last_idx;

}QueueArray;

extern pQueueArray CreateQueueArray(void);
extern RETURN PushQueueArray(pQueueArray pQueue, ELEMENT_TYPE input);
extern RETURN PopQueueArray(pQueueArray pQueue);


#endif

