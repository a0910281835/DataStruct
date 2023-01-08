#include"stack_array.h"

NUM_T SizeStack(PSTACK_ARRAY_T pStackArray)
{
    return pStackArray->size;
}

PSTACK_ARRAY_T CreatStackArray(void)
{
    PSTACK_ARRAY_T pStackArray = (PSTACK_ARRAY_T) malloc(sizeof(StackArray));
    pStackArray->size = EMPTY_SIZE;
    return pStackArray;
}

void PushStack(PSTACK_ARRAY_T pStackArray, SPECIFY_OBJECT_TYPE inputObj)
{
    int *pSize = &(pStackArray->size);
    if ((MAX_SIZE) == *pSize)
    {
        printf("Warn! Stack is full\n");
    }
    else
    {
        pStackArray->stackCell[(*pSize)++] = inputObj;
    }
}

SPECIFY_OBJECT_TYPE StackTop(PSTACK_ARRAY_T pStackArray)
{

    int idx = (pStackArray->size) - 1;
    SPECIFY_OBJECT_TYPE outputObj = pStackArray->stackCell[idx];

    return outputObj;

}

SPECIFY_OBJECT_TYPE PopStack(PSTACK_ARRAY_T pStackArray)
{
    // Pointer may be not release in array, 
    SPECIFY_OBJECT_TYPE outputObj;
    int *pSize = &(pStackArray->size);
    if ((EMPTY_SIZE) == *pSize)
    {
        printf("Warn! Stack is empty, can't use\n");
    }
    else
    {
        outputObj = pStackArray->stackCell[--(*pSize)];
    }

        return outputObj;
}


static DECIDE_T isStateStack(PSTACK_ARRAY_T pStackArray, SIZE_STATE_T sizeState)
{
    DECIDE_T decide = NO;

    if (sizeState == pStackArray->size)
    {
        decide = YES;
    }

    return decide;
}

DECIDE_T IsEmptyStack(PSTACK_ARRAY_T pStackArray)
{
    DECIDE_T decide = isStateStack(pStackArray, EMPTY_SIZE);

    return decide;
}


DECIDE_T IsFullStack(PSTACK_ARRAY_T pStackArray)
{
    DECIDE_T decide = isStateStack(pStackArray, MAX_SIZE);

    return decide;
}
