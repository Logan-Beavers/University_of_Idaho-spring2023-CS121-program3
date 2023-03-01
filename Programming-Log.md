# Programming-Log

#### Research + Trying Algorithm by hand: 1.5 hours

Learned how to translate postfix to infix
Learned the rules to the infix to postfix translation algorithm
    1) The operators are divided into priority classes:
        class 1: ^
        class 2: *, /
        class 3: +, -
    2) Operators of the same or lower priority cannot be pushed onto a higher (or same) priority operator on the stack: if you have a + on the stack, and want to add a -, you must place the + in the postfix expression first
    3) When parenthesis are encountered, limit rule scope to the parenthesis, then place operators inside in the postfix expression when parenthesis end: A * (B - C) -> ABC-*
Created rules for checking if the basic arithmetic is semantically correct
    Constraints
        1) any variables XY will be interpreted as a single variable
        2) a(b) should be writeen a * b
    Rules
        1) The stack should not be pushed to consecutively unless it is a parenthesis
        2) There should be n-1 operators for n operands

