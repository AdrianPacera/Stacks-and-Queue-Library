#ifndef __MYQUEUEH__
#define __MYQUEUEH__

#include "mystack.h"
#include <cstddef>

class Queue{
    private:
        Stack stack_in;
        Stack stack_out;
        size_t item_size;
    public:
        Queue(int size);
        ~Queue();

        int myqueue_enqueue(void *obj);

        int myqueue_dequeue(void *obj);
};

#endif
