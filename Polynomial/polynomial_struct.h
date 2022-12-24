#ifndef _H_POLYNOMAIL_STRUCT
#define _H_POLYNOMAIL_STRUCT
#include "basic.h"

// Polynomial use array to construct
# ifdef _POLYNOMAIL_ARRAY 
typedef struct PolyArray_T
{
    int totalTerm;
    P_NONZERO_TERM_T polyArray;
}PolyArray_T;
# endif



// Polynomial use link list to construct
# ifdef _POLYNOMAIL_LINK
typedef struct PolyNode_T * POLY_LINK_HEAD;
typedef struct PolyNode_T * P_POLYNODE_T;

typedef struct PolyNode_T
{
    P_POLYNODE_T link;
    NONZERO_TERM_T term;
}POLYNODE_T;
# endif


# if defined(_POLYNOMAIL_LINK) && defined(_POLYNOMAIL_ARRAY)
typedef struct PolyNode_T *polynomial;
#elif defined(_POLYNOMAIL_ARRAY) && !defined(_POLYNOMAIL_LINK)
typedef struct PolyArray_T *polynomial;
#endif


#endif
