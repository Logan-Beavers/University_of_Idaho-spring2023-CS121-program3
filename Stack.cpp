#include "Stack.h"
/*********************************************************************
*                              Stack.cpp
*
* Stack class member definitions
*
* TODO why is this here
**********************************************************************/

bool Stack::push(Stack::element e)
{
	//add element to stack
	//check if it was successfully added
	return list.add_element(e);
}

Stack::element Stack::pop()
{
    //check if stack is empty
	if(list.get_size() == 0)
	{
        return NULL;
	}

	//get element
	Stack::element e = list.get_element();

	//remove element from stack
	list.remove_element();

	//return element
	return e;
}

int Stack::size()
{
	//get stack size from the list
	return list.get_size();
}
