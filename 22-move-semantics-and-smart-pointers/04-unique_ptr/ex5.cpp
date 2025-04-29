#include <iostream>
#include <memory> // for std::unique_ptr
#include <utility> // for std::move

class Resource
{
private:
    std::string name;
    double value;
public:
	Resource(std::string name="nothing", double value=0.0) 
    : name {name}, value {value}
    { 
        std::cout << "Resource acquired:\n\t";
        std::cout << "Name = " << this->name << " | Value = " << this->value << '\n';
    }
	~Resource() { std::cout << "Resource destroyed\n"; }

    std::string get_name() { return this->name; }

    double get_value() { return this->value; }
};

std::ostream& operator<<(std::ostream& out, Resource& resource)
{
	out << "I am a Resource:\n\t";
    out << "Name = " << resource.get_name() 
        << " | Value = " << resource.get_value() << '\n';
	return out;
}

int main()
{
    Resource res {"gold", 42.0};    // Stack-allocated
    
    // This is a bad code:
    // std::unique_ptr<Resource> ptr1 { &res };     // BAD!
    // Uncomment the above code to see the problem on the console. You would see
    //  free(): invalid pointer
    // on the console.

    /* This is dangerous because:
    (1) std::unique_ptr assumes ownership of the pointer and will delete it when it 
        goes out of scope.
    (2) But res is not heap-allocated — it's a local variable.
    (3) So when ptr1 tries to delete &res, you're effectively doing delete on a stack 
        pointer → undefined behavior, hence:
            free(): invalid pointer
    */
    // If you want to use a std::unique_ptr, you need to dynamically allocate the resource:
    std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>("gold", 42.0);

    // This will make error as two pointers would point to the same object.
    // std::unique_ptr<Resource> ptr2 { ptr1 };

    if (ptr1) // use implicit cast to bool to ensure res contains a Resource
        std::cout << "ptr1 is " << *ptr1;

    // Using shared pointer to point to the same object is OK.
    std::shared_ptr<Resource> ptr3 = std::make_shared<Resource>("silver", 24.0);
    std::shared_ptr<Resource> ptr4 { ptr3 };
    std::cout << "ptr3 is " << *ptr3;
    std::cout << "ptr4 is " << *ptr4;
}