#include <stdio.h>

#include "colors.h"
#include "input_roots.h"
#include "input_validation.h"
#include "solution_equation.h"

void input_roots (struct  coefficients *coof)
{
    printf (COLOR_YELLOW ("Solve quadratic equation\n"));
    printf (COLOR_GREEN ("Enter the  coefficientss of the equation\n"));

    input_validation (coof);
}

