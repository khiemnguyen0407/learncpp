/* SWITCH STATEMENT */

/*
Because testing a variable or expression for equality against a set of different values is common, 
C++ provides an alternative conditional statement called a switch-statement that is specialized for 
this purpose. Here is the same program as above using a switch.

The idea behind a switch statement is simple: an expression (sometimes called the condition) is 
evaluated to produce a value. Then one of the following occurs:
    * If the expression's value is equal to the value after any of the case-labels, the statements 
      after the matching case-label are executed.
    * If no matching value can be found and a default label exists, the statements after the 
      default label are executed.
    * If no matching value can be found and there is no default label, the switch is skipped.

Starting a switch
=================
We start a switch-statement by using the switch keyword, followed by parentheses with the 
conditional expression that we would like to evaluate inside. Often the expression is just a single 
variable, but it can be any valid expression.

The condition in a switch must evaluate to an integral type or an enumerated type (this topic will
be covered later down the road) or be convertible to one. Expressions that evaluate to floating 
point types, strings, and most other non-integral types may not be used here.

Following the conditional expression, we declare a block. Inside the block, we use labels to define 
all of the values we want to test for equality. There are two kinds of labels used with switch 
statements, which we'll discuss subsequently.

Case labels
=================
The first kind of label is the case label, which is declared using the case keyword and followed 
by a constant expression. The constant expression must either match the type of the condition or 
must be convertible to that type. If the value of the conditional expression equals the expression 
after a case label, execution begins at the first statement after that case label and then 
continues sequentially. There is no practical limit to the number of case labels you can have, but 
all case labels in a switch must be unique.

The default label
=================
The second kind of label is the default label (often called the default case), which is declared 
using the default keyword. If the conditional expression does not match any case label and a 
default label exists, execution begins at the first statement after the default label.
*/


// No explanation is better than an example.
#include <iostream>

void print_digit_in_word(int x)
{
    // There is no practical limit to the number of case labels you can have, 
    // but all case labels in a switch must be unique. That is, you can not do this:

    // case 54:
    // case 54:  // error: already used value 54!
    // case '6': // error: '6' converts to integer value 54, which is already used
    switch (x)
    {
    /* Labels are conventionally not indented

    We noted that code is typically indented one level after the curly braces to help identify that 
    it's part of a nested scope region. Since the curly braces of the switch defines a new scope 
    region, we would normally indent everything inside the curly braces one level.

    A label, on the other hand, does not define a nested scope. Therefore, the code following a
    label is conventionally not indented.
    */
    case 1:
        std::cout << "One";
        break;
    case 2:
        std::cout << "Two";
        break;
    case 3:
        std::cout << "Three";
        break;
    case 4:
        std::cout << "Four";
        break;

    // The default label is optional, and there can only be one default label 
    // per switch statement. By convention, the default case is placed last 
    // in the switch block.
    default:
        std::cout << "I don't know how to write this number in word!";
        break;
    }

    // After the switch statement is executed, the execution of course continues.
    std::cout << '\n';
    std::cout << "Hello there again after switch statement!";
}

int main()
{
    print_digit_in_word(2);
    std::cout << '\n';

    print_digit_in_word(42);
    return 0;
}

/* Simple question: Switch versus if-else

Switch statements are best used when there is a single expression (with a non-boolean integral type 
or an enumerated type) we want to evaluate for equality against a small number of values. If the 
number of case labels gets too large, the switch can be hard to read.

Compared to the equivalent if-else statements, a switch-statement can be more readable, makes it 
clearer that it is the same expression being tested for equality in each case, and has the 
advantage of only evaluating the expression once (making it more efficient).

However, if-else is significantly more flexible. Some cases where if or if-else is typically 
better:

    * Testing an expression for comparisons other than equality (e.g. x > 5)
    * Testing multiple conditions (e.g. x == 5 && y == 6)
    * Determining whether a value is within a range (e.g. x >= 5 && x <= 10)
    * The expression has a type that switch doesn't support (e.g. d == 4.0).
    * The expression evaluates to a bool.

It is indeed not important to remember all the cases mentioned above. Overtime, you will get 
familiar with the programming language and know which one is the best for your programming tasks.
*/