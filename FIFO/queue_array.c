#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"queue_array.h"


pQueueArray CreateQueueArray(void)
{
    pQueueArray pQueue = (pQueueArray) malloc(sizeof(QueueArray));
    pQueue->top_idx = pQueue->tail_idx = -1;

    return pQueue;
}
