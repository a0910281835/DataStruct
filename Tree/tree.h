#ifndef _TREE_H
#define _TREE_H
#include "basic.h"

typedef struct BINNODE_T * BINTREE_HEAD;
typedef struct BINNODE_T * P_BINNODE_T;
typedef struct BINNODE_T
{
    ELEMENT_TYPE val;
    P_BINNODE_T right;
    P_BINNODE_T left;

}BINNODE_T;
#endif
