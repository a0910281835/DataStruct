#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>


typedef struct PolyNode_T *polynomial;

typedef struct NONZERO_TERM *nonzero_term;

typedef struct
{
    int coef;
    int expon;
}NONZERO_TERM;

typedef struct PolyNode_T
{
    polynomial link;
    //int coef;
    //int expon;
    NONZERO_TERM term;
}POLYNODE_T;



NONZERO_TERM polynomailSeq[5] =
{
    {.coef = 4, .expon = 10},
    {.coef = 2, .expon = 7},
    {.coef = 5, .expon = 6},
    {.coef = 100, .expon = 2},
    {.coef = 20, .expon = 0},

};
NONZERO_TERM polynomailSeq2[5] =
{
    {.coef = 5, .expon = 11},
    {.coef = 1, .expon = 8},
    {.coef = 5, .expon = 6},
    {.coef = 100, .expon = 1},
    {.coef = 20, .expon = -5},

};




// Easy Make Polynomail
polynomial PolyInital(NONZERO_TERM* pPolySeq, int Size)
{
    polynomial head[Size];
    int idx = 0;
    for (idx = 0; idx < Size; idx++)
    {
        head[idx] = malloc(sizeof(POLYNODE_T));
        (head[idx]->term).coef = pPolySeq[idx].coef;
        (head[idx]->term).expon = pPolySeq[idx].expon;

    }

    head[Size-1]->link = NULL;

    for (idx = Size - 2; idx >= 0; idx--)
    {
        head[idx]->link = head[idx + 1];
    }
    //headI
    return head[0];

}

void PrintfPolynomail(polynomial head)
{
    if (head == NULL)
    {
        printf("This polynomial is empty\n");
    }
    else
    {
        printf("%dx^%d ", (head->term).coef, (head->term).expon);
        head = head->link;
    }

    while (head != NULL)
    {
        printf("+ %dx^%d ", (head->term).coef, (head->term).expon);
        head = head->link;
    }
    printf("\n");

}

polynomial AddPolynomial(polynomial head, polynomial head2)
{
    polynomial head3;
    polynomial last, current;
    last = malloc(sizeof(POLYNODE_T));
    (last->term).coef = 0;
    (last->term).expon = INT_MAX;
    head3 = last;

    // Compare two order sequence
    while (head != NULL && head2 != NULL)
    {
        int compVal1, compVal2;
        compVal1 = (head->term).expon;
        compVal2 = (head2->term).expon;
        current = malloc(sizeof(POLYNODE_T));
        last->link = current;
        last = current;

        if (compVal1 > compVal2)
        {
            (current->term).coef = (head->term).coef;
            (current->term).expon = compVal1;
            head = head->link;
        }
        else if (compVal2 > compVal1)
        {
            (current->term).coef = (head2->term).coef;
            (current->term).expon = compVal2;
            head2 = head2->link;
        }
        else
        {
            (current->term).coef = ((head->term).coef << 1);
            (current->term).expon = compVal1;
            head = head->link;
            head2 = head2->link;

        }
    }

    if (head2 != NULL)
    {
        head = head2;
    }

    while (head != NULL)
    {
        current = malloc(sizeof(POLYNODE_T));
        last->link = current;
        last = current;
        (current->term).coef = (head->term).coef;
        (current->term).expon = (head->term).expon;
        head = head->link;
    }

    current->link = NULL;
    last = head3;
    head3 = head3 ->link;
    last->link = NULL;
    free(last);
    return head3;



}


//nonzero_term 
void ParserStr2Polynomial(char *str)
{
    //Descript :
    //Example : 2x^5+3x^3-2x^2+7x^0;
    char str1[50];
    printf("enter your polynomial : ");
    fgets(str1, 50, stdin);
    printf("Output : %s", str1);
    if (str == NULL)
    {
        printf("it's empty\n");
    }
    else
    {
        printf("%s,", str);
    }

}
#define ARB 100
int main(void)
{
    char str[ARB] = "5x^3+4x^2-7x^0";
    int idx = 0;
    ParserStr2Polynomial(str);

    //PolyNode_T array;
    //PolyNode_T* head1 = malloc(sizeof(PolyNode_T));
    //head1->coef = 5;
    polynomial head2, head3, head4;
    head2 = PolyInital(polynomailSeq, 5);
    head3 = PolyInital(polynomailSeq2, 5);

    printf("%dx^%d\n", (head2->term).coef, (head2->term).expon);
    PrintfPolynomail(head2);
    PrintfPolynomail(head3);
    head4 = AddPolynomial(head2, head3);
    PrintfPolynomail(head4);

    free(head2);
    free(head3);

    return 1;
}
