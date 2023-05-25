#include"basic.h"
#include"graph.h"

int main(void)
{
    //     5 ---- 4
    //     |\     |
    //     | \    |
    //     |  \   |
    //     |   \  |
    //     |    \ |
    //     2      3



    //printf("h\n");
    //P_NODE_GRAPH_T pNode = malloc(sizeof(NODE_GRAPH_T));

    //pNode->val = 5;
    //pNode->numNeighbors = 3;
    //pNode->neighbors = malloc(sizeof(P_NODE_GRAPH_T) * 3);

    //pNode->neighbors[0] = malloc(sizeof(NODE_GRAPH_T)); // val 4
    //pNode->neighbors[1] = malloc(sizeof(NODE_GRAPH_T)); // val 3
    //pNode->neighbors[2] = malloc(sizeof(NODE_GRAPH_T)); // val 2

    //P_NODE_GRAPH_T pHead2 = pNode->neighbors[0];
    //pHead2->val = 4;
    //pHead2->numNeighbors = 2;
    //pHead2->neighbors = malloc(sizeof(P_NODE_GRAPH_T) * 2);
    //pHead2->neighbors[0] = pNode; // 5
    //pHead2->neighbors[1] = pNode->neighbors[1]; // 3


    //pHead2 = pNode->neighbors[1];
    //pHead2->val = 3;
    //pHead2->numNeighbors = 2;
    //pHead2->neighbors = malloc(sizeof(P_NODE_GRAPH_T) * 2);
    //pHead2->neighbors[0] = pNode; // 5
    //pHead2->neighbors[1] = pNode->neighbors[0]; // 4

    //pHead2 = pNode->neighbors[2];
    //pHead2->val = 2;
    //pHead2->numNeighbors = 1;
    //pHead2->neighbors = malloc(sizeof(P_NODE_GRAPH_T) * 1);
    //pHead2->neighbors[0] = pNode; // 5


    //pHead2 = cloneGraph(pNode);
    //PrintfGraph(pHead2);
    //printf("-------\n");
    //PrintfGraph(pNode);
    //int ret = reverseBits(0x20);
    //printf("%x\n", ret);


    //int array[11] = { 1, 1, 2, 2, 4, 4, 10000, 20000, 20000, -1200, -1200};
    //int array[] = {-401451,-177656,-2147483646,-473874,-814645,-2147483646,-852036,-457533,-401451,-473874,-401451,-216555,-917279,-457533,-852036,-457533,-177656,-2147483646,-177656,-917279,-473874,-852036,-917279,-216555,-814645,2147483645,-2147483648,2147483645,-814645,2147483645,-216555};
    //printf("%2d\n", (int)sizeof(array));

    //singleNumber2(array, 31);
    //ret = hammingWeight(0xfffffffd);
    //printf("%d\n", ret);

    //printf("------------------\n");
    //P_LISTNODE_T pList = malloc(sizeof(LISTNODE_T));
    //P_LISTNODE_T pTemp = pList;
    //P_LISTNODE_T pTemp2 = pList;

    //int idx = 0;
    //for (idx = 0; idx < 3; idx++)
    //{
    //    pList->val = idx + 3;
    //    pList->next = malloc(sizeof(LISTNODE_T));
    //    pList = pList->next;
    //}
    //pList->val = 8;
    //pList->next = pTemp;
    //pList->next = NULL;

    //while(NULL != pTemp)
    //{
    //    printf("%d", pTemp->val);
    //    pTemp = pTemp->next;
    //    if (NULL != pTemp) printf(" -> ");
    //}
    //printf("\n");
    //NEXT(pTemp2);
    //printf("temp: %d\n", pTemp2->val);
    //pTemp = (pTemp->next)->next;
    //ret = hasCycle(pTemp);
    //ret = hasCycle2(pTemp2);
    //printf("%x\n", ret);

    //--------------
    //P_MIN_STACK_T pMinStack = minStackCreate();
    //int * pUseNum = &(pMinStack->useNum);
    //P_LISTNODE_T *pHead = &(pMinStack->pHead);
    //P_LISTNODE_T pListNode;
    //int idx;

    //minStackPush(pMinStack, 512);
    //minStackPush(pMinStack, -1024);
    //minStackPush(pMinStack, -1024);
    //minStackPush(pMinStack, 512);
    //pListNode = *pHead;
    //printf("Stack\n");
    //for (idx = 0; idx < (*pUseNum); idx++)
    //{
    //    printf("%d(%2d)", pListNode->val, pListNode->pos);
    //    pListNode = pListNode->next;
    //    if (pListNode != NULL)
    //        printf(" -> ");

    //}
    //printf("\n");
    //int val;
    //printf("MinPriority\n");
    //for (idx = 0; idx < (*pUseNum); idx++)
    //{
    //    printf("idx : %d ,val : %d\n", idx, pMinStack->pArray[idx]->val);

    //}
    //printf("\n");

    //minStackPop(pMinStack);
    //int ret = minStackGetMin(pMinStack);
    //printf("min : %d\n", ret);
    //pListNode = *pHead;
    //printf("Stack\n");
    //for (idx = 0; idx < (*pUseNum); idx++)
    //{
    //    printf("%d(%2d)", pListNode->val, pListNode->pos);
    //    pListNode = pListNode->next;
    //    if (pListNode != NULL)
    //        printf(" -> ");

    //}
    //printf("\n");
    //printf("MinPriority\n");
    //for (idx = 0; idx < (*pUseNum); idx++)
    //{
    //    printf("idx : %d ,val : %d\n", idx, pMinStack->pArray[idx]->val);

    //}
    //printf("\n");
    //minStackPop(pMinStack);
    ////ret = minStackGetMin(pMinStack);
    ////printf("min : %d\n", ret);

    ////for (idx = 0; idx < *pUseNum; idx++)
    ////{
    ////    printf("%d -> ", (*pHead)->val);
    ////}
    ////printf("\n");

    ////printf("StackSize = %d, UseSize = %d\n", pMinStack->cellNum, pMinStack->useNum);
    ////
    ////minStackPush(pMinStack, 10);
    ////minStackPush(pMinStack, 14);
    ////minStackPush(pMinStack, 9);
    ////minStackPush(pMinStack, 13);
    ////minStackPush(pMinStack, 3);
    ////minStackPush(pMinStack, 12);
    ////minStackPush(pMinStack, 1);
    //pListNode = *pHead;
    //printf("Stack\n");
    //for (idx = 0; idx < (*pUseNum); idx++)
    //{
    //    printf("%d", pListNode->val);
    //    pListNode = pListNode->next;
    //    if (pListNode != NULL)
    //        printf(" -> ");

    //}
    //printf("\n");
    //printf("MinPriority\n");
    //for (idx = 0; idx < (*pUseNum); idx++)
    //{
    //    printf("idx : %d ,val : %d\n", idx, pMinStack->pArray[idx]->val);

    //}
    //printf("\n");
    ////minStackPop(pMinStack);
    ////pListNode = *pHead;
    ////printf("Stack\n");
    ////for (idx = 0; idx < (*pUseNum); idx++)
    ////{
    ////    printf("%d", pListNode->val);
    ////    pListNode = pListNode->next;
    ////    if (pListNode != NULL)
    ////        printf(" -> ");

    ////}
    ////printf("\n");
    ////printf("MinPriority\n");
    ////for (idx = 0; idx < (*pUseNum); idx++)
    ////{
    ////    printf("idx : %d ,val : %d\n", idx, pMinStack->pArray[idx]->val);

    ////}
    ////printf("\n");
    ////
    ////minStackFree(pMinStack);
    ////printf("StackSize = %d, UseSize = %d\n", pMinStack->cellNum, pMinStack->useNum);
    ////printf("StackFirstNum : %d , Array First : %d\n", (pMinStack->pHead)->val, (pMinStack->pArray[0])->val);


    ////char *ch[] = {"MinStack","push", "push", "getMin", "top", "pop", "getMin", "top"};
    ////char *strArray = "{[],[10],[5],[],[],[],[],[]}";
    //char *ch[] = {"MinStack","push","push","getMin","getMin","getMin","pop","getMin","push","push","getMin","push","top","push","getMin","push","getMin","push","push","getMin","push","push","push","getMin","top","push","getMin","getMin","getMin","pop","push","getMin","getMin","getMin","top","top","push","top","getMin","push","push","getMin","top","push","getMin","getMin","top","top","push","getMin","getMin","pop","pop","top","getMin","push","pop","push","push","getMin","push","push","pop","getMin","getMin","push","push","getMin","push","getMin","push","push","push","push","push","getMin","pop","getMin","push","push","push","push","pop","getMin","top","getMin","getMin","top","push","pop","push","top","push","push","push","getMin","top","push","push","push","top","push","push","push","top","getMin","push","getMin","push","top","push","push","getMin","pop","pop","push","pop","getMin","top","getMin","top","push","getMin","push","getMin","getMin","push","getMin","push","top","getMin","getMin","push","getMin","pop","getMin","getMin","getMin","top","pop","push","top","getMin","getMin","getMin","push","getMin","push","pop","push","push","push","push","pop","getMin","pop","pop","push","top","push","pop","getMin","getMin","push","push","getMin","pop","push","top","push","push","top","push","push","push","getMin","push","pop","getMin","push","push","getMin","push","getMin","pop","getMin","push","push","top","top","push","getMin","pop","push","getMin","push","push","getMin","top","pop","push"};
    //char *strArray = "{[],[-124],[-164],[],[],[],[],[],[-24],[-100],[],[33],[],[-22],[],[197],[],[127],[122],[],[139],[142],[189],[],[],[-40],[],[],[],[],[174],[],[],[],[],[],[-28],[],[],[177],[-117],[],[],[42],[],[],[],[],[-43],[],[],[],[],[],[],[158],[],[25],[-197],[],[-120],[-74],[],[],[],[51],[60],[],[182],[],[-161],[57],[156],[-182],[28],[],[],[],[122],[-119],[-101],[77],[],[],[],[],[],[],[-185],[],[-25],[],[-7],[91],[-79],[],[],[-168],[115],[-14],[],[-95],[-24],[34],[],[],[20],[],[-88],[],[1],[186],[],[],[],[-45],[],[],[],[],[],[89],[],[-65],[],[],[-100],[],[-85],[],[],[],[91],[],[],[],[],[],[],[],[-80],[],[],[],[],[-66],[],[-3],[],[-185],[-15],[-185],[-8],[],[],[],[],[177],[],[-160],[],[],[],[-39],[-67],[],[],[187],[],[178],[32],[],[-119],[-83],[162],[],[124],[],[],[-86],[-21],[],[19],[],[],[],[-126],[-110],[],[],[71],[],[],[-64],[],[-21],[148],[],[],[],[72]}";
    //int size = (int)(sizeof(ch)/ sizeof(int*));
    //printf("size %d\n", size);
    //printf("\n");
    //int *array = ParserStringToArray(strArray, size);
    //MinStackSeqOperate(ch, array, size);
    //ret = ParserStringToMinStackOperate(ch[3]);
    //printf("Res%d\n", ret);
    //
    int cnt = 9;
    int idx = 0;

    P_LISTNODE_T pList = malloc(sizeof(LISTNODE_T));
    pList->val = 1;
    pList->next = NULL;
    P_LISTNODE_T pOld = pList;

    for (idx = 0; idx < cnt; idx++)
    {
        int val;
        if (idx < (cnt >> 1))
        {
            val = idx;
        }
        else
        {
            val = cnt - idx - 1;
        }

        P_LISTNODE_T pNew = malloc(sizeof(LISTNODE_T));
        pNew->val  = val;
        pNew->next = NULL;
        pOld->next = pNew;
        pOld = pOld->next;

    }

    pOld = pList;
    while (pOld != NULL)
    {
        printf("%d -> ", pOld->val);
        pOld = pOld->next;
    }
    printf("\n");

    
    int ret = isPalindrome(pList->next);
    printf("%d\n", ret);

    return 1;
}
