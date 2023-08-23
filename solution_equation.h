typedef struct coefficient
{
    float a;
    float b;
    float c;
} coefficient;


typedef struct roots
{
    float x1;
    float x2;
    int n;
} roots;


enum root
{
    NO_ROOTS,
    ONE_ROOTS,
    TWO_ROOTS,
    INFINITY_ROOTS
};


int square_solver0(float a);
void solve_equation(coefficient coof , roots* root);
void solve_linear_equation(coefficient coof , roots* root);
int float_equal(float a, float b);
void user_input();

