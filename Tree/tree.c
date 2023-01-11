#include"config.h"
#include"tree.h"
#include"stack_array.h"

P_BINNODE_T insertValBinNode(P_BINNODE_T pBinNode, CUSTOM_ELEMENT_TYPE val)
{
    if (pBinNode != NULL)
    {
        CUSTOM_ELEMENT_TYPE temp = pBinNode->val;
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


// Function Pointer reduce Cache Miss
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

#elif defined(_TRAVSAL_USE_STACK)
void PreOrderTravsl(P_BINNODE_T pBinNode)
{
    PSTACK_ARRAY_T pStackVisitedNode = CreatStackArray();
    DECIDE_T decide;

    do
    {
        while(NULL != pBinNode)
        {
            PrintfCustomElement(pBinNode->val);
            PushStack(pStackVisitedNode, pBinNode);
            pBinNode = pBinNode->left;
        }

        decide = IsEmptyStack(pStackVisitedNode);

        if (decide == NO)
        {
            pBinNode = PopStack(pStackVisitedNode);
            pBinNode = pBinNode->right;
        }

    } while(NO == decide);
}

void InOrderTravsl(P_BINNODE_T pBinNode)
{
    PSTACK_ARRAY_T pStackVisitedNode = CreatStackArray();
    DECIDE_T decide;

    do
    {
        while(NULL != pBinNode)
        {
            PushStack(pStackVisitedNode, pBinNode);
            pBinNode = pBinNode->left;
        }

        decide = IsEmptyStack(pStackVisitedNode);

        if (decide == NO)
        {
            pBinNode = PopStack(pStackVisitedNode);
            PrintfCustomElement(pBinNode->val);
            pBinNode = pBinNode->right;
        }

    } while(NO == decide);
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

#endif
void BreadthOrderTravsl(P_BINNODE_T pBinNode)
{

}


//Use function Pointer to Construct
void TravelBinTree(BINTREE_HEAD pBinHead, TRAVERSAL_MODE mode)
{
    fp_Traversal[mode](pBinHead);
}

