#include "tree_application.h"

//--------------------- Here is Practce LeetCode ----------------------------------------

// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree
// and inorder is the inorder traversal of the same tree, construct and return the binary tree.
//

// 106. Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree
// and postorder is the postorder traversal of the same tree, construct and return the binary tree.


//static int findSameElement(CUSTOM_ELEMENT_TYPE src, CUSTOM_ELEMENT_TYPE * I
static BINTREE_HEAD recuresiveXXAndInorder(CUSTOM_ELEMENT_TYPE* pXOrderAddr, CUSTOM_ELEMENT_TYPE* pInOrderAddr, int num, TRAVERSAL_MODE mode)
{
    BINTREE_HEAD pSubTreeHead;
    if (0 == num)
    {
        pSubTreeHead = NULL;
    }
    else
    {

        pSubTreeHead = malloc(sizeof(BINTREE_HEAD));
        pSubTreeHead->val = (PRE_ORDER == mode) ? (*pXOrderAddr) : (*(pXOrderAddr + (num - 1)));
        pSubTreeHead->right = NULL;
        pSubTreeHead->left  = NULL;


        //findSameElement
        int idx = 0;
        for(idx = 0; idx < num; idx++)
        {
            if (pSubTreeHead->val == *(pInOrderAddr + idx)) break;
        }

        // Pre   [ 1 | n | m ]
        // In    [ n | 1 | m ]
        // Post  [ n | m | 1 ] 

        int xleftSubtreeIdx, xrightSubtreeIdx;

        xleftSubtreeIdx  = (PRE_ORDER == mode) ? 1 : 0;
        xrightSubtreeIdx = (PRE_ORDER == mode) ? (idx + 1) : 0;


        BINTREE_HEAD pSubLeftTree  = recuresiveXXAndInorder((pXOrderAddr + xleftSubtreeIdx), pInOrderAddr, idx, mode);
        BINTREE_HEAD pSubRightTree = recuresiveXXAndInorder((pXOrderAddr + xrightSubtreeIdx), (pInOrderAddr + (1 + idx)), num - 1 - idx, mode);


        pSubTreeHead->left  = pSubLeftTree;
        pSubTreeHead->right = pSubRightTree;


    }


    return pSubTreeHead;



}


BINTREE_HEAD CreateTree(P_TRAVSAL_T orderSeq, P_TRAVSAL_T inorderSeq)
{

    BINTREE_HEAD pHead = recuresiveXXAndInorder(orderSeq->elementArray, inorderSeq->elementArray, orderSeq->length, orderSeq->travlMode);
    return pHead;
}

//--------------------- Here is Practce LeetCode End ------------------------------------




//--------Binary Search Tree 
