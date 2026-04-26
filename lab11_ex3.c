#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функція приймає вказівник на масив, його розмір та вказівники на змінні для результатів
void calculate_stats(double *arr, int n, double *mean, double *variance) {
    double sum = 0;
    // Рахуємо середнє арифметичне
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    *mean = sum / n; // Записуємо результат за адресою mean

    // Рахуємо дисперсію за формулою: сума (x - mean)^2 / n
    double sq_sum = 0;
    for (int i = 0; i < n; i++) {
        sq_sum += pow(arr[i] - (*mean), 2);
    }
    *variance = sq_sum / n; // Записуємо результат за адресою variance
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Меню ---\n");
        printf("1. Ввести масив та порахувати дисперсію\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        if (choice == 0) break;

        int n;
        printf("Введіть розмір масиву: ");
        while (scanf("%d", &n) != 1 || n <= 0) {
            printf("Помилка. Введіть число > 0: ");
            while (getchar() != '\n');
        }

        // Динамічний масив дробових чисел
        double *data = (double*)malloc(n * sizeof(double));
        printf("Введіть елементи:\n");
        for (int i = 0; i < n; i++) {
            printf("[%d]: ", i);
            while (scanf("%lf", &data[i]) != 1) {
                printf("Некоректне число. Спробуйте ще раз: ");
                while (getchar() != '\n');
            }
        }

        double res_mean, res_variance;
        // Передаємо адреси змінних, щоб функція могла їх змінити
        calculate_stats(data, n, &res_mean, &res_variance);

        printf("\n--- Результати ---");
        printf("\nСереднє значення: %.4f", res_mean);
        printf("\nДисперсія: %.4f\n", res_variance);

        free(data); // Чистимо пам'ять
    }
    return 0;
}