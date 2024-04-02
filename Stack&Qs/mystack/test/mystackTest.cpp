#include "gtest/gtest.h"
#include "mystack.h"

TEST(MystackCtor, ConstructorTest){
    Stack stack(sizeof(int));

    EXPECT_EQ(0, stack.mystack_nofelem());
}

TEST(MystackPush, NormalValues){
	Stack stack(sizeof(int));
	
	//test values which get pushed to the stack
	int array[4] = {1,2,3,4};

	//last value getting pushed to the stack
	int inputValue = 5;
	void* ptr1 = &inputValue;
    int pushMultiple = -1;

	//pushing test values to the stack
	for(int i = 0; i < 4; i++){
		pushMultiple = stack.mystack_push(&array[i]);
	}

	//pushing the 5th value to stack
	int lastPushedValue = stack.mystack_push(ptr1);

	//value to which gets copied the last value stored in stack


	EXPECT_EQ(0, pushMultiple);						    //expecting to have a normal outcome of function -> 0, since functrion returns -1 if there was an issue
	EXPECT_EQ(0, lastPushedValue);		                //expecting having the top value in stack to be the last pushed value (lastPushedValue)
	EXPECT_EQ(5,  stack.mystack_nofelem());				//expecting number of elements in stack to be 5, since 5 values ware pushed to the stack
}

TEST(MystackPush, NullValues){
    Stack stack(sizeof(int));

	int resultNullPtr = stack.mystack_push(NULL);

	EXPECT_EQ(-1, resultNullPtr);				//expecting to have return value of -1 due to passed NULL arguement
}

TEST(MystackPop, NormalValues){
	Stack stack(sizeof(int));

	//test values which get pushed to the stack
	int array[5] = {1,2,3,4,5};
	
	//pushing test values to the stack
	for(int i = 0; i < 5; i++){
		stack.mystack_push(&array[i]);
	}

	//value to which we store the last pushed value in stack
	int outputValue = -99;
	void* ptr1 = &outputValue;

	//expected value to be on stack
	int expectedPoppedValue = array[4];

	//popping the value from stack
	int result = stack.mystack_pop(ptr1);
	
	EXPECT_EQ(0, result);									//expecting to have a normal outcome of function -> 0, since functrion returns -1 if there was an issue
	EXPECT_EQ(expectedPoppedValue, outputValue);			//expecting having the top value in stack to be the last pushed value (lastPushedValue)
	EXPECT_EQ(4, stack.mystack_nofelem());							//expecting number of elements in stack to be 4, since 5 were pushed and one popped from the stack

}

TEST(MystackPop, NullValues){
	Stack stack(sizeof(int));

	//running functions
	int resultNullPtr = stack.mystack_pop(NULL);
	
	EXPECT_EQ(-1, resultNullPtr);									//expecting to have a normal outcome of function -> 0, since functrion returns -1 if there was an issue
}

TEST(MystackPop, EmptyStack){
    Stack stack(sizeof(int));
    
    //test value initialization
	int a = 5;
	void* ptr = &a;

	//popping the value from stack
	int result = stack.mystack_pop(ptr);

	EXPECT_EQ(-1, result);				//expecting to have return value of -1 due to no elements being pushed to stack
}

TEST(Mystack, NumOfElementsNormalValues){
    Stack stack(sizeof(int));

	//dummy values for filling up the stack
	int array[10] = {1, 2, 3, 4 ,5, 6, 7, 8, 9};

	//test value initialization
	int a = 0;
	void* ptr = &a;
	
	//push all values to stack
	for(int i = 0; i < 10; i++){
		stack.mystack_push( &array[i]);
	}

	//pop 6 of them 
	for(int i = 0; i < 6; i++){
		stack.mystack_pop(&ptr);
	}

	//getting the number of elements in stack
	int numberOfStacks = stack.mystack_nofelem();

	EXPECT_EQ(4, numberOfStacks); 
}