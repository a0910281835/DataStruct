#ifndef _H_GRAPH
#define _H_GRAPH
#include "basic.h"

typedef struct Node  NODE_GRAPH_T;
typedef struct Node* P_NODE_GRAPH_T;
typedef struct Node
{
    int val;
    int numNeighbors;
    P_NODE_GRAPH_T*  neighbors;
}Node;

#define STATUS_T char
enum
{
    UNINITAL  = 0,
    TRAVELING = 1,
};

typedef struct NODE_INFORM_T
{
    P_NODE_GRAPH_T pNode;
    STATUS_T status;
}NODE_INFORM_T;

typedef struct NODE_INFORM_T* P_NODE_INFORM_T;


// FIFO struct
typedef struct FIFO_T * P_FIFO_T;

typedef struct FIFO_T
{
    P_NODE_GRAPH_T nodeArray[128];
    int inputIdx;
    int outputIdx;
}FIFO_T;
// ------------------------------
//
extern P_FIFO_T CreateFIFOArray(void);
extern void PushFIFO(P_FIFO_T pFifo, P_NODE_GRAPH_T pNode);
extern P_NODE_GRAPH_T PopFIFO(P_FIFO_T pFifo);
extern void PrintfGraph(P_NODE_GRAPH_T pNode);

extern struct Node *cloneGraph(struct Node *s);
#define uint32_t unsigned int
uint32_t reverseBits(uint32_t n);
//136. Single Number
extern int singleNumber(int* nums, int numsSize);
#endif
