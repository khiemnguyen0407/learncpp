/* Functions can call functions that call other functions */

/* 
You have already seen that function main() can call other functions (such as function do_print() in 
the example above). The functions called by main() can also call other functions (and those 
functions can call functions too, etc...). 
*/

#include <iostream> // for std::cout

void do_job_A()
{
    std::cout << "do job A\n";
}

void do_job_B()
{
    std::cout << "start job B\n";
    std::cout << "call do_job_A in do_job_B: ";
    do_job_A();
    std::cout << "end job B\n";
}

void do_job_C()
{
    std::cout << "start job C\n";
    std::cout << "call do_job_A in do_job_C: ";
    do_job_A();

    std::cout << "call do_job_B in do_job_C: ";
    do_job_B();
    std::cout << "end job C\n";
}

// definition of function main()
int main()
{
    std::cout << "Starting main()\n";

    do_job_B();

    do_job_C();

    std::cout << "Ending main()\n";
    return 0;
}

/* 

*/