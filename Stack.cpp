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
	//add element to list
	//check if it was successfully added
	return list.add_element(e);
}

Stack::element Stack::pop()
{
	//TODO document and double check this
	Stack::element e = list.get_element();
	list.remove_element();
	return e;
}

int Stack::size()
{
	//get size from the list
	return list.get_size();
}
