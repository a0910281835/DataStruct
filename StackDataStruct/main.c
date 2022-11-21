#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"stack_array.h"

// Use array to make stack

#define SIGN_NUM 6
char sign[SIGN_NUM] = {'+', '-', '*', '/', '(', '^'};

int findSignIdx(char signInput)
{
    int idx = 0;
    int resultIdx = -1;

    for (idx = 0; idx < SIGN_NUM; idx++)
    {
        if (sign[idx] == signInput)
        {
            resultIdx = idx;
        }
    }
    return resultIdx;
}

int compareSignPriority[6][6] =
{
    {1, 1, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 1}
};

PSTACK_ARRAY_T ParserStringInfix2RPN(char *stringInput)
{
    //example : 2*(9+6/3-5)+4 , Output:2963/+5-*4+
    printf("Ha\n");
    char *Ouptut = (char *) malloc(MAX_SIZE);
    printf("%s\n", stringInput);
    PSTACK_ARRAY_T pStackArrayALL = CreatStackArray();
    PSTACK_ARRAY_T pSaveOperation = CreatStackArray();
    int idx = 0;
    char strCheck = stringInput[idx];
    int firstNumIdx, lastNumIdx;
    firstNumIdx = 0;
    lastNumIdx = -1;
    while (strCheck != '\0')
    {
        if ( (((int)'0') <=  ((int)strCheck)) && (((int)strCheck) <= ((int)'9') ))
        {
            lastNumIdx = idx;
            strCheck = stringInput[++idx];
            continue;
        }
        else
        {
            //Do sometghing but this time check
            if (firstNumIdx <= lastNumIdx)
            {
                //Output value
                printf("%d, %d\n", firstNumIdx, lastNumIdx);
                firstNumIdx = lastNumIdx = -1;

            }
            firstNumIdx = ++idx;
            strCheck = stringInput[idx];
        }



    }
    if (firstNumIdx != -1)
    {
                printf("%d, %d\n", firstNumIdx, lastNumIdx);
    }

    return pStackArrayALL;
}
/*
//-------------------------------------------
// Use Stack to finish expression for miditim

void ParserStringToInfixNotaion(char *string)
{
    //example :  (3+4*5+2+1)*5^4-2
    //string conatain
    // number : 1,2,...9,0
    // Operation:

}
*/

/* Pointer-------------------------------------------------------
typedef int ELEMENT_T;
typedef struct StackNode *STACKNODE_PT;

typedef enum
{
    NODE,
    HEAD,
    TAIL

}TYPE;


typedef struct StackNode
{
    ELEMENT_T val;
    STACKNODE_PT pNext;
    TYPE type;

}StackNode;


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
    }
    return ret;
}

PointerEnd---------------------------------------*/


//--------------------------------------------
//
//

int main(void)
{
    ELEMENT_TYPE notaion;
    notaion.tag = SIGN;
    notaion.sign = 'c';
    printf("%d, %c\n", notaion.tag, notaion.sign);
    notaion.tag = NUM;
    notaion.val = 12;
    printf("%d, %d\n", notaion.tag, notaion.val);
    printf("%d, %c\n", notaion.tag, notaion.sign);

    printf("%c\n", 76);
    //printf("%d\n", MAX_SIZE);
    //
    //STACKNODE_PT head = CreatePtrStack();
    //printf("Head Type:%d\n", (int)(head->type));
    //STACKNODE_PT pNode = head->pNext;
    //printf("TAIL Type:%d\n", pNode->type);
    //int idx = 0;
    //for (idx = 0; idx < 20; idx++)
    //{
    //    PushStackPointer(head, idx+60);
    //}
    //RETURN ret;
    //do
    //{
    //    ret = PopStackPointer(head);
    //    printf("pop Val %c\n", ret.val);

    //}while(SUCC == ret.result);

    PSTACK_ARRAY_T pStackArray = CreatStackArray();
    printf("%d\n", pStackArray->size);
    RETURN ret = PopStack(pStackArray);
    printf("%d\n", ret.ouput.val);
    printf("%d\n", '0');
    printf("%d\n", '1');
    printf("%d\n", '9');

    char *inputStr = "2*(9+6/3-5)+4";
    ParserStringInfix2RPN(inputStr);
   // char str1 = '-';
   // int arrayIdx = findSignIdx(str1);
   // printf("%d\n", arrayIdx);
   // char str2 = '*';
   // int arrayIdx2 = findSignIdx(str2);
   // printf("%d\n", arrayIdx2);

   // int comVal = compareSignPriority[arrayIdx][arrayIdx2];
   // printf("ret : %d\n", comVal);

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
