#include "input_roots.h"
#include "print_roots.h"
#include "solution_equation.h"
#include "test.h"

int main ()
{
#ifdef DO_TEST
    test ();
#else
    roots root = {};
     coefficients coof = {};

    input_roots (&coof);
    solve_equation (coof, &root);
    print_roots (root);
#endif
}




