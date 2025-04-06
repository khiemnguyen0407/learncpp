/* Status code */

/*
You may be wondering why we return 0 from main(), and when we might return something else.

The return value from main() is sometimes called a status code (or less commonly, an exit code, or 
rarely a return code). The status code is used to signal whether your program was successful or not.

By convention, a status code of 0 means the program ran normally (meaning the program executed and 
behaved as expected). A non-zero status code is often used to indicate some kind of failure (and 
while this works fine on most operating systems, strictly speaking, it's not guaranteed to be 
portable).

Best practice:
Your main function should return the value 0 if the program ran normally.

For advanced readers:
=====================
The C++ standard only defines the meaning of 3 status codes: 0, EXIT_SUCCESS, and EXIT_FAILURE. 
0 and EXIT_SUCCESS both mean the program executed successfully. EXIT_FAILURE means the program did 
not execute successfully.

EXIT_SUCCESS and EXIT_FAILURE are preprocessor macros defined in the <cstdlib> header.

If you want to maximize portability, you should only use 0 or EXIT_SUCCESS to indicate a successful 
termination, or EXIT_FAILURE to indicate an unsuccessful termination. Note: We cover the 
preprocessor and preprocessor macros in later lesson.

The status code is passed back to the operating system. The OS will typically make the status code 
available to whichever program launched the program returning the status code. This provides a 
crude mechanism for any program launching another program to determine whether the launched program 
ran successfully or not.
*/

#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE
#include <iostream>
int main()
{
    std::cout << "Write something before returning EXIT_SUCCESS\n";
    // The program will return 0 (EXIT_SUCCESS) to the operating system
    // when it reaches the end of main() or when it executes a return statement.
    return EXIT_SUCCESS;
}
