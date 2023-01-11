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


    printf("--------Travel Start----------\n");
    TravelBinTree(pHead, IN_ORDER);
    printf("--------Travel End------------\n");


    PSTACK_ARRAY_T pStack = CreatStackArray(sizeof(char));
    printf("stack size = %d, %d %d\n", pStack->size, (int)sizeof(char), (int)sizeof(int));
    int a =1001;

    InsertStackElement(pStack, sizeof(char), 3, &a);
    printf("%d", *((char*)pStack->pStackCell + 3));
    /*
    DECIDE_T decideIdx = IsEmptyStack(pStack);
    printf("stack is empty : %s\n", (array[decideIdx]));
    PushStack(pStack, 5);
    NUM_T num = SizeStack(pStack);
    printf("Stack size %d\n", num);
    PushStack(pStack, 6);
    num = SizeStack(pStack);
    printf("Stack size %d\n", num);
    int output = StackTop(pStack);
    printf("Seek Stack Element : %d\n", output);
    num = SizeStack(pStack);
    printf("Stack size %d\n", num);
    output = PopStack(pStack);
    printf("Pop Stack Element : %d\n", output);
    num = SizeStack(pStack);
    printf("Stack size %d\n", num);
    output = PopStack(pStack);
    printf("Pop Stack Element : %d\n", output);
    num = SizeStack(pStack);
    printf("Stack size %d\n", num);
    decideIdx = IsEmptyStack(pStack);
    printf("stack is empty : %s\n", (array[decideIdx]));
*/


    return 1;
}
