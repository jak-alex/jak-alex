#include <stdio.h>

int main() {
    int choice;

    // Головний цикл програми
    do {
        // --- МЕНЮ ---
        printf("\n========================================\n");
        printf("              ГОЛОВНЕ МЕНЮ              \n");
        printf("========================================\n");
        printf("1. Запустити обробку масиву\n");
        printf("0. Вийти з програми\n");
        printf("========================================\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int n;

            // Перевірка введення n (не може бути від'ємним або нулем)
            do {
                printf("\nВведіть кількість елементів масиву (n > 0): ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("Помилка! Кількість елементів має бути більшою за нуль.\n");
                }
            } while (n <= 0);

            int a[n]; 
            double sum = 0;
            int count_neg = 0;

            printf("Введіть %d цілих чисел:\n", n);
            for (int i = 0; i < n; i++) {
                printf("a[%d] = ", i);
                scanf("%d", &a[i]);

                sum += a[i];
                if (a[i] < 0) {
                    count_neg++;
                }
            }

            double average = sum / n;

            printf("\n--- РЕЗУЛЬТАТИ АНАЛІЗУ ---\n");
            printf("Кількість від'ємних елементів: %d\n", count_neg);
            printf("Середнє арифметичне масиву: %.2f\n", average);
            printf("---------------------------\n");

            if ((double)count_neg > average) {
                printf("Умова виконана (%d > %.2f).\n", count_neg, average);
                printf("Результат: ");
                for (int i = 0; i < n; i++) {
                    a[i] += 10;
                    printf("%d ", a[i]);
                }
                printf("\n");
            } else {
                printf("Умова не виконана (%d <= %.2f).\n", count_neg, average);
                printf("Результат: ");
                for (int i = 0; i < n; i++) {
                    printf("0 ");
                }
                printf("\n");
            }

        } else if (choice != 0) {
            printf("\n[!] Невірна команда. Спробуйте ще раз.\n");
        }

    } while (choice != 0); // Цикл триває, поки choice не дорівнює 0

    printf("\nПрограма завершена. Гарного дня!\n");
    return 0;
}
