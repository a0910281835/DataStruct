#include"stack_array.h"
#include<stdio.h>
#include<stdlib.h>

PSTACK_ARRAY_T CreatStackArray(void)
{
    PSTACK_ARRAY_T pStackArray = (PSTACK_ARRAY_T) malloc(sizeof(StackArray));
    pStackArray->size = -1;
    return pStackArray;
}

void PushStack(PSTACK_ARRAY_T pStackArray, ELEMENT_TYPE input)
{
    int *pSize = &(pStackArray->size);
    if ((MAX_SIZE - 1) == *pSize)
    {
        printf("stack is full\n");
    }
    else
    {
#if defined(_ELEMENT_TYPE_INT)
        pStackArray->stackCell[++*(pSize)] = input;
#elif defined(_ELEMENT_TYPE_UNION)
        (pStackArray->stackCell[*(pSize)]).sign = input.sign;
        (pStackArray->stackCell[++*(pSize)]).val = input.val;
#endif
    }
}

RETURN PopStack(PSTACK_ARRAY_T pStackArray)
{
    int *pSize = &(pStackArray->size);
    RETURN ret;
    if (EMPTY_SIZE == *pSize)
    {
        ret.result = EMPTY;
        printf("stack is empty\n");
    }
    else
    {
        ret.result = SUCC;
#if defined(_ELEMENT_TYPE_INT)
        ret.val = pStackArray->stackCell[(*pSize)--];
#elif defined(_ELEMENT_TYPE_UNION)
        ret.ouput.sign = (pStackArray->stackCell[*(pSize)]).sign;
        ret.ouput.val  = (pStackArray->stackCell[(*pSize)--]).val;
#endif
    }
        return ret;
}
