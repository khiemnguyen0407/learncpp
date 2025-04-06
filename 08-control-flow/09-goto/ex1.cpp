/* goto statements */


/*
Avoid using goto
========================
Before you decide to read this cpp file, I just want to inform that goto is mostly disapproved in 
modern programming. It has been mathematically proved that all of the "solvable" programming tasks 
can be implemented without using goto. So, it is perfectly fine not to learn goto statement.

Avoid using goto

Use of goto is shunned in C++ (and other modern high level languages as well). Edsger W. Dijkstra, 
a noted computer scientist, laid out the case for avoiding goto in a famous but difficult to read 
paper called Go To Statement Considered Harmful:

https://www.cs.utexas.edu/~EWD/ewd02xx/EWD215.PDF

The primary problem with goto is that it allows a programmer to jump around the code arbitrarily. 
This creates what is not-so-affectionately known as spaghetti code. Spaghetti code is code that has 
a path of execution that resembles a bowl of spaghetti (all tangled and twisted), making it 
extremely difficult to follow the logic of such code.

As Dijkstra says somewhat humorously, "the quality of programmers is a decreasing function of the 
density of go to statements in the programs they produce".

Almost any code written using a goto statement can be more clearly written using other constructs 
in C++, such as if-statements and loops. One notable exception is when you need to exit a nested 
loop but not the entire function -- in such a case, a goto to just beyond the loops is probably the 
cleanest solution.
/*

/*
The next kind of control flow statement we’ll cover is the unconditional jump. An unconditional 
jump causes execution to jump to another spot in the code. The term “unconditional” means the jump 
always happens (unlike an if-statement or switch-statement, where the jump only happens 
conditionally based on the result of an expression).

In C++, unconditional jumps are implemented via a goto statement, and the spot to jump to is 
identified through use of a statement label. Just like with switch case labels, statement labels 
are conventionally not indented.
*/

#include <iostream>
#include <cmath> // for sqrt() function

int main()
{
    double x{};
tryAgain: // this is a statement label
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0)
        goto tryAgain; // this is the goto statement

    std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';
    return 0;
}