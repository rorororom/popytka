#include "solution_equation.h"
#include "test.h"
#include "input_roots.h"
#include "print_roots.h"
#include <stdio.h>

int main()
{
#ifdef DO_TEST
    test();
#else
    roots root = {0,0,0};
    coefficient coof = {0,0,0};
    input_roots(&coof);
    solve_equation(coof, &root);
    print_roots(root);
#endif
}



