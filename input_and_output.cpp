/*********************************************************************
*                           input_and_output.h
*
* Function definitions for program input and output
*
* TODO why is this here
**********************************************************************/

#include <iostream>
#include <string>

#include "input_and_output.h"

bool fill_with_infix(std::string& functionOut_fill)
{
	//get infix from user
	std::getline(std::cin, functionOut_fill);
	
	//check if user entered quit
	if (functionOut_fill == "quit")
	{
		//clear string
		functionOut_fill.clear();

		return false;
	}

	return true;
}

void print(std::string output)
{
	//print string
	std::cout << output << std::endl;
}
