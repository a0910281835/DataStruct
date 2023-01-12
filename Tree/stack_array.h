#ifndef _H_STACK_ARRAY
#define _H_STACK_ARRAY
#include "basic.h"
#if defined(_TRAVSAL_USE_STACK)
#include "tree.h"
#endif


#if defined(_TRAVSAL_USE_STACK)
#define SPECIFY_OBJECT_TYPE P_BINNODE_T
#else
//--------------------------------
#define SPECIFY_OBJECT_TYPE int
//-------------------------------
#endif

typedef struct STACK_ARRAY_T *PSTACK_ARRAY_T;

typedef struct STACK_ARRAY_T
{
    int  current_num;
    void *pStackBox;
}STACK_ARRAY_T;


// It's Important to use those operation in your flow. Don't Add other Function. Push always Push. it doesn't check full or not. if you are afraid , you need to use IsFullStack to check.
extern PSTACK_ARRAY_T CreatStackArray(size_t sizeofSpecialObj);
extern void memcpyInStack(PSTACK_ARRAY_T pStackArray, void *cpyAdd, int arrayIdx, size_t sizeofSpecialObj);
/*
extern void PushStack(PSTACK_ARRAY_T pStackArray, SPECIFY_OBJECT_TYPE inputObj);
extern SPECIFY_OBJECT_TYPE PopStack(PSTACK_ARRAY_T pStackArray);
extern SPECIFY_OBJECT_TYPE StackTop(PSTACK_ARRAY_T pStackArray);
extern DECIDE_T IsEmptyStack(PSTACK_ARRAY_T pStackArray);   
extern DECIDE_T IsFullStack(PSTACK_ARRAY_T pStackArray);
extern NUM_T SizeStack(PSTACK_ARRAY_T pStackArray);
*/

#endif
