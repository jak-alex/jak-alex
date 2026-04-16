#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

// Прототип функції
double Leng(double x1, double y1, double x2, double y2);

int main() {
    double xA, yA, xB, yB, xC, yC, xD, yD;
    int choice;

    while (1) {
        printf("\n--- МЕНЮ ---\n");
        printf("1. Ввести координати точок (A, B, C, D)\n");
        printf("2. Обчислити довжини відрізків (AB, BC, CD)\n");
        printf("3. Вихід\n");
        printf("Ваш вибір: ");

        // Перевірка на правильність вводу цифри меню
        if (scanf("%d", &choice) != 1) {
            printf("Помилка! Введіть число.\n");
            while (getchar() != '\n'); // Очищення буфера від літер
            continue;
        }

        switch (choice) {
            case 1:
                printf("Введіть A (x y): ");
                scanf("%lf %lf", &xA, &yA);
                printf("Введіть B (x y): ");
                scanf("%lf %lf", &xB, &yB);
                printf("Введіть C (x y): ");
                scanf("%lf %lf", &xC, &yC);
                printf("Введіть D (x y): ");
                scanf("%lf %lf", &xD, &yD);
                printf("Дані збережено.\n");
                break;

            case 2: {
                // Робимо обчислення
                double lengthAB = Leng(xA, yA, xB, yB);
                double lengthBC = Leng(xB, yB, xC, yC);
                double lengthCD = Leng(xC, yC, xD, yD);

                printf("\n--- Результати ---\n");
                printf("AB = %.2f\n", lengthAB);
                printf("BC = %.2f\n", lengthBC);
                printf("CD = %.2f\n", lengthCD);
                break;
            }

            case 3:
                printf("Завершення програми.\n");
                return 0;

            default:
                printf("Невірний вибір! Спробуйте ще раз.\n");
        }
    }

    return 0;
}

// Реалізація функції
double Leng(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
