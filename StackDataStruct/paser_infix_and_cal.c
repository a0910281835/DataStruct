#include"paser_infix_and_cal.h"

enum
{
    UNKNOW  = -1,
    UNARY   =  1,
    BINARY  =  2,
    TERNARY =  3
};

static char sign[SIGN_NUM] = {'+', '-', '*', '/', '(', '^'};


const FP_OPERAND_T fp_Operand[] =
{
    AddOperand,
    MinusOperand,
    MutOperand,
    DividOperand,
    rightParOperand,
    PowerOperand
};


int AddOperand(int *array)
{
    int ret = 0;

    ret = array[0] + array[1];
    printf(" %d + %d = %d\n ", array[0], array[1], ret);
    return ret;
}

int MinusOperand(int *array)
{
    int ret = 0;

    ret = array[0] - array[1];
    printf(" %d - %d = %d\n ", array[0], array[1], ret);
    return ret;
}

int MutOperand(int *array)
{
    int ret  = 0;

    ret = array[0] * array[1];
    printf(" %d * %d = %d\n ", array[0], array[1], ret);
    return ret;
}

int DividOperand(int *array)
{
    int ret  = 0;

    ret = array[0] / array[1];
    printf(" %d / %d = %d\n ", array[0], array[1], ret);
    return ret;
}

int rightParOperand(int *array)
{
    int ret  = 0;

    printf("error\n");
    return ret;
}

int PowerOperand(int *array)
{
    int ret  = 1;
    int totalTime = array[1];
    int idx = 0;

    for (idx = 0; idx < totalTime; idx++)
    {
        ret *= array[0];
    }
    printf(" %d ^ %d = %d\n ", array[0], array[1], ret);

    return ret;
}



static char operandNum[SIGN_NUM] = {2, 2, 2, 2, -1, 2};

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
static int CompareSignPriorityArray[7][7] =
{

    /* '+' */{1, 1, 0, 0, 0, 0,  1},
    /* '-' */{1, 1, 0, 0, 0, 0,  1},
    /* '*' */{1, 1, 1, 1, 0, 0,  1},
    /* '/' */{1, 1, 1, 1, 0, 0,  1},
    /* '(' */{0, 0, 0, 0, 0, 0, -1},
    /* '^' */{1, 1, 1, 1, 0, 1,  1},
    /* ''  */{0, 0, 0, 0, 0, 0,  1}
};




static int compareSignPriority(char stackIn, char stackOut)
{
    int stackInIdx  = findSignIdx(stackIn);
    int stackOutIdx = findSignIdx(stackOut);
    int ret = CompareSignPriorityArray[stackInIdx][stackOutIdx];

    return ret;

}

static int findOperandNum(char signInput)
{
    int retOperandNum = 0;
    int signIdx = findSignIdx(signInput);
    retOperandNum = operandNum[signIdx];

    return retOperandNum;
}




static int calNum(int * arrayNum, char sign)
{
    int operIdx = findSignIdx(sign);

    int ret = (*fp_Operand[operIdx])(arrayNum);

    return ret;

}

int CalRPN(PQUEUE_ARRAY_T pRPNQueue)
{
    int calVal = 0;
    PSTACK_ARRAY_T pStackNum = CreatStackArray();

    RETURN retPopQueue = PopQueueArray(pRPNQueue);
    int operNum = 0;
    char sign = 'a';
    int* arrayOperand = (int*) malloc(sizeof(int) * 3);
    RETURN retPopStack;

    while (SUCC == retPopQueue.result)
    {

        TAG_TYPE tag = (retPopQueue.output).tag;

        switch (tag)
        {
            case NUM :
                PushStack(pStackNum, retPopQueue.output);
                break;
            case SIGN :
                // sign and Calculate then save
                sign = retPopQueue.output.sign;
                operNum = findOperandNum(sign);
                int idx = 0;
                ELEMENT_TYPE fifoVal;

                for (idx = operNum; idx > 0; idx--)
                {
                    retPopStack = PopStack(pStackNum);
                    arrayOperand[idx - 1] = retPopStack.output.val;
                }
                fifoVal.val = calNum(arrayOperand, sign);
                fifoVal.tag = NUM;
                PushStack(pStackNum, fifoVal);
                break;
        }
        retPopQueue = PopQueueArray(pRPNQueue);
    }


    // Make sure the stack only one element
    retPopStack = PopStack(pStackNum);
    calVal = retPopStack.output.val;

    free(arrayOperand);
    arrayOperand = NULL;

    return calVal;

}

PQUEUE_ARRAY_T ParserStringInfix2RPN(char *stringInput)
{
    //example : 2*(9+6/3-5)+4 , Output:2963/+5-*4+
    PQUEUE_ARRAY_T pQueueNotation = CreateQueueArray();
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
                PushQueueArray(pQueueNotation, valType);
                firstNumIdx = lastNumIdx = -1;

            }


            // Loop compare Sign stack in and stack out
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

                comCondtion = compareSignPriority(signInStack.sign, signOutStack.sign);
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
                            PushQueueArray(pQueueNotation, willPushStack.output);
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
                PushQueueArray(pQueueNotation, valType);
    }

    // the lsat Sign in StackSing will push to StackAll
   RETURN willPushStack = PopStack(pStackSaveSign);

   while (EMPTY != willPushStack.result)
   {
       PushQueueArray(pQueueNotation, willPushStack.output);
       willPushStack = PopStack(pStackSaveSign);
   }

    return pQueueNotation;
}




