#include "tree_application.h"

//--------------------- Here is Practce LeetCode ----------------------------------------

// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree 
// and inorder is the inorder traversal of the same tree, construct and return the binary tree.
//

// 106. Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree 
// and postorder is the postorder traversal of the same tree, construct and return the binary tree.


//static int findSameElement(CUSTOM_ELEMENT_TYPE src, CUSTOM_ELEMENT_TYPE * I
static BINTREE_HEAD recuresivePreAndInorder(CUSTOM_ELEMENT_TYPE* pPreOrderAddr, CUSTOM_ELEMENT_TYPE* pInOrderAddr, int num)
{
    BINTREE_HEAD pSubTreeHead;
    if (0 == num)
    {
        pSubTreeHead = NULL;
    }
    else
    {
        pSubTreeHead = malloc(sizeof(BINTREE_HEAD));
        pSubTreeHead->val = *pPreOrderAddr;
        pSubTreeHead->right = NULL;
        pSubTreeHead->left  = NULL;


        //findSameElement
        int idx = 0;
        for(idx = 0; idx < num; idx++)
        {
            if (*pPreOrderAddr == *(pInOrderAddr + idx)) break;
        }

        BINTREE_HEAD pSubLeftTree  = recuresivePreAndInorder((pPreOrderAddr + 1), pInOrderAddr, idx);
        BINTREE_HEAD pSubRightTree = recuresivePreAndInorder((pPreOrderAddr + (1 + idx)), (pInOrderAddr + (1 + idx)), num - 1 - idx);


        pSubTreeHead->left  = pSubLeftTree;
        pSubTreeHead->right = pSubRightTree;


    }


    return pSubTreeHead;



}


BINTREE_HEAD CreateTree(P_TRAVSAL_T orderSeq, P_TRAVSAL_T inorderSeq)
{

    if (PRE_ORDER == orderSeq->travlMode)
    {
        recuresivePreAndInorder(orderSeq->elementArray, inorderSeq->elementArray, orderSeq->length);
    }


}

//--------------------- Here is Practce LeetCode End ------------------------------------
