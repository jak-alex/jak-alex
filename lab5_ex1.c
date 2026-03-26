#include <stdio.h>

int main() {
    int n;

    // Ввід розміру масиву
    printf("Введіть кількість елементів масиву (n): ");
    scanf("%d", &n);

    int a[n]; // Створення масиву на n елементів
    double sum = 0;
    int count_neg = 0;

    // Тикаємо пальчиками
    printf("Введіть %d цілих чисел:\n", n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);

        // Середнє арифметичне
        sum += a[i];

        // Перевіряємо, чи число від'ємне
        if (a[i] < 0) {
            count_neg++;
        }
    }

    // Обчислення
    double average = sum / n;

    printf("\n--- Результат ---\n");
    printf("Кількість від'ємних елементів: %d\n", count_neg);
    printf("Середнє арифметичне всього масиву: %.2f\n", average);
    printf("---------------------------\n\n");

    if (count_neg > average) {
        printf("Умова виконана (кількість від'ємних > середнього).\n");
        printf("Збільшуємо кожен елемент на 10:\n");
        for (int i = 0; i < n; i++) {
            a[i] = a[i] + 10;
            printf("%d ", a[i]);
        }
    } else {
        printf("Умова не виконана. Виводимо нулі:\n");
        for (int i = 0; i < n; i++) {
            printf("0 ");
        }
    }

    printf("\n");
    return 0;
}