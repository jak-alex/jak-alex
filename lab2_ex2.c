#include <stdio.h>
#include <math.h>

int main() {
    // Оголошення сталих змінних
    const int a = 2;
    const int b = -2;
    const int c = 22;
    double y;

    printf("Обчислення значення функції:\n");
    printf("Вхідні дані: a = %.1d, b = %.1d, c = %.1d\n", a, b, c);

    int term1 = (a * b * c) / (a + b + c);
    int term2 = (a - b - c) / (a * b * c);
        
    y = term1 - term2;

        // Результат
        printf("\nРезультат обчислення функції y = %.4f\n", y);
    

    return 0;
}
