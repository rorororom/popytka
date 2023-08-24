#include "solution_equation.h"
#include <stdio.h>
#include "input_roots.h"
#include "colors.h"


void input_roots(struct coefficient *coof)
{
    printf("Solve quadratic equation\n");
    printf(COLOR_GREEN("Enter the coefficients of the equation\n"));
    int verification = (scanf("%f%f%f", &coof->a, &coof->b, &coof->c));
    while (verification != 3)
    {
        printf(COLOR_RED("Invalid value entered\n"));
        while(getchar() != '\n');
        verification = (scanf("%f%f%f", &coof->a, &coof->b, &coof->c));
    }
}
