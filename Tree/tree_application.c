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


P_TREE_NODE_T DeleteTree(P_TREE_NODE_T tree)
{
    //Inital Condition
    if (NULL != tree)
    {
        tree->left  = DeleteTree(tree->left);
        tree->right = DeleteTree(tree->right);
        free(tree);
        tree = NULL;
    }
    return tree;
}


P_HEAD_COLLECT_T DeleteTreeSet(P_HEAD_COLLECT_T treeSet, int numTree)
{
    int idx = 0;
    for (idx = 0; idx < numTree; idx++)
    {
        treeSet[idx] = DeleteTree(treeSet[idx]);
    }

    return treeSet;
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
                    leftSubTree  = NULL;
                    rightSubTree = NULL;
                }
            }


            //Delete Those No Need
            //leftHead  = DeleteTreeSet(leftHead,  leftTreeNum);
            //free(leftHead);
            //rightHead = DeleteTreeSet(rightHead, rightTreeNum);
            //free(rightHead);

            //for (idx1 = 0; idx1 < leftTreeNum; idx1++)
            //{
            //    //leftHead[idx1] = DeleteTree(leftHead[idx1]);
            //    //leftHead[idx1] = NULL;
            //    free(leftHead[idx1]);
            //}
            //free(leftHead);
            //for (idx1 = 0; idx1 < rightTreeNum; idx1++)
            //{
            //    //leftHead[idx1] = DeleteTree(leftHead[idx1]);
            //    //leftHead[idx1] = NULL;
            //    free(rightHead[idx1]);
            //}
            //free(rightHead);



            // Extend Array
            int cpyIdx = 0;

            if (current_val <= (last_num + headIdxAsHeadNum))
            {
                //printf(" n = %2d current_val :%2d last_num: %2d headIdxAsHeadNum :%2d, headIdx : %2d\n", n ,current_val, last_num, headIdxAsHeadNum, headIdx);

                P_HEAD_COLLECT_T extendPointer = malloc(sizeof(P_TREE_NODE_T) * ((last_num + headIdxAsHeadNum) << 1));

                //Copy OLD term. XXX : Copy is Copy Structure, then space is continuous.
                for (cpyIdx = 0; cpyIdx < last_num; cpyIdx++)
                {
                    extendPointer[cpyIdx] = (pHeadColl[cpyIdx]);
                }

                for (cpyIdx = 0; cpyIdx < current_val; cpyIdx++)
                {
                    pHeadColl[cpyIdx] = NULL;
                }

                free(pHeadColl);
                pHeadColl = extendPointer;
                current_val = ((last_num + headIdxAsHeadNum) << 1);

            }

            //Copy New term.
            for (cpyIdx = 0; cpyIdx < headIdxAsHeadNum; cpyIdx++)
            {
                pHeadColl[cpyIdx + last_num] = headIdxHead[cpyIdx];
                headIdxHead[cpyIdx] = NULL;
            }

            //Cpy end and free
            free(headIdxHead);

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

    //printf("--------------\n");
    //printf("n = %2d\n", n);
    //printf("size = %2d\n", *returnSize);

    //int idx = 0;
    //for (idx = 0; idx < *returnSize; idx++)
    //{
    //    if (pHeadColl[idx] == NULL)
    //    {
    //        printf("NULL\n");
    //    }
    //    else
    //    {
    //        TravelBinTree((BINTREE_HEAD)pHeadColl[idx], BREADTH_ORDER);
    //        printf("\n");

    //    }
    //}


    return pHeadColl;
}


struct TreeNode** generateTrees(int n, int* returnSize)
{
    P_HEAD_COLLECT_T nTreeHead = generateTreesByRecursive(n, returnSize);
    return nTreeHead;
}


//99. Recover Binary Search Tree
//You are given the root of a binary search tree (BST),
//where the values of exactly two nodes of the tree were swapped by mistake.
//Recover the tree without changing its structure.

/*
 *  graph like this
 *      1         3
 *     /         /
 *    3         1
 *     \         \ .
 *      2         2
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
*/

//
//    3            2
//   / \    =>    / \ .
//  1   4        1   4
//     /            /
//    2            3


/*
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
*/



P_TREE_NODE_T* recoverTreeByRecursive(P_TREE_NODE_T pHead)
{
    static int errorIdx = 0;
    static P_TREE_NODE_T pErrorNode[2] = {NULL, NULL};
    static P_TREE_NODE_T pLastNode= NULL;

    // Inital Codition
    if (NULL != pHead)
    {
        recoverTreeByRecursive(pHead->left);

        // Do Somthing for This Node.
        if (NULL == pLastNode)
        {
            pLastNode = pHead;
        }
        else
        {
            if ((pLastNode->val > pHead->val) && (errorIdx <= 1))
            {
                pErrorNode[errorIdx] = (errorIdx == 0) ? (pLastNode) : (pHead);
                if (errorIdx == 0) pErrorNode[errorIdx + 1] = pHead;
                errorIdx++;

            }

            pLastNode = pHead;

        }

        recoverTreeByRecursive(pHead->right);
    }


    int idx = 0;
    //for (idx = 0; idx < 2; idx++)
    //{
    //    if (pErrorNode[idx] == NULL)
    //    {
    //        printf(" NULL, ");
    //    }
    //    else
    //    {
    //        printf("%2d, ", (pErrorNode[idx])->val);
    //    }
    //}
    //printf("\n");

    return pErrorNode;
}




void RecoverTree(P_TREE_NODE_T pRoot)
{
    P_TREE_NODE_T* pErrorNodeArray = recoverTreeByRecursive(pRoot);
    int temp;

    temp = pErrorNodeArray[0]->val;
    pErrorNodeArray[0]->val = pErrorNodeArray[1]->val;
    pErrorNodeArray[1]->val = temp;

}


// there are two error pattern.
void FixOrderSeqence(int *array, int num)
{
    int idx = 0;
    int errorArray[2];
    int errorIdx = 0;

    for (idx = 0; idx < num; idx++)
    {
        printf(" %3d ", array[idx]);
    }
    printf("\n");



    for (idx = 0; idx < num; idx++)
    {
        if (array[idx] > array[idx+1])
        {
            errorArray[errorIdx] = (errorIdx == 1) ? (idx + 1) : (idx);
            errorIdx++;
        }

    }

    int temp  = 0;

    temp = array[errorArray[0]];
    array[errorArray[0]] = array[errorArray[1]];
    array[errorArray[1]] = temp;


    for (idx = 0; idx < num; idx++)
    {
        printf(" %3d ", array[idx]);
    }
    printf("\n");

}



/*
 * 100. Same Tree
 * Easy
 * 9K
 * 181
 * Companies
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.
 *
 * Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 *
 *
 *
 *  Example 1:
 *  Input: p = [1,2,3], q = [1,2,3]
 *  Output: true
 *
 *  Example 2:
 *  Input: p = [1,2], q = [1,null,2]
 *  Output: false
 *
 *  Example 3:
 *
 *  Input: p = [1,2,1], q = [1,1,2]
 *  Output: false
 *
 *  Constraints:
 *
 *  The number of nodes in both trees is in the range [0, 100].
 *  -104 <= Node.val <= 104
 *
 *  */

static bool isSameTreeByRecursive(P_TREE_NODE_T firstTree, P_TREE_NODE_T secondTree)
{
    bool ret;
    // Inital Condition
    if ((NULL != firstTree) && (NULL != secondTree))
    {
        if (firstTree->val == secondTree->val)
        {
            ret = (isSameTreeByRecursive(firstTree->left, secondTree->left)) & (isSameTreeByRecursive(firstTree->right, secondTree->right));
            return ret;
        }
        else
        {
            return 0;
        }

    }
    else if ((NULL == firstTree) && (NULL == secondTree))
    {
        return 1;
    }
    else
    {
        return 0;
    }


}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    bool ret = isSameTreeByRecursive(p, q);

    return ret;

}


//101. Symmetric Tree
//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
//Example 1:
//Input: root = [1,2,2,3,4,4,3]
//Output: true
//Example 2:
//Input: root = [1,2,2,null,3,null,3]
//Output: false
//Constraints:
//
//The number of nodes in the tree is in the range [1, 1000].
//-100 <= Node.val <= 100
//
//
static bool isSymTreeByRecursive(P_TREE_NODE_T firstTree, P_TREE_NODE_T secondTree)
{
    bool ret;
    // Inital Condition
    if ((NULL != firstTree) && (NULL != secondTree))
    {
        if (firstTree->val == secondTree->val)
        {
            ret = (isSymTreeByRecursive(firstTree->left, secondTree->right)) & (isSymTreeByRecursive(firstTree->right, secondTree->left));
            return ret;
        }
        else
        {
            return 0;
        }

    }
    else if ((NULL == firstTree) && (NULL == secondTree))
    {
        return 1;
    }
    else
    {
        return 0;
    }


}

bool isSymmetric(struct TreeNode* root)
{
    bool ret = 1;
    if (root != NULL) ret = isSymTreeByRecursive(root->left, root->right);
    return ret;

}


//
//102. Binary Tree Level Order Traversal
//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
//
// Example 1:Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
//
// Example 2:
// Input: root = [1]
// Output: [[1]]
//
// Example 3:
// Input: root = []
// Output: []
//
// Constraints:
//
// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000
//

// pFifo->pInput == pFifo->pOutput &&


P_FIFO_TREE_NODE_T CreateFifo(void)
{
    P_FIFO_TREE_NODE_T pFifo = malloc(sizeof(FIFO_TREE_NODE_T ));
    pFifo->pInput  = NULL;
    pFifo->pOutput = NULL;
    return pFifo;
}


DECIDE_T IsEmptyFIFOTree(P_FIFO_TREE_NODE_T pFifo)
{
    DECIDE_T ret = YES;
    if (NULL != pFifo->pInput) ret = NO;
    return ret;
}

void PushFIFOTree(P_FIFO_TREE_NODE_T pFifo, P_TREE_NODE_T pNode)
{
    if (NULL != pNode)
    {
        P_TWO_WAY_LINK_NODE_T pInsertNode = malloc(sizeof(TWO_WAY_LINK_NODE_T));
        pInsertNode->pNode    = pNode;
        pInsertNode->pPrevious = NULL;

        DECIDE_T ret = IsEmptyFIFOTree(pFifo);

        if (YES == ret)
        {
            //empty condition
            pFifo->pInput  = pInsertNode;
            pFifo->pOutput = pInsertNode;
            pInsertNode->pNext = NULL;
        }
        else
        {
            P_TWO_WAY_LINK_NODE_T pOldInput = pFifo->pInput;
            pOldInput->pPrevious = pInsertNode;// ---(1)
            pInsertNode->pNext = pOldInput;   // ----(2)
            pFifo->pInput = pInsertNode;      // ----(3)
        }


    }
}

P_TREE_NODE_T PopFIFOTree(P_FIFO_TREE_NODE_T pFifo)
{
    P_TREE_NODE_T pPopTreeNode = NULL;
    DECIDE_T ret = IsEmptyFIFOTree(pFifo);

    if (NO == ret)
    {
        pPopTreeNode = (pFifo->pOutput)->pNode;
        // Only element
        if ((pFifo->pInput) == (pFifo->pOutput))
        {
            free(pFifo->pOutput);
            pFifo->pInput  = NULL;
            pFifo->pOutput = NULL;
        }
        else
        {
            P_TWO_WAY_LINK_NODE_T pNextPopNode = (pFifo->pOutput)->pPrevious;
            pNextPopNode->pNext = NULL;
            free(pFifo->pOutput);
            pFifo->pOutput = pNextPopNode;

        }
    }
    else
    {
        printf("Error fifo is empty\n ");
    }

    return pPopTreeNode;
}

int FifoSize(P_FIFO_TREE_NODE_T pFifo)
{
    int size = 0;
    P_TWO_WAY_LINK_NODE_T pCell = pFifo->pInput;

    while (NULL != pCell)
    {
        size++;
        pCell = pCell->pNext;
    }

    return size;

}

/**
 *  * Return an array of arrays of size *returnSize.
 *   * The sizes of the arrays are returned as *returnColumnSizes array.
 *    * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 *     */

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{

    P_TREE_NODE_T pLayersLastNode = root;
    P_TREE_NODE_T pRecoderNode;
    int capacity = 1;//cap of collect and returnColumnSizes
    int thislayerSize = 1;
    int numLayers     = 0;
    int idxThisLyer   = 0;
    int** collect = malloc(sizeof(int*) * capacity);
    *returnColumnSizes = malloc(sizeof(int) * capacity);

    P_FIFO_TREE_NODE_T pFifo = CreateFifo();
    *returnSize = 0;
    (*returnColumnSizes)[0] = 0;
    if (NULL == root) return collect;
    collect[numLayers] = malloc(sizeof(int) * thislayerSize);
    (*returnColumnSizes)[0] = 1;

    PushFIFOTree(pFifo, root);
    P_TREE_NODE_T pPopNode = PopFIFOTree(pFifo);

    while (NULL != pPopNode)
    {
        collect[numLayers][idxThisLyer++] = pPopNode->val;
        //collect[0]
        PushFIFOTree(pFifo, pPopNode->left);
        if (NULL != pPopNode->left) pRecoderNode = pPopNode->left;
        PushFIFOTree(pFifo, pPopNode->right);
        if (NULL != pPopNode->right) pRecoderNode = pPopNode->right;

        if (pPopNode == pLayersLastNode)
        {
            numLayers++;

            if (numLayers == capacity) // need to extend collect, returnColumnSizes
            {

                // malloc
                int** tempCollect   = malloc(sizeof(int*) * (capacity << 1));
                int*  tempColumSize = malloc(sizeof(int)  * (capacity << 1));

                // copy pointer or data
                int idx = 0;
                for (idx = 0; idx < capacity; idx++)
                {
                    tempCollect[idx]   = collect[idx];//Copy pointer;
                    tempColumSize[idx] = (*returnColumnSizes)[idx];
                }

                //free old data
                free(collect);
                free(*returnColumnSizes);

                //Those pointer pointed New Space
                collect = tempCollect;
                *returnColumnSizes = tempColumSize;
                capacity <<= 1;

                tempCollect = NULL;
                tempColumSize = NULL;
            }

            pLayersLastNode = pRecoderNode;
            thislayerSize = FifoSize(pFifo);
            collect[numLayers] = malloc(sizeof(int) * thislayerSize);
            (*returnColumnSizes)[numLayers] = thislayerSize;
            idxThisLyer = 0;

        }


        pPopNode = PopFIFOTree(pFifo);

    }

    *returnSize = numLayers;

    return collect;

}


//103. Binary Tree Zigzag Level Order Traversal
//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
//
//Example 1:
//
//          3
//        /   \
//       9    20
//           /   \
//          15    7
//
//Ouput : root and right to left for 2 layers and left to right for 3 layer







P_SPE_FIFO_TREE_NODE_T CreateSpeFifo(void)
{
    P_SPE_FIFO_TREE_NODE_T pFifo = malloc(sizeof(SPE_FIFO_TREE_NODE_T ));
    pFifo->pLeftNode  = NULL;
    pFifo->pRightNode = NULL;
    pFifo->direct = LEFT_TO_RIGHT;
    return pFifo;
}

DECIDE_T IsEmptySPEFIFOTree(P_SPE_FIFO_TREE_NODE_T pFifo)
{
    DECIDE_T ret = YES;
    if (NULL != pFifo->pLeftNode) ret = NO;
    return ret;
}

int SPEFifoSize(P_SPE_FIFO_TREE_NODE_T pFifo)
{
    int size = 0;
    P_SPE_TWO_WAY_LINK_NODE_T pCell = (LEFT_TO_RIGHT == pFifo->direct) ? (pFifo->pLeftNode) : (pFifo->pRightNode);

    while (NULL != pCell)
    {
        size++;
        pCell = (LEFT_TO_RIGHT == pFifo->direct) ? (pCell->pToRight) : (pCell->pToLeft);
    }

    return size;

}
void PushSPEFIFOTree(P_SPE_FIFO_TREE_NODE_T pFifo, P_TREE_NODE_T pNode)
{
    if (NULL != pNode)
    {
        P_SPE_TWO_WAY_LINK_NODE_T pInsertNode = malloc(sizeof(SPE_TWO_WAY_LINK_NODE_T));
        pInsertNode->pNode    = pNode;
        P_SPE_TWO_WAY_LINK_NODE_T* pPreviousPointer = (LEFT_TO_RIGHT == pFifo->direct) ? &(pInsertNode->pToLeft)  : &(pInsertNode->pToRight);
        P_SPE_TWO_WAY_LINK_NODE_T* pNextPointer     = (LEFT_TO_RIGHT == pFifo->direct) ? &(pInsertNode->pToRight) : &(pInsertNode->pToLeft);
        if (LEFT_TO_RIGHT == pFifo->direct)


        *pPreviousPointer  = NULL;

        DECIDE_T ret = IsEmptySPEFIFOTree(pFifo);

        if (YES == ret)
        {
            //empty condition
            pFifo->pLeftNode  = pInsertNode;
            pFifo->pRightNode = pInsertNode;
            *pNextPointer = NULL;
        }
        else
        {
            P_SPE_TWO_WAY_LINK_NODE_T* pOldInput     = (LEFT_TO_RIGHT == pFifo->direct) ?  &(pFifo->pLeftNode)    :  &(pFifo->pRightNode);// Exist
            P_SPE_TWO_WAY_LINK_NODE_T* pOldPrevious = (LEFT_TO_RIGHT == pFifo->direct) ? &((*pOldInput)->pToLeft)  : &((*pOldInput)->pToRight);
            P_SPE_TWO_WAY_LINK_NODE_T* pOldNext     = (LEFT_TO_RIGHT == pFifo->direct) ? &((*pOldInput)->pToRight) :  &((*pOldInput)->pToLeft);
            *pOldPrevious = pInsertNode;// ----(1)
            *pNextPointer = *pOldInput; // ----(2)
            *pOldInput = pInsertNode;   // ----(3)
        }


    }
}
P_TREE_NODE_T PopSPEFIFOTree(P_SPE_FIFO_TREE_NODE_T pFifo)
{
    P_TREE_NODE_T pPopTreeNode = NULL;
    DECIDE_T ret = IsEmptySPEFIFOTree(pFifo);

    if (NO == ret)
    {
        P_SPE_TWO_WAY_LINK_NODE_T* pOuputFIFO = (LEFT_TO_RIGHT == pFifo->direct) ? &(pFifo->pRightNode) : &(pFifo->pLeftNode);
        P_SPE_TWO_WAY_LINK_NODE_T* pInputFIFO = (LEFT_TO_RIGHT == pFifo->direct) ? &(pFifo->pLeftNode)  : &(pFifo->pRightNode);
        pPopTreeNode = (*pOuputFIFO)->pNode;
        // Only element
        if ((*pInputFIFO) == (*pOuputFIFO))
        {
            free(*pOuputFIFO);
            *pInputFIFO  = NULL;
            *pOuputFIFO  = NULL;
        }
        else
        {
            P_SPE_TWO_WAY_LINK_NODE_T  pNextPopNode         = (LEFT_TO_RIGHT == pFifo->direct) ? ((*pOuputFIFO)->pToLeft)     :  ((*pOuputFIFO)->pToRight);
            P_SPE_TWO_WAY_LINK_NODE_T* pNextPopNodeNext     = (LEFT_TO_RIGHT == pFifo->direct) ? &((pNextPopNode)->pToRight)  :  &((pNextPopNode)->pToLeft);
            *pNextPopNodeNext = NULL;
            free(*pOuputFIFO);
            *pOuputFIFO = pNextPopNode;

        }
    }
    else
    {
        printf("Error fifo is empty\n ");
    }

    return pPopTreeNode;
}

void ChangeSPEFIFODirect(P_SPE_FIFO_TREE_NODE_T pFifo, TAG_TYPE direct)
{
    if (pFifo != NULL) pFifo->direct = direct;
}

P_TREE_NODE_T SeekSPEFIFOTree(P_SPE_FIFO_TREE_NODE_T pFifo)
{
    P_TREE_NODE_T pSeekNode = NULL;
    DECIDE_T ret = IsEmptySPEFIFOTree(pFifo);

    if (NO == ret)
    {
        pSeekNode = (LEFT_TO_RIGHT == pFifo->direct) ? ((pFifo->pRightNode)->pNode) : ((pFifo->pLeftNode)->pNode);
    }

    return pSeekNode;

}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{

    P_TREE_NODE_T pLayersLastNode = root;
    int capacity = 1;//cap of collect and returnColumnSizes
    int thislayerSize = 1;
    int numLayers     = 0;
    int idxThisLyer   = 0;
    int** collect = malloc(sizeof(int*) * capacity);
    *returnColumnSizes = malloc(sizeof(int) * capacity);

    P_SPE_FIFO_TREE_NODE_T pFifo = CreateSpeFifo();
    *returnSize = 0;
    (*returnColumnSizes)[0] = 0;
    if (NULL == root) return collect;
    collect[numLayers] = malloc(sizeof(int) * thislayerSize);
    (*returnColumnSizes)[0] = 1;

    PushSPEFIFOTree(pFifo, root);
    P_TREE_NODE_T pPopNode = PopSPEFIFOTree(pFifo);

    while (NULL != pPopNode)
    {
        collect[numLayers][idxThisLyer++] = pPopNode->val;

        int idx = 0;
        for (idx = 0; idx < 2; idx++)
        {
            P_TREE_NODE_T pPushNode =  (LEFT_TO_RIGHT == ((pFifo->direct + idx) & 0x1)) ? (pPopNode->left) : (pPopNode->right) ;
            PushSPEFIFOTree(pFifo, pPushNode);
        }

        if (pPopNode == pLayersLastNode)
        {
            numLayers++;

            if (numLayers == capacity) // need to extend collect, returnColumnSizes
            {

                // malloc
                int** tempCollect   = malloc(sizeof(int*) * (capacity << 1));
                int*  tempColumSize = malloc(sizeof(int)  * (capacity << 1));

                // copy pointer or data
                int idx = 0;
                for (idx = 0; idx < capacity; idx++)
                {
                    tempCollect[idx]   = collect[idx];//Copy pointer;
                    tempColumSize[idx] = (*returnColumnSizes)[idx];
                }

                //free old data
                free(collect);
                free(*returnColumnSizes);

                //Those pointer pointed New Space
                collect = tempCollect;
                *returnColumnSizes = tempColumSize;
                capacity <<= 1;

                tempCollect = NULL;
                tempColumSize = NULL;
            }

            pLayersLastNode = SeekSPEFIFOTree(pFifo);
            thislayerSize = SPEFifoSize(pFifo);
            collect[numLayers] = malloc(sizeof(int) * thislayerSize);
            (*returnColumnSizes)[numLayers] = thislayerSize;
            (pFifo->direct) = (LEFT_TO_RIGHT == pFifo->direct) ? (RIGHT_TO_LEFT) : (LEFT_TO_RIGHT);

            idxThisLyer = 0;

        }


        pPopNode = PopSPEFIFOTree(pFifo);

    }

    *returnSize = numLayers;

    return collect;

}



//104. Maximum Depth of Binary Tree
//Given the root of a binary tree, return its maximum depth.
//A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//Example 1:
//Input: root = [3,9,20,null,null,15,7]
//Output: 3
//
//         3
//      /     \
//     9      20
//           /  \
//          15   7


int maxDepth(struct TreeNode* root)
{
    int depth = 0;
    if (NULL != root)
    {
        int leftDepth  = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        depth = (leftDepth > rightDepth) ? (leftDepth) : (rightDepth);
        depth++;

    }

    return depth;

}


//108. Convert Sorted Array to Binary Search Tree
//Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
//
//Example 1:
//Input: nums = [-10,-3,0,5,9]
//Output: [0,-3,9,-10,null,5]
//Explanation: [0,-10,5,null,-3,null,9] is also accepted.
//
//
//Constraints:
//
//1 <= nums.length <= 104
//-104 <= nums[i] <= 104
//nums is sorted in a strictly increasing order.
//

static P_TREE_NODE_T sortedArrayToBSTByrecursive(int* nums, int numSize)
{
    P_TREE_NODE_T pHead = NULL;
    if (numSize != 0)
    {
        pHead = malloc(sizeof(TREE_NODE_T));
        int leftSize  = ((numSize -1) >> 1);
        int rightSize = (numSize - 1 - leftSize);
        pHead->val = nums[leftSize];
        pHead->left  = sortedArrayToBSTByrecursive(nums, leftSize);
        pHead->right = sortedArrayToBSTByrecursive(nums + leftSize + 1, rightSize);
    }


    return pHead;

}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    P_TREE_NODE_T pHead = sortedArrayToBSTByrecursive(nums, numsSize);
}


//Leetcode 109. Convert Sorted List to Binary Search Tree
//Given the "head of a singly linked list" where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

int CalListLength(P_LISTNODE_T pList)
{
    int nums = 0;

    while (NULL != pList)
    {
        pList = pList->next;
        nums++;
    }

    return nums;
}

static P_TREE_NODE_T constructdBSTByrecursive(int numSize)
{
    P_TREE_NODE_T pHead = NULL;
    if (numSize != 0)
    {
        pHead = malloc(sizeof(TREE_NODE_T));
        int leftSize  = ((numSize -1) >> 1);
        int rightSize = (numSize - 1 - leftSize);
        pHead->left  = constructdBSTByrecursive(leftSize);
        pHead->right = constructdBSTByrecursive(rightSize);
    }

    return pHead;

}


void InorederTree(P_TREE_NODE_T pHead,  P_LISTNODE_T* pList)
{
    if (NULL != pHead)
    {
        InorederTree(pHead->left, pList);
        pHead->val = (*pList)->val;
        (*pList) = (*pList)->next;
        InorederTree(pHead->right, pList);
    }

}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    int totalNums = CalListLength(head);
    P_TREE_NODE_T pHead = constructdBSTByrecursive(totalNums);
    P_LISTNODE_T* pRecord = malloc(sizeof(P_LISTNODE_T));
    *pRecord = head;
    InorederTree(pHead, pRecord);
    return pHead;
}






//116. Populating Next Right Pointers in Each Node
//You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
//struct Node
//{
//    int val;
//    Node *left;
//    Node *right;
//    Node *next;
//}
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//Initially, all next pointers are set to NULL.
//
//Input: root = [1,2,3,4,5,6,7]
//Output: [1,#,2,3,#,4,5,6,7,#]
//Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
//The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
//
// Constraints:
//
// The number of nodes in the tree is in the range [0, 2^12 - 1].
// -1000 <= Node.val <= 1000
//
//
//  Follow-up:
//
//  You may only use constant extra space.
//  The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
//
P_FIFO_ARRAY_T CreateFifoArray(void)
{
    P_FIFO_ARRAY_T  pFifo = malloc(sizeof(FIFO_ARRAY_T));
    pFifo->inputIdx = pFifo->outputIdx = 0;
    return pFifo;
}

DECIDE_T IsFifoArrayEmpty(P_FIFO_ARRAY_T pFifo)
{
    DECIDE_T ret = NO;

    if ((pFifo->inputIdx) == (pFifo->outputIdx))
    {
        ret = YES;
    }

    return ret;
}

//  O : be occupy. X : No occupy
//
//    inputIdx
//      ||
//      \/
// [ O | X |  |  |  | ... |  ]

//       inputIdx
//          ||
//          \/
// [ O | O | X |  |  | ... |  ]
void PushFifoArray(P_FIFO_ARRAY_T pFifo, P_NODE_T node)
{
    // FULL is impoibble if we use this size for this leetcode 116
    if (NULL != node)
    {
        int *pIdx = &(pFifo->inputIdx);
        pFifo->array[*pIdx] = node;
        (*pIdx) = ((*pIdx) + 1) & 0xfff ;
    }
}

P_NODE_T PopFifoArray(P_FIFO_ARRAY_T pFifo)
{
    DECIDE_T ret = IsFifoArrayEmpty(pFifo);
    P_NODE_T pNode = NULL;
    if (ret != YES)
    {
        int *pIdx = &(pFifo->outputIdx);
        pNode = pFifo->array[*pIdx];
        pFifo->array[*pIdx] = NULL;
        (*pIdx) = ((*pIdx) + 1) & 0xfff ;
    }

    return pNode;
}

struct Node* connect(struct Node* root)
{

    if (NULL != root)
    {
        P_FIFO_ARRAY_T  pFifo = CreateFifoArray();
        P_NODE_T pLastNode   = NULL;//Next time output in FIfo

        int thislayersNum = 1;
        int totalLayers   = 1;
        PushFifoArray(pFifo, root);

        DECIDE_T ret = IsFifoArrayEmpty(pFifo);
        while (ret != YES)
        {
            int thisLayerIdx = 0;
            P_NODE_T popNode;


            for (thisLayerIdx = 0; thisLayerIdx < thislayersNum; thisLayerIdx++)
            {
                popNode = PopFifoArray(pFifo);

                if (pLastNode != NULL) pLastNode->next = popNode; //Connected
                PushFifoArray(pFifo, popNode->left);
                PushFifoArray(pFifo, popNode->right);
                pLastNode = popNode;

            }

            thislayersNum = (1 << totalLayers);
            totalLayers++;

            pLastNode = NULL;// End This layers

            ret = IsFifoArrayEmpty(pFifo);
        }
    }



    return root;

}


//117. Populating Next Right Pointers in Each Node II
//Given a binary tree
//
//struct Node
//{
//    int val;
//    Node *left;
//    Node *right;
//    Node *next;
//}
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//Initially, all next pointers are set to NULL.
//
struct Node* connect117(struct Node* root)
{

    if (NULL != root)
    {
        P_FIFO_ARRAY_T  pFifo = CreateFifoArray();
        P_NODE_T pThisLayerLastNode   = root;   //Record this layers Last Node
        P_NODE_T pRecordNextLayerNode   = NULL; //Next time output in FIfo
        P_NODE_T popNode = NULL;
        P_NODE_T pPrePopNode = NULL;

        PushFifoArray(pFifo, root);

        DECIDE_T ret = IsFifoArrayEmpty(pFifo);
        while (ret != YES)
        {
            popNode = PopFifoArray(pFifo);
            printf("%2d\n", popNode->val);

            if (pPrePopNode != NULL) pPrePopNode->next = popNode;
            pPrePopNode = popNode;

            if (NULL != popNode->left)
            {
                pRecordNextLayerNode = popNode->left;
                PushFifoArray(pFifo, popNode->left);
            }
            if (NULL != popNode->right)
            {
                pRecordNextLayerNode = popNode->right;
                PushFifoArray(pFifo, popNode->right);
            }


            if (popNode == pThisLayerLastNode)
            {
                pThisLayerLastNode = pRecordNextLayerNode;
                pPrePopNode = NULL;

            }

            ret = IsFifoArrayEmpty(pFifo);
        }
    }

    return root;
}



//118. Pascal's Triangle
//Given an integer numRows, return the first numRows of Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
//Example 1:
//Input: numRows = 5
//Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//
//
//1 <= numRows <= 30
//
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//*/
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    *returnSize = numRows;

    int idx = 1;
    *returnColumnSizes = malloc(sizeof(int)  * numRows);
    int **pascalArray  = malloc(sizeof(int*) * numRows);
    int *prePtr;
    int *currPtr;
    int *thisLayersPtr;

    for (idx = 1; idx <= numRows; idx++)
    {
        (*returnColumnSizes)[idx-1] = idx;
        pascalArray[idx-1] = malloc(sizeof(int) * idx);
        pascalArray[idx-1][0] = 1;//Default a|k,1 = 0 for all k
        if (idx > 2)
        {
            prePtr   = pascalArray[idx-2];
            currPtr = (((int*) pascalArray[idx-2]) + 1);
        }

        // Cnt : do pascal algorithm time
        int cnt = (idx & 0x1) ? ((idx + 1) >> 1) : (idx >> 1);
        cnt--;
        int idx2 = 0;
        thisLayersPtr = (((int*) pascalArray[idx-1]) + 1);

        for (idx2 = 1; idx2 <= cnt; idx2++)
        {
            *(thisLayersPtr++) = *(prePtr++) + *(currPtr++);
        }

        // only copy time : idx - cnt - 1// 1 is default
        int cpyIdx;

        for (cpyIdx = (cnt + 1); cpyIdx < idx; cpyIdx++)
        {
            pascalArray[idx-1][cpyIdx] = pascalArray[idx-1][idx-1-cpyIdx];
        }

    }

    return pascalArray;

}



//121. Best Time to Buy and Sell Stock
//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
//Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
//
//
//Exampl1 :

//Input: prices = [7,1,5,3,6,4]
//Output: 5
//Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
//
//Example 2:
//
//Input: prices = [7,6,4,3,1]
//Output: 0
//Explanation: In this case, no transactions are done and the max profit = 0.
//
//Constraints:
//1 <= prices.length <= 105
//0 <= prices[i] <= 104

static int findMaxPrices(int *prices, int precesSize)
{
    int maxPrices = prices[0];
    int idx = 0;
    for (idx = 0; idx < precesSize; idx++)
    {
        if (maxPrices < prices[idx])
        {
            maxPrices = prices[idx];
        }
    }

    return maxPrices;
}

static int findMinPrices(int *prices, int precesSize)
{
    int minPrices = prices[0];
    int idx = 0;
    for (idx = 0; idx < precesSize; idx++)
    {
        if (minPrices >  prices[idx])
        {
            minPrices = prices[idx];
        }
    }

    return minPrices;
}

int maxProfit(int* prices, int pricesSize)
{
    int leftSize  = (pricesSize >> 1);
    int rightSize = (pricesSize - leftSize);

    if (pricesSize == 1)
    {

    }

}

