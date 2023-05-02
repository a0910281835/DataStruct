#include "graph.h"
// leetcode 133. Clone Graph
//Given a reference of a node in a connected undirected graph.
//Return a deep copy (clone) of the graph.
//Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
//class Node
//{
//  public int val;
//  public List<Node> neighbors;
//}
//
//
//Test case format:
//For simplicity, each node's value is the same as the node's index (1-indexed).
//For example, the first node with val == 1, the second node with val == 2, and so on.
//The graph is represented in the test case using an adjacency list.
//An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
//The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
//
//Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
//Output: [[2,4],[1,3],[2,4],[1,3]]
//Explanation: There are 4 nodes in the graph.
//1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
//2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
//3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
//4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
//
//
//Input: adjList = [[]]
//Output: [[]]
//Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
//
//
//
//Example 3:
//Input: adjList = []
//Output: []
//Explanation: This an empty graph, it does not have any nodes.
//
//Constraints:
//The number of nodes in the graph is in the range [0, 100].
//1 <= Node.val <= 100
//Node.val is unique for each node.
//There are no repeated edges and no self-loops in the graph.
//The Graph is connected and all nodes can be visited starting from the given node.

// Input : original(be copy) Graph Node.  Output : Copy Graph Node.
static P_NODE_GRAPH_T recursiveGraph(P_NODE_GRAPH_T pHead, NODE_INFORM_T * pNodeState)
{
    P_NODE_GRAPH_T pCpyNode = NULL;

    if (NULL != pHead)
    {
        int idx = pHead->val;
        if (pNodeState[idx].status == UNINITAL)
        {
            //printf("First Time : %d\n",pHead->val);
            pCpyNode = malloc(sizeof(NODE_GRAPH_T));
            pCpyNode->numNeighbors = pHead->numNeighbors;
            pCpyNode->neighbors = malloc(sizeof(P_NODE_GRAPH_T) * (pCpyNode->numNeighbors));
            pCpyNode->val = pHead->val;
            pNodeState[idx].pNode  = pCpyNode;
            pNodeState[idx].status = TRAVELING;

            int neighIdx = 0;
            P_NODE_GRAPH_T pNeighNode;

            for (neighIdx = 0; neighIdx < pCpyNode->numNeighbors; neighIdx++)
            {
                //printf("time %2d\n", neighIdx);
                //printf("Neigh : %2d\n", (pHead->neighbors[neighIdx])->val);
                pNeighNode = recursiveGraph(pHead->neighbors[neighIdx], pNodeState);
                pCpyNode->neighbors[neighIdx] = pNeighNode;
            }

        }
        else
        {
            pCpyNode = pNodeState[idx].pNode;
            //printf("Call Have Exist Val : %2d\n", (pNodeState[idx].pNode)->val);
        }

    }
    else
    {
        //printf("not exist");
    }
    return  pCpyNode;

}



struct Node *cloneGraph(struct Node *s)
{
    NODE_INFORM_T nodeArray[101];
    int idx = 0;
    for (idx = 0; idx < 101; idx++)
    {
        nodeArray[idx].pNode  = NULL;
        nodeArray[idx].status = UNINITAL;
    }

    P_NODE_GRAPH_T pRet;
    pRet =  recursiveGraph(s, nodeArray);
    //Use DFS
    return pRet;
}

// FIFO function
P_FIFO_T CreateFIFOArray(void)
{
    P_FIFO_T pFifo = malloc(sizeof(FIFO_T));
    pFifo->inputIdx  = 0;
    pFifo->outputIdx = 0;

    return pFifo;
}

void PushFIFO(P_FIFO_T pFifo, P_NODE_GRAPH_T pNode)
{
    // FULL in this leetcode don't worry.
    if (NULL != pNode)
    {
        int *pIdx = &(pFifo->inputIdx);
        pFifo->nodeArray[*pIdx] = pNode;
        *pIdx = ((*pIdx) + 1) & 0x7f;
    }
}

P_NODE_GRAPH_T PopFIFO(P_FIFO_T pFifo)
{
    int *pInpIdx = &(pFifo->inputIdx);
    int *pOutIdx = &(pFifo->outputIdx);
    P_NODE_GRAPH_T pOutNode = NULL;
    if (*pInpIdx == *pOutIdx)
    {
        printf("Empty\n");
    }
    else
    {
        pOutNode = pFifo->nodeArray[*pOutIdx];
        *pOutIdx  = (*pOutIdx + 1) & 0x7f;
    }
    return pOutNode;
}

void PrintfGraph(P_NODE_GRAPH_T pNode)
{
    if (NULL != pNode)
    {
        STATUS_T statusArray[101] = {0};
        P_FIFO_T pFifo = CreateFIFOArray();
        PushFIFO(pFifo, pNode);

        P_NODE_GRAPH_T pOuputNode = PopFIFO(pFifo);


        // FIFO is not empty!
        while (NULL != pOuputNode)
        {
            int idx = pOuputNode->val;
            if (UNINITAL == statusArray[idx])
            {
                int neighborIdx = 0;
                statusArray[idx] = TRAVELING;

                printf("Node val : %2d\n", pOuputNode->val);

                for (neighborIdx = 0; neighborIdx < pOuputNode->numNeighbors; neighborIdx++)
                {
                    PushFIFO(pFifo, pOuputNode->neighbors[neighborIdx]);
                }
            }

            pOuputNode = PopFIFO(pFifo);
        }

    }


}





// 190. Reverse Bits
// Reverse bits of a given 32 bits unsigned integer.
//
// Note:
//
// Note that in some languages, such as Java, there is no unsigned integer type.
// In this case, both input and output will be given as a signed integer type.
// They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
// In Java, the compiler represents the signed integers using 2's complement notation.
// Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
//
//
// Example 1:
//
// Input: n = 00000010100101000001111010011100
// Output:    964176192 (00111001011110000010100101000000)
// Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596,
// so return 964176192 which its binary representation is 00111001011110000010100101000000.
//
// Example 2:
//
// Input: n = 11111111111111111111111111111101
// Output:   3221225471 (10111111111111111111111111111111)
// Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293,
// so return 3221225471 which its binary representation is 10111111111111111111111111111111.
// Constraints:
//
// The input must be a binary string of length 32
//
//  Follow up: If this function is called many times, how would you optimize it?
//
//
uint32_t reverseBits(uint32_t n)
{
    //

    int num = n;
    int sum = 0;
    int idx = 31;
    while (idx > 0)
    {
        while ((num >> idx) & 0x1)
        {
            sum += (1 << (31-idx));
            idx--;
        }

        idx--;
    }

    return sum;
}
