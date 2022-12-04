#include"stack_array.h"

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
        if (SIGN == input.tag)
        {
            printf("THIS is SIGN\n");
            (pStackArray->stackCell[++(*pSize)]).sign = input.sign;
            (pStackArray->stackCell[(*pSize)]).tag = input.tag;

        }
        else if (NUM == input.tag)
        {
            printf("THIS is NUM\n");
            (pStackArray->stackCell[++*(pSize)]).val = input.val;
            (pStackArray->stackCell[(*pSize)]).tag = input.tag;
        }
#endif
    }
}

RETURN StackTop(PSTACK_ARRAY_T pStackArray)
{
    int *pSize = &(pStackArray->size);

    RETURN ret;
    if (EMPTY_SIZE == *pSize)
    {
        ret.result = EMPTY;
        ret.output.sign = 'c';
    }
    else
    {
        ret.result = SUCC;
        ret.output = pStackArray->stackCell[*pSize];
    }

    return ret;

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
        if (SIGN == (pStackArray->stackCell[*(pSize)]).tag)
        {
            ret.output.tag = SIGN;
            ret.output.sign = (pStackArray->stackCell[(*pSize)--]).sign;

        }
        else if (NUM == (pStackArray->stackCell[*(pSize)]).tag)
        {
            ret.output.tag = NUM;
            ret.output.val = (pStackArray->stackCell[(*pSize)--]).val;
        }
#endif
    }
        return ret;
}
