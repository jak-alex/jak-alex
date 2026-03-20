#include <stdio.h>
#include <math.h>

int main() {
    int x, y, z;
    double t;
    int is_correct = 0; 

    while (is_correct == 0) {
        printf("\nВведіть цілі числа x, y, z через пробіл: ");
        scanf("%d %d %d", &x, &y, &z);

        if (z == 0) {
            printf("Помилка: z не може бути 0 (ділення y/z). Спробуйте ще раз.\n");
            continue;
        }

        double denominator = x - (1.0 / (1.0 + x * x));
        
        if (denominator == 0) {
            printf("Помилка: для таких x знаменник дорівнює 0. Спробуйте інші значення.\n");
            continue;
        }

        is_correct = 1; 

        t = (1.0 + z) * ( (x + (double)y / z) / denominator );

        printf("\nРезультат: t = %.4f\n", t);
    }

    printf("Програма завершена.\n");

    return 0;
}