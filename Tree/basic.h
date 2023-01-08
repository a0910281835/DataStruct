#ifndef _H_BASIC
#define _H_BASIC
#include"config.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define STR_NUM_MAX_SIZE 30

// Basic Operation can put basic.c
typedef  int ELEMENT_TYPE;


typedef enum
{
    NO,
    YES
}DECIDE_T;

typedef enum
{
    EMPTY_SIZE = 0,
    MAX_SIZE = 1000
}SIZE_STATE_T;

#define NUM_T int 

#endif
