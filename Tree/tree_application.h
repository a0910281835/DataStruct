#ifndef _H_TREE_APPLICATION
#define _H_TREE_APPLICATION
#include "tree.h"

typedef struct TRAVSAL_T * P_TRAVSAL_T;
typedef struct TRAVSAL_T
{
    CUSTOM_ELEMENT_TYPE * elementArray;
    NUM_T length;
    TRAVERSAL_MODE travlMode;
}TRAVSAL_T;


#endif

