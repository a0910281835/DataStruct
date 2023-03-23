#ifndef _H_TREE_APPLICATION
#define _H_TREE_APPLICATION
#include "tree.h"

// this strct be created to applied for leetcode problem 105 and 106.
typedef struct TRAVSAL_T * P_TRAVSAL_T;
typedef struct TRAVSAL_T
{
    CUSTOM_ELEMENT_TYPE * elementArray;
    NUM_T length;
    TRAVERSAL_MODE travlMode;
}TRAVSAL_T;

extern BINTREE_HEAD CreateTree(P_TRAVSAL_T orderSeq, P_TRAVSAL_T inorderSeq);


typedef enum
{
    MIN_EVENT = 0,
    MAX_EVENT = 1,
}EXTREMUM_EVENT_T;


// BST struct and function
typedef struct BINNODE_T BST_NODE_T;
typedef struct BINNODE_T *P_BST_HEAD_T;
typedef struct BINNODE_T *P_BST_NODE_T;

//BST fundmetal function
extern P_BST_NODE_T FindElementInBST(P_BST_HEAD_T pHead, CUSTOM_ELEMENT_TYPE element);
extern P_BST_NODE_T TakeMaxInBST(P_BST_HEAD_T pHead);
extern P_BST_NODE_T TakeMinInBST(P_BST_HEAD_T pHead);
extern P_BST_HEAD_T InsertElementInBST(P_BST_HEAD_T pHead, CUSTOM_ELEMENT_TYPE element);
extern P_BST_HEAD_T DeleteElementInBST(P_BST_HEAD_T pHead, CUSTOM_ELEMENT_TYPE element);
extern P_BST_HEAD_T DeleteElementInBSTByRecursive(P_BST_HEAD_T pHead, CUSTOM_ELEMENT_TYPE element);

//BST Special funtion
//Leetcode 98
extern DECIDE_T IsBSTTree(P_BST_HEAD_T pHead);
extern DECIDE_T IsBSTTreeByRecursive(P_BST_HEAD_T pHead);
//LeetCode 96
extern int numTrees(int n);
extern int numTreesByRecursive(int n);

typedef struct TreeNode    TREE_NODE_T;
typedef struct TreeNode*   P_TREE_NODE_T;
typedef struct TreeNode*   P_TREE_HEAD_T;
typedef struct TreeNode**  P_HEAD_COLLECT_T;

extern P_TREE_NODE_T DeleteTree(P_TREE_NODE_T tree);
extern P_TREE_NODE_T CopyTree(P_TREE_NODE_T beCopyTree);
extern P_TREE_NODE_T travalTreeAndAddNum(int num, P_TREE_NODE_T treeHead);
extern P_TREE_NODE_T CopyTree(P_TREE_NODE_T beCopyTree);
typedef struct TreeNode
{
    int val;
    P_TREE_NODE_T left;
    P_TREE_NODE_T right;
}TreeNode;


typedef enum
{
    FALSE = 0,
    TRUE  = 1,
}bool;
extern struct TreeNode** generateTrees(int n, int* returnSize);

// AVL Tree
// Calulate the min size of Blance BST

//leetcode 99
extern void RecoverTree(P_TREE_NODE_T pRoot);
extern void FixOrderSeqence(int *array, int num);
extern bool isSymmetric(struct TreeNode* root);

// leetcode 101
// tree FIFO use two way link list.
typedef struct TWO_WAY_LINK_NODE_T* P_TWO_WAY_LINK_NODE_T;
typedef struct TWO_WAY_LINK_NODE_T
{
    P_TREE_NODE_T  pNode;
    P_TWO_WAY_LINK_NODE_T pNext;
    P_TWO_WAY_LINK_NODE_T pPrevious;
    
}TWO_WAY_LINK_NODE_T;

typedef struct FIFO_TREE_NODE_T * P_FIFO_TREE_NODE_T;
typedef struct FIFO_TREE_NODE_T
{
    P_TWO_WAY_LINK_NODE_T pInput;
    P_TWO_WAY_LINK_NODE_T pOutput;
}FIFO_TREE_NODE_T;

extern P_FIFO_TREE_NODE_T CreateFifo(void);
extern DECIDE_T IsEmptyFIFOTree(P_FIFO_TREE_NODE_T pFifo);
extern void PushFIFOTree(P_FIFO_TREE_NODE_T pFifo, P_TREE_NODE_T pNode);
extern P_TREE_NODE_T PopFIFOTree(P_FIFO_TREE_NODE_T pFifo);
extern int FifoSize(P_FIFO_TREE_NODE_T pFifo);
extern int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);





#endif

