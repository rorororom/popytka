struct coefficient{
    float a;
    float b;
    float c;
};

struct roots{
    float x1;
    float x2;
    int n;
};


int comparison0(float a);
int solve_the_equation(coefficient coof , roots* root);
int solve_linear_the_equation(coefficient coof , roots* root);
int comparison(float a, float b);

