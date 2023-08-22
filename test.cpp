#include "functions.h"
#include <stdio.h>
#include "test.h"

#define test_case(a_cof,b_cof,c_cof,first_root,second_y,n_root)\
    coof = {a_cof,b_cof,c_cof};\
    expected_root = {first_root,second_y,n_root};\
    roots={0,0,0};\
    solve_the_equation(coof , &roots);\
    if(comparison(expected_root.x1,roots.x1) && comparison(expected_root.x2,roots.x2) && comparison(expected_root.n,roots.n)) \
        cnt_r+=1;\
    else{\
        cnt_r+=1;\
        printf("faild test %d, received data {%f, %f,%f},\n expected data {%f, %f,%d},\n answer {%f, %f,%d}\n", cnt_r, coof.a,coof.b,coof.c,expected_root.x1,expected_root.x2,expected_root.n, roots.x1, roots.x2, roots.n);}\


void test()
{
    int cnt_r = 0;
    struct coefficient coof = {0,0,0};
    struct roots expected_root = {0,0,0};
    struct roots roots = {0,0,0};
    test_case(1,-6,9,3,3,2)
    test_case(0,0,0,0,0,3)
    test_case(0,0,1,0,0,0)
    printf("%d\n", cnt_r);
    // test_case({0,1,0}, {0,0,1})
    // test_case({0,5,6}, {-1.2,0,1})
    // test_case({1,0,0}, {0,0,1})

}
