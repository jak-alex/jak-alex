#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Для випадкових чисел

    int n;
    printf("Введіть розмір квадратної матриці (n): ");
    scanf("%d", &n);

    double a[n][n];
    double sum_main = 0, sum_side = 0;

    // Генерируємо матрицю та виводимо її
    printf("\nЗгенерована матриця:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            // Формула для double в діапазоні [-100, 100]
            a[i][j] = ((double)rand() / RAND_MAX) * 200.0 - 100.0;
            printf("%7.2f ", a[i][j]);

            // Рахуємо головну діагональ (i == j)
            if (i == j) sum_main += a[i][j];
            
            // Рахуємо побічну діагональ (i + j == n - 1)
            if (i + j == n - 1) sum_side += a[i][j];
        }
        printf("\n");
    }

    printf("\nСума головної діагоналі: %.2f", sum_main);
    printf("\nСума побічної діагоналі: %.2f\n", sum_side);

    // Перевіряємоооо
    if (sum_main > sum_side) {
        printf("\nУмова виконана (головна > побічної). Транспонуємо матрицю...\n");
        
        // Транспонуємо
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
            }
        }

        // Ось наш шедевр
        printf("\nРезультат транспонування:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%7.2f ", a[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nУмова не виконана (головна <= побічної). Матриця залишається без змін.\n");
    }

    return 0;
}