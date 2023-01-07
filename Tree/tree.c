#include"config.h"
#include"tree.h"

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

const FP_TREVALSAL_T fp_Traversal[] = 
{
   PreOrderTravsl,
   InOrderTravsl,
   PostOrderTravsl,
   BreadthOrderTravsl,
};


#if defined(_RECURSIVE_TRAVESAL)
// Recursive method
void PreOrderTravsl(P_BINNODE_T pBinNode)
{
    if (pBinNode != NULL)
    {
        printf("%d\n", pBinNode->val);
        PreOrderTravsl(pBinNode->left);
        PreOrderTravsl(pBinNode->right);
    }
}

void InOrderTravsl(P_BINNODE_T pBinNode)
{
    if (pBinNode != NULL)
    {
        InOrderTravsl(pBinNode->left);
        printf("%d\n", pBinNode->val);
        InOrderTravsl(pBinNode->right);
    }
}

void PostOrderTravsl(P_BINNODE_T pBinNode)
{
    if (pBinNode != NULL)
    {
        PostOrderTravsl(pBinNode->left);
        PostOrderTravsl(pBinNode->right);
        printf("%d\n", pBinNode->val);
    }
}

void BreadthOrderTravsl(P_BINNODE_T pBinNode)
{

}
#elif defined(_TRAVSAL_USE_STACK)
#endif


//Use function Pointer to Construct
void TravelBinTree(BINTREE_HEAD pBinHead, TRAVERSAL_MODE mode)
{
    fp_Traversal[mode](pBinHead);
}

