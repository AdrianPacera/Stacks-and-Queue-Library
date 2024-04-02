#ifndef __MYSTACKH__
#define __MYSTACKH__

#include <cstddef>

typedef struct stackObject
{   
    void* obj;
    struct stackObject *next;
} StackObject_t;

class Stack{
    private:
        StackObject_t *stack;
        size_t objsize;
        int numelem;

    public:
        
        Stack(size_t objsize);
        ~Stack();

        int mystack_push(void* obj);

        int mystack_pop(void* obj);

        int mystack_nofelem();


};

#endif
