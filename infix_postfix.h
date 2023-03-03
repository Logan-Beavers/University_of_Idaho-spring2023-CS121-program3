/*********************************************************************
*                           infix_postfix.h
*
* Function declarations for converting infix to postfix
**********************************************************************/

//header guard
#pragma once

#include <string>

/*  transform an infix string to a postfix string
    will return an error string if a syntax error was detected */
std::string infix_to_postfix(std::string infix);
