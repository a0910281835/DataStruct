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






#endif

