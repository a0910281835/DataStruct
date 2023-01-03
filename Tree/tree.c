#include "tree.h"

RESULT insert(P_BINNODE_T pBinNode, ELEMENT_TYPE val)
{
    if (pBinNode != NULL)
    {
        printf("This Node Have Data");
        return FAIL;
    }
    else
    {
        pBinNode = (P_BINNODE_T) malloc(sizeof(BINNODE_T));
        pBinNode->val = val;
        return SUCC;
    }


}

