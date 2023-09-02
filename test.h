#ifndef TEST_H
#define TEST_H
//
//! @brief contains a file with tests and their execution
//!
//! @attention In the file in the first line the number of lines, and in further lines the  coefficientss and roots for the test
//
void test ();


//
//! @brief checks tests
//! @param [in] i   test number
//! @param [in] test_cases  are the  coefficientss and roots
//!
//! The function receives a structure of  coefficientss and estimated roots, runs the solve_equation function, which returns the estimated roots. Next, the function compares the values ​​of the estimated roots and the roots that the solve_equation function outputs.

void test_work (char test_case[], int i);
#endif
