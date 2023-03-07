#ifndef _H_BASIC
#define _H_BASIC
#include"config.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define STR_NUM_MAX_SIZE 30

// Basic Operation can put basic.c
typedef int CUSTOM_ELEMENT_TYPE;


typedef enum
{
    NO,
    YES
}DECIDE_T;

typedef enum
{
    EMPTY_SIZE = 0,
    MAX_SIZE = 1024 // 2^10
}SIZE_STATE_T;

typedef enum
{
    INPUT_CPY_TO_STACK,
    STACK_CPY_TO_OUTPUT
}CPY_MODE_T;

#define NUM_T int

extern void PrintfCustomElement(CUSTOM_ELEMENT_TYPE element);
extern void memcpyMySelf(void *cpyAddr, void *beCpyAddr, size_t cpyByteNum);
#endif
