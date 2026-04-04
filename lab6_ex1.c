#include <stdio.h>

int main() {
    int n, m;
    int sum = 0;

    printf("Введіть кількість рядків (n): ");
    scanf("%d", &n);
    printf("Введіть кількість стовпців (m): ");
    scanf("%d", &m);

    int a[n][m];

    // Введення матриці
    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Пошук суми найбільших елементів рядків
    for (int i = 0; i < n; i++) {
        int max = a[i][0]; 
        for (int j = 1; j < m; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        sum += max; // Додаємо знайдений максимум до загальної суми
    }

    printf("\nСума найбільших елементів рядків: %d\n", sum);

    return 0;
}