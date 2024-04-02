#include "mystack.h"
#include "myqueue.h"
#include <cstring>
#include <iostream>

Queue :: Queue(int size)
    :stack_in(size), stack_out(size), item_size(size)
{
}

Queue :: ~Queue(){

}

int Queue:: myqueue_enqueue(void* obj){

	//check if valid pointers were passed to the function
	if(obj == nullptr){
		return -1;
	}

	//enquing the passed value
	int successfulPush = stack_in.mystack_push(obj);

	//checking if there was no error in enqueuing
	if(successfulPush == -1){
		return  -1;
	}

	return 0;    
}   

int Queue:: myqueue_dequeue(void* obj){
	//chceck if valid pointers were passed to the function
	if(obj == NULL){
		return -1;

	}

	//temporary value which will be then returned in obj value
    void* temp = malloc(item_size);
    
	//checking whether the stack out is empty, if yes, enqueued values must be pushed into it
    if(stack_out.mystack_nofelem() == 0){
		
		//checking if there are values to be pushed from stack in into stack out
		if(stack_in.mystack_nofelem() > 0){

			//variables used for checking if popping / pushing went correctly
			int successfulPop;
			int successfulPush;

			//pushing values into stack out from stack in until enqueue stack (stack in) is empty
			while(stack_in.mystack_nofelem() != 0){
				successfulPop = stack_in.mystack_pop(temp);
				successfulPush = stack_out.mystack_push(temp);

				//checking if the popping / pushing went successfully
				if(successfulPop == -1 || successfulPush == -1){
					return -1;
				}
			}
		}
		else{
			free(temp);
			return -1;
		}
    }
    //popping the last element pushed to the stack out (following principle of queue = LIFO)
    int successfulPop = stack_out.mystack_pop(temp);
    
	//checking if popping went correctly
    if(successfulPop == -1){
      return -1;
    }
    
	//copying memory of temp item into the obj passed by user, the temp represents the last value popped from stack in / newest value pushed into stack out
	memcpy(obj, temp, item_size);
    

	free(temp);

    return 0;
}
