#ifndef _H_QUEUE_ARRAY
#define _H_QUEUE_ARRAY
#include "basic.h"
#include "tree.h"

typedef struct QUEUE_ARRAY_T *P_QUEUE_ARRAY_T;


// for templete or More essentially The Structure Queue and Stakc are same , but Obj function is different.
typedef struct QUEUE_ARRAY_T
{
    int    exitIdx;
    int    entranceIdx;
    size_t sizeofObj;
    void   *pQueueBox;

}QUEUE_ARRAY_T;


extern P_QUEUE_ARRAY_T CreatQueueArray(size_t sizeofSpecialObj);


#define R(x) (TakeRemainder((x), (MAX_SIZE)))
#endif
