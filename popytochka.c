#include <stdio.h>
#include <math.h>

#define EPS 0.000001
#define ENUM 100500

int comparison0(int a); // проверка числа на равенство 0
int solve_the_equation(float a, float b, float c, float *x1, float *x2);
int solve_linear_r_the_equation(float b, float c, float **x1);

int main()
{
    float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    if ((scanf("%f", &a)) != 1 || (scanf("%f", &b)) != 1 || (scanf("%f", &c)) != 1) // проверка на правильность ввода
        printf("Неверное введенное значение");
    else // если корректный ввод, то переходит к решению уравнения
    {
        int number_of_roots = solve_the_equation(a,b,c, &x1, &x2); // запускаем функцию, считающую кол-во корней
        if (number_of_roots == 2) printf("x1 = %f, x2 = %f\n", x1, x2); //если 2 корня
        else if (number_of_roots == 1) printf("x1 = %f\n", x1); // если 1 корень
        else if (number_of_roots == 0) printf("корней нет"); // если 0 корней
        else printf("бесконечное кол-во корней");
    }
}


int comparison0(int a)
{
    if (abs(a - 0) < EPS) return 1;// если число равно 0, то выводим истину return 1;
    return 0; // иначе ложь
}


int solve_the_equation(float a, float b, float c, float *x1, float *x2)
{
    if (comparison0(a) == 0) // если а не 0
    {
        float discriminant = b * b - 4 * a * c; // считаем дискриминант;
        if (discriminant > 0) // если дискриминант больше 0
        {
            *x1 = (-b + sqrt(discriminant)) / (2 * a);
            *x2 = (-b - sqrt(discriminant)) / (2 * a);
            return 2;
        }
        else if (comparison0(discriminant) == 1) // если дискриминант 0
        {
            *x1 = -b / (2 * a);
            return 1;
        }
        return 0;
    }
    else return solve_linear_r_the_equation(b, c, &x1); // случай, если а = 0
}


int solve_linear_r_the_equation(float b, float c, float **x1)
{
    if (comparison0(b) == 1 && comparison0(c) == 1) return ENUM;
    else if(comparison0(b) == 1) return 0;
    else
    {
        **x1 = -c / b;
        return 1;
    }
}

