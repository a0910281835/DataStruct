#ifndef _H_QUEUE_ARRAY
#define _H_QUEUE_ARRAY
#include"basic.h"

typedef struct QueueArray* pQueueArray;
typedef struct QueueArray
{
    ELEMENT_T queueVal[MAX_SIZE];
    int top_idx;
    int tail_idx;

}QueueArray;

extern pQueueArray CreateQueueArray(void);


#endif

