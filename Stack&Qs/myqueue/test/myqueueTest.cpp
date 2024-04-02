#include "gtest/gtest.h"
#include "myqueue.h"

TEST(MyqueueEnqueue, EnqueValue){

    //fix :
    Queue q(sizeof(int));

    int a = 1;
    void* ptr1 = &a;

    int pushOutcome = q.myqueue_enqueue(ptr1);

    int returnVal = -999;
    void* ptr2 = &returnVal;
    q.myqueue_dequeue(ptr2);

    EXPECT_EQ(0, pushOutcome);
    EXPECT_EQ(a, returnVal);

}

TEST(MyqueueEnqueue, EnqueueNULL){
    Queue q(sizeof(int));

    int pushOutcome = q.myqueue_enqueue(nullptr);

    EXPECT_EQ(-1, pushOutcome);
}

TEST(MyqueueDequeue, DequeueValue){
    Queue q(sizeof(int));

    int a = 1;
    int b = 1;
    int c = 1;
    int d = 1;

    q.myqueue_enqueue(&a);
    q.myqueue_enqueue(&b);
    q.myqueue_enqueue(&c);
    q.myqueue_enqueue(&d);

    int returnVal = -999;

    int dequeueResult = q.myqueue_dequeue(&returnVal);

    EXPECT_EQ(0, dequeueResult);
    EXPECT_EQ(d, returnVal);
}

TEST(MyqueueDequeue, DequeueEmpty){
    Queue q(sizeof(int));

    int returnVal = -999;

    int dequeueResult = q.myqueue_dequeue(&returnVal);

    EXPECT_EQ(-1, dequeueResult);
}   

TEST(MyqueueDequeue, DequeueNULL){
    Queue q(sizeof(int));

    int popOutcome = q.myqueue_dequeue(nullptr);

    EXPECT_EQ(-1, popOutcome);
}




