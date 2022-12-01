#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"queue_array.h"

int main(void)
{
    pQueueArray pQueue = CreateQueueArray();
    printf("%d, %d\n", pQueue->first_idx, pQueue->last_idx);
    int idx = 0;
    RETURN ret;
    for (idx = 0; idx < 102; idx++)
    {
         ret = PushQueueArray(pQueue, idx);
        if (SUCC == ret.size_cond)
        {
            printf("PushVal:%d\n", ret.output);
        }
        else
        {
            printf("FULL\n");
        }
    }


    do
    {
        ret = PopQueueArray(pQueue);
        if (EMPTY == ret.size_cond)
        {
            printf("Queue is empty\n");
        }
        else
        {
            printf("PopVal : %d\n", ret.output);
        }

    } while(ret.size_cond);

    return 1;
}
