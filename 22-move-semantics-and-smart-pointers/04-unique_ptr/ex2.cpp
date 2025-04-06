/* std::unique_ptr */

// Unlike std::auto_ptr, std::unique_ptr properly implements move semantics.

#include <iostream>
#include <memory> // for std::unique_ptr
#include <utility> // for std::move

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	std::unique_ptr<Resource> res1{ new Resource{} }; // Resource created here
	std::unique_ptr<Resource> res2{}; // Start as nullptr

	std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
	std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

	// res2 = res1; // Won't compile: copy assignment is disabled
	res2 = std::move(res1); // res2 assumes ownership, res1 is set to null

	std::cout << "Ownership transferred\n";

	std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
	std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

	return 0;
} // Resource destroyed here when res2 goes out of scope

/* Discussion
Because std::unique_ptr is designed with move semantics in mind, copy initialization and copy 
assignment are disabled. If you want to transfer the contents managed by std::unique_ptr, you must 
use move semantics. In the program above, we accomplish this via std::move (which converts res1 
into an r-value, which triggers a move assignment instead of a copy assignment).
*/