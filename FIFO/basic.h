#ifndef _H_BASIC
#define _H_BASIC

#define MAX_SIZE 100
typedef int ELEMENT_T;

typedef enum
{
    EMPTY,
    SUCC,
    FULL = (MAX_SIZE - 1)
}SIZE_CONDITION;

typedef struct RETRURN
{
    SIZE_CONDITION size_cond;
    ELEMENT_T output;

}RETURN;

#endif
