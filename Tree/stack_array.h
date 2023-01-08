#ifndef _H_STACK_ARRAY
#define _H_STACK_ARRAY
#include "basic.h"

// Condtion By You use!
//--------------------------------
#define SPECIFY_OBJECT_TYPE int
//-------------------------------


typedef struct StackArray *PSTACK_ARRAY_T;

typedef struct StackArray
{
    int size;
    SPECIFY_OBJECT_TYPE stackCell[MAX_SIZE];
}StackArray;


// It's Important to use those operation in your flow. Don't Add other Function. Push always Push. it doesn't check full or not. if you are afraid , you need to use IsFullStack to check.
extern PSTACK_ARRAY_T CreatStackArray(void);
extern void PushStack(PSTACK_ARRAY_T pStackArray, SPECIFY_OBJECT_TYPE inputObj);
extern SPECIFY_OBJECT_TYPE PopStack(PSTACK_ARRAY_T pStackArray);
extern SPECIFY_OBJECT_TYPE StackTop(PSTACK_ARRAY_T pStackArray);
extern DECIDE_T IsEmptyStack(PSTACK_ARRAY_T pStackArray);   
extern DECIDE_T IsFullStack(PSTACK_ARRAY_T pStackArray);
extern NUM_T SizeStack(PSTACK_ARRAY_T pStackArray);


#endif
