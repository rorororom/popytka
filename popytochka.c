#include <stdio.h>
#include <math.h>


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


int comparison0(int a);
int solve_the_equation(float a, float b, float c, float *x1, float *x2);
int solve_linear_the_equation(float b, float c, float *x1);

int main()
{
    float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    if ((scanf("%f%f%f", &a, &b, &c)) != 3)
        printf("Неверное введенное значение");
    else
    {
        printf("kek0\n");
        int nRoots = solve_the_equation(a,b,c, &x1, &x2);
        switch (nRoots)
        {
            case TWO_ROOTS: printf("x1 = %f, x2 = %f\n", x1, x2);
                break;
            case ONE_ROOTS: printf("x = %f\n", x1);
                break;
            case NO_ROOTS: printf("корней нет");
                break;
            case INFINITY_ROOTS: printf("бесконечное кол-во корней");
                break;
            default: printf("");
        }
    }
}


int comparison0(float a)
{
    if (abs(a - 0) < EPS) return 1;
    return 0;
}


int solve_the_equation(float a, float b, float c, float *x1, float *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    printf("kek1\n");
    if (comparison0(a) == 0)
    {
        printf("kek2\n");
        float discriminant = b * b - 4 * a * c;
        if (comparison0(discriminant) == 1)
        {
            printf("sg\n");
            *x1 = -b / (2 * a);
            return ONE_ROOTS;
        }
        else if (discriminant > 0)
        {
            *x1 = (-b + sqrt(discriminant)) / (2 * a);
            *x2 = (-b - sqrt(discriminant)) / (2 * a);
            return TWO_ROOTS;
        }
        return NO_ROOTS;
    }
    else return solve_linear_the_equation(b, c, x1);
}


int solve_linear_the_equation(float b, float c, float *x1)
{
    if (comparison0(b) == 1 && comparison0(c) == 1) return INFINITY_ROOTS;
    else if(comparison0(b) == 1) return NO_ROOTS;
    else
    {
        *x1 = -c / b;
        return ONE_ROOTS;
    }

}

