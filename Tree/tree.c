#include "tree.h"

P_BINNODE_T insertValBinNode(P_BINNODE_T pBinNode, ELEMENT_TYPE val)
{
    if (pBinNode != NULL)
    {
        ELEMENT_TYPE temp = pBinNode->val;
        pBinNode->val = val;
        printf("This val be change %d -> %d\n", temp, val);
    }
    else
    {
        pBinNode = (P_BINNODE_T) malloc(sizeof(BINNODE_T));
        pBinNode->val = val;
        printf("Create the val %d\n", val);
    }

    return pBinNode;


}

