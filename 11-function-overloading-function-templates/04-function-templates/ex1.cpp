/* Introduction to C++ template */

/* In C++, the template system was designed to simplify the process of creating functions (or 
classes) that are able to work with different data types.

Instead of manually creating a bunch of mostly-identical functions or classes (one for each set of 
different types), we instead create a single template. Just like a normal definition, a template 
definition describes what a function or class looks like. Unlike a normal definition (where all 
types must be specified), in a template we can use one or more placeholder types. A placeholder 
type represents some type that is not known at the time the template is defined, but that will be 
provided later (when the template is used).

Once a template is defined, the compiler can use the template to generate as many overloaded 
functions (or classes) as needed, each using different actual types!

The end result is the same -- we end up with a bunch of mostly-identical functions or classes (one 
for each set of different types). But we only have to create and maintain a single template, and 
the compiler does all the hard work to create the rest for us.

Key point to remember:
======================
The compiler can use a single template to generate a family of related functions or classes, each 
using a different set of actual types.

Because the actual types aren’t determined until the template is used in a program (not when the 
template is written), the author of the template doesn’t have to try to anticipate all of the 
actual types that might be used. This means template code can be used with types that did not even 
exist when the template was written! We'll see how this comes in handy later, when we start 
exploring the C++ standard library, which is absolutely full of template code!

Key point to remember:
======================
Templates can work with types that didn’t even exist when the template was written. This helps make 
template code both flexible and future proof!
*/

/*
==================
Function templates
==================
A function template is a function-like definition that is used to generate one or more overloaded 
functions, each with a different set of actual types. This is what will allow us to create 
functions that can work with many different types. The initial function template that is used to 
generate other functions is called the primary template, and the functions generated from the 
primary template are called instantiated functions.

When we create a primary function template, we use placeholder types (technically called type 
template parameters, informally called template types) for any parameter types, return types, or 
types used in the function body that we want to be specified later, by the user of the template.
*/

/* 
Function templates are something that is best taught by example, so let’s convert our normal 
max(int, int) function from the example above into a function template. It's surprisingly easy.
*/


#include <iostream>

/* Here's our new function that uses a single template type, where all occurrences of actual type 
int have been replaced with type template parameter T. Then, we'going to tell the compiler that 
this is a template, and that T is a type template parameter that is a placeholder for any type. 
Both of these are done using a template parameter declaration, which defines any template 
parameters that will be subsequently used. */


template <typename T>   // template parameter declaration defining T as a type template parameter
T max(T x, T y)
{
    return (x < y) ? y : x;
}

/* There is no difference between the "typename" and "class" keywords in this context. You will 
often see people use the class keyword since it was introduced into the language earlier. However, 
we prefer the newer typename keyword, because it makes it clearer that the type template parameter 
can be replaced by any type (such as a fundamental type), not just class types.*/
template <class T> 
T add(T x, T y) { return x + y; }

int main()
{   

    int x1 { 24 }, x2 { 42 };
    // max<int>(x1, x2) instantiates and calls function max<int>(int, int)
    int int_max { max<int>(x1, x2) };
    std::cout << "Using function template\n";

    std::cout << "int_max = " << int_max << '\n';
    std::cout << "max<int>(x1, x2) = " << max<int>(x1, x2) << '\n';
    std::cout << "add<int>(x1, x2) = " << add<int>(x1, x2) << "\n\n";
    
    
    double d1 { 24.42 }, d2 { 42.24 };

    // max<double>(x1, x2) instantiates and calls function max<double>(int, int)
    double double_max { max<double>(d1, d2) };
    std::cout << "double_max = " << double_max << '\n';
    std::cout << "max<double>(d1, d2) = " << max<double>(d1, d2) << '\n';

    std::cout << "add<double>(d1, d2) = " << add<double>(d1, d2) << '\n';

    return 0;
}

/* 
Good practice:
==============
Use a single capital letter starting with T (e.g. T, U, V, etc…) to name type template parameters
that are used in trivial or obvious ways and represent "any reasonable type".
*/