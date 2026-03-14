#include <stdio.h>
#include <math.h>

int main() {
    // Оголошення сталих змінних
    double a = 2.0;
    double b = -2.0;
    double c = 22.0;
    double y;

    printf("Обчислення значення функції:\n");
    printf("Вхідні дані: a = %.1f, b = %.1f, c = %.1f\n", a, b, c);

    // Перевірка на нуль 
    if ((a + b + c) == 0 || (a * b * c) == 0) {
        printf("\nПомилка: ділення на нуль! Перевірте вхідні дані.\n");
    } else {
        
        // Формула, яку я розбив на дві частини
        double term1 = (a * b * c) / (a + b + c);
        double term2 = (a - b - c) / (a * b * c);
        
        y = term1 - term2;

        // Результат
        printf("\nРезультат обчислення функції y = %.4f\n", y);
    }

    return 0;
}