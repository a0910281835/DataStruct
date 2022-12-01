#ifndef _H_QUEUE_ARRAY
#define _H_QUEUE_ARRAY
#include"basic.h"

typedef enum
{
    EMPTY,
    SUCC,
    FULL = (MAX_SIZE - 1)
}SIZE_CONDITION;

typedef struct RETRURN
{
    SIZE_CONDITION size_cond;
    ELEMENT_T output;

}RETURN;
typedef struct QueueArray* pQueueArray;
typedef struct QueueArray
{
    ELEMENT_T queueVal[MAX_SIZE];
    int first_idx;
    int last_idx;

}QueueArray;

extern pQueueArray CreateQueueArray(void);
extern RETURN PushQueueArray(pQueueArray pQueue, ELEMENT_T input);
extern RETURN PopQueueArray(pQueueArray pQueue);


#endif

