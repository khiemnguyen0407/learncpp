/* Reusing functions */

/*
Now we can illustrate a good case for function reuse. Consider the following program:

#include <iostream>

int main()
{
	int x{};
	std::cout << "Enter an integer: ";
	std::cin >> x;

	int y{};
	std::cout << "Enter an integer: ";
	std::cin >> y;

	std::cout << x << " + " << y << " = " << x + y << '\n';

	return 0;
}

While this program works, it’s a little redundant. In fact, this program violates one of the 
central tenets of good programming: Don’t Repeat Yourself (often abbreviated DRY).

Why is repeated code bad? If we wanted to change the text "Enter an integer:"" to something else, 
we would have to update it in two locations. And what if we wanted to initialize 10 variables 
instead of 2? That would be a lot of redundant code (making our programs longer and harder to 
understand), and a lot of room for typos to creep in.

*/

/*
Best practice:
Follow DRY: "Don’t repeat yourself". If you need to do something more than once, consider how to 
modify your code to remove as much redundancy as possible. Variables can be used to store the 
results of calculations that need to be used more than once (so we do not have to repeat the 
calculation). Functions can be used to define a sequence of statements we want to execute more than 
once. And loops (which we will cover in a later chapter) can be used to execute a statement more than 
once.
*/

#include <iostream>

int get_value_from_user()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

int main()
{
    int x { get_value_from_user() }; // first call to get_value_from_user
    int y { get_value_from_user() }; // second call to get_value_from_user
    int z { get_value_from_user() }; // third call to get_value_from_user
    std::cout << x << " + " << y << " + " << z << " = " << x + y + z << '\n';

    return 0;
}