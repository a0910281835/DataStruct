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
    int array[3] = {2, 2, 1};

    singleNumber(array, 3);

    return 1;
}
