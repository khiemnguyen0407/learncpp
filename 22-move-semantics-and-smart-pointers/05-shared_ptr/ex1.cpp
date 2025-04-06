/* std::shared_ptr */
/*
Unlike std::unique_ptr, which is designed to singly own and manage a resource, std::shared_ptr is 
meant to solve the case where you need multiple smart pointers co-owning a resource.

This means that it is fine to have multiple std::shared_ptr pointing to the same resource. 
Internally, std::shared_ptr keeps track of how many std::shared_ptr are sharing the resource. As 
long as at least one std::shared_ptr is pointing to the resource, the resource will not be 
deallocated, even if individual std::shared_ptr are destroyed. As soon as the last std::shared_ptr 
managing the resource goes out of scope (or is reassigned to point at something else), the resource 
will be deallocated.

Like std::unique_ptr, std::shared_ptr lives in the <memory> header.
*/

#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	// allocate a Resource object and have it owned by std::shared_ptr
	Resource* res { new Resource };
	std::shared_ptr<Resource> ptr1{ res };
	{
        // make another std::shared_ptr pointing to the same thing
		std::shared_ptr<Resource> ptr2 { ptr1 }; 

		std::cout << "Killing one shared pointer\n";
	} // ptr2 goes out of scope here, but nothing happens

	std::cout << "Killing another shared pointer\n";

	return 0;
} // ptr1 goes out of scope here, and the allocated Resource is destroyed