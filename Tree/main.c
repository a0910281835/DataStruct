#include "tree.h"
#include "tree_application.h"
#include "stack_array.h"
#include "queue_array.h"


char *(array[2]) = {"NO", "YES" };



int main(void)
{

    BINTREE_HEAD pHead  = NULL;
    P_BINNODE_T current = NULL;

    //       5
    //     2   15
    //        10  19
    //       6   17 23
    //        9   18
    InsertValBinNode(pHead, 5);
    InsertValBinNode(pHead->left, 100);
    InsertValBinNode(pHead->right, 15);
    printf("val: %d, %d, %d\n", pHead->val, (pHead->left)->val, (pHead->right)->val);
    current = pHead->right;
    InsertValBinNode(current->right, 19);
    InsertValBinNode(current->left, 10);
    //printf("val: %d, %d, %d\n", pHead->val, (pHead->left)->val, (pHead->right)->val);


    printf("--------Travel Start----------\n");
    TravelBinTree(pHead, IN_ORDER);
    //TravelBinTree(pHead, PRE_ORDER);
    printf("--------Travel End------------\n");

    TRAVSAL_T preorder, inorder ;
    preorder.travlMode = PRE_ORDER;
    preorder.length = 5;
    preorder.elementArray = malloc(sizeof(CUSTOM_ELEMENT_TYPE) * 5);
    CUSTOM_ELEMENT_TYPE *pElement = preorder.elementArray;
    pElement[0] = 4;
    pElement[1] = 9;
    pElement[2] = 7;
    pElement[3] = 3;
    pElement[4] = 10;

    inorder.travlMode = IN_ORDER;
    inorder.length = 5;
    inorder.elementArray = malloc(sizeof(CUSTOM_ELEMENT_TYPE) * 5);
    pElement = inorder.elementArray;
    pElement[0] = 9;
    pElement[1] = 4;
    pElement[2] = 3;
    pElement[3] = 7;
    pElement[4] = 10;


    pElement = preorder.elementArray;
    int idx = 0;
    for (idx = 0; idx < 5; idx++)
    {
        printf("%2d ", *(pElement + idx));

    }

    BINTREE_HEAD pHead2 = CreateTree(&preorder, &inorder);
    printf("--------Travel Start----------\n");
    TravelBinTree(pHead2, IN_ORDER);
    TravelBinTree(pHead2, PRE_ORDER);
    printf("--------Travel End------------\n");




    current = FindElementInBST(pHead, 15);
    printf("check : %2d\n", current->val);
    current = TakeMaxInBST(pHead);
    printf("check : %2d\n", current->val);
    P_BST_HEAD_T pHead3 = InsertElementInBST(pHead, 17);
    pHead3 = InsertElementInBST(pHead3, 23);
    pHead3 = InsertElementInBST(pHead3, 6);
    pHead3 = InsertElementInBST(pHead3, 9);
    pHead3 = InsertElementInBST(pHead3, 18);
    printf("--------Travel BST Start----------\n");
    printf("Inorder:\n");
    TravelBinTree(pHead3, IN_ORDER);
    printf("Preorder:\n");
    TravelBinTree(pHead3, PRE_ORDER);
    printf("Breathorder:\n");
    TravelBinTree(pHead3, BREADTH_ORDER);
    printf("--------Travel BST End------------\n");

    printf("Delete 10\n");
    DeleteElementInBST(pHead3, 10);
    printf("Breathorder:\n");
    TravelBinTree(pHead3, BREADTH_ORDER);


   CUSTOM_ARRAY_T* output =  BreadthOrderAndOuputArray(pHead3);
   printf("Size = %2d\n", output->current_num);

   for (idx = 0; idx < (output->current_num); idx++)
   {
       printf("%2d\n", output->array[idx]);
   }
   DECIDE_T decide = IsBSTTree(pHead3);
   decide = IsBSTTreeByRecursive(pHead3);
   printf("%s\n", array[decide]);
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
