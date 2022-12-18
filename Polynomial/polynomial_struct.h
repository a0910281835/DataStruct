#ifndef _H_POLYNOMAIL_STRUCT
#define _H_POLYNOMAIL_STRUCT
#include "basic.h"

// Polynomial use array to construct
typedef struct PolyArray_T
{
    int totalTerm;
    P_NONZERO_TERM_T polyArray;
}PolyArray_T;



// Polynomial use link list to construct
typedef struct PolyNode_T *polynomial;

typedef struct PolyNode_T * POLY_LINK_HEAD;

typedef struct PolyNode_T
{
    polynomial link;
    NONZERO_TERM_T term;
}POLYNODE_T;
#endif
