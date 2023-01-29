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
P_BST_NODE_T FindElementInBST(P_BST_HEAD_T pHead, CUSTOM_ELEMENT_TYPE element)
{
    P_BST_NODE_T pNode = pHead;
    while (NULL != pNode)
    {
        if (pNode->val == element) break;// TODO : CUSTOM_ELEMENT_TYPE compare function
        else
        {
            pNode = (pNode->val > element) ? (pNode->left) : (pNode->right);
        }


    }

    return pNode;
}

static P_BST_NODE_T takeMaxParentInBST(P_BST_HEAD_T pHead)
{
    // if ouput is Null, then tree has only one node or is empty
    P_BST_NODE_T pNode = pHead;

    if ((NULL == pNode) || (NULL == (pNode->right))) return NULL;
    while (NULL != ((pNode->right)->right))
    {
        pNode = pNode->right;
    }

    return pNode;
}


P_BST_NODE_T TakeMaxInBST(P_BST_HEAD_T pHead)
{
    P_BST_NODE_T pNode = takeMaxParentInBST(pHead);

    if (NULL == pNode)
    {
        if (NULL != pHead) return pHead;
    }
    else
    {
        pNode = pNode->right;
    }

    return pNode;
}

static P_BST_NODE_T takeMinParentInBST(P_BST_HEAD_T pHead)
{
    // if ouput is Null, then tree has only one node or is empty
    P_BST_NODE_T pNode = pHead;

    if ((NULL == pNode) || (NULL == (pNode->left))) return NULL;
    while (NULL != ((pNode->left)->left))
    {
        pNode = pNode->left;
    }

    return pNode;

}

P_BST_NODE_T TakeMinInBST(P_BST_HEAD_T pHead)
{
    P_BST_NODE_T pNode = takeMinParentInBST(pHead);

    if (NULL == pNode)
    {
        if (NULL != pHead) return pHead;
    }
    else
    {
        pNode = pNode->left;
    }

    return pNode;
}


// the important is insert always in leaf if element not exist in BST
P_BST_HEAD_T InsertElementInBST(P_BST_HEAD_T pHead, CUSTOM_ELEMENT_TYPE element)
{
    // Implement method don't use recursive and didn't change find the funtion.
    P_BST_NODE_T pNode = pHead;
    P_BST_NODE_T pParNode = NULL;
    while (NULL != pNode)
    {
        if (pNode->val == element) return pHead; //This element has been exist in BST.
        else
        {
            pParNode = pNode;
            pNode = (pNode->val > element) ? (pNode->left) : (pNode->right);
        }
    }

    pNode = (P_BST_NODE_T) malloc(sizeof(BST_NODE_T));
    pNode->val = element;
    pNode->right = NULL;
    pNode->left  = NULL;
    if (NULL != pHead)
    {
        if (pParNode->val > element)
            pParNode->left  = pNode;
        else
            pParNode->right = pNode;

    }
    else
    {
        pHead = pNode;
    }


    return pHead;
}

// Delete element may be occur in leaf(easy) and branch(complex)
P_BST_HEAD_T DeleteElementInBST(P_BST_HEAD_T pHead, CUSTOM_ELEMENT_TYPE element)
{
    // Implement method don't use recursive and didn't change find the funtion.
    P_BST_NODE_T pNode = pHead;
    P_BST_NODE_T pParNode = NULL;
    while (NULL != pNode)
    {
        if (pNode->val == element) break; //This element has been exist in BST.
        else
        {
            pParNode = pNode;
            pNode = (pNode->val > element) ? (pNode->left) : (pNode->right);
        }
    }

    // this element eixst in BST
    if ((NULL != pHead) && (NULL != pNode))
    {
        //case 1 : the element in leaf
        if ((NULL == (pNode->left)) && (NULL == (pNode->right)))
        {
            if ((pParNode->val) > element)
                (pParNode->left)  = NULL;
            else
                (pParNode->right) = NULL;
        }
        else
        {

            // case 2 : this element only have one subtree.
            if ((NULL != (pNode->right)) ^ (NULL != (pNode->left)))
            {

                // Two People
                
            }
            // TODO : Can decide the subtree length by left and right , let the subtree is blance
            //
            // case 3 : Choice right subtree and find the min
            // step1 :  find the parent of min, and put left subtree of min to parent's left pointer.
            // step2 :  Repleace D with Min and Reconect right and left subtree of D with Min and farther of D connect to Min
            //          
            //          P.D                 P.D
            //           |                   |
            //           D                  Min
            //         /   \               /   \
            //        1     5             1     5
            //            /   \               /   \
            //          P.Min      ==>      P.Min
            //          /   \               /   \
            //         Min   2             3     2
            //           \  /   \              /   \
            //            3
            else if (NULL != pNode->right)
            {
                //step 1
                P_BST_NODE_T pMinParentInSubBST = takeMinParentInBST(pNode->right);
                P_BST_NODE_T pMinInSubBST = NULL;
                // Case 3.1 if the min is subtree head. don't put the sun to grapa
                if (NULL != pMinParentInSubBST)
                {
                    P_BST_NODE_T pMinInSubBST = pMinParentInSubBST->left;
                    pMinParentInSubBST->left = pMinInSubBST->right;
                    pMinInSubBST->right = NULL;
                }
                else pMinInSubBST = pNode->right;


                //step2
                pMinInSubBST->right = pNode->right;
                pMinInSubBST->left  = pNode->left;
                
                if ((pParNode->val) > element)
                    (pParNode->left)  = pMinInSubBST;
                else
                    (pParNode->right) = pMinInSubBST;

                pNode->right = NULL;
                pNode->left  = NULL;

            }

        }

        //free the element
            free(pNode);

    }


    return pHead;
}
//Determine IsBSTTree
