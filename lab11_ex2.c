#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Очищення буфера, щоб scanf не "зациклювався" при помилковому введенні букв
void clear_buffer() {
    while (getchar() != '\n');
}

int main() {
    srand(time(NULL)); // Ініціалізація рандому часом
    int choice;

    while (1) {
        printf("\n==========================================\n");
        printf("   МЕНЮ (Матриця)   \n");
        printf("==========================================\n");
        printf("1. Згенерувати матрицю та знайти Min/Max\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");

        if (scanf("%d", &choice) != 1) {
            printf("Помилка: введіть цифру!\n");
            clear_buffer();
            continue;
        }

        if (choice == 0) break;
        if (choice != 1) {
            printf("Такого пункту немає.\n");
            continue;
        }

        int n, m;
        printf("\nВведіть кількість рядків (n): ");
        while (scanf("%d", &n) != 1 || n <= 0) {
            printf("Некоректно. Введіть ціле число > 0: ");
            clear_buffer();
        }

        printf("Введіть кількість стовпців (m): ");
        while (scanf("%d", &m) != 1 || m <= 0) {
            printf("Некоректно. Введіть ціле число > 0: ");
            clear_buffer();
        }

        // Виділяємо пам'ять
        // Створюємо масив вказівників (рядки)
        int **A = (int**)malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++) {
            // Для кожного рядка виділяємо пам'ять під m елементів
            A[i] = (int*)malloc(m * sizeof(int));
        }

        // Шукаємо min/max
        int max_val = -101; 
        int min_val = 101;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = rand() % 201 - 100; // Діапазон [-100; 100]
                
                if (A[i][j] > max_val) max_val = A[i][j];
                if (A[i][j] < min_val) min_val = A[i][j];
            }
        }

        // Вивод нашої матриці
        printf("\nСформована матриця %dx%d:\n", n, m);
        printf("------------------------------------------\n");
        for (int i = 0; i < n; i++) {
            printf("| "); // Початок рядка
            for (int j = 0; j < m; j++) {
                // %4d робить кожне число шириною в 4 символи, що вирівнює стовпці
                printf("%4d ", A[i][j]);
            }
            printf(" |\n"); // Кінець рядка
        }
        printf("------------------------------------------\n");

        // Кількість входжень
        int count_max = 0, count_min = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] == max_val) count_max++;
                if (A[i][j] == min_val) count_min++;
            }
        }

        printf("РЕЗУЛЬТАТИ:\n");
        printf("-> Максимальний елемент: %d (знайдено %d разів)\n", max_val, count_max);
        printf("-> Мінімальний елемент:  %d (знайдено %d разів)\n", min_val, count_min);

        // Чистимо нашу пам'ять
        for (int i = 0; i < n; i++) {
            free(A[i]); // Видаляємо рядки
        }
        free(A); // Видаляємо масив вказівників
        
        printf("\nНатисніть Enter, щоб повернутися в меню...");
        clear_buffer();
        getchar();
    }

    printf("Програму завершено.\n");
    return 0;
}