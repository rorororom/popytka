#include <stdio.h>
#include <math.h>

#define EPS 0.000001


int comparison0(int a); // проверка числа на равенство 0
int proverka_na_kolvo_korney(int a, int b, int c);
void chitaem_2_kornya(float *x1, float *x2, int a, int b, int c);
void chitaem_1_koren(float *x1, int a, int b, int c);


int main() {
    float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    if ((scanf("%f", &a)) != 1 || (scanf("%f", &b)) != 1 || (scanf("%f", &c)) != 1) // проверка на правильность ввода
        printf("Неверное введенное значение");
    else // если корректный ввод, то переходит к решению уравнения
    {
        if (comparison0(a) == 0) // если а не 0
        {
            if (proverka_na_kolvo_korney(a, b, c) == 2) {
                chitaem_2_kornya(&x1, &x2, a, b, c);
                printf("x1 = %f, x2 = %f\n", x1, x2);
            } else if (proverka_na_kolvo_korney(a, b, c) == 0)
                printf("корней нет");
            else {
                chitaem_1_koren(&x1, a, b, c);
                printf("x1 = %f\n", x1);
            }
        } else
            printf("это не квадратное уравнение");
    }
}


int comparison0(int a) {
    if (abs(a - 0) < EPS) // если число равно 0, то выводим истину
        return 1;
    return 0; // иначе ложь
}


int proverka_na_kolvo_korney(int a, int b, int c) {
    float discriminant;
    discriminant = b * b - 4 * a * c; // считаем дискриминант
    if (discriminant > 0) // если дискриминант больше 0
        return 2;
    else if (comparison0(discriminant) == 1) // если дискриминант 0
        return 1;
    return 0;
}


void chitaem_2_kornya(float *x1, float *x2, int a, int b, int c) {
    float discriminant = b * b - 4 * a * c;
    *x1 = (-b + sqrt(discriminant)) / (2 * a);
    *x2 = (-b - sqrt(discriminant)) / (2 * a);
}


void chitaem_1_koren(float *x1, int a, int b, int c) {
    float discriminant = b * b - 4 * a * c;
    *x1 = (-b + sqrt(discriminant)) / (2 * a);
}
