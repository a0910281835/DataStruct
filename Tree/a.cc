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


void THREAD_LIST :: InsertSleepList(THREAD *pThread, int sleepTiming)
{
    // Construct  Node to Insert 
    THREAD_NODE *pNode = new THREAD_NODE(pThread, sleepTiming);

    //
     if (IsEmpty())
     {
         pHead = pNode;
         pTail = pNode;
     }
     else
     {
        THREAD_NODE *pCurrent = pTail;
        bool keepFindFlag = (pCurrent->when > pNode->when) ? true : false;

        while (keepFindFlag)
        {
            if (pCurrent->prev != NULL)
            {
                pCurrent = pCurrent->prev;
            }
            else
            {
                break;
            }

            keepFindFlag = (pCurrent->when > pNode->when) ? true : false;
        }

        // list has someone priority > you !
        if (!keepFindFlag)
        {
            if (pCurrent->next != NULL)
            {
                (pCurrent->next)->prev = pNode;
                pNode->next = (pCurrent->next);

            }
            pCurrent->next = pNode; 
            pNode->prev = pCurrent;
        }
        else
        {
            pCurrent->prev = pNode;
            pNode->next = pCurrent;
            pHead = pNode;
        }

     }

}

THREAD* THREAD_LIST :: PopWaittingQueue(void)
{
    THREAD_NODE* pPopNode = pHead;
    THREAD * pThread = NULL;
    if (!IsEmpty())
    {
        pThread = pHead->thread;
        pHead = pHead->next;
        pPopNode->next = NULL;
        if (pHead == NULL)
        {
            pTail = NULL;
        }
        else
        {
            pHead->prev = NULL;
        }
        delete pPopNode;
    }

    return pThread;
}

void THREAD_LIST :: TravelWatingQueue()
{
    if (IsEmpty())
    {
        cout << "Waiting queue is empty now !" << endl;
    }
    else
    {
        THREAD_NODE * pTravelNode = pHead;

        while (pTravelNode != NULL)
        {
            cout << "travel point timing : " <<  pTravelNode->when << " with PID : " << *(pTravelNode->thread) << endl;
            pTravelNode = pTravelNode->next;
        }
    }
}

typedef int PID;
int main(void)
{



    THREAD_LIST *pWaitQueue = new THREAD_LIST();

    PID a = 3;
    PID b = 5;
    PID c = 20;

    pWaitQueue->InsertSleepList(&b, 19);
    pWaitQueue->InsertSleepList(&a, 4);
    pWaitQueue->InsertSleepList(&c, 3);
    pWaitQueue->TravelWatingQueue();

    PID *pTr = pWaitQueue->PopWaittingQueue();
    cout << "Pop PID : " << *pTr << endl;
    pWaitQueue->TravelWatingQueue();

    pTr = pWaitQueue->PopWaittingQueue();
    cout << "Pop PID : " << *pTr << endl;
    pWaitQueue->TravelWatingQueue();

    pTr = pWaitQueue->PopWaittingQueue();
    cout << "Pop PID : " << *pTr << endl;
    pWaitQueue->TravelWatingQueue();

}
