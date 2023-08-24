#include "solution_equation.h"
#include <math.h>
#include <assert.h>
#include <stdio.h>


#define EPS 0.000001



int zero_equal(float a)
{
    return abs(a - 0) < EPS;
}



int float_equal(float a, float b)
{
    return (abs(a - b) < EPS);
}


void solve_equation(coefficient coof , roots* root)
{
    assert(root != NULL);
    assert(isfinite(coof.a));
    assert(isfinite(coof.b));
    assert(isfinite(coof.c));

    if (!zero_equal(coof.a))
    {
        float discriminant = coof.b * coof.b - 4 * coof.a * coof.c;
        if (zero_equal(discriminant))
        {
            root->x1 = -coof.b / (2 * coof.a);
            root->x2 = root -> x1;
            root->n = ONE_ROOTS;
        }
        else if (discriminant > 0)
        {
            root->x1 = (-coof.b + sqrt(discriminant)) / (2 * coof.a);
            root->x2 = (-coof.b - sqrt(discriminant)) / (2 * coof.a);
            root->n = TWO_ROOTS;
        }
        else
            root->n = NO_ROOTS;
    }
    else
    {
        solve_linear_equation(coof, root);
    }
}


void solve_linear_equation(coefficient coof , roots* root)
{
    assert(root != NULL);
    assert(isfinite(coof.c));
    assert(isfinite(coof.b));

    if (zero_equal(coof.b) && zero_equal(coof.c) )
    {
        root -> n = INFINITY_ROOTS;
    }
    else if (zero_equal(coof.b) == 1)
    {
        root -> n = NO_ROOTS;
    }
    else
    {
        root -> x1 = -coof.c / coof.b;
        root -> x2 = root -> x1;
        root -> n = ONE_ROOTS;
    }

}
