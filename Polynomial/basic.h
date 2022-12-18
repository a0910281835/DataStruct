#ifndef _H_BASIC
#define _H_BASIC
#include "config.h"

// Polynomial basic term
typedef struct NONZERO_TERM_T *P_NONZERO_TERM_T;

typedef struct NONZERO_TERM_T
{
    int coef;
    int expon;
}NONZERO_TERM_T;

#endif
