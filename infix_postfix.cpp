#include "infix_postfix.h"
#include "Stack.h"
/*********************************************************************
*                           infix_postfix.cpp
*
* Function definitions for converting infix to postfix
**********************************************************************/

std::string infix_to_postfix(std::string infix)
{
	/*	possible syntax errors:
			The stack should not be pushed to consecutively unless it is a parenthesis: a + + b
			There should be n - 1 operators for n operands
			There shouldn't be any operands waiting to be written to the postfix expression when pushing a left paren '(' to the stack: a + b (c + d)
			The stack should be empty when the input string is empty: ((a + b)
			The stack should only be empty when the input string is empty: (a + b)) */

	//surround the infix string in parenthesis to appease algorithm logic
	infix = "(" + infix + ")";

	//initialize variables

	//string containing the valid postfix, or TODO an error message
	std::string postfix = std::string();

	/*	store how many operands and operators are in the infix string
	*	if there isn't one more operand than operator: syntax error */
	int operand_count = 0;
	int operator_count = 0;

	//string containing the operand character or string i.e. "A" or "801"
	std::string operand = std::string();

	//stack containing the operators
	Stack operators = Stack();

	//what character the function is currently reading
	int position = 0;

	//size of the infix string
	int size_of_infix = infix.size();

	//the current character the function is examining
	char character = NULL;

	//whether or not the stack was pushed too twice in a row without parenthesis or operands in between
	bool consecutive = false;

	while (position < size_of_infix)
	{
		character = infix.at(position);
		if (character == ' ')
		{
			//whitespace can be ignored and removed from the string
		}
		else if ((character >= '1' and character <= '9') or (character >= 'A' and character <= 'Z') or (character >= 'a' and character <= 'z'))
		{
			/*	check for valid operand
			 *	0-9, or A-Z, or a-z
			 *	check using ascii codes */

			 //add character to operand
			operand += character;

			//update consecutive to show something happened in between stack calls
			consecutive = false;
		}
		else if (character == ')')
		{
			/*	end of this parenthesis group
			 *	send all operators in the parenthesis group stack to the postfix string */

			 //check if there is an operand that can be added to postfix
			if (operand.size() != 0)
			{
				//add operand to postfix
				postfix += operand;
				postfix += " ";

				//update operand count
				++operand_count;

				//clear operand
				operand.clear();
			}

			 //empty stack onto postfix
			while (operators.peek() != '(')
			{
				/*	the stack should only be empty when the input string is empty
					if the stack is empty here, the beginning of the paren group '(' couldn't be found */
				if (operators.size() == 0)
				{
					//turn postfix into error string
					postfix = "error: missing '('";
					return postfix;
				}
				postfix += operators.pop();
				postfix += " ";
			}

			//discard parenthesis
			operators.pop();

			//update consecutive to show something happened in between stack calls
			consecutive = false;
		}
		else if (character == '(')
		{
			//there shouldn't be any operands waiting to be written to the postfix expression when pushing a left paren '(' to the stack: a + b (c + d)
			if (operand.size() != 0)
			{
				//clear stack
				operators.free();

				//turn postfix into error string
				postfix = "Error: missing operator";
				return postfix;
			}

			operators.push(character);

			//update consecutive to show something happened in between stack calls
			consecutive = false;
		}
		else if (character == '^') //Tier 1
		{
			//update operator count
			++operator_count;

			//check if there is an operand that can be added to postfix
			if (operand.size() != 0)
			{
				//add operand to postfix
				postfix += operand;
				postfix += " ";

				//update operand count
				++operand_count;

				//clear operand
				operand.clear();
			}

			//add operators on the stack of equal or lesser priority to postfix
			while (operators.peek() != '(' and operators.peek() != '+' and operators.peek() != '-' and operators.peek() != '*' and operators.peek() != '/')
			{
				postfix += operators.pop();
				postfix += " ";
			}

			//add operator to stack
			//check if push was consecutive (bad syntax)
			if (consecutive)
			{
				//free the stack
				operators.free();

				//turn postfix into error string
				postfix = "error: consecutive operators";
				return postfix;
			}
			operators.push(character);

			//update consecutive to show that stack push was called twice in a row
			consecutive = true;
		}
		else if (character == '*' or character == '/') //Tier 2
		{
			//update operator count
			++operator_count;

			//check if there is an operand that can be added to postfix
			if (operand.size() != 0)
			{
				//add operand to postfix
				postfix += operand;
				postfix += " ";

				//update operand count
				++operand_count;

				//clear operand
				operand.clear();
			}

			//add operators on the stack of equal or lesser priority to postfix
			while (operators.peek() != '(' and operators.peek() != '+' and operators.peek() != '-')
			{
				postfix += operators.pop();
				postfix += " ";
			}

			//add operator to stack
			//check if push was consecutive (bad syntax)
			if (consecutive)
			{
				//free the stack
				operators.free();

				//turn postfix into error string
				postfix = "error: consecutive operators";
				return postfix;
			}
			operators.push(character);

			//update consecutive to show that stack push was called twice in a row
			consecutive = true;
		}
		else if (character == '+' or character == '-') //Tier 3
		{
			//update operator count
			++operator_count;

			//check if there is an operand that can be added to postfix
			if (operand.size() != 0)
			{
				//add operand to postfix
				postfix += operand;
				postfix += " ";

				//update operand count
				++operand_count;

				//clear operand
				operand.clear();
			}

			//add operators on the stack of equal or lesser priority to postfix
			while (operators.peek() != '(')
			{
				postfix += operators.pop();
				postfix += " ";
			}

			//add operator to stack
			//check if push was consecutive (bad syntax)
			if (consecutive)
			{
				//free the stack
				operators.free();

				//turn postfix into error string
				postfix = "error: consecutive operators";
				return postfix;
			}
			operators.push(character);

			//update consecutive to show that stack push was called twice in a row
			consecutive = true;
		}
		else
		{
			//not a valid character

			//update postfix to carry Error message
			postfix = "Error: invalid character";

			//clear the stack
			operators.free();

			return postfix;
		}

		//move to next character in infix expression
		++position;
	}

	//There should be n - 1 operators for n operands
	if (operator_count != operand_count - 1)
	{
		//update postfix to carry Error message
		postfix = "Error: inbalance of operands and operators";
	}

	/*	the stack should be empty once the infix expression is translated
		if the stack isn't empty, it means there was an extra left paren '(' in the infix expression */
	if (operators.size() != 0)
	{
		//clear the stack
		operators.free();

		//update postfix to carry Error message
		postfix = "Error: missing ')'";
	}

	return postfix;
}