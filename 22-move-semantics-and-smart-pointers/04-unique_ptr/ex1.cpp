/* std::unique_ptr */

/* std::unique_ptr is the C++11 replacement for std::auto_ptr. It should be used to manage any 
dynamically allocated object that is not shared by multiple objects. That is, std::unique_ptr 
should completely own the object it manages, not share that ownership with other classes. 
std::unique_ptr lives in the <memory> header. */

#include <iostream>
#include <memory> // for std::unique_ptr

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	// allocate a Resource object and have it owned by std::unique_ptr
	std::unique_ptr<Resource> res{ new Resource() };

	return 0;
} // res goes out of scope here, and the allocated Resource is destroyed

// Because the std::unique_ptr is allocated on the stack here, it’s guaranteed to eventually go 
// out of scope, and when it does, it will delete the Resource it is managing.