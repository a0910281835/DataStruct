#ifndef _H_BASIC
#define _H_BASIC
#include"config.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define MAX_SIZE 1000
#define EMPTY_SIZE -1
#define STR_NUM_MAX_SIZE 30


# if defined(_ELEMENT_TYPE_UNION)
typedef enum
{
    SIGN,
    NUM
}TAG_TYPE;

enum
{
    DISCARD   = -1,// '(' enocuter ')'
    LESS_THAN = 0,
    GREATHER_THAN_OR_EQUAL = 1
};
typedef struct ELEMENT_TYPE
{
    union
    {
        char sign;
        int val;
    };
    TAG_TYPE tag;


}ELEMENT_TYPE;
# elif defined(_ELEMENT_TYPE_INT)
typedef  int ELEMENT_TYPE;
# endif

typedef enum
{
    EMPTY,
    SUCC
}CELL_SIZE;

typedef struct RETURN
{
    ELEMENT_TYPE output;
    CELL_SIZE result;
}RETURN;

#endif
