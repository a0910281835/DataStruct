#include<stdio.h>
#include<stdlib.h>


typedef struct PolyNode_T *polynomial;
typedef struct PolyNode_T
{
    polynomial link;
    int coef;
    int expon;
} PolyNode_T;

int main(void)
{

    //PolyNode_T array;
    //PolyNode_T* head1 = malloc(sizeof(PolyNode_T));
    //head1->coef = 5;
    polynomial head2 = malloc(sizeof(PolyNode_T));
    //PolyNode_T* head2;
    //head2 = malloc(1*sizeof(PolyNode_T));
    printf("%d", (int)sizeof(head2));
    head2->coef = 5;
    //head->link = NULL;

    return 1;
}
