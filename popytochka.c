#include <stdio.h>
#include <math.h>
#include <assert.h>


#define EPS 0.000001
enum root{
    NO_ROOTS,
    ONE_ROOTS,
    TWO_ROOTS,
    INFINITY_ROOTS
};

struct coefficient{
    float a;
    float b;
    float c;
};

struct roots{
    float x1;
    float x2;
    int n;
};


int comparison0(float a);
int solve_the_equation(coefficient coof , roots* root);
int solve_linear_the_equation(coefficient coof , roots* root);

int main()
{
    struct coefficient coof = {0,0,0};
    printf("Enter the coefficients of the equation\n");
    if ((scanf("%f%f%f", &coof.a, &coof.b, &coof.c)) != 3)
    printf("Invalid value entered\n");
    else
    {
        struct roots root = {0,0,0};
        root.n = solve_the_equation(coof, &root);
        switch (root.n)
        {
            case TWO_ROOTS: printf("x1 = %f, x2 = %f\n", root.x1, root.x2);
                break;
            case ONE_ROOTS: printf("x = %f\n", root.x1);
                break;
            case NO_ROOTS: printf("No roots\n");
                break;
            case INFINITY_ROOTS: printf("Infinite number of roots\n");
                break;
            default: printf("Something went wrong");
        }
    }
}


int comparison0(float a)
{
    if (abs(a - 0) < EPS) return 1;
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

