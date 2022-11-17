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
typedef int ELEMENT_T;
typedef struct StackNode *STACKNODE_PT;

typedef enum
{
    NODE,
    HEAD,
    TAIL

}TYPE;

typedef enum
{
    EMPTY,
    SUCC
}CELL_SIZE;

typedef struct StackNode
{
    ELEMENT_T val;
    STACKNODE_PT pNext;
    TYPE type;

}StackNode;

typedef struct RETURN
{
    ELEMENT_T val;
    CELL_SIZE result;
}RETURN;

STACKNODE_PT CreatePtrStack(void)
{
    STACKNODE_PT head = (STACKNODE_PT) malloc(sizeof(StackNode));
    head->type = HEAD;
    STACKNODE_PT tail = (STACKNODE_PT) malloc(sizeof(StackNode));
    tail->type = TAIL;
    head->pNext = tail;
    tail->pNext = head;
    return head;
}

void PushStackPointer(STACKNODE_PT head, ELEMENT_T val)
{
    STACKNODE_PT pNode = (STACKNODE_PT) malloc(sizeof(StackNode));
    pNode->val = val;
    pNode->type = NODE;
    pNode->pNext = head->pNext;
    head->pNext = pNode;

}

RETURN PopStackPointer(STACKNODE_PT head)
{
    RETURN ret;
    STACKNODE_PT pNode = head->pNext;

    if (TAIL == pNode->type)
    {
        ret.result = EMPTY;
        printf("the stack is empty\n");
    }
    else
    {
        head->pNext = pNode->pNext;
        ret.val = pNode->val;
        free(pNode);
        pNode = NULL;
        ret.result = SUCC;
        return ret;
    }
}

int main(void)
{
    STACKNODE_PT head = CreatePtrStack();
    printf("Head Type:%d\n", (int)(head->type));
    STACKNODE_PT pNode = head->pNext;
    printf("TAIL Type:%d\n", pNode->type);
    int idx = 0;
    for (idx = 0; idx < 20; idx++)
    {
        PushStackPointer(head, idx);
    }
    RETURN ret;
    do
    {
        ret = PopStackPointer(head);
        printf("pop Val %d\n", ret.val);

    }while(SUCC == ret.result);

    //PSTACK_ARRAY_T pStackArray = CreatStackArray();
    //printf("%d\n", pStackArray->size);
    //PopStack(pStackArray);

    //int idx = 0;
    //for (idx = -4; idx < 4; idx++)
    //{
    //    int val = idx * idx + 3;
    //    printf("push stack val : %d\n", val);
    //    PushStack(pStackArray, val);
    //}

    //for (idx = pStackArray->size; idx >= 0; idx--)
    //{
    //    int val = PopStack(pStackArray);
    //    printf("pop stack order val : %d\n", val);
    //}




    return 1;
}
