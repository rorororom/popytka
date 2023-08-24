#include <stdio.h>

#include "colors.h"
#include "print_roots.h"
#include "solution_equation.h"

// do_while moment?
// caps
#define dbg_printf(str)                                                      \
    printf("Failed in function %s:%d\n", __PRETTY_FUNCTION__, __LINE__);     \
    printf(str);

#define TEST_do_WHILE(str) \
    do { str } while(0)

void print_roots(roots root)
{
    // TEST_do_WHILE(printf("test") ;);
    switch (root.n)
    {
        case TWO_ROOTS: {
            printf(COLOR_MAGENTA("x1 = %f, x2 = %f\n"), root.x1, root.x2);
            break;
        }

        case ONE_ROOTS:
            printf(COLOR_MAGENTA("x = %f\n"), root.x1);
            break;

        case NO_ROOTS:
            printf(COLOR_MAGENTA("No roots\n"));
            break;

        case INFINITY_ROOTS:
            printf(COLOR_MAGENTA("Infinite number of roots\n"));
            break;

        default:
            dbg_printf("Wrong amount of roots\n")
            break;
    }
}
