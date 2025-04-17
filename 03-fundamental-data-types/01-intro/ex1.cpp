/* Fundamental data types */

/*
The C++ language comes with many predefined data types available for your use. The most basic of 
these types are called the fundamental data types (informally sometimes called basic types or 
primitive types).

Here is a list of the fundamental data types, some of which you have already seen:

Types	                Category	            Meaning	                                            Example
float                   Floating Point	        a number with a fractional part	                    3.14
double
long double	
bool	                Integral (Boolean)	    true or false	                                    true
char                    Integral (Character)    a single character of text	                        'c'
wchar_t
char8_t (C++20)
char16_t (C++11)
char32_t (C++11)		
short int               Integral (Integer)      positive and negative whole numbers, including 0    64
int
long int
long long int (C++11)	
std::nullptr_t (C++11)	Null Pointer	        a null pointer	                                    nullptr
void	                Void	                no type	n/a
*/

/*
Integer vs integral types
*/

#include <iostream>
int main()
{
    // floating point number -- real number in mathematics
    float x1 { 3.14 };
    double x2 { 3.1415 };
    long double x3 { 3.1415 };

    // boolean variable storing value "true" or "false"
    bool b1 { true };
    bool b2 { false };
    
    // Character. You do not need to worry too much about other complex char-type data types.
    char c { 'a' };
    
    // Integer: You probably mostly use the data type "int"
    int i2 { 24 };          
    short int i1 { 42 };    // smaller size than int

    // We talk about null pointer later.
    
    std::cout << "x1 = " << x1 << "\nx2 = " << x2 << "\nx3 = " << x3 << '\n';

    // The boolean "true" is represented as "1", "false" as "0"
    std::cout << "b1 = " << b1 << "\nb2 = " << b2 << '\n';

    // To print out "true" or "false", we must use std::boolalpha
    std::cout << "b1 = " << std::boolalpha << b1 << "\nb2 = " << std::boolalpha << b2 << '\n'; 
    return 0;
}