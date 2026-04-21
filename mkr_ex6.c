#include <stdio.h>

int main() {
    int choice;
    double x, f;

    do {
        printf("\n==================================\n");
        printf("   ОБЧИСЛЕННЯ ФУНКЦІЇ f(x)        \n");
        printf("==================================\n");
        printf(" 1 - Ввести x та обчислити\n");
        printf(" 0 - Вийти з програми\n");
        printf("----------------------------------\n");
        printf("Ваш вибір: ");

        // Перевірка вводу пункту меню
        if (scanf("%d", &choice) != 1) {
            printf("\n[!] Помилка: Введіть ціле число (1 або 0)!\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            printf("Введіть значення x: ");
            
            // Перевірка вводу самого числа x
            if (scanf("%lf", &x) != 1) {
                printf("[!] Помилка: Некоректне число x.\n");
                while (getchar() != '\n');
                continue;
            }

            // Розраховуємо вираз, який є спільним для обох гілок
            double expression = x * x + 4 * x + 5;

            if (x > 0) {
                f = expression;
                printf("\nУмова (x > 0) виконана.\n");
            } else {
                // Перевірка на всяк випадок
                if (expression == 0) {
                    printf("\n[!] Помилка: Знаменник дорівнює нулю!\n");
                    continue;
                }
                f = 1.0 / expression;
                printf("\nУмова (x <= 0) виконана.\n");
            }

            printf(">>> РЕЗУЛЬТАТ: f(x) = %.6lf\n", f);

        } else if (choice != 0) {
            printf("\n[!] Такого пункту меню не існує.\n");
        }

    } while (choice != 0);

    printf("\nПрограму завершено.\n");

    return 0;
}