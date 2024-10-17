#include "tree.h"
#include "tree_application.h"
#include "stack_array.h"
#include "queue_array.h"
#include "link_list.h"


char *(DECIDE[2]) = {"NO", "YES" };

char * transWordYesOrNo(bool ret)
{
    return (DECIDE[ret]);
}


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


    //     -10
    //    /   \
    //   9      20
    //         /  \   .
    //        15   7

    //P_TREE_NODE_T pHead = malloc(sizeof(TREE_NODE_T));
    //pHead->val = -10;
    //pHead->left = malloc(sizeof(TREE_NODE_T));
    //(pHead->left)->val = 9;
    //pHead->right = malloc(sizeof(TREE_NODE_T));
    //(pHead->right)->val = 20;
    //(pHead->right)->left = malloc(sizeof(TREE_NODE_T));
    //((pHead->right)->left)->val  = 15;
    //(pHead->right)->right = malloc(sizeof(TREE_NODE_T));
    //(pHead->right)->right->val = 7;

    //int v = maxPathSum(pHead);
    //printf("%3d\n", v);


    //int returnSize = 0;
    //int** returnColumnSizes = malloc(sizeof(int*));
    ////int **array  = levelOrder(pHead, &returnSize, returnColumnSizes);
    //int ** array = zigzagLevelOrder(pHead, &returnSize, returnColumnSizes);
    //printf("%2d\n", returnSize);
    //int idx = 0;
    //int idx2 = 0;
    //for (idx = 0; idx < returnSize; idx++)
    //{
    //    printf("Layers size : %2d\n", (*returnColumnSizes)[idx2]);
    //    for (idx2 = 0; idx2 < (*returnColumnSizes)[idx]; idx2++)
    //    {
    //        printf("%2d, ", array[idx][idx2]);
    //    }


    //    printf("\n");
    //}


    //int depth = maxDepth(pHead);
    //printf("depth = %2d\n", depth);
    ////free
    ////
    ////
    ////

    //int nums[] = {1, 2, 3, 4, 5};

    //P_TREE_NODE_T pHead2 = sortedArrayToBST(nums, 5);
    //InOrderTravsl((P_BINNODE_T)pHead2);


    //for (idx = 0; idx < returnSize; idx++)
    //{
    //    free(array[idx]);
    //}
    //free(*returnColumnSizes);
    //free(returnColumnSizes);
    //free(array);





    //pHead2 = CopyTree(pHead);
    //TravelBinTree((BINTREE_HEAD)pHead, BREADTH_ORDER);
    //travalTreeAndAddNum(3, pHead);
    //TravelBinTree((BINTREE_HEAD)pHead, BREADTH_ORDER);
    //DeleteTree(pHead);
    //TravelBinTree((BINTREE_HEAD)pHead2, BREADTH_ORDER);
    //pHead = NULL;
    //TravelBinTree((BINTREE_HEAD)pHead, BREADTH_ORDER);


    //----- One Way FIFO----------------------//
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

    //-------Two Way FIFO------------------------//
    //
    //P_SPE_FIFO_TREE_NODE_T pFifo = CreateSpeFifo();
    //DECIDE_T retIdx = IsEmptySPEFIFOTree(pFifo);
    //printf(" is empty : %s \n", (DECIDE[retIdx]));
    //int num = SPEFifoSize(pFifo);
    //printf("num = %2d\n", num);
    //PushSPEFIFOTree(pFifo, pHead);
    //PushSPEFIFOTree(pFifo, pHead->left);
    ////PushSPEFIFOTree(pFifo, pHead->right);

    //num = SPEFifoSize(pFifo);
    //printf("num = %2d\n", num);
    //P_TREE_NODE_T pHead2 = PopSPEFIFOTree(pFifo);
    //printf("Val:%2d\n", pHead2->val);
    //ChangeSPEFIFODirect(pFifo, RIGHT_TO_LEFT);
    //printf("Change Direct\n");
    //
    //pHead2 = SeekSPEFIFOTree(pFifo);
    //printf("Val:%2d\n", pHead2->val);
    //pHead2 = PopSPEFIFOTree(pFifo);
    //printf("Val:%2d\n", pHead2->val);
    //pHead2 = PopSPEFIFOTree(pFifo);
    //printf("Val:%2d\n", pHead2->val);
    //num = SPEFifoSize(pFifo);
    //printf("num = %2d\n", num);
    //free(pFifo);



    //P_LISTNODE_T pList = malloc(sizeof(LISTNODE_T));
    //pList->val = 5;
    //pList->next = malloc(sizeof(LISTNODE_T));
    //(pList->next)->val = 7;
    //(pList->next)->next = NULL;
    //P_TREE_NODE_T pHead = sortedListToBST(pList);
    //printf("%2d\n", pHead->val);
    //printf("%2d\n", (pHead->right)->val);

    //int len = CalListLength(pList);
    //printf("%2d\n", len);

    //P_NODE_T pNode = malloc(sizeof(NODE_T));
    //pNode->val = 1;
    //pNode->next = NULL;
    //pNode->left  = malloc(sizeof(NODE_T));
    //pNode->right = malloc(sizeof(NODE_T));
    //(pNode->left)->val = 2;
    //(pNode->right)->val = 3;
    //(pNode->left)->left  = NULL;
    //(pNode->left)->right = NULL;
    //(pNode->right)->left  = NULL;
    //(pNode->right)->right = NULL;

    //(pNode->left)->left  =  malloc(sizeof(NODE_T));
    //(pNode->left)->right  = malloc(sizeof(NODE_T));
    //(pNode->right)->right  =  malloc(sizeof(NODE_T));
    //
    //((pNode->left)->left)->val  = 4;
    //((pNode->left)->right)->val = 5;
    //((pNode->right)->right)->val = 7;
    //((pNode->left)->left)->left  = NULL;
    //((pNode->left)->left)->right = NULL;
    //((pNode->left)->right)->left  = NULL;
    //((pNode->left)->right)->right = NULL;
    //((pNode->right)->right)->left = NULL;
    //((pNode->right)->right)->right = NULL;
    //connect117(pNode);

    //int idx = 0;
    //P_NODE_T pNext = (pNode->left)->left;
    //while(pNext != NULL)
    //{
    //    printf("%2d\n", pNext->val);
    //    pNext = pNext->next;
    //}

    //int returnSize = 0;
    //int numRows    = 5;
    //int ** returnColumnSizes = malloc(sizeof(int*));

    //int** pascalArray = generate(numRows, &returnSize, returnColumnSizes);
    //
    //int idx, idx2;

    //printf("------------------\n");
    //for (idx = 0; idx < returnSize; idx++)
    //{
    //    for (idx2 = 0; idx2 < (*returnColumnSizes)[idx]; idx2++)
    //    {
    //        printf("%2d, ", pascalArray[idx][idx2]);
    //    }

    //    printf("------------------\n");

    //}


    //int prices[] = {0,1,2,4,8,5,6,7,9,3,55,88,77,99,999999999};
    //int ret = longestConsecutive(prices, 15);
    //printf("%2d\n", ret);

    //int array[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    ////MergeSort(array, 7);
    //QuickSort(array, 8);
    //int idx = 0;
    //for (idx = 0; idx < 8; idx++)
    //{
    //    printf("%d\n", array[idx]);
    //}

    //T_WAITTING_PRIORITY_QUEUE * pWaitQueue = CreateWaittingQueue();

    //printf("empty : %2d \n", IsWQEmpty(pWaitQueue));

    //PT_THREAD pT = malloc(sizeof(T_THREAD));
    //*pT = 24;//this is PID
    //InsertSleepList(pWaitQueue, pT, 20);
    //printf("val : %d\n " , pWaitQueue->pHead->when);
    //pT = malloc(sizeof(T_THREAD));
    //*pT = 25;
    //InsertSleepList(pWaitQueue, pT, 50);
    //InsertSleepList(pWaitQueue, pT, 30);
    //printf("val : %d\n" , pWaitQueue->pHead->when);
    //printf("val : %d\n" , (pWaitQueue->pHead)->next->when);

    //TravelWatingQueue(pWaitQueue);
    //pT = PopWaittingQueue(pWaitQueue);
    //printf("pid : %d\n", *pT);
    //TravelWatingQueue(pWaitQueue);
    //pT = PopWaittingQueue(pWaitQueue);
    //printf("pid : %d\n", *pT);
    //TravelWatingQueue(pWaitQueue);
    //pT = PopWaittingQueue(pWaitQueue);
    //printf("pid : %d\n", *pT);
    //TravelWatingQueue(pWaitQueue);

    //---------------------------------- Leetcode LRU cache Test-------------------------------------------------------------
    //
    // 1. Node Test
    int key   = 5;
    int value = 20;
    //PT_CACHE_NODE pNode = CreateNode(key, value);
    //printf("Create Node with key:%2d, value:%2d\n", pNode->key, pNode->value);

    ////----------Double Link List  Test Start ----------------------
    //PT_DOUBLE_LINK_LIST pDoubleList = CreateDoubleList(2);
    //bool ret = IsDoubleListEmpty(pDoubleList);
    //printf("Double list is empty : %s\n", transWordYesOrNo(ret));
    //printf("Insert Node\n");
    //InsertInDoubleList(pDoubleList, pNode);
    //ret = IsDoubleListEmpty(pDoubleList);
    //printf("Double list is empty : %s\n", transWordYesOrNo(ret));

    //printf("Insert Node\n");
    //pNode = CreateNode(4, 11);
    //InsertInDoubleList(pDoubleList, pNode);
    //printf("Is full now?\n");
    //ret = IsDoubleListFull(pDoubleList);
    //printf("Double list is full : %s\n", transWordYesOrNo(ret));

    //TravelDoubleList(pDoubleList);
    //printf("current node key and value : %2d, %2d\n", pNode->key, pNode->value);
    //printf("------------Take Out Node By Special method \n");
    //PT_CACHE_NODE pNode2 = TakeOutNodeInDoubleList(pNode, pDoubleList);
    //printf("current node2 key and value : %2d, %2d\n", pNode2->key, pNode2->value);
    //TravelDoubleList(pDoubleList);

    ////----------Double Link List  Test end ----------------------
    //int cap = 4;
    //PT_HASH_TABLE pHashTable;
    //PT_CACHE_NODE pNode3 = NULL;
    //pHashTable = CreateHashTable(transOddNum(4));
    //printf("current node key and value : %2d, %2d\n", pNode->key, pNode->value);
    //printf("------");
    //bool findFlag = false;
    //printf("%1d\n", pHashTable->capacity);
    //printf("---find Node\n");
    //FindHashTable(pHashTable, pNode->key, &findFlag);
    //printf("This Node exist in Hash : %s\n", transWordYesOrNo(findFlag));
    //printf("---Insert The Node-----------\n");
    //InsetHashTable(pHashTable, pNode);
    //printf("---find Node\n");
    //pNode3 = FindHashTable(pHashTable, pNode->key, &findFlag);
    //printf("This Node exist in Hash : %s\n", transWordYesOrNo(findFlag));
    //printf("this Node Information : %1d,%1d\n", pNode3->key, pNode3->value);
    //PT_CACHE_NODE pNode4 = CreateNode(9, 21);
    //printf("Create Node with key:%2d, value:%2d\n", pNode4->key, pNode4->value);
    //InsetHashTable(pHashTable, pNode4);
    //printf("Inset The Node------------\n");
    //pNode3 = FindHashTable(pHashTable, pNode4->key, &findFlag);
    //printf("This Node exist in Hash : %s\n", transWordYesOrNo(findFlag));
    //PT_CACHE_NODE pTestNode = (pHashTable->pHashMapping)[4];
    //printf("%1d\n", pTestNode->key);
    //pTestNode = pTestNode->pConflictNext;
    //printf("%1d\n", pTestNode->key);
    //printf("Delete The Node-------\n");
    //DeleteNodeInHash(pHashTable, pNode);
    //pTestNode = (pHashTable->pHashMapping)[4];
    //while (pTestNode != NULL)
    //{
    //    printf("%1d\n", pTestNode->key);
    //    pTestNode = pTestNode->pConflictNext;
    //}

    //-----Cache function Operation Test------------------


    int capacity = 2;
    LRUCache* pLruCache = lRUCacheCreate(capacity);
    printf("--------create cache-----------\n");
    printf("--------0 end-----------\n");
    printf("hash cap : %1d, doublelist cap : %1d and size : %1d\n",(pLruCache->pHashTable)->capacity, (pLruCache->pDoublist)->capacity, (pLruCache->pDoublist)->size);
    lRUCachePut(pLruCache, 2, 1);
    printf("--------put Node 2,1-----------\n");
    printf("--------1 end-----------\n");
    lRUCachePut(pLruCache, 2, 2);
    printf("--------put Node 2,2-----------\n");
    printf("--------2 end-----------\n");
    key = lRUCacheGet(pLruCache, 2);
    printf("key : %1d\n", key);
    printf("--------get key 2-----------\n");
    printf("---travel-start-------------\n");
    TravelHashMapping(pLruCache->pHashTable);
    printf("---travel-end-------------\n");
    printf("--------3 end-----------\n");
    lRUCachePut(pLruCache, 1, 1);
    printf("--------put Node 1,1-----------\n");
    printf("--------4 end-----------\n");
    printf("---travel-start-------------\n");
    TravelHashMapping(pLruCache->pHashTable);
    printf("---travel-end-------------\n");
    lRUCachePut(pLruCache, 4, 1);
    printf("--------put Node 4,1-----------\n");
    printf("--------5 end-----------\n");
    //key = lRUCacheGet(pLruCache, 2);
    //lRUCacheFree(pLruCache);



    return 1;
}
