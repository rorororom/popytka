#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "functions.h"
#include "test.h"





int main()
{
    // struct coefficient coof = {0,0,0};
    // printf("Enter the coefficients of the equation\n");
    // if ((scanf("%f%f%f", &coof.a, &coof.b, &coof.c)) != 3)
    // printf("Invalid value entered\n");
    // else
    // {
    //     struct roots root = {0,0,0};
    //     root.n = solve_the_equation(coof, &root);
    //     switch (root.n)
    //     {
    //         case TWO_ROOTS: printf("x1 = %f, x2 = %f\n", root.x1, root.x2);
    //             break;
    //         case ONE_ROOTS: printf("x = %f\n", root.x1);
    //             break;
    //         case NO_ROOTS: printf("No roots\n");
    //             break;
    //         case INFINITY_ROOTS: printf("Infinite number of roots\n");
    //             break;
    //         default: printf("Something went wrong");
    //     }
    // }
    test();
}



