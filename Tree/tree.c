#include "tree.h"

P_BINNODE_T InsertValBinNode(P_BINNODE_T pBinNode, ELEMENT_TYPE val)
{
    if (pBinNode != NULL)
    {
        pBinNode->val = val;
        printf("This val be change\n");
    }
    else
    {
        pBinNode = (P_BINNODE_T) malloc(sizeof(BINNODE_T));
        pBinNode->val = val;
    }

    return pBinNode;


}

