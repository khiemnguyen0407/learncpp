/* constexpr if statements */


/* REMARK: Read the code first, then come back reading this discussion.

Normally, the conditional of an if-statement is evaluated at runtime. However, consider the case 
where the conditional is a constant expression, such as in the following example. Because 
gravity_earth is constexpr and initialized with value 9.8, the conditional gravity_earth == 9.8 must 
evaluate to true. As a result, the else-statement will never be executed.

Clearly, evaluating a constexpr conditional at runtime is wasteful (since the result will never 
ary). It is also wasteful to compile code into the executable that can never be executed.

C++17 introduces the constexpr if statement, which requires the conditional to be a constant 
expression. The conditional of a constexpr-if-statement will be evaluated at compile-time.

If the constexpr conditional evaluates to true, the entire if-else will be replaced by the 
true-statement. If the constexpr conditional evaluates to false, the entire if-else will be 
replaced by the false-statement (if it exists) or nothing (if there is no else).

To use a constexpr-if-statement, we add the constexpr keyword after the if.
*/

#include <iostream>
int main()
{
	constexpr double gravity_earth{ 9.807 };
	// reminder: low-precision floating point literals of the same type can be tested for equality
	if (gravity_earth == 9.807) // constant expression, always true
		std::cout << "We are living on Earth.\n";   // will always be executed
	else
		std::cout << "We are not living on Earth.\n"; // will never be executed


	// To use constexpr-if-statement, add constexpr keyword after the if.
	// The following conditional statement will be evaluated at the compile-time.

	constexpr double gravity_mars { 3.73 };
	if constexpr (gravity_mars == 3.73) // now using constexpr if
		std::cout << "We are living on Mars.\n";
	else
		std::cout << "We are not living on Mars.\n"; 

	return 0;
}

