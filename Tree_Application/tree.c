#include"config.h"
#include"tree.h"

P_BINNODE_T insertValBinNode(P_BINNODE_T pBinNode, CUSTOM_ELEMENT_TYPE val)
{
    if (pBinNode != NULL)
    {
        CUSTOM_ELEMENT_TYPE temp = pBinNode->val;
        pBinNode->val = val;
        printf("temp:");
        PrintfCustomElement(temp);
        printf("now:");
        PrintfCustomElement(val);
        //printf("This val be change %d -> %d\n", temp, val);
    }
    else
    {
        pBinNode = (P_BINNODE_T) malloc(sizeof(BINNODE_T));
        pBinNode->val = val;
        printf("create:");
        PrintfCustomElement(val);
        //printf("Create the val %d\n", val);
    }

    return pBinNode;
}


bool AmIEldSon(P_BINNODE_T pNode)
{
    bool ret = false;
    P_BINNODE_T pFatherOrElder = pNode->fatherOrElder;
    if (pFatherOrElder->elderSon == pNode)
    {
        ret = true;
    }
    return ret;
}


P_BINNODE_T FindFatherNode(P_BINNODE_T pSonNode)
{
    P_BINNODE_T pFollower = pSonNode;

}




/*

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
//
// Concept : Whatever recursive or Stack
// The important is "PreOrderTravsl(pBinNode->left)"
// you directly this point information but when you back
// "PreOrderTravsl(pBinNode->right)" you need to try again use this point information
// that is why you need to use stack.
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
// post order keypoint is what be saved in stack

static CUSTOM_ARRAY_T* preOrderAndOuput(P_BINNODE_T pBinNode, OUTPUT_FORMAT_T outType)
{
    CUSTOM_ARRAY_T *out = malloc(sizeof(CUSTOM_ARRAY_T));
    if (ARRAY == outType)
    {
        out->size = 2;
        out->current_num = 0;
        out->array = (CUSTOM_ELEMENT_TYPE*) malloc(sizeof(CUSTOM_ELEMENT_TYPE) * (out->size));
    }


    PSTACK_ARRAY_T pStackVisitedNode = CreatStackArray(sizeof(P_BINNODE_T));
    DECIDE_T decide;
    do
    {
        while(NULL != pBinNode)
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
                    //Copy term and extend Double space
                    CUSTOM_ARRAY_T *pCpy = malloc(sizeof(CUSTOM_ARRAY_T));
                    pCpy->size = ((out->size) << 1);
                    pCpy->array = (CUSTOM_ELEMENT_TYPE*) malloc(sizeof(CUSTOM_ELEMENT_TYPE) * (pCpy->size));


                    // copy data in full cell to new cell which has double space.
                    memcpyMySelf((char*)(pCpy->array), (char*)(out->array), sizeof(CUSTOM_ELEMENT_TYPE) * (out->size));
                    pCpy->current_num = out->size;


                    // release the old Data and let Purpose pointer to cpy pointer
                    free(out->array);
                    out->array = NULL;
                    free(out);
                    out = NULL;
                    out = pCpy;
                    pCpy = NULL;

                    //printf("extend experience : %2d -> %2d\n", out

                }

                //Add a new term to array
                memcpyMySelf( ((char*)(out->array) + (out->current_num) * sizeof(CUSTOM_ELEMENT_TYPE)) , &(pBinNode->val), sizeof(CUSTOM_ELEMENT_TYPE));
                out->current_num++;

            }
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


    if (PRINTF == outType)
    {
        free(out);
    }

    return out;
}

CUSTOM_ARRAY_T* PreOrderAndOuputArray(P_BINNODE_T pBinNode)
{
    OUTPUT_FORMAT_T outType = ARRAY;

    CUSTOM_ARRAY_T* output = preOrderAndOuput(pBinNode, outType);

    return output;
}

void PreOrderTravsl(P_BINNODE_T pBinNode)
{
    OUTPUT_FORMAT_T outType = PRINTF;

    preOrderAndOuput(pBinNode, outType);
}

//DD_
static CUSTOM_ARRAY_T* inOrderAndOuput(P_BINNODE_T pBinNode, OUTPUT_FORMAT_T outType)
{
    CUSTOM_ARRAY_T *out = malloc(sizeof(CUSTOM_ARRAY_T));
    out->size = 2;
    out->current_num = 0;
    out->array = (CUSTOM_ELEMENT_TYPE*) malloc(sizeof(CUSTOM_ELEMENT_TYPE) * (out->size));


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

            if (PRINTF == outType)
            {
                PrintfCustomElement(pBinNode->val);
            }
            else if (ARRAY == outType)
            {
                // Is FULL Now, Need to extend
                if (out->current_num == out->size)
                {
                    //Copy term and extend Double space
                    CUSTOM_ARRAY_T *pCpy = malloc(sizeof(CUSTOM_ARRAY_T));
                    pCpy->size = ((out->size) << 1);
                    pCpy->array = (CUSTOM_ELEMENT_TYPE*) malloc(sizeof(CUSTOM_ELEMENT_TYPE) * (pCpy->size));


                    // copy data in full cell to new cell which has double space.
                    memcpyMySelf((char*)(pCpy->array), (char*)(out->array), sizeof(CUSTOM_ELEMENT_TYPE) * (out->size));
                    pCpy->current_num = out->size;


                    // release the old Data and let Purpose pointer to cpy pointer
                    free(out->array);
                    out->array = NULL;
                    free(out);
                    out = NULL;
                    out = pCpy;
                    pCpy = NULL;

                    //printf("extend experience : %2d -> %2d\n", out

                }

                //Add a new term to array
                memcpyMySelf( ((char*)(out->array) + (out->current_num) * sizeof(CUSTOM_ELEMENT_TYPE)) , &(pBinNode->val), sizeof(CUSTOM_ELEMENT_TYPE));
                out->current_num++;

            }

            pBinNode = pBinNode->right;
        }

    } while(NO == decide);

    if (PRINTF == outType)
    {
        free(out);
    }

    return out;
}

CUSTOM_ARRAY_T* InOrderAndOuputArray(P_BINNODE_T pBinNode)
{
    OUTPUT_FORMAT_T outType = ARRAY;

    CUSTOM_ARRAY_T* output = inOrderAndOuput(pBinNode, outType);

    return output;
}
//DD_
void InOrderTravsl(P_BINNODE_T pBinNode)
{
    OUTPUT_FORMAT_T outType = PRINTF;

    inOrderAndOuput(pBinNode, outType);
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

//In order to reuse this funciton.
static CUSTOM_ARRAY_T* breadthOrderAndOuput(P_BINNODE_T pBinNode, OUTPUT_FORMAT_T outType)
{
    CUSTOM_ARRAY_T *out = malloc(sizeof(CUSTOM_ARRAY_T));
    out->size = 2;
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
                //Copy term and extend Double space
                CUSTOM_ARRAY_T *pCpy = malloc(sizeof(CUSTOM_ARRAY_T));
                pCpy->size = ((out->size) << 1);
                pCpy->array = (CUSTOM_ELEMENT_TYPE*) malloc(sizeof(CUSTOM_ELEMENT_TYPE) * (pCpy->size));


                // copy data in full cell to new cell which has double space.
                memcpyMySelf((char*)(pCpy->array), (char*)(out->array), sizeof(CUSTOM_ELEMENT_TYPE) * (out->size));
                pCpy->current_num = out->size;


                // release the old Data and let Purpose pointer to cpy pointer
                free(out->array);
                out->array = NULL;
                free(out);
                out = NULL;
                out = pCpy;
                pCpy = NULL;

                //printf("extend experience : %2d -> %2d\n", out

            }

            //Add a new term to array
            memcpyMySelf( ((char*)(out->array) + (out->current_num) * sizeof(CUSTOM_ELEMENT_TYPE)) , &(pBinNode->val), sizeof(CUSTOM_ELEMENT_TYPE));
            out->current_num++;

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

    return out;
}

CUSTOM_ARRAY_T* BreadthOrderAndOuputArray(P_BINNODE_T pBinNode)
{
    OUTPUT_FORMAT_T outType = ARRAY;

    CUSTOM_ARRAY_T* output = breadthOrderAndOuput(pBinNode, outType);

    return output;
}

void BreadthOrderTravsl(P_BINNODE_T pBinNode)
{
    OUTPUT_FORMAT_T outType = PRINTF;

    breadthOrderAndOuput(pBinNode, outType);
}


//Use function Pointer to Construct
//Here we use another skill to envolpe those function
void TravelBinTree(BINTREE_HEAD pBinHead, TRAVERSAL_MODE mode)
{
    fp_Traversal[mode](pBinHead);
}
*/



// Leetcode 71

//You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.
//
//The rules of a Unix-style file system are as follows:
//
//A single period '.' represents the current directory.
//A double period '..' represents the previous/parent directory.
//Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
//Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
//The simplified canonical path should follow these rules:
//
//The path must start with a single slash '/'.
//Directories within the path must be separated by exactly one slash '/'.
//The path must not end with a slash '/', unless it is the root directory.
//The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
//Return the simplified canonical path.
char* simplifyPath(char* path)
{
    BINTREE_HEAD pRootDir = malloc(sizeof(BINNODE_T));
    pRootDir->val = "root";
    pRootDir->father = NULL;
    
}

char** extendArrayCap(char** oldArray, int* pCurentCap)
{
    int newCap = (*pCurentCap) << 1;
    char** newArray = malloc(sizeof(char*) * newCap);
    int idx = 0;
    for (idx = 0; idx < *pCurentCap; idx++)
    {
        newArray[idx] = oldArray[idx];
    }
    *pCurentCap = newCap;

    return newArray;
}


char** ParserString(char* path, int* pNum)
{
    // this path has been copy, so you can divid it
    char** dividedArray = malloc(sizeof(char*) * 32);
    int cap = 16;

    char* pDividStr = strtok(path, "/");

    *pNum = 0;
    if (NULL != pDividStr)
    {
        
        do
        {
            dividedArray[(*pNum)++] = pDividStr;
            pDividStr = strtok(NULL, "/");
            
            if (*pNum >= cap)
            {
                //Extend Array
                printf("error");
                dividedArray = extendArrayCap(dividedArray, &cap);
            }

        } while(NULL != pDividStr);
    }


    return dividedArray;
}
