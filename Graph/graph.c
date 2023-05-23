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
    //Hash Table
    int hashTable[32] =
    {
        0x80000000, 0x40000000, 0x20000000, 0x10000000, 0x08000000, 0x04000000, 0x02000000, 0x01000000,
        0x00800000, 0x00400000, 0x00200000, 0x00100000, 0x00080000, 0x00040000, 0x00020000, 0x00010000,
        0x008000, 0x004000, 0x002000, 0x001000, 0x000800, 0x0000400, 0x0000200, 0x0000100,
        0x0080, 0x0040, 0x0020, 0x0010, 0x0008, 0x00004, 0x00002, 0x00001,
    };

    int num = n;
    int sum = 0;
    int idx = 31;
    while (idx >= 0)
    {
        while ((idx >= 0) && (num >> idx) & 0x1)
        {
            sum += hashTable[idx];
            idx--;
        }

        idx--;
    }

    return sum;
}

//136. Single Number
//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
//You must implement a solution with a linear runtime complexity and use only constant extra space.
//Example 1:
//
//Input: nums = [2,2,1]
//Output: 1
//Example 2:
//
//Input: nums = [4,1,2,1,2]
//Output: 4
//Example 3:
//
//Input: nums = [1]
//Output: 1
//
//
// Constraints:
//
// 1 <= nums.length <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// Each element in the array appears twice except for one element which appears only once.
//
static void recusiveFindMaxMinMode(int* nums, int numsSize, int *pMax, int *pMin)
{
    if ((*pMax -*pMin) >= 1)
    {
        int hashCollision[2];
        int max[2];
        int min[2];
        int idx = 0;
        printf("---------------------\n");
        printf("compare\n");
        printf(" max : %5d\n", *pMax);
        printf(" min : %5d\n", *pMin);
        printf("---------------------\n");

        for (idx = 0; idx < 2; idx++)
        {
            hashCollision[idx] = 0;
            max[idx] = *pMin - 1;
            min[idx] = *pMax + 1;
        }


        int dividend = (*pMax - *pMin + 1);
        int divisor  = (dividend & 0x1) ? ((dividend >> 1) + 1) : (dividend >> 1);


        for (idx = 0; idx < numsSize; idx++)
        {
            if ((*pMin <= nums[idx]) && (nums[idx] <= *pMax))
            {
                int rangeIdx = (nums[idx] - *pMin) / divisor;
                hashCollision[rangeIdx]++;
                max[rangeIdx] = (max[rangeIdx] < nums[idx]) ? nums[idx] : max[rangeIdx];
                min[rangeIdx] = (nums[idx] < min[rangeIdx]) ? nums[idx] : min[rangeIdx];

            }

        }

        idx = (hashCollision[0] & 0x1) ? 0 : 1;
        *pMax = max[idx];
        *pMin = min[idx];
        printf(" max : %5d\n", *pMax);
        printf(" min : %5d\n", *pMin);
        recusiveFindMaxMinMode(nums, numsSize, pMax, pMin);
    }

}
int singleNumber(int* nums, int numsSize)
{
    //Use Collision to Detect!
    int idx = 0;
    int max =  30001;
    int min = -30001;
    recusiveFindMaxMinMode(nums, numsSize, &max, &min);
    return max;
}

//137. Single Number II
//Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
//You must implement a solution with a linear runtime complexity and use only constant extra space.
//
// Example 1:
//
// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:
//
// Input: nums = [0,1,0,1,0,1,99]
// Output: 99
//
//
//Constraints:
//
//1 <= nums.length <= 3 * 104
//-231 <= nums[i] <= 231 - 1
//Each element in nums appears exactly three times except for one element which appears once.
static void recusiveFindMaxMinMode2(int* nums, int numsSize, int *pMax, int *pMin)
{
    int divisor;
    int hashCollision[64];
    int idx = 0;
    for (idx = 0; idx < 64; idx++)
    {
        hashCollision[idx] = 0;
    }
    if ((*pMax > *pMin) && ((*pMax - 64) > *pMin))
    {
        printf("%d -64:\n", *pMax);

        printf("---------------------\n");
        printf("compare\n");
        printf(" max : %d\n", *pMax);
        printf(" min : %d\n", *pMin);
        printf("---------------------\n");

        divisor  = 1073741824;

        if ((*pMax == 2147483647) && (*pMin == -2147483648))
        {
            for (idx = 0; idx < numsSize; idx++)
            {
                if ((*pMin <= nums[idx]) && (nums[idx] < -1073741824))
                {
                    hashCollision[0]++;
                }
                else if ((-1073741824 <= nums[idx]) && (nums[idx] < 0))
                {
                    hashCollision[1]++;
                }
                else if ((0 <= nums[idx]) && (nums[idx] < 1073741824))
                {
                    hashCollision[2]++;
                }
                else if ((1073741824 <= nums[idx]) && (nums[idx] <= 2147483647))
                {
                     hashCollision[3]++;
                }


            }
        }
        else
        {
            int dividend = (*pMax - *pMin + 1);
            divisor  = (dividend & 0x1) ? ((dividend >> 6) + 1) : (dividend >> 6);
            for (idx = 0; idx < numsSize; idx++)
            {
                if ((*pMin <= nums[idx]) && (nums[idx] <= *pMax))
                {
                    int rangeIdx = (nums[idx] - *pMin) / divisor;
                    hashCollision[rangeIdx]++;

                }

            }

        }
        printf("dividsor : %d\n", divisor);

        for (idx = 0; idx < 64; idx++)
        {
            if ((hashCollision[idx] % 3) == 1) break;
        }
        printf("idx : %d\n", idx);
        if (divisor == 1073741824)
        {
            switch (idx)
            {
                case 0 :
                    *pMax = -1073741823;
                    *pMin = *pMin;
                    break;
                case 1 :
                    *pMax = -1;
                    *pMin = -1073741824;
                    break;
                case 2 :
                    *pMax = 1073741823;
                    *pMin = 0;
                    break;
                case 3 :
                    *pMax = 2147483647;
                    *pMin = 1073741824;
                    break;
            }
        }
        else
        {

            *pMax = *pMin + ((idx + 1) * divisor - 1);
            *pMin = *pMin + idx * divisor;
        }
        printf(" max : %d\n", *pMax);
        printf(" min : %d\n", *pMin);
        recusiveFindMaxMinMode2(nums, numsSize, pMax, pMin);
    }
    else if (*pMin + 64 > *pMax)
    {
        int idx = 0;
        int rangeIdx = 0;
        for (idx = 0; idx < numsSize; idx++)
        {
            if ((*pMin <= nums[idx]) && (nums[idx] <= *pMax))
            {
                int rangeIdx = (nums[idx] - *pMin);
                hashCollision[rangeIdx]++;
            }

        }
        for (idx = 0; idx < 64; idx++)
        {
            if ((hashCollision[idx] % 3) == 1) break;
        }
        printf("idx : %d\n", idx);

         *pMax = idx + *pMin;
         *pMin = idx + *pMin;
        printf(" max : %d\n", *pMax);

    }

}
int singleNumber2(int* nums, int numsSize)
{
    //Use Collision to Detect!
    int idx = 0;
    int max =   2147483647;
    int min =  -2147483648;
    //printf(" max : %d\n", max);
    //printf(" min : %d\n", min);
    recusiveFindMaxMinMode2(nums, numsSize, &max, &min);
    //printf(" max : %d\n", max);
    //printf(" min : %d\n", min);
    return max;

}



//260. Single Number III
//
//Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
//Find the two elements that appear only once. You can return the answer in any order.
//
//You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
//
//Example 1:
//
//Input: nums = [1,2,1,3,2,5]
//Output: [3,5]
//Explanation:  [5, 3] is also a valid answer.
//Example 2:
//
//Input: nums = [-1,0]
//Output: [-1,0]
//Example 3:
//
//Input: nums = [0,1]
//Output: [1,0]
//
//
//Constraints:
//
//2 <= nums.length <= 3 * 104
//-231 <= nums[i] <= 231 - 1
//Each integer in nums will appear twice, only two integers will appear once.
static void recusiveFindMaxMinMode3(int* nums, int numsSize, int *pMax, int *pMin)
{
    if (*pMax > *pMin)
    {

        int divisor;
        int hashCollision[2];
        int max[2];
        int min[2];
        int idx = 0;
        //printf("---------------------\n");
        //printf("compare\n");
        //printf(" max : %d\n", *pMax);
        //printf(" min : %d\n", *pMin);
        //printf("---------------------\n");

        for (idx = 0; idx < 2; idx++)
        {
            hashCollision[idx] = 0;
            max[idx] = *pMin;
            min[idx] = *pMax;
        }

        if ((*pMax == 2147483647) && (*pMin == -2147483648))
        {
            int rangeIdx;
            for (idx = 0; idx < numsSize; idx++)
            {
                if (nums[idx] < 0)
                {
                    rangeIdx = 0;
                }
                else
                {
                    rangeIdx = 1;
                }
                hashCollision[rangeIdx]++;
                max[rangeIdx] = (max[rangeIdx] < nums[idx]) ? nums[idx] : max[rangeIdx];
                min[rangeIdx] = (nums[idx] < min[rangeIdx]) ? nums[idx] : min[rangeIdx];

            }
        }
        else
        {
            int dividend = (*pMax - *pMin + 1);
            divisor  = (dividend & 0x1) ? ((dividend >> 1) + 1) : (dividend >> 1);
            for (idx = 0; idx < numsSize; idx++)
            {
                if ((*pMin <= nums[idx]) && (nums[idx] <= *pMax))
                {
                    int rangeIdx = (nums[idx] - *pMin) / divisor;
                    hashCollision[rangeIdx]++;
                    max[rangeIdx] = (max[rangeIdx] < nums[idx]) ? nums[idx] : max[rangeIdx];
                    min[rangeIdx] = (nums[idx] < min[rangeIdx]) ? nums[idx] : min[rangeIdx];

                }

            }

        }

        idx = ((hashCollision[0] % 3) & 0x1) ? 0 : 1;
        *pMax = max[idx];
        *pMin = min[idx];
        //printf(" max : %d\n", *pMax);
        //printf(" min : %d\n", *pMin);
        recusiveFindMaxMinMode3(nums, numsSize, pMax, pMin);
    }

}
int singleNumber3(int* nums, int numsSize)
{
    //Use Collision to Detect!
    int idx = 0;
    int max =   2147483647;
    int min =  -2147483648;
    //printf(" max : %d\n", max);
    //printf(" min : %d\n", min);
    recusiveFindMaxMinMode3(nums, numsSize, &max, &min);
    //printf(" max : %d\n", max);
    //printf(" min : %d\n", min);
    return max;

}


//191. Number of 1 Bits
//Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
//
//Note:
//Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
//In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.
//
//Example 1:
//
//Input: n = 00000000000000000000000000001011
//Output: 3
//Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
//Example 2:
//
//Input: n = 00000000000000000000000010000000
//Output: 1
//Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
//Example 3:
//
//Input: n = 11111111111111111111111111111101
//Output: 31
//Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
//
//Constraints:
//
//The input must be a binary string of length 32.
//
//
// Follow up: If this function is called many times, how would you optimize it?
int hammingWeight(uint32_t n)
{
    int recordNum = 0;
    while (n != 0)
    {
        n &= (n-1);
        recordNum++;


    }

    return recordNum;
}


// 141. Linked List Cycle
// Given head, the head of a linked list, determine if the linked list has a cycle in it
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.
//
//Example 1:
//
//Input: head = [3,2,0,-4], pos = 1
//Output: true
//Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
//
// (3) -> (2) -> (0) -> (4)
//         ^             |
//         |  <-   <-    v
//
//
//Input: head = [1,2], pos = 0
//Output: true
//Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
//
// (1) -> (2)
//  ^      |
//  |  __  |


// Input: head = [1], pos = -1
//Output: false
//Explanation: There is no cycle in the linked list.
//
// (1)
//
// Constraints:

//The number of the nodes in the list is in the range [0, 10^4].
//-10^5 <= Node.val <= 10^5
//pos is -1 or a valid index in the linked-list.
//
//Follow up: Can you solve it using O(1) (i.e. constant) memory?
//
//
 //* Definition for singly-linked list.
 //* struct ListNode {
 //*     int val;
 //*     struct ListNode *next;
 //* };
 //*/
P_RECORD_ADDRESS_T InsertOrderSeqence(P_RECORD_ADDRESS_T pHead, unsigned int * pAddr, bool * hasCycleRet)
{
    //pList is not empty beacuse has guard element.
    //
    // X->Y
    // X(empty) < val and val < Y.
    P_RECORD_ADDRESS_T pList = pHead;
    while((pList->pNext) != NULL)
    {
        if ((pList->pNext)->pAddr < pAddr)
            pList = pList->pNext;
        else
            break;
    }
    //Cond1 : pList->val < val and val <=  (pList->next)->val
    if ((NULL != pList->pNext) && ((pList->pNext)->pAddr == pAddr))
    {
        *hasCycleRet = YES;
        //printf("YES\n");
    }
    else
    {
        // Inset Element
        //printf("data : %p\n", pList->pAddr);
        //Ineset Position.
        P_RECORD_ADDRESS_T pNext = pList->pNext;
        P_RECORD_ADDRESS_T pInsertEle = malloc(sizeof(RECORD_ADDRESS_T));
        pInsertEle->pAddr = pAddr;
        pList->pNext = pInsertEle;
        pInsertEle->pNext = pNext;
    }
    return pHead;
}

bool hasCycle(struct ListNode *head)
{
    bool hasCycleRet = NO;
    if (NULL != head)
    {
        // At least link list has one elemnet.
        P_RECORD_ADDRESS_T pOrderAddr = malloc(sizeof(RECORD_ADDRESS_T));
        pOrderAddr->pAddr = (unsigned int*)NULL;
        pOrderAddr->pNext = NULL;

        while (NULL != head->next)
        {
            InsertOrderSeqence(pOrderAddr, (unsigned int*)head, &hasCycleRet);
            if (YES == hasCycleRet) break;
            head = head->next;
        }


    }
    return hasCycleRet;

}


bool hasCycle2(struct ListNode *head)
{

    bool hasCycleRet = NO;

    if (NULL != head)
    {
        P_LISTNODE_T pOneStep = head;
        P_LISTNODE_T pTwoStep = head;

        do
        {
            NEXT(pOneStep);
            NEXT(pTwoStep);
            if (pTwoStep != NULL)
            {
                NEXT(pTwoStep);
            }
            else
            {
                hasCycleRet = NO;
                return hasCycleRet;
            }

            if (pOneStep == pTwoStep)
            {

                hasCycleRet = YES;
                return hasCycleRet;
            }


        } while(pTwoStep!= NULL);
    }

    return hasCycleRet;
}
//155. Min Stack
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//Implement the MinStack class:
//
//MinStack() initializes the stack object.
//void push(int val) pushes the element val onto the stack.
//void pop() removes the element on the top of the stack.
//int top() gets the top element of the stack.
//int getMin() retrieves the minimum element in the stack.
//You must implement a solution with O(1) time complexity for each function.

//Example 1:
//
//Input
//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
//
//Output
//[null,null,null,null,-3,null,0,-2]
//
//Explanation
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin(); // return -3
//minStack.pop();
//minStack.top();    // return 0
//minStack.getMin(); // return -2
//
//onstraints:
//
//-2^31 <= val <= 2^31 - 1
//Methods pop, top and getMin operations will always be called on non-empty stacks.
//At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
//



/**
 *  * Your MinStack struct will be instantiated and called as such:
 *  * MinStack* obj = minStackCreate();
 *  * minStackPush(obj, val);
 *
 *  * minStackPop(obj);
 *
 *  * int param_3 = minStackTop(obj);
 *
 *  * int param_4 = minStackGetMin(obj);
 *
 *  * minStackFree(obj);
 * */

char * (StrMinStack[]) = {"MinStack", "push", "pop", "top", "getMin"};


int ParserStringToMinStackOperate(char* string)
{
    int idx = 0;
    for (idx = 0; idx < 5; idx++)
    {
        if (!strcmp(string, StrMinStack[idx]))
                return idx;
    }

    return -1;
}

static int stringToDigital(char ch)
{
    int ret = (int)ch;
    ret -= 48;

    return ret;
}

int Myatoi(const char *s, int size)
{
    int sign = 1;
    int sum  = 0;
    int idx =  0;

    if (s[idx] == '-')
    {
        sign = -1;
        idx++;
    }

    while (idx < size)
    {
        int coeff = stringToDigital(s[idx++]);
        sum = coeff + (sum * 10);
    }

    sum = sum * sign;

    return sum;
}

int * ParserStringToArray(char* string, int size)
{
    int *array = malloc(sizeof(int) * size);

    int idx = 0;
    int arrayCnt = 0;
    int frontBracketIdx = 0;
    int lastBracketIdx  = 0;

    while (arrayCnt < size)
    {
        if (string[idx] == '[')
        {
            frontBracketIdx = idx;
        }
        else if (string[idx] == ']')
        {
            lastBracketIdx = idx;
            array[arrayCnt++] = Myatoi(string + (frontBracketIdx+1) , lastBracketIdx-frontBracketIdx-1);
        }

        idx++;

    }

    return array;
}

void MinStackSeqOperate(char *ch[], int size)
{
    P_MIN_STACK_T pMinStack = NULL;
    static int sFirstCreate = NO;

    int idx = 0;

    for (idx = 0; idx < size; idx++)
    {
        int parserIdx = ParserStringToMinStackOperate(ch[idx]);

        switch(parserIdx)
        {
            case 0 : //MinStack;

                if (NO == sFirstCreate)
                    pMinStack = minStackCreate();
                sFirstCreate = YES;

                break;

            case 1 : //Push

                break;

            case 2 : //Pop

                break;

            case 3 : //Top

                break;

            case 4 : //GetMin

                break;

            default :
                break;
        }
    }


}




MinStack* minStackCreate()
{
    P_MIN_STACK_T pMinStack = malloc(sizeof(MIN_STACK_T));
    pMinStack->pHead = NULL;
    pMinStack->cellNum = 30001;
    pMinStack->useNum = 0;
    pMinStack->pArray = malloc(sizeof(P_MIN_STACK_T) * (pMinStack->cellNum));
    return pMinStack;
}


static int insertInMinPriority(MinStack* pMinStack, P_LISTNODE_T pInsertNode)
{
    //This function guarantee size not full.

    int *pIdx = &(pMinStack->useNum);

    pMinStack->pArray[*pIdx] = pInsertNode;
    int childIdx  = *pIdx;
    int parentIdx = (*pIdx == 0) ? (*pIdx) : ((*pIdx-1) >> 1);

    P_LISTNODE_T pChildList = pMinStack->pArray[childIdx];
    P_LISTNODE_T pParList   = pMinStack->pArray[parentIdx];
    while ((pChildList->val < pParList->val) && (childIdx != 0))
    {
        P_LISTNODE_T pTemp = pChildList;
        pMinStack->pArray[childIdx]  = pParList;
        pParList->pos = childIdx;
        pMinStack->pArray[parentIdx] = pTemp;
        childIdx  = parentIdx;
        parentIdx = (childIdx == 0) ? (childIdx) : ((childIdx-1) >> 1);
        pChildList = pMinStack->pArray[childIdx];
        pParList   = pMinStack->pArray[parentIdx];
    }

    return childIdx;
}

void minStackPush(MinStack* obj, int val)
{
    NUM_T* pUseNum  = &(obj->useNum);
    NUM_T* pCellNum = &(obj->cellNum);

    if (*pCellNum == *pUseNum)
    {
        //printf("Full Do something\n");
    }
    else
    {
        // List Insert.
        P_LISTNODE_T pInsertNode = malloc(sizeof(LISTNODE_T));
        pInsertNode->val = val;
        pInsertNode->next = obj->pHead;
        obj->pHead = pInsertNode;
        // Min Priority Insert.
        int pos = insertInMinPriority(obj, pInsertNode);
        pInsertNode->pos = pos;
        //printf("position: %d\n", pInsertNode->pos);
        (*pUseNum)++;

    }
}

int minStackGetMin(MinStack* obj)
{
    int ret = (obj->pArray[0])->val;
    return ret;
}

int minStackTop(MinStack* obj)
{
    int ret = (obj->pHead)->val;

    return ret;
}


// Output is top element the position
static int DeleteInMinPriority(MinStack* pMinStack, int pos)
{
    //This function guarantee size not full.

    int *pUseNum = &(pMinStack->useNum);
    (*pUseNum)--;
    if (*pUseNum == 0) return -1;
    //printf("now:%2d\n", *pUseNum);
    pMinStack->pArray[pos] = pMinStack->pArray[*pUseNum];
    int selfIdx   = pos;
    int parentIdx = (selfIdx == 0) ? (selfIdx) : ((selfIdx-1) >> 1);
    int childIdx = (*pUseNum) - 1;
    P_LISTNODE_T pSelfList  = pMinStack->pArray[selfIdx];
    P_LISTNODE_T pParList   = pMinStack->pArray[parentIdx];
    P_LISTNODE_T pChildList;

    if ((pSelfList-> val < pParList->val) && (selfIdx != 0))
    {
        // Compare parent
        // ^
        // |
        do
        {
            P_LISTNODE_T pTemp = pSelfList;
            pMinStack->pArray[selfIdx]  = pParList;
            pParList->pos = selfIdx;
            pMinStack->pArray[parentIdx] = pTemp;
            selfIdx  = parentIdx;
            parentIdx = (selfIdx == 0) ? (selfIdx) : ((selfIdx-1) >> 1);
            pSelfList = pMinStack->pArray[selfIdx];
            pParList   = pMinStack->pArray[parentIdx];
        } while((pSelfList-> val < pParList->val) && (selfIdx != 0));

        return selfIdx;
    }
    else if (((selfIdx << 1) + 1) <= (*pUseNum))
    {
        //Compare with child.
        //  |
        // \ /
        //  .
        do
        {
            childIdx = (selfIdx << 1) + 1;

            if ((childIdx != (*pUseNum)) && (pMinStack->pArray[childIdx]->val > pMinStack->pArray[childIdx+1]->val))
                childIdx++;

            pChildList = pMinStack->pArray[childIdx];
            if (pSelfList->val < pChildList->val)
                return selfIdx;
            else
            {
                P_LISTNODE_T pTemp = pChildList;
                pChildList->pos = selfIdx;
                pMinStack->pArray[childIdx]  = pSelfList;
                pMinStack->pArray[selfIdx] = pTemp;
                selfIdx = childIdx;
                pSelfList = pMinStack->pArray[selfIdx];
            }


        } while(((selfIdx << 1) + 1) <= (*pUseNum));
    }
    else
    {
        //printf("others\n");
    }

    return childIdx;
}

void minStackPop(MinStack* obj)
{
    NUM_T* pUseNum  = &(obj->useNum);

    if (0 == *pUseNum)
    {
        //printf("It's empty\n");
    }
    else
    {
        // Record Stack top Pointer and Delete in stack.
        P_LISTNODE_T pPopNode = (obj->pHead);
        (obj->pHead) = (obj->pHead)->next;
        // Remove in MinPriority.
        //printf("Remove : %2d\n", pPopNode->pos);
        int pos = DeleteInMinPriority(obj, pPopNode->pos);
        //printf("Pos : %2d\n", pos);
        if (pos != -1) (obj->pArray[(*pUseNum)-1])->pos = pos;
        free(pPopNode);

    }

}

void minStackFree(MinStack* obj)
{
    free(obj->pArray);
    while (NULL != obj->pHead)
    {
        P_LISTNODE_T pReleaseNode = (obj->pHead);
        (obj->pHead) = (obj->pHead)->next;
        free(pReleaseNode);
    }
    free(obj);
}
