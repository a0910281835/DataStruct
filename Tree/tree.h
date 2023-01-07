#ifndef _TREE_H
#define _TREE_H
#include"basic.h"

typedef struct BINNODE_T * BINTREE_HEAD;
typedef struct BINNODE_T * P_BINNODE_T;
typedef struct BINNODE_T
{
    ELEMENT_TYPE val;
    P_BINNODE_T right;
    P_BINNODE_T left;

}BINNODE_T;

typedef enum
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER,
    BREADTH_ORDER

}TRAVERSAL_MODE;


typedef void (*FP_TREVALSAL_T)(P_BINNODE_T pBinNode);
extern void PreOrderTravsl(P_BINNODE_T pBinNode);
extern void InOrderTravsl(P_BINNODE_T pBinNode);
extern void PostOrderTravsl(P_BINNODE_T pBinNode);
extern void BreadthOrderTravsl(P_BINNODE_T pBinNode);

extern void TravelBinTree(BINTREE_HEAD pBinHead, TRAVERSAL_MODE mode);
extern P_BINNODE_T insertValBinNode(P_BINNODE_T pBinNode, ELEMENT_TYPE val);
#define InsertValBinNode(A,v) ((A) = insertValBinNode((A),(v)))
#endif
