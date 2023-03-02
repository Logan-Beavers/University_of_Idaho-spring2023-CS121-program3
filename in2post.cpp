/****************************************************************************************************
 *												in2post.cpp
 *
 * CS 121.Bolden.........MSVC++ 19.34.31937...........Logan Beavers
 *						 G++ 10.2.1
 * 2023/5/1.................Intel 9100F.............Beav6334@vandals.uidaho.edu
 *							AMD FX-9800P
 *
 * Programming Assignment #3
 * Take in an infix operation, then check for syntax and logic errors and convert it to postfix
 ***************************************************************************************************/

#include <cstdlib>
#include <string>

#include "input_and_output.h"

int main()
{
	//initialize variables
	bool user_active = true;//false if user wants to quit program
	std::string infix = std::string();//infix string the user wants to convert to postfix
	std::string postfix = std::string();//postfix string after user has converted it. May contain an error message if the infix to postfix conversion failed

	//get infix string from user and check if user entered "quit"
	user_active = fill_with_infix(infix);

	//keep prompting for infix to postfix while user hasn't entered quit
	while(user_active)
	{
		//convert infix to postfix
		postfix = infix_to_postfix(infix);

		//print postfix string
		print(postfix);

		//get infix string from user and check if user entered "quit"
		user_active = fill_with_infix(infix);
	}

	return EXIT_SUCCESS;
}