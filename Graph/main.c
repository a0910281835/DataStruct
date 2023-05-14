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



    printf("h\n");
    P_NODE_GRAPH_T pNode = malloc(sizeof(NODE_GRAPH_T));

    pNode->val = 5;
    pNode->numNeighbors = 3;
    pNode->neighbors = malloc(sizeof(P_NODE_GRAPH_T) * 3);

    pNode->neighbors[0] = malloc(sizeof(NODE_GRAPH_T)); // val 4
    pNode->neighbors[1] = malloc(sizeof(NODE_GRAPH_T)); // val 3
    pNode->neighbors[2] = malloc(sizeof(NODE_GRAPH_T)); // val 2

    P_NODE_GRAPH_T pHead2 = pNode->neighbors[0];
    pHead2->val = 4;
    pHead2->numNeighbors = 2;
    pHead2->neighbors = malloc(sizeof(P_NODE_GRAPH_T) * 2);
    pHead2->neighbors[0] = pNode; // 5
    pHead2->neighbors[1] = pNode->neighbors[1]; // 3


    pHead2 = pNode->neighbors[1];
    pHead2->val = 3;
    pHead2->numNeighbors = 2;
    pHead2->neighbors = malloc(sizeof(P_NODE_GRAPH_T) * 2);
    pHead2->neighbors[0] = pNode; // 5
    pHead2->neighbors[1] = pNode->neighbors[0]; // 4

    pHead2 = pNode->neighbors[2];
    pHead2->val = 2;
    pHead2->numNeighbors = 1;
    pHead2->neighbors = malloc(sizeof(P_NODE_GRAPH_T) * 1);
    pHead2->neighbors[0] = pNode; // 5


    pHead2 = cloneGraph(pNode);
    PrintfGraph(pHead2);
    printf("-------\n");
    PrintfGraph(pNode);
    int ret = reverseBits(0x20);
    printf("%x\n", ret);


    //int array[11] = { 1, 1, 2, 2, 4, 4, 10000, 20000, 20000, -1200, -1200};
    //int array[] = {-401451,-177656,-2147483646,-473874,-814645,-2147483646,-852036,-457533,-401451,-473874,-401451,-216555,-917279,-457533,-852036,-457533,-177656,-2147483646,-177656,-917279,-473874,-852036,-917279,-216555,-814645,2147483645,-2147483648,2147483645,-814645,2147483645,-216555};
    //printf("%2d\n", (int)sizeof(array));

    //singleNumber2(array, 31);
    //ret = hammingWeight(0xfffffffd);
    //printf("%d\n", ret);

    printf("------------------\n");
    P_LISTNODE_T pList = malloc(sizeof(LISTNODE_T));
    P_LISTNODE_T pTemp = pList;

    int idx = 0;
    for (idx = 0; idx < 3; idx++)
    {
        pList->val = idx + 3;
        pList->next = malloc(sizeof(LISTNODE_T));
        pList = pList->next;
    }
    pList->val = 8;
    pList->next = pTemp;

    //while(NULL != pTemp)
    //{
    //    printf("%d", pTemp->val);
    //    pTemp = pTemp->next;
    //    if (NULL != pTemp) printf(" -> ");
    //}
    //printf("\n");
    ret = hasCycle(pTemp);
    printf("%x\n", ret);
    int b = 6;
    int *a = &b;
    printf("%p\n",a);

    return 1;
}
