/* Type template parameters in member functions */

/*
Type template parameters defined as part of a class template parameter declaration can be used both 
as the type of data members and as the type of member function parameters.

In the following example, we rewrite the above Pair class template, converting it from a struct 
to a class. Please refer back to the lesson "class templates" explained in the Section dedicated to
enums and structs.
*/

#include <ios>       // for std::boolalpha
#include <iostream>

template <typename T>
class Pair
{
private:
    T first{};
    T second{};

public:
    // When we define a member function inside the class definition,
    // the template parameter declaration belonging to the class applies
    Pair(const T& first, const T& second)
        : first{ first }
        , second{ second }
    {
        std::cout << "Pair(" << this->first << ", " << this->second << ") is constructed!\n";
    }

    bool is_equal(const Pair<T>& pair);
};

// When we define a member function outside the class definition,
// we need to resupply a template parameter declaration
template <typename T>
bool Pair<T>::is_equal(const Pair<T>& pair)
{
    return first == pair.first && second == pair.second;
}

int main()
{
    Pair p1 { 5, 6 }; // uses CTAD to infer type Pair<int>
    Pair p2 { 5, 6 };
    Pair p3 { 5, 7 };
    std::cout << std::boolalpha << "p1.is_equal(p2): " << p1.is_equal(p2) << '\n';
    std::cout << std::boolalpha << "p1.is_equal(p3): " << p1.is_equal(p3) << '\n';

    return 0;
}
/* Discussion

First, because our class has private members, it is not an aggregate, and therefore can not use 
aggregate initialization. Instead, we have to initialize our class objects using a constructor.

Since our class data members are of type T, we make the parameters of our constructor type const 
T&, so the user can supply initialization values of the same type. Because T might be expensive to 
copy, it is safer to pass by const reference than by value.

Note that when we define a member function inside the class template definition, we do not need to 
provide a template parameter declaration for the member function. Such member functions implicitly 
use the class template parameter declaration.

Third, let’s look more closely at the case where we define a member function for a class template 
outside of the class template definition:
-----------------------------------------------------
template <typename T>
bool Pair<T>::isEqual(const Pair<T>& pair)
{
    return m_first == pair.m_first && m_second == pair.m_second;
}
-----------------------------------------------------
Since this member function definition is separate from the class template definition, we need to 
resupply a template parameter declaration (template <typename T>) so the compiler knows what T is.
*/
