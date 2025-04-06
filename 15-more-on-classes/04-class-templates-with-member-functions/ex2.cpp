/* Injected class names */

/*
In a prior lesson, we noted that the name of a constructor must match the name of the class. But in 
our class template for Pair<T> above, we named our constructor Pair, not Pair<T>. Somehow this 
still works, even though the names don't match.

Within the scope of a class, the unqualified name of the class is called an injected class name. In 
a class template, the injected class name serves as shorthand for the fully templated name.

Because Pair is the injected class name of Pair<T>, within the scope of our Pair<T> class template, 
any use of Pair will be treated as if we had written Pair<T> instead. Therefore, although we named 
the constructor Pair, the compiler treats it as if we had written Pair<T> instead. The names now 
match!

This means that we can also define our isEqual() member function like this:
template <typename T>
bool Pair<T>::isEqual(const Pair& pair) // note the parameter has type Pair, not Pair<T>
{
    return m_first == pair.m_first && m_second == pair.m_second;
}
Because this is a definition for a member function of Pair<T>, we are in the scope of the Pair<T> 
class template. Therefore, any use of Pair is shorthand for Pair<T>!

--> See the code below and compile the program to understand better.
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

    bool is_not_equal(const Pair<T>& pair);
};

// When we define a member function outside the class definition,
// we need to resupply a template parameter declaration
template <typename T>
bool Pair<T>::is_equal(const Pair& pair)
{
    return first == pair.first && second == pair.second;
}

template <typename T>
bool Pair<T>::is_not_equal(const Pair& pair)
{
    return !(this->is_equal(pair));
}

int main()
{
    Pair p1 { 5, 6 }; // uses CTAD to infer type Pair<int>
    Pair p2 { 5, 6 };
    Pair p3 { 5, 7 };
    std::cout << std::boolalpha << "p1.is_equal(p2): " << p1.is_equal(p2) << '\n';
    std::cout << std::boolalpha << "p1.is_equal(p3): " << p1.is_equal(p3) << '\n';

    std::cout << std::boolalpha << "p1.is_not_equal(p2): " << p1.is_not_equal(p2) << '\n';
    std::cout << std::boolalpha << "p1.is_not_equal(p3): " << p1.is_not_equal(p3) << '\n';
    return 0;
}

/* Where to define member functions for class templates outside the class

With member functions for class templates, the compiler needs to see both the class definition (to 
ensure that the member function template is declared as part of the class) and the template member 
function definition (to know how to instantiate the template). Therefore, we typically want to 
define both a class and its member function templates in the same location.

When a member function template is defined inside the class definition, the template member 
function definition is part of the class definition, so anywhere the class definition can be seen, 
the template member function definition can also be seen. This makes things easy (at the cost of 
cluttering our class definition).

When a member function template is defined outside the class definition, it should generally be 
defined immediately below the class definition. That way, anywhere the class definition can be 
seen, the member function template definitions immediately below the class definition will also be 
seen.

In the typical case where a class is defined in a header file, this means any member function 
templates defined outside the class should also be defined in the same header file, below the class 
definition.
*/