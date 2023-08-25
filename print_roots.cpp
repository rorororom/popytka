#include <stdio.h>

#include "colors.h"
#include "print_roots.h"
#include "solution_equation.h"

#define dbg_printf(str)                                                          \
    do {                                                                         \
        printf("Failed in function %s:%d\n", __PRETTY_FUNCTION__, __LINE__);     \
        printf(str);                                                             \
    } while (0)

void print_roots(roots root)
{
    switch (root.n)
    {
        case TWO_ROOTS: {
            printf(COLOR_MAGENTA("x1 = %f, x2 = %f\n"), root.x1, root.x2);
            break;
        }

        case ONE_ROOT:
            printf(COLOR_MAGENTA("x = %f\n"), root.x1);
            break;

        case NO_ROOT:
            printf(COLOR_MAGENTA("No roots\n"));
            break;

        case INFINITY_ROOTS:
            printf(COLOR_MAGENTA("Infinite number of roots\n"));
            break;

        default:
            dbg_printf("Wrong amount of roots\n");
            break;
    }
}
