#ifndef _H_STACK_ARRAY
#define _H_STACK_ARRAY
#include "basic.h"


typedef struct StackArray *PSTACK_ARRAY_T;

typedef struct StackArray
{
    int size;
    ELEMENT_TYPE stackCell[MAX_SIZE];
}StackArray;


extern PSTACK_ARRAY_T CreatStackArray(void);
extern void PushStack(PSTACK_ARRAY_T pStackArray, ELEMENT_TYPE input);
extern RETURN PopStack(PSTACK_ARRAY_T pStackArray);
extern RETURN StackTop(PSTACK_ARRAY_T pStackArray);


#endif
