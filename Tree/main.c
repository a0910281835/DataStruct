#include "tree.h"
#include "stack_array.h"
#include "queue_array.h"


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
    TravelBinTree(pHead, BREADTH_ORDER);
    printf("--------Travel End------------\n");



    /*
    char *d = malloc(sizeof(char));
    P_QUEUE_ARRAY_T pQueue = CreatQueueArray(sizeof(char));
    char a = 7;
    char b = 11;
    char c = 13;
    DECIDE_T decide = IsEmptyQueue(pQueue);
    printf("IS empty : %s\n", array[decide]);
    printf("Size = %d\n", (int) pQueue->sizeofObj);
    PushQueue(pQueue, &a);
    PushQueue(pQueue, &b);
    decide = IsEmptyQueue(pQueue);
    printf("IS empty : %s\n", array[decide]);
    PopQueue(pQueue, d);
    printf("%d\n", *d);
    PushQueue(pQueue, &a);
    PushQueue(pQueue, &c);
    PopQueue(pQueue, d);
    printf("%d\n", *d);
    PopQueue(pQueue, d);
    printf("%d\n", *d);
    PopQueue(pQueue, d);
    printf("%d\n", *d);
    PopQueue(pQueue, d);
    printf("%d\n", *d);
    PSTACK_ARRAY_T pStack = CreatStackArray(sizeof(int));
    printf("stack size = %d, %d  %d %d\n", SizeStack(pStack), (int)sizeof(char), (int)sizeof(short),  (int)sizeof(int));
    int a = 0x12345678;
    int b = 0;

    memcpyInStack(pStack, &a, 3, INPUT_CPY_TO_STACK);
    PushStack(pStack, &a);
    printf("stack size = %d, %d  %d %d\n", SizeStack(pStack), (int)sizeof(char), (int)sizeof(short),  (int)sizeof(int));

    printf("%2x\n", *((char*)pStack->pStackBox + 12));
    printf("%1x\n", *((char*)pStack->pStackBox + 13));
    printf("%1x\n", *((char*)pStack->pStackBox + 14));
    printf("%2x\n", *((char*)pStack->pStackBox + 0));
    printf("%1x\n", *((char*)pStack->pStackBox + 1));
    printf("%1x\n", *((char*)pStack->pStackBox + 2));
    StackTop(pStack, &b);
    printf("stack size = %d, %d  %d %d\n", SizeStack(pStack), (int)sizeof(char), (int)sizeof(short),  (int)sizeof(int));
    printf("b = %8x\n", b);
    b = 223;
    printf("b = %8x\n", b);
    PopStack(pStack, &b);
    printf("stack size = %d, %d  %d %d\n", SizeStack(pStack), (int)sizeof(char), (int)sizeof(short),  (int)sizeof(int));
    printf("b = %8x\n", b);
    printf("sizeofObj = %d\n", (int)sizeof(P_BINNODE_T));
    printf("sizeofObj = %d\n", (int)sizeof(int *));

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
