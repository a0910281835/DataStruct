#include "tree.h"
#include "tree_application.h"
#include "stack_array.h"
#include "queue_array.h"


char *(array[2]) = {"NO", "YES" };



int main(void)
{

    //BINTREE_HEAD pHead  = NULL;
    //P_BINNODE_T current = NULL;

    //////       5
    //////     2   15
    //////        10  19
    //////       6   17 23
    //////        9   18
    //InsertValBinNode(pHead, 1);
    //InsertValBinNode(pHead->left, 2);
    //InsertValBinNode(pHead->right, 4);
    //InsertValBinNode((pHead->right)->left, 2);
    //printf("val: %d, %d, %d\n", pHead->val, (pHead->left)->val, (pHead->right)->val);
    //current = pHead->right;
    //InsertValBinNode(current->right, 19);
    //InsertValBinNode(current->left, 10);
    ////printf("val: %d, %d, %d\n", pHead->val, (pHead->left)->val, (pHead->right)->val);


    //printf("--------Travel Start----------\n");
    //TravelBinTree(pHead, BREADTH_ORDER);
    //RecoverTree((P_TREE_NODE_T)pHead);
    //TravelBinTree(pHead, IN_ORDER);
    ////TravelBinTree(pHead, PRE_ORDER);
    //printf("--------Travel End------------\n");

    //TRAVSAL_T preorder, inorder ;
    //preorder.travlMode = PRE_ORDER;
    //preorder.length = 5;
    //preorder.elementArray = malloc(sizeof(CUSTOM_ELEMENT_TYPE) * 5);
    //CUSTOM_ELEMENT_TYPE *pElement = preorder.elementArray;
    //pElement[0] = 4;
    //pElement[1] = 9;
    //pElement[2] = 7;
    //pElement[3] = 3;
    //pElement[4] = 10;

    //inorder.travlMode = IN_ORDER;
    //inorder.length = 5;
    //inorder.elementArray = malloc(sizeof(CUSTOM_ELEMENT_TYPE) * 5);
    //pElement = inorder.elementArray;
    //pElement[0] = 9;
    //pElement[1] = 4;
    //pElement[2] = 3;
    //pElement[3] = 7;
    //pElement[4] = 10;


    //pElement = preorder.elementArray;
    //int idx = 0;
    //for (idx = 0; idx < 5; idx++)
    //{
    //    printf("%2d ", *(pElement + idx));

    //}

    //BINTREE_HEAD pHead2 = CreateTree(&preorder, &inorder);
    //printf("--------Travel Start----------\n");
    //TravelBinTree(pHead2, IN_ORDER);
    //TravelBinTree(pHead2, PRE_ORDER);
    //printf("--------Travel End------------\n");




    //current = FindElementInBST(pHead, 15);
    //printf("check : %2d\n", current->val);
    //current = TakeMaxInBST(pHead);
    //printf("check : %2d\n", current->val);
    //P_BST_HEAD_T pHead3 = InsertElementInBST(pHead, 17);
    //pHead3 = InsertElementInBST(pHead3, 23);
    //pHead3 = InsertElementInBST(pHead3, 6);
    //pHead3 = InsertElementInBST(pHead3, 9);
    //pHead3 = InsertElementInBST(pHead3, 18);
    //printf("--------Travel BST Start----------\n");
    //printf("Inorder:\n");
    //TravelBinTree(pHead3, IN_ORDER);


    //printf("Preorder:\n");
    //TravelBinTree(pHead3, PRE_ORDER);
    //printf("Breathorder:\n");
    //TravelBinTree(pHead3, BREADTH_ORDER);
    //printf("--------Travel BST End------------\n");

    //int val = 19;
    //printf("Delete %2d\n", val);
    ////DeleteElementInBST(pHead3, 10);
    //pHead3 = DeleteElementInBSTByRecursive(pHead3, val);
    //printf("Breathorder:\n");
    //TravelBinTree(pHead3, BREADTH_ORDER);


    //CUSTOM_ARRAY_T* output =  BreadthOrderAndOuputArray(pHead3);
    //printf("Size = %2d\n", output->current_num);

    //for (idx = 0; idx < (output->current_num); idx++)
    //{
    //    printf("%2d\n", output->array[idx]);
    //}
    //DECIDE_T decide = IsBSTTree(pHead3);
    //decide = IsBSTTreeByRecursive(pHead3);
    //printf("%s\n", array[decide]);


   //int max_num = 9;
   //int idx;

   //int n = numTrees(max_num);
   //printf("%2d\n", n);


   //int *ret = malloc(sizeof(int));
   //P_HEAD_COLLECT_T collect;
   //collect = generateTrees(max_num, ret);
   //printf("--------List Trees num Start----------\n");
   //printf("total number : %2d\n", *ret);
   //for (idx = 0; idx < *ret; idx++)
   //{
   //    printf("The %3d th Tree-------\n", idx + 1);
   //    TravelBinTree((BINTREE_HEAD)collect[idx], BREADTH_ORDER);

   //}


   //int array[8] = { 12, 13, 25, 16, 18, 20, 15, 28};

   //FixOrderSeqence(array, 8);




    P_TREE_NODE_T pHead = malloc(sizeof(TREE_NODE_T));
    pHead->val = 5;
    pHead->left = malloc(sizeof(TREE_NODE_T));
    (pHead->left)->val = 7;
    pHead->right = malloc(sizeof(TREE_NODE_T));
    (pHead->right)->val = 3;
    (pHead->left)->right = malloc(sizeof(TREE_NODE_T));
    (pHead->left)->right->val = 4;


    int returnSize = 0;
    int** returnColumnSizes = malloc(sizeof(int*));
    int **array = levelOrder(pHead, &returnSize, returnColumnSizes);
    printf("%2d\n", returnSize);
    int idx;
    int idx2;
    for (idx = 0; idx < returnSize; idx++)
    {
        printf("Layers size : %2d\n", (*returnColumnSizes)[idx2]);
        for (idx2 = 0; idx2 < (*returnColumnSizes)[idx]; idx2++)
        {
            printf("%2d, ", array[idx][idx2]);
        }

        
        printf("\n");
    }





    //pHead2 = CopyTree(pHead);
    //TravelBinTree((BINTREE_HEAD)pHead, BREADTH_ORDER);
    //travalTreeAndAddNum(3, pHead);
    //TravelBinTree((BINTREE_HEAD)pHead, BREADTH_ORDER);
    //DeleteTree(pHead);
    //TravelBinTree((BINTREE_HEAD)pHead2, BREADTH_ORDER);
    //pHead = NULL;
    //TravelBinTree((BINTREE_HEAD)pHead, BREADTH_ORDER);


    //P_FIFO_PTREE_T pFifo = NULL;
    //DECIDE_T retIdx = IsEmptyFIFOTree(pFifo);
    //printf(" is empty : %s \n", array[retIdx]);
    //pFifo = malloc(sizeof(FIFO_PTREE_T));
    //pFifo->pNode = (P_TREE_NODE_T)pHead;
    //printf("%2d\n", pFifo->pNode->val);
    //// Practice FIFO which Saved tree.
    //P_FIFO_TREE_NODE_T pFifo = CreateFifo();
    //DECIDE_T retIdx = IsEmptyFIFOTree(pFifo);
    //printf(" is empty : %s \n", array[retIdx]);
    //PushFIFOTree(pFifo, pHead);
    //PushFIFOTree(pFifo, pHead->left);
    //PushFIFOTree(pFifo, pHead->left);
    //PushFIFOTree(pFifo, pHead->left);
    //int size = FifoSize(pFifo);
    //printf("size = %2d\n", size);

    //pHead2 = PopFIFOTree(pFifo);
    //retIdx = IsEmptyFIFOTree(pFifo);
    //printf(" is empty : %s \n", array[retIdx]);
    //printf("%2d\n", pHead2->val);
    //pHead2 = PopFIFOTree(pFifo);
    //retIdx = IsEmptyFIFOTree(pFifo);
    //printf(" is empty : %s \n", array[retIdx]);
    //printf("%2d\n", pHead2->val);
    //pHead2 = PopFIFOTree(pFifo);
    //retIdx = IsEmptyFIFOTree(pFifo);
    //printf(" is empty : %s \n", array[retIdx]);
    //printf("%2d\n", pHead2->val);
    //pHead2 = PopFIFOTree(pFifo);
    //retIdx = IsEmptyFIFOTree(pFifo);
    //printf(" is empty : %s \n", array[retIdx]);
    //printf("%2d\n", pHead2->val);
    //pHead2 = PopFIFOTree(pFifo);







    return 1;
}
