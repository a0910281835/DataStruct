#ifndef  _H_HEAP
#define  _H_HEAP
#include "basic.h"

typedef struct HEAP_T * P_HEAP_T;


typedef struct HEAP_T
{
    NUM_T capacity;
    NUM_T size;
    int *array;
}HEAP_T;

P_HEAP_T CreateHeap(NUM_T size);
DECIDE_T IsFullHeap(P_HEAP_T pHeap);
DECIDE_T IsEmptyHeap(P_HEAP_T pHeap);
//MAX Heap operation
void InsertMaxHeap(P_HEAP_T pHeap, int val);
int DeleteMaxHeap(P_HEAP_T pHeap);



#endif
