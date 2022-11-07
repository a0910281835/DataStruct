#include<stdio.h>
#include<stdlib.h>


typedef struct PolyNode_T *polynomial;
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

int main(void)
{

    //PolyNode_T array;
    //PolyNode_T* head1 = malloc(sizeof(PolyNode_T));
    //head1->coef = 5;
    polynomial head2;
    head2 = PolyInital(polynomailSeq, 5);

    printf("%dx^%d\n", (head2->term).coef, (head2->term).expon);
    PrintfPolynomail(head2);

    free(head2);

    return 1;
}
