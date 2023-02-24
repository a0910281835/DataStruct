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
            // Only to do is grapa become father.
            // the reason is the Delete element in subtree is Max or Min
            // XXX : Max and Min Delete in tree is easy, you can write function to do this
            if ((NULL != (pNode->right)) ^ (NULL != (pNode->left)))
            {
                printf("this element has only subtree");
                P_BST_NODE_T pGrandSonNode = (NULL != pNode->left) ? pNode->left : pNode->right;
                if ((pParNode->val) > element)
                    (pParNode->left)  = pGrandSonNode;
                else
                    (pParNode->right) = pGrandSonNode;

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
                    pMinInSubBST = pMinParentInSubBST->left;
                    pMinParentInSubBST->left = pMinInSubBST->right;
                    pMinInSubBST->right = NULL;
                }
                else pMinInSubBST = pNode->right;

                printf("Show the value, you find %2d\n", pNode->val);
                printf("Show the min value, you find %2d\n", pMinInSubBST->val);

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


// the quiz pratice my recursive method
//Input:
//pHead    : Current Tree's Head Node
//element  : Delete Element
//OutPut
//          : After Delete, Reback Tree's Head Node
P_BST_HEAD_T DeleteElementInBSTByRecursive(P_BST_HEAD_T pHead, CUSTOM_ELEMENT_TYPE element)
{
    // Inital Condition : This funtion directly find the delete val , so if it in here that means this value not exist.
    if (NULL == pHead)
    {
        printf("this value : %2d not exist\n", element);
    }
    else
    {
        if (element < pHead->val)
        {
            pHead->left = DeleteElementInBSTByRecursive(pHead->left, element);
        }
        else if (pHead->val < element)
        {
            pHead->right = DeleteElementInBSTByRecursive(pHead->right, element);
        }
        else // pHead == val
        {

            P_BST_NODE_T pNode = NULL;
            if ((NULL == pHead->left) && (NULL == pHead->right))
            {
                //the delete element in leaf
                //Do nothing
                free(pHead);
                pHead = NULL;

            }
            else if ((NULL != pHead->left) ^ (NULL != pHead->right))
            {
                pNode = (NULL != (pHead->left)) ? (pHead->left) : (pHead->right);
                pHead->left  = NULL;
                pHead->right = NULL;
                free(pHead);
                pHead = pNode;
            }
            else // left and right are non-empty subtree.
            {
                // The Best method is to check subtree length
                // Here take left subtree max val

                pNode = TakeMaxInBST(pHead->left);
                //FIXME : assign a space to do Memecpy is not need
                //P_BST_NODE_T pCpyNode = (P_BST_NODE_T) malloc(sizeof(BST_NODE_T));
                //pCpyNode->val   = pNode->val;
                //pCpyNode->left  = NULL;
                //pCpyNode->right = NULL;

                pHead->val = pNode->val;
                pHead->left = DeleteElementInBSTByRecursive(pHead->left, pNode->val);

                //This time pNode if be free.
                pNode = NULL;

            }

        }

    }

    return pHead;


}
//98. Validate Binary Search Tree
//Given the root of a binary tree, determine if it is a valid binary search tree (BST).
//
//A valid BST is defined as follows:
//
//The left
//subtree
// of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.



DECIDE_T IsBSTTreeByRecursive(P_BST_HEAD_T pHead)
{

    //Inital Condtion
    if (NULL == pHead) return YES;



    DECIDE_T decide = IsBSTTreeByRecursive(pHead->left);
    P_BST_NODE_T leftSubTreeMax = TakeMaxInBST(pHead->left);
    CUSTOM_ELEMENT_TYPE compareVal;

    if (NULL != leftSubTreeMax)
    {
        compareVal = leftSubTreeMax->val;

        if (compareVal <= pHead->val)
        {
            decide &= YES;
        }
        else
        {
            decide &= NO;
            //printf("not satisy by this value leftsubNode:%2d Node:%2d\n", compareVal, pHead->val);
        }

    }

    decide &= IsBSTTreeByRecursive(pHead->right);
    P_BST_NODE_T rightSubTreeMax = TakeMinInBST(pHead->right);

    if (NULL != rightSubTreeMax)
    {
        compareVal = rightSubTreeMax->val;

        if (pHead->val <= compareVal)
        {
            decide &= YES;
        }
        else
        {
            decide &= NO;
            //printf("not satisy by this value Node:%2d rightNode:%2d\n", pHead->val, compareVal);
        }

    }

    return decide;

}
DECIDE_T IsBSTTree(P_BST_HEAD_T pHead)
{
    DECIDE_T decide = YES;

    CUSTOM_ARRAY_T* output =  InOrderAndOuputArray(pHead);

    // TODO : Construct Struct Order function
    // Check Is this OrderSequecne. Beacuse BST Breadth order is order sequence
    int idx = 0;

    if (output->current_num > 1)
    {
        CUSTOM_ELEMENT_TYPE lastVal = output->array[0];

        for (idx = 1; idx < (output->current_num); idx++)
        {
            if (lastVal <= (output->array[idx]))
            {
                lastVal = (output->array[idx]);
            }
            else
            {
                decide = NO;
                return decide;
            }

        }

    }

    return decide;
}


// 96. Unique Binary Search Trees
// Descript : Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
// Example 1 : Input: n = 3 , Output: 5


int numTrees(int n)
{
    //Solution : 1 | 2 | 3 ..... | n
    // Head is  1 => the right subtree is order 2, ... , n and left subtree is zero. and how do I calulate by  BST(n-1) * BST(0);
    //Dynamic Progaming
    int* storageBST = malloc(sizeof(int) * (n + 1));
    //Inital Condiotn
    storageBST[0] = storageBST[1] = 1;

    int bstTotal = 2;

    for (bstTotal = 2; bstTotal <= n; bstTotal++)
    {
        int recordThisVal = 0;

        int headIdx;
        for (headIdx = 1; headIdx <= bstTotal; headIdx++)
        {
            // Num
            //     headIdx - 1  | headIdx | (bstTotal - headIdx)

            recordThisVal += (storageBST[headIdx-1] * storageBST[bstTotal-headIdx]);
        }

        storageBST[bstTotal] = recordThisVal;
    }


    int lastVal = storageBST[n];
    free(storageBST);



    return lastVal;
}

int numTreesByRecursive(int n)
{
    //Inital Condtion
    if ((0 == n) || (1 == n))
    {
        return 1;
    }
    else
    {
        //headIdx
        // 1 | 2 | 3 | ...... | n
        int headIdx;
        int recordThisVal = 0;

        for (headIdx = 1; headIdx <= n; headIdx++)
        {
            recordThisVal += (numTreesByRecursive(headIdx-1) * numTreesByRecursive(n-headIdx));
        }

        return recordThisVal;
    }

}


// 95. Unique Binary Search Trees II
// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
// Example 1 :
// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
//
// Example 2 :
// Input: n = 1
// Output: [[1]]
//
//Constraints:
//
//1 <= n <= 8
/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     struct TreeNode *left;
 *      *     struct TreeNode *right;
 *       * };
 *        */
/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *
 *   */

#define MAX_HEAD_NUM 1500
P_TREE_NODE_T travalTreeAndAddNum(int num, P_TREE_NODE_T treeHead)
{
    //Inital Condition
    if (NULL != treeHead)
    {
        P_TREE_NODE_T leftSubTree  = treeHead->left;
        P_TREE_NODE_T rightSubTree = treeHead->right;
        leftSubTree  = travalTreeAndAddNum(num, leftSubTree);
        rightSubTree = travalTreeAndAddNum(num, rightSubTree);
        treeHead->val += num;
        treeHead->left  = leftSubTree;
        treeHead->right = rightSubTree;
    }
    return treeHead;
}


// It's Difficult Consider this conditon : list has common
void TravalTreeAddNum(int number, P_HEAD_COLLECT_T collect, int treeNum)
{

    int idx = 0;

    for (idx = 0; idx < treeNum; idx++)
    {
        travalTreeAndAddNum(number, collect[idx]);
    }


}


P_TREE_NODE_T CopyTree(P_TREE_NODE_T beCopyTree)
{
    P_TREE_NODE_T pHead = NULL;
    //Inital Codition
    if (NULL != beCopyTree)
    {
        pHead = malloc(sizeof(TREE_NODE_T));
        pHead->val = beCopyTree->val;
        pHead->left  = CopyTree(beCopyTree->left);
        pHead->right = CopyTree(beCopyTree->right);

    }

    return pHead;
}


void DeleteTree(P_TREE_NODE_T tree)
{
    //Inital Condition
    if (NULL !=  tree)
    {
        DeleteTree(tree->left);
        DeleteTree(tree->right);
        free(tree);
    }
}


void DeleteTreeSet(P_HEAD_COLLECT_T treeSet, int numTree)
{
    int idx = 0;
    for (idx = 0; idx < numTree; idx++)
    {
        DeleteTree(treeSet[idx]);
        treeSet[idx] = NULL;
    }
}

static P_HEAD_COLLECT_T generateTreesByRecursive(int n, int* returnSize)
{
    P_HEAD_COLLECT_T pHeadColl = malloc(sizeof(P_TREE_NODE_T));
    //Intial Condition
    if ((n == 1) || (n == 0))
    {
        *returnSize = 1;
        P_TREE_NODE_T pHead = NULL;
        if (n == 1)
        {
            pHead = malloc(sizeof(TREE_NODE_T));
            pHead->val   = 1;
            pHead->left  = NULL;
            pHead->right = NULL;
        }

        pHeadColl[0] = (pHead);

    }
    else
    {
        int headIdx = 1;
        int last_num = 0;  //  Recording Number of Tree
        int current_val = 1;// Recording Collect Capacity, Remark : this is not Num of tree
        int idx1 = 0;
        int idx2 = 0;
        int headIdxAsHeadNum;

        for (headIdx = 1; headIdx <= n; headIdx++)
        {
            P_HEAD_COLLECT_T leftHead = generateTreesByRecursive(headIdx-1, returnSize);
            int leftTreeNum = *returnSize;
            P_HEAD_COLLECT_T rightHead = generateTreesByRecursive(n-headIdx, returnSize);
            int rightTreeNum = *returnSize;
            //TravalTreeAddNum(headIdx, rightHead, rightTreeNum);
            headIdxAsHeadNum = leftTreeNum * rightTreeNum;
            P_HEAD_COLLECT_T headIdxHead = malloc(sizeof(P_TREE_NODE_T) * headIdxAsHeadNum);


            // Connect All tree with left and right subtree for head  HeadIdx
            for (idx1 = 0; idx1 < leftTreeNum; idx1++)
            {
                for (idx2 = 0; idx2 < rightTreeNum; idx2++)
                {
                    int sumIdx = idx1 + idx2;
                    //printf("sumIdx : %2d = %2d + %2d \n", sumIdx, idx1, idx2);
                    headIdxHead[sumIdx] = malloc(sizeof(TREE_NODE_T));
                    (headIdxHead[sumIdx])->val = headIdx;
                    // Copy left Term
                    P_TREE_NODE_T leftSubTree = CopyTree(leftHead[idx1]);
                    // Copy right Term
                    P_TREE_NODE_T rightSubTree = CopyTree(rightHead[idx2]);
                    rightSubTree = travalTreeAndAddNum(headIdx, rightSubTree);
                    (headIdxHead[sumIdx])->left  = leftSubTree;
                    (headIdxHead[sumIdx])->right = rightSubTree;
                }
            }


            //Delete Those No Need
            DeleteTreeSet(leftHead,  leftTreeNum);
            leftHead = NULL;
            DeleteTreeSet(rightHead, rightTreeNum);
            rightHead = NULL;



            // Extend Array
            int cpyIdx = 0;

            printf(" n = %2d current_val :%2d last_num: %2d headIdxAsHeadNum :%2d\n", n ,current_val, last_num, headIdxAsHeadNum);
            if (current_val <= (last_num + headIdxAsHeadNum))
            {

                P_HEAD_COLLECT_T extendPointer = malloc(sizeof(P_TREE_NODE_T) * ((last_num + headIdxAsHeadNum) << 1));

                //Copy OLD term. XXX : Copy is Copy Structure, then space is continuous.
                for (cpyIdx = 0; cpyIdx < last_num; cpyIdx++)
                {
                    extendPointer[cpyIdx] = CopyTree(pHeadColl[cpyIdx]);
                }

                DeleteTreeSet(pHeadColl, current_val);
                pHeadColl = extendPointer;
                current_val = ((last_num + headIdxAsHeadNum) << 1);

            }

            //Copy New term.
            for (cpyIdx = 0; cpyIdx < headIdxAsHeadNum; cpyIdx++)
            {
                pHeadColl[cpyIdx + last_num] = headIdxHead[cpyIdx];
            }

            //if (n == 3)
            //{
            //    printf("headIdx : %2d\n", headIdx);
            //    printf("current_val :%2d last_num: %2d headIdxAsHeadNum :%2d\n", current_val, last_num, headIdxAsHeadNum);
            //    if (headIdx == 1)
            //    {
            //        for (idx1 = 0; idx1 < last_num + headIdxAsHeadNum;  idx1++)
            //        {
            //            printf("---------\n");
            //            TravelBinTree((BINTREE_HEAD)pHeadColl[idx1], BREADTH_ORDER);
            //            printf("---------\n");
            //        }

            //    }

            //}
            last_num += headIdxAsHeadNum;

        }

        *returnSize = last_num;
    }

    return pHeadColl;
}


struct TreeNode** generateTrees(int n, int* returnSize)
{
    P_HEAD_COLLECT_T nTreeHead = generateTreesByRecursive(n, returnSize);
    return nTreeHead;
}




