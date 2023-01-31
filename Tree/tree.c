#include"config.h"
#include"tree.h"
#include"stack_array.h"
#include "queue_array.h"

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
// the keypoint is what save in stack for Travsal by stack

void PreOrderTravsl(P_BINNODE_T pBinNode)
{
    PSTACK_ARRAY_T pStackVisitedNode = CreatStackArray(sizeof(P_BINNODE_T));
    DECIDE_T decide;

    do
    {
        while(NULL != pBinNode)
        {
            PrintfCustomElement(pBinNode->val);
            PushStack(pStackVisitedNode, &pBinNode);
            pBinNode = pBinNode->left;
        }

        decide = IsEmptyStack(pStackVisitedNode);

        if (decide == NO)
        {
            PopStack(pStackVisitedNode, &pBinNode);
            pBinNode = pBinNode->right;
        }

    } while(NO == decide);
}

void InOrderTravsl(P_BINNODE_T pBinNode)
{
    PSTACK_ARRAY_T pStackVisitedNode = CreatStackArray(sizeof(P_BINNODE_T));
    DECIDE_T decide;

    do
    {
        while(NULL != pBinNode)
        {
            PushStack(pStackVisitedNode, &pBinNode);
            pBinNode = pBinNode->left;
        }

        decide = IsEmptyStack(pStackVisitedNode);

        if (decide == NO)
        {
            PopStack(pStackVisitedNode, &pBinNode);
            PrintfCustomElement(pBinNode->val);
            pBinNode = pBinNode->right;
        }

    } while(NO == decide);
}

void PostOrderTravsl(P_BINNODE_T pBinNode)
{
#define NOT_HAVE_BEEN 0
#define HAVE_BEEN_ONE_TIME 1
    PSTACK_ARRAY_T pStackVisitedNode = CreatStackArray(sizeof(BINNODE_EXPERIENT_T));
    BINNODE_EXPERIENT_T binNodeWithExp;
    DECIDE_T decide;
    binNodeWithExp.pNode = pBinNode;
    binNodeWithExp.num_exp = 0;

    do
    {
        while(NULL != binNodeWithExp.pNode)
        {
            PushStack(pStackVisitedNode, &binNodeWithExp);
            binNodeWithExp.pNode = binNodeWithExp.pNode->left;
            binNodeWithExp.num_exp = NOT_HAVE_BEEN;
        }

        decide = IsEmptyStack(pStackVisitedNode);

        if (NO == decide)
        {
            // check this Node experient time

            PopStack(pStackVisitedNode, &binNodeWithExp);
            if (NOT_HAVE_BEEN == binNodeWithExp.num_exp)
            {

                // Push Stack Again
                binNodeWithExp.num_exp = HAVE_BEEN_ONE_TIME;
                PushStack(pStackVisitedNode, &binNodeWithExp);

                binNodeWithExp.pNode = binNodeWithExp.pNode->right;
                binNodeWithExp.num_exp = NOT_HAVE_BEEN;


            }
            else if (HAVE_BEEN_ONE_TIME == binNodeWithExp.num_exp)
            {
                // right subtree have been visited
                PrintfCustomElement(binNodeWithExp.pNode->val);
                binNodeWithExp.pNode = NULL;
                binNodeWithExp.num_exp = NOT_HAVE_BEEN;
            }
        }

    } while(NO == decide);
}

#endif

static CUSTOM_ARRAY_T breadthOrderAndOuput(P_BINNODE_T pBinNode, OUTPUT_FORMAT_T outType)
{
    CUSTOM_ARRAY_T *out = malloc(sizeof(CUSTOM_ARRAY_T));
    out->size = 10;
    out->current_num = 0;
    out->array = (CUSTOM_ELEMENT_TYPE*) malloc(sizeof(CUSTOM_ELEMENT_TYPE) * (out->size));

    
    P_QUEUE_ARRAY_T pQueue = CreatQueueArray(sizeof(P_BINNODE_T));
    DECIDE_T decide = YES;
    while (NULL != pBinNode)
    {

        if (PRINTF == outType)
        {
            PrintfCustomElement(pBinNode->val);
        }
        else if (ARRAY == outType)
        {
            // Is FULL Now, Need to extend
            if (out->current_num == out->size)
            {
                CUSTOM_ARRAY_T *pTemp = malloc(sizeof(CUSTOM_ARRAY_T));


            }



        }
        if (NULL != pBinNode->left)  PushQueue(pQueue, &(pBinNode->left));
        if (NULL != pBinNode->right) PushQueue(pQueue, &(pBinNode->right));
        
        decide = IsEmptyQueue(pQueue);
        if (NO == decide) 
        {
            PopQueue(pQueue, &pBinNode);
        }
        else
        {
            pBinNode = NULL;
        }
    }

}


void BreadthOrderTravsl(P_BINNODE_T pBinNode)
{
    P_QUEUE_ARRAY_T pQueue = CreatQueueArray(sizeof(P_BINNODE_T));
    DECIDE_T decide = YES;
    while (NULL != pBinNode)
    {
        PrintfCustomElement(pBinNode->val);
        if (NULL != pBinNode->left)  PushQueue(pQueue, &(pBinNode->left));
        if (NULL != pBinNode->right) PushQueue(pQueue, &(pBinNode->right));
        
        decide = IsEmptyQueue(pQueue);
        if (NO == decide) 
        {
            PopQueue(pQueue, &pBinNode);
        }
        else
        {
            pBinNode = NULL;
        }
    }

}


//Use function Pointer to Construct
void TravelBinTree(BINTREE_HEAD pBinHead, TRAVERSAL_MODE mode)
{
    fp_Traversal[mode](pBinHead);
}

