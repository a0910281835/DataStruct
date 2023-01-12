#include"stack_array.h"


PSTACK_ARRAY_T CreatStackArray(size_t sizeofSpecialObj)
{
    PSTACK_ARRAY_T pStackArray = (PSTACK_ARRAY_T) malloc(sizeof(STACK_ARRAY_T));
    pStackArray->current_num = EMPTY_SIZE;
    pStackArray->sizeofObj = sizeofSpecialObj;
    pStackArray->pStackBox = malloc(MAX_SIZE * sizeofSpecialObj);

    return pStackArray;
}

void memcpyInStack(PSTACK_ARRAY_T pStackArray, void *beCpyAddr, int arrayIdx, size_t sizeofSpecialObj)
{
    int cpyByte = sizeofSpecialObj;
    int idx = 0;
    char *cpyAddr = (((char *)pStackArray->pStackBox) + (arrayIdx * sizeofSpecialObj));

    for (idx = 0; idx < cpyByte; idx++)
    {
        *(cpyAddr++) = *((char *)beCpyAddr++);
    }
}

NUM_T SizeStack(PSTACK_ARRAY_T pStackArray)
{
    return pStackArray->current_num;
}

void PushStack(PSTACK_ARRAY_T pStackArray, void *pInputObj, size_t sizeofSpecialObj)
{
    int *pSize = &(pStackArray->current_num);
    if ((MAX_SIZE) == *pSize)
    {
        // To do extend the size
        printf("Warn! Stack is full\n");
    }
    else
    {
        memcpyInStack(pStackArray, pInputObj, *pSize, sizeofSpecialObj);
        (*pSize)++;
    }
}
/*

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
*/
