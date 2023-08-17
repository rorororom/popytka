#include <stdio.h>
#include <math.h>

#define EPS 0.000001


int comparison0(int a); // проверка числа на равенство 0
int solve_the_equation(int a, int b, int c, float *x1, float *x2);


int main() {
    float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    if ((scanf("%f", &a)) != 1 || (scanf("%f", &b)) != 1 || (scanf("%f", &c)) != 1) // проверка на правильность ввода
        printf("Неверное введенное значение");
    else // если корректный ввод, то переходит к решению уравнения
    {
        if (comparison0(a) == 0) // если а не 0
        {
            int number_of_roots = solve_the_equation(a,b,c, &x1, &x2); // запускаем функцию, считающую кол-во корней
            if (number_of_roots == 2) //если 2 корня
                printf("x1 = %f, x2 = %f\n", x1, x2);
            else if (number_of_roots == 1)  // если 1 корень
                printf("x1 = %f\n", x1);
            else // если 0 корней
                printf("корней нет");
        }
        else { // случай, если а = 0
            if (comparison0(b) == 1)
                printf("корней нет");
            else
                printf("x1 = %f\n", -c / b);
        }
    }
}


int comparison0(int a) {
    if (abs(a - 0) < EPS) // если число равно 0, то выводим истину
        return 1;
    return 0; // иначе ложь
}


int solve_the_equation(int a, int b, int c, float *x1, float *x2)
{
    float discriminant;
    discriminant = b * b - 4 * a * c; // считаем дискриминант
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
