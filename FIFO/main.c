#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"queue_array.h"

int main(void)
{
    pQueueArray pQueue = CreateQueueArray();
    printf("%d, %d\n", pQueue->top_idx, pQueue->tail_idx);

    return 1;
}
