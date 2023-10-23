#ifndef _H_A
#define _H_A

typedef int THREAD;

class THREAD_NODE
{
    public :
        THREAD_NODE(THREAD *pT, int timing) : thread(pT), prev(NULL), next(NULL), when(timing) {};
        THREAD* thread;
        THREAD_NODE *prev;
        THREAD_NODE *next;
        int when;
};

class THREAD_LIST
{
    public :
        THREAD_LIST();
        THREAD_NODE * pHead;
        THREAD_NODE * pTail;
        bool IsEmpty();
        void InsertSleepList(THREAD *pThread, int sleepTiming);
        THREAD* PopWaittingQueue(void);
        void TravelWatingQueue();
};






#endif
