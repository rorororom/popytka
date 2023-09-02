#include <stdio.h>

#include "colors.h"
#include "input_validation.h"
#include "solution_equation.h"

void input_validation (struct  coefficients *coof)
{
    int verification = scanf ("%f%f%f", &coof->a, &coof->b, &coof->c);

    while (verification != 3)
    {
        printf (COLOR_RED ("Invalid value entered\n"));
        int n = 0;

        do {
            n = getchar ();
        } while (n != '\n' && n != EOF);

        if (verification == EOF) break;

        verification = scanf ("%f%f%f", &coof->a, &coof->b, &coof->c);

    }
}

