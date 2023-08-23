#include "solution_equation.h"
#include <stdio.h>
#include <assert.h>
#include "test.h"
#include "colors.h"


typedef struct TestCase
{
    float a;
    float b;
    float c;
    float x1;
    float x2;
    int n;
} TestCase;


void test_work(struct TestCase test_cases, int i)
{
    roots answer = {0,0,0};
    coefficient coeff = {test_cases.a, test_cases.b, test_cases.c};
    solve_equation(coeff, &answer);
    if (!(float_equal(test_cases.x1, answer.x1)
       && float_equal(test_cases.x2, answer.x2)
       && float_equal(test_cases.n, answer.n)))
        printf(COLOR_RED("FAILD\n") "test %d, received data {%f, %f, %f}\n"
                "expected data {%f, %f, %d}\n"
                "answer {%f, %f, %d}\n\n", i+1, test_cases.a, test_cases.b, test_cases.c,
                test_cases.x1, test_cases.x2, test_cases.n,
                answer.x1, answer.x2, answer.n);
    else
        printf(COLOR_GREEN("OKEY") " test %d correct\n\n", i+1);
}


void test()
{
    TestCase test_cases[7] = {
    {  1,  -6,   9,   3,   3,  ONE_ROOTS},
    {0.5,   3,   4,  -2,  -4,  TWO_ROOTS},
    {  0,   0,   0,   0,   0,  INFINITY_ROOTS},
    {  0,   0,   1,   0,   0,  NO_ROOTS},
    {  0,   1,   0,   0,   0,  ONE_ROOTS},
    {  0,   5, -10,   2,   2,  ONE_ROOTS},
    {  1,   0,  -4,   2,  -2,  TWO_ROOTS}
    };
    for (int i = 0; i < int(sizeof(test_cases) / sizeof(TestCase)); i++)
        test_work(test_cases[i], i);

}
