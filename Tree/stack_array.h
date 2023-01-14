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
    int    current_num;
    size_t sizeofObj;
    void   *pStackBox;
}STACK_ARRAY_T;

typedef enum
{
    INPUT_CPY_TO_STACK,
    STACK_CPY_TO_OUTPUT
}CPY_MODE_T;

// It's Important to use those operation in your flow. Don't Add other Function. Push always Push. it doesn't check full or not. if you are afraid , you need to use IsFullStack to check.
extern void memcpyInStack(PSTACK_ARRAY_T pStackArray, void *Addr, int arrayIdx, CPY_MODE_T cpyMode);
extern PSTACK_ARRAY_T CreatStackArray(size_t sizeofSpecialObj);
extern void PushStack(PSTACK_ARRAY_T pStackArray, void *pInputObj);
extern void PopStack(PSTACK_ARRAY_T pStackArray, void *pOutputObjAddr);
extern void StackTop(PSTACK_ARRAY_T pStackArray, void *pOutputObjAddr);
extern NUM_T SizeStack(PSTACK_ARRAY_T pStackArray);
extern DECIDE_T IsEmptyStack(PSTACK_ARRAY_T pStackArray);
extern DECIDE_T IsFullStack(PSTACK_ARRAY_T pStackArray);

#endif
