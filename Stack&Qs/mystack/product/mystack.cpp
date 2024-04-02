#include "mystack.h"
#include <cstring>
#include <iostream>

Stack::Stack(size_t size){
	stack = nullptr;
	objsize = size;  
	numelem = 0;
}

Stack::~Stack()
{
	//varibles for deleting the items from stack
	StackObject_t* deleteNode = stack;
	StackObject_t* nextNode = stack;

	//delete / free i number of items from the stack
	for(int i = 0; i < (numelem); i++){
		//check if next node is not the last
		if(nextNode != NULL){
			nextNode = nextNode->next;
		}

		//free one node and reassign node which will get deleted on next iterration
		free(deleteNode->obj);
		delete deleteNode;

		deleteNode = nextNode;

	}	
}

int Stack:: mystack_push(void* obj){

	//checking if valid pointers have been passed to the function
	if(obj == nullptr){
		return -1;
	}

	//creating a item in stack
	StackObject_t *node = new StackObject_t;

	//checking if there is suffienct amount memory
	if(node == NULL){
		return -1;
	}
	else{
	  //allocating memory for the item object in size of the type of what the item is
      node->obj = malloc(objsize);

	  //copying the data to which the passed obj pointer is pointing to into the node obj
      memcpy(node->obj, obj, objsize);
	  
	  //inserting the node into the 1st place in stack and incrementing the value of counter
      node->next = stack;
      stack = node;
      numelem++;
	}

	return 0;
}


int Stack::mystack_pop(void* obj){

	//checking if there is something to be popped
	if(numelem > 0){

		//store the current pointer to 2nd LL in stack to temporary value
		StackObject_t* temp = stack->next;
		
		//copy memory from first value in stack into the passed object
		memcpy(obj, stack->obj, objsize);

		//free the first stack object and memory allocated to it
		free(stack->obj);
		delete stack;

		//connect stack handle to the new 1st stack in stack
		stack = temp;

		//decrement the total value of elements in stack
		numelem--;
	}
	else{
		return -1;
	}
	
    return 0;
}


int Stack::mystack_nofelem(){

	//returning the attribute which is responsible for keeping track of number of the elements in the list
	return numelem;
}
