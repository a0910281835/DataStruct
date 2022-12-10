#ifndef _H_PASER_INFIX_AND_CAL
#define _H_PASER_INFIX_AND_CAL
#include"basic.h"
#include"stack_array.h"
#include"queue_array.h"
#define SIGN_NUM 6

enum
{
    DISCARD   = -1,// '(' enocuter ')'
    LESS_THAN = 0,
    GREATHER_THAN_OR_EQUAL = 1
};

typedef int (*FP_OPERAND_T)(int * arrayNum);

extern PQUEUE_ARRAY_T ParserStringInfix2RPN(char *stringInput);
extern int AddOperand(int* arrayNum);
extern int MinusOperand(int* arrayNum);
extern int MutOperand(int* arrayNum);
extern int DividOperand(int* arrayNum);
extern int rightParOperand(int* arrayNum);
extern int PowerOperand(int* arrayNum);
extern int CalRPN(PQUEUE_ARRAY_T pRPNQueue);

#endif
