/* Control Flow: Introduction */

/*
When a program is run, the CPU begins execution at the top of main(), executes some number of 
statements (in sequential order by default), and then the program terminates at the end of main(). 
The specific sequence of statements that the CPU executes is called the program’s execution path 
(or path, for short).

At this point of time, I don't think I need to explain how important control flow in programming
language is. We will go through important control statements that we have learned in Python.

(1) Conditional statements
    Causes a sequence of code to execute only if some condition is met
    Implemented in C++ by: if, else, switch
(2) Jumps
    Tells the CPU to start executing the statements at some other location
    Implemented in C++ by: goto, break, continue
    goto is however not recommended in modern programming languages. So, we don't need to cover it.
(3) Function calls
    Jump to some other location and back.
    Implemented in C++ by: function calls, return
(4) Loops
    Repeatedly execute some sequence of code zero or more times, until some condition is met.
    Implemented in C++ by: while, do-while, for, ranged-for
(5) Halts
    Terminate the program.
    Implemented in C++ by: std::exit(), std::abort()
(6) Exceptions
    A special kind of flow control structure designed for error handling
    Implemented in C++ by: try, throw, catch

We won't cover (5) and (6) in the lectures and these are the advanced topics that won't appear in
the examinations.
*/