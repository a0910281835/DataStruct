#include "tree.h"


char *(array[2]) = {"FAIL", "SUCC" };

#define InsertSelf(A,v) { (A) = InsertValBinNode((A),(v)) ;}

int main(void)
{

    BINTREE_HEAD pHead;
    P_BINNODE_T current;


    pHead = InsertValBinNode(pHead, 5);
    pHead->left = InsertValBinNode(pHead->left, 6);
    InsertSelf(pHead->left, 9);
    pHead->right = InsertValBinNode(pHead->right, 7);


    printf("val: %d, %d, %d\n", pHead->val, (pHead->left)->val, (pHead->right)->val);

    return 1;
}
