#include <stdio.h>
#include <stdlib.h>

// Функція для очищення буфера введення, щоб програма не "зациклювалася" при помилці
void clear_input() {
    while (getchar() != '\n');
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Меню ---\n");
        printf("1. Виконати програму\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        
        // Перевірка, чи ввів користувач саме число
        if (scanf("%d", &choice) != 1) {
            printf("Помилка: введіть число!\n");
            clear_input();
            continue;
        }

        if (choice == 0) break; // Вихід з циклу
        if (choice != 1) {
            printf("Невірний пункт меню.\n");
            continue;
        }

        int n;
        printf("Введіть розмір масиву n: ");
        // Захист від некоректного розміру (має бути > 0)
        while (scanf("%d", &n) != 1 || n <= 0) {
            printf("Некоректний розмір. Спробуйте ще раз: ");
            clear_input();
        }

        // Виділяємо пам'ять динамічно (в купі)
        int *a = (int*)malloc(n * sizeof(int));
        if (a == NULL) {
            printf("Помилка виділення пам'яті!\n");
            return 1;
        }

        double sum = 0;
        int neg_count = 0;

        printf("Введіть %d елементів масиву:\n", n);
        for (int i = 0; i < n; i++) {
            printf("a[%d] = ", i);
            // Перевірка кожного введеного числа
            while (scanf("%d", &a[i]) != 1) {
                printf("Помилка! Введіть ціле число для a[%d]: ", i);
                clear_input();
            }
            sum += a[i]; // Накопичуємо суму для середнього арифметичного
            if (a[i] < 0) neg_count++; // Рахуємо від'ємні
        }

        double mean = sum / n;
        printf("\nКількість від'ємних: %d", neg_count);
        printf("\nСереднє арифметичне: %.2f\n", mean);

        // Головна логіка за варіантом
        if (neg_count > mean) {
            printf("Умова виконується (кількість > середнє). Додаємо 10 до всіх елементів.\n");
            for (int i = 0; i < n; i++) a[i] += 10;
        } else {
            printf("Умова не виконується. Замінюємо всі елементи на 0.\n");
            for (int i = 0; i < n; i++) a[i] = 0;
        }

        // Виведення результату
        printf("Результат: ");
        for (int i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n");

        // Звільняємо пам'ять після завершення роботи з масивом
        free(a);
    }
    return 0;
}