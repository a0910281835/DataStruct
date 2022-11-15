#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Use array to make stack
#define MAX_SIZE 1000
#define EMPTY_SIZE -1

typedef struct StackArray *PSTACK_ARRAY_T;
typedef struct StackArray
{
    int size;
    int stackCell[MAX_SIZE];

}StackArray;

PSTACK_ARRAY_T CreatStackArray(void)
{
    PSTACK_ARRAY_T pStackArray = (PSTACK_ARRAY_T) malloc(sizeof(StackArray));
    pStackArray->size = -1;
}

void PushStack(PSTACK_ARRAY_T pStackArray, int val)
{
    int *pSize = &(pStackArray->size);
    if ((MAX_SIZE - 1) == *pSize)
    {
        printf("stack is full\n");
    }
    else
    {
        pStackArray->stackCell[++*(pSize)] = val;
    }
}

int PopStack(PSTACK_ARRAY_T pStackArray)
{
    int *pSize = &(pStackArray->size);
    if (EMPTY_SIZE == *pSize)
    {
        printf("stack is empty\n");
    }
    else
    {
        int val = pStackArray->stackCell[(*pSize)--];
        return val;

    }
}
int main(void)
{
    PSTACK_ARRAY_T pStackArray = CreatStackArray();
    printf("%d\n", pStackArray->size);
    PopStack(pStackArray);

    int idx = 0;
    for (idx = -4; idx < 4; idx++)
    {
        int val = idx * idx + 3;
        printf("push stack val : %d\n", val);
        PushStack(pStackArray, val);
    }

    for (idx = pStackArray->size; idx >= 0; idx--)
    {
        int val = PopStack(pStackArray);
        printf("pop stack order val : %d\n", val);
    }
    return 1;
}
