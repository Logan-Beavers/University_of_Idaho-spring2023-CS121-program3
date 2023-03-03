/*********************************************************************
*                              Stack.cpp
*
* Stack class member definitions
**********************************************************************/

#include "Stack.h"
#include <cstddef>

bool Stack::push(Stack::element e)
{
	//add element to stack
	//check if it was successfully added
	return _list.add_element(e);
}

Stack::element Stack::pop()
{
    //check if stack is empty
	if(_list.get_size() == 0)
	{
        return NULL;
	}

	//get element
	Stack::element e = _list.get_element();

	//remove element from stack
	_list.remove_element();

	//return element
	return e;
}

Stack::element Stack::peek()
{
    //check if stack is empty
	if(_list.get_size() == 0)
	{
        return NULL;
	}

	//get element
	return _list.get_element();
}

int Stack::size()
{
	//get stack size from the list
	return _list.get_size();
}

void Stack::free()
{
	//free all memory used by the list
	_list.free();
}
