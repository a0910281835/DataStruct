#include "tree.h"
#include "stack_array.h"


char *(array[2]) = {"NO", "YES" };



int main(void)
{

    BINTREE_HEAD pHead  = NULL;
    P_BINNODE_T current = NULL;


    InsertValBinNode(pHead, 5);
    InsertValBinNode(pHead->left, 9);
    InsertValBinNode(pHead->right, 7);
    printf("val: %d, %d, %d\n", pHead->val, (pHead->left)->val, (pHead->right)->val);
    current = pHead->right;
    InsertValBinNode(current->right, 10);
    InsertValBinNode(current->left, 3);
    //printf("val: %d, %d, %d\n", pHead->val, (pHead->left)->val, (pHead->right)->val);
    printf("val: %d, %d, %d %d %d\n", pHead->val, (pHead->left)->val, (pHead->right)->val, ((pHead->right)->right)->val, ((pHead->right)->left)->val);


    printf("--------------------\n");
    TravelBinTree(pHead, IN_ORDER);


    PSTACK_ARRAY_T pStack = CreatStackArray();
    DECIDE_T decideIdx = IsEmptyStack(pStack);
    printf("stack is empty : %s\n", (array[decideIdx]));
    PushStack(pStack, 5);
    NUM_T num = SizeStack(pStack);
    printf("Stack size %d\n", num);


    return 1;
} 
