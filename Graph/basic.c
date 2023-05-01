#include "basic.h"

void PrintfCustomElement(CUSTOM_ELEMENT_TYPE element)
{
    printf("%d\n", element);
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
