/* Returning *this */

/*
Second, it can sometimes be useful to have a member function return the implicit object as a return 
value. The primary reason to do this is to allow member functions to be "chained" together, so 
several member functions can be called on the same object in a single expression! This is called 
function chaining (or method chaining).

Consider this common example where you're outputting several bits of text using std::cout:
    std::cout << "Hello, " << user_name;
First, operator<< uses std::cout and the string literal "Hello, " to print "Hello, " to the console. 
However, since this is part of an expression, operator<< also needs to return a value (or void). 
If operator<< returned void, you’d end up with this as the partially evaluated expression:
    void{} << user_name;
which clearly doesn’t make any sense (and the compiler would throw an error). Instead, operator<< 
returns the stream object that was passed in, which in this case is std::cout. That way, after the 
first operator<< has been evaluated, we get:
    (std::cout) << user_name;

This way, we only need to specify std::cout once, and then we can chain as many pieces of text 
together using operator<< as we want. Each call to operator<< returns std::cout so the next call to 
operator<< uses std::cout as the left operand.

We can implement this kind of behavior in our member functions too. Consider the following class:

class Calc
{
private:
    int value{};

public:

    void add(int value) { this->value += value; }
    void sub(int value) { this->value -= value; }
    void mult(int value) { this->value *= value; }

    int get_value() const { return this->value; }
};

If you wanted to add 5, subtract 3, and multiply by 4, you’d have to do this:
#include <iostream>

int main()
{
    Calc calc{};
    calc.add(5); // returns void
    calc.sub(3); // returns void
    calc.mult(4); // returns void

    std::cout << calc.getValue() << '\n';

    return 0;
}
However, if we make each function return *this by reference, we can chain the calls together. Here 
is the new version of Calc with "chainable" functions
*/

#include <iostream>
class Calc
{
private:
    int value{};

public:
    Calc& add(int value) { this->value += value; return *this; }
    Calc& sub(int value) { this->value -= value; return *this; }
    Calc& mult(int value) { this->value *= value; return *this; }

    int get_value() const { return m_value; }
};


int main()
{
    Calc calc{};
    calc.add(5).sub(3).mult(4); // method chaining

    std::cout << calc.get_value() << '\n';

    return 0;
}

/* Discussion:
We have effectively condensed three lines into one expression! Let's take a closer look at how this 
works. 

First, calc.add(5) is called, which adds 5 to m_value. add() then returns a reference to *this, 
which is a reference to implicit object calc, so calc will be the object used in the subsequent 
evaluation. Next calc.sub(3) evaluates, which subtracts 3 from m_value and again returns calc. 
Finally, calc.mult(4) multiplies m_value by 4 and returns calc, which isn't used further, and is 
thus ignored. Since each function modified calc as it was executed, the value of calc now contains 
the value (((0 + 5) - 3) * 4), which is 8.

You should consider whenever it makes sense to have chainable member functions.

*/