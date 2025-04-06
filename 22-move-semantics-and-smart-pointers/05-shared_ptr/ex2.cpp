/* std::shared_ptr: Part 2 */

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
	Resource* res { new Resource };
	std::shared_ptr<Resource> ptr1 { res };
	{
		std::shared_ptr<Resource> ptr2 { res }; // create ptr2 directly from res (instead of ptr1)

		std::cout << "Killing one shared pointer\n";
	} // ptr2 goes out of scope here, and the allocated Resource is destroyed

	std::cout << "Killing another shared pointer\n";

	return 0;
} // ptr1 goes out of scope here, and the allocated Resource is destroyed again

/* Discussion:
This program prints:
====================================
Resource acquired
Killing one shared pointer
Resource destroyed
Killing another shared pointer
Resource destroyed
====================================
and then crashes (on my computer).alignas

The difference here compared to ex1.cpp is that we created two std::shared_ptr independently from 
each other. As a consequence, even though they’re both pointing to the same Resource, they aren't 
aware of each other. When ptr2 goes out of scope, it thinks it’s the only owner of the Resource, 
and deallocates it. When ptr1 later goes out of the scope, it thinks the same thing, and tries to 
delete the Resource again. Then bad things happen.

Fortunately, this is easily avoided: if you need more than one std::shared_ptr to a given resource, 
copy an existing std::shared_ptr.

BEST PRACTICE:
Always make a copy of an existing std::shared_ptr if you need more than one std::shared_ptr 
pointing to the same resource.

*/