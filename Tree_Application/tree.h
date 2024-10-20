#ifndef _H_TREE
#define _H_TREE
#include"basic.h"

#define elderSon       left
#define brother        right
#define fatherOrElder  father
typedef struct BINNODE_T * BINTREE_HEAD;
typedef struct BINNODE_T * P_BINNODE_T;
typedef struct BINNODE_T
{
    CUSTOM_ELEMENT_TYPE val;
    P_BINNODE_T left;
    P_BINNODE_T right;
    P_BINNODE_T father;

}BINNODE_T;

//Leetcode 71
//71. Simplify Path
//
char*  simplifyPath(char* path);
char** ParserString(char* path, int* pNum);


typedef enum
{
    PRE_ORDER = 0,
    IN_ORDER,
    POST_ORDER,
    BREADTH_ORDER

}TRAVERSAL_MODE;

#if defined(_TRAVSAL_USE_STACK)
typedef struct BINNODE_EXPERIENT_T
{
    P_BINNODE_T pNode;
    NUM_T num_exp;

}BINNODE_EXPERIENT_T;
#endif


//Purpose : Used to check Is this tree BST
//Output struct array with size
typedef struct CUSTOM_ARRAY_T
{
    CUSTOM_ELEMENT_TYPE* array;
    NUM_T size;
    NUM_T current_num;
}CUSTOM_ARRAY_T;

typedef enum
{
    PRINTF = 0,
    ARRAY  = 1
}OUTPUT_FORMAT_T;
extern CUSTOM_ARRAY_T* BreadthOrderAndOuputArray(P_BINNODE_T pBinNode);
extern CUSTOM_ARRAY_T* PreOrderAndOuputArray(P_BINNODE_T pBinNode);
extern CUSTOM_ARRAY_T* InOrderAndOuputArray(P_BINNODE_T pBinNode);
//Purpose : end



typedef void (*FP_TREVALSAL_T)(P_BINNODE_T pBinNode);
extern void PreOrderTravsl(P_BINNODE_T pBinNode);
extern void InOrderTravsl(P_BINNODE_T pBinNode);
extern void PostOrderTravsl(P_BINNODE_T pBinNode);
extern void BreadthOrderTravsl(P_BINNODE_T pBinNode);

extern void TravelBinTree(BINTREE_HEAD pBinHead, TRAVERSAL_MODE mode);
extern P_BINNODE_T insertValBinNode(P_BINNODE_T pBinNode, CUSTOM_ELEMENT_TYPE val);
#define InsertValBinNode(A,v) ((A) = insertValBinNode((A),(v)))
#endif
