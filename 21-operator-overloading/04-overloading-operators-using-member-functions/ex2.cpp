/* When to use a normal, friend, or member function overload */
 

/* 
Note that the usage of the operator does not change (in both cases, cents1 + 2), we've simply 
defined the function differently. Our two-parameter friend function becomes a one-parameter member 
function, with the leftmost parameter in the friend version (cents) becoming the implicit *this 
parameter in the member function version.*/

/* When to use a normal, friend, or member function overload

In most cases, the language leaves it up to you to determine whether you want to use the 
normal/friend or member function version of the overload. However, one of the two is usually a 
better choice than the other.

(1) When dealing with binary operators that don’t modify the left operand (e.g. operator+), the 
    normal or friend function version is typically preferred, because it works for all parameter 
    types (even when the left operand isn’t a class object, or is a class that is not modifiable). 
    The normal or friend function version has the added benefit of "symmetry", as all operands 
    become explicit parameters (instead of the left operand becoming *this and the right operand 
    becoming an explicit parameter).

(2) When dealing with binary operators that do modify the left operand (e.g. operator+=), the 
member function version is typically preferred. In these cases, the leftmost operand will always be 
a class type, and having the object being modified become the one pointed to by *this is natural. 
Because the rightmost operand becomes an explicit parameter, there’s no confusion over who is 
getting modified and who is getting evaluated.

(3) Unary operators are usually overloaded as member functions as well, since the member version 
    has no parameters.

=============================================================================================
The following rules of thumb can help you determine which form is best for a given situation:
=============================================================================================

* If you're overloading assignment (=), subscript ([]), function call (()), or 
  member selection (->), do so as a member function.

* If you're overloading a unary operator, do so as a member function.

* If you're overloading a binary operator that does not modify its left operand (e.g. operator+), 
  do so as a normal function (preferred) or friend function.
* If you’re overloading a binary operator that modifies its left operand, but you can't add members 
  to the class definition of the left operand (e.g. operator<<, which has a left operand of type 
  ostream), do so as a normal function (preferred) or friend function.
* If you're overloading a binary operator that modifies its left operand (e.g. operator+=), and you 
  can modify the definition of the left operand, do so as a member function.
*/