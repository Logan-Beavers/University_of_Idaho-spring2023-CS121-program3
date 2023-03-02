/*********************************************************************
*                                Stack.h
*
* Stack class definition
*
* TODO why is this here
**********************************************************************/

//header guard
#pragma once

#include "LinkedList.h"

//effectively an alias of the LinkedList class, restricted to adding and removing the head of the list
class Stack {
public:

	//standardize the underlying list datatype and the stack return type
	typedef LinkedList::element element;

	/* adds an element to the top of the stack
	   true -> element was added successfully
	   false -> stack has reached max size */
	bool push(Stack::element);

	/*  remove and return element from the top of the stack
		NULL -> stack is empty */
	Stack::element pop();

	//return the size of the stack
	int size();

private:

	//fundamental data structure of the stack
	LinkedList list;
};