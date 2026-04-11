#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Випадкове число
    int choice;

    do {
        // Меню
        printf("\n========================================\n");
        printf("    АНАЛІЗ ТА ТРАНСПОНУВАННЯ МАТРИЦІ    \n");
        printf("========================================\n");
        printf("1. Згенерувати матрицю та перевірити діагоналі\n");
        printf("0. Вийти з програми\n");
        printf("========================================\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int n;

            // Перевірка розміру (n має бути > 0)
            do {
                printf("\nВведіть розмір квадратної матриці (n > 0): ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("Помилка! Розмір має бути додатним числом.\n");
                }
            } while (n <= 0);

            double a[n][n];
            double sum_main = 0, sum_side = 0;

            // Генерація та вивід матриці
            printf("\nЗгенерована матриця [%dx%d]:\n", n, n);
            for (int i = 0; i < n; i++) {
                printf("| ");
                for (int j = 0; j < n; j++) {
                    // Числа в діапазоні [-100.0, 100.0]
                    a[i][j] = ((double)rand() / RAND_MAX) * 200.0 - 100.0;
                    printf("%8.2f ", a[i][j]);

                    // Сума головної діагоналі
                    if (i == j) sum_main += a[i][j];
                    
                    // Сума побічної діагоналі
                    if (i + j == n - 1) sum_side += a[i][j];
                }
                printf(" |\n");
            }

            printf("\nСума головної діагоналі: %.2f\n", sum_main);
            printf("Сума побічної діагоналі: %.2f\n", sum_side);

            // Порівняння та транспонування
            if (sum_main > sum_side) {
                printf("\n[Умова виконана: %.2f > %.2f]\n", sum_main, sum_side);
                printf("Транспонуємо матрицю (рядки стають стовпцями)...\n");
                
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        double temp = a[i][j];
                        a[i][j] = a[j][i];
                        a[j][i] = temp;
                    }
                }

                printf("\nРезультат транспонування:\n");
                for (int i = 0; i < n; i++) {
                    printf("| ");
                    for (int j = 0; j < n; j++) {
                        printf("%8.2f ", a[i][j]);
                    }
                    printf(" |\n");
                }
            } else {
                printf("\n[Умова не виконана: %.2f <= %.2f]\n", sum_main, sum_side);
                printf("Матриця залишається без змін.\n");
            }

        } else if (choice != 0) {
            printf("\n[!] Невірна команда. Спробуйте ще раз.\n");
        }

    } while (choice != 0);

    printf("\nПрограма завершена\n");
    return 0;
}
