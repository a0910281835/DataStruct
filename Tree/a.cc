#include <iostream>
#include "a.h"
using namespace std;


THREAD_LIST :: THREAD_LIST()
{
    pHead = NULL;
    pTail = NULL;
}

bool THREAD_LIST :: IsEmpty()
{
    bool ret = false;
    if (pHead == NULL) ret = true;
    return ret;
}





int main(void)
{
    int *p = new int(4);
    cout << *p << endl;


    int a = 3;
    THREAD_NODE *pNode = new THREAD_NODE(&a);
    cout << *(pNode->thread) << endl;

    *(pNode->thread) = 5;
    cout << *(pNode->thread) << endl;





    THREAD_LIST *pWaitQueue = new THREAD_LIST();

    if (pWaitQueue->pHead == NULL)
        cout << "head is Null" << endl;
    if (pWaitQueue->pTail == NULL)
        cout << "Tail is Null" << endl;

    bool ret = false; 
    ret = pWaitQueue->IsEmpty();
    cout << ret << endl;
}
