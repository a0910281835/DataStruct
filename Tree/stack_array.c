#include"stack_array.h"


PSTACK_ARRAY_T CreatStackArray(size_t sizeofSpecialObj)
{
    PSTACK_ARRAY_T pStackArray = (PSTACK_ARRAY_T) malloc(sizeof(STACK_ARRAY_T));
    pStackArray->current_num = EMPTY_SIZE;
    pStackArray->sizeofObj = sizeofSpecialObj;
    pStackArray->pStackBox = malloc(MAX_SIZE * sizeofSpecialObj);

    return pStackArray;
}

void memcpyInStack(PSTACK_ARRAY_T pStackArray, void *Addr, int arrayIdx, CPY_MODE_T cpyMode)
{
    int cpyByteNum = pStackArray->sizeofObj;
    void *srcAddr = (((char *)pStackArray->pStackBox) + (arrayIdx * cpyByteNum));
    if (INPUT_CPY_TO_STACK == cpyMode)
    {
        memcpyMySelf(srcAddr, Addr, cpyByteNum);
    }
    else if (STACK_CPY_TO_OUTPUT == cpyMode)
    {
        memcpyMySelf(Addr, srcAddr, cpyByteNum);
    }

}

NUM_T SizeStack(PSTACK_ARRAY_T pStackArray)
{
    return pStackArray->current_num;
}

void PushStack(PSTACK_ARRAY_T pStackArray, void *pInputObjAddr)
{
    int *pSize = &(pStackArray->current_num);
    if ((MAX_SIZE) == *pSize)
    {
        // TODO: extend the size
        printf("Warn! Stack is full\n");
    }
    else
    {
        memcpyInStack(pStackArray, pInputObjAddr, *pSize, INPUT_CPY_TO_STACK);
        (*pSize)++;
    }
}


void PopStack(PSTACK_ARRAY_T pStackArray, void *pOutputObjAddr)
{
    // Pointer may be not release in array,
    int *pSize = &(pStackArray->current_num);
    if ((EMPTY_SIZE) == *pSize)
    {
        printf("Warn! Stack is empty, can't use\n");
    }
    else
    {
        (*pSize)--;
        memcpyInStack(pStackArray, pOutputObjAddr, *pSize, STACK_CPY_TO_OUTPUT);
    }

}
void StackTop(PSTACK_ARRAY_T pStackArray, void *pOutputObjAddr)
{

    int idx = (pStackArray->current_num) - 1;
    memcpyInStack(pStackArray, pOutputObjAddr, idx, STACK_CPY_TO_OUTPUT);
}

static DECIDE_T isStateStack(PSTACK_ARRAY_T pStackArray, SIZE_STATE_T sizeState)
{
    DECIDE_T decide = NO;

    if (sizeState == pStackArray->current_num)
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


