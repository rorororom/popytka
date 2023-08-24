typedef struct coefficient
{
    float a, b, c;
} coefficient;


typedef struct roots
{
    float x1, x2;
    int n;
} roots;


enum root
{
    NO_ROOTS,
    ONE_ROOTS,
    TWO_ROOTS,
    INFINITY_ROOTS
};

//
//! @brief function zero_equal compares a number with zero
//! @param [in] a   a-number equal to zero
//! @return true or false depending on whether the number is equal to zero
//
int zero_equal(float a);

//
//! @brief function solve_equation solves quadratic equation
//! @param [in] a   a-number equal to zero
//! @return true or false depending on whether the number is equal to zero
//
void solve_equation(coefficient coof , roots* root);


void solve_linear_equation(coefficient coof , roots* root);

//
//! @brief function float_equal compares two floats (a,b)
//! @param [in] a
//! @param [in] b
//! @return true or false depending on the equality of two floats
//
int float_equal(float a, float b);



