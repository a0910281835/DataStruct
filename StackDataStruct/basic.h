#ifndef _H_BASIC
#define _H_BASIC
#include"config.h"

#define MAX_SIZE 1000
#define EMPTY_SIZE -1

# if defined(_ELEMENT_TYPE_UNION) 
typedef enum
{
    SIGN,
    NUM
}TAG_TYPE;
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
    ELEMENT_TYPE ouput;
    CELL_SIZE result;
}RETURN;

#endif
