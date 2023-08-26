#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "colors.h"
#include "solution_equation.h"
#include "test.h"

typedef struct TestCase
{
    static const unsigned int LEN = 128;
    char str[LEN];
    struct {
		float a;
        float b;
        float c;
	} coefficient;
    struct {
        float x1;
        float x2;
        int n;
	} roots;
} TestCase;

void test_work(TestCase test_cases, int i)
{
    roots answer = {0,0,0};
    coefficient coeff = {test_cases.coefficient.a, test_cases.coefficient.b, test_cases.coefficient.c};

    solve_equation(coeff, &answer);
    if (!(float_equal(test_cases.roots.x1, answer.x1)
       && float_equal(test_cases.roots.x2, answer.x2)
       && float_equal(test_cases.roots.n, answer.n)))

    {
        printf(COLOR_RED("FAILED ") "test " COLOR_CYAN("%s ")"%d\n"
                COLOR_YELLOW("received data ") "{ %f,  %f, %f}\n"
                COLOR_YELLOW("expected data ") "{ %f,  %f,        %d}\n"
                COLOR_YELLOW("answer        ") "{%f, %f,        %d}\n\n", test_cases.str, i+1,
                test_cases.coefficient.a, test_cases.coefficient.b, test_cases.coefficient.c,
                test_cases.roots.x1, test_cases.roots.x2, test_cases.roots.n,
                answer.x1, answer.x2, answer.n);
    }

    else
    {
        printf(COLOR_GREEN("OKEY") " test "
               COLOR_CYAN("%s ") "%d correct\n\n",
               test_cases.str, i+1);
    }
}

void test()
{
    FILE *TestFile = fopen("test.txt", "r");
    TestCase test_case;
    assert(TestFile);
    int n = 0;
    fscanf(TestFile, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (fscanf(TestFile, "%s %f %f %f %f %f %d",
                   &test_case.str, &test_case.coefficient.a,
                   &test_case.coefficient.b, &test_case.coefficient.c,
                   &test_case.roots.x1, &test_case.roots.x2, &test_case.roots.n) == 7)
        {
            test_work(test_case, i);
        }
        else
        {
            printf(COLOR_RED("wrong data for equations in file on line ")
                   COLOR_CYAN("%d\n\n"), i+1);
        }
    }
    fclose(TestFile);
}





