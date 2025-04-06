/* Introduction to operator overloading */

/*
We learned about function overloading, which provides a mechanism to create and resolve function 
calls to multiple functions with the same name, so long as each function has a unique function 
prototype. This allows us to create variations of a function to work with different data types, 
without having to think up a unique name for each variant.

In C++, operators are implemented as functions. By using function overloading on the operator 
functions, you can define our own versions of the operators that work with different data types 
(including classes that we have written). Using function overloading to overload operators is 
called operator overloading.

Consider the following example:
int x { 2 };
int y { 3 };
std::cout << x + y << '\n';

The compiler comes with a built-in version of the plus operator (+) for integer operands -- this 
function adds integers x and y together and returns an integer result. When you see the expression 
x + y, you can translate this in your head to the function call operator+(x, y) (where operator+ is 
the name of the function).

Now consider this similar snippet:
double z { 2.0 };
double w { 3.0 };
std::cout << w + z << '\n';

The compiler also comes with a built-in version of the plus operator (+) for double operands. 
Expression w + z becomes function call operator+(w, z), and function overloading is used to 
determine that the compiler should be calling the double version of this function instead of the 
integer version.

Now consider what happens if we try to add two objects of a program-defined class:
Mystring string1 { "Hello, " };
Mystring string2 { "World!" };
std::cout << string1 + string2 << '\n';

What would you expect to happen in this case? The intuitive expected result is that the string 
"Hello, World!" would be printed on the screen. However, because Mystring is a program-defined 
type, the compiler does not have a built-in version of the plus operator that it can use for 
Mystring operands. So in this case, it will give us an error. In order to make it work like we 
want, we'd need to write an overloaded function to tell the compiler how the + operator should work 
with two operands of type Mystring. We’ll look at how to do this in the next lesson.
*/

/*
Resolving overloaded operators
==============================
When evaluating an expression containing an operator, the compiler uses the following rules:

* If all of the operands are fundamental data types, the compiler will call a built-in routine if 
one exists. If one does not exist, the compiler will produce a compiler error.

* If any of the operands are program-defined types (e.g. one of your classes, or an enum type), the 
compiler will use the function overload resolution algorithm to see if it can find an overloaded 
operator that is an unambiguous best match. This may involve implicitly converting one or more 
operands to match the parameter types of an overloaded operator. It may also involve implicitly 
converting program-defined types into fundamental types (via an overloaded typecast, which we will 
cover later in this chapter) so that it can match a built-in operator. If no match can be found (or 
an ambiguous match is found), the compiler will error.

Some points to note:
====================
(1) First, almost any existing operator in C++ can be overloaded. The exceptions are: conditional 
    (?:), sizeof, scope (::), member selector (.), pointer member selector (.*), typeid, and the 
    casting operators.

(2) Second, you can only overload the operators that exist. You can not create new operators or 
    rename existing operators. For example, you could not create an operator** to do exponents.

(3) Third, at least one of the operands in an overloaded operator must be a user-defined type. This 
    means you could overload operator+(int, Mystring), but not operator+(int, double).

(4) Fourth, it is not possible to change the number of operands an operator supports.

(5) Finally, all operators keep their default precedence and associativity (regardless of what 
    they're used for) and this can not be changed.

(6) Overloaded operators should return values in the way that is consistent with the original 
    operators. Operators that do not modify their operands (e.g. arithmetic operators) should generally 
    return results by value. 

(7) Operators that modify their leftmost operand (e.g. pre-increment, any of 
    the assignment operators) should generally return the leftmost operand by reference.

Within those confines, you will still find plenty of useful functionality to overload for your 
custom classes! You can overload the + operator to concatenate your program-defined string class, 
or add two Fraction class objects together. You can overload the << operator to make it easy to 
print your class to the screen (or a file). You can overload the equality operator (==) to compare 
two class objects. This makes operator overloading one of the most useful features in C++ 
-- simply because it allows you to work with your classes in a more intuitive way.
*/