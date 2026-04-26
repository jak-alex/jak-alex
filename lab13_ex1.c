#include <stdio.h>
#include <stdlib.h>

// Рекурсивна функція для виведення цифр
void printDigitsRecursive(int n) {
    // Базовий випадок: якщо число більше 9, спочатку йдемо глибше
    if (n > 9) {
        printDigitsRecursive(n / 10);
    }
    // Друкуємо останню цифру на поточному етапі рекурсії
    printf("%d\n", n % 10);
}

void clear_buffer() {
    while (getchar() != '\n');
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Меню ---\n");
        printf("1. Ввести число та розбити на цифри\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");

        if (scanf("%d", &choice) != 1) {
            printf("Помилка: введіть число!\n");
            clear_buffer();
            continue;
        }

        if (choice == 0) break;
        if (choice != 1) continue;

        int n;
        printf("Введіть натуральне число n: ");
        while (scanf("%d", &n) != 1 || n < 0) {
            printf("Будь ласка, введіть додатне ціле число: ");
            clear_buffer();
        }

        printf("Цифри числа %d:\n", n);
        if (n == 0) printf("0\n"); // Окремий випадок для нуля
        else printDigitsRecursive(n);
    }
    return 0;
}