#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"stack_array.h"
#include<string.h>

// Use array to make stack

#define SIGN_NUM 6
char sign[SIGN_NUM] = {'+', '-', '*', '/', '(', '^'};

static int findSignIdx(char signInput)
{
    int idx = 0;
    int resultIdx = 6;//ex : 'EMPTY' or ')'

    for (idx = 0; idx < SIGN_NUM; idx++)
    {
        if (sign[idx] == signInput)
        {
            resultIdx = idx;
        }
    }
    return resultIdx;
}

// [a][b] mean sign[a] compare sign[b] and result 1 mean sign[a] >= sign[b], result 0 sign[a] < sign[b]
int compareSignPriority[7][7] =
{
    {1, 1, 0, 0, 0, 0,  1},
    {1, 1, 0, 0, 0, 0,  1},
    {1, 1, 1, 1, 0, 0,  1},
    {1, 1, 1, 1, 0, 0,  1},
    {0, 0, 0, 0, 0, 0, -1},
    {1, 1, 1, 1, 0, 1,  1},
    {0, 0, 0, 0, 0, 0,  1}
};

static int priorityString(char stackIn, char stackOut)
{
    int stackInIdx  = findSignIdx(stackIn);
    int stackOutIdx = findSignIdx(stackOut);
    int ret = compareSignPriority[stackInIdx][stackOutIdx];

    return ret;

}

PSTACK_ARRAY_T ParserStringInfix2RPN(char *stringInput)
{
    //example : 2*(9+6/3-5)+4 , Output:2963/+5-*4+
    char *Ouptut = (char *) malloc(MAX_SIZE);
    PSTACK_ARRAY_T pStackALL = CreatStackArray();
    PSTACK_ARRAY_T pStackSaveSign = CreatStackArray();
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
            //Collection Number then push in Stack directily.
            if ((firstNumIdx <= lastNumIdx) && (0 <= firstNumIdx))
            {
                //Output value
                ELEMENT_TYPE valType;
                char cpStr[STR_NUM_MAX_SIZE] = "\0";
                int pushNum;
                strncpy(cpStr, stringInput + firstNumIdx, lastNumIdx - firstNumIdx + 1);
                pushNum = atoi(cpStr);
                valType.tag = NUM;
                valType.val = pushNum;
                PushStack(pStackALL, valType);
                firstNumIdx = lastNumIdx = -1;

            }


            ELEMENT_TYPE signInStack, signOutStack;
            signOutStack.tag = SIGN;
            signOutStack.sign = strCheck;
            int comCondtion;
            do
            {

                RETURN topElement = StackTop(pStackSaveSign);
                signInStack.tag = SIGN;
                signInStack.sign = topElement.output.sign;

                printf("Stackin %c\n", signInStack.sign);
                printf("StackOut %c\n", signOutStack.sign);

                comCondtion = priorityString(signInStack.sign, signOutStack.sign);
                printf("condtion = %d\n", comCondtion);

                RETURN willPushStack;
                switch ( comCondtion )
                {
                    //      <
                    case LESS_THAN :
                        PushStack(pStackSaveSign, signOutStack);
                        break;
                    //      >=
                    case GREATHER_THAN_OR_EQUAL :
                        willPushStack = PopStack(pStackSaveSign);
                        if (EMPTY == willPushStack.result)
                            printf("Input Format is error\n");
                        else
                        {
                            PushStack(pStackALL, willPushStack.output);
                        }
                        break;
                    //  '(' encouter ')'
                    case DISCARD :
                        willPushStack = PopStack(pStackSaveSign);
                        break;

                }

            } while(GREATHER_THAN_OR_EQUAL == comCondtion);

            firstNumIdx = ++idx;
            strCheck = stringInput[idx];
        }



    }
    if (firstNumIdx != -1)
    {
                ELEMENT_TYPE valType;
                char cpStr[STR_NUM_MAX_SIZE] = "\0";
                int pushNum;
                strncpy(cpStr, stringInput + firstNumIdx, lastNumIdx - firstNumIdx + 1);
                pushNum = atoi(cpStr);
                valType.tag = NUM;
                valType.val = pushNum;
                PushStack(pStackALL, valType);
    }

    // the lsat Sign in StackSing will push to StackAll
   RETURN willPushStack = PopStack(pStackSaveSign);

   while (EMPTY != willPushStack.result)
   {
       PushStack(pStackALL, willPushStack.output);
       willPushStack = PopStack(pStackSaveSign);
   }

    return pStackALL;
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
