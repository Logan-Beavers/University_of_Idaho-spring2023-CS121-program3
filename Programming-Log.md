# Programming-Log

### Research + Trying Algorithm by hand: *1.5 hours*

**Learned how to translate postfix to infix**
**Learned the rules to the infix to postfix translation algorithm**

1. The operators are divided into priority classes:
    * class 1: ^
    * class 2: *, /
    * class 3: +, -
2. Operators of the same or lower priority cannot be pushed onto a higher (or same) priority operator on the stack: if you have a + on the stack, and want to add a -, you must place the + in the postfix expression first
3. When parenthesis are encountered, limit rule scope to the parenthesis, then place operators inside in the postfix expression when parenthesis end: A * (B - C) -> ABC-*

**Created rules for checking if the basic arithmetic is semantically correct**
* Constraints
    * any variables XY will be interpreted as a single variable
    * a(b) should be written a * b
* Rules
    * The stack should not be pushed to consecutively unless it is a parenthesis
    * There should be n-1 operators for n operands
    * The stack should be empty when the input string is empty ((
    * The stack should only be empty when the input string is empty ))

### Created Linked List data structure: *2 hours*

* Learned that I should define the node data structure with my List instead of creating a generic one and using it as a one-size-fits-all for other structures. This is because interpreting the ambiguous datatype is not only dangerous but inefficent compared to just defining what you need
* Learned that I shouldn't have private members of the node data structure for this linked list class, the getters and setters were all one line and just added fluff and confusion
* Learned that for the stack class I am implementing I really don't need to have nth element functions, but I'm making them anyways so I will have them for the future

### Created input and output fuctions, and main program loop: *1 hour*
* Realized I should have a seperate file for input and output functions to simplify code
* Researched conventions for multiple return types, decided on passing by reference

### Documented Program: *10 minutes*
* Deciced on a standard for file documentation
