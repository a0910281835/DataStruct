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

extern PQUEUE_ARRAY_T ParserStringInfix2RPN(char *stringInput);

#endif
