#include<stdio.h>
#include<stdlib.h>
#include"stack_array.h"
#include"paser_infix_and_cal.h"



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


    char *inputStr = "2*(9+61*4/3-5)+4";
    PSTACK_ARRAY_T pStackArray = ParserStringInfix2RPN(inputStr);
    printf("%s\n", inputStr);



    RETURN popElement = PopStack(pStackArray);

    while (EMPTY != popElement.result)
    {
        if (SIGN == popElement.output.tag)
        {
            printf("%c", popElement.output.sign);

        }
        else if (NUM == popElement.output.tag)
        {
            printf("%d", popElement.output.val);
        }

        popElement = PopStack(pStackArray);


    }


    return 1;
}
