#ifndef _H_A
#define _H_A

typedef int THREAD;

class THREAD_NODE
{
    public :
        THREAD_NODE(THREAD *pT) : thread(pT), prev(NULL), next(NULL) {};
        THREAD* thread;
        THREAD_NODE *prev;
        THREAD_NODE *next;
};

class THREAD_LIST
{
    public :
        THREAD_LIST();
        THREAD_NODE * pHead;
        THREAD_NODE * pTail;
        bool IsEmpty();
};






#endif
