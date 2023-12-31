#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "solution_equation.h"

float const EPS = 0.000001;

int zero_equal (float a)
{
    return abs (a - 0) < EPS;
}

int float_equal (float a, float b)
{
    return zero_equal (a - b);
}

//---------------------------------------------------------------------------------------

void solve_equation ( coefficients coof , roots* root)
{
    if (root == NULL) return;
    if (!isfinite(coof.a) && !isfinite(coof.b) && !isfinite(coof.c)) return;


    if (!zero_equal (coof.a))
    {
        float discriminant = coof.b * coof.b - 4 * coof.a * coof.c;
        if (zero_equal (discriminant))
        {
            root->x1 = -coof.b / (2 * coof.a);
            root->x2 = root -> x1;
            root->n = ONE_ROOT;
        }
        else if (discriminant > 0)
        {
            float sqrtd = sqrt (discriminant);
            float denominator = 2 * coof.a;

            root->x1 = (-coof.b + sqrtd) / denominator;
            root->x2 = (-coof.b - sqrtd) / denominator;
            root->n = TWO_ROOTS;
        }
        else
            root->n = NO_ROOT;
    }
    else
    {
        solve_linear_equation (coof, root);
    }
}

//---------------------------------------------------------------------------------------

void solve_linear_equation ( coefficients coof , roots* root)
{
    if (root == NULL) return;
    if (!isfinite(coof.b) && !isfinite(coof.c)) return;

    if (zero_equal (coof.b) && zero_equal (coof.c) )
    {
        root -> n = INFINITY_ROOTS;
    }
    else if (zero_equal (coof.b) == 1)
    {
        root -> n = NO_ROOT;
    }
    else
    {
        root -> x1 = -coof.c / coof.b;
        root -> x2 = root -> x1;
        root -> n = ONE_ROOT;
    }
}
