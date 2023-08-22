#include "functions.h"
#include <stdio.h>
#include <math.h>

#define EPS 0.000001
enum root{
    NO_ROOTS,
    ONE_ROOTS,
    TWO_ROOTS,
    INFINITY_ROOTS
};


int comparison0(float a)
{
    if (abs(a - 0) < EPS) return 1;
    return 0;
}

int comparison(float a, float b)
{
    if (abs(a - b) < EPS) return 1;
    return 0;
}



int solve_the_equation(coefficient coof , roots* root)
{
    assert(root != NULL);
    if (comparison0(coof.a) == 0)
    {
        float discriminant = coof.b * coof.b - 4 * coof.a * coof.c;
        if (comparison0(discriminant) == 1)
        {
            root -> x1 = -coof.b / (2 * coof.a);
            return ONE_ROOTS;
        }
        else if (discriminant > 0)
        {
            root -> x1 = (-coof.b + sqrt(discriminant)) / (2 * coof.a);
            root -> x2 = (-coof.b - sqrt(discriminant)) / (2 * coof.a);
            return TWO_ROOTS;
        }
        return NO_ROOTS;
    }
    else return solve_linear_the_equation(coof, root);
}


int solve_linear_the_equation(coefficient coof , roots* root)
{
    assert(root != NULL);
    if (comparison0(coof.b) == 1 && comparison0(coof.c) == 1) return INFINITY_ROOTS;
    else if(comparison0(coof.b) == 1) return NO_ROOTS;
    else
    {
        root -> x1 = -coof.c / coof.b;
        return ONE_ROOTS;
    }

}
