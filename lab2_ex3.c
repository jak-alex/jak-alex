#include <stdio.h>
#include <math.h>

int main() {
    int x, y;
    double f;

    printf("Обчислення значення функції f(x, y)\n");

    // Введення цілих значень
    printf("Введіть ціле число x: ");
    scanf("%d", &x);
    
    printf("Введіть ціле число y: ");
    scanf("%d", &y);
    
    // Формула: f = (x^2 + xy - y^2) / (1 + x^2 + y^2)

    double numerator = pow(x, 2) + (x * y) - pow(y, 2);
    double denominator = 1 + pow(x, 2) + pow(y, 2);

    f = numerator / denominator;

    // Результат
    printf("\nЗадані значення: x = %d, y = %d\n", x, y);
    printf("Результат функції f = %.5f\n", f);

    return 0;
}
