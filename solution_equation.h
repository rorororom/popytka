#ifndef SOLUTION_EQUATION_H
#define SOLUTION_EQUATION_H

/**
 * @brief equation coefficients
 * @param a coefficient at x^2
 * @param b coefficient at x
 * @param c coefficient with x
 */
typedef struct coefficient
{
    float a;
    float b;
    float c;
} coefficient;

/**
 * @brief roots coefficients
 * @param x1 first root
 * @param x2 second root
 * @param n number of roots
 */
typedef struct roots
{
    float x1;
    float x2;
    int n;
} roots;

enum root
{
    NO_ROOT,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITY_ROOTS
};

//
//! @brief compares a number with zero
//! @param [in] a   number equal to zero
//! @return True or false depending on whether the number is equal to zero
//
int zero_equal(float a);

//
//! @brief calculates a quadratic equation
//! @param[in] coof these are the coefficients of the equation
//! @param[in,out] root these are the roots of the equation, which, when solved, will be obtained and rewritten
//!
//! @attention If a = 0, then the solve_linear_equation is called
//!
//! The function receives a structure of coefficients and estimated roots, runs the solve_equation function, which returns the estimated roots. Next, the function compares the values ​​of the estimated roots and the roots that the solve_equation function outputs.
void solve_equation(coefficient coof , roots* root);

//
//! @brief calculates a linear equation
//! @param [in] coof these are the coefficients of the equation
//! @param [in,out] root these are the roots of the equation, which, when solved, will be obtained and rewritten
//!
//!
//! The function receives a structure of coefficients and estimated roots, runs the solve_equation function, which returns the estimated roots. Next, the function compares the values ​​of the estimated roots and the roots that the solve_equation function outputs.
void solve_linear_equation(coefficient coof , roots* root);

//
//! @brief compares two floats
//! @param [in] a first number to compare
//! @param [in] b second number to compare
//!
//! @return True or false depending on the equality of two floats
//
int float_equal(float a, float b);

#endif 



