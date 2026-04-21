#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double a, b, f;

    do {
        printf("\n==================================\n");
        printf("   ОБЧИСЛЕННЯ ВИРАЗУ f(a, b)      \n");
        printf("==================================\n");
        printf(" 1 - Ввести дані та обчислити\n");
        printf(" 0 - Вийти з програми\n");
        printf("----------------------------------\n");
        printf("Ваш вибір: ");

        // Перевірка на коректність введення пункту меню
        if (scanf("%d", &choice) != 1) {
            printf("\n[!] Помилка: Введіть число (1 або 0)!\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            printf("\nВведіть дійсні числа a та b через пробіл: ");
            
            // Перевірка на коректність введення чисел a та b
            if (scanf("%lf %lf", &a, &b) != 2) {
                printf("[!] Помилка: Некоректні числа. Спробуйте ще раз.\n");
                while (getchar() != '\n');
                continue;
            }

            // Обчислення компонентів формули
            double numerator = a * a - b * b;
            double denominator = a * a + 2 * a * b + 3 * b * b + a + b;

            // Перевірка на ділення на нуль
            if (denominator != 0) {
                f = numerator / denominator;
                printf("\n>>> РЕЗУЛЬТАТ: f(a, b) = %.6lf\n", f);
            } else {
                printf("\n[!] Помилка: Знаменник дорівнює нулю. Обчислення неможливе.\n");
            }

        } else if (choice != 0) {
            printf("\n[!] Такого пункту меню не існує.\n");
        }

    } while (choice != 0);

    printf("\nПрограму завершено.\n");

    return 0;
}