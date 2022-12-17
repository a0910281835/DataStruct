#ifndef _H_POLYNOMAIL_STRUCT
#define _H_POLYNOMAIL_STRUCT
#include "basic.h"
typedef struct PolyNode_T *polynomial;


typedef struct PolyArray
{
    int totalTerm;
    nonzero_term pPolyArray;
}PolyArray;

typedef struct PolyNode_T
{
    polynomial link;
    //int coef;
    //int expon;
    NONZERO_TERM term;
}POLYNODE_T;
#endif
