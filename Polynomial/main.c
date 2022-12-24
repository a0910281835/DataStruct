#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include "polynomial_struct.h"
#define ZERO 0





NONZERO_TERM_T polynomailSeq[5] =
{
    {.coef = 4, .expon = 10},
    {.coef = 2, .expon = 7},
    {.coef = 5, .expon = 6},
    {.coef = 100, .expon = 2},
    {.coef = 20, .expon = 0},

};
NONZERO_TERM_T polynomailSeq2[5] =
{
    {.coef = 5, .expon = 11},
    {.coef = 1, .expon = 8},
    {.coef = 5, .expon = 6},
    {.coef = 100, .expon = 1},
    {.coef = 20, .expon = -5},

};




POLY_LINK_HEAD PolayArrayTransPolayLink(PolyArray_T *pPolynomialArray)
{
    int size = pPolynomialArray->totalTerm;
    int idx = 0;

    POLY_LINK_HEAD pLinkHead = NULL;
    POLYNODE_T * pPolynode[size];

    POLYNODE_T* lastTerm = NULL;
    //Create Polynomial from small term to max term
    for (idx = size - 1; idx >= 0; idx--)
    {
        pPolynode[idx] = malloc(sizeof(POLYNODE_T));
        (pPolynode[idx]->term).coef = pPolynomialArray->polyArray[idx].coef;
        (pPolynode[idx]->term).expon = pPolynomialArray->polyArray[idx].expon;
        pPolynode[idx]->link = lastTerm;
        lastTerm = pPolynode[idx];
    }
    lastTerm = NULL;
    pLinkHead = pPolynode[0];

    return pLinkHead;

}


#ifdef _POLYNOMAIL_LINK
static void printfPolyUseLink(polynomial pLinkHead)
{
    if (pLinkHead == NULL)
    {
        printf("This polynomial is empty\n");
    }
    else
    {
        printf("%dx^%d ", (pLinkHead->term).coef, (pLinkHead->term).expon);
        pLinkHead = pLinkHead->link;
    }

    while (pLinkHead != NULL)
    {
        printf("+ %dx^%d ", (pLinkHead->term).coef, (pLinkHead->term).expon);
        pLinkHead = pLinkHead->link;
    }
    printf("\n");
}
#endif

# if defined( _POLYNOMAIL_ARRAY) && !defined(_POLYNOMAIL_LINK)
static void printfPolyUseArray(polynomial pArray)
{
    int size = pArray->totalTerm;
    int idx = 0;
    if (ZERO == size)
    {
        printf("This polynomial is empty\n");
    }
    else
    {
        printf(" %dx^%d ", pArray->polyArray[idx].coef, pArray->polyArray[idx].expon);
        for (idx = 1; idx < size; idx++)
        {
            printf(" + %dx^%d ", pArray->polyArray[idx].coef, pArray->polyArray[idx].expon);
        }
        printf("\n");

    }

}
# endif



void PrintfPolynomail(polynomial head)
{
#ifdef _POLYNOMAIL_LINK
    printfPolyUseLink(head);
#endif
# if defined( _POLYNOMAIL_ARRAY) && !defined(_POLYNOMAIL_LINK)
    printfPolyUseArray(head);
# endif
}

int PolynomailTotalTerm(polynomial head)
{
    int size = 0;
    P_POLYNODE_T node;

    if (NULL != head)
    {
        node = head;
        while (node != NULL)
        {
            size++;
            node = node->link;
        }

    }
    return size;

}

polynomial MulplePolynomial(polynomial head, polynomial head2)
{



}

// Use Link to practice
polynomial AddPolynomialByLink(polynomial pLinkHead, polynomial pLinkHead2)
{
    polynomial pLinkHead3;
    polynomial last, current;
    last = malloc(sizeof(POLYNODE_T));
    (last->term).coef = 0;
    (last->term).expon = INT_MAX;
    pLinkHead3 = last;

    // Compare two order sequence
    while (pLinkHead != NULL && pLinkHead2 != NULL)
    {
        int compVal1, compVal2;
        compVal1 = (pLinkHead->term).expon;
        compVal2 = (pLinkHead2->term).expon;
        current = malloc(sizeof(POLYNODE_T));
        last->link = current;

        if (compVal1 > compVal2)
        {
            (current->term).coef = (pLinkHead->term).coef;
            (current->term).expon = compVal1;
            pLinkHead = pLinkHead->link;
        }
        else if (compVal2 > compVal1)
        {
            (current->term).coef = (pLinkHead2->term).coef;
            (current->term).expon = compVal2;
            pLinkHead2 = pLinkHead2->link;
        }
        else
        {
            (current->term).coef = ((pLinkHead->term).coef + (pLinkHead2->term).coef);
            pLinkHead = pLinkHead->link;
            pLinkHead2 = pLinkHead2->link;

            if (ZERO == (current->term).coef)
            {
                free(current);
                current = NULL;
                continue;
            }
            else
            {
                (current->term).expon = compVal1;
            }


        }

        last = current;
    }

    if (pLinkHead2 != NULL)
    {
        pLinkHead = pLinkHead2;
    }

    while (pLinkHead != NULL)
    {
        current = malloc(sizeof(POLYNODE_T));
        last->link = current;
        last = current;
        (current->term).coef = (pLinkHead->term).coef;
        (current->term).expon = (pLinkHead->term).expon;
        pLinkHead = pLinkHead->link;
    }

    current->link = NULL;
    last = pLinkHead3;
    pLinkHead3 = pLinkHead3 ->link;
    last->link = NULL;
    free(last);
    return pLinkHead3;



}


int* parserTwoPart(char *str)
{
    int *array = malloc(sizeof(int)*2);
    array[0] = INT_MAX;
    array[1] = INT_MAX;
    int count[3] = {-1, -1, -2};
    int totalLenth = (int)strlen(str);
    int idx = 1;
    int time = 0;

    if (str[1] != '-')
    {
        count[0] = 1;
        idx = 2;
        time = 1;

    }
    // Record The first num and Second Num
    while ('\0' != str[idx])
    {
        if (('+' == str[idx]) || ('-' == str[idx]))
        {
            count[time++] = idx;
        }
        idx++;
    }
    char strarray[100];
    int cpyLength = 0;
    idx = 0;
    while (-1 < count[idx])
    {
        if (count[idx+1] - count[idx] < 0)
        {
            cpyLength = totalLenth - count[idx];
        }
        else
        {
            cpyLength = count[idx+1] - count[idx];
        }
        strncpy(strarray, str + count[idx], cpyLength);
        array[idx] = atoi(strarray);

        idx++;
    }


    return array;

}




PolyArray_T* ParserStr2Polynomial(char *str)
{
    PolyArray_T* pPolynomialArray;
    pPolynomialArray = malloc(sizeof(PolyArray_T));


    //Descript :
    //Example : 2x^5+3x^3-2x^2+7x^0;
    if (str == NULL)
    {
        printf("it's empty\n");
    }
    else
    {
        const char* pch = "x";
        char *ptch;

        int totalNum = 0;
        int idx = 0;
        NONZERO_TERM_T arrayTerm[100];
        ptch = strtok(str, pch);
        while (ptch != NULL)
        {
            idx = totalNum++;
            printf("idx = %d\n", idx);
            if (idx == 0)
            {
                printf("here is first\n");
                char str[100];
                strcpy(str, ptch);
                int val = atoi(str);
                printf("val %d\n", val);
                ptch = strtok(NULL, pch);
                arrayTerm[idx].coef = val;

                continue;
            }
            int *array = parserTwoPart(ptch);
            printf("%s\n", ptch);
            printf("expon:%d, coef:%d\n", array[0], array[1]);
            arrayTerm[idx].coef = array[1];
            arrayTerm[idx-1].expon = array[0];

            ptch = strtok(NULL, pch);
            //if( ptch == NULL)
            //{
            //    printf("this is last");
            //}

        }
        //printf("totalcnt : %d\n", idx);
        pPolynomialArray->totalTerm = idx;
        pPolynomialArray->polyArray = malloc(sizeof(NONZERO_TERM_T) * idx);

        for (idx = 0; idx < pPolynomialArray->totalTerm; idx++)
        {
            pPolynomialArray->polyArray[idx].coef  = arrayTerm[idx].coef;
            pPolynomialArray->polyArray[idx].expon = arrayTerm[idx].expon;
            //printf("idx:%d, coef:%d, expon:%d\n", idx, pPolynomialArray->polyArray[idx].coef, pPolynomialArray->polyArray[idx].expon);
        }

    }

    return pPolynomialArray;
}
#define ARB 100
int main(void)
{
    char str[ARB] = "5x^10+4x^3-7x^2-5x^0+3x^-2-100x^-11";
    char str2[ARB] = "27x^4+3x^2-6x^1+5x^0";
    printf("orrigin string: %s\n", str);
    printf("orrigin string: %s\n", str2);
    char strCp[ARB];
    strncpy(strCp, str, ARB);

    int idx = 0;
    PolyArray_T * pPolynomialArray = ParserStr2Polynomial(strCp);
    PolyArray_T * pPolynomialArray1 = ParserStr2Polynomial(str2);

    //PolyNode_T array;
    //PolyNode_T* head1 = malloc(sizeof(PolyNode_T));
    //head1->coef = 5;
    polynomial head2, head3, head4;
    head2 = PolayArrayTransPolayLink(pPolynomialArray);
    head3 = PolayArrayTransPolayLink(pPolynomialArray1);
    head4 = AddPolynomialByLink(head2, head3);
    int size = PolynomailTotalTerm(head4);
    printf("total term : %d\n", size);
    printf("idx:%d, coef:%d, expon:%d\n", idx, pPolynomialArray->polyArray[idx].coef, pPolynomialArray->polyArray[idx].expon);
    free(pPolynomialArray->polyArray);
    free(pPolynomialArray1->polyArray);
    printf("idx:%d, coef:%d, expon:%d\n", idx, pPolynomialArray->polyArray[idx].coef, pPolynomialArray->polyArray[idx].expon);
    free(pPolynomialArray);
    free(pPolynomialArray1);

    PrintfPolynomail(head2);
    PrintfPolynomail(head3);
    PrintfPolynomail(head4);

    free(head2);
    free(head3);

    return 1;
}
