#include <stdio.h>
#include <math.h>// 1

int equation(int a, int b, int c); //функция, решающая квадратное уравнение
int main()
{
    float a,b,c; //выводим коэффициенты уравнения с учетом знака
    scanf("%f%f%f", &a, &b, &c);
    equation(a,b,c);

}
int  equation(int a, int b, int c)
{
    float discriminant;
    float x1, x2;
    if (a != 0 && b != 0 && c != 0)
    {
        discriminant = b * b - 4 * a * c; // считаем дискриминант
        if (discriminant > 0) // если дискриминант больше 0, то уравнение имеет 2 решения
        {
            x1 = (-b + sqrt(discriminant)) / (2 * a);
            x2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("x1 = %f \n", x1);
            printf("x2 = %f \n", x2);
        }
        else if (discriminant == 0) // если дискриминант равен 0, то одно решение
        {
            x1 = (-b + sqrt(discriminant)) / (2 * a);
            printf("x1 = %f \n", x1);
        }
        else // иначе корни комплексные
            printf("%s\n", "корней (не комплексных) нет");
    }
    else if (a != 0)
    {
        if (c == 0 && b == 0) // если коэффициенты c и b равны 0, то корень 0
            printf("%d", 0);
        else if ( b == 0)
        {
            if (a * c > 0) // если коэффициенты a и c одного знака, то корней нет
                printf("%s", "корней нет");
            else
            {
                x1 = sqrt(-c / a);
                x2 = -sqrt(-c / a);
                printf("x1 = %f \n", x1);
                printf("x2 = %f \n", x2);
            }
        }
        else // если только c = 0, то считаем корень)))
        {
            x1 = 0;
            x2 = -b /a;
            printf("x1 = %f \n", x1);
            printf("x2 = %f \n", x2);
        }
    }
    else
        printf("%s", "это не квадратное уравнение");
}
