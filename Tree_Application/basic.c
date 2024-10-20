#include "basic.h"

void PrintfCustomElement(CUSTOM_ELEMENT_TYPE element)
{
#if defined(_ELEMENT_TYPE_IS_INT)
    printf("%d\n", element);
#elif defined(_ELEMENT_TYPE_IS_STRING)
    printf("%s\n", element);
#endif
}

// Further more, you can determine cpyBytes is even or odd. which can be divid by 8 or 4 or 2
void memcpyMySelf(void *cpyAddr, void *beCpyAddr, size_t cpyByteNum)
{
    int idx  = 0;

    for (idx = 0; idx < cpyByteNum; idx++)
    {
        *((char *)cpyAddr++) = *((char *)beCpyAddr++);
    }
}
