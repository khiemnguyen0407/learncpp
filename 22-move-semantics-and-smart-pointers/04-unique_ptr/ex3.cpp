/* Accessing the managed object */

/*
std::unique_ptr has an overloaded operator* and operator-> that can be used to return the resource 
being managed. Operator* returns a reference to the managed resource, and operator-> returns a 
pointer.

Remember that std::unique_ptr may not always be managing an object -- either because it was created 
empty (using the default constructor or passing in a nullptr as the parameter), or because the 
resource it was managing got moved to another std::unique_ptr. So before we use either of these 
operators, we should check whether the std::unique_ptr actually has a resource. Fortunately, this 
is easy: std::unique_ptr has a cast to bool that returns true if the std::unique_ptr is managing a 
resource.
*/

#include <iostream>
#include <memory> // for std::unique_ptr

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

std::ostream& operator<<(std::ostream& out, const Resource&)
{
	out << "I am a resource";
	return out;
}

int main()
{
	std::unique_ptr<Resource> res{ new Resource{} };

	if (res) // use implicit cast to bool to ensure res contains a Resource
		std::cout << *res << '\n'; // print the Resource that res is owning

	return 0;
}