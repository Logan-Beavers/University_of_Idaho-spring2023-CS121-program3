/*********************************************************************
*                           infix_postfix.h
*
* Function declarations for converting infix to postfix
*
* TODO why is this here
**********************************************************************/

//header guard
#pragma once

#include <string>

/*  transform an infix string to a postfix string
    will return an error string if syntax error or divide by zero is detected */
std::string infix_to_postfix(std::string infix);
